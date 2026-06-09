#include"shinsei/file.h"

#ifdef _SHINSEI_OS_ATOMIC
	static struct _SHINSEI_OS_ALIGN_BYTE{
		volatile int_fast32_t init_flag;
		uid_t current_uid;
		gid_t current_gid;
	}cur_mem={
		.init_flag=0
	};
	
	// Copy from sys/sys.h (Assumed for fallback spinlock)
	_SHINSEI_OS_INLINE static bool cPUPause()_SHINSEI_OS_NOEXCEPT{
		#if(defined(_SHINSEI_OS_GNUC)||defined(_SHINSEI_OS_CLANG))
			#if(defined(_SHINSEI_OS_X64)||defined(_SHINSEI_OS_X86)||defined(_SHINSEI_OS_RISCV64)||defined(_SHINSEI_OS_RISCV32))
				__asm__ volatile("pause":::"memory");
				return true;
			#elif(defined(_SHINSEI_OS_ARM64)||defined(_SHINSEI_OS_ARM)||defined(_SHINSEI_OS_S390X))
				__asm__ volatile("yield":::"memory");
				return true;
			#elif(defined(_SHINSEI_OS_POWERPC64)||defined(_SHINSEI_OS_POWERPC32))
				__asm__ volatile("or 27,27,27":::"memory");
				return true;
			#else
				__asm__ volatile("":::"memory");
				return false;
			#endif
		#else
			return false;
		#endif
	}
#else
	static struct _SHINSEI_OS_ALIGN_BYTE{
		pthread_once_t init_once;
		uid_t current_uid;
		gid_t current_gid;
	}cur_mem={
		.init_once=PTHREAD_ONCE_INIT
	};
	
	static void initOwnerCallback()_SHINSEI_OS_NOEXCEPT{
		cur_mem.current_uid=getuid();
		cur_mem.current_gid=getgid();
		register const char* sudo_uid=getenv("SUDO_UID");
		register const char* sudo_gid=getenv("SUDO_GID");
		if(sudo_uid!=nullptr&&sudo_gid!=nullptr){
			cur_mem.current_uid=(uid_t)atoll(sudo_uid);
			cur_mem.current_gid=(gid_t)atoll(sudo_gid);
			return;
		}
		register const char* login_name=getlogin();
		if(__builtin_expect(login_name!=nullptr,1)){
			struct passwd* pw=getpwnam(login_name);
			if(__builtin_expect(pw!=nullptr,1)){
				cur_mem.current_uid=pw->pw_uid;
				cur_mem.current_gid=pw->pw_gid;
			}
		}
		return;
	}
#endif

// [Internal] Unified UNIX Owner Initializer
_SHINSEI_OS_INLINE static void initOwner()_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_OS_ATOMIC
		int expected=0;
		register const bool enter=__atomic_compare_exchange_n(&cur_mem.init_flag,&expected,1,0,__ATOMIC_ACQ_REL,__ATOMIC_RELAXED);
		if(__builtin_expect(enter,0)){
			cur_mem.current_uid=getuid();
			cur_mem.current_gid=getgid();
			register const char* sudo_uid=getenv("SUDO_UID");
			register const char* sudo_gid=getenv("SUDO_GID");
			if(sudo_uid!=nullptr&&sudo_gid!=nullptr){
				cur_mem.current_uid=(uid_t)atoll(sudo_uid);
				cur_mem.current_gid=(gid_t)atoll(sudo_gid);
			}
			else{
				register const char* login_name=getlogin();
				if(__builtin_expect(login_name!=nullptr,1)){
					struct passwd* pw=getpwnam(login_name);
					if(__builtin_expect(pw!=nullptr,1)){
						cur_mem.current_uid=pw->pw_uid;
						cur_mem.current_gid=pw->pw_gid;
					}
				}
			}
			__atomic_store_n(&cur_mem.init_flag,2,__ATOMIC_RELEASE);
		}
		// Spinlock for concurrent threads while init is in progress
		while(__atomic_load_n(&cur_mem.init_flag,__ATOMIC_ACQUIRE)==1) cPUPause();
	#else
		pthread_once(&cur_mem.init_once,initOwnerCallback);
	#endif
	return;
}

// Copy from str/str.c
_SHINSEI_OS_INLINE static int uTF32CharToUTF8Char(char8_t*const restrict des,const char32_t src)_SHINSEI_OS_NOEXCEPT{
	if(src<=0x7F){
		des[0]=(char8_t)src;
		return 1;
	}
	if(src<=0x7FF){
		des[0]=(char8_t)(0xC0|(src>>6));
		des[1]=(char8_t)(0x80|(src&0x3F));
		return 2;
	}
	if(src<=0xFFFF){
		des[0]=(char8_t)(0xE0|(src>>12));
		des[1]=(char8_t)(0x80|((src>>6)&0x3F));
		des[2]=(char8_t)(0x80|(src&0x3F));
		return 3;
	}
	if(src<=0x10FFFF){
		des[0]=(char8_t)(0xF0|(src>>18));
		des[1]=(char8_t)(0x80|((src>>12)&0x3F));
		des[2]=(char8_t)(0x80|((src>>6)&0x3F));
		des[3]=(char8_t)(0x80|(src&0x3F));
		return 4;
	}
	return 0;
}

// Copy from str/str.c
_SHINSEI_OS_INLINE static int uTF16CharToUTF32Char(char32_t*const restrict des,const char16_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(src[0]<0xD800||src[0]>0xDFFF){
		*des=src[0];
		return 1;
	}
	if(src[0]>=0xD800&&src[0]<=0xDBFF&&src_len>=2){
		if(src[1]>=0xDC00&&src[1]<=0xDFFF){
			*des=(((char32_t)(src[0]&0x3FF)<<10)|(src[1]&0x3FF))+0x10000;
			return 2;
		}
	}
	return 0;
}

// Rewrite from str/str.c
_SHINSEI_OS_INLINE static size_t uTF16ToUTF8(char8_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: Size of the source string.
	register size_t si=0;
	register size_t di=0;
	while(si<src_len){
		char32_t cp;
		register const size_t r=(size_t)uTF16CharToUTF32Char(&cp,src+si,src_len-si);
		if(__builtin_expect(!r,0)) return 0;
		si+=r;
		char8_t tmp[4];
		register const size_t w=(size_t)uTF32CharToUTF8Char(tmp,cp);
		if(di+w>des_buf_len){
			di+=w;
			while(si<src_len){
				register const size_t nr=(size_t)uTF16CharToUTF32Char(&cp,src+si,src_len-si);
				if(!nr) return 0;
				si+=nr;
				di+=uTF32CharToUTF8Char(tmp,cp);
			}
			return di;
		}
		for(register size_t i=0;i<w;++i) des_buf[di++]=tmp[i];
	}
	if(di<des_buf_len) des_buf[di]=0;
	return di;
}

// Rewrite from str/str.c
_SHINSEI_OS_INLINE static size_t uTF16ToUTF32(char32_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: Size of the source string.
	register size_t si=0;
	register size_t di=0;
	while(si<src_len){
		char32_t cp;
		register const size_t r=(size_t)uTF16CharToUTF32Char(&cp,src+si,src_len-si);
		if(__builtin_expect(!r,0)) return 0;
		si+=r;
		if(di+1>des_buf_len){
			di+=1;
			while(si<src_len){
				register const size_t nr=(size_t)uTF16CharToUTF32Char(&cp,src+si,src_len-si);
				if(!nr) return 0;
				si+=nr;
				di+=1;
			}
			return di;
		}
		des_buf[di++]=cp;
	}
	if(di<des_buf_len) des_buf[di]=0;
	return di;
}

// Rewrite from str/str.c
_SHINSEI_OS_INLINE static size_t uTF32ToUTF8(char8_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: Size of the source string.
	register size_t si=0;
	register size_t di=0;
	while(si<src_len){
		register const char32_t cp=src[si++];
		char8_t tmp[4];
		register const size_t w=(size_t)uTF32CharToUTF8Char(tmp,cp);
		if(__builtin_expect(!w,0)) return 0;
		if(di+w>des_buf_len){
			di+=w;
			while(si<src_len){
				register const size_t nw=(size_t)uTF32CharToUTF8Char(tmp,src[si++]);
				if(!nw) return 0;
				di+=nw;
			}
			return di;
		}
		for(register size_t i=0;i<w;++i) des_buf[di++]=tmp[i];
	}
	if(di<des_buf_len) des_buf[di]=0;
	return di;
}

// Copy from minimal/path.h
static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_UNIX_DELIMITER_U8=u8'/';
_SHINSEI_OS_INLINE static bool isUnixPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_UNIX_DELIMITER_U8;
}

// [Internal] Apply owner identity to a path
_SHINSEI_OS_INLINE static void applyOwner(const char*const restrict path,const int owner)_SHINSEI_OS_NOEXCEPT{
	// HIGHEST and DEFAULT are natively handled by UNIX kernel safely.
	if(owner!=SHINSEI_FILE_OWNER_CURRENT) return; 
	initOwner();
	if(cur_mem.current_uid!=geteuid()||cur_mem.current_gid!=getegid()){
		chown(path,cur_mem.current_uid,cur_mem.current_gid);
	}
	return;
}

// [Internal] Apply owner identity to an open file descriptor
_SHINSEI_OS_INLINE static void applyOwnerFD(const int fd,const int owner)_SHINSEI_OS_NOEXCEPT{
	// HIGHEST and DEFAULT are natively handled by UNIX kernel safely.
	if(owner!=SHINSEI_FILE_OWNER_CURRENT) return; 
	initOwner();
	if(cur_mem.current_uid!=geteuid()||cur_mem.current_gid!=getegid()){
		fchown(fd,cur_mem.current_uid,cur_mem.current_gid);
	}
	return;
}

// [Internal] Native Path APIs
_SHINSEI_OS_INLINE static int isFileExistingU8(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	(void)len;
	struct stat st;
	if(__builtin_expect(stat((const char*)path,&st)!=0,0)) return SHINSEI_FILE_TYPE_ILLEGAL;
	if(S_ISDIR(st.st_mode)) return SHINSEI_FILE_TYPE_DIRECTORY;
	return SHINSEI_FILE_TYPE_FILE;
}

_SHINSEI_OS_INLINE static bool createDirectoryU8(const char8_t*const restrict path,const size_t len,int owner)_SHINSEI_OS_NOEXCEPT{
	(void)len;
	if(__builtin_expect(mkdir((const char*)path,0755)!=0,0)) return false;
	applyOwner((const char*)path,owner);
	return true;
}

_SHINSEI_OS_INLINE static bool createDirectoriesU8(char8_t*const restrict path,const size_t len,int owner)_SHINSEI_OS_NOEXCEPT{
	for(register size_t i=1;i<len;++i){
		if(isUnixPathDelimiterU8(path[i])){
			path[i]=u8'\0';
			if(isFileExistingU8(path,i)==SHINSEI_FILE_TYPE_ILLEGAL){
				if(__builtin_expect(!createDirectoryU8(path,i,owner),0)){
					path[i]=SHINSEI_PATH_UNIX_DELIMITER_U8;
					return false;
				}
			}
			path[i]=SHINSEI_PATH_UNIX_DELIMITER_U8;
		}
	}
	if(isFileExistingU8(path,len)==SHINSEI_FILE_TYPE_ILLEGAL){
		if(__builtin_expect(!createDirectoryU8(path,len,owner),0)) return false;
	}
	return true;
}

_SHINSEI_OS_INLINE static int_fast64_t getAccessTimeU8(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	(void)len;
	struct stat st;
	if(__builtin_expect(stat((const char*)path,&st)!=0,0)) return -1;
	return (int_fast64_t)st.st_atim.tv_sec*1000LL+(int_fast64_t)(st.st_atim.tv_nsec/1000000L);
}

_SHINSEI_OS_INLINE static int_fast64_t getModifyTimeU8(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	(void)len;
	struct stat st;
	if(__builtin_expect(stat((const char*)path,&st)!=0,0)) return -1;
	return (int_fast64_t)st.st_mtim.tv_sec*1000LL+(int_fast64_t)(st.st_mtim.tv_nsec/1000000L);
}

_SHINSEI_OS_INLINE static int_fast64_t getCreateTimeU8(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	(void)len;
	struct stat st;
	if(__builtin_expect(stat((const char*)path,&st)!=0,0)) return -1;
	return (int_fast64_t)st.st_ctim.tv_sec*1000LL+(int_fast64_t)(st.st_ctim.tv_nsec/1000000L);
}

_SHINSEI_OS_INLINE static bool moveFileU8(const char8_t*const restrict dst,const char8_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	return !rename((const char*)src,(const char*)dst);
}

// [Internal] Path APIs (U16 -> U8)
_SHINSEI_OS_INLINE static int isFileExistingU16(const char16_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return SHINSEI_FILE_TYPE_ILLEGAL;
	register const size_t res=uTF16ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return SHINSEI_FILE_TYPE_ILLEGAL;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return SHINSEI_FILE_TYPE_NEED_MORE_BUFFER;
	}
	cvt_buf[res]=u8'\0';
	return isFileExistingU8(cvt_buf,res);
}
_SHINSEI_OS_INLINE static bool createDirectoryU16(const char16_t*const restrict path,const size_t len,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t res=uTF16ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return false;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return false;
	}
	cvt_buf[res]=u8'\0';
	return createDirectoryU8(cvt_buf,res,owner);
}
_SHINSEI_OS_INLINE static bool createDirectoriesU16(const char16_t*const restrict path,const size_t len,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t res=uTF16ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return false;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return false;
	}
	cvt_buf[res]=u8'\0';
	return createDirectoriesU8(cvt_buf,res,owner);
}
_SHINSEI_OS_INLINE static int_fast64_t getAccessTimeU16(const char16_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return -1;
	register const size_t res=uTF16ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return -1;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return -1;
	}
	cvt_buf[res]=u8'\0';
	return getAccessTimeU8(cvt_buf,res);
}
_SHINSEI_OS_INLINE static int_fast64_t getModifyTimeU16(const char16_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return -1;
	register const size_t res=uTF16ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return -1;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return -1;
	}
	cvt_buf[res]=u8'\0';
	return getModifyTimeU8(cvt_buf,res);
}
_SHINSEI_OS_INLINE static int_fast64_t getCreateTimeU16(const char16_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return -1;
	register const size_t res=uTF16ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return -1;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return -1;
	}
	cvt_buf[res]=u8'\0';
	return getCreateTimeU8(cvt_buf,res);
}
_SHINSEI_OS_INLINE static bool moveFileU16(const char16_t*const restrict dst,const size_t dst_len,const char16_t*const restrict src,const size_t src_len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!dst_len||!src_len,0)) return false;
	register const size_t res_dst=uTF16ToUTF8(cvt_buf,cvt_len,dst,dst_len);
	if(__builtin_expect(!res_dst,0)) return false;
	register const size_t remain_len=(cvt_len>res_dst+1)*(cvt_len-res_dst-1);
	register char8_t*const next_buf=(char8_t*)((cvt_len>res_dst+1)*(uintptr_t)(cvt_buf+res_dst+1)+(cvt_len<=res_dst+1)*(uintptr_t)cvt_buf);
	register const size_t res_src=uTF16ToUTF8(next_buf,remain_len,src,src_len);
	if(__builtin_expect(!res_src,0)) return false;
	register const size_t total_needed=res_dst+1+res_src+1;
	if(__builtin_expect(total_needed>cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=total_needed;
		return false;
	}
	cvt_buf[res_dst]=u8'\0';
	cvt_buf[res_dst+1+res_src]=u8'\0';
	return moveFileU8(cvt_buf,cvt_buf+res_dst+1);
}

// [Internal] Path APIs (U32 -> U8)
_SHINSEI_OS_INLINE static int isFileExistingU32(const char32_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return SHINSEI_FILE_TYPE_ILLEGAL;
	register const size_t res=uTF32ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return SHINSEI_FILE_TYPE_ILLEGAL;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return SHINSEI_FILE_TYPE_NEED_MORE_BUFFER;
	}
	cvt_buf[res]=u8'\0';
	return isFileExistingU8(cvt_buf,res);
}
_SHINSEI_OS_INLINE static bool createDirectoryU32(const char32_t*const restrict path,const size_t len,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t res=uTF32ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return false;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return false;
	}
	cvt_buf[res]=u8'\0';
	return createDirectoryU8(cvt_buf,res,owner);
}
_SHINSEI_OS_INLINE static bool createDirectoriesU32(char32_t*const restrict path,const size_t len,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t res=uTF32ToUTF8(cvt_buf,cvt_len,(const char32_t*)path,len);
	if(__builtin_expect(!res,0)) return false;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return false;
	}
	cvt_buf[res]=u8'\0';
	return createDirectoriesU8(cvt_buf,res,owner);
}
_SHINSEI_OS_INLINE static int_fast64_t getAccessTimeU32(const char32_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return -1;
	register const size_t res=uTF32ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return -1;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return -1;
	}
	cvt_buf[res]=u8'\0';
	return getAccessTimeU8(cvt_buf,res);
}
_SHINSEI_OS_INLINE static int_fast64_t getModifyTimeU32(const char32_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return -1;
	register const size_t res=uTF32ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return -1;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return -1;
	}
	cvt_buf[res]=u8'\0';
	return getModifyTimeU8(cvt_buf,res);
}
_SHINSEI_OS_INLINE static int_fast64_t getCreateTimeU32(const char32_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return -1;
	register const size_t res=uTF32ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return -1;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return -1;
	}
	cvt_buf[res]=u8'\0';
	return getCreateTimeU8(cvt_buf,res);
}
_SHINSEI_OS_INLINE static bool moveFileU32(const char32_t*const restrict dst,const size_t dst_len,const char32_t*const restrict src,const size_t src_len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!dst_len||!src_len,0)) return false;
	register const size_t res_dst=uTF32ToUTF8(cvt_buf,cvt_len,dst,dst_len);
	if(__builtin_expect(!res_dst,0)) return false;
	register const size_t remain_len=(cvt_len>res_dst+1)*(cvt_len-res_dst-1);
	register char8_t*const next_buf=(char8_t*)((cvt_len>res_dst+1)*(uintptr_t)(cvt_buf+res_dst+1)+(cvt_len<=res_dst+1)*(uintptr_t)cvt_buf);
	register const size_t res_src=uTF32ToUTF8(next_buf,remain_len,src,src_len);
	if(__builtin_expect(!res_src,0)) return false;
	register const size_t total_needed=res_dst+1+res_src+1;
	if(__builtin_expect(total_needed>cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=total_needed;
		return false;
	}
	cvt_buf[res_dst]=u8'\0';
	cvt_buf[res_dst+1+res_src]=u8'\0';
	return moveFileU8(cvt_buf,cvt_buf+res_dst+1);
}

// Exported Path APIs (N)
int shinsei_isFileExistingN(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return isFileExistingU8(path,len);
}
bool shinsei_createDirectoryN(const char8_t*const restrict path,const size_t len,int owner)_SHINSEI_OS_NOEXCEPT{
	return createDirectoryU8(path,len,owner);
}
bool shinsei_createDirectoriesN(char8_t*const restrict path,const size_t len,int owner)_SHINSEI_OS_NOEXCEPT{
	return createDirectoriesU8(path,len,owner);
}
int_fast64_t shinsei_getAccessTimeN(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return getAccessTimeU8(path,len);
}
int_fast64_t shinsei_getModifyTimeN(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return getModifyTimeU8(path,len);
}
int_fast64_t shinsei_getCreateTimeN(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return getCreateTimeU8(path,len);
}
bool shinsei_moveFileN(const char8_t*const restrict dst,const size_t dst_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	(void)dst_len;
	(void)src_len;
	return moveFileU8(dst,src);
}

// Exported Path APIs (U8 - Direct pass/copy)
int shinsei_isFileExistingU8(const char8_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return isFileExistingU8(path,len);
}
bool shinsei_createDirectoryU8(const char8_t*const restrict path,const size_t len,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return createDirectoryU8(path,len,owner);
}
bool shinsei_createDirectoriesU8(char8_t*const restrict path,const size_t len,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return createDirectoriesU8(path,len,owner);
}
int_fast64_t shinsei_getAccessTimeU8(const char8_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return getAccessTimeU8(path,len);
}
int_fast64_t shinsei_getModifyTimeU8(const char8_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return getModifyTimeU8(path,len);
}
int_fast64_t shinsei_getCreateTimeU8(const char8_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return getCreateTimeU8(path,len);
}
bool shinsei_moveFileU8(const char8_t*const restrict dst,const size_t dst_len,const char8_t*const restrict src,const size_t src_len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)dst_len;
	(void)src_len;
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return moveFileU8(dst,src);
}

// Exported Path APIs (U16 -> U8)
int shinsei_isFileExistingU16(const char16_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	return isFileExistingU16(path,len,cvt_buf,cvt_len,needed_len);
}
bool shinsei_createDirectoryU16(const char16_t*const restrict path,const size_t len,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	return createDirectoryU16(path,len,owner,cvt_buf,cvt_len,needed_len);
}
bool shinsei_createDirectoriesU16(const char16_t*const restrict path,const size_t len,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	return createDirectoriesU16(path,len,owner,cvt_buf,cvt_len,needed_len);
}
int_fast64_t shinsei_getAccessTimeU16(const char16_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	return getAccessTimeU16(path,len,cvt_buf,cvt_len,needed_len);
}
int_fast64_t shinsei_getModifyTimeU16(const char16_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	return getModifyTimeU16(path,len,cvt_buf,cvt_len,needed_len);
}
int_fast64_t shinsei_getCreateTimeU16(const char16_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	return getCreateTimeU16(path,len,cvt_buf,cvt_len,needed_len);
}
bool shinsei_moveFileU16(const char16_t*const restrict dst,const size_t dst_len,const char16_t*const restrict src,const size_t src_len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	return moveFileU16(dst,dst_len,src,src_len,cvt_buf,cvt_len,needed_len);
}

// Exported Path APIs (U32 -> U8)
int shinsei_isFileExistingU32(const char32_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	return isFileExistingU32(path,len,cvt_buf,cvt_len,needed_len);
}
bool shinsei_createDirectoryU32(const char32_t*const restrict path,const size_t len,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	return createDirectoryU32(path,len,owner,cvt_buf,cvt_len,needed_len);
}
bool shinsei_createDirectoriesU32(char32_t*const restrict path,const size_t len,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	return createDirectoriesU32((const char32_t*)path,len,owner,cvt_buf,cvt_len,needed_len);
}
int_fast64_t shinsei_getAccessTimeU32(const char32_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	return getAccessTimeU32(path,len,cvt_buf,cvt_len,needed_len);
}
int_fast64_t shinsei_getModifyTimeU32(const char32_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	return getModifyTimeU32(path,len,cvt_buf,cvt_len,needed_len);
}
int_fast64_t shinsei_getCreateTimeU32(const char32_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	return getCreateTimeU32(path,len,cvt_buf,cvt_len,needed_len);
}
bool shinsei_moveFileU32(const char32_t*const restrict dst,const size_t dst_len,const char32_t*const restrict src,const size_t src_len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	return moveFileU32(dst,dst_len,src,src_len,cvt_buf,cvt_len,needed_len);
}

// Exported Path APIs (W -> U8)
int shinsei_isFileExistingW(const wchar_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return isFileExistingU32((const char32_t*)path,len,cvt_buf,cvt_len,needed_len);
	#else
		return isFileExistingU16((const char16_t*)path,len,cvt_buf,cvt_len,needed_len);
	#endif
}
bool shinsei_createDirectoryW(const wchar_t*const restrict path,const size_t len,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return createDirectoryU32((const char32_t*)path,len,owner,cvt_buf,cvt_len,needed_len);
	#else
		return createDirectoryU16((const char16_t*)path,len,owner,cvt_buf,cvt_len,needed_len);
	#endif
}
bool shinsei_createDirectoriesW(const wchar_t*const restrict path,const size_t len,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return createDirectoriesU32((const char32_t*)path,len,owner,cvt_buf,cvt_len,needed_len);
	#else
		return createDirectoriesU16((const char16_t*)path,len,owner,cvt_buf,cvt_len,needed_len);
	#endif
}
int_fast64_t shinsei_getAccessTimeW(const wchar_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return getAccessTimeU32((const char32_t*)path,len,cvt_buf,cvt_len,needed_len);
	#else
		return getAccessTimeU16((const char16_t*)path,len,cvt_buf,cvt_len,needed_len);
	#endif
}
int_fast64_t shinsei_getModifyTimeW(const wchar_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return getModifyTimeU32((const char32_t*)path,len,cvt_buf,cvt_len,needed_len);
	#else
		return getModifyTimeU16((const char16_t*)path,len,cvt_buf,cvt_len,needed_len);
	#endif
}
int_fast64_t shinsei_getCreateTimeW(const wchar_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return getCreateTimeU32((const char32_t*)path,len,cvt_buf,cvt_len,needed_len);
	#else
		return getCreateTimeU16((const char16_t*)path,len,cvt_buf,cvt_len,needed_len);
	#endif
}
bool shinsei_moveFileW(const wchar_t*const restrict dst,const size_t dst_len,const wchar_t*const restrict src,const size_t src_len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return moveFileU32((const char32_t*)dst,dst_len,(const char32_t*)src,src_len,cvt_buf,cvt_len,needed_len);
	#else
		return moveFileU16((const char16_t*)dst,dst_len,(const char16_t*)src,src_len,cvt_buf,cvt_len,needed_len);
	#endif
}

// [Internal] mode translation
_SHINSEI_OS_INLINE static int translateMode(const int mode)_SHINSEI_OS_NOEXCEPT{
	switch(mode){
		case SHINSEI_FILE_OPEN_READ:{
			return O_RDONLY;
		}
		case SHINSEI_FILE_OPEN_WRITE:{
			return O_WRONLY|O_CREAT|O_TRUNC;
		}
		case SHINSEI_FILE_OPEN_APPEND:{
			return O_WRONLY|O_CREAT|O_APPEND;
		}
		case SHINSEI_FILE_OPEN_READWRITE:{
			return O_RDWR;
		}
		case SHINSEI_FILE_OPEN_WRITEREAD:{
			return O_RDWR|O_CREAT|O_TRUNC;
		}
		case SHINSEI_FILE_OPEN_READAPPEND:{
			return O_RDWR|O_CREAT|O_APPEND;
		}
	}
	return O_RDONLY;
}

// [Internal] Constructor implementation
_SHINSEI_OS_INLINE static bool fil_open(shinsei_file_t*const restrict this,const char8_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT{
	(void)len;
	register const int flags=translateMode(open_mode);
	register const int fd=open((const char*)path,flags,0666);
	if(__builtin_expect(fd==-1,0)) return false;
	if(__builtin_expect(flags&O_CREAT,0)) applyOwnerFD(fd,owner);
	this->ptr=(void*)(intptr_t)(fd+1);
	this->ctrl|=_SHINSEI_CTRL_RUNNING;
	return true;
}

// [Internal] Close implementation
_SHINSEI_OS_INLINE static void fil_close(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(this->ctrl&_SHINSEI_CTRL_RUNNING){
		if(__builtin_expect(this->ptr!=nullptr,1)){
			close((int)((intptr_t)this->ptr-1));
			this->ptr=nullptr;
		}
		this->ctrl&=~_SHINSEI_CTRL_RUNNING;
	}
	return;
}

// Exported File Constructors (N)
shinsei_file_t* shinsei_file_t_conN(const char8_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT{
	register shinsei_file_t*const this=(shinsei_file_t*const)__builtin_malloc(sizeof(shinsei_file_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	this->ctrl=0;
	if(!len) return this;
	if(__builtin_expect(!fil_open(this,path,len,open_mode,owner),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}
bool shinsei_file_t_asN(shinsei_file_t*const restrict this,const char8_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	if(!len) return true;
	return fil_open(this,path,len,open_mode,owner);
}
bool shinsei_file_t_inlN(shinsei_file_t*const restrict this,const char8_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=_SHINSEI_CTRL_INLINED;
	if(!len) return true;
	return fil_open(this,path,len,open_mode,owner);
}
bool shinsei_file_t_openN(shinsei_file_t*const restrict this,const char8_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT{
	if(fil_isOpened(this)) fil_close(this);
	return fil_open(this,path,len,open_mode,owner);
}

// Exported File Constructors (U8 - Direct pass/copy)
shinsei_file_t* shinsei_file_t_conU8(const char8_t*const restrict path,const size_t len,int open_mode,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len){
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return shinsei_file_t_conN(path,len,open_mode,owner);
}
bool shinsei_file_t_asU8(shinsei_file_t*const restrict this,const char8_t*const restrict path,const size_t len,int open_mode,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return shinsei_file_t_asN(this,path,len,open_mode,owner);
}
bool shinsei_file_t_inlU8(shinsei_file_t*const restrict this,const char8_t*const restrict path,const size_t len,int open_mode,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return shinsei_file_t_inlN(this,path,len,open_mode,owner);
}
bool shinsei_file_t_openU8(shinsei_file_t*const restrict this,const char8_t*const restrict path,const size_t len,int open_mode,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return shinsei_file_t_openN(this,path,len,open_mode,owner);
}

// Exported File Constructors (U16 -> U8)
shinsei_file_t* shinsei_file_t_conU16(const char16_t*const restrict path,const size_t len,int open_mode,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return nullptr;
	register const size_t res=uTF16ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return nullptr;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return nullptr;
	}
	cvt_buf[res]=u8'\0';
	return shinsei_file_t_conN(cvt_buf,res,open_mode,owner);
}
bool shinsei_file_t_asU16(shinsei_file_t*const restrict this,const char16_t*const restrict path,const size_t len,int open_mode,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t res=uTF16ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return false;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return false;
	}
	cvt_buf[res]=u8'\0';
	return shinsei_file_t_asN(this,cvt_buf,res,open_mode,owner);
}
bool shinsei_file_t_inlU16(shinsei_file_t*const restrict this,const char16_t*const restrict path,const size_t len,int open_mode,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t res=uTF16ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return false;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return false;
	}
	cvt_buf[res]=u8'\0';
	return shinsei_file_t_inlN(this,cvt_buf,res,open_mode,owner);
}
bool shinsei_file_t_openU16(shinsei_file_t*const restrict this,const char16_t*const restrict path,const size_t len,int open_mode,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t res=uTF16ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return false;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return false;
	}
	cvt_buf[res]=u8'\0';
	return shinsei_file_t_openN(this,cvt_buf,res,open_mode,owner);
}

// Exported File Constructors (U32 -> U8)
shinsei_file_t* shinsei_file_t_conU32(const char32_t*const restrict path,const size_t len,int open_mode,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return nullptr;
	register const size_t res=uTF32ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return nullptr;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return nullptr;
	}
	cvt_buf[res]=u8'\0';
	return shinsei_file_t_conN(cvt_buf,res,open_mode,owner);
}
bool shinsei_file_t_asU32(shinsei_file_t*const restrict this,const char32_t*const restrict path,const size_t len,int open_mode,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t res=uTF32ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return false;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return false;
	}
	cvt_buf[res]=u8'\0';
	return shinsei_file_t_asN(this,cvt_buf,res,open_mode,owner);
}
bool shinsei_file_t_inlU32(shinsei_file_t*const restrict this,const char32_t*const restrict path,const size_t len,int open_mode,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t res=uTF32ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return false;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return false;
	}
	cvt_buf[res]=u8'\0';
	return shinsei_file_t_inlN(this,cvt_buf,res,open_mode,owner);
}
bool shinsei_file_t_openU32(shinsei_file_t*const restrict this,const char32_t*const restrict path,const size_t len,int open_mode,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t res=uTF32ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return false;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return false;
	}
	cvt_buf[res]=u8'\0';
	return shinsei_file_t_openN(this,cvt_buf,res,open_mode,owner);
}

// Exported File Constructors (W -> U8)
shinsei_file_t* shinsei_file_t_conW(const wchar_t*const restrict path,const size_t len,int open_mode,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return shinsei_file_t_conU32((const char32_t*)path,len,open_mode,owner,cvt_buf,cvt_len,needed_len);
	#else
		return shinsei_file_t_conU16((const char16_t*)path,len,open_mode,owner,cvt_buf,cvt_len,needed_len);
	#endif
}
bool shinsei_file_t_asW(shinsei_file_t*const restrict this,const wchar_t*const restrict path,const size_t len,int open_mode,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return shinsei_file_t_asU32(this,(const char32_t*)path,len,open_mode,owner,cvt_buf,cvt_len,needed_len);
	#else
		return shinsei_file_t_asU16(this,(const char16_t*)path,len,open_mode,owner,cvt_buf,cvt_len,needed_len);
	#endif
}
bool shinsei_file_t_inlW(shinsei_file_t*const restrict this,const wchar_t*const restrict path,const size_t len,int open_mode,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return shinsei_file_t_inlU32(this,(const char32_t*)path,len,open_mode,owner,cvt_buf,cvt_len,needed_len);
	#else
		return shinsei_file_t_inlU16(this,(const char16_t*)path,len,open_mode,owner,cvt_buf,cvt_len,needed_len);
	#endif
}
bool shinsei_file_t_openW(shinsei_file_t*const restrict this,const wchar_t*const restrict path,const size_t len,int open_mode,int owner,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return shinsei_file_t_openU32(this,(const char32_t*)path,len,open_mode,owner,cvt_buf,cvt_len,needed_len);
	#else
		return shinsei_file_t_openU16(this,(const char16_t*)path,len,open_mode,owner,cvt_buf,cvt_len,needed_len);
	#endif
}

// Common Object & IO Operations
_SHINSEI_OS_CONSTEXPR static bool fil_isOpened(const shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_RUNNING;
}

void shinsei_file_t_dec(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(fil_isOpened(this)) fil_close(this);
	__builtin_free(this);
	return;
}

bool shinsei_file_t_isOpened(const shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return fil_isOpened(this); // [FIXED] Proper function invocation
}

bool shinsei_file_t_inlined(const shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}

int_fast32_t shinsei_file_t_getCtrl(const shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl;
}

void shinsei_file_t_setCtrl(shinsei_file_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=ctrl;
	return;
}

size_t shinsei_file_t_read(shinsei_file_t*const restrict this,void*const restrict buf,size_t size,size_t cnt)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return 0;
	register const ssize_t res=read((int)((intptr_t)this->ptr-1),buf,size*cnt);
	if(__builtin_expect(res<=0,0)) return 0;
	return (size_t)res/size;
}

size_t shinsei_file_t_write(shinsei_file_t*const restrict this,const void*const restrict buf,size_t size,size_t cnt)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return 0;
	register const ssize_t res=write((int)((intptr_t)this->ptr-1),buf,size*cnt);
	if(__builtin_expect(res<=0,0)) return 0;
	return (size_t)res/size;
}

uint_fast64_t shinsei_file_t_tell(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return 0;
	return (uint_fast64_t)lseek((int)((intptr_t)this->ptr-1),0,SEEK_CUR);
}

bool shinsei_file_t_seek(shinsei_file_t*const restrict this,int_fast64_t offset,int origin)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return false;
	return lseek((int)((intptr_t)this->ptr-1),(off_t)offset,origin)!=(off_t)-1;
}

void shinsei_file_t_rewind(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr!=nullptr,1)) lseek((int)((intptr_t)this->ptr-1),0,SEEK_SET);
	return;
}

bool shinsei_file_t_flush(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return false;
	return fsync((int)((intptr_t)this->ptr-1))==0;
}

int shinsei_file_t_getChar(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return SHINSEI_FILE_EOF;
	unsigned char ch;
	if(__builtin_expect(read((int)((intptr_t)this->ptr-1),&ch,1)==1,1)) return (int)ch;
	return SHINSEI_FILE_EOF;
}

bool shinsei_file_t_putChar(shinsei_file_t*const restrict this,int ch)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return false;
	unsigned char c=(unsigned char)ch;
	return write((int)((intptr_t)this->ptr-1),&c,1)==1;
}

void shinsei_file_t_close(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	fil_close(this);
	return;
}

// [Internal] Native Path APIs
_SHINSEI_OS_INLINE static uint_fast64_t getFileSizeU8(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	(void)len;
	struct stat st;
	if(__builtin_expect(stat((const char*)path,&st)!=0,0)) return (uint_fast64_t)-1;
	return (uint_fast64_t)st.st_size;
}

// Exported Path APIs (N)
uint_fast64_t shinsei_getFileSizeN(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return getFileSizeU8(path,len);
}

// Exported Path APIs (U8 - Direct pass/copy)
uint_fast64_t shinsei_getFileSizeU8(const char8_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	// [FIXED] Type mismatch: shinsei_path_cvt_t* replaced with char8_t* to align with inner calls
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return getFileSizeU8(path,len);
}

// Exported Path APIs (U16 -> U8)
uint_fast64_t shinsei_getFileSizeU16(const char16_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return (uint_fast64_t)-1;
	register const size_t res=uTF16ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return (uint_fast64_t)-1;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return (uint_fast64_t)-1;
	}
	cvt_buf[res]=u8'\0';
	return getFileSizeU8(cvt_buf,res);
}

// Exported Path APIs (U32 -> U8)
uint_fast64_t shinsei_getFileSizeU32(const char32_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return (uint_fast64_t)-1;
	register const size_t res=uTF32ToUTF8(cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return (uint_fast64_t)-1;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return (uint_fast64_t)-1;
	}
	cvt_buf[res]=u8'\0';
	return getFileSizeU8(cvt_buf,res);
}

// Exported Path APIs (W -> U8)
uint_fast64_t shinsei_getFileSizeW(const wchar_t*const restrict path,const size_t len,char8_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return shinsei_getFileSizeU32((const char32_t*)path,len,cvt_buf,cvt_len,needed_len);
	#else
		return shinsei_getFileSizeU16((const char16_t*)path,len,cvt_buf,cvt_len,needed_len);
	#endif
}

// Common Object & IO Operations (Append)
uint_fast64_t shinsei_file_t_getSize(const shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return (uint_fast64_t)-1;
	struct stat st;
	if(__builtin_expect(fstat((int)((intptr_t)this->ptr-1),&st)!=0,0)) return (uint_fast64_t)-1;
	return (uint_fast64_t)st.st_size;
}
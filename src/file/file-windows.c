#include"shinsei/file.h"

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

#ifdef _SHINSEI_OS_ATOMIC
	static struct _SHINSEI_OS_ALIGN_BYTE{
		volatile int_fast32_t init_flag;
		void* p_current;
		void* p_highest;
		char current_sid_buf[SECURITY_MAX_SID_SIZE];
		char highest_sid_buf[SECURITY_MAX_SID_SIZE];
	}cur_mem={
		.init_flag=0
	};
	
	// Copy from sys/sys.h
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
		#elif(defined(_SHINSEI_OS_MSVC))
			#if(defined(_SHINSEI_OS_X64)||defined(_SHINSEI_OS_X86))
				_mm_pause();
				return true;
			#elif(defined(_SHINSEI_OS_ARM64)||defined(_SHINSEI_OS_ARM))
				__yield();
				return true;
			#else
				__nop();
				return false;
			#endif
		#else
			return false;
		#endif
	}
#else
	static struct _SHINSEI_OS_ALIGN_BYTE{
		INIT_ONCE init_once;
		void* p_current;
		void* p_highest;
		char current_sid_buf[SECURITY_MAX_SID_SIZE];
		char highest_sid_buf[SECURITY_MAX_SID_SIZE];
	}cur_mem={
		.init_once=INIT_ONCE_STATIC_INIT
	};
	
	static BOOL __stdcall initSidCallback(PINIT_ONCE init_once,PVOID para,PVOID* ptr_context)_SHINSEI_OS_NOEXCEPT{
		(void)init_once;
		(void)para;
		(void)ptr_context;
		HANDLE h_token=nullptr;
		if(__builtin_expect(OpenProcessToken(GetCurrentProcess(),TOKEN_QUERY,&h_token),1)){
			char temp_token_buf[sizeof(TOKEN_USER)+SECURITY_MAX_SID_SIZE];
			DWORD dw_size=0;
			if(__builtin_expect(GetTokenInformation(h_token,TokenUser,temp_token_buf,sizeof(temp_token_buf),&dw_size),1)){
				PTOKEN_USER p_token=(PTOKEN_USER)temp_token_buf;
				if(__builtin_expect(CopySid(sizeof(cur_mem.current_sid_buf),(PSID)cur_mem.current_sid_buf,p_token->User.Sid),1)){
					cur_mem.p_current=cur_mem.current_sid_buf;
				}
			}
			CloseHandle(h_token);
		}
		
		DWORD cb_admin_sid=sizeof(cur_mem.highest_sid_buf);
		if(__builtin_expect(CreateWellKnownSid(WinBuiltinAdministratorsSid,nullptr,cur_mem.highest_sid_buf,&cb_admin_sid),1)){
			cur_mem.p_highest=cur_mem.highest_sid_buf;
		}
		return TRUE;
	}
#endif

// [Internal] Unified Zero-Allocation SID Initializer
_SHINSEI_OS_INLINE static void initSid()_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_OS_ATOMIC
		#ifdef _SHINSEI_OS_MSVC
			register const bool enter=(_InterlockedCompareExchange((volatile LONG*)&cur_mem.init_flag,1,0)==0);
		#else
			int_fast32_t expected=0;
			register const bool enter=__atomic_compare_exchange_n(&cur_mem.init_flag,&expected,1,0,__ATOMIC_ACQ_REL,__ATOMIC_RELAXED);
		#endif
		if(__builtin_expect(enter,0)){ 
			HANDLE h_token=nullptr;
			if(__builtin_expect(OpenProcessToken(GetCurrentProcess(),TOKEN_QUERY,&h_token),1)){
				char temp_token_buf[sizeof(TOKEN_USER)+SECURITY_MAX_SID_SIZE];
				DWORD dw_size=0;
				if(__builtin_expect(GetTokenInformation(h_token,TokenUser,temp_token_buf,sizeof(temp_token_buf),&dw_size),1)){
					PTOKEN_USER p_token=(PTOKEN_USER)temp_token_buf;
					if(__builtin_expect(CopySid(sizeof(cur_mem.current_sid_buf),(PSID)cur_mem.current_sid_buf,p_token->User.Sid),1)){
						cur_mem.p_current=cur_mem.current_sid_buf;
					}
				}
				CloseHandle(h_token);
			}
			DWORD cb_admin_sid=sizeof(cur_mem.highest_sid_buf);
			if(__builtin_expect(CreateWellKnownSid(WinBuiltinAdministratorsSid,nullptr,cur_mem.highest_sid_buf,&cb_admin_sid),1)){
				cur_mem.p_highest=cur_mem.highest_sid_buf;
			}
			#ifdef _SHINSEI_OS_MSVC
				_InterlockedExchange((volatile LONG*)&cur_mem.init_flag,2);
			#else
				__atomic_store_n(&cur_mem.init_flag,2,__ATOMIC_RELEASE);
			#endif
		}
		// Fallback spinlock for concurrent threads while initialization is in progress
		#ifdef _SHINSEI_OS_MSVC
			while(_InterlockedOr((volatile LONG*)&cur_mem.init_flag,0)==1) cPUPause();
		#else
			while(__atomic_load_n(&cur_mem.init_flag,__ATOMIC_ACQUIRE)==1) cPUPause();
		#endif
	#else
		InitOnceExecuteOnce(&cur_mem.init_once,initSidCallback,nullptr,nullptr);
	#endif
	return;
}

// Copy from str/str.c
_SHINSEI_OS_INLINE static int uTF32CharToUTF16Char(char16_t*const restrict des,const char32_t src)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(src<0x10000,1)){
		des[0]=(char16_t)src;
		return 1;
	}
	register const char32_t res=src-0x10000;
	des[0]=(char16_t)((res>>10)+0xD800);
	des[1]=(char16_t)((res&0x3FF)+0xDC00);
	return 2;
}

// Copy from str/str.c
_SHINSEI_OS_INLINE static int uTF8CharToUTF32Char(char32_t*const restrict des,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(src[0]<0x80){
		*des=(char32_t)src[0];
		return 1;
	}
	if((src[0]&0xE0)==0xC0&&src_len>=2){
		*des=(((char32_t)(src[0]&0x1F)<<6)|(src[1]&0x3F));
		return 2;
	}
	if((src[0]&0xF0)==0xE0&&src_len>=3){
		*des=(((char32_t)(src[0]&0x0F)<<12)|((src[1]&0x3F)<<6)|(src[2]&0x3F));
		return 3;
	}
	if((src[0]&0xF8)==0xF0&&src_len>=4){
		*des=(((char32_t)(src[0]&0x07)<<18)|((src[1]&0x3F)<<12)|((src[2]&0x3F)<<6)|(src[3]&0x3F));
		return 4;
	}
	return 0;
}

// Rewrite from str/str.c
_SHINSEI_OS_INLINE static size_t uTF8ToUTF16(char16_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: Size of the source string.
	register size_t si=0;
	register size_t di=0;
	while(si<src_len){
		char32_t cp;
		register const size_t r=(size_t)uTF8CharToUTF32Char(&cp,src+si,src_len-si);
		if(__builtin_expect(!r,0)) return 0;
		si+=r;
		char16_t tmp[2];
		register const size_t w=(size_t)uTF32CharToUTF16Char(tmp,cp);
		if(di+w>des_buf_len){
			di+=w;
			while(si<src_len){
				register const size_t nr=(size_t)uTF8CharToUTF32Char(&cp,src+si,src_len-si);
				if(!nr) return 0;
				si+=nr;
				di+=(size_t)uTF32CharToUTF16Char(tmp,cp);
			}
			return di;
		}
		for(register size_t i=0;i<w;++i) des_buf[di++]=tmp[i];
	}
	if(di<des_buf_len) des_buf[di]=0;
	return di;
}

// Rewrite from str/str.c
_SHINSEI_OS_INLINE static size_t uTF32ToUTF16(char16_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: Size of the source string.
	register size_t si=0;
	register size_t di=0;
	while(si<src_len){
		register const char32_t cp=src[si++];
		char16_t tmp[2];
		register const size_t w=(size_t)uTF32CharToUTF16Char(tmp,cp);
		if(__builtin_expect(!w,0)) return 0;
		if(di+w>des_buf_len){
			di+=w;
			while(si<src_len){
				register const size_t nw=(size_t)uTF32CharToUTF16Char(tmp,src[si++]);
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
static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_WINDOWS_DELIMITER_W=L'\\';
static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_UNIX_DELIMITER_W=L'/';
_SHINSEI_OS_INLINE static bool isWindowsPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_WINDOWS_DELIMITER_W||ch==SHINSEI_PATH_UNIX_DELIMITER_W;
}

// [Internal] Filetime to UNIX MS
_SHINSEI_OS_INLINE static int_fast64_t filetimeToUnixMS(const void*const ft)_SHINSEI_OS_NOEXCEPT{
	ULARGE_INTEGER ull;
	ull.LowPart=((const FILETIME*)ft)->dwLowDateTime;
	ull.HighPart=((const FILETIME*)ft)->dwHighDateTime;
	return (int_fast64_t)((ull.QuadPart-116444736000000000ULL)/10000ULL);
}

// [Internal] Apply owner identity to a path
_SHINSEI_OS_INLINE static void applyOwner(const wchar_t*const restrict path,const int owner)_SHINSEI_OS_NOEXCEPT{
	if(owner==SHINSEI_FILE_OWNER_DEFAULT) return;
	initSid();
	void* p_sid=nullptr;
	if(owner==SHINSEI_FILE_OWNER_CURRENT) p_sid=cur_mem.p_current;
	else if(owner==SHINSEI_FILE_OWNER_HIGHEST) p_sid=cur_mem.p_highest;
	if(__builtin_expect(p_sid!=nullptr,1)){
		SetNamedSecurityInfoW((LPWSTR)path,SE_FILE_OBJECT,OWNER_SECURITY_INFORMATION,(PSID)p_sid,nullptr,nullptr,nullptr);
	}
	return;
}

// [Internal] Apply owner identity to an open file descriptor
_SHINSEI_OS_INLINE static void applyOwnerFD(void*const hFile,const int owner)_SHINSEI_OS_NOEXCEPT{
	if(owner==SHINSEI_FILE_OWNER_DEFAULT) return;
	initSid();
	void* p_sid=nullptr;
	if(owner==SHINSEI_FILE_OWNER_CURRENT) p_sid=cur_mem.p_current;
	else if(owner==SHINSEI_FILE_OWNER_HIGHEST) p_sid=cur_mem.p_highest;
	if(__builtin_expect(p_sid!=nullptr,1)){
		SetSecurityInfo(hFile,SE_FILE_OBJECT,OWNER_SECURITY_INFORMATION,(PSID)p_sid,nullptr,nullptr,nullptr);
	}
	return;
}

// [Internal] Native Path APIs
_SHINSEI_OS_INLINE static int isFileExistingW(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	(void)len;
	register const DWORD attr=GetFileAttributesW(path);
	if(__builtin_expect(attr==INVALID_FILE_ATTRIBUTES,0)) return SHINSEI_FILE_TYPE_ILLEGAL;
	if(attr&FILE_ATTRIBUTE_DIRECTORY) return SHINSEI_FILE_TYPE_DIRECTORY;
	return SHINSEI_FILE_TYPE_FILE;
}

_SHINSEI_OS_INLINE static bool createDirectoryW(const wchar_t*const restrict path,const size_t len,int owner)_SHINSEI_OS_NOEXCEPT{
	(void)len;
	if(__builtin_expect(!CreateDirectoryW(path,nullptr),0)) return false;
	applyOwner(path,owner);
	return true;
}

_SHINSEI_OS_INLINE static bool createDirectoriesW(wchar_t*const restrict path,const size_t len,int owner)_SHINSEI_OS_NOEXCEPT{
	for(register size_t i=1;i<len;++i){
		if(isWindowsPathDelimiterW(path[i])){
			register const wchar_t temp=path[i];
			path[i]=L'\0';
			if(isFileExistingW(path,i)==SHINSEI_FILE_TYPE_ILLEGAL){
				if(__builtin_expect(!createDirectoryW(path,i,owner),0)){
					path[i]=temp;
					return false;
				}
			}
			path[i]=temp;
		}
	}
	if(isFileExistingW(path,len)==SHINSEI_FILE_TYPE_ILLEGAL){
		if(__builtin_expect(!createDirectoryW(path,len,owner),0)) return false;
	}
	return true;
}

_SHINSEI_OS_INLINE static int_fast64_t getAccessTimeW(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	(void)len;
	WIN32_FILE_ATTRIBUTE_DATA info;
	if(__builtin_expect(!GetFileAttributesExW(path,GetFileExInfoStandard,&info),0)) return -1;
	return filetimeToUnixMS(&info.ftLastAccessTime);
}

_SHINSEI_OS_INLINE static int_fast64_t getModifyTimeW(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	(void)len;
	WIN32_FILE_ATTRIBUTE_DATA info;
	if(__builtin_expect(!GetFileAttributesExW(path,GetFileExInfoStandard,&info),0)) return -1;
	return filetimeToUnixMS(&info.ftLastWriteTime);
}

_SHINSEI_OS_INLINE static int_fast64_t getCreateTimeW(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	(void)len;
	WIN32_FILE_ATTRIBUTE_DATA info;
	if(__builtin_expect(!GetFileAttributesExW(path,GetFileExInfoStandard,&info),0)) return -1;
	return filetimeToUnixMS(&info.ftCreationTime);
}

_SHINSEI_OS_INLINE static bool fil_moveFile(const wchar_t*const restrict dst,const wchar_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	return MoveFileExW(src,dst,MOVEFILE_REPLACE_EXISTING|MOVEFILE_COPY_ALLOWED)!=0;
}

// Exported Path APIs (N)
int shinsei_isFileExistingN(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return isFileExistingW(path,len);
}
bool shinsei_createDirectoryN(const wchar_t*const restrict path,const size_t len,int owner)_SHINSEI_OS_NOEXCEPT{
	return createDirectoryW(path,len,owner);
}
bool shinsei_createDirectoriesN(wchar_t*const restrict path,const size_t len,int owner)_SHINSEI_OS_NOEXCEPT{
	return createDirectoriesW(path,len,owner);
}
int_fast64_t shinsei_getAccessTimeN(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return getAccessTimeW(path,len);
}
int_fast64_t shinsei_getModifyTimeN(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return getModifyTimeW(path,len);
}
int_fast64_t shinsei_getCreateTimeN(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return getCreateTimeW(path,len);
}
bool shinsei_moveFileN(const wchar_t*const restrict dst,const size_t dst_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	(void)dst_len;
	(void)src_len;
	return fil_moveFile(dst,src);
}

// Exported Path APIs (W - Direct pass/copy)
int shinsei_isFileExistingW(const wchar_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return isFileExistingW(path,len);
}
bool shinsei_createDirectoryW(const wchar_t*const restrict path,const size_t len,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return createDirectoryW(path,len,owner);
}
bool shinsei_createDirectoriesW(wchar_t*const restrict path,const size_t len,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return createDirectoriesW(path,len,owner);
}
int_fast64_t shinsei_getAccessTimeW(const wchar_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return getAccessTimeW(path,len);
}
int_fast64_t shinsei_getModifyTimeW(const wchar_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return getModifyTimeW(path,len);
}
int_fast64_t shinsei_getCreateTimeW(const wchar_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return getCreateTimeW(path,len);
}
bool shinsei_moveFileW(const wchar_t*const restrict dst,const size_t dst_len,const wchar_t*const restrict src,const size_t src_len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	(void)dst_len;
	(void)src_len;
	return fil_moveFile(dst,src);
}

// Exported Path APIs (U8 -> W)
int shinsei_isFileExistingU8(const char8_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return SHINSEI_FILE_TYPE_ILLEGAL;
	#ifdef _SHINSEI_WCHAR_U32
		register const size_t res=uTF8ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
	#else
		register const size_t res=uTF8ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
	#endif
	if(__builtin_expect(!res,0)) return SHINSEI_FILE_TYPE_ILLEGAL;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return SHINSEI_FILE_TYPE_NEED_MORE_BUFFER;
	}
	cvt_buf[res]=L'\0';
	return isFileExistingW(cvt_buf,res);
}
bool shinsei_createDirectoryU8(const char8_t*const restrict path,const size_t len,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	#ifdef _SHINSEI_WCHAR_U32
		register const size_t res=uTF8ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
	#else
		register const size_t res=uTF8ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
	#endif
	if(__builtin_expect(!res,0)) return false;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return false;
	}
	cvt_buf[res]=L'\0';
	return createDirectoryW(cvt_buf,res,owner);
}
bool shinsei_createDirectoriesU8(char8_t*const restrict path,const size_t len,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	#ifdef _SHINSEI_WCHAR_U32
		register const size_t res=uTF8ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
	#else
		register const size_t res=uTF8ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
	#endif
	if(__builtin_expect(!res,0)) return false;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return false;
	}
	cvt_buf[res]=L'\0';
	return createDirectoriesW(cvt_buf,res,owner);
}
int_fast64_t shinsei_getAccessTimeU8(const char8_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return -1;
	#ifdef _SHINSEI_WCHAR_U32
		register const size_t res=uTF8ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
	#else
		register const size_t res=uTF8ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
	#endif
	if(__builtin_expect(!res,0)) return -1;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return -1;
	}
	cvt_buf[res]=L'\0';
	return getAccessTimeW(cvt_buf,res);
}
int_fast64_t shinsei_getModifyTimeU8(const char8_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return -1;
	#ifdef _SHINSEI_WCHAR_U32
		register const size_t res=uTF8ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
	#else
		register const size_t res=uTF8ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
	#endif
	if(__builtin_expect(!res,0)) return -1;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return -1;
	}
	cvt_buf[res]=L'\0';
	return getModifyTimeW(cvt_buf,res);
}
int_fast64_t shinsei_getCreateTimeU8(const char8_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return -1;
	#ifdef _SHINSEI_WCHAR_U32
		register const size_t res=uTF8ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
	#else
		register const size_t res=uTF8ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
	#endif
	if(__builtin_expect(!res,0)) return -1;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return -1;
	}
	cvt_buf[res]=L'\0';
	return getCreateTimeW(cvt_buf,res);
}
bool shinsei_moveFileU8(const char8_t*const restrict dst,const size_t dst_len,const char8_t*const restrict src,const size_t src_len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!dst_len||!src_len,0)) return false;
	#ifdef _SHINSEI_WCHAR_U32
		register const size_t res_dst=uTF8ToUTF32((char32_t*)cvt_buf,cvt_len,dst,dst_len);
		if(__builtin_expect(!res_dst,0)) return false;
		register const size_t remain_len=(cvt_len>res_dst+1)*(cvt_len-res_dst-1);
		register wchar_t*const next_buf=(wchar_t*)((cvt_len>res_dst+1)*(uintptr_t)(cvt_buf+res_dst+1)+(cvt_len<=res_dst+1)*(uintptr_t)cvt_buf);
		register const size_t res_src=uTF8ToUTF32((char32_t*)next_buf,remain_len,src,src_len);
	#else
		register const size_t res_dst=uTF8ToUTF16((char16_t*)cvt_buf,cvt_len,dst,dst_len);
		if(__builtin_expect(!res_dst,0)) return false;
		register const size_t remain_len=(cvt_len>res_dst+1)*(cvt_len-res_dst-1);
		register wchar_t*const next_buf=(wchar_t*)((cvt_len>res_dst+1)*(uintptr_t)(cvt_buf+res_dst+1)+(cvt_len<=res_dst+1)*(uintptr_t)cvt_buf);
		register const size_t res_src=uTF8ToUTF16((char16_t*)next_buf,remain_len,src,src_len);
	#endif
	if(__builtin_expect(!res_src,0)) return false;
	register const size_t total_needed=res_dst+1+res_src+1;
	if(__builtin_expect(total_needed>cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=total_needed;
		return false;
	}
	cvt_buf[res_dst]=L'\0';
	cvt_buf[res_dst+1+res_src]=L'\0';
	return fil_moveFile(cvt_buf,cvt_buf+res_dst+1);
}

// Exported Path APIs (U16 -> W)
int shinsei_isFileExistingU16(const char16_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		if(__builtin_expect(!len,0)) return SHINSEI_FILE_TYPE_ILLEGAL;
		register const size_t res=uTF16ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return SHINSEI_FILE_TYPE_ILLEGAL;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return SHINSEI_FILE_TYPE_NEED_MORE_BUFFER;
		}
		cvt_buf[res]=L'\0';
		return isFileExistingW(cvt_buf,res);
	#else
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return isFileExistingW((const wchar_t*)path,len);
	#endif
}
bool shinsei_createDirectoryU16(const char16_t*const restrict path,const size_t len,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		if(__builtin_expect(!len,0)) return false;
		register const size_t res=uTF16ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return false;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return false;
		}
		cvt_buf[res]=L'\0';
		return createDirectoryW(cvt_buf,res,owner);
	#else
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return createDirectoryW((const wchar_t*)path,len,owner);
	#endif
}
bool shinsei_createDirectoriesU16(char16_t*const restrict path,const size_t len,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		if(__builtin_expect(!len,0)) return false;
		register const size_t res=uTF16ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return false;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return false;
		}
		cvt_buf[res]=L'\0';
		return createDirectoriesW(cvt_buf,res,owner);
	#else
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return createDirectoriesW((wchar_t*)path,len,owner);
	#endif
}
int_fast64_t shinsei_getAccessTimeU16(const char16_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		if(__builtin_expect(!len,0)) return -1;
		register const size_t res=uTF16ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return -1;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return -1;
		}
		cvt_buf[res]=L'\0';
		return getAccessTimeW(cvt_buf,res);
	#else
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return getAccessTimeW((const wchar_t*)path,len);
	#endif
}
int_fast64_t shinsei_getModifyTimeU16(const char16_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		if(__builtin_expect(!len,0)) return -1;
		register const size_t res=uTF16ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return -1;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return -1;
		}
		cvt_buf[res]=L'\0';
		return getModifyTimeW(cvt_buf,res);
	#else
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return getModifyTimeW((const wchar_t*)path,len);
	#endif
}
int_fast64_t shinsei_getCreateTimeU16(const char16_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		if(__builtin_expect(!len,0)) return -1;
		register const size_t res=uTF16ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return -1;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return -1;
		}
		cvt_buf[res]=L'\0';
		return getCreateTimeW(cvt_buf,res);
	#else
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return getCreateTimeW((const wchar_t*)path,len);
	#endif
}
bool shinsei_moveFileU16(const char16_t*const restrict dst,const size_t dst_len,const char16_t*const restrict src,const size_t src_len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		if(__builtin_expect(!dst_len||!src_len,0)) return false;
		register const size_t res_dst=uTF16ToUTF32((char32_t*)cvt_buf,cvt_len,dst,dst_len);
		if(__builtin_expect(!res_dst,0)) return false;
		
		register const size_t remain_len=(cvt_len>res_dst+1)*(cvt_len-res_dst-1);
		register wchar_t*const next_buf=(wchar_t*)((cvt_len>res_dst+1)*(uintptr_t)(cvt_buf+res_dst+1)+(cvt_len<=res_dst+1)*(uintptr_t)cvt_buf);
		
		register const size_t res_src=uTF16ToUTF32((char32_t*)next_buf,remain_len,src,src_len);
		if(__builtin_expect(!res_src,0)) return false;
		
		register const size_t total_needed=res_dst+1+res_src+1;
		if(__builtin_expect(total_needed>cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=total_needed;
			return false;
		}
		cvt_buf[res_dst]=L'\0';
		cvt_buf[res_dst+1+res_src]=L'\0';
		return fil_moveFile(cvt_buf,cvt_buf+res_dst+1);
	#else
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		(void)dst_len;
		(void)src_len;
		return fil_moveFile((const wchar_t*)dst,(const wchar_t*)src);
	#endif
}

// Exported Path APIs (U32 -> W)
int shinsei_isFileExistingU32(const char32_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return isFileExistingW((const wchar_t*)path,len);
	#else
		if(__builtin_expect(!len,0)) return SHINSEI_FILE_TYPE_ILLEGAL;
		register const size_t res=uTF32ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return SHINSEI_FILE_TYPE_ILLEGAL;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return SHINSEI_FILE_TYPE_NEED_MORE_BUFFER;
		}
		cvt_buf[res]=L'\0';
		return isFileExistingW(cvt_buf,res);
	#endif
}
bool shinsei_createDirectoryU32(const char32_t*const restrict path,const size_t len,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return createDirectoryW((const wchar_t*)path,len,owner);
	#else
		if(__builtin_expect(!len,0)) return false;
		register const size_t res=uTF32ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return false;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return false;
		}
		cvt_buf[res]=L'\0';
		return createDirectoryW(cvt_buf,res,owner);
	#endif
}
bool shinsei_createDirectoriesU32(char32_t*const restrict path,const size_t len,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return createDirectoriesW((wchar_t*)path,len,owner);
	#else
		if(__builtin_expect(!len,0)) return false;
		register const size_t res=uTF32ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return false;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return false;
		}
		cvt_buf[res]=L'\0';
		return createDirectoriesW(cvt_buf,res,owner);
	#endif
}
int_fast64_t shinsei_getAccessTimeU32(const char32_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return getAccessTimeW((const wchar_t*)path,len);
	#else
		if(__builtin_expect(!len,0)) return -1;
		register const size_t res=uTF32ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return -1;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return -1;
		}
		cvt_buf[res]=L'\0';
		return getAccessTimeW(cvt_buf,res);
	#endif
}
int_fast64_t shinsei_getModifyTimeU32(const char32_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return getModifyTimeW((const wchar_t*)path,len);
	#else
		if(__builtin_expect(!len,0)) return -1;
		register const size_t res=uTF32ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return -1;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return -1;
		}
		cvt_buf[res]=L'\0';
		return getModifyTimeW(cvt_buf,res);
	#endif
}
int_fast64_t shinsei_getCreateTimeU32(const char32_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return getCreateTimeW((const wchar_t*)path,len);
	#else
		if(__builtin_expect(!len,0)) return -1;
		register const size_t res=uTF32ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return -1;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return -1;
		}
		cvt_buf[res]=L'\0';
		return getCreateTimeW(cvt_buf,res);
	#endif
}
bool shinsei_moveFileU32(const char32_t*const restrict dst,const size_t dst_len,const char32_t*const restrict src,const size_t src_len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		(void)dst_len;
		(void)src_len;
		return fil_moveFile((const wchar_t*)dst,(const wchar_t*)src);
	#else
		if(__builtin_expect(!dst_len||!src_len,0)) return false;
		register const size_t res_dst=uTF32ToUTF16((char16_t*)cvt_buf,cvt_len,dst,dst_len);
		if(__builtin_expect(!res_dst,0)) return false;
		register const size_t remain_len=(cvt_len>res_dst+1)*(cvt_len-res_dst-1);
		register wchar_t*const next_buf=(wchar_t*)((cvt_len>res_dst+1)*(uintptr_t)(cvt_buf+res_dst+1)+(cvt_len<=res_dst+1)*(uintptr_t)cvt_buf);
		register const size_t res_src=uTF32ToUTF16((char16_t*)next_buf,remain_len,src,src_len);
		if(__builtin_expect(!res_src,0)) return false;
		register const size_t total_needed=res_dst+1+res_src+1;
		if(__builtin_expect(total_needed>cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=total_needed;
			return false;
		}
		cvt_buf[res_dst]=L'\0';
		cvt_buf[res_dst+1+res_src]=L'\0';
		return fil_moveFile(cvt_buf,cvt_buf+res_dst+1);
	#endif
}

// [Internal] mode translation
_SHINSEI_OS_INLINE static void translateMode(const int mode,DWORD*const restrict access,DWORD*const restrict creation)_SHINSEI_OS_NOEXCEPT{
	switch(mode){
		case SHINSEI_FILE_OPEN_READ:{
			*access=GENERIC_READ;
			*creation=OPEN_EXISTING;
			return;
		}
		case SHINSEI_FILE_OPEN_WRITE:{
			*access=GENERIC_WRITE;
			*creation=CREATE_ALWAYS;
			return;
		}
		case SHINSEI_FILE_OPEN_APPEND:{
			*access=FILE_APPEND_DATA;
			*creation=OPEN_ALWAYS;
			return;
		}
		case SHINSEI_FILE_OPEN_READWRITE:{
			*access=GENERIC_READ|GENERIC_WRITE;
			*creation=OPEN_EXISTING;
			return;
		}
		case SHINSEI_FILE_OPEN_WRITEREAD:{
			*access=GENERIC_READ|GENERIC_WRITE;
			*creation=CREATE_ALWAYS;
			return;
		}
		case SHINSEI_FILE_OPEN_READAPPEND:{
			*access=GENERIC_READ|FILE_APPEND_DATA;
			*creation=OPEN_ALWAYS;
			return;
		}
	}
	*access=GENERIC_READ;
	*creation=OPEN_EXISTING;
	return;
}

// [Internal] Constructor implementation
_SHINSEI_OS_INLINE static bool fil_open(shinsei_file_t*const restrict this,const wchar_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT{
	(void)len;
	DWORD access, creation;
	translateMode(open_mode,&access,&creation);
	
	register const DWORD attr=GetFileAttributesW(path);
	register const bool exist=(attr!=INVALID_FILE_ATTRIBUTES);
	
	register HANDLE h=CreateFileW(path,access,FILE_SHARE_READ|FILE_SHARE_WRITE,nullptr,creation,FILE_ATTRIBUTE_NORMAL,nullptr);
	if(__builtin_expect(h==INVALID_HANDLE_VALUE,0)){
		this->ptr=nullptr;
		return false;
	}
	
	if(__builtin_expect(!exist&&(creation==CREATE_ALWAYS||creation==OPEN_ALWAYS),0)){
		applyOwnerFD((void*)h,owner);
	}
	
	this->ptr=(void*)h;
	this->ctrl|=_SHINSEI_CTRL_RUNNING;
	return true;
}

// [Internal] Close implementation
_SHINSEI_OS_INLINE static void fil_close(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(this->ctrl&_SHINSEI_CTRL_RUNNING){
		if(__builtin_expect(this->ptr!=nullptr,1)){
			CloseHandle((HANDLE)this->ptr);
			this->ptr=nullptr;
		}
		this->ctrl&=~_SHINSEI_CTRL_RUNNING;
	}
	return;
}

_SHINSEI_OS_INLINE static bool fil_isOpened(const shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_RUNNING;
}

// Exported File Constructors (N)
shinsei_file_t* shinsei_file_t_conN(const wchar_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT{
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
bool shinsei_file_t_asN(shinsei_file_t*const restrict this,const wchar_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	if(!len) return true;
	return fil_open(this,path,len,open_mode,owner);
}
bool shinsei_file_t_inlN(shinsei_file_t*const restrict this,const wchar_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=_SHINSEI_CTRL_INLINED;
	if(!len) return true;
	return fil_open(this,path,len,open_mode,owner);
}
bool shinsei_file_t_openN(shinsei_file_t*const restrict this,const wchar_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT{
	if(fil_isOpened(this)) fil_close(this);
	if(!len) return true;
	return fil_open(this,path,len,open_mode,owner);
}

// Exported File Constructors (W - Direct call)
shinsei_file_t* shinsei_file_t_conW(const wchar_t*const restrict path,const size_t len,int open_mode,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return shinsei_file_t_conN(path,len,open_mode,owner);
}
bool shinsei_file_t_asW(shinsei_file_t*const restrict this,const wchar_t*const restrict path,const size_t len,int open_mode,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return shinsei_file_t_asN(this,path,len,open_mode,owner);
}
bool shinsei_file_t_inlW(shinsei_file_t*const restrict this,const wchar_t*const restrict path,const size_t len,int open_mode,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return shinsei_file_t_inlN(this,path,len,open_mode,owner);
}
bool shinsei_file_t_openW(shinsei_file_t*const restrict this,const wchar_t*const restrict path,const size_t len,int open_mode,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return shinsei_file_t_openN(this,path,len,open_mode,owner);
}

// Exported File Constructors (U8 -> W)
shinsei_file_t* shinsei_file_t_conU8(const char8_t*const restrict path,const size_t len,int open_mode,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return nullptr;
	register const size_t res=uTF8ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return nullptr;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return nullptr;
	}
	cvt_buf[res]=L'\0';
	return shinsei_file_t_conN(cvt_buf,res,open_mode,owner);
}
bool shinsei_file_t_asU8(shinsei_file_t*const restrict this,const char8_t*const restrict path,const size_t len,int open_mode,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t res=uTF8ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return false;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return false;
	}
	cvt_buf[res]=L'\0';
	return shinsei_file_t_asN(this,cvt_buf,res,open_mode,owner);
}
bool shinsei_file_t_inlU8(shinsei_file_t*const restrict this,const char8_t*const restrict path,const size_t len,int open_mode,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t res=uTF8ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return false;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return false;
	}
	cvt_buf[res]=L'\0';
	return shinsei_file_t_inlN(this,cvt_buf,res,open_mode,owner);
}
bool shinsei_file_t_openU8(shinsei_file_t*const restrict this,const char8_t*const restrict path,const size_t len,int open_mode,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t res=uTF8ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
	if(__builtin_expect(!res,0)) return false;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return false;
	}
	cvt_buf[res]=L'\0';
	return shinsei_file_t_openN(this,cvt_buf,res,open_mode,owner);
}

// Exported File Constructors (U16 -> W)
shinsei_file_t* shinsei_file_t_conU16(const char16_t*const restrict path,const size_t len,int open_mode,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		if(__builtin_expect(!len,0)) return nullptr;
		register const size_t res=uTF16ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return nullptr;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return nullptr;
		}
		cvt_buf[res]=L'\0';
		return shinsei_file_t_conN(cvt_buf,res,open_mode,owner);
	#else
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return shinsei_file_t_conN((const wchar_t*)path,len,open_mode,owner);
	#endif
}
bool shinsei_file_t_asU16(shinsei_file_t*const restrict this,const char16_t*const restrict path,const size_t len,int open_mode,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		if(__builtin_expect(!len,0)) return false;
		register const size_t res=uTF16ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return false;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return false;
		}
		cvt_buf[res]=L'\0';
		return shinsei_file_t_asN(this,cvt_buf,res,open_mode,owner);
	#else
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return shinsei_file_t_asN(this,(const wchar_t*)path,len,open_mode,owner);
	#endif
}
bool shinsei_file_t_inlU16(shinsei_file_t*const restrict this,const char16_t*const restrict path,const size_t len,int open_mode,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		if(__builtin_expect(!len,0)) return false;
		register const size_t res=uTF16ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return false;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return false;
		}
		cvt_buf[res]=L'\0';
		return shinsei_file_t_inlN(this,cvt_buf,res,open_mode,owner);
	#else
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return shinsei_file_t_inlN(this,(const wchar_t*)path,len,open_mode,owner);
	#endif
}
bool shinsei_file_t_openU16(shinsei_file_t*const restrict this,const char16_t*const restrict path,const size_t len,int open_mode,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		if(__builtin_expect(!len,0)) return false;
		register const size_t res=uTF16ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return false;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return false;
		}
		cvt_buf[res]=L'\0';
		return shinsei_file_t_openN(this,cvt_buf,res,open_mode,owner);
	#else
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return shinsei_file_t_openN(this,(const wchar_t*)path,len,open_mode,owner);
	#endif
}

// Exported File Constructors (U32 -> W)
shinsei_file_t* shinsei_file_t_conU32(const char32_t*const restrict path,const size_t len,int open_mode,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return shinsei_file_t_conN((const wchar_t*)path,len,open_mode,owner);
	#else
		if(__builtin_expect(!len,0)) return nullptr;
		register const size_t res=uTF32ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return nullptr;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return nullptr;
		}
		cvt_buf[res]=L'\0';
		return shinsei_file_t_conN(cvt_buf,res,open_mode,owner);
	#endif
}
bool shinsei_file_t_asU32(shinsei_file_t*const restrict this,const char32_t*const restrict path,const size_t len,int open_mode,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return shinsei_file_t_asN(this,(const wchar_t*)path,len,open_mode,owner);
	#else
		if(__builtin_expect(!len,0)) return false;
		register const size_t res=uTF32ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return false;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return false;
		}
		cvt_buf[res]=L'\0';
		return shinsei_file_t_asN(this,cvt_buf,res,open_mode,owner);
	#endif
}
bool shinsei_file_t_inlU32(shinsei_file_t*const restrict this,const char32_t*const restrict path,const size_t len,int open_mode,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return shinsei_file_t_inlN(this,(const wchar_t*)path,len,open_mode,owner);
	#else
		if(__builtin_expect(!len,0)) return false;
		register const size_t res=uTF32ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return false;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return false;
		}
		cvt_buf[res]=L'\0';
		return shinsei_file_t_inlN(this,cvt_buf,res,open_mode,owner);
	#endif
}
bool shinsei_file_t_openU32(shinsei_file_t*const restrict this,const char32_t*const restrict path,const size_t len,int open_mode,int owner,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return shinsei_file_t_openN(this,(const wchar_t*)path,len,open_mode,owner);
	#else
		if(__builtin_expect(!len,0)) return false;
		register const size_t res=uTF32ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return false;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return false;
		}
		cvt_buf[res]=L'\0';
		return shinsei_file_t_openN(this,cvt_buf,res,open_mode,owner);
	#endif
}

// Common Object & IO Operations

void shinsei_file_t_dec(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(fil_isOpened(this)) fil_close(this);
	__builtin_free(this);
	return;
}

bool shinsei_file_t_isOpened(const shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return fil_isOpened(this);
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
	DWORD read_bytes=0;
	if(__builtin_expect(!ReadFile((HANDLE)this->ptr,buf,(DWORD)(size*cnt),&read_bytes,nullptr),0)) return 0;
	return (size_t)read_bytes/size;
}

size_t shinsei_file_t_write(shinsei_file_t*const restrict this,const void*const restrict buf,size_t size,size_t cnt)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return 0;
	DWORD written_bytes=0;
	if(__builtin_expect(!WriteFile((HANDLE)this->ptr,buf,(DWORD)(size*cnt),&written_bytes,nullptr),0)) return 0;
	return (size_t)written_bytes/size;
}

uint_fast64_t shinsei_file_t_tell(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return 0;
	LARGE_INTEGER li={0};
	SetFilePointerEx((HANDLE)this->ptr,li,&li,FILE_CURRENT);
	return (uint_fast64_t)li.QuadPart;
}

bool shinsei_file_t_seek(shinsei_file_t*const restrict this,int_fast64_t offset,int origin)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return false;
	LARGE_INTEGER li;
	li.QuadPart=(LONGLONG)offset;
	
	DWORD moveMethod;
	switch(origin){
		case SHINSEI_FILE_SEEK_SET: moveMethod=FILE_BEGIN; break;
		case SHINSEI_FILE_SEEK_CUR: moveMethod=FILE_CURRENT; break;
		case SHINSEI_FILE_SEEK_END: moveMethod=FILE_END; break;
		default: return false;
	}
	
	return SetFilePointerEx((HANDLE)this->ptr,li,nullptr,moveMethod)!=0;
}

void shinsei_file_t_rewind(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr!=nullptr,1)){
		LARGE_INTEGER li={0};
		SetFilePointerEx((HANDLE)this->ptr,li,nullptr,FILE_BEGIN);
	}
	return;
}

bool shinsei_file_t_flush(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return false;
	return FlushFileBuffers((HANDLE)this->ptr)!=0;
}

int shinsei_file_t_getChar(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return SHINSEI_FILE_EOF;
	unsigned char ch;
	DWORD read_bytes=0;
	if(__builtin_expect(ReadFile((HANDLE)this->ptr,&ch,1,&read_bytes,nullptr)&&read_bytes==1,1)) return (int)ch;
	return SHINSEI_FILE_EOF;
}

bool shinsei_file_t_putChar(shinsei_file_t*const restrict this,int ch)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return false;
	unsigned char c=(unsigned char)ch;
	DWORD written_bytes=0;
	return WriteFile((HANDLE)this->ptr,&c,1,&written_bytes,nullptr)&&written_bytes==1;
}

void shinsei_file_t_close(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	fil_close(this);
	return;
}

// [Internal] Native Path APIs
_SHINSEI_OS_INLINE static uint_fast64_t getFileSizeW(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	(void)len;
	WIN32_FILE_ATTRIBUTE_DATA info;
	if(__builtin_expect(!GetFileAttributesExW(path,GetFileExInfoStandard,&info),0)) return (uint_fast64_t)-1;
	ULARGE_INTEGER ull;
	ull.LowPart=info.nFileSizeLow;
	ull.HighPart=info.nFileSizeHigh;
	return (uint_fast64_t)ull.QuadPart;
}

// Exported Path APIs (N)
uint_fast64_t shinsei_getFileSizeN(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return getFileSizeW(path,len);
}

// Exported Path APIs (W - Direct pass/copy)
uint_fast64_t shinsei_getFileSizeW(const wchar_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	(void)cvt_buf;
	(void)cvt_len;
	(void)needed_len;
	return getFileSizeW(path,len);
}

// Exported Path APIs (U8 -> W)
uint_fast64_t shinsei_getFileSizeU8(const char8_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return (uint_fast64_t)-1;
	#ifdef _SHINSEI_WCHAR_U32
		register const size_t res=uTF8ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
	#else
		register const size_t res=uTF8ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
	#endif
	if(__builtin_expect(!res,0)) return (uint_fast64_t)-1;
	if(__builtin_expect(res>=cvt_len,0)){
		if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
		return (uint_fast64_t)-1;
	}
	cvt_buf[res]=L'\0';
	return getFileSizeW(cvt_buf,res);
}

// Exported Path APIs (U16 -> W)
uint_fast64_t shinsei_getFileSizeU16(const char16_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		if(__builtin_expect(!len,0)) return (uint_fast64_t)-1;
		register const size_t res=uTF16ToUTF32((char32_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return (uint_fast64_t)-1;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return (uint_fast64_t)-1;
		}
		cvt_buf[res]=L'\0';
		return getFileSizeW(cvt_buf,res);
	#else
		if(__builtin_expect(!len,0)) return (uint_fast64_t)-1;
		if(__builtin_expect(len>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=len+1;
			return (uint_fast64_t)-1;
		}
		__builtin_memcpy(cvt_buf,path,len*sizeof(char16_t));
		cvt_buf[len]=L'\0';
		return getFileSizeW(cvt_buf,len);
	#endif
}

// Exported Path APIs (U32 -> W)
uint_fast64_t shinsei_getFileSizeU32(const char32_t*const restrict path,const size_t len,wchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		(void)cvt_buf;
		(void)cvt_len;
		(void)needed_len;
		return getFileSizeW((const wchar_t*)path,len);
	#else
		if(__builtin_expect(!len,0)) return (uint_fast64_t)-1;
		register const size_t res=uTF32ToUTF16((char16_t*)cvt_buf,cvt_len,path,len);
		if(__builtin_expect(!res,0)) return (uint_fast64_t)-1;
		if(__builtin_expect(res>=cvt_len,0)){
			if(__builtin_expect(needed_len!=nullptr,1)) *needed_len=res+1;
			return (uint_fast64_t)-1;
		}
		cvt_buf[res]=L'\0';
		return getFileSizeW(cvt_buf,res);
	#endif
}

// Common Object & IO Operations (Append)
uint_fast64_t shinsei_file_t_getSize(const shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return (uint_fast64_t)-1;
	LARGE_INTEGER li;
	if(__builtin_expect(!GetFileSizeEx((HANDLE)this->ptr,&li),0)) return (uint_fast64_t)-1;
	return (uint_fast64_t)li.QuadPart;
}

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif
#include"shinsei/str.h"

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

#ifdef _SHINSEI_OS_ATOMIC
	static struct _SHINSEI_OS_ALIGN_BYTE{
		volatile unsigned int code_page;
	}cur_mem={0};
#else
	static struct _SHINSEI_OS_ALIGN_BYTE{
		INIT_ONCE init_ansi;
		unsigned int code_page;
	}cur_mem={
		.init_ansi=INIT_ONCE_STATIC_INIT
	};
	
	static BOOL WINAPI initANSICallback(PINIT_ONCE init_once,PVOID para,PVOID* ptr_context)_SHINSEI_OS_NOEXCEPT{
		(void)init_once;
		(void)para;
		(void)ptr_context;
		cur_mem.code_page=GetACP();
		return TRUE;
	}
#endif

_SHINSEI_OS_INLINE static unsigned int systemCP()_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_OS_ATOMIC
		register unsigned int cp=cur_mem.code_page;
		if(__builtin_expect(!cp,0)){
			register unsigned int new_cp=GetACP();
			#ifdef _SHINSEI_OS_MSVC
				register unsigned int prev=(unsigned int)_InterlockedCompareExchange((volatile long*)&cur_mem.code_page,(long)new_cp,0);
				cp=prev+!prev*new_cp;
			#else
				unsigned int expected=0;
				__atomic_compare_exchange_n(&cur_mem.code_page,&expected,new_cp,0,__ATOMIC_ACQ_REL,__ATOMIC_RELAXED);
				cp=expected+!expected*new_cp;
			#endif
		}
		return cp;
	#else
		InitOnceExecuteOnce(&cur_mem.init_ansi,initANSICallback,nullptr,nullptr);
		return cur_mem.code_page;
	#endif
}

unsigned int shinsei_systemCP()_SHINSEI_OS_NOEXCEPT{
	return systemCP();
}

int shinsei_charSizeA(const int starter_ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_charSizeCP(systemCP(),starter_ch,0,0,nullptr);
}
int shinsei_charSizeN(const wint_t starter_ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_charSizeW(starter_ch);
}

bool shinsei_isBDigitA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isBDigitCP(systemCP(),ch);
}
bool shinsei_isBDigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isBDigitCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isBDigitN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isBDigitW(ch);
}
bool shinsei_isBDigitNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isBDigitWM(str_ptr,len);
}

bool shinsei_isODigitA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isODigitCP(systemCP(),ch);
}
bool shinsei_isODigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isODigitCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isODigitN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isODigitW(ch);
}
bool shinsei_isODigitNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isODigitWM(str_ptr,len);
}

bool shinsei_isDigitA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isDigitCP(systemCP(),ch);
}
bool shinsei_isDigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isDigitCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isDigitN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isDigitW(ch);
}
bool shinsei_isDigitNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isDigitWM(str_ptr,len);
}

bool shinsei_isXDigitA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isXDigitCP(systemCP(),ch);
}
bool shinsei_isXDigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isXDigitCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isXDigitN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isXDigitW(ch);
}
bool shinsei_isXDigitNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isXDigitWM(str_ptr,len);
}

bool shinsei_isUpperA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isUpperCP(systemCP(),ch);
}
bool shinsei_isUpperAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isUpperCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isUpperN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isUpperW(ch);
}
bool shinsei_isUpperNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isUpperWM(str_ptr,len);
}

bool shinsei_isLowerA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isLowerCP(systemCP(),ch);
}
bool shinsei_isLowerAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isLowerCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isLowerN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isLowerW(ch);
}
bool shinsei_isLowerNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isLowerWM(str_ptr,len);
}

bool shinsei_isAlphaA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isAlphaCP(systemCP(),ch);
}
bool shinsei_isAlphaAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isAlphaCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isAlphaN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isAlphaW(ch);
}
bool shinsei_isAlphaNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isAlphaWM(str_ptr,len);
}

bool shinsei_isAlnumA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isAlnumCP(systemCP(),ch);
}
bool shinsei_isAlnumAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isAlnumCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isAlnumN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isAlnumW(ch);
}
bool shinsei_isAlnumNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isAlnumWM(str_ptr,len);
}

bool shinsei_isBlankA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isBlankCP(systemCP(),ch);
}
bool shinsei_isBlankAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isBlankCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isBlankN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isBlankW(ch);
}
bool shinsei_isBlankNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isBlankWM(str_ptr,len);
}

bool shinsei_isCntrlA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isCntrlCP(systemCP(),ch);
}
bool shinsei_isCntrlAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isCntrlCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isCntrlN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isCntrlW(ch);
}
bool shinsei_isCntrlNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isCntrlWM(str_ptr,len);
}

bool shinsei_isPrintA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isPrintCP(systemCP(),ch);
}
bool shinsei_isPrintAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isPrintCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isPrintN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isPrintW(ch);
}
bool shinsei_isPrintNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isPrintWM(str_ptr,len);
}

bool shinsei_isGraphA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isGraphCP(systemCP(),ch);
}
bool shinsei_isGraphAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isGraphCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isGraphN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isGraphW(ch);
}
bool shinsei_isGraphNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isGraphWM(str_ptr,len);
}

bool shinsei_isPunctA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isPunctCP(systemCP(),ch);
}
bool shinsei_isPunctAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isPunctCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isPunctN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isPunctW(ch);
}
bool shinsei_isPunctNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isPunctWM(str_ptr,len);
}

bool shinsei_isSpaceA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isSpaceCP(systemCP(),ch);
}
bool shinsei_isSpaceAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isSpaceCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isSpaceN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isSpaceW(ch);
}
bool shinsei_isSpaceNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isSpaceWM(str_ptr,len);
}

bool shinsei_isJSONWhitespaceA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isJSONWhitespaceCP(systemCP(),ch);
}
bool shinsei_isJSONWhitespaceAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isJSONWhitespaceCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isJSONWhitespaceN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isJSONWhitespaceW(ch);
}
bool shinsei_isJSONWhitespaceNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isJSONWhitespaceWM(str_ptr,len);
}

int shinsei_toUpperA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_toUpperCP(systemCP(),ch);
}
int shinsei_toUpperAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_toUpperCPM(systemCP(),str_ptr,len,nullptr);
}
wint_t shinsei_toUpperN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_toUpperW(ch);
}
wint_t shinsei_toUpperNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_toUpperWM(str_ptr,len);
}

int shinsei_toLowerA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_toLowerCP(systemCP(),ch);
}
int shinsei_toLowerAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_toLowerCPM(systemCP(),str_ptr,len,nullptr);
}
wint_t shinsei_toLowerN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_toLowerW(ch);
}
wint_t shinsei_toLowerNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_toLowerWM(str_ptr,len);
}

int shinsei_isHexColorA(const char*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// len: Size of the string buffer in character units.
	// Possible length: 3 ("123"), 4 ("#123"), 6("123456") and 7("#123456")
	return shinsei_isHexColorCP(systemCP(),str,len);
}
int shinsei_isHexColorN(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// len: Size of the string buffer in character units.
	// Possible length: 3 ("123"), 4 ("#123"), 6("123456") and 7("#123456")
	return shinsei_isHexColorW(str,len);
}

size_t shinsei_stringLinesA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	return shinsei_stringLinesCP(systemCP(),idx_buf,idx_buf_len,str,str_len);
}
size_t shinsei_stringLinesN(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	return shinsei_stringLinesW(idx_buf,idx_buf_len,str,str_len);
}

size_t shinsei_findStringsA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	return shinsei_findStringsCP(systemCP(),idx_buf,idx_buf_len,str,str_len);
}
size_t shinsei_findStringsN(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	return shinsei_findStringsW(idx_buf,idx_buf_len,str,str_len);
}

size_t shinsei_splitStringToPartsA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char delimiter)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToPartsCP(systemCP(),des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
}
size_t shinsei_splitStringToPartsN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const wchar_t delimiter)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToPartsW(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
}

size_t shinsei_strLenA(const char*const restrict str)_SHINSEI_OS_NOEXCEPT{
	return __builtin_strlen(str);
}
size_t shinsei_strLenN(const wchar_t*const restrict str)_SHINSEI_OS_NOEXCEPT{
	return wcslen(str);
}

void shinsei_strCpyA(char*const restrict des,const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	__builtin_memcpy(des,src,len*sizeof(char));
	des[len]=0;
	return;
}
void shinsei_strCpyN(wchar_t*const restrict des,const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	__builtin_memcpy(des,src,len*sizeof(wchar_t));
	des[len]=0;
	return;
}

size_t shinsei_strCatA(char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	__builtin_memcpy(des+des_len,src,src_len*sizeof(char));
	register const size_t res=des_len+src_len;
	des[res]=0;
	return res;
}
size_t shinsei_strCatN(wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	__builtin_memcpy(des+des_len,src,src_len*sizeof(wchar_t));
	register const size_t res=des_len+src_len;
	des[res]=0;
	return res;
}

int shinsei_strCmpA(const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	register const size_t min_len=(des_len<src_len)*des_len+(des_len>=src_len)*src_len;
	register const int res=__builtin_memcmp(des,src,min_len*sizeof(char));
	return (res>0)-(res<0)+!res*((des_len>src_len)-(des_len<src_len));
}
int shinsei_strCmpN(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	register const size_t min_len=(des_len<src_len)*des_len+(des_len>=src_len)*src_len;
	register const int res=__builtin_memcmp(des,src,min_len*sizeof(wchar_t));
	return (res>0)-(res<0)+!res*((des_len>src_len)-(des_len<src_len));
}

size_t shinsei_strChrA(const char*const restrict des,const size_t des_len,const char src)_SHINSEI_OS_NOEXCEPT{
	register const void* res=__builtin_memchr(des,src,des_len);
	return (res==nullptr)*SIZE_MAX+(res!=nullptr)*(size_t)((const char*)res-des);
}
size_t shinsei_strChrN(const wchar_t*const restrict des,const size_t des_len,const wchar_t src)_SHINSEI_OS_NOEXCEPT{
	register const void* res=(const void*)(size_t)wmemchr((const wchar_t*)des,src,des_len);
	return (res==nullptr)*SIZE_MAX+(res!=nullptr)*(size_t)((const wchar_t*)res-des);
}

size_t shinsei_strStrA(const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(__builtin_expect(des_len<src_len,0)) return SIZE_MAX;
	register const size_t limit=des_len-src_len;
	for(register size_t i=0;i<=limit;++i){
		if(!__builtin_memcmp(des+i,src,src_len*sizeof(char))) return i;
	}
	return SIZE_MAX;
}
size_t shinsei_strStrN(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(__builtin_expect(des_len<src_len,0)) return SIZE_MAX;
	register const size_t limit=des_len-src_len;
	for(register size_t i=0;i<=limit;++i){
		if(!__builtin_memcmp(des+i,src,src_len*sizeof(wchar_t))) return i;
	}
	return SIZE_MAX;
}

size_t shinsei_strKMPA(const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(__builtin_expect(des_len<src_len,0)) return SIZE_MAX;
	if(__builtin_expect(buf_len<src_len,0)) return SIZE_MAX;
	buf[0]=0;
	register size_t len=0;
	for(register size_t i=1;i<src_len;){
		if(src[i]==src[len]) buf[i++]=++len;
		else if(len) len=buf[len-1];
		else buf[i++]=0;
	}
	register size_t i=0,j=0;
	while(i<des_len){
		if(src[j]==des[i]){ ++i; ++j; }
		if(j==src_len) return i-j;
		else if(i<des_len&&src[j]!=des[i]){
			if(j) j=buf[j-1];
			else ++i;
		}
	}
	return SIZE_MAX;
}
size_t shinsei_strKMPN(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(__builtin_expect(des_len<src_len,0)) return SIZE_MAX;
	if(__builtin_expect(buf_len<src_len,0)) return SIZE_MAX;
	buf[0]=0;
	register size_t len=0;
	for(register size_t i=1;i<src_len;){
		if(src[i]==src[len]) buf[i++]=++len;
		else if(len) len=buf[len-1];
		else buf[i++]=0;
	}
	register size_t i=0,j=0;
	while(i<des_len){
		if(src[j]==des[i]){ ++i; ++j; }
		if(j==src_len) return i-j;
		else if(i<des_len&&src[j]!=des[i]){
			if(j) j=buf[j-1];
			else ++i;
		}
	}
	return SIZE_MAX;
}

// Int8/UInt8 string converters (A)
size_t shinsei_uInt8ToStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToStringCP(systemCP(),des,src);
}
size_t shinsei_uInt8ToBinStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToBinStringCP(systemCP(),des,src);
}
size_t shinsei_uInt8ToOctStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToOctStringCP(systemCP(),des,src);
}
size_t shinsei_uInt8ToHexStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToHexStringCP(systemCP(),des,src);
}
size_t shinsei_uInt8ToBase36StringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToBase36StringCP(systemCP(),des,src);
}
size_t shinsei_uInt8ToBase62StringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToBase62StringCP(systemCP(),des,src);
}
size_t shinsei_int8ToStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToStringCP(systemCP(),des,src);
}
size_t shinsei_int8ToBinStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToBinStringCP(systemCP(),des,src);
}
size_t shinsei_int8ToOctStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToOctStringCP(systemCP(),des,src);
}
size_t shinsei_int8ToHexStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToHexStringCP(systemCP(),des,src);
}
size_t shinsei_int8ToBase36StringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToBase36StringCP(systemCP(),des,src);
}
size_t shinsei_int8ToBase62StringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToBase62StringCP(systemCP(),des,src);
}

// Int8/UInt8 string converters (N)
size_t shinsei_uInt8ToStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToStringW(des,src);
}
size_t shinsei_uInt8ToBinStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToBinStringW(des,src);
}
size_t shinsei_uInt8ToOctStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToOctStringW(des,src);
}
size_t shinsei_uInt8ToHexStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToHexStringW(des,src);
}
size_t shinsei_uInt8ToBase36StringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToBase36StringW(des,src);
}
size_t shinsei_uInt8ToBase62StringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToBase62StringW(des,src);
}
size_t shinsei_int8ToStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToStringW(des,src);
}
size_t shinsei_int8ToBinStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToBinStringW(des,src);
}
size_t shinsei_int8ToOctStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToOctStringW(des,src);
}
size_t shinsei_int8ToHexStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToHexStringW(des,src);
}
size_t shinsei_int8ToBase36StringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToBase36StringW(des,src);
}
size_t shinsei_int8ToBase62StringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToBase62StringW(des,src);
}

// Int16/UInt16 string converters (A)
size_t shinsei_uInt16ToStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToStringCP(systemCP(),des,src);
}
size_t shinsei_uInt16ToBinStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToBinStringCP(systemCP(),des,src);
}
size_t shinsei_uInt16ToOctStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToOctStringCP(systemCP(),des,src);
}
size_t shinsei_uInt16ToHexStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToHexStringCP(systemCP(),des,src);
}
size_t shinsei_uInt16ToBase36StringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToBase36StringCP(systemCP(),des,src);
}
size_t shinsei_uInt16ToBase62StringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToBase62StringCP(systemCP(),des,src);
}
size_t shinsei_int16ToStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToStringCP(systemCP(),des,src);
}
size_t shinsei_int16ToBinStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToBinStringCP(systemCP(),des,src);
}
size_t shinsei_int16ToOctStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToOctStringCP(systemCP(),des,src);
}
size_t shinsei_int16ToHexStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToHexStringCP(systemCP(),des,src);
}
size_t shinsei_int16ToBase36StringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToBase36StringCP(systemCP(),des,src);
}
size_t shinsei_int16ToBase62StringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToBase62StringCP(systemCP(),des,src);
}

// Int16/UInt16 string converters (N)
size_t shinsei_uInt16ToStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToStringW(des,src);
}
size_t shinsei_uInt16ToBinStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToBinStringW(des,src);
}
size_t shinsei_uInt16ToOctStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToOctStringW(des,src);
}
size_t shinsei_uInt16ToHexStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToHexStringW(des,src);
}
size_t shinsei_uInt16ToBase36StringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToBase36StringW(des,src);
}
size_t shinsei_uInt16ToBase62StringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToBase62StringW(des,src);
}
size_t shinsei_int16ToStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToStringW(des,src);
}
size_t shinsei_int16ToBinStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToBinStringW(des,src);
}
size_t shinsei_int16ToOctStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToOctStringW(des,src);
}
size_t shinsei_int16ToHexStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToHexStringW(des,src);
}
size_t shinsei_int16ToBase36StringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToBase36StringW(des,src);
}
size_t shinsei_int16ToBase62StringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToBase62StringW(des,src);
}

// Int32/UInt32 string converters (A)
size_t shinsei_uInt32ToStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToStringCP(systemCP(),des,src);
}
size_t shinsei_uInt32ToBinStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToBinStringCP(systemCP(),des,src);
}
size_t shinsei_uInt32ToOctStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToOctStringCP(systemCP(),des,src);
}
size_t shinsei_uInt32ToHexStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToHexStringCP(systemCP(),des,src);
}
size_t shinsei_uInt32ToBase36StringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToBase36StringCP(systemCP(),des,src);
}
size_t shinsei_uInt32ToBase62StringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToBase62StringCP(systemCP(),des,src);
}
size_t shinsei_int32ToStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToStringCP(systemCP(),des,src);
}
size_t shinsei_int32ToBinStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToBinStringCP(systemCP(),des,src);
}
size_t shinsei_int32ToOctStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToOctStringCP(systemCP(),des,src);
}
size_t shinsei_int32ToHexStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToHexStringCP(systemCP(),des,src);
}
size_t shinsei_int32ToBase36StringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToBase36StringCP(systemCP(),des,src);
}
size_t shinsei_int32ToBase62StringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToBase62StringCP(systemCP(),des,src);
}

// Int32/UInt32 string converters (N)
size_t shinsei_uInt32ToStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToStringW(des,src);
}
size_t shinsei_uInt32ToBinStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToBinStringW(des,src);
}
size_t shinsei_uInt32ToOctStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToOctStringW(des,src);
}
size_t shinsei_uInt32ToHexStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToHexStringW(des,src);
}
size_t shinsei_uInt32ToBase36StringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToBase36StringW(des,src);
}
size_t shinsei_uInt32ToBase62StringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToBase62StringW(des,src);
}
size_t shinsei_int32ToStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToStringW(des,src);
}
size_t shinsei_int32ToBinStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToBinStringW(des,src);
}
size_t shinsei_int32ToOctStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToOctStringW(des,src);
}
size_t shinsei_int32ToHexStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToHexStringW(des,src);
}
size_t shinsei_int32ToBase36StringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToBase36StringW(des,src);
}
size_t shinsei_int32ToBase62StringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToBase62StringW(des,src);
}

// Int64/UInt64 string converters (A)
size_t shinsei_uInt64ToStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToStringCP(systemCP(),des,src);
}
size_t shinsei_uInt64ToBinStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToBinStringCP(systemCP(),des,src);
}
size_t shinsei_uInt64ToOctStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToOctStringCP(systemCP(),des,src);
}
size_t shinsei_uInt64ToHexStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToHexStringCP(systemCP(),des,src);
}
size_t shinsei_uInt64ToBase36StringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToBase36StringCP(systemCP(),des,src);
}
size_t shinsei_uInt64ToBase62StringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToBase62StringCP(systemCP(),des,src);
}
size_t shinsei_int64ToStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToStringCP(systemCP(),des,src);
}
size_t shinsei_int64ToBinStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToBinStringCP(systemCP(),des,src);
}
size_t shinsei_int64ToOctStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToOctStringCP(systemCP(),des,src);
}
size_t shinsei_int64ToHexStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToHexStringCP(systemCP(),des,src);
}
size_t shinsei_int64ToBase36StringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToBase36StringCP(systemCP(),des,src);
}
size_t shinsei_int64ToBase62StringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToBase62StringCP(systemCP(),des,src);
}

// Int64/UInt64 string converters (N)
size_t shinsei_uInt64ToStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToStringW(des,src);
}
size_t shinsei_uInt64ToBinStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToBinStringW(des,src);
}
size_t shinsei_uInt64ToOctStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToOctStringW(des,src);
}
size_t shinsei_uInt64ToHexStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToHexStringW(des,src);
}
size_t shinsei_uInt64ToBase36StringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToBase36StringW(des,src);
}
size_t shinsei_uInt64ToBase62StringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToBase62StringW(des,src);
}
size_t shinsei_int64ToStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToStringW(des,src);
}
size_t shinsei_int64ToBinStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToBinStringW(des,src);
}
size_t shinsei_int64ToOctStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToOctStringW(des,src);
}
size_t shinsei_int64ToHexStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToHexStringW(des,src);
}
size_t shinsei_int64ToBase36StringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToBase36StringW(des,src);
}
size_t shinsei_int64ToBase62StringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToBase62StringW(des,src);
}

// String to int8/uint8 converters (A)
uint_fast8_t shinsei_stringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToUInt8CP(systemCP(),src,len);
}
uint_fast8_t shinsei_binStringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToUInt8CP(systemCP(),src,len);
}
uint_fast8_t shinsei_octStringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToUInt8CP(systemCP(),src,len);
}
uint_fast8_t shinsei_hexStringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToUInt8CP(systemCP(),src,len);
}
uint_fast8_t shinsei_base36StringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToUInt8CP(systemCP(),src,len);
}
uint_fast8_t shinsei_base62StringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToUInt8CP(systemCP(),src,len);
}

int_fast8_t shinsei_stringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToInt8CP(systemCP(),src,len);
}
int_fast8_t shinsei_binStringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToInt8CP(systemCP(),src,len);
}
int_fast8_t shinsei_octStringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToInt8CP(systemCP(),src,len);
}
int_fast8_t shinsei_hexStringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToInt8CP(systemCP(),src,len);
}
int_fast8_t shinsei_base36StringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToInt8CP(systemCP(),src,len);
}
int_fast8_t shinsei_base62StringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToInt8CP(systemCP(),src,len);
}

// String to int8/uint8 converters (N)
uint_fast8_t shinsei_stringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToUInt8W(src,len);
}
uint_fast8_t shinsei_binStringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToUInt8W(src,len);
}
uint_fast8_t shinsei_octStringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToUInt8W(src,len);
}
uint_fast8_t shinsei_hexStringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToUInt8W(src,len);
}
uint_fast8_t shinsei_base36StringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToUInt8W(src,len);
}
uint_fast8_t shinsei_base62StringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToUInt8W(src,len);
}

int_fast8_t shinsei_stringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToInt8W(src,len);
}
int_fast8_t shinsei_binStringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToInt8W(src,len);
}
int_fast8_t shinsei_octStringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToInt8W(src,len);
}
int_fast8_t shinsei_hexStringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToInt8W(src,len);
}
int_fast8_t shinsei_base36StringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToInt8W(src,len);
}
int_fast8_t shinsei_base62StringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToInt8W(src,len);
}

// Int16/UInt16 string converters (A)
uint_fast16_t shinsei_stringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToUInt16CP(systemCP(),src,len);
}
uint_fast16_t shinsei_binStringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToUInt16CP(systemCP(),src,len);
}
uint_fast16_t shinsei_octStringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToUInt16CP(systemCP(),src,len);
}
uint_fast16_t shinsei_hexStringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToUInt16CP(systemCP(),src,len);
}
uint_fast16_t shinsei_base36StringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToUInt16CP(systemCP(),src,len);
}
uint_fast16_t shinsei_base62StringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToUInt16CP(systemCP(),src,len);
}

int_fast16_t shinsei_stringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToInt16CP(systemCP(),src,len);
}
int_fast16_t shinsei_binStringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToInt16CP(systemCP(),src,len);
}
int_fast16_t shinsei_octStringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToInt16CP(systemCP(),src,len);
}
int_fast16_t shinsei_hexStringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToInt16CP(systemCP(),src,len);
}
int_fast16_t shinsei_base36StringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToInt16CP(systemCP(),src,len);
}
int_fast16_t shinsei_base62StringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToInt16CP(systemCP(),src,len);
}

// Int16/UInt16 string converters (N)
uint_fast16_t shinsei_stringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToUInt16W(src,len);
}
uint_fast16_t shinsei_binStringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToUInt16W(src,len);
}
uint_fast16_t shinsei_octStringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToUInt16W(src,len);
}
uint_fast16_t shinsei_hexStringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToUInt16W(src,len);
}
uint_fast16_t shinsei_base36StringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToUInt16W(src,len);
}
uint_fast16_t shinsei_base62StringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToUInt16W(src,len);
}

int_fast16_t shinsei_stringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToInt16W(src,len);
}
int_fast16_t shinsei_binStringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToInt16W(src,len);
}
int_fast16_t shinsei_octStringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToInt16W(src,len);
}
int_fast16_t shinsei_hexStringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToInt16W(src,len);
}
int_fast16_t shinsei_base36StringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToInt16W(src,len);
}
int_fast16_t shinsei_base62StringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToInt16W(src,len);
}

// Int32/UInt32 string converters (A)
uint_fast32_t shinsei_stringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToUInt32CP(systemCP(),src,len);
}
uint_fast32_t shinsei_binStringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToUInt32CP(systemCP(),src,len);
}
uint_fast32_t shinsei_octStringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToUInt32CP(systemCP(),src,len);
}
uint_fast32_t shinsei_hexStringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToUInt32CP(systemCP(),src,len);
}
uint_fast32_t shinsei_base36StringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToUInt32CP(systemCP(),src,len);
}
uint_fast32_t shinsei_base62StringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToUInt32CP(systemCP(),src,len);
}

int_fast32_t shinsei_stringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToInt32CP(systemCP(),src,len);
}
int_fast32_t shinsei_binStringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToInt32CP(systemCP(),src,len);
}
int_fast32_t shinsei_octStringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToInt32CP(systemCP(),src,len);
}
int_fast32_t shinsei_hexStringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToInt32CP(systemCP(),src,len);
}
int_fast32_t shinsei_base36StringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToInt32CP(systemCP(),src,len);
}
int_fast32_t shinsei_base62StringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToInt32CP(systemCP(),src,len);
}

// Int32/UInt32 string converters (N)
uint_fast32_t shinsei_stringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToUInt32W(src,len);
}
uint_fast32_t shinsei_binStringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToUInt32W(src,len);
}
uint_fast32_t shinsei_octStringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToUInt32W(src,len);
}
uint_fast32_t shinsei_hexStringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToUInt32W(src,len);
}
uint_fast32_t shinsei_base36StringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToUInt32W(src,len);
}
uint_fast32_t shinsei_base62StringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToUInt32W(src,len);
}

int_fast32_t shinsei_stringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToInt32W(src,len);
}
int_fast32_t shinsei_binStringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToInt32W(src,len);
}
int_fast32_t shinsei_octStringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToInt32W(src,len);
}
int_fast32_t shinsei_hexStringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToInt32W(src,len);
}
int_fast32_t shinsei_base36StringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToInt32W(src,len);
}
int_fast32_t shinsei_base62StringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToInt32W(src,len);
}

// Int64/UInt64 string converters (A)
uint_fast64_t shinsei_stringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToUInt64CP(systemCP(),src,len);
}
uint_fast64_t shinsei_binStringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToUInt64CP(systemCP(),src,len);
}
uint_fast64_t shinsei_octStringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToUInt64CP(systemCP(),src,len);
}
uint_fast64_t shinsei_hexStringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToUInt64CP(systemCP(),src,len);
}
uint_fast64_t shinsei_base36StringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToUInt64CP(systemCP(),src,len);
}
uint_fast64_t shinsei_base62StringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToUInt64CP(systemCP(),src,len);
}

int_fast64_t shinsei_stringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToInt64CP(systemCP(),src,len);
}
int_fast64_t shinsei_binStringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToInt64CP(systemCP(),src,len);
}
int_fast64_t shinsei_octStringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToInt64CP(systemCP(),src,len);
}
int_fast64_t shinsei_hexStringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToInt64CP(systemCP(),src,len);
}
int_fast64_t shinsei_base36StringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToInt64CP(systemCP(),src,len);
}
int_fast64_t shinsei_base62StringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToInt64CP(systemCP(),src,len);
}

// Int64/UInt64 string converters (N)
uint_fast64_t shinsei_stringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToUInt64W(src,len);
}
uint_fast64_t shinsei_binStringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToUInt64W(src,len);
}
uint_fast64_t shinsei_octStringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToUInt64W(src,len);
}
uint_fast64_t shinsei_hexStringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToUInt64W(src,len);
}
uint_fast64_t shinsei_base36StringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToUInt64W(src,len);
}
uint_fast64_t shinsei_base62StringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToUInt64W(src,len);
}

int_fast64_t shinsei_stringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToInt64W(src,len);
}
int_fast64_t shinsei_binStringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToInt64W(src,len);
}
int_fast64_t shinsei_octStringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToInt64W(src,len);
}
int_fast64_t shinsei_hexStringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToInt64W(src,len);
}
int_fast64_t shinsei_base36StringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToInt64W(src,len);
}
int_fast64_t shinsei_base62StringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToInt64W(src,len);
}

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif
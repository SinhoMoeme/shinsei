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

void shinsei_uInt64ToStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_uInt64ToStringCP(systemCP(),des,src);
	return;
}
void shinsei_uInt64ToBinStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_uInt64ToBinStringCP(systemCP(),des,src);
	return;
}
void shinsei_uInt64ToOctStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_uInt64ToOctStringCP(systemCP(),des,src);
	return;
}
void shinsei_uInt64ToHexStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_uInt64ToHexStringCP(systemCP(),des,src);
	return;
}
void shinsei_uInt64To36BaseStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_uInt64To36BaseStringCP(systemCP(),des,src);
	return;
}
void shinsei_uInt64To62BaseStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_uInt64To62BaseStringCP(systemCP(),des,src);
	return;
}
void shinsei_int64ToStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_int64ToStringCP(systemCP(),des,src);
	return;
}
void shinsei_int64ToBinStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_int64ToBinStringCP(systemCP(),des,src);
	return;
}
void shinsei_int64ToOctStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_int64ToOctStringCP(systemCP(),des,src);
	return;
}
void shinsei_int64ToHexStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_int64ToHexStringCP(systemCP(),des,src);
	return;
}
void shinsei_int64To36BaseStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_int64To36BaseStringCP(systemCP(),des,src);
	return;
}
void shinsei_int64To62BaseStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_int64To62BaseStringCP(systemCP(),des,src);
	return;
}

void shinsei_uInt64ToStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_uInt64ToStringW(des,src);
	return;
}
void shinsei_uInt64ToBinStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_uInt64ToBinStringW(des,src);
	return;
}
void shinsei_uInt64ToOctStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_uInt64ToOctStringW(des,src);
	return;
}
void shinsei_uInt64ToHexStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_uInt64ToHexStringW(des,src);
	return;
}
void shinsei_uInt64To36BaseStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_uInt64To36BaseStringW(des,src);
	return;
}
void shinsei_uInt64To62BaseStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_uInt64To62BaseStringW(des,src);
	return;
}
void shinsei_int64ToStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_int64ToStringW(des,src);
	return;
}
void shinsei_int64ToBinStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_int64ToBinStringW(des,src);
	return;
}
void shinsei_int64ToOctStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_int64ToOctStringW(des,src);
	return;
}
void shinsei_int64ToHexStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_int64ToHexStringW(des,src);
	return;
}
void shinsei_int64To36BaseStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_int64To36BaseStringW(des,src);
	return;
}
void shinsei_int64To62BaseStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	shinsei_int64To62BaseStringW(des,src);
	return;
}

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif
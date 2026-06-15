#include"shinsei/str.h"

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

unsigned int shinsei_systemCP()_SHINSEI_OS_NOEXCEPT{
	return SHINSEI_CODE_PAGE_UTF_8;
}

int shinsei_charSizeA(const int starter_ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_charSizeU8((char8_t)starter_ch);
}
int shinsei_charSizeN(const char8_t starter_ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_charSizeU8(starter_ch);
}

bool shinsei_isBDigitA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isBDigitU8((char8_t)ch);
}
bool shinsei_isBDigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isBDigitU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isBDigitN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isBDigitU8(ch);
}
bool shinsei_isBDigitNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isBDigitU8M(str_ptr,len);
}

bool shinsei_isDigitA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isDigitU8((char8_t)ch);
}
bool shinsei_isDigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isDigitU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isDigitN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isDigitU8(ch);
}
bool shinsei_isDigitNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isDigitU8M(str_ptr,len);
}

bool shinsei_isXDigitA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isXDigitU8((char8_t)ch);
}
bool shinsei_isXDigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isXDigitU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isXDigitN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isXDigitU8(ch);
}
bool shinsei_isXDigitNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isXDigitU8M(str_ptr,len);
}

bool shinsei_isUpperA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isUpperU8((char8_t)ch);
}
bool shinsei_isUpperAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isUpperU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isUpperN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isUpperU8(ch);
}
bool shinsei_isUpperNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isUpperU8M(str_ptr,len);
}

bool shinsei_isLowerA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isLowerU8((char8_t)ch);
}
bool shinsei_isLowerAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isLowerU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isLowerN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isLowerU8(ch);
}
bool shinsei_isLowerNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isLowerU8M(str_ptr,len);
}

bool shinsei_isAlphaA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isAlphaU8((char8_t)ch);
}
bool shinsei_isAlphaAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isAlphaU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isAlphaN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isAlphaU8(ch);
}
bool shinsei_isAlphaNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isAlphaU8M(str_ptr,len);
}

bool shinsei_isAlnumA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isAlnumU8((char8_t)ch);
}
bool shinsei_isAlnumAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isAlnumU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isAlnumN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isAlnumU8(ch);
}
bool shinsei_isAlnumNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isAlnumU8M(str_ptr,len);
}

bool shinsei_isBlankA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isBlankU8((char8_t)ch);
}
bool shinsei_isBlankAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isBlankU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isBlankN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isBlankU8(ch);
}
bool shinsei_isBlankNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isBlankU8M(str_ptr,len);
}

bool shinsei_isCntrlA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isCntrlU8((char8_t)ch);
}
bool shinsei_isCntrlAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isCntrlU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isCntrlN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isCntrlU8(ch);
}
bool shinsei_isCntrlNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isCntrlU8M(str_ptr,len);
}

bool shinsei_isPrintA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isPrintU8((char8_t)ch);
}
bool shinsei_isPrintAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isPrintU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isPrintN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isPrintU8(ch);
}
bool shinsei_isPrintNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isPrintU8M(str_ptr,len);
}

bool shinsei_isGraphA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isGraphU8((char8_t)ch);
}
bool shinsei_isGraphAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isGraphU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isGraphN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isGraphU8(ch);
}
bool shinsei_isGraphNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isGraphU8M(str_ptr,len);
}

bool shinsei_isPunctA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isPunctU8((char8_t)ch);
}
bool shinsei_isPunctAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isPunctU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isPunctN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isPunctU8(ch);
}
bool shinsei_isPunctNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isPunctU8M(str_ptr,len);
}

bool shinsei_isODigitA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isODigitU8((char8_t)ch);
}
bool shinsei_isODigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isODigitU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isODigitN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isODigitU8(ch);
}
bool shinsei_isODigitNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isODigitU8M(str_ptr,len);
}

bool shinsei_isSpaceA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isSpaceU8((char8_t)ch);
}
bool shinsei_isSpaceAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isSpaceU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isSpaceN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isSpaceU8(ch);
}
bool shinsei_isSpaceNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isSpaceU8M(str_ptr,len);
}

bool shinsei_isJSONWhitespaceA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isJSONWhitespaceU8((char8_t)ch);
}
bool shinsei_isJSONWhitespaceAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isJSONWhitespaceU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isJSONWhitespaceN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isJSONWhitespaceU8(ch);
}
bool shinsei_isJSONWhitespaceNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isJSONWhitespaceU8M(str_ptr,len);
}

int shinsei_toUpperA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_toUpperU8((char8_t)ch);
}
int shinsei_toUpperAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_toUpperU8M((const char8_t**)str_ptr,len);
}
char8_t shinsei_toUpperN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_toUpperU8(ch);
}
char8_t shinsei_toUpperNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_toUpperU8M(str_ptr,len);
}

int shinsei_toLowerA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_toLowerU8((char8_t)ch);
}
int shinsei_toLowerAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_toLowerU8M((const char8_t**)str_ptr,len);
}
char8_t shinsei_toLowerN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_toLowerU8(ch);
}
char8_t shinsei_toLowerNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_toLowerU8M(str_ptr,len);
}

int shinsei_isHexColorA(const char*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// len: Size of the string buffer in character units.
	// Possible length: 3 ("123"), 4 ("#123"), 6("123456") and 7("#123456")
	return shinsei_isHexColorU8((const char8_t*)str,len);
}
int shinsei_isHexColorN(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// len: Size of the string buffer in character units.
	// Possible length: 3 ("123"), 4 ("#123"), 6("123456") and 7("#123456")
	return shinsei_isHexColorU8(str,len);
}

size_t shinsei_stringLinesA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	return shinsei_stringLinesU8(idx_buf,idx_buf_len,(char8_t*)str,str_len);
}
size_t shinsei_stringLinesN(size_t*restrict idx_buf,size_t idx_buf_len,char8_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	return shinsei_stringLinesU8(idx_buf,idx_buf_len,str,str_len);
}

size_t shinsei_findStringsA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	return shinsei_findStringsU8(idx_buf,idx_buf_len,(char8_t*)str,str_len);
}
size_t shinsei_findStringsN(size_t*restrict idx_buf,size_t idx_buf_len,char8_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	return shinsei_findStringsU8(idx_buf,idx_buf_len,str,str_len);
}

size_t shinsei_splitStringToPartsA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char delimiter)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToPartsU8((char8_t*)des_buf,des_buf_len,(const char8_t*)src,src_len,part_len,max_part_cnt,(char8_t)delimiter);
}
size_t shinsei_splitStringToPartsN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char8_t delimiter)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToPartsU8(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
}

size_t shinsei_strLenA(const char*const restrict str)_SHINSEI_OS_NOEXCEPT{
	return __builtin_strlen(str);
}
size_t shinsei_strLenN(const char8_t*const restrict str)_SHINSEI_OS_NOEXCEPT{
	return __builtin_strlen((const char*)str);
}

void shinsei_strCpyA(char*const restrict des,const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	__builtin_memcpy(des,src,len*sizeof(char));
	des[len]=0;
	return;
}
void shinsei_strCpyN(char8_t*const restrict des,const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	__builtin_memcpy(des,src,len*sizeof(char8_t));
	des[len]=0;
	return;
}

size_t shinsei_strCatA(char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	__builtin_memcpy(des+des_len,src,src_len*sizeof(char));
	register const size_t res=des_len+src_len;
	des[res]=0;
	return res;
}
size_t shinsei_strCatN(char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	__builtin_memcpy(des+des_len,src,src_len*sizeof(char8_t));
	register const size_t res=des_len+src_len;
	des[res]=0;
	return res;
}

int shinsei_strCmpA(const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	register const size_t min_len=(des_len<src_len)*des_len+(des_len>=src_len)*src_len;
	register const int res=__builtin_memcmp(des,src,min_len*sizeof(char));
	return (res>0)-(res<0)+!res*((des_len>src_len)-(des_len<src_len));
}
int shinsei_strCmpN(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	register const size_t min_len=(des_len<src_len)*des_len+(des_len>=src_len)*src_len;
	register const int res=__builtin_memcmp(des,src,min_len*sizeof(char8_t));
	return (res>0)-(res<0)+!res*((des_len>src_len)-(des_len<src_len));
}

size_t shinsei_strChrA(const char*const restrict des,const size_t des_len,const char src)_SHINSEI_OS_NOEXCEPT{
	register const void* res=__builtin_memchr(des,src,des_len);
	return (res==nullptr)*SIZE_MAX+(res!=nullptr)*(size_t)((const char*)res-des);
}
size_t shinsei_strChrN(const char8_t*const restrict des,const size_t des_len,const char8_t src)_SHINSEI_OS_NOEXCEPT{
	register const void* res=__builtin_memchr(des,src,des_len);
	return (res==nullptr)*SIZE_MAX+(res!=nullptr)*(size_t)((const char8_t*)res-des);
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
size_t shinsei_strStrN(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(__builtin_expect(des_len<src_len,0)) return SIZE_MAX;
	register const size_t limit=des_len-src_len;
	for(register size_t i=0;i<=limit;++i){
		if(!__builtin_memcmp(des+i,src,src_len*sizeof(char8_t))) return i;
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
size_t shinsei_strKMPN(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT{
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
	return shinsei_uInt8ToStringU8((char8_t*)des,src);
}
size_t shinsei_uInt8ToBinStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToBinStringU8((char8_t*)des,src);
}
size_t shinsei_uInt8ToOctStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToOctStringU8((char8_t*)des,src);
}
size_t shinsei_uInt8ToHexStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToHexStringU8((char8_t*)des,src);
}
size_t shinsei_uInt8ToBase36StringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToBase36StringU8((char8_t*)des,src);
}
size_t shinsei_uInt8ToBase62StringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToBase62StringU8((char8_t*)des,src);
}
size_t shinsei_int8ToStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToStringU8((char8_t*)des,src);
}
size_t shinsei_int8ToBinStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToBinStringU8((char8_t*)des,src);
}
size_t shinsei_int8ToOctStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToOctStringU8((char8_t*)des,src);
}
size_t shinsei_int8ToHexStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToHexStringU8((char8_t*)des,src);
}
size_t shinsei_int8ToBase36StringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToBase36StringU8((char8_t*)des,src);
}
size_t shinsei_int8ToBase62StringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToBase62StringU8((char8_t*)des,src);
}

// Int8/UInt8 string converters (N)
size_t shinsei_uInt8ToStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToStringU8(des,src);
}
size_t shinsei_uInt8ToBinStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToBinStringU8(des,src);
}
size_t shinsei_uInt8ToOctStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToOctStringU8(des,src);
}
size_t shinsei_uInt8ToHexStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToHexStringU8(des,src);
}
size_t shinsei_uInt8ToBase36StringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToBase36StringU8(des,src);
}
size_t shinsei_uInt8ToBase62StringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt8ToBase62StringU8(des,src);
}
size_t shinsei_int8ToStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToStringU8(des,src);
}
size_t shinsei_int8ToBinStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToBinStringU8(des,src);
}
size_t shinsei_int8ToOctStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToOctStringU8(des,src);
}
size_t shinsei_int8ToHexStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToHexStringU8(des,src);
}
size_t shinsei_int8ToBase36StringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToBase36StringU8(des,src);
}
size_t shinsei_int8ToBase62StringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int8ToBase62StringU8(des,src);
}

// Int16/UInt16 string converters (A)
size_t shinsei_uInt16ToStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToStringU8((char8_t*)des,src);
}
size_t shinsei_uInt16ToBinStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToBinStringU8((char8_t*)des,src);
}
size_t shinsei_uInt16ToOctStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToOctStringU8((char8_t*)des,src);
}
size_t shinsei_uInt16ToHexStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToHexStringU8((char8_t*)des,src);
}
size_t shinsei_uInt16ToBase36StringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToBase36StringU8((char8_t*)des,src);
}
size_t shinsei_uInt16ToBase62StringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToBase62StringU8((char8_t*)des,src);
}
size_t shinsei_int16ToStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToStringU8((char8_t*)des,src);
}
size_t shinsei_int16ToBinStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToBinStringU8((char8_t*)des,src);
}
size_t shinsei_int16ToOctStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToOctStringU8((char8_t*)des,src);
}
size_t shinsei_int16ToHexStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToHexStringU8((char8_t*)des,src);
}
size_t shinsei_int16ToBase36StringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToBase36StringU8((char8_t*)des,src);
}
size_t shinsei_int16ToBase62StringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToBase62StringU8((char8_t*)des,src);
}

// Int16/UInt16 string converters (N)
size_t shinsei_uInt16ToStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToStringU8(des,src);
}
size_t shinsei_uInt16ToBinStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToBinStringU8(des,src);
}
size_t shinsei_uInt16ToOctStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToOctStringU8(des,src);
}
size_t shinsei_uInt16ToHexStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToHexStringU8(des,src);
}
size_t shinsei_uInt16ToBase36StringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToBase36StringU8(des,src);
}
size_t shinsei_uInt16ToBase62StringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt16ToBase62StringU8(des,src);
}
size_t shinsei_int16ToStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToStringU8(des,src);
}
size_t shinsei_int16ToBinStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToBinStringU8(des,src);
}
size_t shinsei_int16ToOctStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToOctStringU8(des,src);
}
size_t shinsei_int16ToHexStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToHexStringU8(des,src);
}
size_t shinsei_int16ToBase36StringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToBase36StringU8(des,src);
}
size_t shinsei_int16ToBase62StringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int16ToBase62StringU8(des,src);
}

// Int32/UInt32 string converters (A)
size_t shinsei_uInt32ToStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToStringU8((char8_t*)des,src);
}
size_t shinsei_uInt32ToBinStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToBinStringU8((char8_t*)des,src);
}
size_t shinsei_uInt32ToOctStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToOctStringU8((char8_t*)des,src);
}
size_t shinsei_uInt32ToHexStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToHexStringU8((char8_t*)des,src);
}
size_t shinsei_uInt32ToBase36StringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToBase36StringU8((char8_t*)des,src);
}
size_t shinsei_uInt32ToBase62StringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToBase62StringU8((char8_t*)des,src);
}
size_t shinsei_int32ToStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToStringU8((char8_t*)des,src);
}
size_t shinsei_int32ToBinStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToBinStringU8((char8_t*)des,src);
}
size_t shinsei_int32ToOctStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToOctStringU8((char8_t*)des,src);
}
size_t shinsei_int32ToHexStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToHexStringU8((char8_t*)des,src);
}
size_t shinsei_int32ToBase36StringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToBase36StringU8((char8_t*)des,src);
}
size_t shinsei_int32ToBase62StringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToBase62StringU8((char8_t*)des,src);
}

// Int32/UInt32 string converters (N)
size_t shinsei_uInt32ToStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToStringU8(des,src);
}
size_t shinsei_uInt32ToBinStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToBinStringU8(des,src);
}
size_t shinsei_uInt32ToOctStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToOctStringU8(des,src);
}
size_t shinsei_uInt32ToHexStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToHexStringU8(des,src);
}
size_t shinsei_uInt32ToBase36StringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToBase36StringU8(des,src);
}
size_t shinsei_uInt32ToBase62StringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt32ToBase62StringU8(des,src);
}
size_t shinsei_int32ToStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToStringU8(des,src);
}
size_t shinsei_int32ToBinStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToBinStringU8(des,src);
}
size_t shinsei_int32ToOctStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToOctStringU8(des,src);
}
size_t shinsei_int32ToHexStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToHexStringU8(des,src);
}
size_t shinsei_int32ToBase36StringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToBase36StringU8(des,src);
}
size_t shinsei_int32ToBase62StringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int32ToBase62StringU8(des,src);
}

// Int64/UInt64 string converters (A)
size_t shinsei_uInt64ToStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToStringU8((char8_t*)des,src);
}
size_t shinsei_uInt64ToBinStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToBinStringU8((char8_t*)des,src);
}
size_t shinsei_uInt64ToOctStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToOctStringU8((char8_t*)des,src);
}
size_t shinsei_uInt64ToHexStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToHexStringU8((char8_t*)des,src);
}
size_t shinsei_uInt64ToBase36StringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToBase36StringU8((char8_t*)des,src);
}
size_t shinsei_uInt64ToBase62StringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToBase62StringU8((char8_t*)des,src);
}
size_t shinsei_int64ToStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToStringU8((char8_t*)des,src);
}
size_t shinsei_int64ToBinStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToBinStringU8((char8_t*)des,src);
}
size_t shinsei_int64ToOctStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToOctStringU8((char8_t*)des,src);
}
size_t shinsei_int64ToHexStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToHexStringU8((char8_t*)des,src);
}
size_t shinsei_int64ToBase36StringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToBase36StringU8((char8_t*)des,src);
}
size_t shinsei_int64ToBase62StringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToBase62StringU8((char8_t*)des,src);
}

// Int64/UInt64 string converters (N)
size_t shinsei_uInt64ToStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToStringU8(des,src);
}
size_t shinsei_uInt64ToBinStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToBinStringU8(des,src);
}
size_t shinsei_uInt64ToOctStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToOctStringU8(des,src);
}
size_t shinsei_uInt64ToHexStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToHexStringU8(des,src);
}
size_t shinsei_uInt64ToBase36StringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToBase36StringU8(des,src);
}
size_t shinsei_uInt64ToBase62StringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_uInt64ToBase62StringU8(des,src);
}
size_t shinsei_int64ToStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToStringU8(des,src);
}
size_t shinsei_int64ToBinStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToBinStringU8(des,src);
}
size_t shinsei_int64ToOctStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToOctStringU8(des,src);
}
size_t shinsei_int64ToHexStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToHexStringU8(des,src);
}
size_t shinsei_int64ToBase36StringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToBase36StringU8(des,src);
}
size_t shinsei_int64ToBase62StringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	return shinsei_int64ToBase62StringU8(des,src);
}

// String to int8/uint8 converters (A)
uint_fast8_t shinsei_stringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToUInt8U8((const char8_t*)src,len);
}
uint_fast8_t shinsei_binStringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToUInt8U8((const char8_t*)src,len);
}
uint_fast8_t shinsei_octStringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToUInt8U8((const char8_t*)src,len);
}
uint_fast8_t shinsei_hexStringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToUInt8U8((const char8_t*)src,len);
}
uint_fast8_t shinsei_base36StringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToUInt8U8((const char8_t*)src,len);
}
uint_fast8_t shinsei_base62StringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToUInt8U8((const char8_t*)src,len);
}

int_fast8_t shinsei_stringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToInt8U8((const char8_t*)src,len);
}
int_fast8_t shinsei_binStringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToInt8U8((const char8_t*)src,len);
}
int_fast8_t shinsei_octStringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToInt8U8((const char8_t*)src,len);
}
int_fast8_t shinsei_hexStringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToInt8U8((const char8_t*)src,len);
}
int_fast8_t shinsei_base36StringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToInt8U8((const char8_t*)src,len);
}
int_fast8_t shinsei_base62StringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToInt8U8((const char8_t*)src,len);
}

// String to int8/uint8 converters (N)
uint_fast8_t shinsei_stringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToUInt8U8(src,len);
}
uint_fast8_t shinsei_binStringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToUInt8U8(src,len);
}
uint_fast8_t shinsei_octStringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToUInt8U8(src,len);
}
uint_fast8_t shinsei_hexStringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToUInt8U8(src,len);
}
uint_fast8_t shinsei_base36StringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToUInt8U8(src,len);
}
uint_fast8_t shinsei_base62StringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToUInt8U8(src,len);
}

int_fast8_t shinsei_stringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToInt8U8(src,len);
}
int_fast8_t shinsei_binStringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToInt8U8(src,len);
}
int_fast8_t shinsei_octStringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToInt8U8(src,len);
}
int_fast8_t shinsei_hexStringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToInt8U8(src,len);
}
int_fast8_t shinsei_base36StringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToInt8U8(src,len);
}
int_fast8_t shinsei_base62StringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToInt8U8(src,len);
}

// Int16/UInt16 string converters (A)
uint_fast16_t shinsei_stringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToUInt16U8((const char8_t*)src,len);
}
uint_fast16_t shinsei_binStringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToUInt16U8((const char8_t*)src,len);
}
uint_fast16_t shinsei_octStringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToUInt16U8((const char8_t*)src,len);
}
uint_fast16_t shinsei_hexStringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToUInt16U8((const char8_t*)src,len);
}
uint_fast16_t shinsei_base36StringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToUInt16U8((const char8_t*)src,len);
}
uint_fast16_t shinsei_base62StringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToUInt16U8((const char8_t*)src,len);
}

int_fast16_t shinsei_stringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToInt16U8((const char8_t*)src,len);
}
int_fast16_t shinsei_binStringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToInt16U8((const char8_t*)src,len);
}
int_fast16_t shinsei_octStringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToInt16U8((const char8_t*)src,len);
}
int_fast16_t shinsei_hexStringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToInt16U8((const char8_t*)src,len);
}
int_fast16_t shinsei_base36StringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToInt16U8((const char8_t*)src,len);
}
int_fast16_t shinsei_base62StringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToInt16U8((const char8_t*)src,len);
}

// Int16/UInt16 string converters (N)
uint_fast16_t shinsei_stringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToUInt16U8(src,len);
}
uint_fast16_t shinsei_binStringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToUInt16U8(src,len);
}
uint_fast16_t shinsei_octStringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToUInt16U8(src,len);
}
uint_fast16_t shinsei_hexStringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToUInt16U8(src,len);
}
uint_fast16_t shinsei_base36StringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToUInt16U8(src,len);
}
uint_fast16_t shinsei_base62StringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToUInt16U8(src,len);
}

int_fast16_t shinsei_stringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToInt16U8(src,len);
}
int_fast16_t shinsei_binStringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToInt16U8(src,len);
}
int_fast16_t shinsei_octStringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToInt16U8(src,len);
}
int_fast16_t shinsei_hexStringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToInt16U8(src,len);
}
int_fast16_t shinsei_base36StringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToInt16U8(src,len);
}
int_fast16_t shinsei_base62StringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToInt16U8(src,len);
}

// Int32/UInt32 string converters (A)
uint_fast32_t shinsei_stringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToUInt32U8((const char8_t*)src,len);
}
uint_fast32_t shinsei_binStringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToUInt32U8((const char8_t*)src,len);
}
uint_fast32_t shinsei_octStringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToUInt32U8((const char8_t*)src,len);
}
uint_fast32_t shinsei_hexStringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToUInt32U8((const char8_t*)src,len);
}
uint_fast32_t shinsei_base36StringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToUInt32U8((const char8_t*)src,len);
}
uint_fast32_t shinsei_base62StringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToUInt32U8((const char8_t*)src,len);
}

int_fast32_t shinsei_stringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToInt32U8((const char8_t*)src,len);
}
int_fast32_t shinsei_binStringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToInt32U8((const char8_t*)src,len);
}
int_fast32_t shinsei_octStringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToInt32U8((const char8_t*)src,len);
}
int_fast32_t shinsei_hexStringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToInt32U8((const char8_t*)src,len);
}
int_fast32_t shinsei_base36StringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToInt32U8((const char8_t*)src,len);
}
int_fast32_t shinsei_base62StringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToInt32U8((const char8_t*)src,len);
}

// Int32/UInt32 string converters (N)
uint_fast32_t shinsei_stringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToUInt32U8(src,len);
}
uint_fast32_t shinsei_binStringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToUInt32U8(src,len);
}
uint_fast32_t shinsei_octStringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToUInt32U8(src,len);
}
uint_fast32_t shinsei_hexStringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToUInt32U8(src,len);
}
uint_fast32_t shinsei_base36StringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToUInt32U8(src,len);
}
uint_fast32_t shinsei_base62StringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToUInt32U8(src,len);
}

int_fast32_t shinsei_stringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToInt32U8(src,len);
}
int_fast32_t shinsei_binStringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToInt32U8(src,len);
}
int_fast32_t shinsei_octStringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToInt32U8(src,len);
}
int_fast32_t shinsei_hexStringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToInt32U8(src,len);
}
int_fast32_t shinsei_base36StringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToInt32U8(src,len);
}
int_fast32_t shinsei_base62StringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToInt32U8(src,len);
}

// Int64/UInt64 string converters (A)
uint_fast64_t shinsei_stringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToUInt64U8((const char8_t*)src,len);
}
uint_fast64_t shinsei_binStringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToUInt64U8((const char8_t*)src,len);
}
uint_fast64_t shinsei_octStringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToUInt64U8((const char8_t*)src,len);
}
uint_fast64_t shinsei_hexStringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToUInt64U8((const char8_t*)src,len);
}
uint_fast64_t shinsei_base36StringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToUInt64U8((const char8_t*)src,len);
}
uint_fast64_t shinsei_base62StringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToUInt64U8((const char8_t*)src,len);
}

int_fast64_t shinsei_stringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToInt64U8((const char8_t*)src,len);
}
int_fast64_t shinsei_binStringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToInt64U8((const char8_t*)src,len);
}
int_fast64_t shinsei_octStringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToInt64U8((const char8_t*)src,len);
}
int_fast64_t shinsei_hexStringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToInt64U8((const char8_t*)src,len);
}
int_fast64_t shinsei_base36StringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToInt64U8((const char8_t*)src,len);
}
int_fast64_t shinsei_base62StringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToInt64U8((const char8_t*)src,len);
}

// Int64/UInt64 string converters (N)
uint_fast64_t shinsei_stringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToUInt64U8(src,len);
}
uint_fast64_t shinsei_binStringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToUInt64U8(src,len);
}
uint_fast64_t shinsei_octStringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToUInt64U8(src,len);
}
uint_fast64_t shinsei_hexStringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToUInt64U8(src,len);
}
uint_fast64_t shinsei_base36StringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToUInt64U8(src,len);
}
uint_fast64_t shinsei_base62StringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToUInt64U8(src,len);
}

int_fast64_t shinsei_stringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_stringToInt64U8(src,len);
}
int_fast64_t shinsei_binStringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_binStringToInt64U8(src,len);
}
int_fast64_t shinsei_octStringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_octStringToInt64U8(src,len);
}
int_fast64_t shinsei_hexStringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_hexStringToInt64U8(src,len);
}
int_fast64_t shinsei_base36StringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base36StringToInt64U8(src,len);
}
int_fast64_t shinsei_base62StringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_base62StringToInt64U8(src,len);
}

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif
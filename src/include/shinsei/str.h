#pragma once

#include"shinsei/minimal/str.h"
#include"shinsei/.internal/std.h"

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

_SHINSEI_LIB_API unsigned int shinsei_systemCP()_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_charSizeA(const int starter_ch)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isBDigitA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isBDigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isODigitA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isODigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isDigitA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isDigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isXDigitA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isXDigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isUpperA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUpperAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isLowerA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLowerAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isAlphaA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isAlphaAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isAlnumA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isAlnumAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isBlankA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isBlankAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isCntrlA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCntrlAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isPrintA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isPrintAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isGraphA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isGraphAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isPunctA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isPunctAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isSpaceA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSpaceAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isJSONWhitespaceA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isJSONWhitespaceAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_toUpperA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_toUpperAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_toLowerA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_toLowerAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_isHexColorA(const char*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_stringLinesA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_findStringsA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToPartsA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char delimiter)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_strLenA(const char*const restrict str)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_strCpyA(char*const restrict des,const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_strCatA(char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_strCmpA(const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_strChrA(const char*const restrict des,const size_t des_len,const char src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_strStrA(const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_strKMPA(const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT;

#ifdef _SHINSEI_OS_WINDOWS
	_SHINSEI_LIB_API int shinsei_charSizeN(const wint_t starter_ch)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isBDigitN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isBDigitNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isODigitN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isODigitNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isDigitN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isDigitNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isXDigitN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isXDigitNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isUpperN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isUpperNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isLowerN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isLowerNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isAlphaN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isAlphaNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isAlnumN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isAlnumNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isBlankN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isBlankNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isCntrlN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isCntrlNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isPrintN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isPrintNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isGraphN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isGraphNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isPunctN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isPunctNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isSpaceN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isSpaceNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isJSONWhitespaceN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isJSONWhitespaceNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API wint_t shinsei_toUpperN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API wint_t shinsei_toUpperNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API wint_t shinsei_toLowerN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API wint_t shinsei_toLowerNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_isHexColorN(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_stringLinesN(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_findStringsN(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToPartsN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const wchar_t delimiter)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strLenN(const wchar_t*const restrict str)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API void shinsei_strCpyN(wchar_t*const restrict des,const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strCatN(wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_strCmpN(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strChrN(const wchar_t*const restrict des,const size_t des_len,const wchar_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strStrN(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strKMPN(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT;
	
#elif defined(_SHINSEI_OS_UNIX)
	_SHINSEI_LIB_API int shinsei_charSizeN(const char8_t starter_ch)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isBDigitN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isBDigitNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isODigitN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isODigitNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isDigitN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isDigitNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isXDigitN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isXDigitNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isUpperN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isUpperNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isLowerN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isLowerNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isAlphaN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isAlphaNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isAlnumN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isAlnumNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isBlankN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isBlankNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isCntrlN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isCntrlNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isPrintN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isPrintNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isGraphN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isGraphNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isPunctN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isPunctNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isSpaceN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isSpaceNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isJSONWhitespaceN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isJSONWhitespaceNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API char8_t shinsei_toUpperN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API char8_t shinsei_toUpperNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API char8_t shinsei_toLowerN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API char8_t shinsei_toLowerNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_isHexColorN(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_stringLinesN(size_t*restrict idx_buf,size_t idx_buf_len,char8_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_findStringsN(size_t*restrict idx_buf,size_t idx_buf_len,char8_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToPartsN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char8_t delimiter)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strLenN(const char8_t*const restrict str)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API void shinsei_strCpyN(char8_t*const restrict des,const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strCatN(char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_strCmpN(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strChrN(const char8_t*const restrict des,const size_t des_len,const char8_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strStrN(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strKMPN(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT;
	
#endif

#ifdef _SHINSEI_OS_CPP
}
#endif
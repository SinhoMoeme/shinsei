#pragma once

#include"shinsei/.internal/usage.h"

#include<wchar.h>
#include<uchar.h>
#include<ctype.h>
#include<wctype.h>
#include<limits.h>
#include<stdlib.h>

#ifdef _SHINSEI_OS_CONSTEXPR
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_MAX_UTF16_OF_UTF32=sizeof(char32_t)/sizeof(char16_t);
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_MAX_UTF8_OF_UTF32=sizeof(char32_t)/sizeof(char8_t);
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_MAX_UTF8_OF_UTF16=sizeof(char16_t)/sizeof(char8_t);
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_POINTER_BIT=sizeof(void*)*CHAR_BIT;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_POINTER_OF_CHAR=sizeof(void*);
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_POINTER_OF_WCHAR=sizeof(void*)/sizeof(wchar_t);
#else
	#define SHINSEI_MAX_UTF16_OF_UTF32 (size_t)(sizeof(char32_t)/sizeof(char16_t))
	#define SHINSEI_MAX_UTF8_OF_UTF32 (size_t)(sizeof(char32_t)/sizeof(char8_t))
	#define SHINSEI_MAX_UTF8_OF_UTF16 (size_t)(sizeof(char16_t)/sizeof(char8_t))
	#define SHINSEI_POINTER_BIT (size_t)(sizeof(void*)*CHAR_BIT)
	#define SHINSEI_POINTER_OF_CHAR (size_t)sizeof(void*)
	#define SHINSEI_POINTER_OF_WCHAR (size_t)(sizeof(void*)/sizeof(wchar_t))
#endif

#ifdef _SHINSEI_OS_CPP
extern "C" {
#endif

_SHINSEI_LIB_API int shinsei_utf8CharSize(const char8_t starter_char);
_SHINSEI_LIB_API int shinsei_utf16CharSize(const char16_t str_ptr);

_SHINSEI_LIB_API bool shinsei_isBDigitA(const int ch);
_SHINSEI_LIB_API bool shinsei_isBDigitW(const wint_t ch);
_SHINSEI_LIB_API bool shinsei_isBDigitU8S(const char8_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isBDigitU16S(const char16_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isBDigitU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isODigitA(const int ch);
_SHINSEI_LIB_API bool shinsei_isODigitW(const wint_t ch);
_SHINSEI_LIB_API bool shinsei_isODigitU8S(const char8_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isODigitU16S(const char16_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isODigitU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isDigitA(const int ch);
_SHINSEI_LIB_API bool shinsei_isDigitW(const wint_t ch);
_SHINSEI_LIB_API bool shinsei_isDigitU8S(const char8_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isDigitU16S(const char16_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isDigitU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isXDigitA(const int ch);
_SHINSEI_LIB_API bool shinsei_isXDigitW(const wint_t ch);
_SHINSEI_LIB_API bool shinsei_isXDigitU8S(const char8_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isXDigitU16S(const char16_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isXDigitU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isUpperA(const int ch);
_SHINSEI_LIB_API bool shinsei_isUpperW(const wint_t ch);
_SHINSEI_LIB_API bool shinsei_isUpperU8(const char8_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isUpperU16(const char16_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isUpperU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isLowerA(const int ch);
_SHINSEI_LIB_API bool shinsei_isLowerW(const wint_t ch);
_SHINSEI_LIB_API bool shinsei_isLowerU8S(const char8_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isLowerU16S(const char16_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isLowerU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isAlphaA(const int ch);
_SHINSEI_LIB_API bool shinsei_isAlphaW(const wint_t ch);
_SHINSEI_LIB_API bool shinsei_isAlphaU8S(const char8_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isAlphaU16S(const char16_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isAlphaU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isAlnumA(const int ch);
_SHINSEI_LIB_API bool shinsei_isAlnumW(const wint_t ch);
_SHINSEI_LIB_API bool shinsei_isAlnumU8S(const char8_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isAlnumU16S(const char16_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isAlnumU32(const char32_t ch);

_SHINSEI_LIB_API int shinsei_toUpperA(const int ch);
_SHINSEI_LIB_API wint_t shinsei_toUpperW(const wint_t ch);
_SHINSEI_LIB_API char8_t shinsei_toUpperU8S(const char8_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API char16_t shinsei_toUpperU16S(const char16_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API char32_t shinsei_toUpperU32(const char32_t ch);

_SHINSEI_LIB_API int shinsei_isHexColorA(const char*restrict str);
_SHINSEI_LIB_API int shinsei_isHexColorW(const wchar_t*restrict str);

_SHINSEI_LIB_API int shinsei_utf32CharToUtf16Char(char16_t*const restrict des,const char32_t src);
_SHINSEI_LIB_API int shinsei_utf32CharToUtf8Char(char8_t*const restrict des,const char32_t src);
_SHINSEI_LIB_API int shinsei_utf16CharToUtf8Char(char8_t*const restrict des,const char16_t*const restrict src,const size_t src_len);

_SHINSEI_LIB_API int shinsei_utf16CharToUtf32Char(char32_t*const restrict des,const char16_t*const restrict src,const size_t src_len);
_SHINSEI_LIB_API int shinsei_utf8CharToUtf32Char(char32_t*const restrict des,const char8_t*const restrict src,const size_t src_len);
_SHINSEI_LIB_API int shinsei_utf8CharToUtf16Char(char16_t*const restrict des,const char8_t*const restrict src,const size_t src_len);

_SHINSEI_LIB_API size_t shinsei_utf16ToUtf8(char8_t *const restrict des,const size_t des_len,const char16_t *const restrict src,const size_t src_len);
_SHINSEI_LIB_API char8_t* shinsei_utf16ToUtf8B(const char16_t*const restrict src,const size_t src_len);

_SHINSEI_LIB_API int shinsei_parseEscapedCharA(char*const restrict des,const char*const restrict src,const size_t src_len);
_SHINSEI_LIB_API size_t shinsei_parseEscapedCharW(wchar_t**restrict des,const wchar_t*restrict src,size_t src_len);

_SHINSEI_LIB_API size_t shinsei_readEscapedLineA(char*const restrict str,const size_t len);
_SHINSEI_LIB_API size_t shinsei_readEscapedLineW(wchar_t*const restrict str,const size_t len);

_SHINSEI_LIB_API size_t shinsei_stringLinesA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len);
_SHINSEI_LIB_API size_t shinsei_stringLinesW(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len);

_SHINSEI_LIB_API size_t shinsei_findStringsA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len);
_SHINSEI_LIB_API size_t shinsei_findStringsW(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len);

_SHINSEI_LIB_API size_t shinsei_escapedLineToStringsA(size_t*restrict ptr_buf,size_t ptr_buf_len,char*restrict str,const size_t str_len);
_SHINSEI_LIB_API size_t shinsei_escapedLineToStringsW(size_t*restrict ptr_buf,size_t ptr_buf_len,wchar_t*restrict str,const size_t str_len);

#ifdef _SHINSEI_OS_CPP
}
#endif
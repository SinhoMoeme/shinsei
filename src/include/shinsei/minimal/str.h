#pragma once

#include"shinsei/.internal/os.h"
#include"shinsei/.internal/usage.h"

#ifndef __cplusplus
#define SHINSEI_MAX_UTF16_OF_UTF32 (size_t)(sizeof(char32_t)/sizeof(char16_t))
#define SHINSEI_MAX_UTF8_OF_UTF32 (size_t)(sizeof(char32_t)/sizeof(unsigned char))
#define SHINSEI_MAX_UTF8_OF_UTF16 (size_t)(sizeof(char16_t)/sizeof(unsigned char))
#endif

#include<wchar.h>
#include<uchar.h>
#include<ctype.h>
#include<wctype.h>
#include<limits.h>

#ifdef __cplusplus
extern "C" {
#endif

_SHINSEI_LIB_API int shinsei_utf8CharSize(const unsigned char starter_char);
_SHINSEI_LIB_API int shinsei_utf16CharSize(const char16_t str_ptr);

_SHINSEI_LIB_API bool shinsei_isBDigitA(const int ch);
_SHINSEI_LIB_API bool shinsei_isBDigitW(const wint_t ch);
_SHINSEI_LIB_API bool shinsei_isBDigitU8(const unsigned char**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isBDigitU16(const char16_t**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isBDigitU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isODigitA(const int ch);
_SHINSEI_LIB_API bool shinsei_isODigitW(const wint_t ch);
_SHINSEI_LIB_API bool shinsei_isODigitU8(const unsigned char**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isODigitU16(const char16_t**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isODigitU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isDigitA(const int ch);
_SHINSEI_LIB_API bool shinsei_isDigitW(const wint_t ch);
_SHINSEI_LIB_API bool shinsei_isDigitU8(const unsigned char**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isDigitU16(const char16_t**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isDigitU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isXDigitA(const int ch);
_SHINSEI_LIB_API bool shinsei_isXDigitW(const wint_t ch);
_SHINSEI_LIB_API bool shinsei_isXDigitU8(const unsigned char**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isXDigitU16(const char16_t**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isXDigitU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isUpperA(const int ch);
_SHINSEI_LIB_API bool shinsei_isUpperW(const wint_t ch);
_SHINSEI_LIB_API bool shinsei_isUpperU8(const unsigned char**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isUpperU16(const char16_t**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isUpperU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isLowerA(const int ch);
_SHINSEI_LIB_API bool shinsei_isLowerW(const wint_t ch);
_SHINSEI_LIB_API bool shinsei_isLowerU8(const unsigned char**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isLowerU16(const char16_t**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isLowerU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isAlphaA(const int ch);
_SHINSEI_LIB_API bool shinsei_isAlphaW(const wint_t ch);
_SHINSEI_LIB_API bool shinsei_isAlphaU8(const unsigned char**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isAlphaU16(const char16_t**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isAlphaU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isAlnumA(const int ch);
_SHINSEI_LIB_API bool shinsei_isAlnumW(const wint_t ch);
_SHINSEI_LIB_API bool shinsei_isAlnumU8(const unsigned char**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isAlnumU16(const char16_t**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isAlnumU32(const char32_t ch);

_SHINSEI_LIB_API int shinsei_isHexColorA(const char*restrict str);
_SHINSEI_LIB_API int shinsei_isHexColorW(const wchar_t*restrict str);

_SHINSEI_LIB_API int shinsei_utf32CharToUtf16Char(char16_t*restrict des,char32_t src);
_SHINSEI_LIB_API int shinsei_utf32CharToUtf8Char(unsigned char*restrict des,const char32_t src);
_SHINSEI_LIB_API int shinsei_utf16CharToUtf8Char(unsigned char*restrict des,const char16_t*restrict src,const size_t src_len);

_SHINSEI_LIB_API int shinsei_utf16CharToUtf32Char(char32_t*restrict des,const char16_t* src,const size_t src_len);
_SHINSEI_LIB_API int shinsei_utf8CharToUtf32Char(char32_t*restrict des,const unsigned char* src,const size_t src_len);
_SHINSEI_LIB_API int shinsei_utf8CharToUtf16Char(char16_t*restrict des,const unsigned char* src,const size_t src_len);

_SHINSEI_LIB_API int shinsei_parseEscapedCharA(char*restrict des,const char*restrict src,const size_t src_len);
_SHINSEI_LIB_API size_t shinsei_parseEscapedCharW(wchar_t**restrict des,const wchar_t*restrict src,size_t src_len);

_SHINSEI_LIB_API size_t shinsei_readEscapedLineA(char*restrict str,const size_t len);
_SHINSEI_LIB_API size_t shinsei_readEscapedLineW(wchar_t*restrict str,const size_t len);

_SHINSEI_LIB_API size_t shinsei_stringLinesA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len);
_SHINSEI_LIB_API size_t shinsei_stringLinesW(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len);

_SHINSEI_LIB_API size_t shinsei_findStringsA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len);
_SHINSEI_LIB_API size_t shinsei_findStringsW(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len);

_SHINSEI_LIB_API size_t shinsei_escapedLineToStringsA(size_t*restrict ptr_buf,size_t ptr_buf_len,char*restrict str,const size_t str_len);
_SHINSEI_LIB_API size_t shinsei_escapedLineToStringsW(size_t*restrict ptr_buf,size_t ptr_buf_len,wchar_t*restrict str,const size_t str_len);

#ifdef __cplusplus
}
#endif
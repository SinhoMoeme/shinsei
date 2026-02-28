#pragma once

#include"shinsei/.internal/os.h"
#include"shinsei/.internal/usage.h"
#include"shinsei/str.h"

#ifndef __cplusplus__
#define SHINSEI_PATH_ILLEGAL (int)0
#define SHINSEI_PATH_ABSOLUTE (int)1
#define SHINSEI_PATH_RELATIVE (int)2
#endif

#ifdef __cplusplus
extern "C" {
#endif

_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterA(const char ch);
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterW(const wchar_t ch);
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterU8(const unsigned char**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterU16(const char16_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterA(const char ch);
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterW(const wchar_t ch);
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterU8(const unsigned char**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterU16(const char16_t**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterU32(const char32_t ch);

_SHINSEI_LIB_API int shinsei_windowsPathStandardizeA(char* path,size_t* len);
_SHINSEI_LIB_API int shinsei_windowsPathStandardizeW(wchar_t* path,size_t* len);

_SHINSEI_LIB_API int shinsei_linuxPathStandardizeA(char* path,size_t* len);
_SHINSEI_LIB_API int shinsei_linuxPathStandardizeW(wchar_t* path,size_t* len);

_SHINSEI_LIB_API void shinsei_windowsPathJoinA(char* buf,const size_t buf_len,int part_cnt,const char* first_part,const size_t first_part_len,...);
_SHINSEI_LIB_API void shinsei_windowsPathJoinW(wchar_t* buf,size_t buf_len,int path_cnt,const wchar_t* first_part,const size_t first_part_len,...);

#ifdef __cplusplus
}
#endif
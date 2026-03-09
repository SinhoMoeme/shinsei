#pragma once

#include"shinsei/minimal/path.h"
#include"shinsei/.internal/std.h"

#ifdef _SHINSEI_OS_WINDOWS
#include"shinsei/minimal/struct.h"
#endif

#ifdef _SHINSEI_OS_CPP
extern "C" {
#endif

_SHINSEI_LIB_API shinsei_object_t* shinsei_getUserDataPathN();
_SHINSEI_LIB_API size_t shinsei_getUserDataPathW(wchar_t *const buf,const size_t buf_len);
_SHINSEI_LIB_API wchar_t* shinsei_getUserDataPathWB();
_SHINSEI_LIB_API size_t shinsei_getUserDataPathU8(char8_t *const buf,const size_t buf_len);
_SHINSEI_LIB_API char8_t* shinsei_getUserDataPathU8B();

_SHINSEI_LIB_API shinsei_object_t* shinsei_getSystemDataPathN();
_SHINSEI_LIB_API size_t shinsei_getSystemDataPathW(wchar_t *const buf,const size_t buf_len);
_SHINSEI_LIB_API wchar_t* shinsei_getSystemDataPathWB();
_SHINSEI_LIB_API size_t shinsei_getSystemDataPathU8(char8_t *const buf,const size_t buf_len);
_SHINSEI_LIB_API char8_t* shinsei_getSystemDataPathU8B();

_SHINSEI_LIB_API void shinsei_freeUserDataPathN(shinsei_object_t *const path_obj);

#ifdef _SHINSEI_OS_CPP
}
#endif
#pragma once

#include"shinsei/minimal/io.h"
#include"shinsei/.internal/std.h"

_SHINSEI_LIB_API void shinsei_printA(const char*restrict const str,const size_t len);
_SHINSEI_LIB_API void shinsei_printW(const wchar_t*restrict const str,const size_t len);
_SHINSEI_LIB_API void shinsei_printLnA(const char*restrict const str,const size_t len);
_SHINSEI_LIB_API void shinsei_printLnW(const wchar_t*restrict const str,const size_t len);
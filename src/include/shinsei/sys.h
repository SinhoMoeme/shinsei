#pragma once

#include"shinsei/minimal/struct.h"
#include"shinsei/.internal/std.h"

#ifdef _SHINSEI_OS_WINDOWS
#include<stdint.h>
#endif

#ifdef _SHINSEI_OS_CPP
extern "C" {
#endif

_SHINSEI_LIB_API bool shinsei_sleepMs(const unsigned long long ms);

#ifdef _SHINSEI_OS_CPP
}
#endif
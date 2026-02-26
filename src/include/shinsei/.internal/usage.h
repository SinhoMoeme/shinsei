#pragma once

// Windows
#if defined(_SHINSEI_OS_WINDOWS)
    #ifdef _SHINSEI_BUILD_LIB
        #define _SHINSEI_LIB_API __declspec(dllexport)
    #elif defined(_SHINSEI_USE_SHARED)
        #define _SHINSEI_LIB_API __declspec(dllimport)
    #else
        #define _SHINSEI_LIB_API
    #endif

// Linux / Unix
#elif defined(_SHINSEI_OS_UNIX)
    #if defined(_SHINSEI_BUILD_LIB)||defined(_SHINSEI_USE_SHARED)
        #if defined(_SHINSEI_OS_GNUC_4)||defined(_SHINSEI_OS_CLANG)
            #define _SHINSEI_LIB_API __attribute__((visibility("default")))
        #else
            #define _SHINSEI_LIB_API
        #endif
    #else
        #define _SHINSEI_LIB_API
    #endif

// Unknown
#else
    #define _SHINSEI_LIB_API
#endif
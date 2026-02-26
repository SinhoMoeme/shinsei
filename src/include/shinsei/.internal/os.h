#pragma once

// Cygwin
#if defined(__CYGWIN__)
    #define _SHINSEI_OS_CYGWIN
    #define _SHINSEI_OS_UNIX

// Windows
#elif defined(_WIN32)||defined(_WIN64)
    #define _SHINSEI_OS_WINDOWS
    #if defined(_WIN64)
        #define _SHINSEI_OS_WINDOWS_64
    #else
        #define _SHINSEI_OS_WINDOWS_32
    #endif

// Apple (macOS, iOS, etc.)
#elif defined(__APPLE__)&&defined(__MACH__)
    #define _SHINSEI_OS_MACOS
    #define _SHINSEI_OS_UNIX

// Linux
#elif defined(__linux__)
    #define _SHINSEI_OS_LINUX
    #define _SHINSEI_OS_UNIX

// FreeBSD
#elif defined(__FreeBSD__)
    #define _SHINSEI_OS_FREEBSD
    #define _SHINSEI_OS_UNIX

// SunOS / Solaris
#elif defined(__sun)
    #define _SHINSEI_OS_SUNOS
    #define _SHINSEI_OS_UNIX

// Unix
#elif defined(__unix__)||defined(__unix)
    #define _SHINSEI_OS_UNIX

// Unknown
#else
    #define _SHINSEI_OS_UNKNOWN
#endif

// Clang
#if defined(__clang__)
    #define _SHINSEI_OS_CLANG

// GCC
#elif defined(__GNUC__)
    #define _SHINSEI_OS_GNUC
    #if __GNUC__>=4
        #define _SHINSEI_OS_GNUC_4
    #endif
#endif
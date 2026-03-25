#pragma once

// Cygwin
#if defined(__CYGWIN__)
    #define _SHINSEI_OS_CYGWIN
    #define _SHINSEI_OS_UNIX

// Windows
#elif defined(_WIN32)||defined(_WIN64)
    #define _SHINSEI_OS_WINDOWS
    #if(defined(_WIN64))
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
    #define _SHINSEI_OS_GNUC __GNUC__
    #if(_SHINSEI_OS_GNUC>=4)
        #define _SHINSEI_OS_GNUC_4
    #endif

//MSVC
#elif defined(_MSC_VER)
	#define _SHINSEI_OS_MSVC _MSC_VER
	#if(_SHINSEI_OS_MSVC>=1980)
		#define _SHINSEI_OS_MSVC_2015
	#endif
#endif

//C++
#ifdef __cplusplus
	#if(__cplusplus>202302L)
		#define _SHINSEI_OS_CPP_26
		#define _SHINSEI_OS_CPP 2026
	#elif(__cplusplus==202302L)
		#define _SHINSEI_OS_CPP_23
		#define _SHINSEI_OS_CPP 2023
	#elif(__cplusplus>=202002L)
		#define _SHINSEI_OS_CPP_20
		#define _SHINSEI_OS_CPP 2020
	#elif(__cplusplus>=201703L)
		#define _SHINSEI_OS_CPP_17
		#define _SHINSEI_OS_CPP 2017
	#elif(__cplusplus>=201402L)
		#define _SHINSEI_OS_CPP_14
		#define _SHINSEI_OS_CPP 2014
	#elif(__cplusplus>=201103L)
		#define _SHINSEI_OS_CPP_11
		#define _SHINSEI_OS_CPP 2011
	#elif(__cplusplus>=199711L)
		#define _SHINSEI_OS_CPP_98
		#define _SHINSEI_OS_CPP 1998
	#else
		#define _SHINSEI_OS_CPP 0
	#endif
#elif(defined(__STDC_VERSION__)||defined(__STDC__))
	#if(__STDC_VERSION__>=202311L)
        #define _SHINSEI_OS_C_23
		#define _SHINSEI_OS_C 2023
    #elif(__STDC_VERSION__>=201710L)
        #define _SHINSEI_OS_C_17
		#define _SHINSEI_OS_C 2017
    #elif(__STDC_VERSION__>=201112L)
        #define _SHINSEI_OS_C_11
		#define _SHINSEI_OS_C 2011
    #elif(__STDC_VERSION__>=199901L)
        #define _SHINSEI_OS_C_99
		#define _SHINSEI_OS_C 1999
	#elif defined(__STDC__)
		#define _SHINSEI_OS_C_90
		#define _SHINSEI_OS_C 1990
	#else
		#define _SHINSEI_OS_C_94
		#define _SHINSEI_OS_C 1994
	#endif
#else
	#define _SHINSEI_OS_UNKNOWN_C
#endif

// Cold path
#if(defined(_SHINSEI_OS_GNUC)||defined(_SHINSEI_OS_CLANG))
    #define _SHINSEI_COLD __attribute__((noinline,cold))
#elif(defined(_SHINSEI_OS_MSVC))
	#define _SHINSEI_COLD __declspec(noinline)
#else
    #define _SHINSEI_COLD
#endif

//constexpr
#if(defined(_SHINSEI_OS_CPP)&&_SHINSEI_OS_CPP>=2011)
	#define _SHINSEI_OS_CONSTEXPR constexpr
	#define _SHINSEI_OS_CONSTEXPR_FUNC constexpr
#elif(defined(_SHINSEI_OS_C)&&_SHINSEI_OS_C>=2023)
	#define _SHINSEI_OS_CONSTEXPR constexpr
	#define _SHINSEI_OS_CONSTEXPR_FUNC
#else
	#define _SHINSEI_OS_CONSTEXPR
	#define _SHINSEI_OS_CONSTEXPR_FUNC
#endif

//inline
#if(defined(_SHINSEI_OS_MSVC)&&!defined(_SHINSEI_OS_CPP))
	#define _SHINSEI_OS_INLINE __inline
#elif(defined(_SHINSEI_OS_CPP)||(defined(_SHINSEI_OS_C)&&_SHINSEI_OS_C>=1999))
	#define _SHINSEI_OS_INLINE inline
#else
	#define _SHINSEI_OS_INLINE
#endif

#if(defined(_SHINSEI_OS_CPP)&&_SHINSEI_OS_CPP>=2017)
	#define _SHINSEI_OS_INLINE_VAR inline
#else
	#define _SHINSEI_OS_INLINE_VAR
#endif

// Compatibility macros
#ifndef _SHINSEI_IGNORE_COMPATIBILITY
	// nullptr
	#if((defined(_SHINSEI_OS_CPP)&&_SHINSEI_OS_CPP<2011)||(defined(_SHINSEI_OS_C)&&_SHINSEI_OS_C<2023))
		#ifndef nullptr
			#define nullptr NULL
		#endif
	#endif

	// char8_t
	#if(defined(_SHINSEI_OS_C)||(defined(_SHINSEI_OS_CPP)&&_SHINSEI_OS_CPP<2020))
		#ifndef char8_t
			typedef unsigned char char8_t;
		#endif
	#endif

	// bool
	#if(defined(_SHINSEI_OS_C)&&_SHINSEI_OS_C<2023)
		#ifndef bool
			#define bool _Bool
		#endif
	#endif

	// restrict
	#if(defined _SHINSEI_OS_CPP||defined(_SHINSEI_OS_MSVC))
		#ifndef restrict
            #define restrict __restrict
        #endif
	#endif
	
	// __builtin_expect
	#if defined(_SHINSEI_OS_MSVC)
		#define __builtin_expect(x,y) (x)
	#endif
	
	// __builtin of cstring
	#if defined(_SHINSEI_OS_MSVC)
		#define __builtin_memcpy(dst,src,len) memcpy(dst,src,len)
        #define __builtin_memmove(dst,src,len) memmove(dst,src,len)
        #define __builtin_memset(dst,ch,len) memset(dst,ch,len)
        #define __builtin_memcmp(x,y,len) memcmp(x,y,len)
        #define __builtin_memchr(ptr,ch,len) memchr(ptr,ch,len)
        #define __builtin_strcmp(x,y) strcmp(x,y)
        #define __builtin_strlen(str) strlen(str)
        #define __builtin_strncmp(x,y,len) strncmp(x,y,len)
        #define __builtin_strchr(str,ch) strchr(str,ch)
        #define __builtin_strrchr(str,ch) strrchr(str,ch)
        #define __builtin_strcat(dst,src) strcat(dst,src)
        #define __builtin_strcpy(dst,src) strcpy(dst,src)
        #define __builtin_strncat(dst,src,n) strncat(dst,src,n)
        #define __builtin_strncpy(dst,src,n) strncpy(dst,src,n) // May be dangerous
        #define __builtin_strcspn(s1,s2) strcspn(s1,s2)
        #define __builtin_strspn(s1,s2) strspn(s1,s2)
        #define __builtin_strpbrk(s1,s2) strpbrk(s1,s2)
        #define __builtin_strstr(s1,s2) strstr(s1,s2)
        #define __builtin_strdup(s) _strdup(s)
        #define __builtin_strndup(s,n) _strndup(s,n) // May be dangerous
        #define __builtin_strcasecmp(s1,s2) _stricmp(s1,s2)
        #define __builtin_strncasecmp(s1,s2,n) _strnicmp(s1,s2,n)
		#define __builtin_mempcpy(dst,src,len) ((void*)((char*)memcpy(dst,src,len)+(len)))
        #define __builtin_stpcpy(dst,src) (strcpy(dst,src)+strlen(src))
        #define __builtin_stpncpy(dst,src,n) (strncpy(dst,src,n)+strnlen(src,n))
	#endif
	
	// __builtin of cwchar
	#if defined(_SHINSEI_OS_MSVC)
		#define __builtin_wmemcpy(dst,src,len) wmemcpy(dst,src,len)
        #define __builtin_wmemmove(dst,src,len) wmemmove(dst,src,len)
        #define __builtin_wmemset(dst,ch,len) wmemset(dst,ch,len)
        #define __builtin_wmemcmp(x,y,len) wmemcmp(x,y,len)
        #define __builtin_wmemchr(ptr,ch,len) wmemchr(ptr,ch,len)
        #define __builtin_wcscmp(x,y) wcscmp(x,y)
        #define __builtin_wcslen(str) wcslen(str)
        #define __builtin_wcsncmp(x,y,len) wcsncmp(x,y,len)
        #define __builtin_wcschr(str,ch) wcschr(str,ch)
        #define __builtin_wcsrchr(str,ch) wcsrchr(str,ch)
        #define __builtin_wcscpy(dst,src) wcscpy(dst,src)
        #define __builtin_wcsstr(s1,s2) wcsstr(s1,s2)
        #define __builtin_wmempcpy(dst,src,len) ((wchar_t*)wmemcpy(dst,src,len)+(len))
	#endif
	
	// __builtin_unreachable
	#if defined(_SHINSEI_OS_MSVC)
		#define SHINSEI_UNREACHABLE __assume(0)
	#else
		#define SHINSEI_UNREACHABLE __builtin_unreachable()
	#endif
	
#endif
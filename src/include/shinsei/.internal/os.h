#pragma once

// Cygwin
#if defined(__CYGWIN__)
	#define _SHINSEI_OS_CYGWIN
	#define _SHINSEI_OS_UNIX

// Windows
#elif defined(_WIN16)||defined(_WIN32)||defined(_WIN64)
	#if(defined(_WIN64))
		#define _SHINSEI_OS_WINDOWS 64
		#define _SHINSEI_OS_WINDOWS_64
	#elif(defined(_WIN32))
		#define _SHINSEI_OS_WINDOWS 32
		#define _SHINSEI_OS_WINDOWS_32
	#else
		#define _SHINSEI_OS_WINDOWS 16
		#define _SHINSEI_OS_WINDOWS_16
	#endif

// Apple (macOS, iOS, etc.)
#elif defined(__APPLE__)&&defined(__MACH__)
	#define _SHINSEI_OS_APPLE
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
	#define _SHINSEI_OS_SUN
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
	#define _SHINSEI_OS_GNUC_MINOR __GNUC_MINOR__
	#if(_SHINSEI_OS_GNUC>=4)
		#define _SHINSEI_OS_GNUC_4
		#if(_SHINSEI_OS_GNUC>4||_SHINSEI_OS_GNUC_MINOR>=7)
			#define _SHINSEI_OS_GNUC_4_7
		#endif
	#endif

//MSVC
#elif defined(_MSC_VER)
	#define _SHINSEI_OS_MSVC _MSC_VER
	#if(_SHINSEI_OS_MSVC>=1980)
		#define _SHINSEI_OS_MSVC_2015
	#endif
	#include<intrin.h>
#endif

//C++
#ifdef __cplusplus
	#if(__cplusplus>=202604L)
		#define _SHINSEI_OS_CPP_26
		#define _SHINSEI_OS_CPP 2026
	#elif(__cplusplus>=202302L)
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

// inline
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

// noexcept
#ifdef _SHINSEI_OS_CPP
	#define _SHINSEI_OS_NOEXCEPT noexcept
#else
	#define _SHINSEI_OS_NOEXCEPT
#endif

// stdatomic
#if(defined(_SHINSEI_OS_GNUC_4_7)||defined(_SHINSEI_OS_CLANG)||defined(_SHINSEI_OS_MSVC))
    #define _SHINSEI_OS_ATOMIC
#endif

// CPU Architectures
#if(defined(__x86_64__)||defined(_M_X64)||defined(_M_AMD64)||defined(__amd64__))
	#define _SHINSEI_OS_X64
#elif(defined(__i386__)||defined(_M_IX86)||defined(__X86__)||defined(_X86_))
	#define _SHINSEI_OS_X86
#elif(defined(__aarch64__)||defined(_M_ARM64)||defined(__ARM_ARCH_ISA_A64))
	#define _SHINSEI_OS_ARM64
#elif(defined(__arm__)||defined(_M_ARM)||defined(__TARGET_ARCH_ARM)||defined(__ARM_ARCH))
	#define _SHINSEI_OS_ARM
#elif(defined(__riscv)&&(__riscv_xlen==64))
	#define _SHINSEI_OS_RISCV64
#elif(defined(__riscv)&&(__riscv_xlen==32))
	#define _SHINSEI_OS_RISCV32
#elif(defined(__wasm64__))
	#define _SHINSEI_OS_WASM64
#elif(defined(__wasm__)||defined(__wasm32__))
	#define _SHINSEI_OS_WASM32
#elif(defined(__ppc64__)||defined(__PPC64__))
	#define _SHINSEI_OS_POWERPC64
#elif(defined(__powerpc__)||defined(__ppc__)||defined(__PPC__)||defined(_M_PPC))
	#define _SHINSEI_OS_POWERPC32
#elif(defined(__mips64))
	#define _SHINSEI_OS_MIPS64
#elif(defined(__mips__))
	#define _SHINSEI_OS_MIPS32
#elif(defined(__s390x__))
	#define _SHINSEI_OS_S390X
#elif(defined(__AVR__))
	#define _SHINSEI_OS_AVR
#elif(defined(__MSP430__))
	#define _SHINSEI_OS_MSP430
#else
	#define _SHINSEI_OS_UNKNOWN_CPU
#endif

// Bits
#if(defined(__SIZEOF_POINTER__))
	#define _SHINSEI_OS_BITS (__SIZEOF_POINTER__*8)
#elif(defined(_WIN64))
	#define _SHINSEI_OS_BITS 64
#elif(defined(_SHINSEI_OS_X64)||defined(_SHINSEI_OS_ARM64)||defined(_SHINSEI_OS_RISCV64)||defined(_SHINSEI_OS_WASM64)||defined(_SHINSEI_OS_POWERPC64)||defined(_SHINSEI_OS_MIPS64)||defined(_SHINSEI_OS_S390X))
	#define _SHINSEI_OS_BITS 64
#elif(defined(_SHINSEI_OS_X86)||defined(_SHINSEI_OS_ARM)||defined(_SHINSEI_OS_RISCV32)||defined(_SHINSEI_OS_WASM32)||defined(_SHINSEI_OS_POWERPC32)||defined(_SHINSEI_OS_MIPS32)||defined(_WIN32))
	#define _SHINSEI_OS_BITS 32
#elif(defined(_SHINSEI_OS_MSP430)||(defined(_SHINSEI_OS_AVR)&&!defined(__AVR_ARCH__)))
	#define _SHINSEI_OS_BITS 16
#elif(defined(_SHINSEI_OS_AVR))
	#if(defined(__AVR_ARCH__)&&(__AVR_ARCH__>=100))
		#define _SHINSEI_OS_BITS 32
	#else
		#define _SHINSEI_OS_BITS 16
	#endif
#else
	// Fallback to 32-bit
	#define _SHINSEI_OS_BITS 32
#endif

// Byte alignments
#if(_SHINSEI_OS_BITS==64)
	#if(defined(__AVX512F__))
		#define _SHINSEI_OS_BYTE_ALIGNMENT 64
	#elif(defined(__AVX__)||defined(__AVX2__))
		#define _SHINSEI_OS_BYTE_ALIGNMENT 32
	#elif(defined(_SHINSEI_OS_X64)||defined(_SHINSEI_OS_ARM64)||defined(__SSE__)||defined(__SSE2__)||defined(__ARM_NEON)||defined(__wasm_simd128__))
		#define _SHINSEI_OS_BYTE_ALIGNMENT 16
	#else
		#define _SHINSEI_OS_BYTE_ALIGNMENT 8
	#endif
#elif(_SHINSEI_OS_BITS==32)
	#if(defined(__SSE__)||defined(__SSE2__)||defined(__ARM_NEON)||defined(__wasm_simd128__))
		#define _SHINSEI_OS_BYTE_ALIGNMENT 16
	#else
		#define _SHINSEI_OS_BYTE_ALIGNMENT 4
	#endif
#elif(_SHINSEI_OS_BITS==16)
	#define _SHINSEI_OS_BYTE_ALIGNMENT 2
#elif(_SHINSEI_OS_BITS==8)
	#define _SHINSEI_OS_BYTE_ALIGNMENT 1
#endif

#if(defined(_SHINSEI_OS_CPP)&&_SHINSEI_OS_CPP>=2011)
	#define _SHINSEI_OS_ALIGN_BYTE alignas(_SHINSEI_OS_BYTE_ALIGNMENT)
#elif(defined(_SHINSEI_OS_MSVC))
	#define _SHINSEI_OS_ALIGN_BYTE __declspec(align(_SHINSEI_OS_BYTE_ALIGNMENT))
#elif(defined(_SHINSEI_OS_GNUC)||defined(_SHINSEI_OS_CLANG))
	#define _SHINSEI_OS_ALIGN_BYTE __attribute__((aligned(_SHINSEI_OS_BYTE_ALIGNMENT)))
#else
	#define _SHINSEI_OS_ALIGN_BYTE
#endif

// Register
#if(defined(_SHINSEI_OS_CPP)&&_SHINSEI_OS_CPP>=2011)
	#define register
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
		#define __builtin_malloc(size) malloc(size)
		#define __builtin_free(ptr) free(ptr)
		#define __builtin_realloc(ptr,size) realloc(ptr,size)
		
		#define __builtin_memcpy(dst,src,len) memcpy(dst,src,len)
		#define __builtin_memmove(dst,src,len) memmove(dst,src,len)
		#define __builtin_memset(dst,ch,len) memset(dst,ch,len)
		#define __builtin_memcmp(x,y,len) memcmp(x,y,len)
		#define __builtin_memchr(ptr,ch,len) memchr(ptr,ch,len)
		
		#define __builtin_strlen(str) strlen(str)
	#endif
	
	// __builtin_unreachable
	#if defined(_SHINSEI_OS_MSVC)
		#define SHINSEI_UNREACHABLE __assume(0)
	#else
		#define SHINSEI_UNREACHABLE __builtin_unreachable()
	#endif
	
#endif
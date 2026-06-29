#include"shinsei/.internal/cpp_init.hpp"

#ifdef _SHINSEI_OS_CPP
	#if(defined(_SHINSEI_OS_WINDOWS))
		#define shinsei_stringToIPv4W ::shinsei_stringToIPv4W
		#define shinsei_stringToIPv4CP ::shinsei_stringToIPv4CP
		#define shinsei_iPv4ToStringW ::shinsei_iPv4ToStringW
		#define shinsei_iPv4ToStringCP ::shinsei_iPv4ToStringCP
		#define shinsei_stringToIPv6W ::shinsei_stringToIPv6W
		#define shinsei_stringToIPv6CP ::shinsei_stringToIPv6CP
		#define shinsei_iPv6ToStringW ::shinsei_iPv6ToStringW
		#define shinsei_iPv6ToStringCP ::shinsei_iPv6ToStringCP
		#define GetACP ::GetACP
		#define _InterlockedCompareExchange ::_InterlockedCompareExchange
		#define __atomic_compare_exchange_n ::__atomic_compare_exchange_n
		#define InitOnceExecuteOnce ::InitOnceExecuteOnce
	#elif(defined(_SHINSEI_OS_UNIX))
		#define shinsei_stringToIPv4U8 ::shinsei_stringToIPv4U8
		#define shinsei_iPv4ToStringU8 ::shinsei_iPv4ToStringU8
		#define shinsei_stringToIPv6U8 ::shinsei_stringToIPv6U8
		#define shinsei_iPv6ToStringU8 ::shinsei_iPv6ToStringU8
	#endif
	
	#ifndef _SHINSEI_OS_MSVC
		#define __builtin_expect ::__builtin_expect
		#define __builtin_expect_with_probability ::__builtin_expect_with_probability
	#endif
#endif
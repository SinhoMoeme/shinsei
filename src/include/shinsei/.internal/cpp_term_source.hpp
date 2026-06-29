#include"shinsei/.internal/cpp_term.hpp"

#ifdef _SHINSEI_OS_CPP
	#if(defined(_SHINSEI_OS_WINDOWS))
		#undef shinsei_stringToIPv4W
		#undef shinsei_stringToIPv4CP
		#undef shinsei_iPv4ToStringW
		#undef shinsei_iPv4ToStringCP
		#undef shinsei_stringToIPv6W
		#undef shinsei_stringToIPv6CP
		#undef shinsei_iPv6ToStringW
		#undef shinsei_iPv6ToStringCP
		#undef GetACP
		#undef _InterlockedCompareExchange
		#undef __atomic_compare_exchange_n
		#undef InitOnceExecuteOnce
	#elif(defined(_SHINSEI_OS_UNIX))
		#undef shinsei_stringToIPv4U8
		#undef shinsei_iPv4ToStringU8
		#undef shinsei_stringToIPv6U8
		#undef shinsei_iPv6ToStringU8
	#endif
	
	#ifndef _SHINSEI_OS_MSVC
		#undef __builtin_expect
		#undef __builtin_expect_with_probability
	#endif
#endif
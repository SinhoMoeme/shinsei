#include"shinsei/network.h"

#include"shinsei/.internal/cpp_init.hpp"

// Get system ANSI code page
#ifdef _SHINSEI_OS_ATOMIC
	static struct _SHINSEI_OS_ALIGN_BYTE{
		volatile uint32_t code_page;
	}cur_mem={0};
#else
	static struct _SHINSEI_OS_ALIGN_BYTE{
		INIT_ONCE init_ansi;
		uint_fast32_t code_page;
	}cur_mem={
		.init_ansi=INIT_ONCE_STATIC_INIT
	};
	
	static BOOL WINAPI initANSICallback(register PINIT_ONCE init_once,register PVOID para,register PVOID* ptr_context){
		(void)init_once;
		(void)para;
		(void)ptr_context;
		cur_mem.code_page=GetACP();
		return TRUE;
	}
#endif

_SHINSEI_OS_INLINE static uint_fast32_t systemCP(){
	#ifdef _SHINSEI_OS_ATOMIC
		register uint_fast32_t cp=cur_mem.code_page;
		if(__builtin_expect_with_probability(!cp,1,1e-7)){
			register uint_fast32_t new_cp=GetACP();
			#ifdef _SHINSEI_OS_MSVC
				register uint_fast32_t prev=_InterlockedCompareExchange((volatile long*)&cur_mem.code_page,(long)new_cp,0);
				cp=prev?prev:new_cp;
			#else
				uint_fast32_t expected=0;
				__atomic_compare_exchange_n(&cur_mem.code_page,&expected,new_cp,0,__ATOMIC_ACQ_REL,__ATOMIC_RELAXED);
				cp=expected?expected:new_cp;
			#endif
		}
		return cp;
	#else
		InitOnceExecuteOnce(&cur_mem.init_ansi,initANSICallback,nullptr,nullptr);
		return (uint_fast32_t)cur_mem.code_page;
	#endif
}

// Convert string to IPv4 address
_SHINSEI_LIB_API bool shinsei_stringToIPv4A(register uint32_t*const restrict des,register const char*const restrict src,register const size_t src_len){
	return shinsei_stringToIPv4CP(systemCP(),des,src,src_len);
}
_SHINSEI_LIB_API bool shinsei_stringToIPv4N(register uint32_t*const restrict des,register const wchar_t*const restrict src,register const size_t src_len){
	return shinsei_stringToIPv4W(des,src,src_len);
}

// Convert IPv4 address to string
_SHINSEI_LIB_API size_t shinsei_iPv4ToStringA(register char*const restrict des,register const uint32_t*const restrict src){
	return shinsei_iPv4ToStringCP(systemCP(),des,src);
}
_SHINSEI_LIB_API size_t shinsei_iPv4ToStringN(register wchar_t*const restrict des,register const uint32_t*const restrict src){
	return shinsei_iPv4ToStringW(des,src);
}

// Convert string to IPv6 address
_SHINSEI_LIB_API bool shinsei_stringToIPv6A(register uint32_t*const restrict des,register const char*const restrict src,register const size_t src_len){
	return shinsei_stringToIPv6CP(systemCP(),des,src,src_len);
}
_SHINSEI_LIB_API bool shinsei_stringToIPv6N(register uint32_t*const restrict des,register const wchar_t*const restrict src,register const size_t src_len){
	return shinsei_stringToIPv6W(des,src,src_len);
}

// Convert IPv6 address string
_SHINSEI_LIB_API size_t shinsei_iPv6ToStringA(register char*const restrict des,register const uint32_t*const restrict src){
	return shinsei_iPv6ToStringCP(systemCP(),des,src);
}
_SHINSEI_LIB_API size_t shinsei_iPv6ToStringN(register wchar_t*const restrict des,register const uint32_t*const restrict src){
	return shinsei_iPv6ToStringW(des,src);
}

#include"shinsei/.internal/cpp_term.hpp"
#pragma once

#include"shinsei/minimal/network.h"
#include"shinsei/.internal/std.h"
#define _SHINSEI_MODULE_NETWORK

#include"shinsei/.internal/cpp_init.hpp"

// Convert string to IPv4 address
_SHINSEI_LIB_API bool shinsei_stringToIPv4A(register uint32_t*const restrict des,register const char*const restrict src,register const size_t src_len);

// Convert IPv4 address to string
_SHINSEI_LIB_API size_t shinsei_iPv4ToStringA(register char*const restrict des,register const uint32_t*const restrict src);

// Convert string to IPv6 address
_SHINSEI_LIB_API bool shinsei_stringToIPv6A(register uint32_t*const restrict des,register const char*const restrict src,register const size_t src_len);

// Convert IPv6 address string
_SHINSEI_LIB_API size_t shinsei_iPv6ToStringA(register char*const restrict des,register const uint32_t*const restrict src);

#ifdef _SHINSEI_OS_WINDOWS
	// Convert string to IPv4 address
	_SHINSEI_LIB_API bool shinsei_stringToIPv4N(register uint32_t*const restrict des,register const wchar_t*const restrict src,register const size_t src_len);

	// Convert IPv4 address to string
	_SHINSEI_LIB_API size_t shinsei_iPv4ToStringN(register wchar_t*const restrict des,register const uint32_t*const restrict src);

	// Convert string to IPv6 address
	_SHINSEI_LIB_API bool shinsei_stringToIPv6N(register uint32_t*const restrict des,register const wchar_t*const restrict src,register const size_t src_len);

	// Convert IPv6 address string
	_SHINSEI_LIB_API size_t shinsei_iPv6ToStringN(register wchar_t*const restrict des,register const uint32_t*const restrict src);
	
#elif defined(_SHINSEI_OS_UNIX)
	// Convert string to IPv4 address
	_SHINSEI_LIB_API bool shinsei_stringToIPv4N(register uint32_t*const restrict des,register const char8_t*const restrict src,register const size_t src_len);

	// Convert IPv4 address to string
	_SHINSEI_LIB_API size_t shinsei_iPv4ToStringN(register char8_t*const restrict des,register const uint32_t*const restrict src);

	// Convert string to IPv6 address
	_SHINSEI_LIB_API bool shinsei_stringToIPv6N(register uint32_t*const restrict des,register const char8_t*const restrict src,register const size_t src_len);

	// Convert IPv6 address string
	_SHINSEI_LIB_API size_t shinsei_iPv6ToStringN(register char8_t*const restrict des,register const uint32_t*const restrict src);
	
#endif

#include"shinsei/.internal/cpp_term.hpp"
#pragma once

#include"shinsei/.internal/usage.h"
#include"shinsei/.internal/wchar.h"
#include<stdbool.h>
#include<stdint.h>
#include<uchar.h>
#define _SHINSEI_MODULE_NETWORK_MINIMAL

#include"shinsei/.internal/cpp_init.hpp"

#ifdef _SHINSEI_OS_CONSTEXPR
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_MAX_IPV4_BUF=16;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_MAX_IPV6_BUF=40;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_MAX_MAPPED_IPV6_BUF=46;
#else
	#define SHINSEI_MAX_IPV4_BUF (size_t)16
	#define SHINSEI_MAX_IPV6_BUF (size_t)40
	#define SHINSEI_MAX_MAPPED_IPV6_BUF (size_t)46
#endif

// Convert string to IPv4 address
_SHINSEI_LIB_API bool shinsei_stringToIPv4CP(register const uint_fast32_t code_page,register uint32_t*const restrict des,register const char*const restrict src,register const size_t src_len);
_SHINSEI_LIB_API bool shinsei_stringToIPv4W(register uint32_t*const restrict des,register const wchar_t*const restrict src,register const size_t src_len);
_SHINSEI_LIB_API bool shinsei_stringToIPv4U8(register uint32_t*const restrict des,register const char8_t*const restrict src,register const size_t src_len);
_SHINSEI_LIB_API bool shinsei_stringToIPv4U16(register uint32_t*const restrict des,register const char16_t*const restrict src,register const size_t src_len);
_SHINSEI_LIB_API bool shinsei_stringToIPv4U32(register uint32_t*const restrict des,register const char32_t*const restrict src,register const size_t src_len);

// Convert IPv4 address to string
_SHINSEI_LIB_API size_t shinsei_iPv4ToStringCP(register const uint_fast32_t code_page,register char*const restrict des,register const uint32_t*const restrict src);
_SHINSEI_LIB_API size_t shinsei_iPv4ToStringW(register wchar_t*const restrict des,register const uint32_t*const restrict src);
_SHINSEI_LIB_API size_t shinsei_iPv4ToStringU8(register char8_t*const restrict des,register const uint32_t*const restrict src);
_SHINSEI_LIB_API size_t shinsei_iPv4ToStringU16(register char16_t*const restrict des,register const uint32_t*const restrict src);
_SHINSEI_LIB_API size_t shinsei_iPv4ToStringU32(register char32_t*const restrict des,register const uint32_t*const restrict src);

// Convert string to IPv6 address
_SHINSEI_LIB_API bool shinsei_stringToIPv6CP(register const uint_fast32_t code_page,register uint32_t*const restrict des,register const char*const restrict src,register const size_t src_len);
_SHINSEI_LIB_API bool shinsei_stringToIPv6W(register uint32_t*const restrict des,register const wchar_t*const restrict src,register const size_t src_len);
_SHINSEI_LIB_API bool shinsei_stringToIPv6U8(register uint32_t*const restrict des,register const char8_t*const restrict src,register const size_t src_len);
_SHINSEI_LIB_API bool shinsei_stringToIPv6U16(register uint32_t*const restrict des,register const char16_t*const restrict src,register const size_t src_len);
_SHINSEI_LIB_API bool shinsei_stringToIPv6U32(register uint32_t*const restrict des,register const char32_t*const restrict src,register const size_t src_len);

// Convert IPv6 address to string
_SHINSEI_LIB_API size_t shinsei_iPv6ToStringCP(register const uint_fast32_t code_page,register char*const restrict des,register const uint32_t*const restrict src);
_SHINSEI_LIB_API size_t shinsei_iPv6ToStringW(register wchar_t*const restrict des,register const uint32_t*const restrict src);
_SHINSEI_LIB_API size_t shinsei_iPv6ToStringU8(register char8_t*const restrict des,register const uint32_t*const restrict src);
_SHINSEI_LIB_API size_t shinsei_iPv6ToStringU16(register char16_t*const restrict des,register const uint32_t*const restrict src);
_SHINSEI_LIB_API size_t shinsei_iPv6ToStringU32(register char32_t*const restrict des,register const uint32_t*const restrict src);

// Convert string to mapped IPv6 address
_SHINSEI_LIB_API bool shinsei_stringToMappedIPv6CP(register const uint_fast32_t code_page,register uint32_t*const restrict des,register const char*const restrict src,register const size_t src_len);
_SHINSEI_LIB_API bool shinsei_stringToMappedIPv6W(register uint32_t*const restrict des,register const wchar_t*const restrict src,register const size_t src_len);
_SHINSEI_LIB_API bool shinsei_stringToMappedIPv6U8(register uint32_t*const restrict des,register const char8_t*const restrict src,register const size_t src_len);
_SHINSEI_LIB_API bool shinsei_stringToMappedIPv6U16(register uint32_t*const restrict des,register const char16_t*const restrict src,register const size_t src_len);
_SHINSEI_LIB_API bool shinsei_stringToMappedIPv6U32(register uint32_t*const restrict des,register const char32_t*const restrict src,register const size_t src_len);

// Convert mapped IPv6 address to string
_SHINSEI_LIB_API size_t shinsei_mappedIPv6ToStringCP(register const uint_fast32_t code_page,register char*const restrict des,register const uint32_t*const restrict src);
_SHINSEI_LIB_API size_t shinsei_mappedIPv6ToStringW(register wchar_t*const restrict des,register const uint32_t*const restrict src);
_SHINSEI_LIB_API size_t shinsei_mappedIPv6ToStringU8(register char8_t*const restrict des,register const uint32_t*const restrict src);
_SHINSEI_LIB_API size_t shinsei_mappedIPv6ToStringU16(register char16_t*const restrict des,register const uint32_t*const restrict src);
_SHINSEI_LIB_API size_t shinsei_mappedIPv6ToStringU32(register char32_t*const restrict des,register const uint32_t*const restrict src);

#include"shinsei/.internal/cpp_term.hpp"
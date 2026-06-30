#include"shinsei/network.h"

#include"shinsei/.internal/cpp_init.hpp"

// Convert string to IPv4 address
_SHINSEI_LIB_API bool shinsei_stringToIPv4A(register uint32_t*const restrict des,register const char*const restrict src,register const size_t src_len){
	return shinsei_stringToIPv4U8(des,(const char8_t*)src,src_len);
}
_SHINSEI_LIB_API bool shinsei_stringToIPv4N(register uint32_t*const restrict des,register const char8_t*const restrict src,register const size_t src_len){
	return shinsei_stringToIPv4U8(des,src,src_len);
}

// Convert IPv4 address to string
_SHINSEI_LIB_API size_t shinsei_iPv4ToStringA(register char*const restrict des,register const uint32_t*const restrict src){
	return shinsei_iPv4ToStringU8((char8_t*)des,src);
}
_SHINSEI_LIB_API size_t shinsei_iPv4ToStringN(register char8_t*const restrict des,register const uint32_t*const restrict src){
	return shinsei_iPv4ToStringU8(des,src);
}

// Convert string to IPv6 address
_SHINSEI_LIB_API bool shinsei_stringToIPv6A(register uint32_t*const restrict des,register const char*const restrict src,register const size_t src_len){
	return shinsei_stringToIPv6U8(des,(const char8_t*)src,src_len);
}
_SHINSEI_LIB_API bool shinsei_stringToIPv6N(register uint32_t*const restrict des,register const char8_t*const restrict src,register const size_t src_len){
	return shinsei_stringToIPv6U8(des,src,src_len);
}

// Convert IPv6 address string
_SHINSEI_LIB_API size_t shinsei_iPv6ToStringA(register char*const restrict des,register const uint32_t*const restrict src){
	return shinsei_iPv6ToStringU8((char8_t*)des,src);
}
_SHINSEI_LIB_API size_t shinsei_iPv6ToStringN(register char8_t*const restrict des,register const uint32_t*const restrict src){
	return shinsei_iPv6ToStringU8(des,src);
}

#include"shinsei/.internal/cpp_term.hpp"
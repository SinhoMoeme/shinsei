#pragma once

#include"shinsei/network.h"
#include"shinsei/minimal/network.hpp"

namespace shinsei{
	// Convert string to IPv4 address
	_SHINSEI_OS_INLINE bool stringToIPv4A(::uint32_t*const restrict des,const char*const restrict src,const ::size_t src_len){
		return ::shinsei_stringToIPv4A(des,src,src_len);
	}
	_SHINSEI_OS_INLINE bool stringToIPv4(::uint32_t*const restrict des,const char*const restrict src,const ::size_t src_len){
		return ::shinsei_stringToIPv4A(des,src,src_len);
	}
	
	// Convert IPv4 address to string
	_SHINSEI_OS_INLINE ::size_t iPv4ToStringA(char*const restrict des,const ::uint32_t*const restrict src){
		return ::shinsei_iPv4ToStringA(des,src);
	}
	_SHINSEI_OS_INLINE ::size_t iPv4ToString(char*const restrict des,const ::uint32_t*const restrict src){
		return ::shinsei_iPv4ToStringA(des,src);
	}
	
	// Convert string to IPv6 address
	_SHINSEI_OS_INLINE bool stringToIPv6A(::uint32_t*const restrict des,const char*const restrict src,const ::size_t src_len){
		return ::shinsei_stringToIPv6A(des,src,src_len);
	}
	_SHINSEI_OS_INLINE bool stringToIPv6(::uint32_t*const restrict des,const char*const restrict src,const ::size_t src_len){
		return ::shinsei_stringToIPv6A(des,src,src_len);
	}
	
	// Convert IPv6 address to string
	_SHINSEI_OS_INLINE ::size_t iPv6ToStringA(char*const restrict des,const ::uint32_t*const restrict src){
		return ::shinsei_iPv6ToStringA(des,src);
	}
	_SHINSEI_OS_INLINE ::size_t iPv6ToString(char*const restrict des,const ::uint32_t*const restrict src){
		return ::shinsei_iPv6ToStringA(des,src);
	}
	
	// Convert string to mapped IPv6 address
	_SHINSEI_OS_INLINE bool stringToMappedIPv6A(::uint32_t*const restrict des,const char*const restrict src,const ::size_t src_len){
		return ::shinsei_stringToMappedIPv6A(des,src,src_len);
	}
	_SHINSEI_OS_INLINE bool stringToMappedIPv6(::uint32_t*const restrict des,const char*const restrict src,const ::size_t src_len){
		return ::shinsei_stringToMappedIPv6A(des,src,src_len);
	}
	
	// Convert mapped IPv6 address to string
	_SHINSEI_OS_INLINE ::size_t mappedIPv6ToStringA(char*const restrict des,const ::uint32_t*const restrict src){
		return ::shinsei_mappedIPv6ToStringA(des,src);
	}
	_SHINSEI_OS_INLINE ::size_t mappedIPv6ToString(char*const restrict des,const ::uint32_t*const restrict src){
		return ::shinsei_mappedIPv6ToStringA(des,src);
	}
	
	#ifdef _SHINSEI_OS_WINDOWS
		// Convert string to IPv4 address
		_SHINSEI_OS_INLINE bool stringToIPv4N(::uint32_t*const restrict des,const wchar_t*const restrict src,const ::size_t src_len){
			return ::shinsei_stringToIPv4N(des,src,src_len);
		}
		
		// Convert IPv4 address to string
		_SHINSEI_OS_INLINE ::size_t iPv4ToStringN(wchar_t*const restrict des,const ::uint32_t*const restrict src){
			return ::shinsei_iPv4ToStringN(des,src);
		}
		
		// Convert string to IPv6 address
		_SHINSEI_OS_INLINE bool stringToIPv6N(::uint32_t*const restrict des,const wchar_t*const restrict src,const ::size_t src_len){
			return ::shinsei_stringToIPv6N(des,src,src_len);
		}
		
		// Convert IPv6 address to string
		_SHINSEI_OS_INLINE ::size_t iPv6ToStringN(wchar_t*const restrict des,const ::uint32_t*const restrict src){
			return ::shinsei_iPv6ToStringN(des,src);
		}
		
		// Convert string to mapped IPv6 address
		_SHINSEI_OS_INLINE bool stringToMappedIPv6N(::uint32_t*const restrict des,const wchar_t*const restrict src,const ::size_t src_len){
			return ::shinsei_stringToMappedIPv6N(des,src,src_len);
		}
		
		// Convert mapped IPv6 address to string
		_SHINSEI_OS_INLINE ::size_t mappedIPv6ToStringN(wchar_t*const restrict des,const ::uint32_t*const restrict src){
			return ::shinsei_mappedIPv6ToStringN(des,src);
		}
		
	#elif defined(_SHINSEI_OS_UNIX)
		// Convert string to IPv4 address
		_SHINSEI_OS_INLINE bool stringToIPv4N(::uint32_t*const restrict des,const char8_t*const restrict src,const ::size_t src_len){
			return ::shinsei_stringToIPv4N(des,src,src_len);
		}
		
		// Convert IPv4 address to string
		_SHINSEI_OS_INLINE ::size_t iPv4ToStringN(char8_t*const restrict des,const ::uint32_t*const restrict src){
			return ::shinsei_iPv4ToStringN(des,src);
		}
		
		// Convert string to IPv6 address
		_SHINSEI_OS_INLINE bool stringToIPv6N(::uint32_t*const restrict des,const char8_t*const restrict src,const ::size_t src_len){
			return ::shinsei_stringToIPv6N(des,src,src_len);
		}
		
		// Convert IPv6 address to string
		_SHINSEI_OS_INLINE ::size_t iPv6ToStringN(char8_t*const restrict des,const ::uint32_t*const restrict src){
			return ::shinsei_iPv6ToStringN(des,src);
		}
		
		// Convert string to mapped IPv6 address
		_SHINSEI_OS_INLINE bool stringToMappedIPv6N(::uint32_t*const restrict des,const char8_t*const restrict src,const ::size_t src_len){
			return ::shinsei_stringToMappedIPv6N(des,src,src_len);
		}
		
		// Convert mapped IPv6 address to string
		_SHINSEI_OS_INLINE ::size_t mappedIPv6ToStringN(char8_t*const restrict des,const ::uint32_t*const restrict src){
			return ::shinsei_mappedIPv6ToStringN(des,src);
		}
		
	#endif
}
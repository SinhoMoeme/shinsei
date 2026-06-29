#pragma once

#include"shinsei/minimal/network.h"

namespace jail301{
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_IPV4_BUF=::SHINSEI_MAX_IPV4_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_IPV6_BUF=::SHINSEI_MAX_IPv6_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_MAPPED_IPV6_BUF=::SHINSEI_MAX_MAPPED_IPV6_BUF;
	
	// Convert string to IPv4 address
	_SHINSEI_OS_INLINE bool stringToIPv4CP(const ::uint_fast32_t code_page,::uint32_t*const restrict des,const char*const restrict src,const ::size_t src_len){
		return ::shinsei_stringToIPv4CP(code_page,des,src,src_len);
	}
	_SHINSEI_OS_INLINE bool stringToIPv4W(::uint32_t*const restrict des,const wchar_t*const restrict src,const ::size_t src_len){
		return ::shinsei_string_stringToIPv4W(des,src,src_len);
	}
	_SHINSEI_OS_INLINE bool stringToIPv4U8(::uint32_t*const restrict des,const char8_t*const restrict src,const ::size_t src_len){
		return ::shinsei_string_stringToIPv4U8(des,src,src_len);
	}
	_SHINSEI_OS_INLINE bool stringToIPv4U16(::uint32_t*const restrict des,const char16_t*const restrict src,const ::size_t src_len){
		return ::shinsei_string_stringToIPv4U16(des,src,src_len);
	}
	_SHINSEI_OS_INLINE bool stringToIPv4U32(::uint32_t*const restrict des,const char32_t*const restrict src,const ::size_t src_len){
		return ::shinsei_string_stringToIPv4U32(des,src,src_len);
	}
	
	// Convert IPv4 address to string
	_SHINSEI_OS_INLINE ::size_t iPv4ToStringCP(const ::uint_fast32_t code_page,char*const restrict des,const ::uint32_t*const restrict src){
		return ::shinsei_iPv4ToStringCP(code_page,des,src);
	}
	_SHINSEI_OS_INLINE ::size_t iPv4ToStringW(wchar_t*const restrict des,const ::uint32_t*const restrict src){
		return ::shinsei_iPv4ToStringW(des,src);
	}
	_SHINSEI_OS_INLINE ::size_t iPv4ToStringU8(char8_t*const restrict des,const ::uint32_t*const restrict src){
		return ::shinsei_iPv4ToStringU8(des,src);
	}
	_SHINSEI_OS_INLINE ::size_t iPv4ToStringU16(char16_t*const restrict des,const ::uint32_t*const restrict src){
		return ::shinsei_iPv4ToStringU16(des,src);
	}
	_SHINSEI_OS_INLINE ::size_t iPv4ToStringU32(char32_t*const restrict des,const ::uint32_t*const restrict src){
		return ::shinsei_iPv4ToStringU32(des,src);
	}
	
	// Convert string to IPv6 address
	_SHINSEI_OS_INLINE bool stringToIPv6CP(const ::uint_fast32_t code_page,::uint32_t*const restrict des,const char*const restrict src,const ::size_t src_len){
		return ::shinsei_stringToIPv6CP(code_page,des,src,src_len);
	}
	_SHINSEI_OS_INLINE bool stringToIPv6W(::uint32_t*const restrict des,const wchar_t*const restrict src,const ::size_t src_len){
		return ::shinsei_stringToIPv6W(des,src,src_len);
	}
	_SHINSEI_OS_INLINE bool stringToIPv6U8(::uint32_t*const restrict des,const char8_t*const restrict src,const ::size_t src_len){
		return ::shinsei_stringToIPv6U8(des,src,src_len);
	}
	_SHINSEI_OS_INLINE bool stringToIPv6U16(::uint32_t*const restrict des,const char16_t*const restrict src,const ::size_t src_len){
		return ::shinsei_stringToIPv6U16(des,src,src_len);
	}
	_SHINSEI_OS_INLINE bool stringToIPv6U32(::uint32_t*const restrict des,const char32_t*const restrict src,const ::size_t src_len){
		return ::shinsei_stringToIPv6U32(des,src,src_len);
	}
	
	// Convert IPv6 address string
	_SHINSEI_OS_INLINE ::size_t iPv6ToStringCP(const ::uint_fast32_t code_page,char*const restrict des,const ::uint32_t*const restrict src){
		return ::shinsei_iPv6ToStringCP(code_page,des,src);
	}
	_SHINSEI_OS_INLINE ::size_t iPv6ToStringW(wchar_t*const restrict des,const ::uint32_t*const restrict src){
		return ::shinsei_iPv6ToStringW(des,src);
	}
	_SHINSEI_OS_INLINE ::size_t iPv6ToStringU8(char8_t*const restrict des,const ::uint32_t*const restrict src){
		return ::shinsei_iPv6ToStringU8(des,src);
	}
	_SHINSEI_OS_INLINE ::size_t iPv6ToStringU16(char16_t*const restrict des,const ::uint32_t*const restrict src){
		return ::shinsei_iPv6ToStringU16(des,src);
	}
	_SHINSEI_OS_INLINE ::size_t iPv6ToStringU32(char32_t*const restrict des,const ::uint32_t*const restrict src){
		return ::shinsei_iPv6ToStringU32(des,src);
	}
}
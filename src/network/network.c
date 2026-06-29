#include"shinsei/minimal/network.h"

#include"shinsei/.internal/cpp_init_source.hpp"

#include"shinsei/.internal/str/ebcdic.h"
// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isEBCDICCodePage(const uint_fast32_t id)_SHINSEI_OS_NOEXCEPT{
	switch(id){
		case SHINSEI_CODE_PAGE_IBM037:
		case SHINSEI_CODE_PAGE_IBM500:
		case SHINSEI_CODE_PAGE_IBM1026:
		case SHINSEI_CODE_PAGE_IBM01140:
		case SHINSEI_CODE_PAGE_IBM01141:
		case SHINSEI_CODE_PAGE_IBM01142:
		case SHINSEI_CODE_PAGE_IBM01143:
		case SHINSEI_CODE_PAGE_IBM01144:
		case SHINSEI_CODE_PAGE_IBM01145:
		case SHINSEI_CODE_PAGE_IBM01146:
		case SHINSEI_CODE_PAGE_IBM01147:
		case SHINSEI_CODE_PAGE_IBM01148:
		case SHINSEI_CODE_PAGE_IBM01149:
		case SHINSEI_CODE_PAGE_IBM273:
		case SHINSEI_CODE_PAGE_IBM277:
		case SHINSEI_CODE_PAGE_IBM278:
		case SHINSEI_CODE_PAGE_IBM280:
		case SHINSEI_CODE_PAGE_IBM284:
		case SHINSEI_CODE_PAGE_IBM285:
		case SHINSEI_CODE_PAGE_IBM290:
		case SHINSEI_CODE_PAGE_IBM297:
		case SHINSEI_CODE_PAGE_IBM420:
		case SHINSEI_CODE_PAGE_IBM423:
		case SHINSEI_CODE_PAGE_IBM424:
		case SHINSEI_CODE_PAGE_IBM871:
		case SHINSEI_CODE_PAGE_IBM880:
		case SHINSEI_CODE_PAGE_IBM905:
		case SHINSEI_CODE_PAGE_IBM00924:
		case SHINSEI_CODE_PAGE_CP1025:
		case SHINSEI_CODE_PAGE_X_EBCDIC_KOREANEXTENDED:
		case SHINSEI_CODE_PAGE_EBCDIC_JA_KATAKANA_EXTENDED:
		case SHINSEI_CODE_PAGE_EBCDIC_US_CA_JP:
		case SHINSEI_CODE_PAGE_EBCDIC_KO_EXTENDED:
		case SHINSEI_CODE_PAGE_EBCDIC_SC_EXTENDED:
		case SHINSEI_CODE_PAGE_EBCDIC_SC:
		case SHINSEI_CODE_PAGE_EBCDIC_US_CA_TC:
		case SHINSEI_CODE_PAGE_EBCDIC_JA_LATIN_EXTENDED:{
			return true;
		}
	}
	return false;
}

// Convert string to IPv4 address
_SHINSEI_OS_INLINE static bool stringToIPv4U16(register uint32_t*const restrict des,register const char16_t*const restrict src,register const size_t src_len){
	register uint_fast16_t res=0;
	for(register size_t i=0;i<src_len;++i){
		
	}
}
_SHINSEI_OS_INLINE static bool stringToIPv4U32(register uint32_t*const restrict des,register const char32_t*const restrict src,register const size_t src_len){
	
}
bool shinsei_stringToIPv4CP(register const uint_fast32_t code_page,register uint32_t*const restrict des,register const char*const restrict src,register const size_t src_len){
	register const bool ebcdic=isEBCDICCodePage(code_page);
	
}
bool shinsei_stringToIPv4W(register uint32_t*const restrict des,register const wchar_t*const restrict src,register const size_t src_len){
	#ifdef _SHINSEI_WCHAR_U32
		return stringToIPv4U32(des,src,src_len);
	#else
		return stringToIPv4U16(des,src,src_len);
	#endif
}
bool shinsei_stringToIPv4U8(register uint32_t*const restrict des,register const char8_t*const restrict src,register const size_t src_len){
	
}
bool shinsei_stringToIPv4U16(register uint32_t*const restrict des,register const char16_t*const restrict src,register const size_t src_len){
	return stringToIPv4U16(des,src,src_len);
}
bool shinsei_stringToIPv4U32(register uint32_t*const restrict des,register const char32_t*const restrict src,register const size_t src_len){
	return stringToIPv4U32(des,src,src_len);
}

// Convert IPv4 address to string
_SHINSEI_OS_INLINE static size_t iPv4ToStringU16(register char16_t*const restrict des,register const uint32_t*const restrict src){
	
}
_SHINSEI_OS_INLINE static size_t iPv4ToStringU32(register char32_t*const restrict des,register const uint32_t*const restrict src){
	
}
size_t shinsei_iPv4ToStringCP(register const uint_fast32_t code_page,register char*const restrict des,register const uint32_t*const restrict src){
	register const bool ebcdic=isEBCDICCodePage(code_page);
	
}
size_t shinsei_iPv4ToStringW(register wchar_t*const restrict des,register const uint32_t*const restrict src){
	#ifdef _SHINSEI_WCHAR_U32
		return iPv4ToStringU32(des,src);
	#else
		return iPv4ToStringU16(des,src);
	#endif
}
size_t shinsei_iPv4ToStringU8(register char8_t*const restrict des,register const uint32_t*const restrict src){
	
}
size_t shinsei_iPv4ToStringU16(register char16_t*const restrict des,register const uint32_t*const restrict src){
	return iPv4ToStringU16(des,src);
}
size_t shinsei_iPv4ToStringU32(register char32_t*const restrict des,register const uint32_t*const restrict src){
	return iPv4ToStringU32(des,src);
}

// Convert string to IPv6 address
_SHINSEI_OS_INLINE static bool stringToIPv6U16(register uint32_t*const restrict des,register const char16_t*const restrict src,register const size_t src_len){
	
}
_SHINSEI_OS_INLINE static bool stringToIPv6U32(register uint32_t*const restrict des,register const char32_t*const restrict src,register const size_t src_len){
	
}
bool shinsei_stringToIPv6CP(register const uint_fast32_t code_page,register uint32_t*const restrict des,register const char*const restrict src,register const size_t src_len){
	register const bool ebcdic=isEBCDICCodePage(code_page);
	
}
bool shinsei_stringToIPv6W(register uint32_t*const restrict des,register const wchar_t*const restrict src,register const size_t src_len){
	#ifdef _SHINSEI_WCHAR_U32
		return stringToIPv6U32(des,src,src_len);
	#else
		return stringToIPv6U16(des,src,src_len);
	#endif
}
bool shinsei_stringToIPv6U8(register uint32_t*const restrict des,register const char8_t*const restrict src,register const size_t src_len){
	
}
bool shinsei_stringToIPv6U16(register uint32_t*const restrict des,register const char16_t*const restrict src,register const size_t src_len){
	return stringToIPv6U16(des,src,src_len);
}
bool shinsei_stringToIPv6U32(register uint32_t*const restrict des,register const char32_t*const restrict src,register const size_t src_len){
	return stringToIPv6U32(des,src,src_len);
}

// Convert IPv6 address string
_SHINSEI_OS_INLINE static size_t iPv6ToStringU16(register char16_t*const restrict des,register const uint32_t*const restrict src){
	
}
_SHINSEI_OS_INLINE static size_t iPv6ToStringU32(register char32_t*const restrict des,register const uint32_t*const restrict src){
	
}
size_t shinsei_iPv6ToStringCP(register const uint_fast32_t code_page,register char*const restrict des,register const uint32_t*const restrict src){
	register const bool ebcdic=isEBCDICCodePage(code_page);
	
}
size_t shinsei_iPv6ToStringW(register wchar_t*const restrict des,register const uint32_t*const restrict src){
	#ifdef _SHINSEI_WCHAR_U32
		return iPv6ToStringU32(des,src);
	#else
		return iPv6ToStringU16(des,src);
	#endif
}
size_t shinsei_iPv6ToStringU8(register char8_t*const restrict des,register const uint32_t*const restrict src){
	
}
size_t shinsei_iPv6ToStringU16(register char16_t*const restrict des,register const uint32_t*const restrict src){
	return iPv6ToStringU16(des,src);
}
size_t shinsei_iPv6ToStringU32(register char32_t*const restrict des,register const uint32_t*const restrict src){
	return iPv6ToStringU32(des,src);
}

#include"shinsei/.internal/cpp_term_source.hpp"
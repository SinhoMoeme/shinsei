#include"path.h"

bool shinsei_isWindowsPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isWindowsPathDelimiterU8((char8_t)ch);
}
bool shinsei_isWindowsPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathDelimiterU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isWindowsPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isWindowsPathDelimiterU8(ch);
}
bool shinsei_isWindowsPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathDelimiterU8M(str_ptr,len);
}

bool shinsei_isUnixPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isUnixPathDelimiterU8((char8_t)ch);
}
bool shinsei_isUnixPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isUnixPathDelimiterU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isUnixPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isUnixPathDelimiterU8(ch);
}
bool shinsei_isUnixPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isUnixPathDelimiterU8M(str_ptr,len);
}

bool shinsei_isLinuxPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isLinuxPathDelimiterU8((char8_t)ch);
}
bool shinsei_isLinuxPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isLinuxPathDelimiterU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isLinuxPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isLinuxPathDelimiterU8(ch);
}
bool shinsei_isLinuxPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isLinuxPathDelimiterU8M(str_ptr,len);
}

bool shinsei_isApplePathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isApplePathDelimiterU8((char8_t)ch);
}
bool shinsei_isApplePathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isApplePathDelimiterU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isApplePathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isApplePathDelimiterU8(ch);
}
bool shinsei_isApplePathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isApplePathDelimiterU8M(str_ptr,len);
}

bool shinsei_isSunPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isSunPathDelimiterU8((char8_t)ch);
}
bool shinsei_isSunPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isSunPathDelimiterU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isSunPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isSunPathDelimiterU8(ch);
}
bool shinsei_isSunPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isSunPathDelimiterU8M(str_ptr,len);
}

bool shinsei_isFreeBSDPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isFreeBSDPathDelimiterU8((char8_t)ch);
}
bool shinsei_isFreeBSDPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isFreeBSDPathDelimiterU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isFreeBSDPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isFreeBSDPathDelimiterU8(ch);
}
bool shinsei_isFreeBSDPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isFreeBSDPathDelimiterU8M(str_ptr,len);
}

bool shinsei_isCygwinPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isCygwinPathDelimiterU8((char8_t)ch);
}
bool shinsei_isCygwinPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isCygwinPathDelimiterU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isCygwinPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isCygwinPathDelimiterU8(ch);
}
bool shinsei_isCygwinPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isCygwinPathDelimiterU8M(str_ptr,len);
}

bool shinsei_isNativePathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isNativePathDelimiterU8((char8_t)ch);
}
bool shinsei_isNativePathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isNativePathDelimiterU8M((const char8_t**const restrict)str_ptr,len);
}
bool shinsei_isNativePathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathDelimiterW(ch);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathDelimiterW(ch);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathDelimiterW(ch);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathDelimiterW(ch);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathDelimiterW(ch);
	#else
		return isUnixPathDelimiterW(ch);
	#endif
}
bool shinsei_isNativePathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathDelimiterWM(str_ptr,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathDelimiterWM(str_ptr,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathDelimiterWM(str_ptr,len);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathDelimiterWM(str_ptr,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathDelimiterWM(str_ptr,len);
	#else
		return isUnixPathDelimiterWM(str_ptr,len);
	#endif
}
bool shinsei_isNativePathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathDelimiterCP(code_page,ch);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathDelimiterCP(code_page,ch);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathDelimiterCP(code_page,ch);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathDelimiterCP(code_page,ch);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathDelimiterCP(code_page,ch);
	#else
		return isUnixPathDelimiterCP(code_page,ch);
	#endif
}
bool shinsei_isNativePathDelimiterCPM(const unsigned int code_page,const char**const restrict str_ptr,const size_t len,int*const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathDelimiterCPM(code_page,str_ptr,len,status);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathDelimiterCPM(code_page,str_ptr,len,status);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathDelimiterCPM(code_page,str_ptr,len,status);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathDelimiterCPM(code_page,str_ptr,len,status);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathDelimiterCPM(code_page,str_ptr,len,status);
	#else
		return isUnixPathDelimiterCPM(code_page,str_ptr,len,status);
	#endif
}
bool shinsei_isNativePathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathDelimiterU8(ch);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathDelimiterU8(ch);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathDelimiterU8(ch);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathDelimiterU8(ch);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathDelimiterU8(ch);
	#else
		return isUnixPathDelimiterU8(ch);
	#endif
}
bool shinsei_isNativePathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathDelimiterU8M(str_ptr,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathDelimiterU8M(str_ptr,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathDelimiterU8M(str_ptr,len);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathDelimiterU8M(str_ptr,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathDelimiterU8M(str_ptr,len);
	#else
		return isUnixPathDelimiterU8M(str_ptr,len);
	#endif
}
bool shinsei_isNativePathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathDelimiterU16(ch);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathDelimiterU16(ch);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathDelimiterU16(ch);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathDelimiterU16(ch);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathDelimiterU16(ch);
	#else
		return isUnixPathDelimiterU16(ch);
	#endif
}
bool shinsei_isNativePathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathDelimiterU16M(str_ptr,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathDelimiterU16M(str_ptr,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathDelimiterU16M(str_ptr,len);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathDelimiterU16M(str_ptr,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathDelimiterU16M(str_ptr,len);
	#else
		return isUnixPathDelimiterU16M(str_ptr,len);
	#endif
}
bool shinsei_isNativePathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathDelimiterU32(ch);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathDelimiterU32(ch);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathDelimiterU32(ch);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathDelimiterU32(ch);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathDelimiterU32(ch);
	#else
		return isUnixPathDelimiterU32(ch);
	#endif
}
bool shinsei_isNativePathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathDelimiterU32M(str_ptr,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathDelimiterU32M(str_ptr,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathDelimiterU32M(str_ptr,len);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathDelimiterU32M(str_ptr,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathDelimiterU32M(str_ptr,len);
	#else
		return isUnixPathDelimiterU32M(str_ptr,len);
	#endif
}
bool shinsei_isNativePathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isNativePathDelimiterU8(ch);
}
bool shinsei_isNativePathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isNativePathDelimiterU8M(str_ptr,len);
}

bool shinsei_isURLPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isURLPathDelimiterU8((char8_t)ch);
}
bool shinsei_isURLPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isURLPathDelimiterU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isURLPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isURLPathDelimiterU8(ch);
}
bool shinsei_isURLPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isURLPathDelimiterU8M(str_ptr,len);
}

bool shinsei_isWindowsPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isWindowsPathIllegalCharU8((char8_t)ch);
}
bool shinsei_isWindowsPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathIllegalCharU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isWindowsPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isWindowsPathIllegalCharU8(ch);
}
bool shinsei_isWindowsPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathIllegalCharU8M(str_ptr,len);
}

bool shinsei_isUnixPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isUnixPathIllegalCharU8((char8_t)ch);
}
bool shinsei_isUnixPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isUnixPathIllegalCharU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isUnixPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isUnixPathIllegalCharU8(ch);
}
bool shinsei_isUnixPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isUnixPathIllegalCharU8M(str_ptr,len);
}

bool shinsei_isLinuxPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isLinuxPathIllegalCharU8((char8_t)ch);
}
bool shinsei_isLinuxPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isLinuxPathIllegalCharU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isLinuxPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isLinuxPathIllegalCharU8(ch);
}
bool shinsei_isLinuxPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isLinuxPathIllegalCharU8M(str_ptr,len);
}

bool shinsei_isApplePathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isApplePathIllegalCharU8((char8_t)ch);
}
bool shinsei_isApplePathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isApplePathIllegalCharU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isApplePathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isApplePathIllegalCharU8(ch);
}
bool shinsei_isApplePathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isApplePathIllegalCharU8M(str_ptr,len);
}

bool shinsei_isSunPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isSunPathIllegalCharU8((char8_t)ch);
}
bool shinsei_isSunPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isSunPathIllegalCharU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isSunPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isSunPathIllegalCharU8(ch);
}
bool shinsei_isSunPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isSunPathIllegalCharU8M(str_ptr,len);
}

bool shinsei_isFreeBSDPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isFreeBSDPathIllegalCharU8((char8_t)ch);
}
bool shinsei_isFreeBSDPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isFreeBSDPathIllegalCharU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isFreeBSDPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isFreeBSDPathIllegalCharU8(ch);
}
bool shinsei_isFreeBSDPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isFreeBSDPathIllegalCharU8M(str_ptr,len);
}

bool shinsei_isCygwinPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isCygwinPathIllegalCharU8((char8_t)ch);
}
bool shinsei_isCygwinPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isCygwinPathIllegalCharU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isCygwinPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isCygwinPathIllegalCharU8(ch);
}
bool shinsei_isCygwinPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isCygwinPathIllegalCharU8M(str_ptr,len);
}

bool shinsei_isNativePathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isNativePathIllegalCharU8((char8_t)ch);
}
bool shinsei_isNativePathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isNativePathIllegalCharU8M((const char8_t**const restrict)str_ptr,len);
}
bool shinsei_isNativePathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathIllegalCharW(ch);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathIllegalCharW(ch);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathIllegalCharW(ch);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathIllegalCharW(ch);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathIllegalCharW(ch);
	#else
		return isUnixPathIllegalCharW(ch);
	#endif
}
bool shinsei_isNativePathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathIllegalCharWM(str_ptr,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathIllegalCharWM(str_ptr,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathIllegalCharWM(str_ptr,len);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathIllegalCharWM(str_ptr,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathIllegalCharWM(str_ptr,len);
	#else
		return isUnixPathIllegalCharWM(str_ptr,len);
	#endif
}
bool shinsei_isNativePathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathIllegalCharCP(code_page,ch);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathIllegalCharCP(code_page,ch);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathIllegalCharCP(code_page,ch);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathIllegalCharCP(code_page,ch);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathIllegalCharCP(code_page,ch);
	#else
		return isUnixPathIllegalCharCP(code_page,ch);
	#endif
}
bool shinsei_isNativePathIllegalCharCPM(const unsigned int code_page,const char**const restrict str_ptr,const size_t len,int*const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathIllegalCharCPM(code_page,str_ptr,len,status);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathIllegalCharCPM(code_page,str_ptr,len,status);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathIllegalCharCPM(code_page,str_ptr,len,status);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathIllegalCharCPM(code_page,str_ptr,len,status);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathIllegalCharCPM(code_page,str_ptr,len,status);
	#else
		return isUnixPathIllegalCharCPM(code_page,str_ptr,len,status);
	#endif
}
bool shinsei_isNativePathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathIllegalCharU8(ch);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathIllegalCharU8(ch);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathIllegalCharU8(ch);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathIllegalCharU8(ch);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathIllegalCharU8(ch);
	#else
		return isUnixPathIllegalCharU8(ch);
	#endif
}
bool shinsei_isNativePathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathIllegalCharU8M(str_ptr,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathIllegalCharU8M(str_ptr,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathIllegalCharU8M(str_ptr,len);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathIllegalCharU8M(str_ptr,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathIllegalCharU8M(str_ptr,len);
	#else
		return isUnixPathIllegalCharU8M(str_ptr,len);
	#endif
}
bool shinsei_isNativePathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathIllegalCharU16(ch);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathIllegalCharU16(ch);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathIllegalCharU16(ch);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathIllegalCharU16(ch);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathIllegalCharU16(ch);
	#else
		return isUnixPathIllegalCharU16(ch);
	#endif
}
bool shinsei_isNativePathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathIllegalCharU16M(str_ptr,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathIllegalCharU16M(str_ptr,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathIllegalCharU16M(str_ptr,len);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathIllegalCharU16M(str_ptr,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathIllegalCharU16M(str_ptr,len);
	#else
		return isUnixPathIllegalCharU16M(str_ptr,len);
	#endif
}
bool shinsei_isNativePathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathIllegalCharU32(ch);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathIllegalCharU32(ch);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathIllegalCharU32(ch);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathIllegalCharU32(ch);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathIllegalCharU32(ch);
	#else
		return isUnixPathIllegalCharU32(ch);
	#endif
}
bool shinsei_isNativePathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#if defined(_SHINSEI_OS_APPLE)
		return isApplePathIllegalCharU32M(str_ptr,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return isLinuxPathIllegalCharU32M(str_ptr,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return isFreeBSDPathIllegalCharU32M(str_ptr,len);
	#elif defined(_SHINSEI_OS_SUN)
		return isSunPathIllegalCharU32M(str_ptr,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return isCygwinPathIllegalCharU32M(str_ptr,len);
	#else
		return isUnixPathIllegalCharU32M(str_ptr,len);
	#endif
}
bool shinsei_isNativePathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isNativePathIllegalCharU8(ch);
}
bool shinsei_isNativePathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isNativePathIllegalCharU8M(str_ptr,len);
}

bool shinsei_isURLPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isURLPathIllegalCharU8((char8_t)ch);
}
bool shinsei_isURLPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isURLPathIllegalCharU8M((const char8_t**)str_ptr,len);
}
bool shinsei_isURLPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return shinsei_isURLPathIllegalCharU8(ch);
}
bool shinsei_isURLPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isURLPathIllegalCharU8M(str_ptr,len);
}

int shinsei_windowsPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeU8((char8_t*)path,len);
}
int shinsei_windowsPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeU8(path,len);
}

int shinsei_unixPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_unixPathNormalizeU8((char8_t*)path,len);
}
int shinsei_unixPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_unixPathNormalizeU8(path,len);
}

int shinsei_linuxPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_linuxPathNormalizeU8((char8_t*)path,len);
}
int shinsei_linuxPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_linuxPathNormalizeU8(path,len);
}

int shinsei_applePathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_applePathNormalizeU8((char8_t*)path,len);
}
int shinsei_applePathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_applePathNormalizeU8(path,len);
}

int shinsei_sunPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_sunPathNormalizeU8((char8_t*)path,len);
}
int shinsei_sunPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_sunPathNormalizeU8(path,len);
}

int shinsei_freeBSDPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_freeBSDPathNormalizeU8((char8_t*)path,len);
}
int shinsei_freeBSDPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_freeBSDPathNormalizeU8(path,len);
}

int shinsei_cygwinPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_cygwinPathNormalizeU8((char8_t*)path,len);
}
int shinsei_cygwinPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_cygwinPathNormalizeU8(path,len);
}

int shinsei_nativePathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	#if defined(_SHINSEI_OS_APPLE)
		return shinsei_applePathNormalizeW(path,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return shinsei_linuxPathNormalizeW(path,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return shinsei_freeBSDPathNormalizeW(path,len);
	#elif defined(_SHINSEI_OS_SUN)
		return shinsei_sunPathNormalizeW(path,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return shinsei_cygwinPathNormalizeW(path,len);
	#else
		return shinsei_unixPathNormalizeW(path,len);
	#endif
}
int shinsei_nativePathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	#if defined(_SHINSEI_OS_APPLE)
		return shinsei_applePathNormalizeCP(code_page,path,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return shinsei_linuxPathNormalizeCP(code_page,path,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return shinsei_freeBSDPathNormalizeCP(code_page,path,len);
	#elif defined(_SHINSEI_OS_SUN)
		return shinsei_sunPathNormalizeCP(code_page,path,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return shinsei_cygwinPathNormalizeCP(code_page,path,len);
	#else
		return shinsei_unixPathNormalizeCP(code_page,path,len);
	#endif
}
int shinsei_nativePathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	#if defined(_SHINSEI_OS_APPLE)
		return shinsei_applePathNormalizeU8(path,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return shinsei_linuxPathNormalizeU8(path,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return shinsei_freeBSDPathNormalizeU8(path,len);
	#elif defined(_SHINSEI_OS_SUN)
		return shinsei_sunPathNormalizeU8(path,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return shinsei_cygwinPathNormalizeU8(path,len);
	#else
		return shinsei_unixPathNormalizeU8(path,len);
	#endif
}
int shinsei_nativePathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	#if defined(_SHINSEI_OS_APPLE)
		return shinsei_applePathNormalizeU16(path,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return shinsei_linuxPathNormalizeU16(path,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return shinsei_freeBSDPathNormalizeU16(path,len);
	#elif defined(_SHINSEI_OS_SUN)
		return shinsei_sunPathNormalizeU16(path,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return shinsei_cygwinPathNormalizeU16(path,len);
	#else
		return shinsei_unixPathNormalizeU16(path,len);
	#endif
}
int shinsei_nativePathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	#if defined(_SHINSEI_OS_APPLE)
		return shinsei_applePathNormalizeU32(path,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return shinsei_linuxPathNormalizeU32(path,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return shinsei_freeBSDPathNormalizeU32(path,len);
	#elif defined(_SHINSEI_OS_SUN)
		return shinsei_sunPathNormalizeU32(path,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return shinsei_cygwinPathNormalizeU32(path,len);
	#else
		return shinsei_unixPathNormalizeU32(path,len);
	#endif
}
int shinsei_nativePathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_nativePathNormalizeU8((char8_t*)path,len);
}
int shinsei_nativePathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_nativePathNormalizeU8(path,len);
}

int shinsei_uRLPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_uRLPathNormalizeU8((char8_t*)path,len);
}
int shinsei_uRLPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_uRLPathNormalizeU8(path,len);
}

int shinsei_windowsPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeNoTraversalU8((char8_t*)path,len);
}
int shinsei_windowsPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeNoTraversalU8(path,len);
}

int shinsei_unixPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_unixPathNormalizeNoTraversalU8((char8_t*)path,len);
}
int shinsei_unixPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_unixPathNormalizeNoTraversalU8(path,len);
}

int shinsei_linuxPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_linuxPathNormalizeNoTraversalU8((char8_t*)path,len);
}
int shinsei_linuxPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_linuxPathNormalizeNoTraversalU8(path,len);
}

int shinsei_applePathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_applePathNormalizeNoTraversalU8((char8_t*)path,len);
}
int shinsei_applePathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_applePathNormalizeNoTraversalU8(path,len);
}

int shinsei_sunPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_sunPathNormalizeNoTraversalU8((char8_t*)path,len);
}
int shinsei_sunPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_sunPathNormalizeNoTraversalU8(path,len);
}

int shinsei_freeBSDPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_freeBSDPathNormalizeNoTraversalU8((char8_t*)path,len);
}
int shinsei_freeBSDPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_freeBSDPathNormalizeNoTraversalU8(path,len);
}

int shinsei_cygwinPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_cygwinPathNormalizeNoTraversalU8((char8_t*)path,len);
}
int shinsei_cygwinPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_cygwinPathNormalizeNoTraversalU8(path,len);
}

_SHINSEI_OS_INLINE static int nativePathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	#if defined(_SHINSEI_OS_APPLE)
		return shinsei_applePathNormalizeNoTraversalU16(path,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return shinsei_linuxPathNormalizeNoTraversalU16(path,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return shinsei_freeBSDPathNormalizeNoTraversalU16(path,len);
	#elif defined(_SHINSEI_OS_SUN)
		return shinsei_sunPathNormalizeNoTraversalU16(path,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return shinsei_cygwinPathNormalizeNoTraversalU16(path,len);
	#else
		return shinsei_unixPathNormalizeNoTraversalU16(path,len);
	#endif
}
_SHINSEI_OS_INLINE static int nativePathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	#if defined(_SHINSEI_OS_APPLE)
		return shinsei_applePathNormalizeNoTraversalU32(path,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return shinsei_linuxPathNormalizeNoTraversalU32(path,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return shinsei_freeBSDPathNormalizeNoTraversalU32(path,len);
	#elif defined(_SHINSEI_OS_SUN)
		return shinsei_sunPathNormalizeNoTraversalU32(path,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return shinsei_cygwinPathNormalizeNoTraversalU32(path,len);
	#else
		return shinsei_unixPathNormalizeNoTraversalU32(path,len);
	#endif
}

int shinsei_nativePathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	#if defined(_SHINSEI_OS_APPLE)
		return shinsei_applePathNormalizeNoTraversalW(path,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return shinsei_linuxPathNormalizeNoTraversalW(path,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return shinsei_freeBSDPathNormalizeNoTraversalW(path,len);
	#elif defined(_SHINSEI_OS_SUN)
		return shinsei_sunPathNormalizeNoTraversalW(path,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return shinsei_cygwinPathNormalizeNoTraversalW(path,len);
	#else
		return shinsei_unixPathNormalizeNoTraversalW(path,len);
	#endif
}
int shinsei_nativePathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	#if defined(_SHINSEI_OS_APPLE)
		return shinsei_applePathNormalizeNoTraversalCP(code_page,path,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return shinsei_linuxPathNormalizeNoTraversalCP(code_page,path,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return shinsei_freeBSDPathNormalizeNoTraversalCP(code_page,path,len);
	#elif defined(_SHINSEI_OS_SUN)
		return shinsei_sunPathNormalizeNoTraversalCP(code_page,path,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return shinsei_cygwinPathNormalizeNoTraversalCP(code_page,path,len);
	#else
		return shinsei_unixPathNormalizeNoTraversalCP(code_page,path,len);
	#endif
}
int shinsei_nativePathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	#if defined(_SHINSEI_OS_APPLE)
		return shinsei_applePathNormalizeNoTraversalU8(path,len);
	#elif defined(_SHINSEI_OS_LINUX)
		return shinsei_linuxPathNormalizeNoTraversalU8(path,len);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return shinsei_freeBSDPathNormalizeNoTraversalU8(path,len);
	#elif defined(_SHINSEI_OS_SUN)
		return shinsei_sunPathNormalizeNoTraversalU8(path,len);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return shinsei_cygwinPathNormalizeNoTraversalU8(path,len);
	#else
		return shinsei_unixPathNormalizeNoTraversalU8(path,len);
	#endif
}
int shinsei_nativePathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return nativePathNormalizeNoTraversalU16(path,len);
}
int shinsei_nativePathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return nativePathNormalizeNoTraversalU32(path,len);
}
int shinsei_nativePathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_nativePathNormalizeNoTraversalU8((char8_t*)path,len);
}
int shinsei_nativePathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_nativePathNormalizeNoTraversalU8(path,len);
}

int shinsei_uRLPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_uRLPathNormalizeNoTraversalU8((char8_t*)path,len);
}
int shinsei_uRLPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_uRLPathNormalizeNoTraversalU8(path,len);
}

// Copy from str/str.c
_SHINSEI_OS_INLINE static int uTF32CharToUTF16Char(char16_t*const restrict des,const char32_t src)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(src<0x10000,1)){
		des[0]=(char16_t)src;
		return 1;
	}
	register const char32_t res=src-0x10000;
	des[0]=(char16_t)((res>>10)+0xD800);
	des[1]=(char16_t)((res&0x3FF)+0xDC00);
	return 2;
}

// Copy from str/str.c
_SHINSEI_OS_INLINE static int uTF8CharToUTF32Char(char32_t*const restrict des,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(src[0]<0x80){
		*des=(char32_t)src[0];
		return 1;
	}
	if((src[0]&0xE0)==0xC0&&src_len>=2){
		*des=(((char32_t)(src[0]&0x1F)<<6)|(src[1]&0x3F));
		return 2;
	}
	if((src[0]&0xF0)==0xE0&&src_len>=3){
		*des=(((char32_t)(src[0]&0x0F)<<12)|((src[1]&0x3F)<<6)|(src[2]&0x3F));
		return 3;
	}
	if((src[0]&0xF8)==0xF0&&src_len>=4){
		*des=(((char32_t)(src[0]&0x07)<<18)|((src[1]&0x3F)<<12)|((src[2]&0x3F)<<6)|(src[3]&0x3F));
		return 4;
	}
	return 0;
}

// Rewrite from str/str.c
_SHINSEI_OS_INLINE static size_t uTF8ToUTF32(char32_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	register size_t si=0;
	register size_t di=0;
	while(si<src_len){
		char32_t cp;
		register const size_t r=(size_t)uTF8CharToUTF32Char(&cp,src+si,src_len-si);
		if(__builtin_expect(!r,0)) return 0;
		si+=r;
		if(di+1>des_buf_len) return di+1;
		des_buf[di++]=cp;
	}
	if(di<des_buf_len) des_buf[di]=0;
	return di;
}

// Rewrite from str/str.c
_SHINSEI_OS_INLINE static size_t uTF8ToUTF16(char16_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	register size_t si=0;
	register size_t di=0;
	while(si<src_len){
		char32_t cp;
		register const size_t r=(size_t)uTF8CharToUTF32Char(&cp,src+si,src_len-si);
		if(__builtin_expect(!r,0)) return 0;
		si+=r;
		char16_t tmp[2];
		register const size_t w=(size_t)uTF32CharToUTF16Char(tmp,cp);
		if(di+w>des_buf_len) return di+w;
		for(register size_t i=0;i<w;++i) des_buf[di++]=tmp[i];
	}
	if(di<des_buf_len) des_buf[di]=0;
	return di;
}

_SHINSEI_OS_INLINE static size_t getUserDataPathU8(char8_t*const restrict des_buf,const size_t des_buf_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(des_buf_len<2,0)) return 0;
	register const char* path=getenv("XDG_CONFIG_HOME");
	register const size_t len=0;
	if(path&&*path){
		while(path[len]) ++len;
		if(len>=des_buf_len) return 0;
		for(register const size_t i=0;i<len;++i) des_buf[i]=(char8_t)path[i];
		des_buf[len]=u8'\0';
		return len;
	}
	path=getenv("HOME");
	if(path&&*path){
		while(path[len]) ++len;
		register const char* suffix="/.config";
		register const size_t slen=8;
		if(len+slen>=des_buf_len) return 0;
		for(register const size_t i=0;i<len;++i) des_buf[i]=(char8_t)path[i];
		for(register const size_t i=0;i<slen;++i) des_buf[len+i]=(char8_t)suffix[i];
		len+=slen;
		des_buf[len]=u8'\0';
		return len;
	}
	return 0;
}

size_t shinsei_getUserDataPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,char8_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// convert_buf_len: Size of the convert string + 1 for terminator 0.
	(void)convert_buf;
	(void)convert_buf_len;
	return getUserDataPathU8(des_buf,des_buf_len);
}

size_t shinsei_getUserDataPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,char8_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// convert_buf_len: Size of the convert string + 1 for terminator 0.
	if(__builtin_expect(des_buf_len<2,0)) return 0;
	register const size_t u8len=getUserDataPathU8(convert_buf,convert_buf_len);
	if(!u8len) return 0;
	register const size_t res=uTF8ToUTF16(des_buf,des_buf_len,convert_buf,u8len);
	if(res>des_buf_len||!res) return 0;
	return res;
}

size_t shinsei_getUserDataPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,char8_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// convert_buf_len: Size of the convert string + 1 for terminator 0.
	if(__builtin_expect(des_buf_len<2,0)) return 0;
	register const size_t u8len=getUserDataPathU8(convert_buf,convert_buf_len);
	if(!u8len) return 0;
	register const size_t res=uTF8ToUTF32(des_buf,des_buf_len,convert_buf,u8len);
	if(res>des_buf_len||!res) return 0;
	return res;
}

size_t shinsei_getUserDataPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,char8_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// convert_buf_len: Size of the convert string + 1 for terminator 0.
	#ifdef _SHINSEI_WCHAR_U32
		return shinsei_getUserDataPathU32((char32_t*)des_buf,des_buf_len,convert_buf,convert_buf_len);
	#else
		return shinsei_getUserDataPathU16((char16_t*)des_buf,des_buf_len,convert_buf,convert_buf_len);
	#endif
}

size_t shinsei_getUserDataPathN(char8_t*const restrict des_buf,const size_t des_buf_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	return getUserDataPathU8(des_buf,des_buf_len);
}

_SHINSEI_OS_INLINE static size_t getSystemApplicationPathU8(char8_t*const restrict des_buf,const size_t des_buf_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(des_buf_len<5,0)) return 0;
	des_buf[0]=u8'/';
	des_buf[1]=u8'o';
	des_buf[2]=u8'p';
	des_buf[3]=u8't';
	des_buf[4]=u8'\0';
	return 4;
}

size_t shinsei_getSystemApplicationPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,char8_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// convert_buf_len: Size of the convert string + 1 for terminator 0.
	(void)convert_buf;
	(void)convert_buf_len;
	return getSystemApplicationPathU8(des_buf,des_buf_len);
}

size_t shinsei_getSystemApplicationPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,char8_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// convert_buf_len: Size of the convert string + 1 for terminator 0.
	if(__builtin_expect(des_buf_len<5,0)) return 0;
	register const size_t u8len=getSystemApplicationPathU8(convert_buf,convert_buf_len);
	if(!u8len) return 0;
	register const size_t res=uTF8ToUTF16(des_buf,des_buf_len,convert_buf,u8len);
	if(res>des_buf_len||!res) return 0;
	return res;
}

size_t shinsei_getSystemApplicationPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,char8_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// convert_buf_len: Size of the convert string + 1 for terminator 0.
	if(__builtin_expect(des_buf_len<5,0)) return 0;
	register const size_t u8len=getSystemApplicationPathU8(convert_buf,convert_buf_len);
	if(!u8len) return 0;
	register const size_t res=uTF8ToUTF32(des_buf,des_buf_len,convert_buf,u8len);
	if(res>des_buf_len||!res) return 0;
	return res;
}

size_t shinsei_getSystemApplicationPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,char8_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// convert_buf_len: Size of the convert string + 1 for terminator 0.
	#ifdef _SHINSEI_WCHAR_U32
		return shinsei_getSystemApplicationPathU32((char32_t*)des_buf,des_buf_len,convert_buf,convert_buf_len);
	#else
		return shinsei_getSystemApplicationPathU16((char16_t*)des_buf,des_buf_len,convert_buf,convert_buf_len);
	#endif
}

size_t shinsei_getSystemApplicationPathN(char8_t*const restrict des_buf,const size_t des_buf_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	return getSystemApplicationPathU8(des_buf,des_buf_len);
}

// Windows
size_t shinsei_windowsPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_windowsPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_windowsPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_windowsPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_windowsPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_windowsPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_windowsPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_windowsPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// Unix
size_t shinsei_unixPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_unixPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_unixPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_unixPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// Linux
size_t shinsei_linuxPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_linuxPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_linuxPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_linuxPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// Apple
size_t shinsei_applePathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_applePathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_applePathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_applePathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// Sun
size_t shinsei_sunPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_sunPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_sunPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_sunPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// FreeBSD
size_t shinsei_freeBSDPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_freeBSDPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_freeBSDPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_freeBSDPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// Cygwin
size_t shinsei_cygwinPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_cygwinPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_cygwinPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_cygwinPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// uRL
size_t shinsei_uRLPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_uRLPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_uRLPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_uRLPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
2. path/path-unix.c (Standard Layer)
C
#include "shinsei/path.h"
#include <stdarg.h>

// Windows
size_t shinsei_windowsPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_windowsPathJoinU8V((char8_t*)des_buf,des_buf_len,path_cnt,(const char8_t*)first_part,first_part_len,args);
}
size_t shinsei_windowsPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_windowsPathJoinU8V((char8_t*)des_buf,des_buf_len,path_cnt,(const char8_t*)first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_windowsPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_windowsPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_windowsPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_windowsPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// Unix
size_t shinsei_unixPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinU8V((char8_t*)des_buf,des_buf_len,path_cnt,(const char8_t*)first_part,first_part_len,args);
}
size_t shinsei_unixPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinU8V((char8_t*)des_buf,des_buf_len,path_cnt,(const char8_t*)first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_unixPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_unixPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// Linux
size_t shinsei_linuxPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinU8V((char8_t*)des_buf,des_buf_len,path_cnt,(const char8_t*)first_part,first_part_len,args);
}
size_t shinsei_linuxPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinU8V((char8_t*)des_buf,des_buf_len,path_cnt,(const char8_t*)first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_linuxPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_linuxPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// Apple
size_t shinsei_applePathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinU8V((char8_t*)des_buf,des_buf_len,path_cnt,(const char8_t*)first_part,first_part_len,args);
}
size_t shinsei_applePathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinU8V((char8_t*)des_buf,des_buf_len,path_cnt,(const char8_t*)first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_applePathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_applePathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// Sun
size_t shinsei_sunPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinU8V((char8_t*)des_buf,des_buf_len,path_cnt,(const char8_t*)first_part,first_part_len,args);
}
size_t shinsei_sunPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinU8V((char8_t*)des_buf,des_buf_len,path_cnt,(const char8_t*)first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_sunPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_sunPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// FreeBSD
size_t shinsei_freeBSDPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinU8V((char8_t*)des_buf,des_buf_len,path_cnt,(const char8_t*)first_part,first_part_len,args);
}
size_t shinsei_freeBSDPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinU8V((char8_t*)des_buf,des_buf_len,path_cnt,(const char8_t*)first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_freeBSDPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_freeBSDPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// Cygwin
size_t shinsei_cygwinPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinU8V((char8_t*)des_buf,des_buf_len,path_cnt,(const char8_t*)first_part,first_part_len,args);
}
size_t shinsei_cygwinPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinU8V((char8_t*)des_buf,des_buf_len,path_cnt,(const char8_t*)first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_cygwinPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_cygwinPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// URL
size_t shinsei_uRLPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinU8V((char8_t*)des_buf,des_buf_len,path_cnt,(const char8_t*)first_part,first_part_len,args);
}
size_t shinsei_uRLPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinU8V((char8_t*)des_buf,des_buf_len,path_cnt,(const char8_t*)first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_uRLPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_uRLPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

size_t shinsei_splitStringToWindowsPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToWindowsPathU8((char8_t*)des_buf,des_buf_len,(const char8_t*)src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToWindowsPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToWindowsPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}

size_t shinsei_splitStringToUnixPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToUnixPathU8((char8_t*)des_buf,des_buf_len,(const char8_t*)src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToUnixPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToUnixPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}

size_t shinsei_splitStringToLinuxPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToLinuxPathU8((char8_t*)des_buf,des_buf_len,(const char8_t*)src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToLinuxPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToLinuxPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}

size_t shinsei_splitStringToApplePathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToApplePathU8((char8_t*)des_buf,des_buf_len,(const char8_t*)src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToApplePathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToApplePathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}

size_t shinsei_splitStringToSunPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToSunPathU8((char8_t*)des_buf,des_buf_len,(const char8_t*)src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToSunPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToSunPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}

size_t shinsei_splitStringToFreeBSDPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToFreeBSDPathU8((char8_t*)des_buf,des_buf_len,(const char8_t*)src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToFreeBSDPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToFreeBSDPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}

size_t shinsei_splitStringToCygwinPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToCygwinPathU8((char8_t*)des_buf,des_buf_len,(const char8_t*)src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToCygwinPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToCygwinPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}

size_t shinsei_splitStringToURLPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToURLPathU8((char8_t*)des_buf,des_buf_len,(const char8_t*)src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToURLPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToURLPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}

size_t shinsei_splitStringToNativePathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	#if defined(_SHINSEI_OS_APPLE)
		return shinsei_splitStringToApplePathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_LINUX)
		return shinsei_splitStringToLinuxPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return shinsei_splitStringToFreeBSDPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_SUN)
		return shinsei_splitStringToSunPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return shinsei_splitStringToCygwinPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#else
		return shinsei_splitStringToUnixPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#endif
}
size_t shinsei_splitStringToNativePathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	#if defined(_SHINSEI_OS_APPLE)
		return shinsei_splitStringToApplePathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_LINUX)
		return shinsei_splitStringToLinuxPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return shinsei_splitStringToFreeBSDPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_SUN)
		return shinsei_splitStringToSunPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return shinsei_splitStringToCygwinPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#else
		return shinsei_splitStringToUnixPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#endif
}
size_t shinsei_splitStringToNativePathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	#if defined(_SHINSEI_OS_APPLE)
		return shinsei_splitStringToApplePathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_LINUX)
		return shinsei_splitStringToLinuxPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return shinsei_splitStringToFreeBSDPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_SUN)
		return shinsei_splitStringToSunPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return shinsei_splitStringToCygwinPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#else
		return shinsei_splitStringToUnixPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#endif
}
size_t shinsei_splitStringToNativePathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	#if defined(_SHINSEI_OS_APPLE)
		return shinsei_splitStringToApplePathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_LINUX)
		return shinsei_splitStringToLinuxPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return shinsei_splitStringToFreeBSDPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_SUN)
		return shinsei_splitStringToSunPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return shinsei_splitStringToCygwinPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#else
		return shinsei_splitStringToUnixPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#endif
}
size_t shinsei_splitStringToNativePathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	#if defined(_SHINSEI_OS_APPLE)
		return shinsei_splitStringToApplePathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_LINUX)
		return shinsei_splitStringToLinuxPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return shinsei_splitStringToFreeBSDPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_SUN)
		return shinsei_splitStringToSunPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return shinsei_splitStringToCygwinPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#else
		return shinsei_splitStringToUnixPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#endif
}
size_t shinsei_splitStringToNativePathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	#if defined(_SHINSEI_OS_APPLE)
		return shinsei_splitStringToApplePathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_LINUX)
		return shinsei_splitStringToLinuxPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return shinsei_splitStringToFreeBSDPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_SUN)
		return shinsei_splitStringToSunPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return shinsei_splitStringToCygwinPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#else
		return shinsei_splitStringToUnixPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#endif
}
size_t shinsei_splitStringToNativePathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	#if defined(_SHINSEI_OS_APPLE)
		return shinsei_splitStringToApplePathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_LINUX)
		return shinsei_splitStringToLinuxPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_FREEBSD)
		return shinsei_splitStringToFreeBSDPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_SUN)
		return shinsei_splitStringToSunPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#elif defined(_SHINSEI_OS_CYGWIN)
		return shinsei_splitStringToCygwinPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#else
		return shinsei_splitStringToUnixPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	#endif
}
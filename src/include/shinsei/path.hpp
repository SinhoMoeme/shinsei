#pragma once

#include"shinsei/minimal/path.hpp"
#include"shinsei/path.h"

namespace shinsei{
	#if defined(_SHINSEI_OS_WINDOWS)
	static _SHINSEI_OS_CONSTEXPR wchar_t PATH_WINDOWS_DELIMITER_N=::SHINSEI_PATH_WINDOWS_DELIMITER_N;
	#elif defined(_SHINSEI_OS_UNIX)
	static _SHINSEI_OS_CONSTEXPR char8_t PATH_WINDOWS_DELIMITER_N=::SHINSEI_PATH_WINDOWS_DELIMITER_N;
	#endif
	
	#if defined(_SHINSEI_OS_WINDOWS)
	static _SHINSEI_OS_CONSTEXPR wchar_t PATH_UNIX_DELIMITER_N=::SHINSEI_PATH_UNIX_DELIMITER_N;
	#elif defined(_SHINSEI_OS_UNIX)
	static _SHINSEI_OS_CONSTEXPR char8_t PATH_UNIX_DELIMITER_N=::SHINSEI_PATH_UNIX_DELIMITER_N;
	#endif
	
	static _SHINSEI_OS_CONSTEXPR char32_t PATH_LINUX_DELIMITER_N=::SHINSEI_PATH_LINUX_DELIMITER_N;
	
	static _SHINSEI_OS_CONSTEXPR char32_t PATH_APPLE_DELIMITER_N=::SHINSEI_PATH_APPLE_DELIMITER_N;
	
	static _SHINSEI_OS_CONSTEXPR char32_t PATH_SUN_DELIMITER_N=::SHINSEI_PATH_SUN_DELIMITER_N;
	
	static _SHINSEI_OS_CONSTEXPR char32_t PATH_FREEBSD_DELIMITER_N=::SHINSEI_PATH_FREEBSD_DELIMITER_N;
	
	static _SHINSEI_OS_CONSTEXPR char32_t PATH_CYGWIN_DELIMITER_N=::SHINSEI_PATH_CYGWIN_DELIMITER_N;
	
	#if defined(_SHINSEI_OS_WINDOWS)
	static _SHINSEI_OS_CONSTEXPR wchar_t PATH_URL_DELIMITER_N=::SHINSEI_PATH_URL_DELIMITER_N;
	#elif defined(_SHINSEI_OS_UNIX)
	static _SHINSEI_OS_CONSTEXPR char8_t PATH_URL_DELIMITER_N=::SHINSEI_PATH_URL_DELIMITER_N;
	#endif
	
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiter(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiter(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiter(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isApplePathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiter(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiterM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isSunPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiter(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiterM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiter(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiter(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isNativePathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiter(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiterM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiter(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiterM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiter(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiterCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiterM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiter(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiterM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiter(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiterM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiter(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathDelimiterM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathDelimiterU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isURLPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiter(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterA(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiterM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalChar(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalChar(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalChar(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalChar(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalChar(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalChar(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalChar(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalChar(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalChar(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalChar(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalChar(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalChar(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalChar(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isNativePathIllegalCharM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isNativePathIllegalCharU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalChar(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharA(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE int windowsPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeA(path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalize(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeA(path,len);
	}
	
	_SHINSEI_OS_INLINE int unixPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeA(path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalize(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeA(path,len);
	}
	
	_SHINSEI_OS_INLINE int linuxPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeA(path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalize(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeA(path,len);
	}
	
	_SHINSEI_OS_INLINE int applePathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeA(path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalize(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeA(path,len);
	}
	
	_SHINSEI_OS_INLINE int sunPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeA(path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalize(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeA(path,len);
	}
	
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeA(path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalize(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeA(path,len);
	}
	
	_SHINSEI_OS_INLINE int cygwinPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeA(path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalize(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeA(path,len);
	}
	
	_SHINSEI_OS_INLINE int uRLPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeA(path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalize(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeA(path,len);
	}
	
	_SHINSEI_OS_INLINE int nativePathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeA(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalize(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeA(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalize(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalize(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalize(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalize(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeU32(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalize(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeU32(path,len);
	}
	
	_SHINSEI_OS_INLINE int windowsPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeNoTraversalA(path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalizeNoTraversal(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeNoTraversalA(path,len);
	}
	
	_SHINSEI_OS_INLINE int unixPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeNoTraversalA(path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalizeNoTraversal(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeNoTraversalA(path,len);
	}
	
	_SHINSEI_OS_INLINE int linuxPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeNoTraversalA(path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalizeNoTraversal(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeNoTraversalA(path,len);
	}
	
	_SHINSEI_OS_INLINE int applePathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeNoTraversalA(path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalizeNoTraversal(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeNoTraversalA(path,len);
	}
	
	_SHINSEI_OS_INLINE int sunPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeNoTraversalA(path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalizeNoTraversal(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeNoTraversalA(path,len);
	}
	
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeNoTraversalA(path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeNoTraversal(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeNoTraversalA(path,len);
	}
	
	_SHINSEI_OS_INLINE int cygwinPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeNoTraversalA(path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalizeNoTraversal(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeNoTraversalA(path,len);
	}
	
	_SHINSEI_OS_INLINE int nativePathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeNoTraversalA(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalizeNoTraversal(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeNoTraversalA(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalizeNoTraversal(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalizeNoTraversal(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalizeNoTraversal(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalizeNoTraversal(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeNoTraversalU32(path,len);
	}
	_SHINSEI_OS_INLINE int nativePathNormalizeNoTraversal(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_nativePathNormalizeNoTraversalU32(path,len);
	}
	
	_SHINSEI_OS_INLINE int uRLPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeNoTraversalA(path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalizeNoTraversal(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeNoTraversalA(path,len);
	}
	
	_SHINSEI_OS_INLINE size_t getUserDataPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getUserDataPathW(des_buf,des_buf_len,convert_buf,convert_buf_len);
	}
	_SHINSEI_OS_INLINE size_t getUserDataPath(wchar_t*const restrict des_buf,const size_t des_buf_len,nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getUserDataPathW(des_buf,des_buf_len,convert_buf,convert_buf_len);
	}
	_SHINSEI_OS_INLINE size_t getUserDataPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getUserDataPathU8(des_buf,des_buf_len,convert_buf,convert_buf_len);
	}
	_SHINSEI_OS_INLINE size_t getUserDataPath(char8_t*const restrict des_buf,const size_t des_buf_len,nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getUserDataPathU8(des_buf,des_buf_len,convert_buf,convert_buf_len);
	}
	_SHINSEI_OS_INLINE size_t getUserDataPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getUserDataPathU16(des_buf,des_buf_len,convert_buf,convert_buf_len);
	}
	_SHINSEI_OS_INLINE size_t getUserDataPath(char16_t*const restrict des_buf,const size_t des_buf_len,nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getUserDataPathU16(des_buf,des_buf_len,convert_buf,convert_buf_len);
	}
	_SHINSEI_OS_INLINE size_t getUserDataPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getUserDataPathU32(des_buf,des_buf_len,convert_buf,convert_buf_len);
	}
	_SHINSEI_OS_INLINE size_t getUserDataPath(char32_t*const restrict des_buf,const size_t des_buf_len,nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getUserDataPathU32(des_buf,des_buf_len,convert_buf,convert_buf_len);
	}
	
	_SHINSEI_OS_INLINE size_t getSystemApplicationPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getSystemApplicationPathW(des_buf,des_buf_len,convert_buf,convert_buf_len);
	}
	_SHINSEI_OS_INLINE size_t getSystemApplicationPath(wchar_t*const restrict des_buf,const size_t des_buf_len,nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getSystemApplicationPathW(des_buf,des_buf_len,convert_buf,convert_buf_len);
	}
	_SHINSEI_OS_INLINE size_t getSystemApplicationPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getSystemApplicationPathU8(des_buf,des_buf_len,convert_buf,convert_buf_len);
	}
	_SHINSEI_OS_INLINE size_t getSystemApplicationPath(char8_t*const restrict des_buf,const size_t des_buf_len,nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getSystemApplicationPathU8(des_buf,des_buf_len,convert_buf,convert_buf_len);
	}
	_SHINSEI_OS_INLINE size_t getSystemApplicationPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getSystemApplicationPathU16(des_buf,des_buf_len,convert_buf,convert_buf_len);
	}
	_SHINSEI_OS_INLINE size_t getSystemApplicationPath(char16_t*const restrict des_buf,const size_t des_buf_len,nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getSystemApplicationPathU16(des_buf,des_buf_len,convert_buf,convert_buf_len);
	}
	_SHINSEI_OS_INLINE size_t getSystemApplicationPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getSystemApplicationPathU32(des_buf,des_buf_len,convert_buf,convert_buf_len);
	}
	_SHINSEI_OS_INLINE size_t getSystemApplicationPath(char32_t*const restrict des_buf,const size_t des_buf_len,nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getSystemApplicationPathU32(des_buf,des_buf_len,convert_buf,convert_buf_len);
	}
	
	// Windows
	_SHINSEI_OS_INLINE size_t windowsPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoinV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_windowsPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoin(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_windowsPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	
	// Unix
	_SHINSEI_OS_INLINE size_t unixPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t unixPathJoinV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t unixPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_unixPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	_SHINSEI_OS_INLINE size_t unixPathJoin(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_unixPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	
	// Linux
	_SHINSEI_OS_INLINE size_t linuxPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t linuxPathJoinV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t linuxPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_linuxPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	_SHINSEI_OS_INLINE size_t linuxPathJoin(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_linuxPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	
	// Apple
	_SHINSEI_OS_INLINE size_t applePathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t applePathJoinV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t applePathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_applePathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	_SHINSEI_OS_INLINE size_t applePathJoin(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_applePathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	
	// Sun
	_SHINSEI_OS_INLINE size_t sunPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t sunPathJoinV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t sunPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_sunPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	_SHINSEI_OS_INLINE size_t sunPathJoin(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_sunPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	
	// FreeBSD
	_SHINSEI_OS_INLINE size_t freeBSDPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t freeBSDPathJoinV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t freeBSDPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_freeBSDPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	_SHINSEI_OS_INLINE size_t freeBSDPathJoin(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_freeBSDPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	
	// Cygwin
	_SHINSEI_OS_INLINE size_t cygwinPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t cygwinPathJoinV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t cygwinPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_cygwinPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	_SHINSEI_OS_INLINE size_t cygwinPathJoin(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_cygwinPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	
	// URL
	_SHINSEI_OS_INLINE size_t uRLPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t uRLPathJoinV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t uRLPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_uRLPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	_SHINSEI_OS_INLINE size_t uRLPathJoin(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_uRLPathJoinAV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	
	_SHINSEI_OS_INLINE size_t splitStringToWindowsPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToWindowsPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToWindowsPath(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToWindowsPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	
	_SHINSEI_OS_INLINE size_t splitStringToUnixPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToUnixPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToUnixPath(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToUnixPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	
	_SHINSEI_OS_INLINE size_t splitStringToLinuxPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToLinuxPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToLinuxPath(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToLinuxPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	
	_SHINSEI_OS_INLINE size_t splitStringToApplePathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToApplePathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToApplePath(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToApplePathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	
	_SHINSEI_OS_INLINE size_t splitStringToSunPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToSunPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToSunPath(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToSunPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	
	_SHINSEI_OS_INLINE size_t splitStringToFreeBSDPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToFreeBSDPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToFreeBSDPath(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToFreeBSDPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	
	_SHINSEI_OS_INLINE size_t splitStringToCygwinPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToCygwinPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToCygwinPath(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToCygwinPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	
	_SHINSEI_OS_INLINE size_t splitStringToURLPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToURLPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToURLPath(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToURLPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	
	_SHINSEI_OS_INLINE size_t splitStringToNativePathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToNativePathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToNativePath(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToNativePathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToNativePathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToNativePathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToNativePath(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToNativePathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToNativePathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToNativePathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToNativePath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToNativePathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToNativePathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToNativePathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToNativePath(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToNativePathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToNativePathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToNativePathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToNativePath(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToNativePathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToNativePathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToNativePathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToNativePath(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToNativePathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	
	// OS Specific API Wrappers
	#ifdef _SHINSEI_OS_WINDOWS
		_SHINSEI_OS_INLINE bool isWindowsPathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isWindowsPathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isWindowsPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isWindowsPathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isUnixPathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isUnixPathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isUnixPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isUnixPathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isLinuxPathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isLinuxPathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isLinuxPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isLinuxPathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isApplePathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isApplePathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isApplePathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isApplePathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isSunPathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isSunPathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isSunPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isSunPathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isFreeBSDPathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isFreeBSDPathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isCygwinPathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isCygwinPathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isCygwinPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isCygwinPathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isURLPathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isURLPathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isURLPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isURLPathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isNativePathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isNativePathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isNativePathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isNativePathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isWindowsPathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isWindowsPathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isUnixPathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isUnixPathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isUnixPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isUnixPathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isLinuxPathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isLinuxPathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isApplePathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isApplePathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isApplePathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isApplePathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isSunPathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isSunPathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isSunPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isSunPathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isFreeBSDPathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isFreeBSDPathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isCygwinPathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isCygwinPathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isURLPathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isURLPathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isURLPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isURLPathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isNativePathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isNativePathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isNativePathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isNativePathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE int windowsPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_windowsPathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int unixPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_unixPathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int linuxPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_linuxPathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int applePathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_applePathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int sunPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_sunPathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int freeBSDPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_freeBSDPathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int cygwinPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_cygwinPathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int uRLPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uRLPathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int nativePathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_nativePathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int windowsPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_windowsPathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE int unixPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_unixPathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE int linuxPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_linuxPathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE int applePathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_applePathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE int sunPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_sunPathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE int freeBSDPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_freeBSDPathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE int cygwinPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_cygwinPathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE int nativePathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_nativePathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE int uRLPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uRLPathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE size_t getUserDataPathN(wchar_t*const restrict des_buf,const size_t des_buf_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getUserDataPathN(des_buf,des_buf_len);
		}
		_SHINSEI_OS_INLINE size_t getUserDataPath(wchar_t*const restrict des_buf,const size_t des_buf_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getUserDataPathN(des_buf,des_buf_len);
		}
		
		_SHINSEI_OS_INLINE size_t getSystemApplicationPathN(wchar_t*const restrict des_buf,const size_t des_buf_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getSystemApplicationPathN(des_buf,des_buf_len);
		}
		_SHINSEI_OS_INLINE size_t getSystemApplicationPath(wchar_t*const restrict des_buf,const size_t des_buf_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getSystemApplicationPathN(des_buf,des_buf_len);
		}
		
		_SHINSEI_OS_INLINE size_t windowsPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_windowsPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		}
		_SHINSEI_OS_INLINE size_t windowsPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
			va_list args;
			va_start(args,first_part_len);
			const size_t res=::shinsei_windowsPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
			va_end(args);
			return res;
		}
		
		_SHINSEI_OS_INLINE size_t unixPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_unixPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		}
		_SHINSEI_OS_INLINE size_t unixPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
			va_list args;
			va_start(args,first_part_len);
			const size_t res=::shinsei_unixPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
			va_end(args);
			return res;
		}
		
		_SHINSEI_OS_INLINE size_t linuxPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_linuxPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		}
		_SHINSEI_OS_INLINE size_t linuxPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
			va_list args;
			va_start(args,first_part_len);
			const size_t res=::shinsei_linuxPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
			va_end(args);
			return res;
		}
		
		_SHINSEI_OS_INLINE size_t applePathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_applePathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		}
		_SHINSEI_OS_INLINE size_t applePathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
			va_list args;
			va_start(args,first_part_len);
			const size_t res=::shinsei_applePathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
			va_end(args);
			return res;
		}
		
		_SHINSEI_OS_INLINE size_t sunPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_sunPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		}
		_SHINSEI_OS_INLINE size_t sunPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
			va_list args;
			va_start(args,first_part_len);
			const size_t res=::shinsei_sunPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
			va_end(args);
			return res;
		}
		
		_SHINSEI_OS_INLINE size_t freeBSDPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_freeBSDPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		}
		_SHINSEI_OS_INLINE size_t freeBSDPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
			va_list args;
			va_start(args,first_part_len);
			const size_t res=::shinsei_freeBSDPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
			va_end(args);
			return res;
		}
		
		_SHINSEI_OS_INLINE size_t cygwinPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_cygwinPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		}
		_SHINSEI_OS_INLINE size_t cygwinPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
			va_list args;
			va_start(args,first_part_len);
			const size_t res=::shinsei_cygwinPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
			va_end(args);
			return res;
		}
		
		_SHINSEI_OS_INLINE size_t uRLPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uRLPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		}
		_SHINSEI_OS_INLINE size_t uRLPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
			va_list args;
			va_start(args,first_part_len);
			const size_t res=::shinsei_uRLPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
			va_end(args);
			return res;
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToWindowsPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToWindowsPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToUnixPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToUnixPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToLinuxPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToLinuxPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToApplePathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToApplePathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToSunPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToSunPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToFreeBSDPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToFreeBSDPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToCygwinPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToCygwinPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToURLPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToURLPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToNativePathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToNativePathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
	#elif defined(_SHINSEI_OS_UNIX)
		_SHINSEI_OS_INLINE bool isWindowsPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isWindowsPathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isWindowsPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isWindowsPathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isUnixPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isUnixPathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isUnixPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isUnixPathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isLinuxPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isLinuxPathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isLinuxPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isLinuxPathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isApplePathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isApplePathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isApplePathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isApplePathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isSunPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isSunPathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isSunPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isSunPathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isFreeBSDPathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isFreeBSDPathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isCygwinPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isCygwinPathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isCygwinPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isCygwinPathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isNativePathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isNativePathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isNativePathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isNativePathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isURLPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isURLPathDelimiterN(ch);
		}
		_SHINSEI_OS_INLINE bool isURLPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isURLPathDelimiterNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isWindowsPathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isWindowsPathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isUnixPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isUnixPathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isUnixPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isUnixPathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isLinuxPathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isLinuxPathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isApplePathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isApplePathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isApplePathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isApplePathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isSunPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isSunPathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isSunPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isSunPathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isFreeBSDPathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isFreeBSDPathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isCygwinPathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isCygwinPathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isNativePathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isNativePathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isNativePathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isNativePathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isURLPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isURLPathIllegalCharN(ch);
		}
		_SHINSEI_OS_INLINE bool isURLPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isURLPathIllegalCharNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE int windowsPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_windowsPathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int unixPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_unixPathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int linuxPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_linuxPathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int applePathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_applePathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int sunPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_sunPathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int freeBSDPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_freeBSDPathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int cygwinPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_cygwinPathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int uRLPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uRLPathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int nativePathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_nativePathNormalizeN(path,len);
		}
		_SHINSEI_OS_INLINE int nativePathNormalize(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_nativePathNormalizeN(path,len);
		}
		
		_SHINSEI_OS_INLINE int windowsPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_windowsPathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE int unixPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_unixPathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE int linuxPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_linuxPathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE int applePathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_applePathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE int sunPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_sunPathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE int freeBSDPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_freeBSDPathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE int cygwinPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_cygwinPathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE int nativePathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_nativePathNormalizeNoTraversalN(path,len);
		}
		_SHINSEI_OS_INLINE int nativePathNormalizeNoTraversal(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_nativePathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE int uRLPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uRLPathNormalizeNoTraversalN(path,len);
		}
		
		_SHINSEI_OS_INLINE size_t getUserDataPathN(char8_t*const restrict des_buf,const size_t des_buf_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getUserDataPathN(des_buf,des_buf_len);
		}
		_SHINSEI_OS_INLINE size_t getUserDataPath(char8_t*const restrict des_buf,const size_t des_buf_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getUserDataPathN(des_buf,des_buf_len);
		}
		
		_SHINSEI_OS_INLINE size_t getSystemApplicationPathN(char8_t*const restrict des_buf,const size_t des_buf_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getSystemApplicationPathN(des_buf,des_buf_len);
		}
		_SHINSEI_OS_INLINE size_t getSystemApplicationPath(char8_t*const restrict des_buf,const size_t des_buf_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getSystemApplicationPathN(des_buf,des_buf_len);
		}
		
		_SHINSEI_OS_INLINE size_t windowsPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_windowsPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		}
		_SHINSEI_OS_INLINE size_t windowsPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
			va_list args;
			va_start(args,first_part_len);
			const size_t res=::shinsei_windowsPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
			va_end(args);
			return res;
		}
		
		_SHINSEI_OS_INLINE size_t unixPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_unixPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		}
		_SHINSEI_OS_INLINE size_t unixPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
			va_list args;
			va_start(args,first_part_len);
			const size_t res=::shinsei_unixPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
			va_end(args);
			return res;
		}
		
		_SHINSEI_OS_INLINE size_t linuxPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_linuxPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		}
		_SHINSEI_OS_INLINE size_t linuxPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
			va_list args;
			va_start(args,first_part_len);
			const size_t res=::shinsei_linuxPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
			va_end(args);
			return res;
		}
		
		_SHINSEI_OS_INLINE size_t applePathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_applePathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		}
		_SHINSEI_OS_INLINE size_t applePathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
			va_list args;
			va_start(args,first_part_len);
			const size_t res=::shinsei_applePathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
			va_end(args);
			return res;
		}
		
		_SHINSEI_OS_INLINE size_t sunPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_sunPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		}
		_SHINSEI_OS_INLINE size_t sunPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
			va_list args;
			va_start(args,first_part_len);
			const size_t res=::shinsei_sunPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
			va_end(args);
			return res;
		}
		
		_SHINSEI_OS_INLINE size_t freeBSDPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_freeBSDPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		}
		_SHINSEI_OS_INLINE size_t freeBSDPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
			va_list args;
			va_start(args,first_part_len);
			const size_t res=::shinsei_freeBSDPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
			va_end(args);
			return res;
		}
		
		_SHINSEI_OS_INLINE size_t cygwinPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_cygwinPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		}
		_SHINSEI_OS_INLINE size_t cygwinPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
			va_list args;
			va_start(args,first_part_len);
			const size_t res=::shinsei_cygwinPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
			va_end(args);
			return res;
		}
		
		_SHINSEI_OS_INLINE size_t uRLPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uRLPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		}
		_SHINSEI_OS_INLINE size_t uRLPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
			va_list args;
			va_start(args,first_part_len);
			const size_t res=::shinsei_uRLPathJoinNV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
			va_end(args);
			return res;
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToWindowsPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToWindowsPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		_SHINSEI_OS_INLINE size_t splitStringToWindowsPath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToWindowsPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToUnixPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToUnixPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		_SHINSEI_OS_INLINE size_t splitStringToUnixPath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToUnixPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToLinuxPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToLinuxPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		_SHINSEI_OS_INLINE size_t splitStringToLinuxPath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToLinuxPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToApplePathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToApplePathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		_SHINSEI_OS_INLINE size_t splitStringToApplePath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToApplePathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToSunPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToSunPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		_SHINSEI_OS_INLINE size_t splitStringToSunPath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToSunPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToFreeBSDPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToFreeBSDPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		_SHINSEI_OS_INLINE size_t splitStringToFreeBSDPath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToFreeBSDPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToCygwinPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToCygwinPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		_SHINSEI_OS_INLINE size_t splitStringToCygwinPath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToCygwinPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToURLPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToURLPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		_SHINSEI_OS_INLINE size_t splitStringToURLPath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToURLPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToNativePathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToNativePathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		_SHINSEI_OS_INLINE size_t splitStringToNativePath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToNativePathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
		}
		
	#endif
}
#pragma once

#include"shinsei/minimal/path.h"

namespace shinsei{
	static _SHINSEI_OS_CONSTEXPR int PATH_ILLEGAL=::SHINSEI_PATH_ILLEGAL;
	static _SHINSEI_OS_CONSTEXPR int PATH_ABSOLUTE=::SHINSEI_PATH_ABSOLUTE;
	static _SHINSEI_OS_CONSTEXPR int PATH_RELATIVE=::SHINSEI_PATH_RELATIVE;
	static _SHINSEI_OS_CONSTEXPR int PATH_TRAVERSAL=::SHINSEI_PATH_TRAVERSAL;
	static _SHINSEI_OS_CONSTEXPR int PATH_WINDOWS_UNC=::SHINSEI_PATH_WINDOWS_UNC;
	static _SHINSEI_OS_CONSTEXPR int PATH_WINDOWS_DRIVE_RELATIVE=::SHINSEI_PATH_WINDOWS_DRIVE_RELATIVE;
	static _SHINSEI_OS_CONSTEXPR int PATH_WINDOWS_DEVICE=::SHINSEI_PATH_WINDOWS_DEVICE;
	static _SHINSEI_OS_CONSTEXPR int PATH_WINDOWS_DOS_DEVICE=::SHINSEI_PATH_WINDOWS_DOS_DEVICE;
	
	static _SHINSEI_OS_CONSTEXPR size_t PATH_WINDOWS_MAX_LEGACY=::SHINSEI_PATH_WINDOWS_MAX_LEGACY;
	static _SHINSEI_OS_CONSTEXPR size_t PATH_WINDOWS_MAX=::SHINSEI_PATH_WINDOWS_MAX;
	static _SHINSEI_OS_CONSTEXPR size_t PATH_UNIX_MAX=::SHINSEI_PATH_UNIX_MAX;
	static _SHINSEI_OS_CONSTEXPR size_t PATH_LINUX_MAX=::SHINSEI_PATH_LINUX_MAX;
	static _SHINSEI_OS_CONSTEXPR size_t PATH_APPLE_MAX=::SHINSEI_PATH_APPLE_MAX;
	static _SHINSEI_OS_CONSTEXPR size_t PATH_APPLE_MAX_LEGACY=::SHINSEI_PATH_APPLE_MAX_LEGACY;
	static _SHINSEI_OS_CONSTEXPR size_t PATH_SUN_MAX=::SHINSEI_PATH_SUN_MAX;
	static _SHINSEI_OS_CONSTEXPR size_t PATH_FREEBSD_MAX=::SHINSEI_PATH_FREEBSD_MAX;
	static _SHINSEI_OS_CONSTEXPR size_t PATH_CYGWIN_MAX=::SHINSEI_PATH_CYGWIN_MAX;
	
	static _SHINSEI_OS_CONSTEXPR size_t PATH_SBO_CNT=::SHINSEI_PATH_SBO_CNT;
	static _SHINSEI_OS_CONSTEXPR size_t PATH_MINIMAL=::SHINSEI_PATH_MINIMAL;
	
	static _SHINSEI_OS_CONSTEXPR char PATH_WINDOWS_DELIMITER_ASCII=::SHINSEI_PATH_WINDOWS_DELIMITER_ASCII;
	static _SHINSEI_OS_CONSTEXPR char PATH_WINDOWS_DELIMITER_EBCDIC=::SHINSEI_PATH_WINDOWS_DELIMITER_EBCDIC;
	static _SHINSEI_OS_CONSTEXPR wchar_t PATH_WINDOWS_DELIMITER_W=::SHINSEI_PATH_WINDOWS_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t PATH_WINDOWS_DELIMITER_U8=::SHINSEI_PATH_WINDOWS_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t PATH_WINDOWS_DELIMITER_U16=::SHINSEI_PATH_WINDOWS_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t PATH_WINDOWS_DELIMITER_U32=::SHINSEI_PATH_WINDOWS_DELIMITER_U32;
	
	static _SHINSEI_OS_CONSTEXPR char PATH_UNIX_DELIMITER_ASCII=::SHINSEI_PATH_UNIX_DELIMITER_ASCII;
	static _SHINSEI_OS_CONSTEXPR char PATH_UNIX_DELIMITER_EBCDIC=::SHINSEI_PATH_UNIX_DELIMITER_EBCDIC;
	static _SHINSEI_OS_CONSTEXPR wchar_t PATH_UNIX_DELIMITER_W=::SHINSEI_PATH_UNIX_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t PATH_UNIX_DELIMITER_U8=::SHINSEI_PATH_UNIX_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t PATH_UNIX_DELIMITER_U16=::SHINSEI_PATH_UNIX_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t PATH_UNIX_DELIMITER_U32=::SHINSEI_PATH_UNIX_DELIMITER_U32;
	
	static _SHINSEI_OS_CONSTEXPR char PATH_LINUX_DELIMITER_ASCII=::SHINSEI_PATH_LINUX_DELIMITER_ASCII;
	static _SHINSEI_OS_CONSTEXPR char PATH_LINUX_DELIMITER_EBCDIC=::SHINSEI_PATH_LINUX_DELIMITER_EBCDIC;
	static _SHINSEI_OS_CONSTEXPR wchar_t PATH_LINUX_DELIMITER_W=::SHINSEI_PATH_LINUX_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t PATH_LINUX_DELIMITER_U8=::SHINSEI_PATH_LINUX_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t PATH_LINUX_DELIMITER_U16=::SHINSEI_PATH_LINUX_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t PATH_LINUX_DELIMITER_U32=::SHINSEI_PATH_LINUX_DELIMITER_U32;
	
	static _SHINSEI_OS_CONSTEXPR char PATH_APPLE_DELIMITER_ASCII=::SHINSEI_PATH_APPLE_DELIMITER_ASCII;
	static _SHINSEI_OS_CONSTEXPR char PATH_APPLE_DELIMITER_EBCDIC=::SHINSEI_PATH_APPLE_DELIMITER_EBCDIC;
	static _SHINSEI_OS_CONSTEXPR wchar_t PATH_APPLE_DELIMITER_W=::SHINSEI_PATH_APPLE_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t PATH_APPLE_DELIMITER_U8=::SHINSEI_PATH_APPLE_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t PATH_APPLE_DELIMITER_U16=::SHINSEI_PATH_APPLE_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t PATH_APPLE_DELIMITER_U32=::SHINSEI_PATH_APPLE_DELIMITER_U32;
	
	static _SHINSEI_OS_CONSTEXPR char PATH_SUN_DELIMITER_ASCII=::SHINSEI_PATH_SUN_DELIMITER_ASCII;
	static _SHINSEI_OS_CONSTEXPR char PATH_SUN_DELIMITER_EBCDIC=::SHINSEI_PATH_SUN_DELIMITER_EBCDIC;
	static _SHINSEI_OS_CONSTEXPR wchar_t PATH_SUN_DELIMITER_W=::SHINSEI_PATH_SUN_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t PATH_SUN_DELIMITER_U8=::SHINSEI_PATH_SUN_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t PATH_SUN_DELIMITER_U16=::SHINSEI_PATH_SUN_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t PATH_SUN_DELIMITER_U32=::SHINSEI_PATH_SUN_DELIMITER_U32;
	
	static _SHINSEI_OS_CONSTEXPR char PATH_FREEBSD_DELIMITER_ASCII=::SHINSEI_PATH_FREEBSD_DELIMITER_ASCII;
	static _SHINSEI_OS_CONSTEXPR char PATH_FREEBSD_DELIMITER_EBCDIC=::SHINSEI_PATH_FREEBSD_DELIMITER_EBCDIC;
	static _SHINSEI_OS_CONSTEXPR wchar_t PATH_FREEBSD_DELIMITER_W=::SHINSEI_PATH_FREEBSD_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t PATH_FREEBSD_DELIMITER_U8=::SHINSEI_PATH_FREEBSD_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t PATH_FREEBSD_DELIMITER_U16=::SHINSEI_PATH_FREEBSD_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t PATH_FREEBSD_DELIMITER_U32=::SHINSEI_PATH_FREEBSD_DELIMITER_U32;
	
	static _SHINSEI_OS_CONSTEXPR char PATH_CYGWIN_DELIMITER_ASCII=::SHINSEI_PATH_CYGWIN_DELIMITER_ASCII;
	static _SHINSEI_OS_CONSTEXPR char PATH_CYGWIN_DELIMITER_EBCDIC=::SHINSEI_PATH_CYGWIN_DELIMITER_EBCDIC;
	static _SHINSEI_OS_CONSTEXPR wchar_t PATH_CYGWIN_DELIMITER_W=::SHINSEI_PATH_CYGWIN_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t PATH_CYGWIN_DELIMITER_U8=::SHINSEI_PATH_CYGWIN_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t PATH_CYGWIN_DELIMITER_U16=::SHINSEI_PATH_CYGWIN_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t PATH_CYGWIN_DELIMITER_U32=::SHINSEI_PATH_CYGWIN_DELIMITER_U32;
	
	static _SHINSEI_OS_CONSTEXPR char PATH_URL_DELIMITER_ASCII=::SHINSEI_PATH_URL_DELIMITER_ASCII;
	static _SHINSEI_OS_CONSTEXPR char PATH_URL_DELIMITER_EBCDIC=::SHINSEI_PATH_URL_DELIMITER_EBCDIC;
	static _SHINSEI_OS_CONSTEXPR wchar_t PATH_URL_DELIMITER_W=::SHINSEI_PATH_URL_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t PATH_URL_DELIMITER_U8=::SHINSEI_PATH_URL_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t PATH_URL_DELIMITER_U16=::SHINSEI_PATH_URL_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t PATH_URL_DELIMITER_U32=::SHINSEI_PATH_URL_DELIMITER_U32;
	
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiter(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiter(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiter(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiter(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiter(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathDelimiterM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathDelimiterU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiter(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiter(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiter(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiter(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiter(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathDelimiterM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathDelimiterU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiter(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiter(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiter(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiter(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiter(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathDelimiterM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathDelimiterU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isApplePathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiterCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiter(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiterM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiter(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiterM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiter(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiterM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiter(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiterM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiter(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathDelimiterM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathDelimiterU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isSunPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiterCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiter(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiterM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiter(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiterM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiter(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiterM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiter(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiterM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiter(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathDelimiterM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathDelimiterU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiter(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiter(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiter(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiter(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiter(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathDelimiterM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathDelimiterU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiter(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiter(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiter(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiter(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiter(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathDelimiterM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathDelimiterU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isURLPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiterCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiter(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterW(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiterM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiter(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiterM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiter(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterU8(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiterM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiter(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterU16(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiterM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiter(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterU32(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathDelimiterM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathDelimiterU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalChar(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalChar(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalChar(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalChar(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalChar(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isWindowsPathIllegalCharM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isWindowsPathIllegalCharU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalChar(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalChar(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalChar(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalChar(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalChar(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isUnixPathIllegalCharM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUnixPathIllegalCharU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalChar(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalChar(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalChar(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalChar(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalChar(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isLinuxPathIllegalCharM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLinuxPathIllegalCharU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalChar(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalChar(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalChar(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalChar(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalChar(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isApplePathIllegalCharM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isApplePathIllegalCharU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalChar(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalChar(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalChar(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalChar(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalChar(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isSunPathIllegalCharM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSunPathIllegalCharU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalChar(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalChar(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalChar(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalChar(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalChar(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isFreeBSDPathIllegalCharM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFreeBSDPathIllegalCharU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalChar(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalChar(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalChar(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalChar(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalChar(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isCygwinPathIllegalCharM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCygwinPathIllegalCharU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalChar(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharW(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalChar(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharCP(code_page,ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharCPM(code_page,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalChar(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharU8(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalChar(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharU16(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharM(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalChar(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharU32(ch);
	}
	_SHINSEI_OS_INLINE bool isURLPathIllegalCharM(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isURLPathIllegalCharU32M(str_ptr,len);
	}
	
	// Windows Path Normalize
	_SHINSEI_OS_INLINE int windowsPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalize(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalize(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalize(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalize(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeU32(path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalize(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeU32(path,len);
	}
	
	// Unix Path Normalize
	_SHINSEI_OS_INLINE int unixPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalize(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalize(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalize(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalize(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeU32(path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalize(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeU32(path,len);
	}
	
	// Linux Path Normalize
	_SHINSEI_OS_INLINE int linuxPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalize(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalize(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalize(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalize(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeU32(path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalize(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeU32(path,len);
	}
	
	// Apple Path Normalize
	_SHINSEI_OS_INLINE int applePathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalize(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalize(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalize(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalize(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeU32(path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalize(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeU32(path,len);
	}
	
	// Sun Path Normalize
	_SHINSEI_OS_INLINE int sunPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalize(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalize(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalize(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalize(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeU32(path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalize(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeU32(path,len);
	}
	
	// FreeBSD Path Normalize
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalize(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalize(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalize(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalize(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeU32(path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalize(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeU32(path,len);
	}
	
	// Cygwin Path Normalize
	_SHINSEI_OS_INLINE int cygwinPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalize(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalize(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalize(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalize(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeU32(path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalize(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeU32(path,len);
	}
	
	// URL Path Normalize
	_SHINSEI_OS_INLINE int uRLPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalize(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeW(path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalize(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalize(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeU8(path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalize(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeU16(path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeU32(path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalize(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeU32(path,len);
	}
	
	// Windows Path Normalize No Traversal
	_SHINSEI_OS_INLINE int windowsPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalizeNoTraversal(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalizeNoTraversal(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalizeNoTraversal(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalizeNoTraversal(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeNoTraversalU32(path,len);
	}
	_SHINSEI_OS_INLINE int windowsPathNormalizeNoTraversal(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathNormalizeNoTraversalU32(path,len);
	}
	
	// Unix Path Normalize No Traversal
	_SHINSEI_OS_INLINE int unixPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalizeNoTraversal(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalizeNoTraversal(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalizeNoTraversal(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalizeNoTraversal(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeNoTraversalU32(path,len);
	}
	_SHINSEI_OS_INLINE int unixPathNormalizeNoTraversal(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_unixPathNormalizeNoTraversalU32(path,len);
	}
	
	// Linux Path Normalize No Traversal
	_SHINSEI_OS_INLINE int linuxPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalizeNoTraversal(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalizeNoTraversal(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalizeNoTraversal(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalizeNoTraversal(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeNoTraversalU32(path,len);
	}
	_SHINSEI_OS_INLINE int linuxPathNormalizeNoTraversal(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_linuxPathNormalizeNoTraversalU32(path,len);
	}
	
	// Apple Path Normalize No Traversal
	_SHINSEI_OS_INLINE int applePathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalizeNoTraversal(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalizeNoTraversal(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalizeNoTraversal(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalizeNoTraversal(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeNoTraversalU32(path,len);
	}
	_SHINSEI_OS_INLINE int applePathNormalizeNoTraversal(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_applePathNormalizeNoTraversalU32(path,len);
	}
	
	// Sun Path Normalize No Traversal
	_SHINSEI_OS_INLINE int sunPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalizeNoTraversal(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalizeNoTraversal(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalizeNoTraversal(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalizeNoTraversal(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeNoTraversalU32(path,len);
	}
	_SHINSEI_OS_INLINE int sunPathNormalizeNoTraversal(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_sunPathNormalizeNoTraversalU32(path,len);
	}
	
	// FreeBSD Path Normalize No Traversal
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeNoTraversal(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeNoTraversal(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeNoTraversal(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeNoTraversal(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeNoTraversalU32(path,len);
	}
	_SHINSEI_OS_INLINE int freeBSDPathNormalizeNoTraversal(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_freeBSDPathNormalizeNoTraversalU32(path,len);
	}
	
	// Cygwin Path Normalize No Traversal
	_SHINSEI_OS_INLINE int cygwinPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalizeNoTraversal(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalizeNoTraversal(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalizeNoTraversal(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalizeNoTraversal(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeNoTraversalU32(path,len);
	}
	_SHINSEI_OS_INLINE int cygwinPathNormalizeNoTraversal(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_cygwinPathNormalizeNoTraversalU32(path,len);
	}
	
	// URL Path Normalize No Traversal
	_SHINSEI_OS_INLINE int uRLPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalizeNoTraversal(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeNoTraversalW(path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalizeNoTraversal(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeNoTraversalCP(code_page,path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalizeNoTraversal(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeNoTraversalU8(path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalizeNoTraversal(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeNoTraversalU16(path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeNoTraversalU32(path,len);
	}
	_SHINSEI_OS_INLINE int uRLPathNormalizeNoTraversal(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uRLPathNormalizeNoTraversalU32(path,len);
	}
	
	_SHINSEI_OS_INLINE size_t windowsPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoinV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoinW(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_windowsPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoin(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_windowsPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoinCPV(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoinV(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoinCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_windowsPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoin(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_windowsPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoinV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoinU8(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_windowsPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoin(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_windowsPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoinV(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoinU16(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_windowsPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoin(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_windowsPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoinV(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_windowsPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoinU32(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_windowsPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	_SHINSEI_OS_INLINE size_t windowsPathJoin(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
		va_list args;
		va_start(args,first_part_len);
		const size_t res=::shinsei_windowsPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
		va_end(args);
		return res;
	}
	
	_SHINSEI_OS_INLINE size_t splitStringToWindowsPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToWindowsPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToWindowsPath(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToWindowsPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToWindowsPathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToWindowsPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToWindowsPath(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToWindowsPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToWindowsPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToWindowsPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToWindowsPath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToWindowsPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToWindowsPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToWindowsPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToWindowsPath(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToWindowsPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToWindowsPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToWindowsPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToWindowsPath(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToWindowsPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	
	// Unix
	_SHINSEI_OS_INLINE size_t splitStringToUnixPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToUnixPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToUnixPath(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToUnixPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToUnixPathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToUnixPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToUnixPath(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToUnixPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToUnixPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToUnixPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToUnixPath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToUnixPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToUnixPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToUnixPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToUnixPath(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToUnixPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToUnixPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToUnixPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToUnixPath(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToUnixPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	
	// Linux
	_SHINSEI_OS_INLINE size_t splitStringToLinuxPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToLinuxPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToLinuxPath(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToLinuxPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToLinuxPathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToLinuxPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToLinuxPath(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToLinuxPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToLinuxPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToLinuxPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToLinuxPath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToLinuxPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToLinuxPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToLinuxPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToLinuxPath(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToLinuxPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToLinuxPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToLinuxPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToLinuxPath(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToLinuxPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	
	// Apple
	_SHINSEI_OS_INLINE size_t splitStringToApplePathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToApplePathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToApplePath(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToApplePathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToApplePathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToApplePathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToApplePath(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToApplePathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToApplePathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToApplePathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToApplePath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToApplePathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToApplePathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToApplePathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToApplePath(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToApplePathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToApplePathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToApplePathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToApplePath(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToApplePathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	
	// Sun
	_SHINSEI_OS_INLINE size_t splitStringToSunPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToSunPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToSunPath(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToSunPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToSunPathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToSunPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToSunPath(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToSunPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToSunPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToSunPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToSunPath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToSunPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToSunPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToSunPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToSunPath(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToSunPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToSunPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToSunPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToSunPath(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToSunPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	
	// FreeBSD
	_SHINSEI_OS_INLINE size_t splitStringToFreeBSDPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToFreeBSDPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToFreeBSDPath(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToFreeBSDPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToFreeBSDPathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToFreeBSDPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToFreeBSDPath(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToFreeBSDPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToFreeBSDPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToFreeBSDPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToFreeBSDPath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToFreeBSDPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToFreeBSDPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToFreeBSDPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToFreeBSDPath(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToFreeBSDPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToFreeBSDPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToFreeBSDPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToFreeBSDPath(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToFreeBSDPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	
	// Cygwin
	_SHINSEI_OS_INLINE size_t splitStringToCygwinPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToCygwinPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToCygwinPath(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToCygwinPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToCygwinPathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToCygwinPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToCygwinPath(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToCygwinPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToCygwinPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToCygwinPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToCygwinPath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToCygwinPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToCygwinPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToCygwinPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToCygwinPath(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToCygwinPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToCygwinPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToCygwinPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToCygwinPath(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToCygwinPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	
	// URL
	_SHINSEI_OS_INLINE size_t splitStringToURLPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToURLPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToURLPath(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToURLPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToURLPathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToURLPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToURLPath(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToURLPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToURLPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToURLPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToURLPath(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToURLPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToURLPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToURLPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToURLPath(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToURLPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToURLPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToURLPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
	_SHINSEI_OS_INLINE size_t splitStringToURLPath(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToURLPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
	}
}
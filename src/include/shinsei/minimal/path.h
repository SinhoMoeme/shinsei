#pragma once

#include"shinsei/.internal/usage.h"
#include"shinsei/.internal/wchar.h"

#include<uchar.h>
#include<stdarg.h>
#if defined(_SHINSEI_OS_MSVC)
	#include<string.h>
#endif

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

#ifdef _SHINSEI_OS_CONSTEXPR
	static _SHINSEI_OS_CONSTEXPR int SHINSEI_PATH_ILLEGAL=0;
	static _SHINSEI_OS_CONSTEXPR int SHINSEI_PATH_ABSOLUTE=1;
	static _SHINSEI_OS_CONSTEXPR int SHINSEI_PATH_RELATIVE=2;
	static _SHINSEI_OS_CONSTEXPR int SHINSEI_PATH_TRAVERSAL=0x10000000;
	static _SHINSEI_OS_CONSTEXPR int SHINSEI_PATH_WINDOWS_UNC=0x00010000;
	static _SHINSEI_OS_CONSTEXPR int SHINSEI_PATH_WINDOWS_DRIVE_RELATIVE=0x00020000;
	static _SHINSEI_OS_CONSTEXPR int SHINSEI_PATH_WINDOWS_DEVICE=0x00030000;
	static _SHINSEI_OS_CONSTEXPR int SHINSEI_PATH_WINDOWS_DOS_DEVICE=0x00040000;
	
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_PATH_WINDOWS_MAX_LEGACY=260;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_PATH_WINDOWS_MAX=32767;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_PATH_UNIX_MAX=4096;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_PATH_LINUX_MAX=SHINSEI_PATH_UNIX_MAX;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_PATH_APPLE_MAX=SHINSEI_PATH_UNIX_MAX;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_PATH_APPLE_MAX_LEGACY=1024;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_PATH_SUN_MAX=SHINSEI_PATH_UNIX_MAX;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_PATH_FREEBSD_MAX=SHINSEI_PATH_UNIX_MAX;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_PATH_CYGWIN_MAX=SHINSEI_PATH_UNIX_MAX;
	
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_PATH_SBO_CNT=4;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_PATH_MINIMAL=32;
	
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_WINDOWS_DELIMITER_ASCII='\\';
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_WINDOWS_DELIMITER_EBCDIC=(char)0xE0;
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_WINDOWS_DELIMITER_W=L'\\';
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_WINDOWS_DELIMITER_U8=u8'\\';
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_WINDOWS_DELIMITER_U16=u'\\';
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_WINDOWS_DELIMITER_U32=U'\\';
	
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_UNIX_DELIMITER_ASCII='/';
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_UNIX_DELIMITER_EBCDIC=(char)0x61;
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_UNIX_DELIMITER_W=L'/';
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_UNIX_DELIMITER_U8=u8'/';
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_UNIX_DELIMITER_U16=u'/';
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_UNIX_DELIMITER_U32=U'/';
	
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_LINUX_DELIMITER_ASCII=SHINSEI_PATH_UNIX_DELIMITER_ASCII;
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_LINUX_DELIMITER_EBCDIC=SHINSEI_PATH_UNIX_DELIMITER_EBCDIC;
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_LINUX_DELIMITER_W=SHINSEI_PATH_UNIX_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_LINUX_DELIMITER_U8=SHINSEI_PATH_UNIX_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_LINUX_DELIMITER_U16=SHINSEI_PATH_UNIX_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_LINUX_DELIMITER_U32=SHINSEI_PATH_UNIX_DELIMITER_U32;
	
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_APPLE_DELIMITER_ASCII=SHINSEI_PATH_UNIX_DELIMITER_ASCII;
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_APPLE_DELIMITER_EBCDIC=SHINSEI_PATH_UNIX_DELIMITER_EBCDIC;
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_APPLE_DELIMITER_W=SHINSEI_PATH_UNIX_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_APPLE_DELIMITER_U8=SHINSEI_PATH_UNIX_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_APPLE_DELIMITER_U16=SHINSEI_PATH_UNIX_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_APPLE_DELIMITER_U32=SHINSEI_PATH_UNIX_DELIMITER_U32;
	
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_SUN_DELIMITER_ASCII=SHINSEI_PATH_UNIX_DELIMITER_ASCII;
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_SUN_DELIMITER_EBCDIC=SHINSEI_PATH_UNIX_DELIMITER_EBCDIC;
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_SUN_DELIMITER_W=SHINSEI_PATH_UNIX_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_SUN_DELIMITER_U8=SHINSEI_PATH_UNIX_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_SUN_DELIMITER_U16=SHINSEI_PATH_UNIX_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_SUN_DELIMITER_U32=SHINSEI_PATH_UNIX_DELIMITER_U32;
	
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_FREEBSD_DELIMITER_ASCII=SHINSEI_PATH_UNIX_DELIMITER_ASCII;
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_FREEBSD_DELIMITER_EBCDIC=SHINSEI_PATH_UNIX_DELIMITER_EBCDIC;
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_FREEBSD_DELIMITER_W=SHINSEI_PATH_UNIX_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_FREEBSD_DELIMITER_U8=SHINSEI_PATH_UNIX_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_FREEBSD_DELIMITER_U16=SHINSEI_PATH_UNIX_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_FREEBSD_DELIMITER_U32=SHINSEI_PATH_UNIX_DELIMITER_U32;
	
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_CYGWIN_DELIMITER_ASCII=SHINSEI_PATH_UNIX_DELIMITER_ASCII;
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_CYGWIN_DELIMITER_EBCDIC=SHINSEI_PATH_UNIX_DELIMITER_EBCDIC;
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_CYGWIN_DELIMITER_W=SHINSEI_PATH_UNIX_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_CYGWIN_DELIMITER_U8=SHINSEI_PATH_UNIX_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_CYGWIN_DELIMITER_U16=SHINSEI_PATH_UNIX_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_CYGWIN_DELIMITER_U32=SHINSEI_PATH_UNIX_DELIMITER_U32;
	
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_URL_DELIMITER_ASCII='/';
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_URL_DELIMITER_EBCDIC=(char)0x61;
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_URL_DELIMITER_W=L'/';
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_URL_DELIMITER_U8=u8'/';
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_URL_DELIMITER_U16=u'/';
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_URL_DELIMITER_U32=U'/';
#else
	#define SHINSEI_PATH_ILLEGAL 0
	#define SHINSEI_PATH_ABSOLUTE 1
	#define SHINSEI_PATH_RELATIVE 2
	#define SHINSEI_PATH_TRAVERSAL 0x10000000
	#define SHINSEI_PATH_WINDOWS_UNC 0x00010000
	#define SHINSEI_PATH_WINDOWS_DRIVE_RELATIVE 0x00020000
	#define SHINSEI_PATH_WINDOWS_DEVICE 0x00030000
	#define SHINSEI_PATH_WINDOWS_DOS_DEVICE 0x00040000
	
	#define SHINSEI_PATH_WINDOWS_MAX_LEGACY ((size_t)260)
	#define SHINSEI_PATH_WINDOWS_MAX ((size_t)32767)
	#define SHINSEI_PATH_UNIX_MAX ((size_t)4096)
	#define SHINSEI_PATH_LINUX_MAX SHINSEI_PATH_UNIX_MAX
	#define SHINSEI_PATH_APPLE_MAX SHINSEI_PATH_UNIX_MAX
	#define SHINSEI_PATH_APPLE_MAX_LEGACY ((size_t)1024)
	#define SHINSEI_PATH_SUN_MAX SHINSEI_PATH_UNIX_MAX
	#define SHINSEI_PATH_FREEBSD_MAX SHINSEI_PATH_UNIX_MAX
	#define SHINSEI_PATH_CYGWIN_MAX SHINSEI_PATH_UNIX_MAX
	
	#define SHINSEI_PATH_SBO_CNT ((size_t)4)
	#define SHINSEI_PATH_MINIMAL ((size_t)32)
	
	#define SHINSEI_PATH_WINDOWS_DELIMITER_ASCII '\\'
	#define SHINSEI_PATH_WINDOWS_DELIMITER_EBCDIC ((char)0xE0)
	#define SHINSEI_PATH_WINDOWS_DELIMITER_W L'\\'
	#define SHINSEI_PATH_WINDOWS_DELIMITER_U8 u8'\\'
	#define SHINSEI_PATH_WINDOWS_DELIMITER_U16 u'\\'
	#define SHINSEI_PATH_WINDOWS_DELIMITER_U32 U'\\'
	
	#define SHINSEI_PATH_UNIX_DELIMITER_ASCII '/'
	#define SHINSEI_PATH_UNIX_DELIMITER_EBCDIC ((char)0x61)
	#define SHINSEI_PATH_UNIX_DELIMITER_W L'/'
	#define SHINSEI_PATH_UNIX_DELIMITER_U8 u8'/'
	#define SHINSEI_PATH_UNIX_DELIMITER_U16 u'/'
	#define SHINSEI_PATH_UNIX_DELIMITER_U32 U'/'
	
	#define SHINSEI_PATH_LINUX_DELIMITER_ASCII SHINSEI_PATH_UNIX_DELIMITER_ASCII
	#define SHINSEI_PATH_LINUX_DELIMITER_EBCDIC SHINSEI_PATH_UNIX_DELIMITER_EBCDIC
	#define SHINSEI_PATH_LINUX_DELIMITER_W SHINSEI_PATH_UNIX_DELIMITER_W
	#define SHINSEI_PATH_LINUX_DELIMITER_U8 SHINSEI_PATH_UNIX_DELIMITER_U8
	#define SHINSEI_PATH_LINUX_DELIMITER_U16 SHINSEI_PATH_UNIX_DELIMITER_U16
	#define SHINSEI_PATH_LINUX_DELIMITER_U32 SHINSEI_PATH_UNIX_DELIMITER_U32
	
	#define SHINSEI_PATH_APPLE_DELIMITER_ASCII SHINSEI_PATH_UNIX_DELIMITER_ASCII
	#define SHINSEI_PATH_APPLE_DELIMITER_EBCDIC SHINSEI_PATH_UNIX_DELIMITER_EBCDIC
	#define SHINSEI_PATH_APPLE_DELIMITER_W SHINSEI_PATH_UNIX_DELIMITER_W
	#define SHINSEI_PATH_APPLE_DELIMITER_U8 SHINSEI_PATH_UNIX_DELIMITER_U8
	#define SHINSEI_PATH_APPLE_DELIMITER_U16 SHINSEI_PATH_UNIX_DELIMITER_U16
	#define SHINSEI_PATH_APPLE_DELIMITER_U32 SHINSEI_PATH_UNIX_DELIMITER_U32
	
	#define SHINSEI_PATH_SUN_DELIMITER_ASCII SHINSEI_PATH_UNIX_DELIMITER_ASCII
	#define SHINSEI_PATH_SUN_DELIMITER_EBCDIC SHINSEI_PATH_UNIX_DELIMITER_EBCDIC
	#define SHINSEI_PATH_SUN_DELIMITER_W SHINSEI_PATH_UNIX_DELIMITER_W
	#define SHINSEI_PATH_SUN_DELIMITER_U8 SHINSEI_PATH_UNIX_DELIMITER_U8
	#define SHINSEI_PATH_SUN_DELIMITER_U16 SHINSEI_PATH_UNIX_DELIMITER_U16
	#define SHINSEI_PATH_SUN_DELIMITER_U32 SHINSEI_PATH_UNIX_DELIMITER_U32
	
	#define SHINSEI_PATH_FREEBSD_DELIMITER_ASCII SHINSEI_PATH_UNIX_DELIMITER_ASCII
	#define SHINSEI_PATH_FREEBSD_DELIMITER_EBCDIC SHINSEI_PATH_UNIX_DELIMITER_EBCDIC
	#define SHINSEI_PATH_FREEBSD_DELIMITER_W SHINSEI_PATH_UNIX_DELIMITER_W
	#define SHINSEI_PATH_FREEBSD_DELIMITER_U8 SHINSEI_PATH_UNIX_DELIMITER_U8
	#define SHINSEI_PATH_FREEBSD_DELIMITER_U16 SHINSEI_PATH_UNIX_DELIMITER_U16
	#define SHINSEI_PATH_FREEBSD_DELIMITER_U32 SHINSEI_PATH_UNIX_DELIMITER_U32
	
	#define SHINSEI_PATH_CYGWIN_DELIMITER_ASCII SHINSEI_PATH_UNIX_DELIMITER_ASCII
	#define SHINSEI_PATH_CYGWIN_DELIMITER_EBCDIC SHINSEI_PATH_UNIX_DELIMITER_EBCDIC
	#define SHINSEI_PATH_CYGWIN_DELIMITER_W SHINSEI_PATH_UNIX_DELIMITER_W
	#define SHINSEI_PATH_CYGWIN_DELIMITER_U8 SHINSEI_PATH_UNIX_DELIMITER_U8
	#define SHINSEI_PATH_CYGWIN_DELIMITER_U16 SHINSEI_PATH_UNIX_DELIMITER_U16
	#define SHINSEI_PATH_CYGWIN_DELIMITER_U32 SHINSEI_PATH_UNIX_DELIMITER_U32
	
	#define SHINSEI_PATH_URL_DELIMITER_ASCII '/'
	#define SHINSEI_PATH_URL_DELIMITER_EBCDIC ((char)0x61)
	#define SHINSEI_PATH_URL_DELIMITER_W L'/'
	#define SHINSEI_PATH_URL_DELIMITER_U8 u8'/'
	#define SHINSEI_PATH_URL_DELIMITER_U16 u'/'
	#define SHINSEI_PATH_URL_DELIMITER_U32 U'/'
	
#endif

_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isUnixPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathDelimiterCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isApplePathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathDelimiterCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isSunPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathDelimiterCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isFreeBSDPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathDelimiterCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isCygwinPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathDelimiterCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isURLPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathDelimiterCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isUnixPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathIllegalCharCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isApplePathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathIllegalCharCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isSunPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathIllegalCharCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isFreeBSDPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathIllegalCharCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isCygwinPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathIllegalCharCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isURLPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathIllegalCharCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_windowsPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_windowsPathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_windowsPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_windowsPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_windowsPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_unixPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_unixPathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_unixPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_unixPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_unixPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_linuxPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_linuxPathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_linuxPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_linuxPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_linuxPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_applePathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_applePathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_applePathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_applePathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_applePathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_sunPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_sunPathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_sunPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_sunPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_sunPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_uRLPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_uRLPathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_uRLPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_uRLPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_uRLPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_windowsPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_windowsPathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_windowsPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_windowsPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_windowsPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_unixPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_unixPathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_unixPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_unixPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_unixPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_linuxPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_linuxPathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_linuxPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_linuxPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_linuxPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_applePathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_applePathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_applePathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_applePathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_applePathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_sunPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_sunPathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_sunPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_sunPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_sunPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_uRLPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_uRLPathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_uRLPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_uRLPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_uRLPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_windowsPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_windowsPathJoinW(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_windowsPathJoinCPV(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_windowsPathJoinCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_windowsPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_windowsPathJoinU8(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_windowsPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_windowsPathJoinU16(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_windowsPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_windowsPathJoinU32(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_unixPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_unixPathJoinW(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_unixPathJoinCPV(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_unixPathJoinCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_unixPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_unixPathJoinU8(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_unixPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_unixPathJoinU16(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_unixPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_unixPathJoinU32(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_linuxPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_linuxPathJoinW(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_linuxPathJoinCPV(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_linuxPathJoinCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_linuxPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_linuxPathJoinU8(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_linuxPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_linuxPathJoinU16(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_linuxPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_linuxPathJoinU32(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_applePathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_applePathJoinW(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_applePathJoinCPV(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_applePathJoinCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_applePathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_applePathJoinU8(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_applePathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_applePathJoinU16(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_applePathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_applePathJoinU32(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_sunPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_sunPathJoinW(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_sunPathJoinCPV(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_sunPathJoinCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_sunPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_sunPathJoinU8(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_sunPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_sunPathJoinU16(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_sunPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_sunPathJoinU32(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_freeBSDPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_freeBSDPathJoinW(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_freeBSDPathJoinCPV(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_freeBSDPathJoinCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_freeBSDPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_freeBSDPathJoinU8(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_freeBSDPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_freeBSDPathJoinU16(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_freeBSDPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_freeBSDPathJoinU32(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_cygwinPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_cygwinPathJoinW(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_cygwinPathJoinCPV(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_cygwinPathJoinCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_cygwinPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_cygwinPathJoinU8(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_cygwinPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_cygwinPathJoinU16(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_cygwinPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_cygwinPathJoinU32(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_uRLPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uRLPathJoinW(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uRLPathJoinCPV(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uRLPathJoinCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uRLPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uRLPathJoinU8(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uRLPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uRLPathJoinU16(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uRLPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uRLPathJoinU32(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToWindowsPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToWindowsPathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToWindowsPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToWindowsPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToWindowsPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToUnixPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToUnixPathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToUnixPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToUnixPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToUnixPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToLinuxPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToLinuxPathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToLinuxPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToLinuxPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToLinuxPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToApplePathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToApplePathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToApplePathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToApplePathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToApplePathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToSunPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToSunPathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToSunPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToSunPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToSunPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToFreeBSDPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToFreeBSDPathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToFreeBSDPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToFreeBSDPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToFreeBSDPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToCygwinPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToCygwinPathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToCygwinPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToCygwinPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToCygwinPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToURLPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToURLPathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToURLPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToURLPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToURLPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif
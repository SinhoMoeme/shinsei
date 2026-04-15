#pragma once

#include"shinsei/.internal/usage.h"
#include"shinsei/str.h"

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
	
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_WINDOWS_DELIMITER_A='\\';
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_WINDOWS_DELIMITER_W=L'\\';
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_WINDOWS_DELIMITER_U8=u8'\\';
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_WINDOWS_DELIMITER_U16=u'\\';
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_WINDOWS_DELIMITER_U32=U'\\';
	#if defined(_SHINSEI_OS_WINDOWS)
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_WINDOWS_DELIMITER_N=SHINSEI_PATH_WINDOWS_DELIMITER_W;
	#elif defined(_SHINSEI_OS_UNIX)
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_WINDOWS_DELIMITER_N=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
	#endif
	
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_UNIX_DELIMITER_A='/';
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_UNIX_DELIMITER_W=L'/';
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_UNIX_DELIMITER_U8=u8'/';
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_UNIX_DELIMITER_U16=u'/';
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_UNIX_DELIMITER_U32=U'/';
	#if defined(_SHINSEI_OS_WINDOWS)
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_UNIX_DELIMITER_N=SHINSEI_PATH_UNIX_DELIMITER_W;
	#elif defined(_SHINSEI_OS_UNIX)
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_UNIX_DELIMITER_N=SHINSEI_PATH_UNIX_DELIMITER_U8;
	#endif
	
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_LINUX_DELIMITER_A=SHINSEI_PATH_UNIX_DELIMITER_A;
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_LINUX_DELIMITER_W=SHINSEI_PATH_UNIX_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_LINUX_DELIMITER_U8=SHINSEI_PATH_UNIX_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_LINUX_DELIMITER_U16=SHINSEI_PATH_UNIX_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_LINUX_DELIMITER_U32=SHINSEI_PATH_UNIX_DELIMITER_U32;
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_LINUX_DELIMITER_N=SHINSEI_PATH_UNIX_DELIMITER_N;
	
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_APPLE_DELIMITER_A=SHINSEI_PATH_UNIX_DELIMITER_A;
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_APPLE_DELIMITER_W=SHINSEI_PATH_UNIX_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_APPLE_DELIMITER_U8=SHINSEI_PATH_UNIX_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_APPLE_DELIMITER_U16=SHINSEI_PATH_UNIX_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_APPLE_DELIMITER_U32=SHINSEI_PATH_UNIX_DELIMITER_U32;
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_APPLE_DELIMITER_N=SHINSEI_PATH_UNIX_DELIMITER_N;
	
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_SUN_DELIMITER_A=SHINSEI_PATH_UNIX_DELIMITER_A;
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_SUN_DELIMITER_W=SHINSEI_PATH_UNIX_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_SUN_DELIMITER_U8=SHINSEI_PATH_UNIX_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_SUN_DELIMITER_U16=SHINSEI_PATH_UNIX_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_SUN_DELIMITER_U32=SHINSEI_PATH_UNIX_DELIMITER_U32;
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_SUN_DELIMITER_N=SHINSEI_PATH_UNIX_DELIMITER_N;
	
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_FREEBSD_DELIMITER_A=SHINSEI_PATH_UNIX_DELIMITER_A;
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_FREEBSD_DELIMITER_W=SHINSEI_PATH_UNIX_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_FREEBSD_DELIMITER_U8=SHINSEI_PATH_UNIX_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_FREEBSD_DELIMITER_U16=SHINSEI_PATH_UNIX_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_FREEBSD_DELIMITER_U32=SHINSEI_PATH_UNIX_DELIMITER_U32;
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_FREEBSD_DELIMITER_N=SHINSEI_PATH_UNIX_DELIMITER_N;
	
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_CYGWIN_DELIMITER_A=SHINSEI_PATH_UNIX_DELIMITER_A;
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_CYGWIN_DELIMITER_W=SHINSEI_PATH_UNIX_DELIMITER_W;
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_CYGWIN_DELIMITER_U8=SHINSEI_PATH_UNIX_DELIMITER_U8;
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_CYGWIN_DELIMITER_U16=SHINSEI_PATH_UNIX_DELIMITER_U16;
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_CYGWIN_DELIMITER_U32=SHINSEI_PATH_UNIX_DELIMITER_U32;
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_CYGWIN_DELIMITER_N=SHINSEI_PATH_UNIX_DELIMITER_N;
	
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_URL_DELIMITER_A='/';
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_URL_DELIMITER_W=L'/';
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_URL_DELIMITER_U8=u8'/';
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_URL_DELIMITER_U16=u'/';
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_URL_DELIMITER_U32=U'/';
	#if defined(_SHINSEI_OS_WINDOWS)
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_URL_DELIMITER_N=SHINSEI_PATH_URL_DELIMITER_W;
	#elif defined(_SHINSEI_OS_UNIX)
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_URL_DELIMITER_N=SHINSEI_PATH_URL_DELIMITER_U8;
	#endif
#else
	#define SHINSEI_PATH_ILLEGAL 0
	#define SHINSEI_PATH_ABSOLUTE 1
	#define SHINSEI_PATH_RELATIVE 2
	#define SHINSEI_PATH_TRAVERSAL 0x10000000
	#define SHINSEI_PATH_WINDOWS_UNC 0x00010000
	#define SHINSEI_PATH_WINDOWS_DRIVE_RELATIVE 0x00020000
	#define SHINSEI_PATH_WINDOWS_DEVICE 0x00030000
	#define SHINSEI_PATH_WINDOWS_DOS_DEVICE 0x00040000
	
	#define SHINSEI_PATH_WINDOWS_MAX_LEGACY (size_t)260
	#define SHINSEI_PATH_WINDOWS_MAX (size_t)32767
	#define SHINSEI_PATH_UNIX_MAX (size_t)4096
	#define SHINSEI_PATH_LINUX_MAX SHINSEI_PATH_UNIX_MAX
	#define SHINSEI_PATH_APPLE_MAX SHINSEI_PATH_UNIX_MAX
	#define SHINSEI_PATH_APPLE_MAX_LEGACY (size_t)1024
	#define SHINSEI_PATH_SUN_MAX SHINSEI_PATH_UNIX_MAX
	#define SHINSEI_PATH_FREEBSD_MAX SHINSEI_PATH_UNIX_MAX
	#define SHINSEI_PATH_CYGWIN_MAX SHINSEI_PATH_UNIX_MAX
	
	#define SHINSEI_PATH_SBO_CNT (size_t)4
	#define SHINSEI_PATH_MINIMAL (size_t)32
	
	#define SHINSEI_PATH_WINDOWS_DELIMITER_A '\\'
	#define SHINSEI_PATH_WINDOWS_DELIMITER_W L'\\'
	#define SHINSEI_PATH_WINDOWS_DELIMITER_U8 u8'\\'
	#define SHINSEI_PATH_WINDOWS_DELIMITER_U16 u'\\'
	#define SHINSEI_PATH_WINDOWS_DELIMITER_U32 U'\\'
	#if defined(_SHINSEI_OS_WINDOWS)
		#define SHINSEI_PATH_WINDOWS_DELIMITER_N SHINSEI_PATH_WINDOWS_DELIMITER_W
	#elif defined(_SHINSEI_OS_UNIX)
		#define SHINSEI_PATH_WINDOWS_DELIMITER_N SHINSEI_PATH_WINDOWS_DELIMITER_U8
	#endif
	
	#define SHINSEI_PATH_UNIX_DELIMITER_A '/'
	#define SHINSEI_PATH_UNIX_DELIMITER_W L'/'
	#define SHINSEI_PATH_UNIX_DELIMITER_U8 u8'/'
	#define SHINSEI_PATH_UNIX_DELIMITER_U16 u'/'
	#define SHINSEI_PATH_UNIX_DELIMITER_U32 U'/'
	#if defined(_SHINSEI_OS_WINDOWS)
		#define SHINSEI_PATH_UNIX_DELIMITER_N SHINSEI_PATH_UNIX_DELIMITER_W
	#elif defined(_SHINSEI_OS_UNIX)
		#define SHINSEI_PATH_UNIX_DELIMITER_N SHINSEI_PATH_UNIX_DELIMITER_U8
	#endif
	
	#define SHINSEI_PATH_LINUX_DELIMITER_A SHINSEI_PATH_UNIX_DELIMITER_A
	#define SHINSEI_PATH_LINUX_DELIMITER_W SHINSEI_PATH_UNIX_DELIMITER_W
	#define SHINSEI_PATH_LINUX_DELIMITER_U8 SHINSEI_PATH_UNIX_DELIMITER_U8
	#define SHINSEI_PATH_LINUX_DELIMITER_U16 SHINSEI_PATH_UNIX_DELIMITER_U16
	#define SHINSEI_PATH_LINUX_DELIMITER_U32 SHINSEI_PATH_UNIX_DELIMITER_U32
	#define SHINSEI_PATH_LINUX_DELIMITER_N SHINSEI_PATH_UNIX_DELIMITER_N
	
	#define SHINSEI_PATH_APPLE_DELIMITER_A SHINSEI_PATH_UNIX_DELIMITER_A
	#define SHINSEI_PATH_APPLE_DELIMITER_W SHINSEI_PATH_UNIX_DELIMITER_W
	#define SHINSEI_PATH_APPLE_DELIMITER_U8 SHINSEI_PATH_UNIX_DELIMITER_U8
	#define SHINSEI_PATH_APPLE_DELIMITER_U16 SHINSEI_PATH_UNIX_DELIMITER_U16
	#define SHINSEI_PATH_APPLE_DELIMITER_U32 SHINSEI_PATH_UNIX_DELIMITER_U32
	#define SHINSEI_PATH_APPLE_DELIMITER_N SHINSEI_PATH_UNIX_DELIMITER_N
	
	#define SHINSEI_PATH_SUN_DELIMITER_A SHINSEI_PATH_UNIX_DELIMITER_A
	#define SHINSEI_PATH_SUN_DELIMITER_W SHINSEI_PATH_UNIX_DELIMITER_W
	#define SHINSEI_PATH_SUN_DELIMITER_U8 SHINSEI_PATH_UNIX_DELIMITER_U8
	#define SHINSEI_PATH_SUN_DELIMITER_U16 SHINSEI_PATH_UNIX_DELIMITER_U16
	#define SHINSEI_PATH_SUN_DELIMITER_U32 SHINSEI_PATH_UNIX_DELIMITER_U32
	#define SHINSEI_PATH_SUN_DELIMITER_N SHINSEI_PATH_UNIX_DELIMITER_N
	
	#define SHINSEI_PATH_FREEBSD_DELIMITER_A SHINSEI_PATH_UNIX_DELIMITER_A
	#define SHINSEI_PATH_FREEBSD_DELIMITER_W SHINSEI_PATH_UNIX_DELIMITER_W
	#define SHINSEI_PATH_FREEBSD_DELIMITER_U8 SHINSEI_PATH_UNIX_DELIMITER_U8
	#define SHINSEI_PATH_FREEBSD_DELIMITER_U16 SHINSEI_PATH_UNIX_DELIMITER_U16
	#define SHINSEI_PATH_FREEBSD_DELIMITER_U32 SHINSEI_PATH_UNIX_DELIMITER_U32
	#define SHINSEI_PATH_FREEBSD_DELIMITER_N SHINSEI_PATH_UNIX_DELIMITER_N
	
	#define SHINSEI_PATH_CYGWIN_DELIMITER_A SHINSEI_PATH_UNIX_DELIMITER_A
	#define SHINSEI_PATH_CYGWIN_DELIMITER_W SHINSEI_PATH_UNIX_DELIMITER_W
	#define SHINSEI_PATH_CYGWIN_DELIMITER_U8 SHINSEI_PATH_UNIX_DELIMITER_U8
	#define SHINSEI_PATH_CYGWIN_DELIMITER_U16 SHINSEI_PATH_UNIX_DELIMITER_U16
	#define SHINSEI_PATH_CYGWIN_DELIMITER_U32 SHINSEI_PATH_UNIX_DELIMITER_U32
	#define SHINSEI_PATH_CYGWIN_DELIMITER_N SHINSEI_PATH_UNIX_DELIMITER_N
	
	#define SHINSEI_PATH_URL_DELIMITER_A '/'
	#define SHINSEI_PATH_URL_DELIMITER_W L'/'
	#define SHINSEI_PATH_URL_DELIMITER_U8 u8'/'
	#define SHINSEI_PATH_URL_DELIMITER_U16 u'/'
	#define SHINSEI_PATH_URL_DELIMITER_U32 U'/'
	#if defined(_SHINSEI_OS_WINDOWS)
		#define SHINSEI_PATH_URL_DELIMITER_N SHINSEI_PATH_URL_DELIMITER_W
	#elif defined(_SHINSEI_OS_UNIX)
		#define SHINSEI_PATH_URL_DELIMITER_N SHINSEI_PATH_URL_DELIMITER_U8
	#endif
#endif

#ifdef _SHINSEI_OS_CPP
extern "C" {
#endif

_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterA(const char ch);
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterW(const wchar_t ch);
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterU8(const char8_t ch);
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterU8S(const char8_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterU16(const char16_t ch);
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterU16S(const char16_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterA(const char ch);
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterW(const wchar_t ch);
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterU8(const char8_t ch);
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterU8S(const char8_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterU16(const char16_t ch);
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterU16S(const char16_t**restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharA(const char ch);
_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharW(const wchar_t ch);
_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharU8(const char8_t ch);
_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalChaoU8S(const char8_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharU16(const char16_t ch);
_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalChaoU16S(const char16_t**const restrict str_ptr,const size_t len);
_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharU32(const char32_t ch);

_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharA(const char ch);
_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharW(const wchar_t ch);
_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharU8(const char8_t ch);
_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharU8S(const char8_t ch);
_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharU16(const char16_t ch);
_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharU16S(const char16_t ch);
_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharU32(const char32_t ch);

_SHINSEI_LIB_API int shinsei_windowsPathNormalizeA(char*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_windowsPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len);

_SHINSEI_LIB_API int shinsei_unixPathNormalizeA(char*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_unixPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_unixPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_unixPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_unixPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len);
#if defined(_SHINSEI_OS_WINDOWS)
_SHINSEI_LIB_API int shinsei_unixPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len);
#elif defined(_SHINSEI_OS_UNIX)
_SHINSEI_LIB_API int shinsei_unixPathNormalizeN(char8_t*const restrict path,size_t*const restrict len);
#endif

_SHINSEI_LIB_API int shinsei_linuxPathNormalizeA(char*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_linuxPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_linuxPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_linuxPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_linuxPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len);
#if defined(_SHINSEI_OS_WINDOWS)
_SHINSEI_LIB_API int shinsei_linuxPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len);
#elif defined(_SHINSEI_OS_UNIX)
_SHINSEI_LIB_API int shinsei_linuxPathNormalizeN(char8_t*const restrict path,size_t*const restrict len);
#endif

_SHINSEI_LIB_API int shinsei_applePathNormalizeA(char*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_applePathNormalizeW(wchar_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_applePathNormalizeU8(char8_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_applePathNormalizeU16(char16_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_applePathNormalizeU32(char32_t*const restrict path,size_t*const restrict len);
#if defined(_SHINSEI_OS_WINDOWS)
_SHINSEI_LIB_API int shinsei_applePathNormalizeN(wchar_t*const restrict path,size_t*const restrict len);
#elif defined(_SHINSEI_OS_UNIX)
_SHINSEI_LIB_API int shinsei_applePathNormalizeN(char8_t*const restrict path,size_t*const restrict len);
#endif

_SHINSEI_LIB_API int shinsei_sunPathNormalizeA(char*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_sunPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_sunPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_sunPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_sunPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len);
#if defined(_SHINSEI_OS_WINDOWS)
_SHINSEI_LIB_API int shinsei_sunPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len);
#elif defined(_SHINSEI_OS_UNIX)
_SHINSEI_LIB_API int shinsei_sunPathNormalizeN(char8_t*const restrict path,size_t*const restrict len);
#endif

_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeA(char*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len);
#if defined(_SHINSEI_OS_WINDOWS)
_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len);
#elif defined(_SHINSEI_OS_UNIX)
_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeN(char8_t*const restrict path,size_t*const restrict len);
#endif

_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeA(char*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len);
#if defined(_SHINSEI_OS_WINDOWS)
_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len);
#elif defined(_SHINSEI_OS_UNIX)
_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeN(char8_t*const restrict path,size_t*const restrict len);
#endif

_SHINSEI_LIB_API int shinsei_nativePathNormalizeA(char*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_nativePathNormalizeW(wchar_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_nativePathNormalizeU8(char8_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_nativePathNormalizeU16(char16_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_nativePathNormalizeU32(char32_t*const restrict path,size_t*const restrict len);
#if defined(_SHINSEI_OS_WINDOWS)
_SHINSEI_LIB_API int shinsei_nativePathNormalizeN(wchar_t*const restrict path,size_t*const restrict len);
#elif defined(_SHINSEI_OS_UNIX)
_SHINSEI_LIB_API int shinsei_nativePathNormalizeN(char8_t*const restrict path,size_t*const restrict len);
#endif

_SHINSEI_LIB_API int shinsei_uRLPathNormalizeA(char*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_uRLPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_uRLPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_uRLPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_uRLPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len);
#if defined(_SHINSEI_OS_WINDOWS)
_SHINSEI_LIB_API int shinsei_uRLPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len);
#elif defined(_SHINSEI_OS_UNIX)
_SHINSEI_LIB_API int shinsei_uRLPathNormalizeN(char8_t*const restrict path,size_t*const restrict len);
#endif

_SHINSEI_LIB_API size_t shinsei_windowsPathJoinA(char*const restrict buf,const size_t buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...);
_SHINSEI_LIB_API size_t shinsei_windowsPathJoinW(wchar_t*const restrict buf,const size_t buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...);

_SHINSEI_LIB_API size_t shinsei_linuxPathJoinA(char*const restrict buf,const size_t buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...);
_SHINSEI_LIB_API size_t shinsei_linuxPathJoinW(wchar_t*const restrict buf,const size_t buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...);

_SHINSEI_LIB_API size_t shinsei_splitStrToWindowsPathA(char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt);
_SHINSEI_LIB_API size_t shinsei_splitStrToWindowsPathW(wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt);

_SHINSEI_LIB_API size_t shinsei_splitStrToLinuxPathA(char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt);
_SHINSEI_LIB_API size_t shinsei_splitStrToLinuxPathW(wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt);

#ifdef _SHINSEI_OS_CPP
}
#endif
#pragma once

#include"shinsei/minimal/path.h"
#include"shinsei/.internal/std.h"

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

#ifdef _SHINSEI_OS_CONSTEXPR
	#if defined(_SHINSEI_OS_WINDOWS)
		static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_WINDOWS_DELIMITER_N=SHINSEI_PATH_WINDOWS_DELIMITER_W;
	#elif defined(_SHINSEI_OS_UNIX)
		static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_WINDOWS_DELIMITER_N=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
	#endif
	
	#if defined(_SHINSEI_OS_WINDOWS)
		static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_UNIX_DELIMITER_N=SHINSEI_PATH_UNIX_DELIMITER_W;
	#elif defined(_SHINSEI_OS_UNIX)
		static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_UNIX_DELIMITER_N=SHINSEI_PATH_UNIX_DELIMITER_U8;
	#endif
	
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_LINUX_DELIMITER_N=SHINSEI_PATH_UNIX_DELIMITER_N;
	
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_APPLE_DELIMITER_N=SHINSEI_PATH_UNIX_DELIMITER_N;
	
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_SUN_DELIMITER_N=SHINSEI_PATH_UNIX_DELIMITER_N;
	
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_FREEBSD_DELIMITER_N=SHINSEI_PATH_UNIX_DELIMITER_N;
	
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_CYGWIN_DELIMITER_N=SHINSEI_PATH_UNIX_DELIMITER_N;
	
	#if defined(_SHINSEI_OS_WINDOWS)
		static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_URL_DELIMITER_N=SHINSEI_PATH_URL_DELIMITER_W;
	#elif defined(_SHINSEI_OS_UNIX)
		static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_URL_DELIMITER_N=SHINSEI_PATH_URL_DELIMITER_U8;
	#endif
	
#else
	#if defined(_SHINSEI_OS_WINDOWS)
		#define SHINSEI_PATH_WINDOWS_DELIMITER_N SHINSEI_PATH_WINDOWS_DELIMITER_W
	#elif defined(_SHINSEI_OS_UNIX)
		#define SHINSEI_PATH_WINDOWS_DELIMITER_N SHINSEI_PATH_WINDOWS_DELIMITER_U8
	#endif
	
	#if defined(_SHINSEI_OS_WINDOWS)
		#define SHINSEI_PATH_UNIX_DELIMITER_N SHINSEI_PATH_UNIX_DELIMITER_W
	#elif defined(_SHINSEI_OS_UNIX)
		#define SHINSEI_PATH_UNIX_DELIMITER_N SHINSEI_PATH_UNIX_DELIMITER_U8
	#endif
	
	#define SHINSEI_PATH_LINUX_DELIMITER_N SHINSEI_PATH_UNIX_DELIMITER_N
	
	#define SHINSEI_PATH_APPLE_DELIMITER_N SHINSEI_PATH_UNIX_DELIMITER_N
	
	#define SHINSEI_PATH_SUN_DELIMITER_N SHINSEI_PATH_UNIX_DELIMITER_N
	
	#define SHINSEI_PATH_FREEBSD_DELIMITER_N SHINSEI_PATH_UNIX_DELIMITER_N
	
	#define SHINSEI_PATH_CYGWIN_DELIMITER_N SHINSEI_PATH_UNIX_DELIMITER_N
	
	#if defined(_SHINSEI_OS_WINDOWS)
		#define SHINSEI_PATH_URL_DELIMITER_N SHINSEI_PATH_URL_DELIMITER_W
	#elif defined(_SHINSEI_OS_UNIX)
		#define SHINSEI_PATH_URL_DELIMITER_N SHINSEI_PATH_URL_DELIMITER_U8
	#endif
	
#endif

_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isUnixPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isApplePathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isSunPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isFreeBSDPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isCygwinPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isNativePathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathDelimiterCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathDelimiterCPM(const unsigned int code_page,const char**const restrict str_ptr,const size_t len,int*const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isURLPathDelimiterA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathDelimiterAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isUnixPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUnixPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isApplePathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isApplePathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isSunPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSunPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isFreeBSDPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isFreeBSDPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isCygwinPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCygwinPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isNativePathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathIllegalCharCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathIllegalCharCPM(const unsigned int code_page,const char**const restrict str_ptr,const size_t len,int*const restrict status)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isNativePathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isURLPathIllegalCharA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isURLPathIllegalCharAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_windowsPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_unixPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_linuxPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_applePathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_sunPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_nativePathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_nativePathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_nativePathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_nativePathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_nativePathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_nativePathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_uRLPathNormalizeA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_windowsPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_unixPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_linuxPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_applePathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_sunPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_nativePathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_nativePathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_nativePathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_nativePathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_nativePathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_nativePathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_uRLPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_getUserDataPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,shinsei_nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_getUserDataPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,shinsei_nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_getUserDataPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,shinsei_nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_getUserDataPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,shinsei_nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_getSystemApplicationPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,shinsei_nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_getSystemApplicationPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,shinsei_nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_getSystemApplicationPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,shinsei_nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_getSystemApplicationPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,shinsei_nchar_t*const restrict convert_buf,const size_t convert_buf_len)_SHINSEI_OS_NOEXCEPT;
// Windows
_SHINSEI_LIB_API size_t shinsei_windowsPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_windowsPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;

// Unix
_SHINSEI_LIB_API size_t shinsei_unixPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_unixPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;

// Linux
_SHINSEI_LIB_API size_t shinsei_linuxPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_linuxPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;

// Apple
_SHINSEI_LIB_API size_t shinsei_applePathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_applePathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;

// Sun
_SHINSEI_LIB_API size_t shinsei_sunPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_sunPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;

// FreeBSD
_SHINSEI_LIB_API size_t shinsei_freeBSDPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_freeBSDPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;

// Cygwin
_SHINSEI_LIB_API size_t shinsei_cygwinPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_cygwinPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;

// URL
_SHINSEI_LIB_API size_t shinsei_uRLPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uRLPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToWindowsPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToUnixPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToLinuxPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToApplePathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToSunPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToFreeBSDPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToCygwinPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToURLPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToNativePathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToNativePathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToNativePathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToNativePathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToNativePathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_splitStringToNativePathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;

#ifdef _SHINSEI_OS_WINDOWS
	_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isUnixPathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isUnixPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isApplePathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isApplePathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isSunPathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isSunPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isFreeBSDPathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isFreeBSDPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isCygwinPathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isCygwinPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isNativePathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isNativePathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isURLPathDelimiterN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isURLPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isUnixPathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isUnixPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isApplePathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isApplePathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isSunPathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isSunPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isFreeBSDPathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isFreeBSDPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isCygwinPathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isCygwinPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isNativePathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isNativePathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isURLPathIllegalCharN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isURLPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_windowsPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_unixPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_linuxPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_applePathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_sunPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_nativePathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_uRLPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_windowsPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_unixPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_linuxPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_applePathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_sunPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_nativePathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_uRLPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_getUserDataPathN(wchar_t*const restrict des_buf,const size_t des_buf_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_getSystemApplicationPathN(wchar_t*const restrict des_buf,const size_t des_buf_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_windowsPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_windowsPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_unixPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_unixPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_linuxPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_linuxPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_applePathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_applePathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_sunPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_sunPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_freeBSDPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_freeBSDPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_cygwinPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_cygwinPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_uRLPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uRLPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToWindowsPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToUnixPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToLinuxPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToApplePathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToSunPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToFreeBSDPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToCygwinPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToURLPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToNativePathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
#elif defined(_SHINSEI_OS_UNIX)
	_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isUnixPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isUnixPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isLinuxPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isApplePathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isApplePathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isSunPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isSunPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isFreeBSDPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isFreeBSDPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isCygwinPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isCygwinPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isNativePathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isNativePathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isURLPathDelimiterN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isURLPathDelimiterNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isWindowsPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isUnixPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isUnixPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isLinuxPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isApplePathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isApplePathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isSunPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isSunPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isFreeBSDPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isFreeBSDPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isCygwinPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isCygwinPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isNativePathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isNativePathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isURLPathIllegalCharN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isURLPathIllegalCharNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_windowsPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_unixPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_linuxPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_applePathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_sunPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_nativePathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_uRLPathNormalizeN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_windowsPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_unixPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_linuxPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_applePathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_sunPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_freeBSDPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_cygwinPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_nativePathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_uRLPathNormalizeNoTraversalN(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_getUserDataPathN(char8_t*const restrict des_buf,const size_t des_buf_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_getSystemApplicationPathN(char8_t*const restrict des_buf,const size_t des_buf_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_windowsPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_windowsPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_unixPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_unixPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_linuxPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_linuxPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_applePathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_applePathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_sunPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_sunPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_freeBSDPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_freeBSDPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_cygwinPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_cygwinPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_uRLPathJoinNV(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uRLPathJoinN(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToWindowsPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToUnixPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToLinuxPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToApplePathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToSunPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToFreeBSDPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToCygwinPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToURLPathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToNativePathN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT;
	
#endif

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif
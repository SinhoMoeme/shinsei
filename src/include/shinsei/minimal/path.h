#pragma once

#include"shinsei/.internal/usage.h"
#include"shinsei/str.h"

#ifdef _SHINSEI_OS_CONSTEXPR
	static _SHINSEI_OS_CONSTEXPR int SHINSEI_PATH_ILLEGAL=0;
	static _SHINSEI_OS_CONSTEXPR int SHINSEI_PATH_ABSOLUTE=1;
	static _SHINSEI_OS_CONSTEXPR int SHINSEI_PATH_RELATIVE=2;
	static _SHINSEI_OS_CONSTEXPR int SHINSEI_PATH_NETWORK=3;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_PATH_WINDOWS_MAX_LEGACY=260;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_PATH_WINDOWS_MAX=32767;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_PATH_UNIX_MAX=4096;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_PATH_LINUX_MAX=SHINSEI_PATH_UNIX_MAX;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_PATH_SBO_CNT=4;
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_PATH_MINIMAL=32;
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_WINDOWS_DELIMITER_A='\\';
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_WINDOWS_DELIMITER_W=L'\\';
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_WINDOWS_DELIMITER_U8=u8'\\';
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_WINDOWS_DELIMITER_U16=u'\\';
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_WINDOWS_DELIMITER_U32=U'\\';
	static _SHINSEI_OS_CONSTEXPR char SHINSEI_PATH_LINUX_DELIMITER_A='/';
	static _SHINSEI_OS_CONSTEXPR wchar_t SHINSEI_PATH_LINUX_DELIMITER_W=L'/';
	static _SHINSEI_OS_CONSTEXPR char8_t SHINSEI_PATH_LINUX_DELIMITER_U8=u8'/';
	static _SHINSEI_OS_CONSTEXPR char16_t SHINSEI_PATH_LINUX_DELIMITER_U16=u'/';
	static _SHINSEI_OS_CONSTEXPR char32_t SHINSEI_PATH_LINUX_DELIMITER_U32=U'/';
#else
	#define SHINSEI_PATH_ILLEGAL 0
	#define SHINSEI_PATH_ABSOLUTE 1
	#define SHINSEI_PATH_RELATIVE 2
	#define SHINSEI_PATH_NETWORK 3
	#define SHINSEI_PATH_WINDOWS_MAX_LEGACY (size_t)260
	#define SHINSEI_PATH_WINDOWS_MAX (size_t)32767
	#define SHINSEI_PATH_UNIX_MAX (size_t)4096
	#define SHINSEI_PATH_LINUX_MAX SHINSEI_PATH_UNIX_MAX
	#define SHINSEI_PATH_SBO_CNT (size_t)4
	#define SHINSEI_PATH_MINIMAL (size_t)32
	#define SHINSEI_PATH_WINDOWS_DELIMITER_A '\\'
	#define SHINSEI_PATH_WINDOWS_DELIMITER_W L'\\'
	#define SHINSEI_PATH_WINDOWS_DELIMITER_U8 u8'\\'
	#define SHINSEI_PATH_WINDOWS_DELIMITER_U16 u'\\'
	#define SHINSEI_PATH_WINDOWS_DELIMITER_U32 U'\\'
	#define SHINSEI_PATH_LINUX_DELIMITER_A '/'
	#define SHINSEI_PATH_LINUX_DELIMITER_W L'/'
	#define SHINSEI_PATH_LINUX_DELIMITER_U8 u8'/'
	#define SHINSEI_PATH_LINUX_DELIMITER_U16 u'/'
	#define SHINSEI_PATH_LINUX_DELIMITER_U32 U'/'
#endif

#ifdef _SHINSEI_OS_CPP
extern "C" {
#endif

_SHINSEI_LIB_API bool shinsei_isWindowsPathDelimiterA(const int ch);
bool shinsei_isWindowsPathDelimiterW(const wint_t ch);
bool shinsei_isWindowsPathDelimiterU8S(const char8_t**const restrict str_ptr,const size_t len);
bool shinsei_isWindowsPathDelimiterU16S(const char16_t**const restrict str_ptr,const size_t len);
bool shinsei_isWindowsPathDelimiterU32(const char32_t ch);

bool shinsei_isLinuxPathDelimiterA(const int ch);
bool shinsei_isLinuxPathDelimiterW(const wint_t ch);
bool shinsei_isLinuxPathDelimiterU8S(const char8_t**const restrict str_ptr,const size_t len);
bool shinsei_isLinuxPathDelimiterU16S(const char16_t**const restrict str_ptr,const size_t len);
bool shinsei_isLinuxPathDelimiterU32(const char32_t ch);

bool shinsei_isWindowsPathIllegalCharA(const int ch);
bool shinsei_isWindowsPathIllegalCharW(const wint_t ch);
bool shinsei_isWindowsPathIllegalCharU8(const char8_t ch);
bool shinsei_isWindowsPathIllegalCharU16(const char16_t ch);
bool shinsei_isWindowsPathIllegalCharU32(const char32_t ch);

bool shinsei_isLinuxPathIllegalCharA(const int ch);
bool shinsei_isLinuxPathIllegalCharW(const wint_t ch);
bool shinsei_isLinuxPathIllegalCharU8(const char8_t ch);
bool shinsei_isLinuxPathIllegalCharU16(const char16_t ch);
bool shinsei_isLinuxPathIllegalCharU32(const char32_t ch);

_SHINSEI_LIB_API int shinsei_windowsPathNormalizeA(char*const restrict path,size_t*const restrict len);
_SHINSEI_LIB_API int shinsei_windowsPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len);

_SHINSEI_LIB_API int shinsei_linuxPathNormalizeA(char* path,size_t* len);
_SHINSEI_LIB_API int shinsei_linuxPathNormalizeW(wchar_t* path,size_t* len);

_SHINSEI_LIB_API size_t shinsei_windowsPathJoinA(char*const restrict buf,const size_t buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...);
_SHINSEI_LIB_API size_t shinsei_windowsPathJoinW(wchar_t*const restrict buf,const size_t buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...);
_SHINSEI_LIB_API size_t shinsei_linuxPathJoinA(char*const restrict buf,const size_t buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...);
_SHINSEI_LIB_API size_t shinsei_linuxPathJoinW(wchar_t*const restrict buf,const size_t buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...);

_SHINSEI_LIB_API size_t shinsei_splitHashToWindowsPathA(char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt);
_SHINSEI_LIB_API size_t shinsei_splitHashToWindowsPathW(wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt);

_SHINSEI_LIB_API size_t shinsei_splitHashToLinuxPathA(char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt);
_SHINSEI_LIB_API size_t shinsei_splitHashToLinuxPathW(wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt);

#ifdef _SHINSEI_OS_CPP
}
#endif
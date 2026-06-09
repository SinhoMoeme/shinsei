#pragma once

#include"shinsei/minimal/file.h"
#include"shinsei/.internal/std.h"
#include"shinsei/.internal/wchar.h"
#include<uchar.h>
#ifdef _SHINSEI_OS_UNIX
	#include<sys/stat.h>
	#include<sys/types.h>
	#include<fcntl.h>
	#include<pwd.h>
	#ifndef _SHINSEI_OS_ATOMIC
		#include<pthread.h>
	#endif
#elif defined(_SHINSEI_OS_WINDOWS)
	#include<aclapi.h>
#endif

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

typedef struct _SHINSEI_OS_ALIGN_BYTE{
	int_fast32_t ctrl;
	void* ptr;
}shinsei_file_t;

// Path APIs (W, U8, U16, U32)
_SHINSEI_LIB_API int shinsei_isFileExistingW(const wchar_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_isFileExistingU8(const char8_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_isFileExistingU16(const char16_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_isFileExistingU32(const char32_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_createDirectoryW(const wchar_t*const restrict path,const size_t len,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_createDirectoryU8(const char8_t*const restrict path,const size_t len,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_createDirectoryU16(const char16_t*const restrict path,const size_t len,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_createDirectoryU32(const char32_t*const restrict path,const size_t len,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_createDirectoriesW(wchar_t*const restrict path,const size_t len,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_createDirectoriesU8(char8_t*const restrict path,const size_t len,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_createDirectoriesU16(char16_t*const restrict path,const size_t len,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_createDirectoriesU32(char32_t*const restrict path,const size_t len,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int_fast64_t shinsei_getAccessTimeW(const wchar_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast64_t shinsei_getAccessTimeU8(const char8_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast64_t shinsei_getAccessTimeU16(const char16_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast64_t shinsei_getAccessTimeU32(const char32_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int_fast64_t shinsei_getModifyTimeW(const wchar_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast64_t shinsei_getModifyTimeU8(const char8_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast64_t shinsei_getModifyTimeU16(const char16_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast64_t shinsei_getModifyTimeU32(const char32_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int_fast64_t shinsei_getCreateTimeW(const wchar_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast64_t shinsei_getCreateTimeU8(const char8_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast64_t shinsei_getCreateTimeU16(const char16_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast64_t shinsei_getCreateTimeU32(const char32_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_moveFileW(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_moveFileU8(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_moveFileU16(const char16_t*const restrict des,const size_t des_len,const char16_t*const restrict src,const size_t src_len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_moveFileU32(const char32_t*const restrict des,const size_t des_len,const char32_t*const restrict src,const size_t src_len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API uint_fast64_t shinsei_getFileSizeW(const wchar_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast64_t shinsei_getFileSizeU8(const char8_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast64_t shinsei_getFileSizeU16(const char16_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast64_t shinsei_getFileSizeU32(const char32_t*const restrict path,const size_t len,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;

#ifdef _SHINSEI_OS_WINDOWS
	_SHINSEI_LIB_API int shinsei_isFileExistingN(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_createDirectoryN(const wchar_t*const restrict path,const size_t len,int owner)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_createDirectoriesN(wchar_t*const restrict path,const size_t len,int owner)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast64_t shinsei_getAccessTimeN(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast64_t shinsei_getModifyTimeN(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast64_t shinsei_getCreateTimeN(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_moveFileN(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast64_t shinsei_getFileSizeN(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT;
#elif defined(_SHINSEI_OS_UNIX)
	_SHINSEI_LIB_API int shinsei_isFileExistingN(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_createDirectoryN(const char8_t*const restrict path,const size_t len,int owner)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_createDirectoriesN(char8_t*const restrict path,const size_t len,int owner)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast64_t shinsei_getAccessTimeN(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast64_t shinsei_getModifyTimeN(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast64_t shinsei_getCreateTimeN(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_moveFileN(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast64_t shinsei_getFileSizeN(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT;
#endif

// File Constructors (W, U8, U16, U32)
_SHINSEI_LIB_API shinsei_file_t* shinsei_file_t_conW(const wchar_t*const restrict path,const size_t len,int open_mode,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_file_t* shinsei_file_t_conU8(const char8_t*const restrict path,const size_t len,int open_mode,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_file_t* shinsei_file_t_conU16(const char16_t*const restrict path,const size_t len,int open_mode,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_file_t* shinsei_file_t_conU32(const char32_t*const restrict path,const size_t len,int open_mode,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_file_t_asW(shinsei_file_t*const restrict this,const wchar_t*const restrict path,const size_t len,int open_mode,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_file_t_asU8(shinsei_file_t*const restrict this,const char8_t*const restrict path,const size_t len,int open_mode,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_file_t_asU16(shinsei_file_t*const restrict this,const char16_t*const restrict path,const size_t len,int open_mode,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_file_t_asU32(shinsei_file_t*const restrict this,const char32_t*const restrict path,const size_t len,int open_mode,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_file_t_inlW(shinsei_file_t*const restrict this,const wchar_t*const restrict path,const size_t len,int open_mode,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_file_t_inlU8(shinsei_file_t*const restrict this,const char8_t*const restrict path,const size_t len,int open_mode,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_file_t_inlU16(shinsei_file_t*const restrict this,const char16_t*const restrict path,const size_t len,int open_mode,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_file_t_inlU32(shinsei_file_t*const restrict this,const char32_t*const restrict path,const size_t len,int open_mode,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_file_t_openW(shinsei_file_t*const restrict this,const wchar_t*const restrict path,const size_t len,int open_mode,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_file_t_openU8(shinsei_file_t*const restrict this,const char8_t*const restrict path,const size_t len,int open_mode,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_file_t_openU16(shinsei_file_t*const restrict this,const char16_t*const restrict path,const size_t len,int open_mode,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_file_t_openU32(shinsei_file_t*const restrict this,const char32_t*const restrict path,const size_t len,int open_mode,int owner,shinsei_nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len)_SHINSEI_OS_NOEXCEPT;

// File Constructors (N)
#ifdef _SHINSEI_OS_WINDOWS
	_SHINSEI_LIB_API shinsei_file_t* shinsei_file_t_conN(const wchar_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_file_t_asN(shinsei_file_t*const restrict this,const wchar_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_file_t_inlN(shinsei_file_t*const restrict this,const wchar_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_file_t_openN(shinsei_file_t*const restrict this,const wchar_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT;
#elif defined(_SHINSEI_OS_UNIX)
	_SHINSEI_LIB_API shinsei_file_t* shinsei_file_t_conN(const char8_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_file_t_asN(shinsei_file_t*const restrict this,const char8_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_file_t_inlN(shinsei_file_t*const restrict this,const char8_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_file_t_openN(shinsei_file_t*const restrict this,const char8_t*const restrict path,const size_t len,int open_mode,int owner)_SHINSEI_OS_NOEXCEPT;
#endif

// Common Object & IO Operations
_SHINSEI_LIB_API void shinsei_file_t_dec(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_file_t_inlined(const shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_file_t_getCtrl(const shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_file_t_setCtrl(shinsei_file_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_file_t_isOpened(const shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_file_t_read(shinsei_file_t*const restrict this,void*const restrict buf,size_t size,size_t cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_file_t_write(shinsei_file_t*const restrict this,const void*const restrict buf,size_t size,size_t cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast64_t shinsei_file_t_tell(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_file_t_seek(shinsei_file_t*const restrict this,int_fast64_t offset,int origin)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_file_t_rewind(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_file_t_flush(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_file_t_getChar(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_file_t_putChar(shinsei_file_t*const restrict this,int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_file_t_close(shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast64_t shinsei_file_t_getSize(const shinsei_file_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif
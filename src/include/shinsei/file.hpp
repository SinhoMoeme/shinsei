#pragma once

#include"shinsei/file.h"
#include"shinsei/minimal/file.hpp"
#include"shinsei/.internal/tag.hpp"
#include<new>

namespace shinsei{
	// Path API Wrappers: isFileExisting
	_SHINSEI_OS_INLINE int isFileExistingW(const wchar_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFileExistingW(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int isFileExisting(const wchar_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFileExistingW(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int isFileExistingU8(const char8_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFileExistingU8(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int isFileExisting(const char8_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFileExistingU8(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int isFileExistingU16(const char16_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFileExistingU16(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int isFileExisting(const char16_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFileExistingU16(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int isFileExistingU32(const char32_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFileExistingU32(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int isFileExisting(const char32_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isFileExistingU32(path,len,cvt_buf,cvt_len,needed_len);
	}
	
	// Path API Wrappers: createDirectory
	_SHINSEI_OS_INLINE bool createDirectoryW(const wchar_t*const restrict path,const size_t len,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_createDirectoryW(path,len,owner,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool createDirectory(const wchar_t*const restrict path,const size_t len,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_createDirectoryW(path,len,owner,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool createDirectoryU8(const char8_t*const restrict path,const size_t len,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_createDirectoryU8(path,len,owner,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool createDirectory(const char8_t*const restrict path,const size_t len,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_createDirectoryU8(path,len,owner,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool createDirectoryU16(const char16_t*const restrict path,const size_t len,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_createDirectoryU16(path,len,owner,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool createDirectory(const char16_t*const restrict path,const size_t len,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_createDirectoryU16(path,len,owner,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool createDirectoryU32(const char32_t*const restrict path,const size_t len,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_createDirectoryU32(path,len,owner,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool createDirectory(const char32_t*const restrict path,const size_t len,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_createDirectoryU32(path,len,owner,cvt_buf,cvt_len,needed_len);
	}
	
	// Path API Wrappers: createDirectories
	_SHINSEI_OS_INLINE bool createDirectoriesW(wchar_t*const restrict path,const size_t len,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_createDirectoriesW(path,len,owner,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool createDirectories(wchar_t*const restrict path,const size_t len,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_createDirectoriesW(path,len,owner,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool createDirectoriesU8(char8_t*const restrict path,const size_t len,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_createDirectoriesU8(path,len,owner,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool createDirectories(char8_t*const restrict path,const size_t len,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_createDirectoriesU8(path,len,owner,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool createDirectoriesU16(char16_t*const restrict path,const size_t len,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_createDirectoriesU16(path,len,owner,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool createDirectories(char16_t*const restrict path,const size_t len,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_createDirectoriesU16(path,len,owner,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool createDirectoriesU32(char32_t*const restrict path,const size_t len,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_createDirectoriesU32(path,len,owner,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool createDirectories(char32_t*const restrict path,const size_t len,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_createDirectoriesU32(path,len,owner,cvt_buf,cvt_len,needed_len);
	}
	
	// Path API Wrappers: getAccessTime
	_SHINSEI_OS_INLINE int_fast64_t getAccessTimeW(const wchar_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getAccessTimeW(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getAccessTime(const wchar_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getAccessTimeW(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getAccessTimeU8(const char8_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getAccessTimeU8(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getAccessTime(const char8_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getAccessTimeU8(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getAccessTimeU16(const char16_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getAccessTimeU16(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getAccessTime(const char16_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getAccessTimeU16(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getAccessTimeU32(const char32_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getAccessTimeU32(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getAccessTime(const char32_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getAccessTimeU32(path,len,cvt_buf,cvt_len,needed_len);
	}

	// Path API Wrappers: getModifyTime
	_SHINSEI_OS_INLINE int_fast64_t getModifyTimeW(const wchar_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getModifyTimeW(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getModifyTime(const wchar_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getModifyTimeW(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getModifyTimeU8(const char8_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getModifyTimeU8(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getModifyTime(const char8_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getModifyTimeU8(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getModifyTimeU16(const char16_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getModifyTimeU16(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getModifyTime(const char16_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getModifyTimeU16(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getModifyTimeU32(const char32_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getModifyTimeU32(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getModifyTime(const char32_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getModifyTimeU32(path,len,cvt_buf,cvt_len,needed_len);
	}
	
	// Path API Wrappers: getCreateTime
	_SHINSEI_OS_INLINE int_fast64_t getCreateTimeW(const wchar_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getCreateTimeW(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getCreateTime(const wchar_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getCreateTimeW(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getCreateTimeU8(const char8_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getCreateTimeU8(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getCreateTime(const char8_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getCreateTimeU8(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getCreateTimeU16(const char16_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getCreateTimeU16(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getCreateTime(const char16_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getCreateTimeU16(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getCreateTimeU32(const char32_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getCreateTimeU32(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE int_fast64_t getCreateTime(const char32_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getCreateTimeU32(path,len,cvt_buf,cvt_len,needed_len);
	}
	
	// Path API Wrappers: moveFile
	_SHINSEI_OS_INLINE bool moveFileW(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_moveFileW(des,des_len,src,src_len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool moveFile(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_moveFileW(des,des_len,src,src_len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool moveFileU8(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_moveFileU8(des,des_len,src,src_len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool moveFile(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_moveFileU8(des,des_len,src,src_len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool moveFileU16(const char16_t*const restrict des,const size_t des_len,const char16_t*const restrict src,const size_t src_len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_moveFileU16(des,des_len,src,src_len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool moveFile(const char16_t*const restrict des,const size_t des_len,const char16_t*const restrict src,const size_t src_len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_moveFileU16(des,des_len,src,src_len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool moveFileU32(const char32_t*const restrict des,const size_t des_len,const char32_t*const restrict src,const size_t src_len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_moveFileU32(des,des_len,src,src_len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE bool moveFile(const char32_t*const restrict des,const size_t des_len,const char32_t*const restrict src,const size_t src_len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_moveFileU32(des,des_len,src,src_len,cvt_buf,cvt_len,needed_len);
	}
	
	// Path API Wrappers: getFileSize
	_SHINSEI_OS_INLINE uint_fast64_t getFileSizeW(const wchar_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getFileSizeW(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE uint_fast64_t getFileSize(const wchar_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getFileSizeW(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE uint_fast64_t getFileSizeU8(const char8_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getFileSizeU8(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE uint_fast64_t getFileSize(const char8_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getFileSizeU8(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE uint_fast64_t getFileSizeU16(const char16_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getFileSizeU16(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE uint_fast64_t getFileSize(const char16_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getFileSizeU16(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE uint_fast64_t getFileSizeU32(const char32_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getFileSizeU32(path,len,cvt_buf,cvt_len,needed_len);
	}
	_SHINSEI_OS_INLINE uint_fast64_t getFileSize(const char32_t*const restrict path,const size_t len,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_getFileSizeU32(path,len,cvt_buf,cvt_len,needed_len);
	}
	
	// N versions
	#ifdef _SHINSEI_OS_WINDOWS
		_SHINSEI_OS_INLINE int isFileExistingN(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isFileExistingN(path,len);
		}
		_SHINSEI_OS_INLINE int isFileExisting(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isFileExistingN(path,len);
		}
		_SHINSEI_OS_INLINE bool createDirectoryN(const wchar_t*const restrict path,const size_t len,int owner=::SHINSEI_FILE_OWNER_DEFAULT)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_createDirectoryN(path,len,owner);
		}
		_SHINSEI_OS_INLINE bool createDirectory(const wchar_t*const restrict path,const size_t len,int owner=::SHINSEI_FILE_OWNER_DEFAULT)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_createDirectoryN(path,len,owner);
		}
		_SHINSEI_OS_INLINE bool createDirectoriesN(wchar_t*const restrict path,const size_t len,int owner=::SHINSEI_FILE_OWNER_DEFAULT)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_createDirectoriesN(path,len,owner);
		}
		_SHINSEI_OS_INLINE bool createDirectories(wchar_t*const restrict path,const size_t len,int owner=::SHINSEI_FILE_OWNER_DEFAULT)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_createDirectoriesN(path,len,owner);
		}
		
		_SHINSEI_OS_INLINE int_fast64_t getAccessTimeN(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getAccessTimeN(path,len);
		}
		_SHINSEI_OS_INLINE int_fast64_t getAccessTime(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getAccessTimeN(path,len);
		}
		_SHINSEI_OS_INLINE int_fast64_t getModifyTimeN(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getModifyTimeN(path,len);
		}
		_SHINSEI_OS_INLINE int_fast64_t getModifyTime(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getModifyTimeN(path,len);
		}
		_SHINSEI_OS_INLINE int_fast64_t getCreateTimeN(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getCreateTimeN(path,len);
		}
		_SHINSEI_OS_INLINE int_fast64_t getCreateTime(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getCreateTimeN(path,len);
		}
		
		_SHINSEI_OS_INLINE bool moveFileN(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_moveFileN(des,des_len,src,src_len);
		}
		_SHINSEI_OS_INLINE bool moveFile(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_moveFileN(des,des_len,src,src_len);
		}
		
		_SHINSEI_OS_INLINE uint_fast64_t getFileSizeN(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getFileSizeN(path,len);
		}
		_SHINSEI_OS_INLINE uint_fast64_t getFileSize(const wchar_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getFileSizeN(path,len);
		}
		
	#elif defined(_SHINSEI_OS_UNIX)
		_SHINSEI_OS_INLINE int isFileExistingN(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isFileExistingN(path,len);
		}
		_SHINSEI_OS_INLINE int isFileExisting(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isFileExistingN(path,len);
		}
		_SHINSEI_OS_INLINE bool createDirectoryN(const char8_t*const restrict path,const size_t len,int owner=::SHINSEI_FILE_OWNER_DEFAULT)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_createDirectoryN(path,len,owner);
		}
		_SHINSEI_OS_INLINE bool createDirectory(const char8_t*const restrict path,const size_t len,int owner=::SHINSEI_FILE_OWNER_DEFAULT)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_createDirectoryN(path,len,owner);
		}
		_SHINSEI_OS_INLINE bool createDirectoriesN(char8_t*const restrict path,const size_t len,int owner=::SHINSEI_FILE_OWNER_DEFAULT)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_createDirectoriesN(path,len,owner);
		}
		_SHINSEI_OS_INLINE bool createDirectories(char8_t*const restrict path,const size_t len,int owner=::SHINSEI_FILE_OWNER_DEFAULT)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_createDirectoriesN(path,len,owner);
		}
		
		_SHINSEI_OS_INLINE int_fast64_t getAccessTimeN(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getAccessTimeN(path,len);
		}
		_SHINSEI_OS_INLINE int_fast64_t getAccessTime(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getAccessTimeN(path,len);
		}
		_SHINSEI_OS_INLINE int_fast64_t getModifyTimeN(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getModifyTimeN(path,len);
		}
		_SHINSEI_OS_INLINE int_fast64_t getModifyTime(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getModifyTimeN(path,len);
		}
		_SHINSEI_OS_INLINE int_fast64_t getCreateTimeN(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getCreateTimeN(path,len);
		}
		_SHINSEI_OS_INLINE int_fast64_t getCreateTime(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getCreateTimeN(path,len);
		}
		
		_SHINSEI_OS_INLINE bool moveFileN(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_moveFileN(des,des_len,src,src_len);
		}
		_SHINSEI_OS_INLINE bool moveFile(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_moveFileN(des,des_len,src,src_len);
		}
		
		_SHINSEI_OS_INLINE uint_fast64_t getFileSizeN(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getFileSizeN(path,len);
		}
		_SHINSEI_OS_INLINE uint_fast64_t getFileSize(const char8_t*const restrict path,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_getFileSizeN(path,len);
		}
		
	#endif
	
	class file_t{
	private:
		::shinsei_file_t obj;
		
	public:
		// Constructors (Native)
		file_t(const shinsei_nchar_t*const restrict path=nullptr,const size_t len=0,int open_mode=FILE_OPEN_READ,int owner=FILE_OWNER_DEFAULT){
			if(!::shinsei_file_t_asN(&obj,path,len,open_mode,owner)) throw std::bad_alloc();
			return;
		}
		explicit file_t(shinsei::in_place_t,const shinsei_nchar_t*const restrict path,const size_t len,int open_mode,int owner=::SHINSEI_FILE_OWNER_DEFAULT){
			if(!::shinsei_file_t_asN(&obj,path,len,open_mode,owner)) throw std::bad_alloc();
			return;
		}
		explicit file_t(shinsei::inlined_t,const shinsei_nchar_t*const restrict path,const size_t len,int open_mode,int owner=::SHINSEI_FILE_OWNER_DEFAULT){
			if(!::shinsei_file_t_inlN(&obj,path,len,open_mode,owner)) throw std::bad_alloc();
			return;
		}
		
		// Constructors (Converted)
		file_t(const char8_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_asU8(&obj,path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		explicit file_t(shinsei::in_place_t,const char8_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_asU8(&obj,path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		explicit file_t(shinsei::inlined_t,const char8_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_inlU8(&obj,path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		
		file_t(const char16_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_asU16(&obj,path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		explicit file_t(shinsei::in_place_t,const char16_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_asU16(&obj,path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		explicit file_t(shinsei::inlined_t,const char16_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_inlU16(&obj,path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		
		file_t(const char32_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_asU32(&obj,path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		explicit file_t(shinsei::in_place_t,const char32_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_asU32(&obj,path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		explicit file_t(shinsei::inlined_t,const char32_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_inlU32(&obj,path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		
		file_t(const wchar_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_asW(&obj,path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		explicit file_t(shinsei::in_place_t,const wchar_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_asW(&obj,path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		explicit file_t(shinsei::inlined_t,const wchar_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_inlW(&obj,path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		
		// Destructor
		~file_t()_SHINSEI_OS_NOEXCEPT{
			if(isOpened()) close();
			return;
		}
		
		// Disable Copy & Move
		file_t(const file_t&)=delete;
		file_t(file_t&&)=delete;
		file_t& operator=(const file_t&)=delete;
		file_t& operator=(file_t&&)=delete;
		
		// IO Operations
		bool isOpened()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_file_t_isOpened(&obj);
		}
		size_t read(void*const restrict buf,size_t size,size_t cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_file_t_read(&obj,buf,size,cnt);
		}
		size_t write(const void*const restrict buf,size_t size,size_t cnt)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_file_t_write(&obj,buf,size,cnt);
		}
		uint_fast64_t tell()_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_file_t_tell(&obj);
		}
		bool seek(int_fast64_t offset,int origin)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_file_t_seek(&obj,offset,origin);
		}
		void rewind()_SHINSEI_OS_NOEXCEPT{
			::shinsei_file_t_rewind(&obj);
			return;
		}
		bool flush()_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_file_t_flush(&obj);
		}
		int getChar()_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_file_t_getChar(&obj);
		}
		bool putChar(int ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_file_t_putChar(&obj,ch);
		}
		void close()_SHINSEI_OS_NOEXCEPT{
			::shinsei_file_t_close(&obj);
			return;
		}
		
		uint_fast64_t getSize()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_file_t_getSize(&obj);
		}
		
		// Open API Wrappers
		bool open(const shinsei_nchar_t*const restrict path,const size_t len,int open_mode,int owner=::SHINSEI_FILE_OWNER_DEFAULT)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_file_t_openN(&obj,path,len,open_mode,owner);
		}
		bool open(const char8_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_file_t_openU8(&obj,path,len,open_mode,owner,cvt_buf,cvt_len,needed_len);
		}
		bool open(const char16_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_file_t_openU16(&obj,path,len,open_mode,owner,cvt_buf,cvt_len,needed_len);
		}
		bool open(const char32_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_file_t_openU32(&obj,path,len,open_mode,owner,cvt_buf,cvt_len,needed_len);
		}
		bool open(const wchar_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_file_t_openW(&obj,path,len,open_mode,owner,cvt_buf,cvt_len,needed_len);
		}
		
		// Static Helpers
		static void as(file_t*const restrict ptr,const shinsei_nchar_t*const restrict path,const size_t len,int open_mode,int owner=::SHINSEI_FILE_OWNER_DEFAULT){
			if(!::shinsei_file_t_asN(ptr->cObj(),path,len,open_mode,owner)) throw std::bad_alloc();
			return;
		}
		static void as(file_t*const restrict ptr,const char8_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_asU8(ptr->cObj(),path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		static void as(file_t*const restrict ptr,const char16_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_asU16(ptr->cObj(),path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		static void as(file_t*const restrict ptr,const char32_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_asU32(ptr->cObj(),path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		static void as(file_t*const restrict ptr,const wchar_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_asW(ptr->cObj(),path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		
		static void inl(file_t*const restrict ptr,const shinsei_nchar_t*const restrict path,const size_t len,int open_mode,int owner=::SHINSEI_FILE_OWNER_DEFAULT){
			if(!::shinsei_file_t_inlN(ptr->cObj(),path,len,open_mode,owner)) throw std::bad_alloc();
			return;
		}
		static void inl(file_t*const restrict ptr,const char8_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_inlU8(ptr->cObj(),path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		static void inl(file_t*const restrict ptr,const char16_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_inlU16(ptr->cObj(),path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		static void inl(file_t*const restrict ptr,const char32_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_inlU32(ptr->cObj(),path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		static void inl(file_t*const restrict ptr,const wchar_t*const restrict path,const size_t len,int open_mode,int owner,nchar_t*const restrict cvt_buf,const size_t cvt_len,size_t*const restrict needed_len=nullptr){
			if(!::shinsei_file_t_inlW(ptr->cObj(),path,len,open_mode,owner,cvt_buf,cvt_len,needed_len)) throw std::bad_alloc();
			return;
		}
		
		// Core Identity Controls
		bool inlined()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_file_t_inlined(&obj);
		}
		int_fast32_t getCtrl()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_file_t_getCtrl(&obj);
		}
		void setCtrl(const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
			::shinsei_file_t_setCtrl(&obj,ctrl);
			return;
		}
		
		// Type Casting / Access
		::shinsei_file_t* cObj()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		const ::shinsei_file_t* cObj()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator ::shinsei_file_t*()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator const ::shinsei_file_t*()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
	};
}
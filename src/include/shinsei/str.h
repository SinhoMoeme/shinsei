#pragma once

#include"shinsei/minimal/str.h"
#include"shinsei/.internal/std.h"

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

_SHINSEI_LIB_API unsigned int shinsei_systemCP()_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_charSizeA(const int starter_ch)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isBDigitA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isBDigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isODigitA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isODigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isDigitA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isDigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isXDigitA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isXDigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isUpperA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isUpperAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isLowerA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isLowerAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isAlphaA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isAlphaAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isAlnumA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isAlnumAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isBlankA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isBlankAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isCntrlA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isCntrlAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isPrintA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isPrintAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isGraphA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isGraphAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isPunctA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isPunctAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isSpaceA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isSpaceAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_isJSONWhitespaceA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_isJSONWhitespaceAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_toUpperA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_toUpperAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_toLowerA(const int ch)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int shinsei_toLowerAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_isHexColorA(const char*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_stringLinesA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_findStringsA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_splitStringToPartsA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char delimiter)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_strLenA(const char*const restrict str)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_strCpyA(char*const restrict des,const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_strCatA(char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int shinsei_strCmpA(const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_strChrA(const char*const restrict des,const size_t des_len,const char src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_strStrA(const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_strKMPA(const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT;

// Int8/UInt8 string converters (A)
_SHINSEI_LIB_API size_t shinsei_uInt8ToStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt8ToBinStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt8ToOctStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt8ToHexStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt8ToBase36StringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt8ToBase62StringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_int8ToStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int8ToBinStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int8ToOctStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int8ToHexStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int8ToBase36StringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int8ToBase62StringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;

// Int16/UInt16 string converters (A)
_SHINSEI_LIB_API size_t shinsei_uInt16ToStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt16ToBinStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt16ToOctStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt16ToHexStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt16ToBase36StringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt16ToBase62StringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_int16ToStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int16ToBinStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int16ToOctStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int16ToHexStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int16ToBase36StringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int16ToBase62StringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;

// Int32/UInt32 string converters (A)
_SHINSEI_LIB_API size_t shinsei_uInt32ToStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt32ToBinStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt32ToOctStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt32ToHexStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt32ToBase36StringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt32ToBase62StringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_int32ToStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int32ToBinStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int32ToOctStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int32ToHexStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int32ToBase36StringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int32ToBase62StringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;

// Int64/UInt64 string converters (A)
_SHINSEI_LIB_API size_t shinsei_uInt64ToStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt64ToBinStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt64ToOctStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt64ToHexStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt64ToBase36StringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_uInt64ToBase62StringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_int64ToStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int64ToBinStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int64ToOctStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int64ToHexStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int64ToBase36StringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_int64ToBase62StringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;

// String to int8/uint8 converters (A)
_SHINSEI_LIB_API uint_fast8_t shinsei_stringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast8_t shinsei_binStringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast8_t shinsei_octStringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast8_t shinsei_hexStringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast8_t shinsei_base36StringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast8_t shinsei_base62StringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int_fast8_t shinsei_stringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast8_t shinsei_binStringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast8_t shinsei_octStringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast8_t shinsei_hexStringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast8_t shinsei_base36StringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast8_t shinsei_base62StringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;

// String to int16/uint16 converters (A)
_SHINSEI_LIB_API uint_fast16_t shinsei_stringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast16_t shinsei_binStringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast16_t shinsei_octStringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast16_t shinsei_hexStringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast16_t shinsei_base36StringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast16_t shinsei_base62StringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int_fast16_t shinsei_stringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast16_t shinsei_binStringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast16_t shinsei_octStringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast16_t shinsei_hexStringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast16_t shinsei_base36StringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast16_t shinsei_base62StringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;

// String to int32/uint32 converters (A)
_SHINSEI_LIB_API uint_fast32_t shinsei_stringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast32_t shinsei_binStringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast32_t shinsei_octStringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast32_t shinsei_hexStringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast32_t shinsei_base36StringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast32_t shinsei_base62StringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int_fast32_t shinsei_stringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_binStringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_octStringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_hexStringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_base36StringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_base62StringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;

// Int64/UInt64 string converters (A)
_SHINSEI_LIB_API uint_fast64_t shinsei_stringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast64_t shinsei_binStringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast64_t shinsei_octStringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast64_t shinsei_hexStringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast64_t shinsei_base36StringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast64_t shinsei_base62StringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API int_fast64_t shinsei_stringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast64_t shinsei_binStringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast64_t shinsei_octStringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast64_t shinsei_hexStringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast64_t shinsei_base36StringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast64_t shinsei_base62StringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;

#ifdef _SHINSEI_OS_WINDOWS
	_SHINSEI_LIB_API int shinsei_charSizeN(const wint_t starter_ch)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isBDigitN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isBDigitNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isODigitN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isODigitNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isDigitN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isDigitNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isXDigitN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isXDigitNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isUpperN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isUpperNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isLowerN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isLowerNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isAlphaN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isAlphaNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isAlnumN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isAlnumNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isBlankN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isBlankNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isCntrlN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isCntrlNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isPrintN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isPrintNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isGraphN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isGraphNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isPunctN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isPunctNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isSpaceN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isSpaceNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isJSONWhitespaceN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isJSONWhitespaceNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API wint_t shinsei_toUpperN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API wint_t shinsei_toUpperNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API wint_t shinsei_toLowerN(const wint_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API wint_t shinsei_toLowerNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_isHexColorN(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_stringLinesN(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_findStringsN(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToPartsN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const wchar_t delimiter)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strLenN(const wchar_t*const restrict str)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API void shinsei_strCpyN(wchar_t*const restrict des,const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strCatN(wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_strCmpN(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strChrN(const wchar_t*const restrict des,const size_t des_len,const wchar_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strStrN(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strKMPN(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT;
	
	// Int8/UInt8 string converters (N)
	_SHINSEI_LIB_API size_t shinsei_uInt8ToStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt8ToBinStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt8ToOctStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt8ToHexStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt8ToBase36StringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt8ToBase62StringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_int8ToStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int8ToBinStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int8ToOctStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int8ToHexStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int8ToBase36StringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int8ToBase62StringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	
	// Int16/UInt16 string converters (N)
	_SHINSEI_LIB_API size_t shinsei_uInt16ToStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt16ToBinStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt16ToOctStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt16ToHexStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt16ToBase36StringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt16ToBase62StringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_int16ToStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int16ToBinStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int16ToOctStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int16ToHexStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int16ToBase36StringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int16ToBase62StringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	
	// Int32/UInt32 string converters (N)
	_SHINSEI_LIB_API size_t shinsei_uInt32ToStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt32ToBinStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt32ToOctStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt32ToHexStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt32ToBase36StringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt32ToBase62StringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_int32ToStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int32ToBinStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int32ToOctStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int32ToHexStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int32ToBase36StringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int32ToBase62StringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	
	// Int64/UInt64 string converters (N)
	_SHINSEI_LIB_API size_t shinsei_uInt64ToStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt64ToBinStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt64ToOctStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt64ToHexStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt64ToBase36StringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt64ToBase62StringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_int64ToStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int64ToBinStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int64ToOctStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int64ToHexStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int64ToBase36StringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int64ToBase62StringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	
	// String to int8/uint8 converters (N)
	_SHINSEI_LIB_API uint_fast8_t shinsei_stringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast8_t shinsei_binStringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast8_t shinsei_octStringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast8_t shinsei_hexStringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast8_t shinsei_base36StringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast8_t shinsei_base62StringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int_fast8_t shinsei_stringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast8_t shinsei_binStringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast8_t shinsei_octStringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast8_t shinsei_hexStringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast8_t shinsei_base36StringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast8_t shinsei_base62StringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	// String to int16/uint16 converters (N)
	_SHINSEI_LIB_API uint_fast16_t shinsei_stringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast16_t shinsei_binStringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast16_t shinsei_octStringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast16_t shinsei_hexStringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast16_t shinsei_base36StringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast16_t shinsei_base62StringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int_fast16_t shinsei_stringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast16_t shinsei_binStringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast16_t shinsei_octStringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast16_t shinsei_hexStringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast16_t shinsei_base36StringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast16_t shinsei_base62StringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	// String to int32/uint32 converters (N)
	_SHINSEI_LIB_API uint_fast32_t shinsei_stringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast32_t shinsei_binStringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast32_t shinsei_octStringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast32_t shinsei_hexStringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast32_t shinsei_base36StringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast32_t shinsei_base62StringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int_fast32_t shinsei_stringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast32_t shinsei_binStringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast32_t shinsei_octStringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast32_t shinsei_hexStringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast32_t shinsei_base36StringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast32_t shinsei_base62StringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	// String to int64/uint64 converters (N)
	_SHINSEI_LIB_API uint_fast64_t shinsei_stringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast64_t shinsei_binStringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast64_t shinsei_octStringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast64_t shinsei_hexStringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast64_t shinsei_base36StringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast64_t shinsei_base62StringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int_fast64_t shinsei_stringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast64_t shinsei_binStringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast64_t shinsei_octStringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast64_t shinsei_hexStringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast64_t shinsei_base36StringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast64_t shinsei_base62StringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
#elif defined(_SHINSEI_OS_UNIX)
	_SHINSEI_LIB_API int shinsei_charSizeN(const char8_t starter_ch)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isBDigitN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isBDigitNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isODigitN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isODigitNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isDigitN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isDigitNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isXDigitN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isXDigitNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isUpperN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isUpperNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isLowerN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isLowerNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isAlphaN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isAlphaNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isAlnumN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isAlnumNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isBlankN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isBlankNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isCntrlN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isCntrlNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isPrintN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isPrintNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isGraphN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isGraphNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isPunctN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isPunctNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isSpaceN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isSpaceNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API bool shinsei_isJSONWhitespaceN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API bool shinsei_isJSONWhitespaceNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API char8_t shinsei_toUpperN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API char8_t shinsei_toUpperNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API char8_t shinsei_toLowerN(const char8_t ch)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API char8_t shinsei_toLowerNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_isHexColorN(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_stringLinesN(size_t*restrict idx_buf,size_t idx_buf_len,char8_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_findStringsN(size_t*restrict idx_buf,size_t idx_buf_len,char8_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_splitStringToPartsN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char8_t delimiter)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strLenN(const char8_t*const restrict str)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API void shinsei_strCpyN(char8_t*const restrict des,const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strCatN(char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int shinsei_strCmpN(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strChrN(const char8_t*const restrict des,const size_t des_len,const char8_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strStrN(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_strKMPN(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT;
	
	// Int8/UInt8 string converters (N)
	_SHINSEI_LIB_API size_t shinsei_uInt8ToStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt8ToBinStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt8ToOctStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt8ToHexStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt8ToBase36StringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt8ToBase62StringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_int8ToStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int8ToBinStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int8ToOctStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int8ToHexStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int8ToBase36StringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int8ToBase62StringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	
	// Int16/UInt16 string converters (N)
	_SHINSEI_LIB_API size_t shinsei_uInt16ToStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt16ToBinStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt16ToOctStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt16ToHexStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt16ToBase36StringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt16ToBase62StringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_int16ToStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int16ToBinStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int16ToOctStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int16ToHexStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int16ToBase36StringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int16ToBase62StringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	
	// Int32/UInt32 string converters (N)
	_SHINSEI_LIB_API size_t shinsei_uInt32ToStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt32ToBinStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt32ToOctStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt32ToHexStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt32ToBase36StringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt32ToBase62StringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_int32ToStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int32ToBinStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int32ToOctStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int32ToHexStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int32ToBase36StringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int32ToBase62StringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	
	// Int64/UInt64 string converters (N)
	_SHINSEI_LIB_API size_t shinsei_uInt64ToStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt64ToBinStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt64ToOctStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt64ToHexStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt64ToBase36StringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_uInt64ToBase62StringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API size_t shinsei_int64ToStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int64ToBinStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int64ToOctStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int64ToHexStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int64ToBase36StringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API size_t shinsei_int64ToBase62StringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	
	// String to int8/uint8 converters (N)
	_SHINSEI_LIB_API uint_fast8_t shinsei_stringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast8_t shinsei_binStringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast8_t shinsei_octStringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast8_t shinsei_hexStringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast8_t shinsei_base36StringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast8_t shinsei_base62StringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int_fast8_t shinsei_stringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast8_t shinsei_binStringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast8_t shinsei_octStringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast8_t shinsei_hexStringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast8_t shinsei_base36StringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast8_t shinsei_base62StringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	// String to int16/uint16 converters (N)
	_SHINSEI_LIB_API uint_fast16_t shinsei_stringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast16_t shinsei_binStringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast16_t shinsei_octStringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast16_t shinsei_hexStringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast16_t shinsei_base36StringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast16_t shinsei_base62StringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int_fast16_t shinsei_stringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast16_t shinsei_binStringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast16_t shinsei_octStringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast16_t shinsei_hexStringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast16_t shinsei_base36StringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast16_t shinsei_base62StringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	// String to int32/uint32 converters (N)
	_SHINSEI_LIB_API uint_fast32_t shinsei_stringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast32_t shinsei_binStringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast32_t shinsei_octStringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast32_t shinsei_hexStringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast32_t shinsei_base36StringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast32_t shinsei_base62StringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int_fast32_t shinsei_stringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast32_t shinsei_binStringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast32_t shinsei_octStringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast32_t shinsei_hexStringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast32_t shinsei_base36StringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast32_t shinsei_base62StringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	// String to int64/uint64 converters (N)
	_SHINSEI_LIB_API uint_fast64_t shinsei_stringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast64_t shinsei_binStringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast64_t shinsei_octStringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast64_t shinsei_hexStringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast64_t shinsei_base36StringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API uint_fast64_t shinsei_base62StringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API int_fast64_t shinsei_stringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast64_t shinsei_binStringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast64_t shinsei_octStringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast64_t shinsei_hexStringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast64_t shinsei_base36StringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API int_fast64_t shinsei_base62StringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
	
#endif

#ifdef _SHINSEI_OS_CPP
}
#endif
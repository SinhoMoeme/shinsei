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
_SHINSEI_LIB_API void shinsei_uInt8ToStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt8ToBinStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt8ToOctStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt8ToHexStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt8To36BaseStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt8To62BaseStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_int8ToStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int8ToBinStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int8ToOctStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int8ToHexStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int8To36BaseStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int8To62BaseStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;

// Int16/UInt16 string converters (A)
_SHINSEI_LIB_API void shinsei_uInt16ToStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt16ToBinStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt16ToOctStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt16ToHexStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt16To36BaseStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt16To62BaseStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_int16ToStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int16ToBinStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int16ToOctStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int16ToHexStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int16To36BaseStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int16To62BaseStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;

// Int32/UInt32 string converters (A)
_SHINSEI_LIB_API void shinsei_uInt32ToStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt32ToBinStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt32ToOctStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt32ToHexStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt32To36BaseStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt32To62BaseStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_int32ToStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int32ToBinStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int32ToOctStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int32ToHexStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int32To36BaseStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int32To62BaseStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;

// Int64/UInt64 string converters (A)
_SHINSEI_LIB_API void shinsei_uInt64ToStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt64ToBinStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt64ToOctStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt64ToHexStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt64To36BaseStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_uInt64To62BaseStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_int64ToStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int64ToBinStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int64ToOctStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int64ToHexStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int64To36BaseStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_int64To62BaseStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;

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
	_SHINSEI_LIB_API void shinsei_uInt8ToStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt8ToBinStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt8ToOctStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt8ToHexStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt8To36BaseStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt8To62BaseStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API void shinsei_int8ToStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int8ToBinStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int8ToOctStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int8ToHexStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int8To36BaseStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int8To62BaseStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	
	// Int16/UInt16 string converters (N)
	_SHINSEI_LIB_API void shinsei_uInt16ToStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt16ToBinStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt16ToOctStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt16ToHexStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt16To36BaseStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt16To62BaseStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API void shinsei_int16ToStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int16ToBinStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int16ToOctStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int16ToHexStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int16To36BaseStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int16To62BaseStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	
	// Int32/UInt32 string converters (N)
	_SHINSEI_LIB_API void shinsei_uInt32ToStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt32ToBinStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt32ToOctStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt32ToHexStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt32To36BaseStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt32To62BaseStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API void shinsei_int32ToStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int32ToBinStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int32ToOctStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int32ToHexStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int32To36BaseStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int32To62BaseStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	
	// Int64/UInt64 string converters (N)
	_SHINSEI_LIB_API void shinsei_uInt64ToStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt64ToBinStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt64ToOctStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt64ToHexStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt64To36BaseStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt64To62BaseStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API void shinsei_int64ToStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int64ToBinStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int64ToOctStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int64ToHexStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int64To36BaseStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int64To62BaseStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	
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
	_SHINSEI_LIB_API void shinsei_uInt8ToStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt8ToBinStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt8ToOctStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt8ToHexStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt8To36BaseStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt8To62BaseStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API void shinsei_int8ToStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int8ToBinStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int8ToOctStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int8ToHexStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int8To36BaseStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int8To62BaseStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT;
	
	// Int16/UInt16 string converters (N)
	_SHINSEI_LIB_API void shinsei_uInt16ToStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt16ToBinStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt16ToOctStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt16ToHexStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt16To36BaseStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt16To62BaseStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API void shinsei_int16ToStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int16ToBinStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int16ToOctStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int16ToHexStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int16To36BaseStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int16To62BaseStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT;
	
	// Int32/UInt32 string converters (N)
	_SHINSEI_LIB_API void shinsei_uInt32ToStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt32ToBinStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt32ToOctStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt32ToHexStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt32To36BaseStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt32To62BaseStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API void shinsei_int32ToStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int32ToBinStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int32ToOctStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int32ToHexStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int32To36BaseStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int32To62BaseStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT;
	
	// Int64/UInt64 string converters (N)
	_SHINSEI_LIB_API void shinsei_uInt64ToStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt64ToBinStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt64ToOctStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt64ToHexStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt64To36BaseStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_uInt64To62BaseStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	
	_SHINSEI_LIB_API void shinsei_int64ToStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int64ToBinStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int64ToOctStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int64ToHexStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int64To36BaseStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_int64To62BaseStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT;
	
#endif

#ifdef _SHINSEI_OS_CPP
}
#endif
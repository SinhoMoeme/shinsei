#pragma once

#include"shinsei/minimal/io.h"
#include"shinsei/.internal/std.h"

#ifdef _SHINSEI_OS_WINDOWS
	#include<stdio.h>
	#include<fcntl.h>
	#include<io.h>
#endif

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

// Char APIs
_SHINSEI_LIB_API void shinsei_putcharW(const wchar_t c)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_putcharU8(const char8_t c)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_putcharU16(const char16_t c)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_putcharU32(const char32_t c)_SHINSEI_OS_NOEXCEPT;

// Print APIs
_SHINSEI_LIB_API void shinsei_printW(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printU8(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printU16(const char16_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printU32(const char32_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;

// PrintLn APIs
_SHINSEI_LIB_API void shinsei_printLnW(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printLnU8(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printLnU16(const char16_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printLnU32(const char32_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;

// Native Numeric APIs (Decimal)
_SHINSEI_LIB_API void shinsei_printInt8(const int8_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printInt16(const int16_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printInt32(const int32_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printInt64(const int64_t val)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_printUInt8(const uint8_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUInt16(const uint16_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUInt32(const uint32_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUInt64(const uint64_t val)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_printSize(const size_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printPtr(const void*const val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUPtr(const void*const val)_SHINSEI_OS_NOEXCEPT;

// Native Numeric APIs (Binary)
_SHINSEI_LIB_API void shinsei_printInt8Bin(const int8_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printInt16Bin(const int16_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printInt32Bin(const int32_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printInt64Bin(const int64_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUInt8Bin(const uint8_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUInt16Bin(const uint16_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUInt32Bin(const uint32_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUInt64Bin(const uint64_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printSizeBin(const size_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printPtrBin(const void*const val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUPtrBin(const void*const val)_SHINSEI_OS_NOEXCEPT;

// Native Numeric APIs (Octal)
_SHINSEI_LIB_API void shinsei_printInt8Oct(const int8_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printInt16Oct(const int16_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printInt32Oct(const int32_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printInt64Oct(const int64_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUInt8Oct(const uint8_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUInt16Oct(const uint16_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUInt32Oct(const uint32_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUInt64Oct(const uint64_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printSizeOct(const size_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printPtrOct(const void*const val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUPtrOct(const void*const val)_SHINSEI_OS_NOEXCEPT;

// Native Numeric APIs (Hexadecimal)
_SHINSEI_LIB_API void shinsei_printInt8Hex(const int8_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printInt16Hex(const int16_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printInt32Hex(const int32_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printInt64Hex(const int64_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUInt8Hex(const uint8_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUInt16Hex(const uint16_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUInt32Hex(const uint32_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUInt64Hex(const uint64_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printSizeHex(const size_t val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printPtrHex(const void*const val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printUPtrHex(const void*const val)_SHINSEI_OS_NOEXCEPT;

// Bool APIs
_SHINSEI_LIB_API void shinsei_printBool(const bool val)_SHINSEI_OS_NOEXCEPT;

// Custom Bool APIs
_SHINSEI_LIB_API void shinsei_printBoolCustomW(const bool val,const wchar_t*const restrict true_text,const size_t true_len,const wchar_t*const restrict false_text,const size_t false_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printBoolCustomU8(const bool val,const char8_t*const restrict true_text,const size_t true_len,const char8_t*const restrict false_text,const size_t false_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printBoolCustomU16(const bool val,const char16_t*const restrict true_text,const size_t true_len,const char16_t*const restrict false_text,const size_t false_len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_printBoolCustomU32(const bool val,const char32_t*const restrict true_text,const size_t true_len,const char32_t*const restrict false_text,const size_t false_len)_SHINSEI_OS_NOEXCEPT;

#ifdef _SHINSEI_OS_WINDOWS
	#ifdef _SHINSEI_OS_CONSTEXPR
		static _SHINSEI_OS_CONSTEXPR const wchar_t SHINSEI_TEXT_TRUE_N[]=L"true";
		static _SHINSEI_OS_CONSTEXPR const wchar_t SHINSEI_TEXT_FALSE_N[]=L"false";
	#else
		#define SHINSEI_TEXT_TRUE_N L"true"
		#define SHINSEI_TEXT_FALSE_N L"false"
	#endif
	_SHINSEI_LIB_API void shinsei_putcharN(const wchar_t c)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_printN(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_printLnN(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_printBoolCustomN(const bool val,const wchar_t*const restrict true_text,const size_t true_len,const wchar_t*const restrict false_text,const size_t false_len)_SHINSEI_OS_NOEXCEPT;
#elif defined(_SHINSEI_OS_UNIX)
	#ifdef _SHINSEI_OS_CONSTEXPR
		static _SHINSEI_OS_CONSTEXPR const char8_t SHINSEI_TEXT_TRUE_N[]=u8"true";
		static _SHINSEI_OS_CONSTEXPR const char8_t SHINSEI_TEXT_FALSE_N[]=u8"false";
	#else
		#define SHINSEI_TEXT_TRUE_N u8"true"
		#define SHINSEI_TEXT_FALSE_N u8"false"
	#endif
	_SHINSEI_LIB_API void shinsei_putcharN(const char8_t c)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_printN(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_printLnN(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT;
	_SHINSEI_LIB_API void shinsei_printBoolCustomN(const bool val,const char8_t*const restrict true_text,const size_t true_len,const char8_t*const restrict false_text,const size_t false_len)_SHINSEI_OS_NOEXCEPT;
#endif

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif
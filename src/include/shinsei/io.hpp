#pragma once

#include"shinsei/io.h"
#include"shinsei/minimal/io.hpp"

namespace shinsei{
	#ifdef _SHINSEI_OS_WINDOWS
		static _SHINSEI_OS_CONSTEXPR const wchar_t* TEXT_TRUE_N=::SHINSEI_TEXT_TRUE_N;
		static _SHINSEI_OS_CONSTEXPR const wchar_t* TEXT_FALSE_N=::SHINSEI_TEXT_FALSE_N;
	#elif defined(_SHINSEI_OS_UNIX)
		static _SHINSEI_OS_CONSTEXPR const char8_t* TEXT_TRUE_N=::SHINSEI_TEXT_TRUE_N;
		static _SHINSEI_OS_CONSTEXPR const char8_t* TEXT_FALSE_N=::SHINSEI_TEXT_FALSE_N;
	#endif
	
	// Char APIs
	_SHINSEI_OS_INLINE void putcharW(const wchar_t c)_SHINSEI_OS_NOEXCEPT{
		::shinsei_putcharW(c);
		return;
	}
	_SHINSEI_OS_INLINE void putcharU8(const char8_t c)_SHINSEI_OS_NOEXCEPT{
		::shinsei_putcharU8(c);
		return;
	}
	_SHINSEI_OS_INLINE void putcharU16(const char16_t c)_SHINSEI_OS_NOEXCEPT{
		::shinsei_putcharU16(c);
		return;
	}
	_SHINSEI_OS_INLINE void putcharU32(const char32_t c)_SHINSEI_OS_NOEXCEPT{
		::shinsei_putcharU32(c);
		return;
	}
	
	// Print APIs
	_SHINSEI_OS_INLINE void printW(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printW(str,len);
		return;
	}
	_SHINSEI_OS_INLINE void printU8(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printU8(str,len);
		return;
	}
	_SHINSEI_OS_INLINE void printU16(const char16_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printU16(str,len);
		return;
	}
	_SHINSEI_OS_INLINE void printU32(const char32_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printU32(str,len);
		return;
	}
	
	// PrintLn APIs
	_SHINSEI_OS_INLINE void printLnW(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printLnW(str,len);
		return;
	}
	_SHINSEI_OS_INLINE void printLnU8(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printLnU8(str,len);
		return;
	}
	_SHINSEI_OS_INLINE void printLnU16(const char16_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printLnU16(str,len);
		return;
	}
	_SHINSEI_OS_INLINE void printLnU32(const char32_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printLnU32(str,len);
		return;
	}
	
	// Native Numeric APIs (Decimal)
	_SHINSEI_OS_INLINE void printInt8(const int8_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printInt8(val);
		return;
	}
	_SHINSEI_OS_INLINE void printInt16(const int16_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printInt16(val);
		return;
	}
	_SHINSEI_OS_INLINE void printInt32(const int32_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printInt32(val);
		return;
	}
	_SHINSEI_OS_INLINE void printInt64(const int64_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printInt64(val);
		return;
	}
	
	_SHINSEI_OS_INLINE void printUInt8(const uint8_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUInt8(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUInt16(const uint16_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUInt16(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUInt32(const uint32_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUInt32(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUInt64(const uint64_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUInt64(val);
		return;
	}
	
	_SHINSEI_OS_INLINE void printSize(const size_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printSize(val);
		return;
	}
	_SHINSEI_OS_INLINE void printPtr(const void*const val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printPtr(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUPtr(const void*const val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUPtr(val);
		return;
	}
	
	// Native Numeric APIs (Binary)
	_SHINSEI_OS_INLINE void printInt8Bin(const int8_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printInt8Bin(val);
		return;
	}
	_SHINSEI_OS_INLINE void printInt16Bin(const int16_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printInt16Bin(val);
		return;
	}
	_SHINSEI_OS_INLINE void printInt32Bin(const int32_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printInt32Bin(val);
		return;
	}
	_SHINSEI_OS_INLINE void printInt64Bin(const int64_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printInt64Bin(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUInt8Bin(const uint8_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUInt8Bin(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUInt16Bin(const uint16_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUInt16Bin(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUInt32Bin(const uint32_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUInt32Bin(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUInt64Bin(const uint64_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUInt64Bin(val);
		return;
	}
	_SHINSEI_OS_INLINE void printSizeBin(const size_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printSizeBin(val);
		return;
	}
	_SHINSEI_OS_INLINE void printPtrBin(const void*const val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printPtrBin(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUPtrBin(const void*const val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUPtrBin(val);
		return;
	}
	
	// Native Numeric APIs (Octal)
	_SHINSEI_OS_INLINE void printInt8Oct(const int8_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printInt8Oct(val);
		return;
	}
	_SHINSEI_OS_INLINE void printInt16Oct(const int16_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printInt16Oct(val);
		return;
	}
	_SHINSEI_OS_INLINE void printInt32Oct(const int32_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printInt32Oct(val);
		return;
	}
	_SHINSEI_OS_INLINE void printInt64Oct(const int64_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printInt64Oct(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUInt8Oct(const uint8_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUInt8Oct(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUInt16Oct(const uint16_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUInt16Oct(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUInt32Oct(const uint32_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUInt32Oct(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUInt64Oct(const uint64_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUInt64Oct(val);
		return;
	}
	_SHINSEI_OS_INLINE void printSizeOct(const size_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printSizeOct(val);
		return;
	}
	_SHINSEI_OS_INLINE void printPtrOct(const void*const val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printPtrOct(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUPtrOct(const void*const val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUPtrOct(val);
		return;
	}
	
	// Native Numeric APIs (Hexadecimal)
	_SHINSEI_OS_INLINE void printInt8Hex(const int8_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printInt8Hex(val);
		return;
	}
	_SHINSEI_OS_INLINE void printInt16Hex(const int16_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printInt16Hex(val);
		return;
	}
	_SHINSEI_OS_INLINE void printInt32Hex(const int32_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printInt32Hex(val);
		return;
	}
	_SHINSEI_OS_INLINE void printInt64Hex(const int64_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printInt64Hex(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUInt8Hex(const uint8_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUInt8Hex(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUInt16Hex(const uint16_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUInt16Hex(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUInt32Hex(const uint32_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUInt32Hex(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUInt64Hex(const uint64_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUInt64Hex(val);
		return;
	}
	_SHINSEI_OS_INLINE void printSizeHex(const size_t val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printSizeHex(val);
		return;
	}
	_SHINSEI_OS_INLINE void printPtrHex(const void*const val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printPtrHex(val);
		return;
	}
	_SHINSEI_OS_INLINE void printUPtrHex(const void*const val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printUPtrHex(val);
		return;
	}
	
	// Bool APIs
	_SHINSEI_OS_INLINE void printBool(const bool val)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printBool(val);
		return;
	}
	_SHINSEI_OS_INLINE void printBoolCustomW(const bool val,const wchar_t*const restrict true_text,const size_t true_len,const wchar_t*const restrict false_text,const size_t false_len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printBoolCustomW(val,true_text,true_len,false_text,false_len);
		return;
	}
	_SHINSEI_OS_INLINE void printBoolCustomU8(const bool val,const char8_t*const restrict true_text,const size_t true_len,const char8_t*const restrict false_text,const size_t false_len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printBoolCustomU8(val,true_text,true_len,false_text,false_len);
		return;
	}
	_SHINSEI_OS_INLINE void printBoolCustomU16(const bool val,const char16_t*const restrict true_text,const size_t true_len,const char16_t*const restrict false_text,const size_t false_len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printBoolCustomU16(val,true_text,true_len,false_text,false_len);
		return;
	}
	_SHINSEI_OS_INLINE void printBoolCustomU32(const bool val,const char32_t*const restrict true_text,const size_t true_len,const char32_t*const restrict false_text,const size_t false_len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printBoolCustomU32(val,true_text,true_len,false_text,false_len);
		return;
	}
	
	// Generic Wrappers
	_SHINSEI_OS_INLINE void putchar(const wchar_t c)_SHINSEI_OS_NOEXCEPT{
		::shinsei_putcharW(c);
		return;
	}
	_SHINSEI_OS_INLINE void putchar(const char8_t c)_SHINSEI_OS_NOEXCEPT{
		::shinsei_putcharU8(c);
		return;
	}
	_SHINSEI_OS_INLINE void putchar(const char16_t c)_SHINSEI_OS_NOEXCEPT{
		::shinsei_putcharU16(c);
		return;
	}
	_SHINSEI_OS_INLINE void putchar(const char32_t c)_SHINSEI_OS_NOEXCEPT{
		::shinsei_putcharU32(c);
		return;
	}
	
	_SHINSEI_OS_INLINE void print(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printW(str,len);
		return;
	}
	_SHINSEI_OS_INLINE void print(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printU8(str,len);
		return;
	}
	_SHINSEI_OS_INLINE void print(const char16_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printU16(str,len);
		return;
	}
	_SHINSEI_OS_INLINE void print(const char32_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printU32(str,len);
		return;
	}
	
	_SHINSEI_OS_INLINE void printLn(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printLnW(str,len);
		return;
	}
	_SHINSEI_OS_INLINE void printLn(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printLnU8(str,len);
		return;
	}
	_SHINSEI_OS_INLINE void printLn(const char16_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printLnU16(str,len);
		return;
	}
	_SHINSEI_OS_INLINE void printLn(const char32_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_printLnU32(str,len);
		return;
	}
	
	// N versions
	#ifdef _SHINSEI_OS_WINDOWS
		_SHINSEI_OS_INLINE void putcharN(const wchar_t c)_SHINSEI_OS_NOEXCEPT{
			::shinsei_putcharN(c);
			return;
		}
		_SHINSEI_OS_INLINE void printN(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_printN(str,len);
			return;
		}
		_SHINSEI_OS_INLINE void printLnN(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_printLnN(str,len);
			return;
		}
		_SHINSEI_OS_INLINE void printBoolCustomN(const bool val,const wchar_t*const restrict true_text,const size_t true_len,const wchar_t*const restrict false_text,const size_t false_len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_printBoolCustomN(val,true_text,true_len,false_text,false_len);
			return;
		}
	#elif defined(_SHINSEI_OS_UNIX)
		_SHINSEI_OS_INLINE void putcharN(const char8_t c)_SHINSEI_OS_NOEXCEPT{
			::shinsei_putcharN(c);
			return;
		}
		_SHINSEI_OS_INLINE void printN(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_printN(str,len);
			return;
		}
		_SHINSEI_OS_INLINE void printLnN(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_printLnN(str,len);
			return;
		}
		_SHINSEI_OS_INLINE void printBoolCustomN(const bool val,const char8_t*const restrict true_text,const size_t true_len,const char8_t*const restrict false_text,const size_t false_len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_printBoolCustomN(val,true_text,true_len,false_text,false_len);
			return;
		}
	#endif
}
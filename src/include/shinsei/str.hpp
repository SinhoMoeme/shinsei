#pragma once

#include"shinsei/minimal/str.hpp"
#include"shinsei/str.h"

namespace shinsei{
	_SHINSEI_OS_INLINE unsigned int systemCP()_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_systemCP();
	}
	
	_SHINSEI_OS_INLINE int charSizeA(const int starter_ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_charSizeA(starter_ch);
	}
	_SHINSEI_OS_INLINE int charSize(const int starter_ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_charSizeA(starter_ch);
	}
	
	_SHINSEI_OS_INLINE bool isBDigitA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitA(ch);
	}
	_SHINSEI_OS_INLINE bool isBDigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isBDigit(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitA(ch);
	}
	_SHINSEI_OS_INLINE bool isBDigitM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isODigitA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitA(ch);
	}
	_SHINSEI_OS_INLINE bool isODigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isODigit(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitA(ch);
	}
	_SHINSEI_OS_INLINE bool isODigitM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isDigitA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitA(ch);
	}
	_SHINSEI_OS_INLINE bool isDigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isDigit(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitA(ch);
	}
	_SHINSEI_OS_INLINE bool isDigitM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isXDigitA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitA(ch);
	}
	_SHINSEI_OS_INLINE bool isXDigitAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isXDigit(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitA(ch);
	}
	_SHINSEI_OS_INLINE bool isXDigitM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isUpperA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperA(ch);
	}
	_SHINSEI_OS_INLINE bool isUpperAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUpper(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperA(ch);
	}
	_SHINSEI_OS_INLINE bool isUpperM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isLowerA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerA(ch);
	}
	_SHINSEI_OS_INLINE bool isLowerAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLower(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerA(ch);
	}
	_SHINSEI_OS_INLINE bool isLowerM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isAlphaA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaA(ch);
	}
	_SHINSEI_OS_INLINE bool isAlphaAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isAlpha(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaA(ch);
	}
	_SHINSEI_OS_INLINE bool isAlphaM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isAlnumA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumA(ch);
	}
	_SHINSEI_OS_INLINE bool isAlnumAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isAlnum(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumA(ch);
	}
	_SHINSEI_OS_INLINE bool isAlnumM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isBlankA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankA(ch);
	}
	_SHINSEI_OS_INLINE bool isBlankAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isBlank(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankA(ch);
	}
	_SHINSEI_OS_INLINE bool isBlankM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isCntrlA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlA(ch);
	}
	_SHINSEI_OS_INLINE bool isCntrlAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCntrl(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlA(ch);
	}
	_SHINSEI_OS_INLINE bool isCntrlM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isPrintA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintA(ch);
	}
	_SHINSEI_OS_INLINE bool isPrintAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isPrint(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintA(ch);
	}
	_SHINSEI_OS_INLINE bool isPrintM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isGraphA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphA(ch);
	}
	_SHINSEI_OS_INLINE bool isGraphAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isGraph(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphA(ch);
	}
	_SHINSEI_OS_INLINE bool isGraphM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isPunctA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctA(ch);
	}
	_SHINSEI_OS_INLINE bool isPunctAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isPunct(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctA(ch);
	}
	_SHINSEI_OS_INLINE bool isPunctM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isSpaceA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceA(ch);
	}
	_SHINSEI_OS_INLINE bool isSpaceAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSpace(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceA(ch);
	}
	_SHINSEI_OS_INLINE bool isSpaceM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isJSONWhitespaceA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceA(ch);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespaceAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespace(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceA(ch);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespaceM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE int toUpperA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperA(ch);
	}
	_SHINSEI_OS_INLINE int toUpperAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE int toUpper(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperA(ch);
	}
	_SHINSEI_OS_INLINE int toUpperM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE int toLowerA(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerA(ch);
	}
	_SHINSEI_OS_INLINE int toLowerAM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerAM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE int toLower(const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerA(ch);
	}
	_SHINSEI_OS_INLINE int toLowerM(const char**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerAM(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE int isHexColorA(const char*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isHexColorA(str,len);
	}
	_SHINSEI_OS_INLINE int isHexColor(const char*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isHexColorA(str,len);
	}
	
	_SHINSEI_OS_INLINE size_t stringLinesA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringLinesA(idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE size_t stringLines(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringLinesA(idx_buf,idx_buf_len,str,str_len);
	}
	
	_SHINSEI_OS_INLINE size_t findStringsA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_findStringsA(idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE size_t findStrings(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_findStringsA(idx_buf,idx_buf_len,str,str_len);
	}
	
	_SHINSEI_OS_INLINE size_t splitStringToPartsA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char delimiter)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToPartsA(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
	}
	_SHINSEI_OS_INLINE size_t splitStringToParts(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char delimiter)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToPartsA(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
	}
	
	// strLen
	_SHINSEI_OS_INLINE size_t strLenA(const char*const restrict str)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strLenA(str);
	}
	_SHINSEI_OS_INLINE size_t strLen(const char*const restrict str)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strLenA(str);
	}
	
	// strCpy
	inline void strCpyA(char*const restrict des,const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_strCpyA(des,src,len);
		return;
	}
	inline void strCpy(char*const restrict des,const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_strCpyA(des,src,len);
		return;
	}
	
	// strCat
	inline size_t strCatA(char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCatA(des,des_len,src,src_len);
	}
	inline size_t strCat(char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCatA(des,des_len,src,src_len);
	}
	
	// strCmp
	inline int strCmpA(const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCmpA(des,des_len,src,src_len);
	}
	inline int strCmp(const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCmpA(des,des_len,src,src_len);
	}
	
	// strChr
	inline size_t strChrA(const char*const restrict des,const size_t des_len,const char src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strChrA(des,des_len,src);
	}
	inline size_t strChr(const char*const restrict des,const size_t des_len,const char src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strChrA(des,des_len,src);
	}
	
	// strStr
	inline size_t strStrA(const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strStrA(des,des_len,src,src_len);
	}
	inline size_t strStr(const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strStrA(des,des_len,src,src_len);
	}
	
	// strKMP
	inline size_t strKMPA(const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strKMPA(des,des_len,src,src_len,buf,buf_len);
	}
	inline size_t strKMP(const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strKMPA(des,des_len,src,src_len,buf,buf_len);
	}
	
	// Int8/UInt8 string converters (A)
	inline void uInt8ToStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToStringA(des,src);
	}
	inline void uInt8ToBinStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBinStringA(des,src);
	}
	inline void uInt8ToOctStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToOctStringA(des,src);
	}
	inline void uInt8ToHexStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToHexStringA(des,src);
	}
	inline void uInt8To36BaseStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8To36BaseStringA(des,src);
	}
	inline void uInt8To62BaseStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8To62BaseStringA(des,src);
	}
	
	inline void int8ToStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToStringA(des,src);
	}
	inline void int8ToBinStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBinStringA(des,src);
	}
	inline void int8ToOctStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToOctStringA(des,src);
	}
	inline void int8ToHexStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToHexStringA(des,src);
	}
	inline void int8To36BaseStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8To36BaseStringA(des,src);
	}
	inline void int8To62BaseStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8To62BaseStringA(des,src);
	}
	
	// Int16/UInt16 string converters (A)
	inline void uInt16ToStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToStringA(des,src);
	}
	inline void uInt16ToBinStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBinStringA(des,src);
	}
	inline void uInt16ToOctStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToOctStringA(des,src);
	}
	inline void uInt16ToHexStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToHexStringA(des,src);
	}
	inline void uInt16To36BaseStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16To36BaseStringA(des,src);
	}
	inline void uInt16To62BaseStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16To62BaseStringA(des,src);
	}
	
	inline void int16ToStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToStringA(des,src);
	}
	inline void int16ToBinStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBinStringA(des,src);
	}
	inline void int16ToOctStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToOctStringA(des,src);
	}
	inline void int16ToHexStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToHexStringA(des,src);
	}
	inline void int16To36BaseStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16To36BaseStringA(des,src);
	}
	inline void int16To62BaseStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16To62BaseStringA(des,src);
	}
	
	// Int32/UInt32 string converters (A)
	inline void uInt32ToStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToStringA(des,src);
	}
	inline void uInt32ToBinStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBinStringA(des,src);
	}
	inline void uInt32ToOctStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToOctStringA(des,src);
	}
	inline void uInt32ToHexStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToHexStringA(des,src);
	}
	inline void uInt32To36BaseStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32To36BaseStringA(des,src);
	}
	inline void uInt32To62BaseStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32To62BaseStringA(des,src);
	}
	
	inline void int32ToStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToStringA(des,src);
	}
	inline void int32ToBinStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBinStringA(des,src);
	}
	inline void int32ToOctStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToOctStringA(des,src);
	}
	inline void int32ToHexStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToHexStringA(des,src);
	}
	inline void int32To36BaseStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32To36BaseStringA(des,src);
	}
	inline void int32To62BaseStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32To62BaseStringA(des,src);
	}
	
	// Int64/UInt64 string converters (A)
	inline void uInt64ToStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToStringA(des,src);
	}
	inline void uInt64ToBinStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBinStringA(des,src);
	}
	inline void uInt64ToOctStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToOctStringA(des,src);
	}
	inline void uInt64ToHexStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToHexStringA(des,src);
	}
	inline void uInt64To36BaseStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64To36BaseStringA(des,src);
	}
	inline void uInt64To62BaseStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64To62BaseStringA(des,src);
	}
	
	inline void int64ToStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToStringA(des,src);
	}
	inline void int64ToBinStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBinStringA(des,src);
	}
	inline void int64ToOctStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToOctStringA(des,src);
	}
	inline void int64ToHexStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToHexStringA(des,src);
	}
	inline void int64To36BaseStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64To36BaseStringA(des,src);
	}
	inline void int64To62BaseStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64To62BaseStringA(des,src);
	}
	
	using string_a_t=string_t<char>;
	
	#ifdef _SHINSEI_OS_WINDOWS
		_SHINSEI_OS_INLINE int charSizeN(const wint_t starter_ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_charSizeN(starter_ch);
		}
		
		_SHINSEI_OS_INLINE bool isBDigitN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isBDigitN(ch);
		}
		_SHINSEI_OS_INLINE bool isBDigitNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isBDigitNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isODigitN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isODigitN(ch);
		}
		_SHINSEI_OS_INLINE bool isODigitNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isODigitNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isDigitN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isDigitN(ch);
		}
		_SHINSEI_OS_INLINE bool isDigitNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isDigitNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isXDigitN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isXDigitN(ch);
		}
		_SHINSEI_OS_INLINE bool isXDigitNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isXDigitNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isUpperN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isUpperN(ch);
		}
		_SHINSEI_OS_INLINE bool isUpperNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isUpperNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isLowerN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isLowerN(ch);
		}
		_SHINSEI_OS_INLINE bool isLowerNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isLowerNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isAlphaN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isAlphaN(ch);
		}
		_SHINSEI_OS_INLINE bool isAlphaNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isAlphaNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isAlnumN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isAlnumN(ch);
		}
		_SHINSEI_OS_INLINE bool isAlnumNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isAlnumNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isBlankN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isBlankN(ch);
		}
		_SHINSEI_OS_INLINE bool isBlankNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isBlankNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isCntrlN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isCntrlN(ch);
		}
		_SHINSEI_OS_INLINE bool isCntrlNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isCntrlNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isPrintN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isPrintN(ch);
		}
		_SHINSEI_OS_INLINE bool isPrintNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isPrintNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isGraphN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isGraphN(ch);
		}
		_SHINSEI_OS_INLINE bool isGraphNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isGraphNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isPunctN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isPunctN(ch);
		}
		_SHINSEI_OS_INLINE bool isPunctNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isPunctNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isSpaceN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isSpaceN(ch);
		}
		_SHINSEI_OS_INLINE bool isSpaceNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isSpaceNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isJSONWhitespaceN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isJSONWhitespaceN(ch);
		}
		_SHINSEI_OS_INLINE bool isJSONWhitespaceNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isJSONWhitespaceNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE wint_t toUpperN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_toUpperN(ch);
		}
		_SHINSEI_OS_INLINE wint_t toUpperNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_toUpperNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE wint_t toLowerN(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_toLowerN(ch);
		}
		_SHINSEI_OS_INLINE wint_t toLowerNM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_toLowerNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE int isHexColorN(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isHexColorN(str,len);
		}
		
		_SHINSEI_OS_INLINE size_t stringLinesN(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringLinesN(idx_buf,idx_buf_len,str,str_len);
		}
		
		_SHINSEI_OS_INLINE size_t findStringsN(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_findStringsN(idx_buf,idx_buf_len,str,str_len);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToPartsN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const wchar_t delimiter)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToPartsN(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
		}
		
		_SHINSEI_OS_INLINE size_t strLenN(const wchar_t*const restrict str)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_strLenN(str);
		}
		
		_SHINSEI_OS_INLINE void strCpyN(wchar_t*const restrict des,const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_strCpyN(des,src,len);
			return;
		}
		_SHINSEI_OS_INLINE size_t strCatN(wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_strCatN(des,des_len,src,src_len);
		}
		_SHINSEI_OS_INLINE int strCmpN(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_strCmpN(des,des_len,src,src_len);
		}
		_SHINSEI_OS_INLINE size_t strChrN(const wchar_t*const restrict des,const size_t des_len,const wchar_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_strChrN(des,des_len,src);
		}
		_SHINSEI_OS_INLINE size_t strStrN(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_strStrN(des,des_len,src,src_len);
		}
		_SHINSEI_OS_INLINE size_t strKMPN(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_strKMPN(des,des_len,src,src_len,buf,buf_len);
		}
		
		// Int8/UInt8 string converters (N)
		inline void uInt8ToStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToStringN(des,src);
		}
		inline void uInt8ToBinStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToBinStringN(des,src);
		}
		inline void uInt8ToOctStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToOctStringN(des,src);
		}
		inline void uInt8ToHexStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToHexStringN(des,src);
		}
		inline void uInt8To36BaseStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8To36BaseStringN(des,src);
		}
		inline void uInt8To62BaseStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8To62BaseStringN(des,src);
		}
		
		inline void int8ToStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToStringN(des,src);
		}
		inline void int8ToBinStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToBinStringN(des,src);
		}
		inline void int8ToOctStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToOctStringN(des,src);
		}
		inline void int8ToHexStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToHexStringN(des,src);
		}
		inline void int8To36BaseStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8To36BaseStringN(des,src);
		}
		inline void int8To62BaseStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8To62BaseStringN(des,src);
		}
		
		// Int16/UInt16 string converters (N)
		inline void uInt16ToStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToStringN(des,src);
		}
		inline void uInt16ToBinStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToBinStringN(des,src);
		}
		inline void uInt16ToOctStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToOctStringN(des,src);
		}
		inline void uInt16ToHexStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToHexStringN(des,src);
		}
		inline void uInt16To36BaseStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16To36BaseStringN(des,src);
		}
		inline void uInt16To62BaseStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16To62BaseStringN(des,src);
		}
		
		inline void int16ToStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToStringN(des,src);
		}
		inline void int16ToBinStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToBinStringN(des,src);
		}
		inline void int16ToOctStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToOctStringN(des,src);
		}
		inline void int16ToHexStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToHexStringN(des,src);
		}
		inline void int16To36BaseStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16To36BaseStringN(des,src);
		}
		inline void int16To62BaseStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16To62BaseStringN(des,src);
		}
		
		// Int32/UInt32 string converters (N)
		inline void uInt32ToStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToStringN(des,src);
		}
		inline void uInt32ToBinStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToBinStringN(des,src);
		}
		inline void uInt32ToOctStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToOctStringN(des,src);
		}
		inline void uInt32ToHexStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToHexStringN(des,src);
		}
		inline void uInt32To36BaseStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32To36BaseStringN(des,src);
		}
		inline void uInt32To62BaseStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32To62BaseStringN(des,src);
		}
		
		inline void int32ToStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToStringN(des,src);
		}
		inline void int32ToBinStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToBinStringN(des,src);
		}
		inline void int32ToOctStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToOctStringN(des,src);
		}
		inline void int32ToHexStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToHexStringN(des,src);
		}
		inline void int32To36BaseStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32To36BaseStringN(des,src);
		}
		inline void int32To62BaseStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32To62BaseStringN(des,src);
		}
		
		// Int64/UInt64 string converters (N)
		inline void uInt64ToStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToStringN(des,src);
		}
		inline void uInt64ToBinStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToBinStringN(des,src);
		}
		inline void uInt64ToOctStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToOctStringN(des,src);
		}
		inline void uInt64ToHexStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToHexStringN(des,src);
		}
		inline void uInt64To36BaseStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64To36BaseStringN(des,src);
		}
		inline void uInt64To62BaseStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64To62BaseStringN(des,src);
		}
		
		inline void int64ToStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToStringN(des,src);
		}
		inline void int64ToBinStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToBinStringN(des,src);
		}
		inline void int64ToOctStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToOctStringN(des,src);
		}
		inline void int64ToHexStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToHexStringN(des,src);
		}
		inline void int64To36BaseStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64To36BaseStringN(des,src);
		}
		inline void int64To62BaseStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64To62BaseStringN(des,src);
		}
		
		using string_n_t=string_t<wchar_t>;
		
	#elif defined(_SHINSEI_OS_UNIX)
		_SHINSEI_OS_INLINE int charSizeN(const char8_t starter_ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_charSizeN(starter_ch);
		}
		
		_SHINSEI_OS_INLINE bool isBDigitN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isBDigitN(ch);
		}
		_SHINSEI_OS_INLINE bool isBDigitNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isBDigitNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isODigitN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isODigitN(ch);
		}
		_SHINSEI_OS_INLINE bool isODigitNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isODigitNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isSpaceN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isSpaceN(ch);
		}
		_SHINSEI_OS_INLINE bool isSpaceNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isSpaceNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isDigitN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isDigitN(ch);
		}
		_SHINSEI_OS_INLINE bool isDigitNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isDigitNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isXDigitN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isXDigitN(ch);
		}
		_SHINSEI_OS_INLINE bool isXDigitNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isXDigitNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isUpperN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isUpperN(ch);
		}
		_SHINSEI_OS_INLINE bool isUpperNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isUpperNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isLowerN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isLowerN(ch);
		}
		_SHINSEI_OS_INLINE bool isLowerNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isLowerNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isAlphaN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isAlphaN(ch);
		}
		_SHINSEI_OS_INLINE bool isAlphaNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isAlphaNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isAlnumN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isAlnumN(ch);
		}
		_SHINSEI_OS_INLINE bool isAlnumNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isAlnumNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isBlankN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isBlankN(ch);
		}
		_SHINSEI_OS_INLINE bool isBlankNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isBlankNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isCntrlN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isCntrlN(ch);
		}
		_SHINSEI_OS_INLINE bool isCntrlNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isCntrlNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isPrintN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isPrintN(ch);
		}
		_SHINSEI_OS_INLINE bool isPrintNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isPrintNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isGraphN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isGraphN(ch);
		}
		_SHINSEI_OS_INLINE bool isGraphNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isGraphNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isPunctN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isPunctN(ch);
		}
		_SHINSEI_OS_INLINE bool isPunctNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isPunctNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE bool isJSONWhitespaceN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isJSONWhitespaceN(ch);
		}
		_SHINSEI_OS_INLINE bool isJSONWhitespaceNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isJSONWhitespaceNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE char8_t toUpperN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_toUpperN(ch);
		}
		_SHINSEI_OS_INLINE char8_t toUpperNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_toUpperNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE char8_t toLowerN(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_toLowerN(ch);
		}
		_SHINSEI_OS_INLINE char8_t toLowerNM(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_toLowerNM(str_ptr,len);
		}
		
		_SHINSEI_OS_INLINE int isHexColorN(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_isHexColorN(str,len);
		}
		
		_SHINSEI_OS_INLINE size_t stringLinesN(size_t*restrict idx_buf,size_t idx_buf_len,char8_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringLinesN(idx_buf,idx_buf_len,str,str_len);
		}
		
		_SHINSEI_OS_INLINE size_t findStringsN(size_t*restrict idx_buf,size_t idx_buf_len,char8_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_findStringsN(idx_buf,idx_buf_len,str,str_len);
		}
		
		_SHINSEI_OS_INLINE size_t splitStringToPartsN(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char8_t delimiter)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_splitStringToPartsN(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
		}
		
		_SHINSEI_OS_INLINE size_t strLenN(const char8_t*const restrict str)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_strLenN(str);
		}
		
		_SHINSEI_OS_INLINE void strCpyN(char8_t*const restrict des,const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_strCpyN(des,src,len);
			return;
		}
		_SHINSEI_OS_INLINE size_t strCatN(char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_strCatN(des,des_len,src,src_len);
		}
		_SHINSEI_OS_INLINE int strCmpN(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_strCmpN(des,des_len,src,src_len);
		}
		_SHINSEI_OS_INLINE size_t strChrN(const char8_t*const restrict des,const size_t des_len,const char8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_strChrN(des,des_len,src);
		}
		_SHINSEI_OS_INLINE size_t strStrN(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_strStrN(des,des_len,src,src_len);
		}
		_SHINSEI_OS_INLINE size_t strKMPN(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_strKMPN(des,des_len,src,src_len,buf,buf_len);
		}
		
		// Int8/UInt8 string converters (N)
		inline void uInt8ToStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToStringN(des,src);
		}
		inline void uInt8ToBinStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToBinStringN(des,src);
		}
		inline void uInt8ToOctStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToOctStringN(des,src);
		}
		inline void uInt8ToHexStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToHexStringN(des,src);
		}
		inline void uInt8To36BaseStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8To36BaseStringN(des,src);
		}
		inline void uInt8To62BaseStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8To62BaseStringN(des,src);
		}
		
		inline void int8ToStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToStringN(des,src);
		}
		inline void int8ToBinStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToBinStringN(des,src);
		}
		inline void int8ToOctStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToOctStringN(des,src);
		}
		inline void int8ToHexStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToHexStringN(des,src);
		}
		inline void int8To36BaseStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8To36BaseStringN(des,src);
		}
		inline void int8To62BaseStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8To62BaseStringN(des,src);
		}
		
		// Int16/UInt16 string converters (N)
		inline void uInt16ToStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToStringN(des,src);
		}
		inline void uInt16ToBinStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToBinStringN(des,src);
		}
		inline void uInt16ToOctStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToOctStringN(des,src);
		}
		inline void uInt16ToHexStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToHexStringN(des,src);
		}
		inline void uInt16To36BaseStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16To36BaseStringN(des,src);
		}
		inline void uInt16To62BaseStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16To62BaseStringN(des,src);
		}
		
		inline void int16ToStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToStringN(des,src);
		}
		inline void int16ToBinStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToBinStringN(des,src);
		}
		inline void int16ToOctStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToOctStringN(des,src);
		}
		inline void int16ToHexStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToHexStringN(des,src);
		}
		inline void int16To36BaseStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16To36BaseStringN(des,src);
		}
		inline void int16To62BaseStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16To62BaseStringN(des,src);
		}
		
		// Int32/UInt32 string converters (N)
		inline void uInt32ToStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToStringN(des,src);
		}
		inline void uInt32ToBinStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToBinStringN(des,src);
		}
		inline void uInt32ToOctStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToOctStringN(des,src);
		}
		inline void uInt32ToHexStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToHexStringN(des,src);
		}
		inline void uInt32To36BaseStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32To36BaseStringN(des,src);
		}
		inline void uInt32To62BaseStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32To62BaseStringN(des,src);
		}
		
		inline void int32ToStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToStringN(des,src);
		}
		inline void int32ToBinStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToBinStringN(des,src);
		}
		inline void int32ToOctStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToOctStringN(des,src);
		}
		inline void int32ToHexStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToHexStringN(des,src);
		}
		inline void int32To36BaseStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32To36BaseStringN(des,src);
		}
		inline void int32To62BaseStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32To62BaseStringN(des,src);
		}
		
		// Int64/UInt64 string converters (N)
		inline void uInt64ToStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToStringN(des,src);
		}
		inline void uInt64ToBinStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToBinStringN(des,src);
		}
		inline void uInt64ToOctStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToOctStringN(des,src);
		}
		inline void uInt64ToHexStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToHexStringN(des,src);
		}
		inline void uInt64To36BaseStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64To36BaseStringN(des,src);
		}
		inline void uInt64To62BaseStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64To62BaseStringN(des,src);
		}
		
		inline void int64ToStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToStringN(des,src);
		}
		inline void int64ToBinStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToBinStringN(des,src);
		}
		inline void int64ToOctStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToOctStringN(des,src);
		}
		inline void int64ToHexStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToHexStringN(des,src);
		}
		inline void int64To36BaseStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64To36BaseStringN(des,src);
		}
		inline void int64To62BaseStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64To62BaseStringN(des,src);
		}
		
		using string_n_t=string_t<char8_t>;
		
	#endif
}
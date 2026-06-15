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
	inline ::size_t uInt8ToStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToStringA(des,src);
	}
	inline ::size_t uInt8ToBinStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBinStringA(des,src);
	}
	inline ::size_t uInt8ToOctStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToOctStringA(des,src);
	}
	inline ::size_t uInt8ToHexStringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToHexStringA(des,src);
	}
	inline ::size_t uInt8ToBase36StringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBase36StringA(des,src);
	}
	inline ::size_t uInt8ToBase62StringA(char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBase62StringA(des,src);
	}
	
	inline ::size_t int8ToStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToStringA(des,src);
	}
	inline ::size_t int8ToBinStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBinStringA(des,src);
	}
	inline ::size_t int8ToOctStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToOctStringA(des,src);
	}
	inline ::size_t int8ToHexStringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToHexStringA(des,src);
	}
	inline ::size_t int8ToBase36StringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBase36StringA(des,src);
	}
	inline ::size_t int8ToBase62StringA(char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBase62StringA(des,src);
	}
	
	// Int16/UInt16 string converters (A)
	inline ::size_t uInt16ToStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToStringA(des,src);
	}
	inline ::size_t uInt16ToBinStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBinStringA(des,src);
	}
	inline ::size_t uInt16ToOctStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToOctStringA(des,src);
	}
	inline ::size_t uInt16ToHexStringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToHexStringA(des,src);
	}
	inline ::size_t uInt16ToBase36StringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBase36StringA(des,src);
	}
	inline ::size_t uInt16ToBase62StringA(char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBase62StringA(des,src);
	}
	
	inline ::size_t int16ToStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToStringA(des,src);
	}
	inline ::size_t int16ToBinStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBinStringA(des,src);
	}
	inline ::size_t int16ToOctStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToOctStringA(des,src);
	}
	inline ::size_t int16ToHexStringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToHexStringA(des,src);
	}
	inline ::size_t int16ToBase36StringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBase36StringA(des,src);
	}
	inline ::size_t int16ToBase62StringA(char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBase62StringA(des,src);
	}
	
	// Int32/UInt32 string converters (A)
	inline ::size_t uInt32ToStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToStringA(des,src);
	}
	inline ::size_t uInt32ToBinStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBinStringA(des,src);
	}
	inline ::size_t uInt32ToOctStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToOctStringA(des,src);
	}
	inline ::size_t uInt32ToHexStringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToHexStringA(des,src);
	}
	inline ::size_t uInt32ToBase36StringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBase36StringA(des,src);
	}
	inline ::size_t uInt32ToBase62StringA(char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBase62StringA(des,src);
	}
	
	inline ::size_t int32ToStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToStringA(des,src);
	}
	inline ::size_t int32ToBinStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBinStringA(des,src);
	}
	inline ::size_t int32ToOctStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToOctStringA(des,src);
	}
	inline ::size_t int32ToHexStringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToHexStringA(des,src);
	}
	inline ::size_t int32ToBase36StringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBase36StringA(des,src);
	}
	inline ::size_t int32ToBase62StringA(char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBase62StringA(des,src);
	}
	
	// Int64/UInt64 string converters (A)
	inline ::size_t uInt64ToStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToStringA(des,src);
	}
	inline ::size_t uInt64ToBinStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBinStringA(des,src);
	}
	inline ::size_t uInt64ToOctStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToOctStringA(des,src);
	}
	inline ::size_t uInt64ToHexStringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToHexStringA(des,src);
	}
	inline ::size_t uInt64ToBase36StringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBase36StringA(des,src);
	}
	inline ::size_t uInt64ToBase62StringA(char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBase62StringA(des,src);
	}
	
	inline ::size_t int64ToStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToStringA(des,src);
	}
	inline ::size_t int64ToBinStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBinStringA(des,src);
	}
	inline ::size_t int64ToOctStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToOctStringA(des,src);
	}
	inline ::size_t int64ToHexStringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToHexStringA(des,src);
	}
	inline ::size_t int64ToBase36StringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBase36StringA(des,src);
	}
	inline ::size_t int64ToBase62StringA(char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBase62StringA(des,src);
	}
	
	// String to int8/uint8 converters (A)
	inline uint_fast8_t stringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt8A(src,len);
	}
	inline uint_fast8_t binStringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt8A(src,len);
	}
	inline uint_fast8_t octStringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt8A(src,len);
	}
	inline uint_fast8_t hexStringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt8A(src,len);
	}
	inline uint_fast8_t base36StringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt8A(src,len);
	}
	inline uint_fast8_t base62StringToUInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt8A(src,len);
	}
	
	inline int_fast8_t stringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt8A(src,len);
	}
	inline int_fast8_t binStringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt8A(src,len);
	}
	inline int_fast8_t octStringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt8A(src,len);
	}
	inline int_fast8_t hexStringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt8A(src,len);
	}
	inline int_fast8_t base36StringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt8A(src,len);
	}
	inline int_fast8_t base62StringToInt8A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt8A(src,len);
	}
	
	// String to int16/uint16 converters (A)
	inline uint_fast16_t stringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt16A(src,len);
	}
	inline uint_fast16_t binStringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt16A(src,len);
	}
	inline uint_fast16_t octStringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt16A(src,len);
	}
	inline uint_fast16_t hexStringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt16A(src,len);
	}
	inline uint_fast16_t base36StringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt16A(src,len);
	}
	inline uint_fast16_t base62StringToUInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt16A(src,len);
	}
	
	inline int_fast16_t stringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt16A(src,len);
	}
	inline int_fast16_t binStringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt16A(src,len);
	}
	inline int_fast16_t octStringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt16A(src,len);
	}
	inline int_fast16_t hexStringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt16A(src,len);
	}
	inline int_fast16_t base36StringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt16A(src,len);
	}
	inline int_fast16_t base62StringToInt16A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt16A(src,len);
	}
	
	// String to int32/uint32 converters (A)
	inline uint_fast32_t stringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt32A(src,len);
	}
	inline uint_fast32_t binStringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt32A(src,len);
	}
	inline uint_fast32_t octStringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt32A(src,len);
	}
	inline uint_fast32_t hexStringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt32A(src,len);
	}
	inline uint_fast32_t base36StringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt32A(src,len);
	}
	inline uint_fast32_t base62StringToUInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt32A(src,len);
	}
	
	inline int_fast32_t stringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt32A(src,len);
	}
	inline int_fast32_t binStringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt32A(src,len);
	}
	inline int_fast32_t octStringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt32A(src,len);
	}
	inline int_fast32_t hexStringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt32A(src,len);
	}
	inline int_fast32_t base36StringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt32A(src,len);
	}
	inline int_fast32_t base62StringToInt32A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt32A(src,len);
	}
	
	// String to int64/uint64 converters (A)
	inline uint_fast64_t stringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt64A(src,len);
	}
	inline uint_fast64_t binStringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt64A(src,len);
	}
	inline uint_fast64_t octStringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt64A(src,len);
	}
	inline uint_fast64_t hexStringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt64A(src,len);
	}
	inline uint_fast64_t base36StringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt64A(src,len);
	}
	inline uint_fast64_t base62StringToUInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt64A(src,len);
	}
	
	inline int_fast64_t stringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt64A(src,len);
	}
	inline int_fast64_t binStringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt64A(src,len);
	}
	inline int_fast64_t octStringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt64A(src,len);
	}
	inline int_fast64_t hexStringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt64A(src,len);
	}
	inline int_fast64_t base36StringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt64A(src,len);
	}
	inline int_fast64_t base62StringToInt64A(const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt64A(src,len);
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
		inline ::size_t uInt8ToStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToStringN(des,src);
		}
		inline ::size_t uInt8ToBinStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToBinStringN(des,src);
		}
		inline ::size_t uInt8ToOctStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToOctStringN(des,src);
		}
		inline ::size_t uInt8ToHexStringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToHexStringN(des,src);
		}
		inline ::size_t uInt8ToBase36StringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToBase36StringN(des,src);
		}
		inline ::size_t uInt8ToBase62StringN(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToBase62StringN(des,src);
		}
		
		inline ::size_t int8ToStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToStringN(des,src);
		}
		inline ::size_t int8ToBinStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToBinStringN(des,src);
		}
		inline ::size_t int8ToOctStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToOctStringN(des,src);
		}
		inline ::size_t int8ToHexStringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToHexStringN(des,src);
		}
		inline ::size_t int8ToBase36StringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToBase36StringN(des,src);
		}
		inline ::size_t int8ToBase62StringN(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToBase62StringN(des,src);
		}
		
		// Int16/UInt16 string converters (N)
		inline ::size_t uInt16ToStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToStringN(des,src);
		}
		inline ::size_t uInt16ToBinStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToBinStringN(des,src);
		}
		inline ::size_t uInt16ToOctStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToOctStringN(des,src);
		}
		inline ::size_t uInt16ToHexStringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToHexStringN(des,src);
		}
		inline ::size_t uInt16ToBase36StringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToBase36StringN(des,src);
		}
		inline ::size_t uInt16ToBase62StringN(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToBase62StringN(des,src);
		}
		
		inline ::size_t int16ToStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToStringN(des,src);
		}
		inline ::size_t int16ToBinStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToBinStringN(des,src);
		}
		inline ::size_t int16ToOctStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToOctStringN(des,src);
		}
		inline ::size_t int16ToHexStringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToHexStringN(des,src);
		}
		inline ::size_t int16ToBase36StringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToBase36StringN(des,src);
		}
		inline ::size_t int16ToBase62StringN(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToBase62StringN(des,src);
		}
		
		// Int32/UInt32 string converters (N)
		inline ::size_t uInt32ToStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToStringN(des,src);
		}
		inline ::size_t uInt32ToBinStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToBinStringN(des,src);
		}
		inline ::size_t uInt32ToOctStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToOctStringN(des,src);
		}
		inline ::size_t uInt32ToHexStringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToHexStringN(des,src);
		}
		inline ::size_t uInt32ToBase36StringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToBase36StringN(des,src);
		}
		inline ::size_t uInt32ToBase62StringN(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToBase62StringN(des,src);
		}
		
		inline ::size_t int32ToStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToStringN(des,src);
		}
		inline ::size_t int32ToBinStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToBinStringN(des,src);
		}
		inline ::size_t int32ToOctStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToOctStringN(des,src);
		}
		inline ::size_t int32ToHexStringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToHexStringN(des,src);
		}
		inline ::size_t int32ToBase36StringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToBase36StringN(des,src);
		}
		inline ::size_t int32ToBase62StringN(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToBase62StringN(des,src);
		}
		
		// Int64/UInt64 string converters (N)
		inline ::size_t uInt64ToStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToStringN(des,src);
		}
		inline ::size_t uInt64ToBinStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToBinStringN(des,src);
		}
		inline ::size_t uInt64ToOctStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToOctStringN(des,src);
		}
		inline ::size_t uInt64ToHexStringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToHexStringN(des,src);
		}
		inline ::size_t uInt64ToBase36StringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToBase36StringN(des,src);
		}
		inline ::size_t uInt64ToBase62StringN(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToBase62StringN(des,src);
		}
		
		inline ::size_t int64ToStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToStringN(des,src);
		}
		inline ::size_t int64ToBinStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToBinStringN(des,src);
		}
		inline ::size_t int64ToOctStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToOctStringN(des,src);
		}
		inline ::size_t int64ToHexStringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToHexStringN(des,src);
		}
		inline ::size_t int64ToBase36StringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToBase36StringN(des,src);
		}
		inline ::size_t int64ToBase62StringN(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToBase62StringN(des,src);
		}
		
		// String to int8/uint8 converters (N)
		inline uint_fast8_t stringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringToUInt8N(src,len);
		}
		inline uint_fast8_t binStringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_binStringToUInt8N(src,len);
		}
		inline uint_fast8_t octStringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_octStringToUInt8N(src,len);
		}
		inline uint_fast8_t hexStringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_hexStringToUInt8N(src,len);
		}
		inline uint_fast8_t base36StringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base36StringToUInt8N(src,len);
		}
		inline uint_fast8_t base62StringToUInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base62StringToUInt8N(src,len);
		}
		
		inline int_fast8_t stringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringToInt8N(src,len);
		}
		inline int_fast8_t binStringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_binStringToInt8N(src,len);
		}
		inline int_fast8_t octStringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_octStringToInt8N(src,len);
		}
		inline int_fast8_t hexStringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_hexStringToInt8N(src,len);
		}
		inline int_fast8_t base36StringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base36StringToInt8N(src,len);
		}
		inline int_fast8_t base62StringToInt8N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base62StringToInt8N(src,len);
		}
		
		// String to int16/uint16 converters (N)
		inline uint_fast16_t stringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringToUInt16N(src,len);
		}
		inline uint_fast16_t binStringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_binStringToUInt16N(src,len);
		}
		inline uint_fast16_t octStringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_octStringToUInt16N(src,len);
		}
		inline uint_fast16_t hexStringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_hexStringToUInt16N(src,len);
		}
		inline uint_fast16_t base36StringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base36StringToUInt16N(src,len);
		}
		inline uint_fast16_t base62StringToUInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base62StringToUInt16N(src,len);
		}
		
		inline int_fast16_t stringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringToInt16N(src,len);
		}
		inline int_fast16_t binStringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_binStringToInt16N(src,len);
		}
		inline int_fast16_t octStringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_octStringToInt16N(src,len);
		}
		inline int_fast16_t hexStringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_hexStringToInt16N(src,len);
		}
		inline int_fast16_t base36StringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base36StringToInt16N(src,len);
		}
		inline int_fast16_t base62StringToInt16N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base62StringToInt16N(src,len);
		}
		
		// String to int32/uint32 converters (N)
		inline uint_fast32_t stringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringToUInt32N(src,len);
		}
		inline uint_fast32_t binStringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_binStringToUInt32N(src,len);
		}
		inline uint_fast32_t octStringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_octStringToUInt32N(src,len);
		}
		inline uint_fast32_t hexStringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_hexStringToUInt32N(src,len);
		}
		inline uint_fast32_t base36StringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base36StringToUInt32N(src,len);
		}
		inline uint_fast32_t base62StringToUInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base62StringToUInt32N(src,len);
		}
		
		inline int_fast32_t stringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringToInt32N(src,len);
		}
		inline int_fast32_t binStringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_binStringToInt32N(src,len);
		}
		inline int_fast32_t octStringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_octStringToInt32W(src,len);
		}
		inline int_fast32_t hexStringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_hexStringToInt32W(src,len);
		}
		inline int_fast32_t base36StringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base36StringToInt32W(src,len);
		}
		inline int_fast32_t base62StringToInt32N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base62StringToInt32W(src,len);
		}
		
		// String to int64/uint64 converters (N)
		inline uint_fast64_t stringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringToUInt64N(src,len);
		}
		inline uint_fast64_t binStringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_binStringToUInt64N(src,len);
		}
		inline uint_fast64_t octStringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_octStringToUInt64N(src,len);
		}
		inline uint_fast64_t hexStringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_hexStringToUInt64N(src,len);
		}
		inline uint_fast64_t base36StringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base36StringToUInt64N(src,len);
		}
		inline uint_fast64_t base62StringToUInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base62StringToUInt64W(src,len);
		}
		
		inline int_fast64_t stringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringToInt64N(src,len);
		}
		inline int_fast64_t binStringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_binStringToInt64W(src,len);
		}
		inline int_fast64_t octStringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_octStringToInt64W(src,len);
		}
		inline int_fast64_t hexStringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_hexStringToInt64W(src,len);
		}
		inline int_fast64_t base36StringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base36StringToInt64W(src,len);
		}
		inline int_fast64_t base62StringToInt64N(const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base62StringToInt64W(src,len);
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
		inline ::size_t uInt8ToStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToStringN(des,src);
		}
		inline ::size_t uInt8ToBinStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToBinStringN(des,src);
		}
		inline ::size_t uInt8ToOctStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToOctStringN(des,src);
		}
		inline ::size_t uInt8ToHexStringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToHexStringN(des,src);
		}
		inline ::size_t uInt8ToBase36StringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToBase36StringN(des,src);
		}
		inline ::size_t uInt8ToBase62StringN(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt8ToBase62StringN(des,src);
		}
		
		inline ::size_t int8ToStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToStringN(des,src);
		}
		inline ::size_t int8ToBinStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToBinStringN(des,src);
		}
		inline ::size_t int8ToOctStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToOctStringN(des,src);
		}
		inline ::size_t int8ToHexStringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToHexStringN(des,src);
		}
		inline ::size_t int8ToBase36StringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToBase36StringN(des,src);
		}
		inline ::size_t int8ToBase62StringN(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int8ToBase62StringN(des,src);
		}
		
		// Int16/UInt16 string converters (N)
		inline ::size_t uInt16ToStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToStringN(des,src);
		}
		inline ::size_t uInt16ToBinStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToBinStringN(des,src);
		}
		inline ::size_t uInt16ToOctStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToOctStringN(des,src);
		}
		inline ::size_t uInt16ToHexStringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToHexStringN(des,src);
		}
		inline ::size_t uInt16ToBase36StringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToBase36StringN(des,src);
		}
		inline ::size_t uInt16ToBase62StringN(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt16ToBase62StringN(des,src);
		}
		
		inline ::size_t int16ToStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToStringN(des,src);
		}
		inline ::size_t int16ToBinStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToBinStringN(des,src);
		}
		inline ::size_t int16ToOctStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToOctStringN(des,src);
		}
		inline ::size_t int16ToHexStringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToHexStringN(des,src);
		}
		inline ::size_t int16ToBase36StringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToBase36StringN(des,src);
		}
		inline ::size_t int16ToBase62StringN(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int16ToBase62StringN(des,src);
		}
		
		// Int32/UInt32 string converters (N)
		inline ::size_t uInt32ToStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToStringN(des,src);
		}
		inline ::size_t uInt32ToBinStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToBinStringN(des,src);
		}
		inline ::size_t uInt32ToOctStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToOctStringN(des,src);
		}
		inline ::size_t uInt32ToHexStringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToHexStringN(des,src);
		}
		inline ::size_t uInt32ToBase36StringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToBase36StringN(des,src);
		}
		inline ::size_t uInt32ToBase62StringN(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt32ToBase62StringN(des,src);
		}
		
		inline ::size_t int32ToStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToStringN(des,src);
		}
		inline ::size_t int32ToBinStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToBinStringN(des,src);
		}
		inline ::size_t int32ToOctStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToOctStringN(des,src);
		}
		inline ::size_t int32ToHexStringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToHexStringN(des,src);
		}
		inline ::size_t int32ToBase36StringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToBase36StringN(des,src);
		}
		inline ::size_t int32ToBase62StringN(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int32ToBase62StringN(des,src);
		}
		
		// Int64/UInt64 string converters (N)
		inline ::size_t uInt64ToStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToStringN(des,src);
		}
		inline ::size_t uInt64ToBinStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToBinStringN(des,src);
		}
		inline ::size_t uInt64ToOctStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToOctStringN(des,src);
		}
		inline ::size_t uInt64ToHexStringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToHexStringN(des,src);
		}
		inline ::size_t uInt64ToBase36StringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToBase36StringN(des,src);
		}
		inline ::size_t uInt64ToBase62StringN(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_uInt64ToBase62StringN(des,src);
		}
		
		inline ::size_t int64ToStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToStringN(des,src);
		}
		inline ::size_t int64ToBinStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToBinStringN(des,src);
		}
		inline ::size_t int64ToOctStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToOctStringN(des,src);
		}
		inline ::size_t int64ToHexStringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToHexStringN(des,src);
		}
		inline ::size_t int64ToBase36StringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToBase36StringN(des,src);
		}
		inline ::size_t int64ToBase62StringN(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_int64ToBase62StringN(des,src);
		}
		
		// String to int8/uint8 converters (N)
		inline uint_fast8_t stringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringToUInt8N(src,len);
		}
		inline uint_fast8_t binStringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_binStringToUInt8N(src,len);
		}
		inline uint_fast8_t octStringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_octStringToUInt8N(src,len);
		}
		inline uint_fast8_t hexStringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_hexStringToUInt8N(src,len);
		}
		inline uint_fast8_t base36StringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base36StringToUInt8N(src,len);
		}
		inline uint_fast8_t base62StringToUInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base62StringToUInt8N(src,len);
		}
		
		inline int_fast8_t stringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringToInt8N(src,len);
		}
		inline int_fast8_t binStringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_binStringToInt8N(src,len);
		}
		inline int_fast8_t octStringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_octStringToInt8N(src,len);
		}
		inline int_fast8_t hexStringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_hexStringToInt8N(src,len);
		}
		inline int_fast8_t base36StringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base36StringToInt8N(src,len);
		}
		inline int_fast8_t base62StringToInt8N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base62StringToInt8N(src,len);
		}
		
		// String to int16/uint16 converters (N)
		inline uint_fast16_t stringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringToUInt16N(src,len);
		}
		inline uint_fast16_t binStringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_binStringToUInt16N(src,len);
		}
		inline uint_fast16_t octStringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_octStringToUInt16N(src,len);
		}
		inline uint_fast16_t hexStringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_hexStringToUInt16N(src,len);
		}
		inline uint_fast16_t base36StringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base36StringToUInt16N(src,len);
		}
		inline uint_fast16_t base62StringToUInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base62StringToUInt16N(src,len);
		}
		
		inline int_fast16_t stringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringToInt16N(src,len);
		}
		inline int_fast16_t binStringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_binStringToInt16N(src,len);
		}
		inline int_fast16_t octStringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_octStringToInt16N(src,len);
		}
		inline int_fast16_t hexStringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_hexStringToInt16N(src,len);
		}
		inline int_fast16_t base36StringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base36StringToInt16N(src,len);
		}
		inline int_fast16_t base62StringToInt16N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base62StringToInt16N(src,len);
		}
		
		// String to int32/uint32 converters (N)
		inline uint_fast32_t stringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringToUInt32N(src,len);
		}
		inline uint_fast32_t binStringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_binStringToUInt32N(src,len);
		}
		inline uint_fast32_t octStringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_octStringToUInt32N(src,len);
		}
		inline uint_fast32_t hexStringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_hexStringToUInt32N(src,len);
		}
		inline uint_fast32_t base36StringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base36StringToUInt32N(src,len);
		}
		inline uint_fast32_t base62StringToUInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base62StringToUInt32N(src,len);
		}
		
		inline int_fast32_t stringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringToInt32N(src,len);
		}
		inline int_fast32_t binStringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_binStringToInt32N(src,len);
		}
		inline int_fast32_t octStringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_octStringToInt32N(src,len);
		}
		inline int_fast32_t hexStringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_hexStringToInt32N(src,len);
		}
		inline int_fast32_t base36StringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base36StringToInt32N(src,len);
		}
		inline int_fast32_t base62StringToInt32N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base62StringToInt32N(src,len);
		}
		
		// String to int64/uint64 converters (N)
		inline uint_fast64_t stringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringToUInt64N(src,len);
		}
		inline uint_fast64_t binStringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_binStringToUInt64N(src,len);
		}
		inline uint_fast64_t octStringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_octStringToUInt64N(src,len);
		}
		inline uint_fast64_t hexStringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_hexStringToUInt64N(src,len);
		}
		inline uint_fast64_t base36StringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base36StringToUInt64N(src,len);
		}
		inline uint_fast64_t base62StringToUInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base62StringToUInt64N(src,len);
		}
		
		inline int_fast64_t stringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stringToInt64N(src,len);
		}
		inline int_fast64_t binStringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_binStringToInt64N(src,len);
		}
		inline int_fast64_t octStringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_octStringToInt64N(src,len);
		}
		inline int_fast64_t hexStringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_hexStringToInt64N(src,len);
		}
		inline int_fast64_t base36StringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base36StringToInt64N(src,len);
		}
		inline int_fast64_t base62StringToInt64N(const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_base62StringToInt64N(src,len);
		}
		
		using string_n_t=string_t<char8_t>;
		
	#endif
}
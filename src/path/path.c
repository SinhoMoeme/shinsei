#include"shinsei/minimal/path.h"

#include"shinsei/.internal/cpp_init_source.hpp"

#include"shinsei/.internal/str/ebcdic.h"
// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isEBCDICCodePage(const uint_fast32_t id)_SHINSEI_OS_NOEXCEPT{
	switch(id){
		case SHINSEI_CODE_PAGE_IBM037:
		case SHINSEI_CODE_PAGE_IBM500:
		case SHINSEI_CODE_PAGE_IBM1026:
		case SHINSEI_CODE_PAGE_IBM01140:
		case SHINSEI_CODE_PAGE_IBM01141:
		case SHINSEI_CODE_PAGE_IBM01142:
		case SHINSEI_CODE_PAGE_IBM01143:
		case SHINSEI_CODE_PAGE_IBM01144:
		case SHINSEI_CODE_PAGE_IBM01145:
		case SHINSEI_CODE_PAGE_IBM01146:
		case SHINSEI_CODE_PAGE_IBM01147:
		case SHINSEI_CODE_PAGE_IBM01148:
		case SHINSEI_CODE_PAGE_IBM01149:
		case SHINSEI_CODE_PAGE_IBM273:
		case SHINSEI_CODE_PAGE_IBM277:
		case SHINSEI_CODE_PAGE_IBM278:
		case SHINSEI_CODE_PAGE_IBM280:
		case SHINSEI_CODE_PAGE_IBM284:
		case SHINSEI_CODE_PAGE_IBM285:
		case SHINSEI_CODE_PAGE_IBM290:
		case SHINSEI_CODE_PAGE_IBM297:
		case SHINSEI_CODE_PAGE_IBM420:
		case SHINSEI_CODE_PAGE_IBM423:
		case SHINSEI_CODE_PAGE_IBM424:
		case SHINSEI_CODE_PAGE_IBM871:
		case SHINSEI_CODE_PAGE_IBM880:
		case SHINSEI_CODE_PAGE_IBM905:
		case SHINSEI_CODE_PAGE_IBM00924:
		case SHINSEI_CODE_PAGE_CP1025:
		case SHINSEI_CODE_PAGE_X_EBCDIC_KOREANEXTENDED:
		case SHINSEI_CODE_PAGE_EBCDIC_JA_KATAKANA_EXTENDED:
		case SHINSEI_CODE_PAGE_EBCDIC_US_CA_JP:
		case SHINSEI_CODE_PAGE_EBCDIC_KO_EXTENDED:
		case SHINSEI_CODE_PAGE_EBCDIC_SC_EXTENDED:
		case SHINSEI_CODE_PAGE_EBCDIC_SC:
		case SHINSEI_CODE_PAGE_EBCDIC_US_CA_TC:
		case SHINSEI_CODE_PAGE_EBCDIC_JA_LATIN_EXTENDED:{
			return true;
		}
	}
	return false;
}

// Copy from str/str.c
_SHINSEI_OS_INLINE static int charSizeU8(const char8_t starter_ch)_SHINSEI_OS_NOEXCEPT{
	return (starter_ch<=0x7F)+(((starter_ch&0xE0)==0xC0)<<1)+((starter_ch&0xF0)==0xE0)*3+(((starter_ch&0xF8)==0xF0)<<2);
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static int charSizeU16(const char16_t starter_ch)_SHINSEI_OS_NOEXCEPT{
	return (starter_ch<0xD800||starter_ch>0xDFFF)+((starter_ch>=0xD800&&starter_ch<=0xDBFF)<<1);
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static int charSizeCP(const uint_fast32_t code_page,const int starter_ch,const int second_ch,const int third_ch,int*const restrict status)_SHINSEI_OS_NOEXCEPT{
	switch(code_page){
		// Count: 105
		case SHINSEI_CODE_PAGE_AUTO:
		case SHINSEI_CODE_PAGE_IBM037:
		case SHINSEI_CODE_PAGE_IBM437:
		case SHINSEI_CODE_PAGE_IBM500:
		case SHINSEI_CODE_PAGE_ASMO_708:
		case SHINSEI_CODE_PAGE_ASMO_449:
		case SHINSEI_CODE_PAGE_TRANSPARENT_ARABIC:
		case SHINSEI_CODE_PAGE_DOS_720:
		case SHINSEI_CODE_PAGE_IBM737:
		case SHINSEI_CODE_PAGE_IBM775:
		case SHINSEI_CODE_PAGE_IBM850:
		case SHINSEI_CODE_PAGE_IBM852:
		case SHINSEI_CODE_PAGE_IBM855:
		case SHINSEI_CODE_PAGE_IBM857:
		case SHINSEI_CODE_PAGE_IBM00858:
		case SHINSEI_CODE_PAGE_IBM860:
		case SHINSEI_CODE_PAGE_IBM861:
		case SHINSEI_CODE_PAGE_IBM862:
		case SHINSEI_CODE_PAGE_IBM863:
		case SHINSEI_CODE_PAGE_IBM864:
		case SHINSEI_CODE_PAGE_IBM865:
		case SHINSEI_CODE_PAGE_CP866:
		case SHINSEI_CODE_PAGE_IBM869:
		case SHINSEI_CODE_PAGE_IBM870:
		case SHINSEI_CODE_PAGE_WINDOWS_874:
		case SHINSEI_CODE_PAGE_CP875:
		case SHINSEI_CODE_PAGE_IBM1026:
		case SHINSEI_CODE_PAGE_IBM01047:
		case SHINSEI_CODE_PAGE_IBM01140:
		case SHINSEI_CODE_PAGE_IBM01141:
		case SHINSEI_CODE_PAGE_IBM01142:
		case SHINSEI_CODE_PAGE_IBM01143:
		case SHINSEI_CODE_PAGE_IBM01144:
		case SHINSEI_CODE_PAGE_IBM01145:
		case SHINSEI_CODE_PAGE_IBM01146:
		case SHINSEI_CODE_PAGE_IBM01147:
		case SHINSEI_CODE_PAGE_IBM01148:
		case SHINSEI_CODE_PAGE_IBM01149:
		case SHINSEI_CODE_PAGE_WINDOWS_1250:
		case SHINSEI_CODE_PAGE_WINDOWS_1251:
		case SHINSEI_CODE_PAGE_WINDOWS_1252:
		case SHINSEI_CODE_PAGE_WINDOWS_1253:
		case SHINSEI_CODE_PAGE_WINDOWS_1254:
		case SHINSEI_CODE_PAGE_WINDOWS_1255:
		case SHINSEI_CODE_PAGE_WINDOWS_1256:
		case SHINSEI_CODE_PAGE_WINDOWS_1257:
		case SHINSEI_CODE_PAGE_WINDOWS_1258:
		case SHINSEI_CODE_PAGE_MACINTOSH:
		case SHINSEI_CODE_PAGE_X_MAC_ARABIC:
		case SHINSEI_CODE_PAGE_X_MAC_HEBREW:
		case SHINSEI_CODE_PAGE_X_MAC_GREEK:
		case SHINSEI_CODE_PAGE_X_MAC_CYRILLIC:
		case SHINSEI_CODE_PAGE_X_MAC_ROMANIAN:
		case SHINSEI_CODE_PAGE_X_MAC_UKRAINIAN:
		case SHINSEI_CODE_PAGE_X_MAC_THAI:
		case SHINSEI_CODE_PAGE_X_MAC_MAC_CE:
		case SHINSEI_CODE_PAGE_X_MAC_ICELANDIC:
		case SHINSEI_CODE_PAGE_X_MAC_TURKISH:
		case SHINSEI_CODE_PAGE_X_MAC_CROATIAN:
		case SHINSEI_CODE_PAGE_X_CHINESE_CNS: // Native CNS is SBCS until shifted
		case SHINSEI_CODE_PAGE_X_CP20001:
		case SHINSEI_CODE_PAGE_X_CHINESE_ETEN:
		case SHINSEI_CODE_PAGE_X_CP20003:
		case SHINSEI_CODE_PAGE_X_CP20004:
		case SHINSEI_CODE_PAGE_X_CP20005:
		case SHINSEI_CODE_PAGE_X_IA5:
		case SHINSEI_CODE_PAGE_X_IA5_GERMAN:
		case SHINSEI_CODE_PAGE_X_IA5_SWEDISH:
		case SHINSEI_CODE_PAGE_X_IA5_NORWEGIAN:
		case SHINSEI_CODE_PAGE_US_ASCII:
		case SHINSEI_CODE_PAGE_X_CP20261:
		case SHINSEI_CODE_PAGE_X_CP20269:
		case SHINSEI_CODE_PAGE_IBM273:
		case SHINSEI_CODE_PAGE_IBM277:
		case SHINSEI_CODE_PAGE_IBM278:
		case SHINSEI_CODE_PAGE_IBM280:
		case SHINSEI_CODE_PAGE_IBM284:
		case SHINSEI_CODE_PAGE_IBM285:
		case SHINSEI_CODE_PAGE_IBM290:
		case SHINSEI_CODE_PAGE_IBM297:
		case SHINSEI_CODE_PAGE_IBM420:
		case SHINSEI_CODE_PAGE_IBM423:
		case SHINSEI_CODE_PAGE_IBM424:
		case SHINSEI_CODE_PAGE_IBM_THAI:
		case SHINSEI_CODE_PAGE_KOI8_R:
		case SHINSEI_CODE_PAGE_IBM871:
		case SHINSEI_CODE_PAGE_IBM880:
		case SHINSEI_CODE_PAGE_IBM905:
		case SHINSEI_CODE_PAGE_IBM00924:
		case SHINSEI_CODE_PAGE_CP1025:
		case SHINSEI_CODE_PAGE_DEPRECATED:
		case SHINSEI_CODE_PAGE_KOI8_U:
		case SHINSEI_CODE_PAGE_ISO_8859_1:
		case SHINSEI_CODE_PAGE_ISO_8859_2:
		case SHINSEI_CODE_PAGE_ISO_8859_3:
		case SHINSEI_CODE_PAGE_ISO_8859_4:
		case SHINSEI_CODE_PAGE_ISO_8859_5:
		case SHINSEI_CODE_PAGE_ISO_8859_6:
		case SHINSEI_CODE_PAGE_ISO_8859_7:
		case SHINSEI_CODE_PAGE_ISO_8859_8:
		case SHINSEI_CODE_PAGE_ISO_8859_9:
		case SHINSEI_CODE_PAGE_ISO_8859_13:
		case SHINSEI_CODE_PAGE_ISO_8859_15:
		case SHINSEI_CODE_PAGE_X_EUROPA:
		case SHINSEI_CODE_PAGE_ISO_8859_8_I:{
			return 1;
		}
		
		// Count: 2
		case SHINSEI_CODE_PAGE_UTF_32:
		case SHINSEI_CODE_PAGE_UTF_32BE:{
			return 4;
		}
		
		// Count: 3
		case SHINSEI_CODE_PAGE_UTF_8:{
			return charSizeU8((char8_t)starter_ch);
		}
		case SHINSEI_CODE_PAGE_UTF_16:{
			return charSizeU16((char16_t)(starter_ch|(second_ch<<8)))<<1;
		}
		case SHINSEI_CODE_PAGE_UNICODEFFFE:{
			// Big Endian
			return charSizeU16((char16_t)((starter_ch<<8)|second_ch))<<1;
		}
	
		// Count: 13
		case SHINSEI_CODE_PAGE_SHIFT_JIS:
		case SHINSEI_CODE_PAGE_X_MAC_JAPANESE:{
			return 1+((starter_ch>=0x81&&starter_ch<=0x9F)||(starter_ch>=0xE0&&starter_ch<=0xFC));
		}
		case SHINSEI_CODE_PAGE_GB2312:
		case SHINSEI_CODE_PAGE_KS_C_5601_1987:
		case SHINSEI_CODE_PAGE_BIG5:
		case SHINSEI_CODE_PAGE_EUC_CN:
		case SHINSEI_CODE_PAGE_EUC_KR:
		case SHINSEI_CODE_PAGE_EUC_TC:
		case SHINSEI_CODE_PAGE_X_CP20936:
		case SHINSEI_CODE_PAGE_X_CP20949:
		case SHINSEI_CODE_PAGE_X_MAC_CHINESESIMP:
		case SHINSEI_CODE_PAGE_X_MAC_CHINESETRAD:
		case SHINSEI_CODE_PAGE_X_MAC_KOREAN:{
			return 1+(starter_ch>=0x81&&starter_ch<=0xFE);
		}
		case SHINSEI_CODE_PAGE_JOHAB:{
			return 1+((starter_ch>=0x84&&starter_ch<=0xD3)||(starter_ch>=0xD8&&starter_ch<=0xDE)||(starter_ch>=0xE0&&starter_ch<=0xF9));
		}
	
		// Count: 3
		case SHINSEI_CODE_PAGE_EUC_JP:
		case SHINSEI_CODE_PAGE_EUC_JP_LEGACY:{
			return 1+(starter_ch>=0xA1&&starter_ch<=0xFE)+(starter_ch==0x8E)+((starter_ch==0x8F)<<1);
		}
		case SHINSEI_CODE_PAGE_GB18030:{
			register const int is_mb=starter_ch>=0x81&&starter_ch<=0xFE;
			register const int is_4b=is_mb&(second_ch>=0x30&&second_ch<=0x39);
			return 1+is_mb+(is_4b<<1);
		}
	
		// Count: 26
		case SHINSEI_CODE_PAGE_ISO_2022_JP:
		case SHINSEI_CODE_PAGE_CSISO2022JP:
		case SHINSEI_CODE_PAGE_ISO_2022_JP_EXT:
		case SHINSEI_CODE_PAGE_ISO_2022_KR:
		case SHINSEI_CODE_PAGE_X_CP50227:
		case SHINSEI_CODE_PAGE_ISO_2022_TC:{
			// ISO-2022 Shift Sequence triggers on ESC (0x1B)
			// Read the next sequence bytes.
			// If sequence is e.g. ESC $ B / ESC $ @ / ESC $ A -> set status = 1 (DBCS mode).
			// If sequence is e.g. ESC ( B / ESC ( J / ESC ( H -> set status = 0 (ASCII/SBCS mode).
			// Advance pointer past all sequence bytes.
			if(starter_ch==0x1B){
				if(second_ch=='$'&&__builtin_expect(third_ch=='B'||third_ch=='@'||third_ch=='A',1)){
					*status=1;
				}
				if(second_ch=='('&&__builtin_expect(third_ch=='B'||third_ch=='J'||third_ch=='H',1)){
					*status=0;
				}
				return 3;
			}
			return 1+(bool)*status;
		}
		case SHINSEI_CODE_PAGE_X_EBCDIC_KOREANEXTENDED:
		case SHINSEI_CODE_PAGE_EBCDIC_JA_KATAKANA_EXTENDED:
		case SHINSEI_CODE_PAGE_EBCDIC_US_CA_JP:
		case SHINSEI_CODE_PAGE_EBCDIC_KO_EXTENDED:
		case SHINSEI_CODE_PAGE_EBCDIC_SC_EXTENDED:
		case SHINSEI_CODE_PAGE_EBCDIC_SC:
		case SHINSEI_CODE_PAGE_EBCDIC_US_CA_TC:
		case SHINSEI_CODE_PAGE_EBCDIC_JA_LATIN_EXTENDED:{
			// EBCDIC Shift-In (0x0F) and Shift-Out (0x0E)
			// Check starter_ch.
			// If 0x0E (Shift-Out) -> set status = 1 (DBCS mode).
			// If 0x0F (Shift-In)  -> set status = 0 (SBCS mode).
			// Advance pointer past this 1 byte.
			if(starter_ch==0x0E||starter_ch==0x0F){
				*status=starter_ch==0x0E;
				return 1;
			}
			return 1+(bool)*status;
		}
		case SHINSEI_CODE_PAGE_HZ_GB_2312:{
			// HZ Escapes trigger on Tilde (~)
			// Read the next byte.
			// If next byte is '{' -> set status = 1 (DBCS GB2312 mode).
			// If next byte is '}' -> set status = 0 (SBCS ASCII mode).
			// If next byte is '~' -> it is an escaped literal tilde character.
			// Advance pointer past both the '~' and the following byte.
			if(starter_ch==0x7E){
				if(second_ch=='{'||second_ch=='}'){
					*status=(second_ch=='{');
				}
				return 2;
			}
			return 1+(bool)*status;
		}
		case SHINSEI_CODE_PAGE_UTF_7:{
			// UTF-7 shifts via '+' and '-'
			// Check starter_ch.
			// If '+' -> set status = 1 (Modified Base64 mode).
			// If '-' -> set status = 0 (ASCII mode).
			// Advance pointer past this 1 byte.
			if(starter_ch=='+'||starter_ch=='-'){
				*status=starter_ch=='+';
			}
			return 1; 
		}
		case SHINSEI_CODE_PAGE_X_ISCII_DE:
		case SHINSEI_CODE_PAGE_X_ISCII_BE:
		case SHINSEI_CODE_PAGE_X_ISCII_TA:
		case SHINSEI_CODE_PAGE_X_ISCII_TE:
		case SHINSEI_CODE_PAGE_X_ISCII_AS:
		case SHINSEI_CODE_PAGE_X_ISCII_OR:
		case SHINSEI_CODE_PAGE_X_ISCII_KA:
		case SHINSEI_CODE_PAGE_X_ISCII_MA:
		case SHINSEI_CODE_PAGE_X_ISCII_GU:
		case SHINSEI_CODE_PAGE_X_ISCII_PA:{
			// ISCII Ext (ATR / ESC codes)
			// HOW TO HANDLE -1: Read the next byte(s) following 0xEF.
			// This sequence determines font/language shifting or extension blocks.
			// Update parser state/status accordingly. Advance pointer past sequence bytes.
			if(starter_ch==0xEF){
				*status=second_ch;
				return 2;
			}
			return 1;
		}
	}
	return 0;
}

// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isLowerASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-'a')<=25;
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isLowerEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0x81)<=8||(unsigned int)(ch-0x91)<=8||(unsigned int)(ch-0xA2)<=7;
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isLowerCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isLowerEBCDIC(ch)+!ebcdic*isLowerASCII(ch);
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isLowerW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-L'a')<=25;
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isLowerU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-u8'a')<=25;
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isLowerU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-u'a')<=25;
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isLowerU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-U'a')<=25;
}

// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isUpperEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0xC1)<=8||(unsigned int)(ch-0xD1)<=8||(unsigned int)(ch-0xE2)<=7;
}

// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isAlphaASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)((ch|0x20)-'a')<=25;
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isAlphaEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return isUpperEBCDIC(ch)||isLowerEBCDIC(ch);
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isAlphaCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isAlphaEBCDIC(ch)+!ebcdic*isAlphaASCII(ch);
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isAlphaU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)((ch|0x20)-u8'a')<=25;
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isAlphaU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)((ch|0x20)-u'a')<=25;
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isAlphaU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)((ch|0x20)-U'a')<=25;
}
// Rewrite from str/str.c
_SHINSEI_OS_INLINE static bool isAlphaW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)((ch|0x20)-L'a')<=25;
}

// Copy from str/str.c
_SHINSEI_OS_INLINE static int toUpperASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch-(isLowerASCII(ch)<<5);
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static int toUpperEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch+(isLowerEBCDIC(ch)<<6);
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static int toUpperCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*toUpperEBCDIC(ch)+!ebcdic*toUpperASCII(ch);
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static char8_t toUpperU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch-(char8_t)(isLowerU8(ch)<<5);
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static char16_t toUpperU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch-(char16_t)(isLowerU16(ch)<<5);
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static char32_t toUpperU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch-(isLowerU32(ch)<<5);
}
// Rewrite from str/str.c
_SHINSEI_OS_INLINE static wint_t toUpperW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch-(wint_t)(isLowerW(ch)<<5);
}

_SHINSEI_OS_INLINE static bool isWindowsPathDelimiterASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_WINDOWS_DELIMITER_ASCII||ch==SHINSEI_PATH_UNIX_DELIMITER_ASCII;
}
_SHINSEI_OS_INLINE static bool isWindowsPathDelimiterEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_WINDOWS_DELIMITER_EBCDIC||ch==SHINSEI_PATH_UNIX_DELIMITER_EBCDIC;
}
_SHINSEI_OS_INLINE static bool isWindowsPathDelimiterCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isWindowsPathDelimiterEBCDIC(ch)+!ebcdic*isWindowsPathDelimiterASCII(ch);
}
_SHINSEI_OS_INLINE static bool isWindowsPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_WINDOWS_DELIMITER_U8||ch==SHINSEI_PATH_UNIX_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isWindowsPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==SHINSEI_PATH_WINDOWS_DELIMITER_U8||(*str_ptr)[-1]==SHINSEI_PATH_UNIX_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isWindowsPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_WINDOWS_DELIMITER_U16||ch==SHINSEI_PATH_UNIX_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isWindowsPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==SHINSEI_PATH_WINDOWS_DELIMITER_U16||(*str_ptr)[-1]==SHINSEI_PATH_UNIX_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isWindowsPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_WINDOWS_DELIMITER_U32||ch==SHINSEI_PATH_UNIX_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isWindowsPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]==SHINSEI_PATH_WINDOWS_DELIMITER_U32||(*str_ptr)[-1]==SHINSEI_PATH_UNIX_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isWindowsPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_WINDOWS_DELIMITER_W||ch==SHINSEI_PATH_UNIX_DELIMITER_W;
}

bool shinsei_isWindowsPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isWindowsPathDelimiterW(ch);
}
bool shinsei_isWindowsPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isWindowsPathDelimiterU32M((const char32_t**)str_ptr,len);
	#else
		return isWindowsPathDelimiterU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isWindowsPathDelimiterCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isWindowsPathDelimiterCP(code_page,ch);
}
bool shinsei_isWindowsPathDelimiterCPM(const uint_fast32_t code_page,const char** const restrict str_ptr,const size_t len,int*const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return false;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return isWindowsPathDelimiterCP(code_page,starter_ch);
}
bool shinsei_isWindowsPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isWindowsPathDelimiterU8(ch);
}
bool shinsei_isWindowsPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isWindowsPathDelimiterU8M(str_ptr,len);
}
bool shinsei_isWindowsPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isWindowsPathDelimiterU16(ch);
}
bool shinsei_isWindowsPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isWindowsPathDelimiterU16M(str_ptr,len);
}
bool shinsei_isWindowsPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isWindowsPathDelimiterU32(ch);
}
bool shinsei_isWindowsPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isWindowsPathDelimiterU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isUnixPathDelimiterASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_UNIX_DELIMITER_ASCII;
}
_SHINSEI_OS_INLINE static bool isUnixPathDelimiterEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_UNIX_DELIMITER_EBCDIC;
}
_SHINSEI_OS_INLINE static bool isUnixPathDelimiterCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isUnixPathDelimiterEBCDIC(ch)+!ebcdic*isUnixPathDelimiterASCII(ch);
}
_SHINSEI_OS_INLINE static bool isUnixPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_UNIX_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isUnixPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==SHINSEI_PATH_UNIX_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isUnixPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_UNIX_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isUnixPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==SHINSEI_PATH_UNIX_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isUnixPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_UNIX_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isUnixPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]==SHINSEI_PATH_UNIX_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isUnixPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_UNIX_DELIMITER_W;
}

bool shinsei_isUnixPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isUnixPathDelimiterW(ch);
}
bool shinsei_isUnixPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isUnixPathDelimiterU32M((const char32_t**)str_ptr,len);
	#else
		return isUnixPathDelimiterU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isUnixPathDelimiterCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isUnixPathDelimiterCP(code_page,ch);
}
bool shinsei_isUnixPathDelimiterCPM(const uint_fast32_t code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return false;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return isUnixPathDelimiterCP(code_page,starter_ch);
}
bool shinsei_isUnixPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isUnixPathDelimiterU8(ch);
}
bool shinsei_isUnixPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isUnixPathDelimiterU8M(str_ptr,len);
}
bool shinsei_isUnixPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isUnixPathDelimiterU16(ch);
}
bool shinsei_isUnixPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isUnixPathDelimiterU16M(str_ptr,len);
}
bool shinsei_isUnixPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isUnixPathDelimiterU32(ch);
}
bool shinsei_isUnixPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isUnixPathDelimiterU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isLinuxPathDelimiterASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_LINUX_DELIMITER_ASCII;
}
_SHINSEI_OS_INLINE static bool isLinuxPathDelimiterEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_LINUX_DELIMITER_EBCDIC;
}
_SHINSEI_OS_INLINE static bool isLinuxPathDelimiterCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isLinuxPathDelimiterEBCDIC(ch)+!ebcdic*isLinuxPathDelimiterASCII(ch);
}
_SHINSEI_OS_INLINE static bool isLinuxPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_LINUX_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isLinuxPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==SHINSEI_PATH_LINUX_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isLinuxPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_LINUX_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isLinuxPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==SHINSEI_PATH_LINUX_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isLinuxPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_LINUX_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isLinuxPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]==SHINSEI_PATH_LINUX_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isLinuxPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_LINUX_DELIMITER_W;
}

bool shinsei_isLinuxPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isLinuxPathDelimiterW(ch);
}
bool shinsei_isLinuxPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isLinuxPathDelimiterU32M((const char32_t**)str_ptr,len);
	#else
		return isLinuxPathDelimiterU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isLinuxPathDelimiterCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isLinuxPathDelimiterCP(code_page,ch);
}
bool shinsei_isLinuxPathDelimiterCPM(const uint_fast32_t code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return false;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return isLinuxPathDelimiterCP(code_page,starter_ch);
}
bool shinsei_isLinuxPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isLinuxPathDelimiterU8(ch);
}
bool shinsei_isLinuxPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isLinuxPathDelimiterU8M(str_ptr,len);
}
bool shinsei_isLinuxPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isLinuxPathDelimiterU16(ch);
}
bool shinsei_isLinuxPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isLinuxPathDelimiterU16M(str_ptr,len);
}
bool shinsei_isLinuxPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isLinuxPathDelimiterU32(ch);
}
bool shinsei_isLinuxPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isLinuxPathDelimiterU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isApplePathDelimiterASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_APPLE_DELIMITER_ASCII;
}
_SHINSEI_OS_INLINE static bool isApplePathDelimiterEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_APPLE_DELIMITER_EBCDIC;
}
_SHINSEI_OS_INLINE static bool isApplePathDelimiterCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isApplePathDelimiterEBCDIC(ch)+!ebcdic*isApplePathDelimiterASCII(ch);
}
_SHINSEI_OS_INLINE static bool isApplePathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_APPLE_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isApplePathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==SHINSEI_PATH_APPLE_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isApplePathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_APPLE_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isApplePathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==SHINSEI_PATH_APPLE_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isApplePathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_APPLE_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isApplePathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]==SHINSEI_PATH_APPLE_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isApplePathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_APPLE_DELIMITER_W;
}

bool shinsei_isApplePathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isApplePathDelimiterW(ch);
}
bool shinsei_isApplePathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isApplePathDelimiterU32M((const char32_t**)str_ptr,len);
	#else
		return isApplePathDelimiterU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isApplePathDelimiterCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isApplePathDelimiterCP(code_page,ch);
}
bool shinsei_isApplePathDelimiterCPM(const uint_fast32_t code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return false;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return isApplePathDelimiterCP(code_page,starter_ch);
}
bool shinsei_isApplePathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isApplePathDelimiterU8(ch);
}
bool shinsei_isApplePathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isApplePathDelimiterU8M(str_ptr,len);
}
bool shinsei_isApplePathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isApplePathDelimiterU16(ch);
}
bool shinsei_isApplePathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isApplePathDelimiterU16M(str_ptr,len);
}
bool shinsei_isApplePathDelimiterU32(const char32_t ch){
	return isApplePathDelimiterU32(ch);
}
bool shinsei_isApplePathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isApplePathDelimiterU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isSunPathDelimiterASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_SUN_DELIMITER_ASCII;
}
_SHINSEI_OS_INLINE static bool isSunPathDelimiterEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_SUN_DELIMITER_EBCDIC;
}
_SHINSEI_OS_INLINE static bool isSunPathDelimiterCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isSunPathDelimiterEBCDIC(ch)+!ebcdic*isSunPathDelimiterASCII(ch);
}
_SHINSEI_OS_INLINE static bool isSunPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_SUN_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isSunPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==SHINSEI_PATH_SUN_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isSunPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_SUN_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isSunPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==SHINSEI_PATH_SUN_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isSunPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_SUN_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isSunPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]==SHINSEI_PATH_SUN_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isSunPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_SUN_DELIMITER_W;
}

bool shinsei_isSunPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isSunPathDelimiterW(ch);
}
bool shinsei_isSunPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isSunPathDelimiterU32M((const char32_t**)str_ptr,len);
	#else
		return isSunPathDelimiterU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isSunPathDelimiterCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isSunPathDelimiterCP(code_page,ch);
}
bool shinsei_isSunPathDelimiterCPM(const uint_fast32_t code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return false;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return isSunPathDelimiterCP(code_page,starter_ch);
}
bool shinsei_isSunPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isSunPathDelimiterU8(ch);
}
bool shinsei_isSunPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isSunPathDelimiterU8M(str_ptr,len);
}
bool shinsei_isSunPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isSunPathDelimiterU16(ch);
}
bool shinsei_isSunPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isSunPathDelimiterU16M(str_ptr,len);
}
bool shinsei_isSunPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isSunPathDelimiterU32(ch);
}
bool shinsei_isSunPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isSunPathDelimiterU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isFreeBSDPathDelimiterASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_FREEBSD_DELIMITER_ASCII;
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathDelimiterEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_FREEBSD_DELIMITER_EBCDIC;
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathDelimiterCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isFreeBSDPathDelimiterEBCDIC(ch)+!ebcdic*isFreeBSDPathDelimiterASCII(ch);
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_FREEBSD_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==SHINSEI_PATH_FREEBSD_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_FREEBSD_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==SHINSEI_PATH_FREEBSD_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_FREEBSD_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]==SHINSEI_PATH_FREEBSD_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_FREEBSD_DELIMITER_W;
}

bool shinsei_isFreeBSDPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isFreeBSDPathDelimiterW(ch);
}
bool shinsei_isFreeBSDPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isFreeBSDPathDelimiterU32M((const char32_t**)str_ptr,len);
	#else
		return isFreeBSDPathDelimiterU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isFreeBSDPathDelimiterCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isFreeBSDPathDelimiterCP(code_page,ch);
}
bool shinsei_isFreeBSDPathDelimiterCPM(const uint_fast32_t code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return false;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return isFreeBSDPathDelimiterCP(code_page,starter_ch);
}
bool shinsei_isFreeBSDPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isFreeBSDPathDelimiterU8(ch);
}
bool shinsei_isFreeBSDPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isFreeBSDPathDelimiterU8M(str_ptr,len);
}
bool shinsei_isFreeBSDPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isFreeBSDPathDelimiterU16(ch);
}
bool shinsei_isFreeBSDPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isFreeBSDPathDelimiterU16M(str_ptr,len);
}
bool shinsei_isFreeBSDPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isFreeBSDPathDelimiterU32(ch);
}
bool shinsei_isFreeBSDPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isFreeBSDPathDelimiterU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isCygwinPathDelimiterASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_CYGWIN_DELIMITER_ASCII;
}
_SHINSEI_OS_INLINE static bool isCygwinPathDelimiterEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_CYGWIN_DELIMITER_EBCDIC;
}
_SHINSEI_OS_INLINE static bool isCygwinPathDelimiterCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isCygwinPathDelimiterEBCDIC(ch)+!ebcdic*isCygwinPathDelimiterASCII(ch);
}
_SHINSEI_OS_INLINE static bool isCygwinPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_CYGWIN_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isCygwinPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==SHINSEI_PATH_CYGWIN_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isCygwinPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_CYGWIN_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isCygwinPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==SHINSEI_PATH_CYGWIN_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isCygwinPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_CYGWIN_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isCygwinPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]==SHINSEI_PATH_CYGWIN_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isCygwinPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_CYGWIN_DELIMITER_W;
}

bool shinsei_isCygwinPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isCygwinPathDelimiterW(ch);
}
bool shinsei_isCygwinPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isCygwinPathDelimiterU32M((const char32_t**)str_ptr,len);
	#else
		return isCygwinPathDelimiterU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isCygwinPathDelimiterCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isCygwinPathDelimiterCP(code_page,ch);
}
bool shinsei_isCygwinPathDelimiterCPM(const uint_fast32_t code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return false;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return isCygwinPathDelimiterCP(code_page,starter_ch);
}
bool shinsei_isCygwinPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isCygwinPathDelimiterU8(ch);
}
bool shinsei_isCygwinPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isCygwinPathDelimiterU8M(str_ptr,len);
}
bool shinsei_isCygwinPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isCygwinPathDelimiterU16(ch);
}
bool shinsei_isCygwinPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isCygwinPathDelimiterU16M(str_ptr,len);
}
bool shinsei_isCygwinPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isCygwinPathDelimiterU32(ch);
}
bool shinsei_isCygwinPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isCygwinPathDelimiterU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isURLPathDelimiterASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_URL_DELIMITER_ASCII;
}
_SHINSEI_OS_INLINE static bool isURLPathDelimiterEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_URL_DELIMITER_EBCDIC;
}
_SHINSEI_OS_INLINE static bool isURLPathDelimiterCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isURLPathDelimiterEBCDIC(ch)+!ebcdic*isURLPathDelimiterASCII(ch);
}
_SHINSEI_OS_INLINE static bool isURLPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_URL_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isURLPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==SHINSEI_PATH_URL_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isURLPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_URL_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isURLPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==SHINSEI_PATH_URL_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isURLPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_URL_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isURLPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]==SHINSEI_PATH_URL_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isURLPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==SHINSEI_PATH_URL_DELIMITER_W;
}

bool shinsei_isURLPathDelimiterW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isURLPathDelimiterW(ch);
}
bool shinsei_isURLPathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isURLPathDelimiterU32M((const char32_t**)str_ptr,len);
	#else
		return isURLPathDelimiterU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isURLPathDelimiterCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isURLPathDelimiterCP(code_page,ch);
}
bool shinsei_isURLPathDelimiterCPM(const uint_fast32_t code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return false;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return isURLPathDelimiterCP(code_page,starter_ch);
}
bool shinsei_isURLPathDelimiterU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isURLPathDelimiterU8(ch);
}
bool shinsei_isURLPathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isURLPathDelimiterU8M(str_ptr,len);
}
bool shinsei_isURLPathDelimiterU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isURLPathDelimiterU16(ch);
}
bool shinsei_isURLPathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isURLPathDelimiterU16M(str_ptr,len);
}
bool shinsei_isURLPathDelimiterU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isURLPathDelimiterU32(ch);
}
bool shinsei_isURLPathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isURLPathDelimiterU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isWindowsPathIllegalCharASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	if((unsigned int)ch<32) return true;
	return ch=='"'||ch=='*'||ch=='/'||ch=='\\'||ch==':'||ch=='<'||ch=='>'||ch=='?'||ch=='|';
}
_SHINSEI_OS_INLINE static bool isWindowsPathIllegalCharEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	if((unsigned int)ch<=0x3F||ch==0xFF) return true;
	return ch==0x7F||ch==0x5C||ch==0x61||ch==0xE0||ch==0x7A||ch==0x4C||ch==0x6E||ch==0x6F||ch==0x4F;
}
_SHINSEI_OS_INLINE static bool isWindowsPathIllegalCharCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isWindowsPathIllegalCharEBCDIC(ch)+!ebcdic*isWindowsPathIllegalCharASCII(ch);
}
_SHINSEI_OS_INLINE static bool isWindowsPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	if((unsigned int)ch<32) return true;
	return ch==u8'"'||ch==u8'*'||ch==u8'/'||ch==u8'\\'||ch==u8':'||ch==u8'<'||ch==u8'>'||ch==u8'?'||ch==u8'|';
}
_SHINSEI_OS_INLINE static bool isWindowsPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	register const char8_t c=(*str_ptr)[-1];
	if((unsigned int)c<32) return true;
	return c==u8'"'||c==u8'*'||c==u8'/'||c==u8'\\'||c==u8':'||c==u8'<'||c==u8'>'||c==u8'?'||c==u8'|';
}
_SHINSEI_OS_INLINE static bool isWindowsPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	if((unsigned int)ch<32) return true;
	return ch==u'"'||ch==u'*'||ch==u'/'||ch==u'\\'||ch==u':'||ch==u'<'||ch==u'>'||ch==u'?'||ch==u'|';
}
_SHINSEI_OS_INLINE static bool isWindowsPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	register const char16_t c=(*str_ptr)[-1];
	if((unsigned int)c<32) return true;
	return c==u'"'||c==u'*'||c==u'/'||c==u'\\'||c==u':'||c==u'<'||c==u'>'||c==u'?'||c==u'|';
}
_SHINSEI_OS_INLINE static bool isWindowsPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	if((unsigned int)ch<32) return true;
	return ch==U'"'||ch==U'*'||ch==U'/'||ch==U'\\'||ch==U':'||ch==U'<'||ch==U'>'||ch==U'?'||ch==U'|';
}
_SHINSEI_OS_INLINE static bool isWindowsPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	register const char32_t c=(*str_ptr)[-1];
	if((unsigned int)c<32) return true;
	return c==U'"'||c==U'*'||c==U'/'||c==U'\\'||c==U':'||c==U'<'||c==U'>'||c==U'?'||c==U'|';
}
_SHINSEI_OS_INLINE static bool isWindowsPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	if((unsigned int)ch<32) return true;
	return ch==L'"'||ch==L'*'||ch==L'/'||ch==L'\\'||ch==L':'||ch==L'<'||ch==L'>'||ch==L'?'||ch==L'|';
}

bool shinsei_isWindowsPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isWindowsPathIllegalCharW(ch);
}
bool shinsei_isWindowsPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isWindowsPathIllegalCharU32M((const char32_t**)str_ptr,len);
	#else
		return isWindowsPathIllegalCharU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isWindowsPathIllegalCharCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isWindowsPathIllegalCharCP(code_page,ch);
}
bool shinsei_isWindowsPathIllegalCharCPM(const uint_fast32_t code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return false;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return isWindowsPathIllegalCharCP(code_page,starter_ch);
}
bool shinsei_isWindowsPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isWindowsPathIllegalCharU8(ch);
}
bool shinsei_isWindowsPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isWindowsPathIllegalCharU8M(str_ptr,len);
}
bool shinsei_isWindowsPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isWindowsPathIllegalCharU16(ch);
}
bool shinsei_isWindowsPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isWindowsPathIllegalCharU16M(str_ptr,len);
}
bool shinsei_isWindowsPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isWindowsPathIllegalCharU32(ch);
}
bool shinsei_isWindowsPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isWindowsPathIllegalCharU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isUnixPathIllegalCharASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch=='\0'||ch==SHINSEI_PATH_UNIX_DELIMITER_ASCII;
}
_SHINSEI_OS_INLINE static bool isUnixPathIllegalCharEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch=='\0'||ch==SHINSEI_PATH_UNIX_DELIMITER_EBCDIC;
}
_SHINSEI_OS_INLINE static bool isUnixPathIllegalCharCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isUnixPathIllegalCharEBCDIC(ch)+!ebcdic*isUnixPathIllegalCharASCII(ch);
}
_SHINSEI_OS_INLINE static bool isUnixPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==u8'\0'||ch==SHINSEI_PATH_UNIX_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isUnixPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==u8'\0'||(*str_ptr)[-1]==SHINSEI_PATH_UNIX_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isUnixPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==u'\0'||ch==SHINSEI_PATH_UNIX_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isUnixPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==u'\0'||(*str_ptr)[-1]==SHINSEI_PATH_UNIX_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isUnixPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==U'\0'||ch==SHINSEI_PATH_UNIX_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isUnixPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]==U'\0'||(*str_ptr)[-1]==SHINSEI_PATH_UNIX_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isUnixPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==L'\0'||ch==SHINSEI_PATH_UNIX_DELIMITER_W;
}

bool shinsei_isUnixPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isUnixPathIllegalCharW(ch);
}
bool shinsei_isUnixPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isUnixPathIllegalCharU32M((const char32_t**)str_ptr,len);
	#else
		return isUnixPathIllegalCharU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isUnixPathIllegalCharCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isUnixPathIllegalCharCP(code_page,ch);
}
bool shinsei_isUnixPathIllegalCharCPM(const uint_fast32_t code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return false;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return isUnixPathIllegalCharCP(code_page,starter_ch);
}
bool shinsei_isUnixPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isUnixPathIllegalCharU8(ch);
}
bool shinsei_isUnixPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isUnixPathIllegalCharU8M(str_ptr,len);
}
bool shinsei_isUnixPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isUnixPathIllegalCharU16(ch);
}
bool shinsei_isUnixPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isUnixPathIllegalCharU16M(str_ptr,len);
}
bool shinsei_isUnixPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isUnixPathIllegalCharU32(ch);
}
bool shinsei_isUnixPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isUnixPathIllegalCharU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isLinuxPathIllegalCharASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch=='\0'||ch==SHINSEI_PATH_LINUX_DELIMITER_ASCII;
}
_SHINSEI_OS_INLINE static bool isLinuxPathIllegalCharEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch=='\0'||ch==SHINSEI_PATH_LINUX_DELIMITER_EBCDIC;
}
_SHINSEI_OS_INLINE static bool isLinuxPathIllegalCharCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isLinuxPathIllegalCharEBCDIC(ch)+!ebcdic*isLinuxPathIllegalCharASCII(ch);
}
_SHINSEI_OS_INLINE static bool isLinuxPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==u8'\0'||ch==SHINSEI_PATH_LINUX_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isLinuxPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==u8'\0'||(*str_ptr)[-1]==SHINSEI_PATH_LINUX_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isLinuxPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==u'\0'||ch==SHINSEI_PATH_LINUX_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isLinuxPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==u'\0'||(*str_ptr)[-1]==SHINSEI_PATH_LINUX_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isLinuxPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==U'\0'||ch==SHINSEI_PATH_LINUX_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isLinuxPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]==U'\0'||(*str_ptr)[-1]==SHINSEI_PATH_LINUX_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isLinuxPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==L'\0'||ch==SHINSEI_PATH_LINUX_DELIMITER_W;
}

bool shinsei_isLinuxPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isLinuxPathIllegalCharW(ch);
}
bool shinsei_isLinuxPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isLinuxPathIllegalCharU32M((const char32_t**)str_ptr,len);
	#else
		return isLinuxPathIllegalCharU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isLinuxPathIllegalCharCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isLinuxPathIllegalCharCP(code_page,ch);
}
bool shinsei_isLinuxPathIllegalCharCPM(const uint_fast32_t code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return false;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return isLinuxPathIllegalCharCP(code_page,starter_ch);
}
bool shinsei_isLinuxPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isLinuxPathIllegalCharU8(ch);
}
bool shinsei_isLinuxPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isLinuxPathIllegalCharU8M(str_ptr,len);
}
bool shinsei_isLinuxPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isLinuxPathIllegalCharU16(ch);
}
bool shinsei_isLinuxPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isLinuxPathIllegalCharU16M(str_ptr,len);
}
bool shinsei_isLinuxPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isLinuxPathIllegalCharU32(ch);
}
bool shinsei_isLinuxPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isLinuxPathIllegalCharU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isApplePathIllegalCharASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch=='\0'||ch==SHINSEI_PATH_APPLE_DELIMITER_ASCII;
}
_SHINSEI_OS_INLINE static bool isApplePathIllegalCharEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch=='\0'||ch==SHINSEI_PATH_APPLE_DELIMITER_EBCDIC;
}
_SHINSEI_OS_INLINE static bool isApplePathIllegalCharCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isApplePathIllegalCharEBCDIC(ch)+!ebcdic*isApplePathIllegalCharASCII(ch);
}
_SHINSEI_OS_INLINE static bool isApplePathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==u8'\0'||ch==SHINSEI_PATH_APPLE_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isApplePathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==u8'\0'||(*str_ptr)[-1]==SHINSEI_PATH_APPLE_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isApplePathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==u'\0'||ch==SHINSEI_PATH_APPLE_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isApplePathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==u'\0'||(*str_ptr)[-1]==SHINSEI_PATH_APPLE_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isApplePathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==U'\0'||ch==SHINSEI_PATH_APPLE_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isApplePathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]==U'\0'||(*str_ptr)[-1]==SHINSEI_PATH_APPLE_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isApplePathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==L'\0'||ch==SHINSEI_PATH_APPLE_DELIMITER_W;
}

bool shinsei_isApplePathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isApplePathIllegalCharW(ch);
}
bool shinsei_isApplePathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isApplePathIllegalCharU32M((const char32_t**)str_ptr,len);
	#else
		return isApplePathIllegalCharU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isApplePathIllegalCharCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isApplePathIllegalCharCP(code_page,ch);
}
bool shinsei_isApplePathIllegalCharCPM(const uint_fast32_t code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return false;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return isApplePathIllegalCharCP(code_page,starter_ch);
}
bool shinsei_isApplePathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isApplePathIllegalCharU8(ch);
}
bool shinsei_isApplePathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isApplePathIllegalCharU8M(str_ptr,len);
}
bool shinsei_isApplePathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isApplePathIllegalCharU16(ch);
}
bool shinsei_isApplePathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isApplePathIllegalCharU16M(str_ptr,len);
}
bool shinsei_isApplePathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isApplePathIllegalCharU32(ch);
}
bool shinsei_isApplePathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isApplePathIllegalCharU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isSunPathIllegalCharASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch=='\0'||ch==SHINSEI_PATH_SUN_DELIMITER_ASCII;
}
_SHINSEI_OS_INLINE static bool isSunPathIllegalCharEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch=='\0'||ch==SHINSEI_PATH_SUN_DELIMITER_EBCDIC;
}
_SHINSEI_OS_INLINE static bool isSunPathIllegalCharCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isSunPathIllegalCharEBCDIC(ch)+!ebcdic*isSunPathIllegalCharASCII(ch);
}
_SHINSEI_OS_INLINE static bool isSunPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==u8'\0'||ch==SHINSEI_PATH_SUN_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isSunPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==u8'\0'||(*str_ptr)[-1]==SHINSEI_PATH_SUN_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isSunPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==u'\0'||ch==SHINSEI_PATH_SUN_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isSunPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==u'\0'||(*str_ptr)[-1]==SHINSEI_PATH_SUN_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isSunPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==U'\0'||ch==SHINSEI_PATH_SUN_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isSunPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]==U'\0'||(*str_ptr)[-1]==SHINSEI_PATH_SUN_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isSunPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==L'\0'||ch==SHINSEI_PATH_SUN_DELIMITER_W;
}

bool shinsei_isSunPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isSunPathIllegalCharW(ch);
}
bool shinsei_isSunPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isSunPathIllegalCharU32M((const char32_t**)str_ptr,len);
	#else
		return isSunPathIllegalCharU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isSunPathIllegalCharCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isSunPathIllegalCharCP(code_page,ch);
}
bool shinsei_isSunPathIllegalCharCPM(const uint_fast32_t code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return false;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return isSunPathIllegalCharCP(code_page,starter_ch);
}
bool shinsei_isSunPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isSunPathIllegalCharU8(ch);
}
bool shinsei_isSunPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isSunPathIllegalCharU8M(str_ptr,len);
}
bool shinsei_isSunPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isSunPathIllegalCharU16(ch);
}
bool shinsei_isSunPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isSunPathIllegalCharU16M(str_ptr,len);
}
bool shinsei_isSunPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isSunPathIllegalCharU32(ch);
}
bool shinsei_isSunPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isSunPathIllegalCharU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isFreeBSDPathIllegalCharASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch=='\0'||ch==SHINSEI_PATH_FREEBSD_DELIMITER_ASCII;
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathIllegalCharEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch=='\0'||ch==SHINSEI_PATH_FREEBSD_DELIMITER_EBCDIC;
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathIllegalCharCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isFreeBSDPathIllegalCharEBCDIC(ch)+!ebcdic*isFreeBSDPathIllegalCharASCII(ch);
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==u8'\0'||ch==SHINSEI_PATH_FREEBSD_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==u8'\0'||(*str_ptr)[-1]==SHINSEI_PATH_FREEBSD_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==u'\0'||ch==SHINSEI_PATH_FREEBSD_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==u'\0'||(*str_ptr)[-1]==SHINSEI_PATH_FREEBSD_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==U'\0'||ch==SHINSEI_PATH_FREEBSD_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]==U'\0'||(*str_ptr)[-1]==SHINSEI_PATH_FREEBSD_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isFreeBSDPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==L'\0'||ch==SHINSEI_PATH_FREEBSD_DELIMITER_W;
}

bool shinsei_isFreeBSDPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isFreeBSDPathIllegalCharW(ch);
}
bool shinsei_isFreeBSDPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isFreeBSDPathIllegalCharU32M((const char32_t**)str_ptr,len);
	#else
		return isFreeBSDPathIllegalCharU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isFreeBSDPathIllegalCharCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isFreeBSDPathIllegalCharCP(code_page,ch);
}
bool shinsei_isFreeBSDPathIllegalCharCPM(const uint_fast32_t code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return false;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return isFreeBSDPathIllegalCharCP(code_page,starter_ch);
}
bool shinsei_isFreeBSDPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isFreeBSDPathIllegalCharU8(ch);
}
bool shinsei_isFreeBSDPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isFreeBSDPathIllegalCharU8M(str_ptr,len);
}
bool shinsei_isFreeBSDPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isFreeBSDPathIllegalCharU16(ch);
}
bool shinsei_isFreeBSDPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isFreeBSDPathIllegalCharU16M(str_ptr,len);
}
bool shinsei_isFreeBSDPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isFreeBSDPathIllegalCharU32(ch);
}
bool shinsei_isFreeBSDPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isFreeBSDPathIllegalCharU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isCygwinPathIllegalCharASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch=='\0'||ch==SHINSEI_PATH_CYGWIN_DELIMITER_ASCII;
}
_SHINSEI_OS_INLINE static bool isCygwinPathIllegalCharEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch=='\0'||ch==SHINSEI_PATH_CYGWIN_DELIMITER_EBCDIC;
}
_SHINSEI_OS_INLINE static bool isCygwinPathIllegalCharCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isCygwinPathIllegalCharEBCDIC(ch)+!ebcdic*isCygwinPathIllegalCharASCII(ch);
}
_SHINSEI_OS_INLINE static bool isCygwinPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==u8'\0'||ch==SHINSEI_PATH_CYGWIN_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isCygwinPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==u8'\0'||(*str_ptr)[-1]==SHINSEI_PATH_CYGWIN_DELIMITER_U8;
}
_SHINSEI_OS_INLINE static bool isCygwinPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==u'\0'||ch==SHINSEI_PATH_CYGWIN_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isCygwinPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==u'\0'||(*str_ptr)[-1]==SHINSEI_PATH_CYGWIN_DELIMITER_U16;
}
_SHINSEI_OS_INLINE static bool isCygwinPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==U'\0'||ch==SHINSEI_PATH_CYGWIN_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isCygwinPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]==U'\0'||(*str_ptr)[-1]==SHINSEI_PATH_CYGWIN_DELIMITER_U32;
}
_SHINSEI_OS_INLINE static bool isCygwinPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==L'\0'||ch==SHINSEI_PATH_CYGWIN_DELIMITER_W;
}

bool shinsei_isCygwinPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isCygwinPathIllegalCharW(ch);
}
bool shinsei_isCygwinPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isCygwinPathIllegalCharU32M((const char32_t**)str_ptr,len);
	#else
		return isCygwinPathIllegalCharU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isCygwinPathIllegalCharCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isCygwinPathIllegalCharCP(code_page,ch);
}
bool shinsei_isCygwinPathIllegalCharCPM(const uint_fast32_t code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return false;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return isCygwinPathIllegalCharCP(code_page,starter_ch);
}
bool shinsei_isCygwinPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isCygwinPathIllegalCharU8(ch);
}
bool shinsei_isCygwinPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isCygwinPathIllegalCharU8M(str_ptr,len);
}
bool shinsei_isCygwinPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isCygwinPathIllegalCharU16(ch);
}
bool shinsei_isCygwinPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isCygwinPathIllegalCharU16M(str_ptr,len);
}
bool shinsei_isCygwinPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isCygwinPathIllegalCharU32(ch);
}
bool shinsei_isCygwinPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isCygwinPathIllegalCharU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isURLPathIllegalCharASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	(void)ch;
	return false;
}
_SHINSEI_OS_INLINE static bool isURLPathIllegalCharEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	(void)ch;
	return false;
}
_SHINSEI_OS_INLINE static bool isURLPathIllegalCharCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	(void)code_page;
	(void)ch;
	return false;
}
_SHINSEI_OS_INLINE static bool isURLPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	(void)ch;
	return false;
}
_SHINSEI_OS_INLINE static bool isURLPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	return false;
}
_SHINSEI_OS_INLINE static bool isURLPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	(void)ch;
	return false;
}
_SHINSEI_OS_INLINE static bool isURLPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	return false;
}
_SHINSEI_OS_INLINE static bool isURLPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	(void)ch;
	return false;
}
_SHINSEI_OS_INLINE static bool isURLPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return false;
}
_SHINSEI_OS_INLINE static bool isURLPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	(void)ch;
	return false;
}

bool shinsei_isURLPathIllegalCharW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isURLPathIllegalCharW(ch);
}
bool shinsei_isURLPathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isURLPathIllegalCharU32M((const char32_t**)str_ptr,len);
	#else
		return isURLPathIllegalCharU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isURLPathIllegalCharCP(const uint_fast32_t code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isURLPathIllegalCharCP(code_page,ch);
}
bool shinsei_isURLPathIllegalCharCPM(const uint_fast32_t code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return false;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return false;
	*str_ptr+=size;
	return false;
}
bool shinsei_isURLPathIllegalCharU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isURLPathIllegalCharU8(ch);
}
bool shinsei_isURLPathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isURLPathIllegalCharU8M(str_ptr,len);
}
bool shinsei_isURLPathIllegalCharU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isURLPathIllegalCharU16(ch);
}
bool shinsei_isURLPathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isURLPathIllegalCharU16M(str_ptr,len);
}
bool shinsei_isURLPathIllegalCharU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isURLPathIllegalCharU32(ch);
}
bool shinsei_isURLPathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isURLPathIllegalCharU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static int windowsPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register bool can_traverse=false;
	register bool device_path=false;
	register int res;
	register char8_t* ptr;
	register size_t cnt=*len;
	if(isWindowsPathDelimiterU8(path[0])){
		path[0]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
		if(*len>=2&&isWindowsPathDelimiterU8(path[1])){
			path[1]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
			// Device path "\\?\xxx" or DOS device path "\\.\xxx"
			if(*len>=4&&(path[2]==u8'?'||path[2]==u8'.')&&isWindowsPathDelimiterU8(path[3])){
				// Prevent nested device prefix like "\\?\\?\"
				if(__builtin_expect(*len>=6&&isWindowsPathDelimiterU8(path[4])&&(path[5]==u8'?'||path[5]==u8'.')&&isWindowsPathDelimiterU8(path[6]),0)){
					return SHINSEI_PATH_ILLEGAL;
				}
				path[3]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
				device_path=true;
				// Extended UNC path "\\?\UNC\server\share\xxx"
				if(path[2]==u8'?'&&*len>=8&&(path[4]==u8'U'||path[4]==u8'u')&&(path[5]==u8'N'||path[5]==u8'n')&&(path[6]==u8'C'||path[6]==u8'c')&&isWindowsPathDelimiterU8(path[7])){
					path[4]=u8'U';
					path[5]=u8'N';
					path[6]=u8'C';
					path[7]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
					register size_t i=8;
					// Parse server
					if(__builtin_expect(i>=*len||isWindowsPathDelimiterU8(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!isWindowsPathDelimiterU8(path[i])){
						if(__builtin_expect(isWindowsPathIllegalCharU8(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
					path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
					++i;
					// Parse share
					if(__builtin_expect(i>=*len||isWindowsPathDelimiterU8(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!isWindowsPathDelimiterU8(path[i])){
						if(__builtin_expect(isWindowsPathIllegalCharU8(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(i<*len){
						path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
						ptr=path+i+1;
						cnt=*len-(i+1);
					}
					else{
						ptr=path+i;
						cnt=0;
					}
				}
				else{
					ptr=path+4;
					cnt-=4;
				}
				res=SHINSEI_PATH_ABSOLUTE;
			}
			else{
				// UNC path "\\server\share\xxx". Root is "\\server\share"
				register size_t i=2;
				// Parse server
				if(__builtin_expect(i>=*len||isWindowsPathDelimiterU8(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!isWindowsPathDelimiterU8(path[i])){
					if(__builtin_expect(isWindowsPathIllegalCharU8(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
				path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
				++i;
				// Parse share
				if(__builtin_expect(i>=*len||isWindowsPathDelimiterU8(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!isWindowsPathDelimiterU8(path[i])){
					if(__builtin_expect(isWindowsPathIllegalCharU8(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				// Set root
				if(i<*len){
					path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
					ptr=path+i+1;
					cnt=*len-(i+1);
				}
				else{
					ptr=path+i;
					cnt=0;
				}
				res=SHINSEI_PATH_ABSOLUTE;
			}
		}
		else{
			// Relative path of current drive "\xxx". Root is "\".
			if(*len==1){
				path[1]=u8'\0';
				return SHINSEI_PATH_RELATIVE;
			}
			ptr=path+1;
			--cnt;
			while(*ptr==u8'.'){
				if(*len==2){
					path[1]=u8'\0';
					*len=1;
					return SHINSEI_PATH_RELATIVE;
				}
				if(ptr[1]==u8'.'){
					if(*len==3){
						path[1]=u8'\0';
						*len=1;
						return SHINSEI_PATH_RELATIVE;
					}
					if(__builtin_expect(ptr[2]==u8'.',0)) return SHINSEI_PATH_ILLEGAL;
					if(isWindowsPathDelimiterU8(ptr[2])){
						// First segment is "..". Can't get parent any more.
						ptr[2]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
						ptr+=3;
						cnt-=3;
						continue;
					}
					// First segment is "..xxx"
					break;
				}
				if(isWindowsPathDelimiterU8(ptr[1])){
					// First segment is "."
					ptr[1]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
					ptr+=2;
					cnt-=2;
					continue;
				}
				// First segment is ".xxx"
				break;
			}
			res=SHINSEI_PATH_RELATIVE;
		}
	}
	else{
		if(*len>=2&&path[1]==u8':'){
			// Local path with drive prefix
			if(__builtin_expect(!isAlphaU8(path[0]),0)) return SHINSEI_PATH_ILLEGAL;
			path[0]=toUpperU8(path[0]);
			if(*len==2){
				// Drive only "X:".
				path[2]=u8'\0';
				return SHINSEI_PATH_RELATIVE;
			}
			if(isWindowsPathDelimiterU8(path[2])){
				// Local absolute path "X:\". Root is "X:\".
				path[2]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
				ptr=path+3;
				cnt-=3;
				res=SHINSEI_PATH_ABSOLUTE;
			}
			else{
				// Drive relative path "C:xxx". No root (can traverse).
				ptr=path+2;
				cnt-=2;
				can_traverse=true;
				res=SHINSEI_PATH_RELATIVE;
			}
		}
		else{
			// Normal relative path "xxx". No root (can traverse).
			ptr=path;
			can_traverse=true;
			res=SHINSEI_PATH_RELATIVE;
		}
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	register size_t r=0;
	register size_t w=0;
	while(r<cnt){
		// Unify delimiter
		if(isWindowsPathDelimiterU8(ptr[r])){
			ptr[w++]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
			// Collapse multiple delimiters
			while(++r<cnt&&isWindowsPathDelimiterU8(ptr[r]));
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&!isWindowsPathDelimiterU8(ptr[r])){
			if(!device_path&&__builtin_expect(isWindowsPathIllegalCharU8(ptr[r]),0)) return SHINSEI_PATH_ILLEGAL;
			ptr[w++]=ptr[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&ptr[seg_start]==u8'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&ptr[seg_start]==u8'.'&&ptr[seg_start+1]==u8'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(can_traverse){
				// If it can traverse, just keep ".."
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more.
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	*len=(size_t)(ptr-path)+w;
	path[*len]=u8'\0';
	return res;
}
_SHINSEI_OS_INLINE static int windowsPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register bool can_traverse=false;
	register bool device_path=false;
	register int res;
	register char16_t* ptr;
	register size_t cnt=*len;
	if(isWindowsPathDelimiterU16(path[0])){
		path[0]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
		if(*len>=2&&isWindowsPathDelimiterU16(path[1])){
			path[1]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
			// Device path "\\?\xxx" or DOS device path "\\.\xxx"
			if(*len>=4&&(path[2]==u'?'||path[2]==u'.')&&isWindowsPathDelimiterU16(path[3])){
				// Prevent nested device prefix like "\\?\\?\"
				if(__builtin_expect(*len>=6&&isWindowsPathDelimiterU16(path[4])&&(path[5]==u'?'||path[5]==u'.')&&isWindowsPathDelimiterU16(path[6]),0)){
					return SHINSEI_PATH_ILLEGAL;
				}
				path[3]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
				device_path=true;
				// Extended UNC path "\\?\UNC\server\share\xxx"
				if(path[2]==u'?'&&*len>=8&&(path[4]==u'U'||path[4]==u'u')&&(path[5]==u'N'||path[5]==u'n')&&(path[6]==u'C'||path[6]==u'c')&&isWindowsPathDelimiterU16(path[7])){
					path[4]=u'U';
					path[5]=u'N';
					path[6]=u'C';
					path[7]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
					register size_t i=8;
					// Parse server
					if(__builtin_expect(i>=*len||isWindowsPathDelimiterU16(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!isWindowsPathDelimiterU16(path[i])){
						if(__builtin_expect(isWindowsPathIllegalCharU16(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
					path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
					++i;
					// Parse share
					if(__builtin_expect(i>=*len||isWindowsPathDelimiterU16(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!isWindowsPathDelimiterU16(path[i])){
						if(__builtin_expect(isWindowsPathIllegalCharU16(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(i<*len){
						path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
						ptr=path+i+1;
						cnt=*len-(i+1);
					}
					else{
						ptr=path+i;
						cnt=0;
					}
				}
				else{
					ptr=path+4;
					cnt-=4;
				}
				res=SHINSEI_PATH_ABSOLUTE;
			}
			else{
				// UNC path "\\server\share\xxx". Root is "\\server\share"
				register size_t i=2;
				// Parse server
				if(__builtin_expect(i>=*len||isWindowsPathDelimiterU16(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!isWindowsPathDelimiterU16(path[i])){
					if(__builtin_expect(isWindowsPathIllegalCharU16(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
				path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
				++i;
				// Parse share
				if(__builtin_expect(i>=*len||isWindowsPathDelimiterU16(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!isWindowsPathDelimiterU16(path[i])){
					if(__builtin_expect(isWindowsPathIllegalCharU16(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				// Set root
				if(i<*len){
					path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
					ptr=path+i+1;
					cnt=*len-(i+1);
				}
				else{
					ptr=path+i;
					cnt=0;
				}
				res=SHINSEI_PATH_ABSOLUTE;
			}
		}
		else{
			// Relative path of current drive "\xxx". Root is "\".
			if(*len==1){
				path[1]=u'\0';
				return SHINSEI_PATH_RELATIVE;
			}
			ptr=path+1;
			--cnt;
			while(*ptr==u'.'){
				if(*len==2){
					path[1]=u'\0';
					*len=1;
					return SHINSEI_PATH_RELATIVE;
				}
				if(ptr[1]==u'.'){
					if(*len==3){
						path[1]=u'\0';
						*len=1;
						return SHINSEI_PATH_RELATIVE;
					}
					if(__builtin_expect(ptr[2]==u'.',0)) return SHINSEI_PATH_ILLEGAL;
					if(isWindowsPathDelimiterU16(ptr[2])){
						// First segment is "..". Can't get parent any more.
						ptr[2]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
						ptr+=3;
						cnt-=3;
						continue;
					}
					// First segment is "..xxx"
					break;
				}
				if(isWindowsPathDelimiterU16(ptr[1])){
					// First segment is "."
					ptr[1]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
					ptr+=2;
					cnt-=2;
					continue;
				}
				// First segment is ".xxx"
				break;
			}
			res=SHINSEI_PATH_RELATIVE;
		}
	}
	else{
		if(*len>=2&&path[1]==u':'){
			// Local path with drive prefix
			if(__builtin_expect(!isAlphaU16(path[0]),0)) return SHINSEI_PATH_ILLEGAL;
			path[0]=toUpperU16(path[0]);
			if(*len==2){
				// Drive only "X:".
				path[2]=u'\0';
				return SHINSEI_PATH_RELATIVE;
			}
			if(isWindowsPathDelimiterU16(path[2])){
				// Local absolute path "X:\". Root is "X:\".
				path[2]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
				ptr=path+3;
				cnt-=3;
				res=SHINSEI_PATH_ABSOLUTE;
			}
			else{
				// Drive relative path "C:xxx". No root (can traverse).
				ptr=path+2;
				cnt-=2;
				can_traverse=true;
				res=SHINSEI_PATH_RELATIVE;
			}
		}
		else{
			// Normal relative path "xxx". No root (can traverse).
			ptr=path;
			can_traverse=true;
			res=SHINSEI_PATH_RELATIVE;
		}
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	register size_t r=0;
	register size_t w=0;
	while(r<cnt){
		// Unify delimiter
		if(isWindowsPathDelimiterU16(ptr[r])){
			ptr[w++]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
			// Collapse multiple delimiters
			while(++r<cnt&&isWindowsPathDelimiterU16(ptr[r]));
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&!isWindowsPathDelimiterU16(ptr[r])){
			if(!device_path&&__builtin_expect(isWindowsPathIllegalCharU16(ptr[r]),0)) return SHINSEI_PATH_ILLEGAL;
			ptr[w++]=ptr[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&ptr[seg_start]==u'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&ptr[seg_start]==u'.'&&ptr[seg_start+1]==u'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(can_traverse){
				// If it can traverse, just keep ".."
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more.
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	*len=(size_t)(ptr-path)+w;
	path[*len]=u'\0';
	return res;
}
_SHINSEI_OS_INLINE static int windowsPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register bool can_traverse=false;
	register bool device_path=false;
	register int res;
	register char32_t* ptr;
	register size_t cnt=*len;
	if(isWindowsPathDelimiterU32(path[0])){
		path[0]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
		if(*len>=2&&isWindowsPathDelimiterU32(path[1])){
			path[1]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
			// Device path "\\?\xxx" or DOS device path "\\.\xxx"
			if(*len>=4&&(path[2]==U'?'||path[2]==U'.')&&isWindowsPathDelimiterU32(path[3])){
				// Prevent nested device prefix like "\\?\\?\"
				if(__builtin_expect(*len>=6&&isWindowsPathDelimiterU32(path[4])&&(path[5]==U'?'||path[5]==U'.')&&isWindowsPathDelimiterU32(path[6]),0)){
					return SHINSEI_PATH_ILLEGAL;
				}
				path[3]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
				device_path=true;
				// Extended UNC path "\\?\UNC\server\share\xxx"
				if(path[2]==U'?'&&*len>=8&&(path[4]==U'U'||path[4]==U'u')&&(path[5]==U'N'||path[5]==U'n')&&(path[6]==U'C'||path[6]==U'c')&&isWindowsPathDelimiterU32(path[7])){
					path[4]=U'U';
					path[5]=U'N';
					path[6]=U'C';
					path[7]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
					register size_t i=8;
					// Parse server
					if(__builtin_expect(i>=*len||isWindowsPathDelimiterU32(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!isWindowsPathDelimiterU32(path[i])){
						if(__builtin_expect(isWindowsPathIllegalCharU32(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
					path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
					++i;
					// Parse share
					if(__builtin_expect(i>=*len||isWindowsPathDelimiterU32(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!isWindowsPathDelimiterU32(path[i])){
						if(__builtin_expect(isWindowsPathIllegalCharU32(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(i<*len){
						path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
						ptr=path+i+1;
						cnt=*len-(i+1);
					}
					else{
						ptr=path+i;
						cnt=0;
					}
				}
				else{
					ptr=path+4;
					cnt-=4;
				}
				res=SHINSEI_PATH_ABSOLUTE;
			}
			else{
				// UNC path "\\server\share\xxx". Root is "\\server\share"
				register size_t i=2;
				// Parse server
				if(__builtin_expect(i>=*len||isWindowsPathDelimiterU32(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!isWindowsPathDelimiterU32(path[i])){
					if(__builtin_expect(isWindowsPathIllegalCharU32(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
				path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
				++i;
				// Parse share
				if(__builtin_expect(i>=*len||isWindowsPathDelimiterU32(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!isWindowsPathDelimiterU32(path[i])){
					if(__builtin_expect(isWindowsPathIllegalCharU32(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				// Set root
				if(i<*len){
					path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
					ptr=path+i+1;
					cnt=*len-(i+1);
				}
				else{
					ptr=path+i;
					cnt=0;
				}
				res=SHINSEI_PATH_ABSOLUTE;
			}
		}
		else{
			// Relative path of current drive "\xxx". Root is "\".
			if(*len==1){
				path[1]=U'\0';
				return SHINSEI_PATH_RELATIVE;
			}
			ptr=path+1;
			--cnt;
			while(*ptr==U'.'){
				if(*len==2){
					path[1]=U'\0';
					*len=1;
					return SHINSEI_PATH_RELATIVE;
				}
				if(ptr[1]==U'.'){
					if(*len==3){
						path[1]=U'\0';
						*len=1;
						return SHINSEI_PATH_RELATIVE;
					}
					if(__builtin_expect(ptr[2]==U'.',0)) return SHINSEI_PATH_ILLEGAL;
					if(isWindowsPathDelimiterU32(ptr[2])){
						// First segment is "..". Can't get parent any more.
						ptr[2]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
						ptr+=3;
						cnt-=3;
						continue;
					}
					// First segment is "..xxx"
					break;
				}
				if(isWindowsPathDelimiterU32(ptr[1])){
					// First segment is "."
					ptr[1]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
					ptr+=2;
					cnt-=2;
					continue;
				}
				// First segment is ".xxx"
				break;
			}
			res=SHINSEI_PATH_RELATIVE;
		}
	}
	else{
		if(*len>=2&&path[1]==U':'){
			// Local path with drive prefix
			if(__builtin_expect(!isAlphaU32(path[0]),0)) return SHINSEI_PATH_ILLEGAL;
			path[0]=toUpperU32(path[0]);
			if(*len==2){
				// Drive only "X:".
				path[2]=U'\0';
				return SHINSEI_PATH_RELATIVE;
			}
			if(isWindowsPathDelimiterU32(path[2])){
				// Local absolute path "X:\". Root is "X:\".
				path[2]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
				ptr=path+3;
				cnt-=3;
				res=SHINSEI_PATH_ABSOLUTE;
			}
			else{
				// Drive relative path "C:xxx". No root (can traverse).
				ptr=path+2;
				cnt-=2;
				can_traverse=true;
				res=SHINSEI_PATH_RELATIVE;
			}
		}
		else{
			// Normal relative path "xxx". No root (can traverse).
			ptr=path;
			can_traverse=true;
			res=SHINSEI_PATH_RELATIVE;
		}
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	register size_t r=0;
	register size_t w=0;
	while(r<cnt){
		// Unify delimiter
		if(isWindowsPathDelimiterU32(ptr[r])){
			ptr[w++]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
			// Collapse multiple delimiters
			while(++r<cnt&&isWindowsPathDelimiterU32(ptr[r]));
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&!isWindowsPathDelimiterU32(ptr[r])){
			if(!device_path&&__builtin_expect(isWindowsPathIllegalCharU32(ptr[r]),0)) return SHINSEI_PATH_ILLEGAL;
			ptr[w++]=ptr[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&ptr[seg_start]==U'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&ptr[seg_start]==U'.'&&ptr[seg_start+1]==U'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(can_traverse){
				// If it can traverse, just keep ".."
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more.
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	*len=(size_t)(ptr-path)+w;
	path[*len]=U'\0';
	return res;
}
_SHINSEI_OS_INLINE static int windowsPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len){
	#ifdef _SHINSEI_WCHAR_U32
		return windowsPathNormalizeU32((char32_t*)path,len);
	#else
		return windowsPathNormalizeU16((char16_t*)path,len);
	#endif
}
_SHINSEI_OS_INLINE static int windowsPathNormalizeCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char q_mark=(char)(ebcdic*0x6F+!ebcdic*'?');
	register const char dot=(char)(ebcdic*0x4B+!ebcdic*'.');
	register const char char_U=(char)(ebcdic*0xE4+!ebcdic*'U');
	register const char char_u=(char)(ebcdic*0xA4+!ebcdic*'u');
	register const char char_N=(char)(ebcdic*0xD5+!ebcdic*'N');
	register const char char_n=(char)(ebcdic*0x95+!ebcdic*'n');
	register const char char_C=(char)(ebcdic*0xC3+!ebcdic*'C');
	register const char char_c=(char)(ebcdic*0x83+!ebcdic*'c');
	register const char colon=(char)(ebcdic*0x7A+!ebcdic*':');
	register const char null_char='\0';
	register const char delim_win=(char)(ebcdic*SHINSEI_PATH_WINDOWS_DELIMITER_EBCDIC+!ebcdic*SHINSEI_PATH_WINDOWS_DELIMITER_ASCII);
	
	register bool can_traverse=false;
	register bool device_path=false;
	register int res;
	register char* ptr;
	register size_t cnt=*len;
	if(isWindowsPathDelimiterCP(code_page,path[0])){
		path[0]=delim_win;
		if(*len>=2&&isWindowsPathDelimiterCP(code_page,path[1])){
			path[1]=delim_win;
			// Device path "\\?\xxx" or DOS device path "\\.\xxx"
			if(*len>=4&&(path[2]==q_mark||path[2]==dot)&&isWindowsPathDelimiterCP(code_page,path[3])){
				// Prevent nested device prefix like "\\?\\?\"
				if(__builtin_expect(*len>=6&&isWindowsPathDelimiterCP(code_page,path[4])&&(path[5]==q_mark||path[5]==dot)&&isWindowsPathDelimiterCP(code_page,path[6]),0)){
					return SHINSEI_PATH_ILLEGAL;
				}
				path[3]=delim_win;
				device_path=true;
				// Extended UNC path "\\?\UNC\server\share\xxx"
				if(path[2]==q_mark&&*len>=8&&(path[4]==char_U||path[4]==char_u)&&(path[5]==char_N||path[5]==char_n)&&(path[6]==char_C||path[6]==char_c)&&isWindowsPathDelimiterCP(code_page,path[7])){
					path[4]=char_U;
					path[5]=char_N;
					path[6]=char_C;
					path[7]=delim_win;
					register size_t i=8;
					// Parse server
					if(__builtin_expect(i>=*len||isWindowsPathDelimiterCP(code_page,path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!isWindowsPathDelimiterCP(code_page,path[i])){
						if(__builtin_expect(isWindowsPathIllegalCharCP(code_page,path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
					path[i]=delim_win;
					++i;
					// Parse share
					if(__builtin_expect(i>=*len||isWindowsPathDelimiterCP(code_page,path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!isWindowsPathDelimiterCP(code_page,path[i])){
						if(__builtin_expect(isWindowsPathIllegalCharCP(code_page,path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(i<*len){
						path[i]=delim_win;
						ptr=path+i+1;
						cnt=*len-(i+1);
					}
					else{
						ptr=path+i;
						cnt=0;
					}
				}
				else{
					ptr=path+4;
					cnt-=4;
				}
				res=SHINSEI_PATH_ABSOLUTE;
			}
			else{
				// UNC path "\\server\share\xxx". Root is "\\server\share"
				register size_t i=2;
				// Parse server
				if(__builtin_expect(i>=*len||isWindowsPathDelimiterCP(code_page,path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!isWindowsPathDelimiterCP(code_page,path[i])){
					if(__builtin_expect(isWindowsPathIllegalCharCP(code_page,path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
				path[i]=delim_win;
				++i;
				// Parse share
				if(__builtin_expect(i>=*len||isWindowsPathDelimiterCP(code_page,path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!isWindowsPathDelimiterCP(code_page,path[i])){
					if(__builtin_expect(isWindowsPathIllegalCharCP(code_page,path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				// Set root
				if(i<*len){
					path[i]=delim_win;
					ptr=path+i+1;
					cnt=*len-(i+1);
				}
				else{
					ptr=path+i;
					cnt=0;
				}
				res=SHINSEI_PATH_ABSOLUTE;
			}
		}
		else{
			// Relative path of current drive "\xxx". Root is "\".
			if(*len==1){
				path[1]=null_char;
				return SHINSEI_PATH_RELATIVE;
			}
			ptr=path+1;
			--cnt;
			while(*ptr==dot){
				if(*len==2){
					path[1]=null_char;
					*len=1;
					return SHINSEI_PATH_RELATIVE;
				}
				if(ptr[1]==dot){
					if(*len==3){
						path[1]=null_char;
						*len=1;
						return SHINSEI_PATH_RELATIVE;
					}
					if(__builtin_expect(ptr[2]==dot,0)) return SHINSEI_PATH_ILLEGAL;
					if(isWindowsPathDelimiterCP(code_page,ptr[2])){
						// First segment is "..". Can't get parent any more.
						ptr[2]=delim_win;
						ptr+=3;
						cnt-=3;
						continue;
					}
					// First segment is "..xxx"
					break;
				}
				if(isWindowsPathDelimiterCP(code_page,ptr[1])){
					// First segment is "."
					ptr[1]=delim_win;
					ptr+=2;
					cnt-=2;
					continue;
				}
				// First segment is ".xxx"
				break;
			}
			res=SHINSEI_PATH_RELATIVE;
		}
	}
	else{
		if(*len>=2&&path[1]==colon){
			// Local path with drive prefix
			if(__builtin_expect(!isAlphaCP(code_page,path[0]),0)) return SHINSEI_PATH_ILLEGAL;
			path[0]=(char)toUpperCP(code_page,path[0]);
			if(*len==2){
				// Drive only "X:".
				path[2]=null_char;
				return SHINSEI_PATH_RELATIVE;
			}
			if(isWindowsPathDelimiterCP(code_page,path[2])){
				// Local absolute path "X:\". Root is "X:\".
				path[2]=delim_win;
				ptr=path+3;
				cnt-=3;
				res=SHINSEI_PATH_ABSOLUTE;
			}
			else{
				// Drive relative path "C:xxx". No root (can traverse).
				ptr=path+2;
				cnt-=2;
				can_traverse=true;
				res=SHINSEI_PATH_RELATIVE;
			}
		}
		else{
			// Normal relative path "xxx". No root (can traverse).
			ptr=path;
			can_traverse=true;
			res=SHINSEI_PATH_RELATIVE;
		}
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	register size_t r=0;
	register size_t w=0;
	while(r<cnt){
		// Unify delimiter
		if(isWindowsPathDelimiterCP(code_page,ptr[r])){
			ptr[w++]=delim_win;
			// Collapse multiple delimiters
			while(++r<cnt&&isWindowsPathDelimiterCP(code_page,ptr[r]));
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&!isWindowsPathDelimiterCP(code_page,ptr[r])){
			if(!device_path&&__builtin_expect(isWindowsPathIllegalCharCP(code_page,ptr[r]),0)) return SHINSEI_PATH_ILLEGAL;
			ptr[w++]=ptr[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&ptr[seg_start]==dot){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&ptr[seg_start]==dot&&ptr[seg_start+1]==dot){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(can_traverse){
				// If it can traverse, just keep ".."
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more.
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	*len=(size_t)(ptr-path)+w;
	path[*len]=null_char;
	return res;
}

int shinsei_windowsPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return windowsPathNormalizeW(path,len);
}
int shinsei_windowsPathNormalizeCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return windowsPathNormalizeCP(code_page,path,len);
}
int shinsei_windowsPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return windowsPathNormalizeU8(path,len);
}
int shinsei_windowsPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return windowsPathNormalizeU16(path,len);
}
int shinsei_windowsPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return windowsPathNormalizeU32(path,len);
}

_SHINSEI_OS_INLINE static int unixPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_UNIX_DELIMITER_U8;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_UNIX_DELIMITER_U8;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_U8) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_UNIX_DELIMITER_U8){
			if(w>0&&path[w-1]!=SHINSEI_PATH_UNIX_DELIMITER_U8){
				path[w++]=SHINSEI_PATH_UNIX_DELIMITER_U8;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_U8);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_UNIX_DELIMITER_U8){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u8'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u8'.'&&path[seg_start+1]==u8'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u8'.'&&path[rewind-2]==u8'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_UNIX_DELIMITER_U8);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_UNIX_DELIMITER_U8){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_UNIX_DELIMITER_U8)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_UNIX_DELIMITER_U8) --w;
	if(!w&&!is_abs){
		path[0]=u8'.';
		w=1;
	}
	*len=w;
	path[*len]=u8'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int unixPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_UNIX_DELIMITER_U16;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_UNIX_DELIMITER_U16;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_U16) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_UNIX_DELIMITER_U16){
			if(w>0&&path[w-1]!=SHINSEI_PATH_UNIX_DELIMITER_U16){
				path[w++]=SHINSEI_PATH_UNIX_DELIMITER_U16;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_U16);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_UNIX_DELIMITER_U16){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u'.'&&path[seg_start+1]==u'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u'.'&&path[rewind-2]==u'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_UNIX_DELIMITER_U16);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_UNIX_DELIMITER_U16){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_UNIX_DELIMITER_U16)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_UNIX_DELIMITER_U16) --w;
	if(!w&&!is_abs){
		path[0]=u'.';
		w=1;
	}
	*len=w;
	path[*len]=u'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int unixPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_UNIX_DELIMITER_U32;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_UNIX_DELIMITER_U32;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_U32) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_UNIX_DELIMITER_U32){
			if(w>0&&path[w-1]!=SHINSEI_PATH_UNIX_DELIMITER_U32){
				path[w++]=SHINSEI_PATH_UNIX_DELIMITER_U32;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_U32);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_UNIX_DELIMITER_U32){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==U'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==U'.'&&path[seg_start+1]==U'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==U'.'&&path[rewind-2]==U'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_UNIX_DELIMITER_U32);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_UNIX_DELIMITER_U32){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_UNIX_DELIMITER_U32)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_UNIX_DELIMITER_U32) --w;
	if(!w&&!is_abs){
		path[0]=U'.';
		w=1;
	}
	*len=w;
	path[*len]=U'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int unixPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return unixPathNormalizeU32((char32_t*)path,len);
	#else
		return unixPathNormalizeU16((char16_t*)path,len);
	#endif
}

_SHINSEI_OS_INLINE static int unixPathNormalizeCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char dot=(char)(ebcdic*0x4B+!ebcdic*'.');
	register const char delim=(char)(ebcdic*SHINSEI_PATH_UNIX_DELIMITER_EBCDIC+!ebcdic*SHINSEI_PATH_UNIX_DELIMITER_ASCII);
	register const char null_char='\0';

	register const bool is_abs=path[0]==delim;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=delim;
		++r;
		while(r<cnt&&path[r]==delim) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==delim){
			if(w>0&&path[w-1]!=delim){
				path[w++]=delim;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==delim);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=delim){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==dot){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==dot&&path[seg_start+1]==dot){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==dot&&path[rewind-2]==dot&&(rewind==2||path[rewind-3]==delim);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=delim){
						--rewind;
					}
					w=(path[rewind]==delim)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==delim) --w;
	if(!w&&!is_abs){
		path[0]=dot;
		w=1;
	}
	*len=w;
	path[*len]=null_char;
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

int shinsei_unixPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return unixPathNormalizeW(path,len);
}

int shinsei_unixPathNormalizeCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return unixPathNormalizeCP(code_page,path,len);
}

int shinsei_unixPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return unixPathNormalizeU8(path,len);
}

int shinsei_unixPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return unixPathNormalizeU16(path,len);
}

int shinsei_unixPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return unixPathNormalizeU32(path,len);
}

_SHINSEI_OS_INLINE static int linuxPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_LINUX_DELIMITER_U8;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_LINUX_DELIMITER_U8;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_LINUX_DELIMITER_U8) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_LINUX_DELIMITER_U8){
			if(w>0&&path[w-1]!=SHINSEI_PATH_LINUX_DELIMITER_U8){
				path[w++]=SHINSEI_PATH_LINUX_DELIMITER_U8;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_LINUX_DELIMITER_U8);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_LINUX_DELIMITER_U8){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u8'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u8'.'&&path[seg_start+1]==u8'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u8'.'&&path[rewind-2]==u8'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_LINUX_DELIMITER_U8);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_LINUX_DELIMITER_U8){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_LINUX_DELIMITER_U8)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_LINUX_DELIMITER_U8) --w;
	if(!w&&!is_abs){
		path[0]=u8'.';
		w=1;
	}
	*len=w;
	path[*len]=u8'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int linuxPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_LINUX_DELIMITER_U16;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_LINUX_DELIMITER_U16;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_LINUX_DELIMITER_U16) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_LINUX_DELIMITER_U16){
			if(w>0&&path[w-1]!=SHINSEI_PATH_LINUX_DELIMITER_U16){
				path[w++]=SHINSEI_PATH_LINUX_DELIMITER_U16;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_LINUX_DELIMITER_U16);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_LINUX_DELIMITER_U16){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u'.'&&path[seg_start+1]==u'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u'.'&&path[rewind-2]==u'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_LINUX_DELIMITER_U16);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_LINUX_DELIMITER_U16){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_LINUX_DELIMITER_U16)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_LINUX_DELIMITER_U16) --w;
	if(!w&&!is_abs){
		path[0]=u'.';
		w=1;
	}
	*len=w;
	path[*len]=u'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int linuxPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_LINUX_DELIMITER_U32;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_LINUX_DELIMITER_U32;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_LINUX_DELIMITER_U32) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_LINUX_DELIMITER_U32){
			if(w>0&&path[w-1]!=SHINSEI_PATH_LINUX_DELIMITER_U32){
				path[w++]=SHINSEI_PATH_LINUX_DELIMITER_U32;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_LINUX_DELIMITER_U32);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_LINUX_DELIMITER_U32){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==U'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==U'.'&&path[seg_start+1]==U'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==U'.'&&path[rewind-2]==U'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_LINUX_DELIMITER_U32);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_LINUX_DELIMITER_U32){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_LINUX_DELIMITER_U32)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_LINUX_DELIMITER_U32) --w;
	if(!w&&!is_abs){
		path[0]=U'.';
		w=1;
	}
	*len=w;
	path[*len]=U'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int linuxPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return linuxPathNormalizeU32((char32_t*)path,len);
	#else
		return linuxPathNormalizeU16((char16_t*)path,len);
	#endif
}

_SHINSEI_OS_INLINE static int linuxPathNormalizeCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char dot=(char)(ebcdic*0x4B+!ebcdic*'.');
	register const char delim=(char)(ebcdic*SHINSEI_PATH_LINUX_DELIMITER_EBCDIC+!ebcdic*SHINSEI_PATH_LINUX_DELIMITER_ASCII);
	register const char null_char='\0';

	register const bool is_abs=path[0]==delim;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=delim;
		++r;
		while(r<cnt&&path[r]==delim) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==delim){
			if(w>0&&path[w-1]!=delim){
				path[w++]=delim;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==delim);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=delim){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==dot){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==dot&&path[seg_start+1]==dot){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==dot&&path[rewind-2]==dot&&(rewind==2||path[rewind-3]==delim);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=delim){
						--rewind;
					}
					w=(path[rewind]==delim)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==delim) --w;
	if(!w&&!is_abs){
		path[0]=dot;
		w=1;
	}
	*len=w;
	path[*len]=null_char;
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

int shinsei_linuxPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return linuxPathNormalizeW(path,len);
}

int shinsei_linuxPathNormalizeCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return linuxPathNormalizeCP(code_page,path,len);
}

int shinsei_linuxPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return linuxPathNormalizeU8(path,len);
}

int shinsei_linuxPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return linuxPathNormalizeU16(path,len);
}

int shinsei_linuxPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return linuxPathNormalizeU32(path,len);
}

_SHINSEI_OS_INLINE static int applePathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_APPLE_DELIMITER_U8;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_APPLE_DELIMITER_U8;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_APPLE_DELIMITER_U8) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_APPLE_DELIMITER_U8){
			if(w>0&&path[w-1]!=SHINSEI_PATH_APPLE_DELIMITER_U8){
				path[w++]=SHINSEI_PATH_APPLE_DELIMITER_U8;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_APPLE_DELIMITER_U8);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_APPLE_DELIMITER_U8){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u8'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u8'.'&&path[seg_start+1]==u8'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u8'.'&&path[rewind-2]==u8'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_APPLE_DELIMITER_U8);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_APPLE_DELIMITER_U8){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_APPLE_DELIMITER_U8)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_APPLE_DELIMITER_U8) --w;
	if(!w&&!is_abs){
		path[0]=u8'.';
		w=1;
	}
	*len=w;
	path[*len]=u8'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int applePathNormalizeU16(char16_t*const restrict path,size_t*const restrict len){
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_APPLE_DELIMITER_U16;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_APPLE_DELIMITER_U16;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_APPLE_DELIMITER_U16) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_APPLE_DELIMITER_U16){
			if(w>0&&path[w-1]!=SHINSEI_PATH_APPLE_DELIMITER_U16){
				path[w++]=SHINSEI_PATH_APPLE_DELIMITER_U16;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_APPLE_DELIMITER_U16);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_APPLE_DELIMITER_U16){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u'.'&&path[seg_start+1]==u'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u'.'&&path[rewind-2]==u'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_APPLE_DELIMITER_U16);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_APPLE_DELIMITER_U16){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_APPLE_DELIMITER_U16)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_APPLE_DELIMITER_U16) --w;
	if(!w&&!is_abs){
		path[0]=u'.';
		w=1;
	}
	*len=w;
	path[*len]=u'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int applePathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_APPLE_DELIMITER_U32;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_APPLE_DELIMITER_U32;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_APPLE_DELIMITER_U32) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_APPLE_DELIMITER_U32){
			if(w>0&&path[w-1]!=SHINSEI_PATH_APPLE_DELIMITER_U32){
				path[w++]=SHINSEI_PATH_APPLE_DELIMITER_U32;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_APPLE_DELIMITER_U32);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_APPLE_DELIMITER_U32){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==U'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==U'.'&&path[seg_start+1]==U'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==U'.'&&path[rewind-2]==U'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_APPLE_DELIMITER_U32);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_APPLE_DELIMITER_U32){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_APPLE_DELIMITER_U32)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_APPLE_DELIMITER_U32) --w;
	if(!w&&!is_abs){
		path[0]=U'.';
		w=1;
	}
	*len=w;
	path[*len]=U'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int applePathNormalizeW(wchar_t*const restrict path,size_t*const restrict len){
	#ifdef _SHINSEI_WCHAR_U32
		return applePathNormalizeU32((char32_t*)path,len);
	#else
		return applePathNormalizeU16((char16_t*)path,len);
	#endif
}

_SHINSEI_OS_INLINE static int applePathNormalizeCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char dot=(char)(ebcdic*0x4B+!ebcdic*'.');
	register const char delim=(char)(ebcdic*SHINSEI_PATH_APPLE_DELIMITER_EBCDIC+!ebcdic*SHINSEI_PATH_APPLE_DELIMITER_ASCII);
	register const char null_char='\0';

	register const bool is_abs=path[0]==delim;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=delim;
		++r;
		while(r<cnt&&path[r]==delim) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==delim){
			if(w>0&&path[w-1]!=delim){
				path[w++]=delim;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==delim);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=delim){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==dot){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==dot&&path[seg_start+1]==dot){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==dot&&path[rewind-2]==dot&&(rewind==2||path[rewind-3]==delim);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=delim){
						--rewind;
					}
					w=(path[rewind]==delim)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==delim) --w;
	if(!w&&!is_abs){
		path[0]=dot;
		w=1;
	}
	*len=w;
	path[*len]=null_char;
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

int shinsei_applePathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return applePathNormalizeW(path,len);
}

int shinsei_applePathNormalizeCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return applePathNormalizeCP(code_page,path,len);
}

int shinsei_applePathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return applePathNormalizeU8(path,len);
}

int shinsei_applePathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return applePathNormalizeU16(path,len);
}

int shinsei_applePathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return applePathNormalizeU32(path,len);
}

_SHINSEI_OS_INLINE static int sunPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_SUN_DELIMITER_U8;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_SUN_DELIMITER_U8;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_SUN_DELIMITER_U8) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_SUN_DELIMITER_U8){
			if(w>0&&path[w-1]!=SHINSEI_PATH_SUN_DELIMITER_U8){
				path[w++]=SHINSEI_PATH_SUN_DELIMITER_U8;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_SUN_DELIMITER_U8);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_SUN_DELIMITER_U8){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u8'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u8'.'&&path[seg_start+1]==u8'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u8'.'&&path[rewind-2]==u8'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_SUN_DELIMITER_U8);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_SUN_DELIMITER_U8){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_SUN_DELIMITER_U8)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_SUN_DELIMITER_U8) --w;
	if(!w&&!is_abs){
		path[0]=u8'.';
		w=1;
	}
	*len=w;
	path[*len]=u8'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int sunPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_SUN_DELIMITER_U16;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_SUN_DELIMITER_U16;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_SUN_DELIMITER_U16) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_SUN_DELIMITER_U16){
			if(w>0&&path[w-1]!=SHINSEI_PATH_SUN_DELIMITER_U16){
				path[w++]=SHINSEI_PATH_SUN_DELIMITER_U16;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_SUN_DELIMITER_U16);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_SUN_DELIMITER_U16){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u'.'&&path[seg_start+1]==u'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u'.'&&path[rewind-2]==u'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_SUN_DELIMITER_U16);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_SUN_DELIMITER_U16){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_SUN_DELIMITER_U16)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_SUN_DELIMITER_U16) --w;
	if(!w&&!is_abs){
		path[0]=u'.';
		w=1;
	}
	*len=w;
	path[*len]=u'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int sunPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_SUN_DELIMITER_U32;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_SUN_DELIMITER_U32;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_SUN_DELIMITER_U32) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_SUN_DELIMITER_U32){
			if(w>0&&path[w-1]!=SHINSEI_PATH_SUN_DELIMITER_U32){
				path[w++]=SHINSEI_PATH_SUN_DELIMITER_U32;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_SUN_DELIMITER_U32);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_SUN_DELIMITER_U32){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==U'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==U'.'&&path[seg_start+1]==U'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==U'.'&&path[rewind-2]==U'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_SUN_DELIMITER_U32);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_SUN_DELIMITER_U32){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_SUN_DELIMITER_U32)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_SUN_DELIMITER_U32) --w;
	if(!w&&!is_abs){
		path[0]=U'.';
		w=1;
	}
	*len=w;
	path[*len]=U'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int sunPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return sunPathNormalizeU32((char32_t*)path,len);
	#else
		return sunPathNormalizeU16((char16_t*)path,len);
	#endif
}

_SHINSEI_OS_INLINE static int sunPathNormalizeCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char dot=(char)(ebcdic*0x4B+!ebcdic*'.');
	register const char delim=(char)(ebcdic*SHINSEI_PATH_SUN_DELIMITER_EBCDIC+!ebcdic*SHINSEI_PATH_SUN_DELIMITER_ASCII);
	register const char null_char='\0';

	register const bool is_abs=path[0]==delim;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=delim;
		++r;
		while(r<cnt&&path[r]==delim) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==delim){
			if(w>0&&path[w-1]!=delim){
				path[w++]=delim;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==delim);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=delim){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==dot){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==dot&&path[seg_start+1]==dot){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==dot&&path[rewind-2]==dot&&(rewind==2||path[rewind-3]==delim);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=delim){
						--rewind;
					}
					w=(path[rewind]==delim)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==delim) --w;
	if(!w&&!is_abs){
		path[0]=dot;
		w=1;
	}
	*len=w;
	path[*len]=null_char;
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

int shinsei_sunPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return sunPathNormalizeW(path,len);
}

int shinsei_sunPathNormalizeCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return sunPathNormalizeCP(code_page,path,len);
}

int shinsei_sunPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return sunPathNormalizeU8(path,len);
}

int shinsei_sunPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return sunPathNormalizeU16(path,len);
}

int shinsei_sunPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return sunPathNormalizeU32(path,len);
}

_SHINSEI_OS_INLINE static int freeBSDPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_FREEBSD_DELIMITER_U8;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_FREEBSD_DELIMITER_U8;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U8) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U8){
			if(w>0&&path[w-1]!=SHINSEI_PATH_FREEBSD_DELIMITER_U8){
				path[w++]=SHINSEI_PATH_FREEBSD_DELIMITER_U8;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U8);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_FREEBSD_DELIMITER_U8){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u8'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u8'.'&&path[seg_start+1]==u8'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u8'.'&&path[rewind-2]==u8'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_FREEBSD_DELIMITER_U8);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_FREEBSD_DELIMITER_U8){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_FREEBSD_DELIMITER_U8)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_FREEBSD_DELIMITER_U8) --w;
	if(!w&&!is_abs){
		path[0]=u8'.';
		w=1;
	}
	*len=w;
	path[*len]=u8'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int freeBSDPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_FREEBSD_DELIMITER_U16;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_FREEBSD_DELIMITER_U16;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U16) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U16){
			if(w>0&&path[w-1]!=SHINSEI_PATH_FREEBSD_DELIMITER_U16){
				path[w++]=SHINSEI_PATH_FREEBSD_DELIMITER_U16;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U16);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_FREEBSD_DELIMITER_U16){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u'.'&&path[seg_start+1]==u'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u'.'&&path[rewind-2]==u'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_FREEBSD_DELIMITER_U16);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_FREEBSD_DELIMITER_U16){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_FREEBSD_DELIMITER_U16)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_FREEBSD_DELIMITER_U16) --w;
	if(!w&&!is_abs){
		path[0]=u'.';
		w=1;
	}
	*len=w;
	path[*len]=u'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int freeBSDPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_FREEBSD_DELIMITER_U32;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_FREEBSD_DELIMITER_U32;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U32) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U32){
			if(w>0&&path[w-1]!=SHINSEI_PATH_FREEBSD_DELIMITER_U32){
				path[w++]=SHINSEI_PATH_FREEBSD_DELIMITER_U32;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U32);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_FREEBSD_DELIMITER_U32){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==U'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==U'.'&&path[seg_start+1]==U'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==U'.'&&path[rewind-2]==U'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_FREEBSD_DELIMITER_U32);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_FREEBSD_DELIMITER_U32){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_FREEBSD_DELIMITER_U32)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_FREEBSD_DELIMITER_U32) --w;
	if(!w&&!is_abs){
		path[0]=U'.';
		w=1;
	}
	*len=w;
	path[*len]=U'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int freeBSDPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return freeBSDPathNormalizeU32((char32_t*)path,len);
	#else
		return freeBSDPathNormalizeU16((char16_t*)path,len);
	#endif
}

_SHINSEI_OS_INLINE static int freeBSDPathNormalizeCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char dot=(char)(ebcdic*0x4B+!ebcdic*'.');
	register const char delim=(char)(ebcdic*SHINSEI_PATH_FREEBSD_DELIMITER_EBCDIC+!ebcdic*SHINSEI_PATH_FREEBSD_DELIMITER_ASCII);
	register const char null_char='\0';

	register const bool is_abs=path[0]==delim;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=delim;
		++r;
		while(r<cnt&&path[r]==delim) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==delim){
			if(w>0&&path[w-1]!=delim){
				path[w++]=delim;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==delim);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=delim){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==dot){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==dot&&path[seg_start+1]==dot){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==dot&&path[rewind-2]==dot&&(rewind==2||path[rewind-3]==delim);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=delim){
						--rewind;
					}
					w=(path[rewind]==delim)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==delim) --w;
	if(!w&&!is_abs){
		path[0]=dot;
		w=1;
	}
	*len=w;
	path[*len]=null_char;
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

int shinsei_freeBSDPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return freeBSDPathNormalizeW(path,len);
}

int shinsei_freeBSDPathNormalizeCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return freeBSDPathNormalizeCP(code_page,path,len);
}

int shinsei_freeBSDPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return freeBSDPathNormalizeU8(path,len);
}

int shinsei_freeBSDPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return freeBSDPathNormalizeU16(path,len);
}

int shinsei_freeBSDPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return freeBSDPathNormalizeU32(path,len);
}

_SHINSEI_OS_INLINE static int cygwinPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_CYGWIN_DELIMITER_U8;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_CYGWIN_DELIMITER_U8;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U8) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U8){
			if(w>0&&path[w-1]!=SHINSEI_PATH_CYGWIN_DELIMITER_U8){
				path[w++]=SHINSEI_PATH_CYGWIN_DELIMITER_U8;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U8);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_CYGWIN_DELIMITER_U8){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u8'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u8'.'&&path[seg_start+1]==u8'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u8'.'&&path[rewind-2]==u8'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_CYGWIN_DELIMITER_U8);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_CYGWIN_DELIMITER_U8){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_CYGWIN_DELIMITER_U8)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_CYGWIN_DELIMITER_U8) --w;
	if(!w&&!is_abs){
		path[0]=u8'.';
		w=1;
	}
	*len=w;
	path[*len]=u8'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int cygwinPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_CYGWIN_DELIMITER_U16;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_CYGWIN_DELIMITER_U16;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U16) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U16){
			if(w>0&&path[w-1]!=SHINSEI_PATH_CYGWIN_DELIMITER_U16){
				path[w++]=SHINSEI_PATH_CYGWIN_DELIMITER_U16;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U16);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_CYGWIN_DELIMITER_U16){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u'.'&&path[seg_start+1]==u'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u'.'&&path[rewind-2]==u'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_CYGWIN_DELIMITER_U16);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_CYGWIN_DELIMITER_U16){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_CYGWIN_DELIMITER_U16)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_CYGWIN_DELIMITER_U16) --w;
	if(!w&&!is_abs){
		path[0]=u'.';
		w=1;
	}
	*len=w;
	path[*len]=u'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int cygwinPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_CYGWIN_DELIMITER_U32;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_CYGWIN_DELIMITER_U32;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U32) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U32){
			if(w>0&&path[w-1]!=SHINSEI_PATH_CYGWIN_DELIMITER_U32){
				path[w++]=SHINSEI_PATH_CYGWIN_DELIMITER_U32;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U32);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_CYGWIN_DELIMITER_U32){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==U'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==U'.'&&path[seg_start+1]==U'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==U'.'&&path[rewind-2]==U'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_CYGWIN_DELIMITER_U32);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_CYGWIN_DELIMITER_U32){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_CYGWIN_DELIMITER_U32)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_CYGWIN_DELIMITER_U32) --w;
	if(!w&&!is_abs){
		path[0]=U'.';
		w=1;
	}
	*len=w;
	path[*len]=U'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int cygwinPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return cygwinPathNormalizeU32((char32_t*)path,len);
	#else
		return cygwinPathNormalizeU16((char16_t*)path,len);
	#endif
}

_SHINSEI_OS_INLINE static int cygwinPathNormalizeCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char dot=(char)(ebcdic*0x4B+!ebcdic*'.');
	register const char delim=(char)(ebcdic*SHINSEI_PATH_CYGWIN_DELIMITER_EBCDIC+!ebcdic*SHINSEI_PATH_CYGWIN_DELIMITER_ASCII);
	register const char null_char='\0';

	register const bool is_abs=path[0]==delim;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=delim;
		++r;
		while(r<cnt&&path[r]==delim) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==delim){
			if(w>0&&path[w-1]!=delim){
				path[w++]=delim;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==delim);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=delim){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==dot){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==dot&&path[seg_start+1]==dot){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==dot&&path[rewind-2]==dot&&(rewind==2||path[rewind-3]==delim);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=delim){
						--rewind;
					}
					w=(path[rewind]==delim)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==delim) --w;
	if(!w&&!is_abs){
		path[0]=dot;
		w=1;
	}
	*len=w;
	path[*len]=null_char;
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

int shinsei_cygwinPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return cygwinPathNormalizeW(path,len);
}

int shinsei_cygwinPathNormalizeCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return cygwinPathNormalizeCP(code_page,path,len);
}

int shinsei_cygwinPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return cygwinPathNormalizeU8(path,len);
}

int shinsei_cygwinPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return cygwinPathNormalizeU16(path,len);
}

int shinsei_cygwinPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return cygwinPathNormalizeU32(path,len);
}

_SHINSEI_OS_INLINE static int uRLPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_URL_DELIMITER_U8;
	if(*len==1){
		return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
	}
	register const bool end_with_slash=path[*len-1]==SHINSEI_PATH_URL_DELIMITER_U8;
	register const size_t cnt=*len-(size_t)end_with_slash;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_URL_DELIMITER_U8;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_URL_DELIMITER_U8) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_URL_DELIMITER_U8){
			if(w>0&&path[w-1]!=SHINSEI_PATH_URL_DELIMITER_U8){
				path[w++]=SHINSEI_PATH_URL_DELIMITER_U8;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_URL_DELIMITER_U8);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_URL_DELIMITER_U8){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u8'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u8'.'&&path[seg_start+1]==u8'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u8'.'&&path[rewind-2]==u8'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_URL_DELIMITER_U8);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_URL_DELIMITER_U8){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_URL_DELIMITER_U8)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_URL_DELIMITER_U8) --w;
	if(!w&&!is_abs){
		path[0]=u8'.';
		w=1;
	}
	if(end_with_slash){
		if(is_abs&&w==1){
			path[1]=u8'\0';
			*len=1;
			return SHINSEI_PATH_ABSOLUTE;
		}
		path[w]=SHINSEI_PATH_URL_DELIMITER_U8;
	}
	*len=w+(size_t)end_with_slash;
	path[*len]=u8'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int uRLPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_URL_DELIMITER_U16;
	if(*len==1){
		return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
	}
	register const bool end_with_slash=path[*len-1]==SHINSEI_PATH_URL_DELIMITER_U16;
	register const size_t cnt=*len-(size_t)end_with_slash;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_URL_DELIMITER_U16;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_URL_DELIMITER_U16) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_URL_DELIMITER_U16){
			if(w>0&&path[w-1]!=SHINSEI_PATH_URL_DELIMITER_U16){
				path[w++]=SHINSEI_PATH_URL_DELIMITER_U16;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_URL_DELIMITER_U16);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_URL_DELIMITER_U16){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u'.'&&path[seg_start+1]==u'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u'.'&&path[rewind-2]==u'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_URL_DELIMITER_U16);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_URL_DELIMITER_U16){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_URL_DELIMITER_U16)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_URL_DELIMITER_U16) --w;
	if(!w&&!is_abs){
		path[0]=u'.';
		w=1;
	}
	if(end_with_slash){
		if(is_abs&&w==1){
			path[1]=u'\0';
			*len=1;
			return SHINSEI_PATH_ABSOLUTE;
		}
		path[w]=SHINSEI_PATH_URL_DELIMITER_U16;
	}
	*len=w+(size_t)end_with_slash;
	path[*len]=u'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

int shinsei_uRLPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	#ifdef _SHINSEI_WCHAR_U32
		return shinsei_uRLPathNormalizeU32((char32_t*)path,len);
	#else
		return uRLPathNormalizeU16((char16_t*)path,len);
	#endif
}

int shinsei_uRLPathNormalizeCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char dot=(char)(ebcdic*0x4B+!ebcdic*'.');
	register const char delim=(char)(ebcdic*SHINSEI_PATH_URL_DELIMITER_EBCDIC+!ebcdic*SHINSEI_PATH_URL_DELIMITER_ASCII);
	register const char null_char='\0';

	register const bool is_abs=path[0]==delim;
	if(*len==1){
		return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
	}
	register const bool end_with_slash=path[*len-1]==delim;
	register const size_t cnt=*len-(size_t)end_with_slash;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=delim;
		++r;
		while(r<cnt&&path[r]==delim) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==delim){
			if(w>0&&path[w-1]!=delim){
				path[w++]=delim;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==delim);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=delim){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==dot){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==dot&&path[seg_start+1]==dot){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==dot&&path[rewind-2]==dot&&(rewind==2||path[rewind-3]==delim);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=delim){
						--rewind;
					}
					w=(path[rewind]==delim)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==delim) --w;
	if(!w&&!is_abs){
		path[0]=dot;
		w=1;
	}
	if(end_with_slash){
		if(is_abs&&w==1){
			path[1]=null_char;
			*len=1;
			return SHINSEI_PATH_ABSOLUTE;
		}
		path[w]=delim;
	}
	*len=w+(size_t)end_with_slash;
	path[*len]=null_char;
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

int shinsei_uRLPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return uRLPathNormalizeU8(path,len);
}

int shinsei_uRLPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return uRLPathNormalizeU16(path,len);
}

int shinsei_uRLPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_URL_DELIMITER_U32;
	if(*len==1){
		return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
	}
	register const bool end_with_slash=path[*len-1]==SHINSEI_PATH_URL_DELIMITER_U32;
	register const size_t cnt=*len-(size_t)end_with_slash;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_URL_DELIMITER_U32;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_URL_DELIMITER_U32) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_URL_DELIMITER_U32){
			if(w>0&&path[w-1]!=SHINSEI_PATH_URL_DELIMITER_U32){
				path[w++]=SHINSEI_PATH_URL_DELIMITER_U32;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_URL_DELIMITER_U32);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_URL_DELIMITER_U32){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==U'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==U'.'&&path[seg_start+1]==U'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==U'.'&&path[rewind-2]==U'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_URL_DELIMITER_U32);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_URL_DELIMITER_U32){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_URL_DELIMITER_U32)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				pos[back]=seg_start;
				back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
				if(back==front){
					front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_URL_DELIMITER_U32) --w;
	if(!w&&!is_abs){
		path[0]=U'.';
		w=1;
	}
	if(end_with_slash){
		if(is_abs&&w==1){
			path[1]=U'\0';
			*len=1;
			return SHINSEI_PATH_ABSOLUTE;
		}
		path[w]=SHINSEI_PATH_URL_DELIMITER_U32;
	}
	*len=w+(size_t)end_with_slash;
	path[*len]=U'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int windowsPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register bool can_traverse=false;
	register bool device_path=false;
	register int res;
	register char8_t* ptr;
	register size_t cnt=*len;
	if(isWindowsPathDelimiterU8(path[0])){
		path[0]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
		if(*len>=2&&isWindowsPathDelimiterU8(path[1])){
			path[1]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
			// Device path "\\?\xxx" or DOS device path "\\.\xxx"
			if(*len>=4&&(path[2]==u8'?'||path[2]==u8'.')&&isWindowsPathDelimiterU8(path[3])){
				// Prevent nested device prefix like "\\?\\?\"
				if(__builtin_expect(*len>=6&&isWindowsPathDelimiterU8(path[4])&&(path[5]==u8'?'||path[5]==u8'.')&&isWindowsPathDelimiterU8(path[6]),0)){
					return SHINSEI_PATH_ILLEGAL;
				}
				path[3]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
				device_path=true;
				// Extended UNC path "\\?\UNC\server\share\xxx"
				if(path[2]==u8'?'&&*len>=8&&(path[4]==u8'U'||path[4]==u8'u')&&(path[5]==u8'N'||path[5]==u8'n')&&(path[6]==u8'C'||path[6]==u8'c')&&isWindowsPathDelimiterU8(path[7])){
					path[4]=u8'U';
					path[5]=u8'N';
					path[6]=u8'C';
					path[7]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
					register size_t i=8;
					// Parse server
					if(__builtin_expect(i>=*len||isWindowsPathDelimiterU8(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!isWindowsPathDelimiterU8(path[i])){
						if(__builtin_expect(isWindowsPathIllegalCharU8(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
					path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
					++i;
					// Parse share
					if(__builtin_expect(i>=*len||isWindowsPathDelimiterU8(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!isWindowsPathDelimiterU8(path[i])){
						if(__builtin_expect(isWindowsPathIllegalCharU8(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(i<*len){
						path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
						ptr=path+i+1;
						cnt=*len-(i+1);
					}
					else{
						ptr=path+i;
						cnt=0;
					}
				}
				else{
					ptr=path+4;
					cnt-=4;
				}
				res=SHINSEI_PATH_ABSOLUTE;
			}
			else{
				// UNC path "\\server\share\xxx". Root is "\\server\share"
				register size_t i=2;
				// Parse server
				if(__builtin_expect(i>=*len||isWindowsPathDelimiterU8(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!isWindowsPathDelimiterU8(path[i])){
					if(__builtin_expect(isWindowsPathIllegalCharU8(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
				path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
				++i;
				// Parse share
				if(__builtin_expect(i>=*len||isWindowsPathDelimiterU8(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!isWindowsPathDelimiterU8(path[i])){
					if(__builtin_expect(isWindowsPathIllegalCharU8(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				// Set root
				if(i<*len){
					path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
					ptr=path+i+1;
					cnt=*len-(i+1);
				}
				else{
					ptr=path+i;
					cnt=0;
				}
				res=SHINSEI_PATH_ABSOLUTE;
			}
		}
		else{
			// Relative path of current drive "\xxx". Root is "\".
			if(*len==1){
				path[1]=u8'\0';
				return SHINSEI_PATH_RELATIVE;
			}
			ptr=path+1;
			--cnt;
			while(*ptr==u8'.'){
				if(*len==2){
					path[1]=u8'\0';
					*len=1;
					return SHINSEI_PATH_RELATIVE;
				}
				if(ptr[1]==u8'.'){
					if(*len==3){
						path[1]=u8'\0';
						*len=1;
						return SHINSEI_PATH_RELATIVE;
					}
					if(__builtin_expect(ptr[2]==u8'.',0)) return SHINSEI_PATH_ILLEGAL;
					if(isWindowsPathDelimiterU8(ptr[2])){
						// First segment is "..". Can't get parent any more.
						ptr[2]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
						ptr+=3;
						cnt-=3;
						continue;
					}
					// First segment is "..xxx"
					break;
				}
				if(isWindowsPathDelimiterU8(ptr[1])){
					// First segment is "."
					ptr[1]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
					ptr+=2;
					cnt-=2;
					continue;
				}
				// First segment is ".xxx"
				break;
			}
			res=SHINSEI_PATH_RELATIVE;
		}
	}
	else{
		if(*len>=2&&path[1]==u8':'){
			// Local path with drive prefix
			if(__builtin_expect(!isAlphaU8(path[0]),0)) return SHINSEI_PATH_ILLEGAL;
			path[0]=toUpperU8(path[0]);
			if(*len==2){
				// Drive only "X:".
				path[2]=u8'\0';
				return SHINSEI_PATH_RELATIVE;
			}
			if(isWindowsPathDelimiterU8(path[2])){
				// Local absolute path "X:\". Root is "X:\".
				path[2]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
				ptr=path+3;
				cnt-=3;
				res=SHINSEI_PATH_ABSOLUTE;
			}
			else{
				// Drive relative path "C:xxx". No root (can traverse).
				ptr=path+2;
				cnt-=2;
				can_traverse=true;
				res=SHINSEI_PATH_RELATIVE;
			}
		}
		else{
			// Normal relative path "xxx". No root (can traverse).
			ptr=path;
			can_traverse=true;
			res=SHINSEI_PATH_RELATIVE;
		}
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	register size_t r=0;
	register size_t w=0;
	while(r<cnt){
		// Unify delimiter
		if(isWindowsPathDelimiterU8(ptr[r])){
			ptr[w++]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
			// Collapse multiple delimiters
			while(++r<cnt&&isWindowsPathDelimiterU8(ptr[r]));
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&!isWindowsPathDelimiterU8(ptr[r])){
			if(!device_path&&__builtin_expect(isWindowsPathIllegalCharU8(ptr[r]),0)) return SHINSEI_PATH_ILLEGAL;
			ptr[w++]=ptr[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&ptr[seg_start]==u8'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&ptr[seg_start]==u8'.'&&ptr[seg_start+1]==u8'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(can_traverse){
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more.
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	*len=(size_t)(ptr-path)+w;
	path[*len]=u8'\0';
	return res;
}

_SHINSEI_OS_INLINE static int windowsPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register bool can_traverse=false;
	register bool device_path=false;
	register int res;
	register char16_t* ptr;
	register size_t cnt=*len;
	if(isWindowsPathDelimiterU16(path[0])){
		path[0]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
		if(*len>=2&&isWindowsPathDelimiterU16(path[1])){
			path[1]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
			// Device path "\\?\xxx" or DOS device path "\\.\xxx"
			if(*len>=4&&(path[2]==u'?'||path[2]==u'.')&&isWindowsPathDelimiterU16(path[3])){
				// Prevent nested device prefix like "\\?\\?\"
				if(__builtin_expect(*len>=6&&isWindowsPathDelimiterU16(path[4])&&(path[5]==u'?'||path[5]==u'.')&&isWindowsPathDelimiterU16(path[6]),0)){
					return SHINSEI_PATH_ILLEGAL;
				}
				path[3]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
				device_path=true;
				// Extended UNC path "\\?\UNC\server\share\xxx"
				if(path[2]==u'?'&&*len>=8&&(path[4]==u'U'||path[4]==u'u')&&(path[5]==u'N'||path[5]==u'n')&&(path[6]==u'C'||path[6]==u'c')&&isWindowsPathDelimiterU16(path[7])){
					path[4]=u'U';
					path[5]=u'N';
					path[6]=u'C';
					path[7]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
					register size_t i=8;
					// Parse server
					if(__builtin_expect(i>=*len||isWindowsPathDelimiterU16(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!isWindowsPathDelimiterU16(path[i])){
						if(__builtin_expect(isWindowsPathIllegalCharU16(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
					path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
					++i;
					// Parse share
					if(__builtin_expect(i>=*len||isWindowsPathDelimiterU16(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!isWindowsPathDelimiterU16(path[i])){
						if(__builtin_expect(isWindowsPathIllegalCharU16(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(i<*len){
						path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
						ptr=path+i+1;
						cnt=*len-(i+1);
					}
					else{
						ptr=path+i;
						cnt=0;
					}
				}
				else{
					ptr=path+4;
					cnt-=4;
				}
				res=SHINSEI_PATH_ABSOLUTE;
			}
			else{
				// UNC path "\\server\share\xxx". Root is "\\server\share"
				register size_t i=2;
				// Parse server
				if(__builtin_expect(i>=*len||isWindowsPathDelimiterU16(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!isWindowsPathDelimiterU16(path[i])){
					if(__builtin_expect(isWindowsPathIllegalCharU16(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
				path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
				++i;
				// Parse share
				if(__builtin_expect(i>=*len||isWindowsPathDelimiterU16(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!isWindowsPathDelimiterU16(path[i])){
					if(__builtin_expect(isWindowsPathIllegalCharU16(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				// Set root
				if(i<*len){
					path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
					ptr=path+i+1;
					cnt=*len-(i+1);
				}
				else{
					ptr=path+i;
					cnt=0;
				}
				res=SHINSEI_PATH_ABSOLUTE;
			}
		}
		else{
			// Relative path of current drive "\xxx". Root is "\".
			if(*len==1){
				path[1]=u'\0';
				return SHINSEI_PATH_RELATIVE;
			}
			ptr=path+1;
			--cnt;
			while(*ptr==u'.'){
				if(*len==2){
					path[1]=u'\0';
					*len=1;
					return SHINSEI_PATH_RELATIVE;
				}
				if(ptr[1]==u'.'){
					if(*len==3){
						path[1]=u'\0';
						*len=1;
						return SHINSEI_PATH_RELATIVE;
					}
					if(__builtin_expect(ptr[2]==u'.',0)) return SHINSEI_PATH_ILLEGAL;
					if(isWindowsPathDelimiterU16(ptr[2])){
						// First segment is "..". Can't get parent any more.
						ptr[2]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
						ptr+=3;
						cnt-=3;
						continue;
					}
					// First segment is "..xxx"
					break;
				}
				if(isWindowsPathDelimiterU16(ptr[1])){
					// First segment is "."
					ptr[1]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
					ptr+=2;
					cnt-=2;
					continue;
				}
				// First segment is ".xxx"
				break;
			}
			res=SHINSEI_PATH_RELATIVE;
		}
	}
	else{
		if(*len>=2&&path[1]==u':'){
			// Local path with drive prefix
			if(__builtin_expect(!isAlphaU16(path[0]),0)) return SHINSEI_PATH_ILLEGAL;
			path[0]=toUpperU16(path[0]);
			if(*len==2){
				// Drive only "X:".
				path[2]=u'\0';
				return SHINSEI_PATH_RELATIVE;
			}
			if(isWindowsPathDelimiterU16(path[2])){
				// Local absolute path "X:\". Root is "X:\".
				path[2]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
				ptr=path+3;
				cnt-=3;
				res=SHINSEI_PATH_ABSOLUTE;
			}
			else{
				// Drive relative path "C:xxx". No root (can traverse).
				ptr=path+2;
				cnt-=2;
				can_traverse=true;
				res=SHINSEI_PATH_RELATIVE;
			}
		}
		else{
			// Normal relative path "xxx". No root (can traverse).
			ptr=path;
			can_traverse=true;
			res=SHINSEI_PATH_RELATIVE;
		}
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	register size_t r=0;
	register size_t w=0;
	while(r<cnt){
		// Unify delimiter
		if(isWindowsPathDelimiterU16(ptr[r])){
			ptr[w++]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
			// Collapse multiple delimiters
			while(++r<cnt&&isWindowsPathDelimiterU16(ptr[r]));
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&!isWindowsPathDelimiterU16(ptr[r])){
			if(!device_path&&__builtin_expect(isWindowsPathIllegalCharU16(ptr[r]),0)) return SHINSEI_PATH_ILLEGAL;
			ptr[w++]=ptr[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&ptr[seg_start]==u'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&ptr[seg_start]==u'.'&&ptr[seg_start+1]==u'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(can_traverse){
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more.
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	*len=(size_t)(ptr-path)+w;
	path[*len]=u'\0';
	return res;
}

_SHINSEI_OS_INLINE static int windowsPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register bool can_traverse=false;
	register bool device_path=false;
	register int res;
	register char32_t* ptr;
	register size_t cnt=*len;
	if(isWindowsPathDelimiterU32(path[0])){
		path[0]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
		if(*len>=2&&isWindowsPathDelimiterU32(path[1])){
			path[1]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
			// Device path "\\?\xxx" or DOS device path "\\.\xxx"
			if(*len>=4&&(path[2]==U'?'||path[2]==U'.')&&isWindowsPathDelimiterU32(path[3])){
				// Prevent nested device prefix like "\\?\\?\"
				if(__builtin_expect(*len>=6&&isWindowsPathDelimiterU32(path[4])&&(path[5]==U'?'||path[5]==U'.')&&isWindowsPathDelimiterU32(path[6]),0)){
					return SHINSEI_PATH_ILLEGAL;
				}
				path[3]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
				device_path=true;
				// Extended UNC path "\\?\UNC\server\share\xxx"
				if(path[2]==U'?'&&*len>=8&&(path[4]==U'U'||path[4]==U'u')&&(path[5]==U'N'||path[5]==U'n')&&(path[6]==U'C'||path[6]==U'c')&&isWindowsPathDelimiterU32(path[7])){
					path[4]=U'U';
					path[5]=U'N';
					path[6]=U'C';
					path[7]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
					register size_t i=8;
					// Parse server
					if(__builtin_expect(i>=*len||isWindowsPathDelimiterU32(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!isWindowsPathDelimiterU32(path[i])){
						if(__builtin_expect(isWindowsPathIllegalCharU32(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
					path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
					++i;
					// Parse share
					if(__builtin_expect(i>=*len||isWindowsPathDelimiterU32(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!isWindowsPathDelimiterU32(path[i])){
						if(__builtin_expect(isWindowsPathIllegalCharU32(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(i<*len){
						path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
						ptr=path+i+1;
						cnt=*len-(i+1);
					}
					else{
						ptr=path+i;
						cnt=0;
					}
				}
				else{
					ptr=path+4;
					cnt-=4;
				}
				res=SHINSEI_PATH_ABSOLUTE;
			}
			else{
				// UNC path "\\server\share\xxx". Root is "\\server\share"
				register size_t i=2;
				// Parse server
				if(__builtin_expect(i>=*len||isWindowsPathDelimiterU32(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!isWindowsPathDelimiterU32(path[i])){
					if(__builtin_expect(isWindowsPathIllegalCharU32(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
				path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
				++i;
				// Parse share
				if(__builtin_expect(i>=*len||isWindowsPathDelimiterU32(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!isWindowsPathDelimiterU32(path[i])){
					if(__builtin_expect(isWindowsPathIllegalCharU32(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				// Set root
				if(i<*len){
					path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
					ptr=path+i+1;
					cnt=*len-(i+1);
				}
				else{
					ptr=path+i;
					cnt=0;
				}
				res=SHINSEI_PATH_ABSOLUTE;
			}
		}
		else{
			// Relative path of current drive "\xxx". Root is "\".
			if(*len==1){
				path[1]=U'\0';
				return SHINSEI_PATH_RELATIVE;
			}
			ptr=path+1;
			--cnt;
			while(*ptr==U'.'){
				if(*len==2){
					path[1]=U'\0';
					*len=1;
					return SHINSEI_PATH_RELATIVE;
				}
				if(ptr[1]==U'.'){
					if(*len==3){
						path[1]=U'\0';
						*len=1;
						return SHINSEI_PATH_RELATIVE;
					}
					if(__builtin_expect(ptr[2]==U'.',0)) return SHINSEI_PATH_ILLEGAL;
					if(isWindowsPathDelimiterU32(ptr[2])){
						// First segment is "..". Can't get parent any more.
						ptr[2]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
						ptr+=3;
						cnt-=3;
						continue;
					}
					// First segment is "..xxx"
					break;
				}
				if(isWindowsPathDelimiterU32(ptr[1])){
					// First segment is "."
					ptr[1]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
					ptr+=2;
					cnt-=2;
					continue;
				}
				// First segment is ".xxx"
				break;
			}
			res=SHINSEI_PATH_RELATIVE;
		}
	}
	else{
		if(*len>=2&&path[1]==U':'){
			// Local path with drive prefix
			if(__builtin_expect(!isAlphaU32(path[0]),0)) return SHINSEI_PATH_ILLEGAL;
			path[0]=toUpperU32(path[0]);
			if(*len==2){
				// Drive only "X:".
				path[2]=U'\0';
				return SHINSEI_PATH_RELATIVE;
			}
			if(isWindowsPathDelimiterU32(path[2])){
				// Local absolute path "X:\". Root is "X:\".
				path[2]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
				ptr=path+3;
				cnt-=3;
				res=SHINSEI_PATH_ABSOLUTE;
			}
			else{
				// Drive relative path "C:xxx". No root (can traverse).
				ptr=path+2;
				cnt-=2;
				can_traverse=true;
				res=SHINSEI_PATH_RELATIVE;
			}
		}
		else{
			// Normal relative path "xxx". No root (can traverse).
			ptr=path;
			can_traverse=true;
			res=SHINSEI_PATH_RELATIVE;
		}
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	register size_t r=0;
	register size_t w=0;
	while(r<cnt){
		// Unify delimiter
		if(isWindowsPathDelimiterU32(ptr[r])){
			ptr[w++]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
			// Collapse multiple delimiters
			while(++r<cnt&&isWindowsPathDelimiterU32(ptr[r]));
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&!isWindowsPathDelimiterU32(ptr[r])){
			if(!device_path&&__builtin_expect(isWindowsPathIllegalCharU32(ptr[r]),0)) return SHINSEI_PATH_ILLEGAL;
			ptr[w++]=ptr[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&ptr[seg_start]==U'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&ptr[seg_start]==U'.'&&ptr[seg_start+1]==U'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(can_traverse){
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more.
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	*len=(size_t)(ptr-path)+w;
	path[*len]=U'\0';
	return res;
}

_SHINSEI_OS_INLINE static int windowsPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return windowsPathNormalizeNoTraversalU32((char32_t*)path,len);
	#else
		return windowsPathNormalizeNoTraversalU16((char16_t*)path,len);
	#endif
}

_SHINSEI_OS_INLINE static int windowsPathNormalizeNoTraversalCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char q_mark=(char)(ebcdic*0x6F+!ebcdic*'?');
	register const char dot=(char)(ebcdic*0x4B+!ebcdic*'.');
	register const char char_U=(char)(ebcdic*0xE4+!ebcdic*'U');
	register const char char_u=(char)(ebcdic*0xA4+!ebcdic*'u');
	register const char char_N=(char)(ebcdic*0xD5+!ebcdic*'N');
	register const char char_n=(char)(ebcdic*0x95+!ebcdic*'n');
	register const char char_C=(char)(ebcdic*0xC3+!ebcdic*'C');
	register const char char_c=(char)(ebcdic*0x83+!ebcdic*'c');
	register const char colon=(char)(ebcdic*0x7A+!ebcdic*':');
	register const char null_char='\0';
	register const char delim_win=(char)(ebcdic*SHINSEI_PATH_WINDOWS_DELIMITER_EBCDIC+!ebcdic*SHINSEI_PATH_WINDOWS_DELIMITER_ASCII);
	
	register bool can_traverse=false;
	register bool device_path=false;
	register int res;
	register char* ptr;
	register size_t cnt=*len;
	if(isWindowsPathDelimiterCP(code_page,path[0])){
		path[0]=delim_win;
		if(*len>=2&&isWindowsPathDelimiterCP(code_page,path[1])){
			path[1]=delim_win;
			// Device path "\\?\xxx" or DOS device path "\\.\xxx"
			if(*len>=4&&(path[2]==q_mark||path[2]==dot)&&isWindowsPathDelimiterCP(code_page,path[3])){
				// Prevent nested device prefix like "\\?\\?\"
				if(__builtin_expect(*len>=6&&isWindowsPathDelimiterCP(code_page,path[4])&&(path[5]==q_mark||path[5]==dot)&&isWindowsPathDelimiterCP(code_page,path[6]),0)){
					return SHINSEI_PATH_ILLEGAL;
				}
				path[3]=delim_win;
				device_path=true;
				// Extended UNC path "\\?\UNC\server\share\xxx"
				if(path[2]==q_mark&&*len>=8&&(path[4]==char_U||path[4]==char_u)&&(path[5]==char_N||path[5]==char_n)&&(path[6]==char_C||path[6]==char_c)&&isWindowsPathDelimiterCP(code_page,path[7])){
					path[4]=char_U;
					path[5]=char_N;
					path[6]=char_C;
					path[7]=delim_win;
					register size_t i=8;
					// Parse server
					if(__builtin_expect(i>=*len||isWindowsPathDelimiterCP(code_page,path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!isWindowsPathDelimiterCP(code_page,path[i])){
						if(__builtin_expect(isWindowsPathIllegalCharCP(code_page,path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
					path[i]=delim_win;
					++i;
					// Parse share
					if(__builtin_expect(i>=*len||isWindowsPathDelimiterCP(code_page,path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!isWindowsPathDelimiterCP(code_page,path[i])){
						if(__builtin_expect(isWindowsPathIllegalCharCP(code_page,path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(i<*len){
						path[i]=delim_win;
						ptr=path+i+1;
						cnt=*len-(i+1);
					}
					else{
						ptr=path+i;
						cnt=0;
					}
				}
				else{
					ptr=path+4;
					cnt-=4;
				}
				res=SHINSEI_PATH_ABSOLUTE;
			}
			else{
				// UNC path "\\server\share\xxx". Root is "\\server\share"
				register size_t i=2;
				// Parse server
				if(__builtin_expect(i>=*len||isWindowsPathDelimiterCP(code_page,path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!isWindowsPathDelimiterCP(code_page,path[i])){
					if(__builtin_expect(isWindowsPathIllegalCharCP(code_page,path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
				path[i]=delim_win;
				++i;
				// Parse share
				if(__builtin_expect(i>=*len||isWindowsPathDelimiterCP(code_page,path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!isWindowsPathDelimiterCP(code_page,path[i])){
					if(__builtin_expect(isWindowsPathIllegalCharCP(code_page,path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				// Set root
				if(i<*len){
					path[i]=delim_win;
					ptr=path+i+1;
					cnt=*len-(i+1);
				}
				else{
					ptr=path+i;
					cnt=0;
				}
				res=SHINSEI_PATH_ABSOLUTE;
			}
		}
		else{
			// Relative path of current drive "\xxx". Root is "\".
			if(*len==1){
				path[1]=null_char;
				return SHINSEI_PATH_RELATIVE;
			}
			ptr=path+1;
			--cnt;
			while(*ptr==dot){
				if(*len==2){
					path[1]=null_char;
					*len=1;
					return SHINSEI_PATH_RELATIVE;
				}
				if(ptr[1]==dot){
					if(*len==3){
						path[1]=null_char;
						*len=1;
						return SHINSEI_PATH_RELATIVE;
					}
					if(__builtin_expect(ptr[2]==dot,0)) return SHINSEI_PATH_ILLEGAL;
					if(isWindowsPathDelimiterCP(code_page,ptr[2])){
						// First segment is "..". Can't get parent any more.
						ptr[2]=delim_win;
						ptr+=3;
						cnt-=3;
						continue;
					}
					// First segment is "..xxx"
					break;
				}
				if(isWindowsPathDelimiterCP(code_page,ptr[1])){
					// First segment is "."
					ptr[1]=delim_win;
					ptr+=2;
					cnt-=2;
					continue;
				}
				// First segment is ".xxx"
				break;
			}
			res=SHINSEI_PATH_RELATIVE;
		}
	}
	else{
		if(*len>=2&&path[1]==colon){
			// Local path with drive prefix
			if(__builtin_expect(!isAlphaCP(code_page,path[0]),0)) return SHINSEI_PATH_ILLEGAL;
			path[0]=(char)toUpperCP(code_page,path[0]);
			if(*len==2){
				// Drive only "X:".
				path[2]=null_char;
				return SHINSEI_PATH_RELATIVE;
			}
			if(isWindowsPathDelimiterCP(code_page,path[2])){
				// Local absolute path "X:\". Root is "X:\".
				path[2]=delim_win;
				ptr=path+3;
				cnt-=3;
				res=SHINSEI_PATH_ABSOLUTE;
			}
			else{
				// Drive relative path "C:xxx". No root (can traverse).
				ptr=path+2;
				cnt-=2;
				can_traverse=true;
				res=SHINSEI_PATH_RELATIVE;
			}
		}
		else{
			// Normal relative path "xxx". No root (can traverse).
			ptr=path;
			can_traverse=true;
			res=SHINSEI_PATH_RELATIVE;
		}
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	register size_t r=0;
	register size_t w=0;
	while(r<cnt){
		// Unify delimiter
		if(isWindowsPathDelimiterCP(code_page,ptr[r])){
			ptr[w++]=delim_win;
			// Collapse multiple delimiters
			while(++r<cnt&&isWindowsPathDelimiterCP(code_page,ptr[r]));
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&!isWindowsPathDelimiterCP(code_page,ptr[r])){
			if(!device_path&&__builtin_expect(isWindowsPathIllegalCharCP(code_page,ptr[r]),0)) return SHINSEI_PATH_ILLEGAL;
			ptr[w++]=ptr[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&ptr[seg_start]==dot){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&ptr[seg_start]==dot&&ptr[seg_start+1]==dot){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(can_traverse){
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more.
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	*len=(size_t)(ptr-path)+w;
	path[*len]=null_char;
	return res;
}

int shinsei_windowsPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return windowsPathNormalizeNoTraversalW(path,len);
}
int shinsei_windowsPathNormalizeNoTraversalCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return windowsPathNormalizeNoTraversalCP(code_page,path,len);
}
int shinsei_windowsPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return windowsPathNormalizeNoTraversalU8(path,len);
}
int shinsei_windowsPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return windowsPathNormalizeNoTraversalU16(path,len);
}
int shinsei_windowsPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return windowsPathNormalizeNoTraversalU32(path,len);
}

_SHINSEI_OS_INLINE static int unixPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_UNIX_DELIMITER_U8;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_UNIX_DELIMITER_U8;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_U8) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_UNIX_DELIMITER_U8){
			if(w>0&&path[w-1]!=SHINSEI_PATH_UNIX_DELIMITER_U8){
				path[w++]=SHINSEI_PATH_UNIX_DELIMITER_U8;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_U8);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_UNIX_DELIMITER_U8){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u8'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u8'.'&&path[seg_start+1]==u8'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u8'.'&&path[rewind-2]==u8'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_UNIX_DELIMITER_U8);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_UNIX_DELIMITER_U8){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_UNIX_DELIMITER_U8)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_UNIX_DELIMITER_U8) --w;
	if(!w&&!is_abs){
		path[0]=u8'.';
		w=1;
	}
	*len=w;
	path[*len]=u8'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int unixPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_UNIX_DELIMITER_U16;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_UNIX_DELIMITER_U16;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_U16) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_UNIX_DELIMITER_U16){
			if(w>0&&path[w-1]!=SHINSEI_PATH_UNIX_DELIMITER_U16){
				path[w++]=SHINSEI_PATH_UNIX_DELIMITER_U16;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_U16);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_UNIX_DELIMITER_U16){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u'.'&&path[seg_start+1]==u'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u'.'&&path[rewind-2]==u'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_UNIX_DELIMITER_U16);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_UNIX_DELIMITER_U16){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_UNIX_DELIMITER_U16)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_UNIX_DELIMITER_U16) --w;
	if(!w&&!is_abs){
		path[0]=u'.';
		w=1;
	}
	*len=w;
	path[*len]=u'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int unixPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_UNIX_DELIMITER_U32;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_UNIX_DELIMITER_U32;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_U32) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_UNIX_DELIMITER_U32){
			if(w>0&&path[w-1]!=SHINSEI_PATH_UNIX_DELIMITER_U32){
				path[w++]=SHINSEI_PATH_UNIX_DELIMITER_U32;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_U32);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_UNIX_DELIMITER_U32){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==U'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==U'.'&&path[seg_start+1]==U'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==U'.'&&path[rewind-2]==U'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_UNIX_DELIMITER_U32);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_UNIX_DELIMITER_U32){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_UNIX_DELIMITER_U32)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_UNIX_DELIMITER_U32) --w;
	if(!w&&!is_abs){
		path[0]=U'.';
		w=1;
	}
	*len=w;
	path[*len]=U'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int unixPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return unixPathNormalizeNoTraversalU32((char32_t*)path,len);
	#else
		return unixPathNormalizeNoTraversalU16((char16_t*)path,len);
	#endif
}

_SHINSEI_OS_INLINE static int unixPathNormalizeNoTraversalCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char dot=(char)(ebcdic*0x4B+!ebcdic*'.');
	register const char delim=(char)(ebcdic*SHINSEI_PATH_UNIX_DELIMITER_EBCDIC+!ebcdic*SHINSEI_PATH_UNIX_DELIMITER_ASCII);
	register const char null_char='\0';
	
	register const bool is_abs=path[0]==delim;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=delim;
		++r;
		while(r<cnt&&path[r]==delim) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==delim){
			if(w>0&&path[w-1]!=delim){
				path[w++]=delim;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==delim);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=delim){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==dot){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==dot&&path[seg_start+1]==dot){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==dot&&path[rewind-2]==dot&&(rewind==2||path[rewind-3]==delim);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=delim){
						--rewind;
					}
					w=(path[rewind]==delim)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==delim) --w;
	if(!w&&!is_abs){
		path[0]=dot;
		w=1;
	}
	*len=w;
	path[*len]=null_char;
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

int shinsei_unixPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return unixPathNormalizeNoTraversalW(path,len);
}
int shinsei_unixPathNormalizeNoTraversalCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return unixPathNormalizeNoTraversalCP(code_page,path,len);
}
int shinsei_unixPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return unixPathNormalizeNoTraversalU8(path,len);
}
int shinsei_unixPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return unixPathNormalizeNoTraversalU16(path,len);
}
int shinsei_unixPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return unixPathNormalizeNoTraversalU32(path,len);
}

_SHINSEI_OS_INLINE static int linuxPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_LINUX_DELIMITER_U8;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_LINUX_DELIMITER_U8;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_LINUX_DELIMITER_U8) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_LINUX_DELIMITER_U8){
			if(w>0&&path[w-1]!=SHINSEI_PATH_LINUX_DELIMITER_U8){
				path[w++]=SHINSEI_PATH_LINUX_DELIMITER_U8;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_LINUX_DELIMITER_U8);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_LINUX_DELIMITER_U8){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u8'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u8'.'&&path[seg_start+1]==u8'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u8'.'&&path[rewind-2]==u8'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_LINUX_DELIMITER_U8);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_LINUX_DELIMITER_U8){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_LINUX_DELIMITER_U8)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_LINUX_DELIMITER_U8) --w;
	if(!w&&!is_abs){
		path[0]=u8'.';
		w=1;
	}
	*len=w;
	path[*len]=u8'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int linuxPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_LINUX_DELIMITER_U16;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_LINUX_DELIMITER_U16;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_LINUX_DELIMITER_U16) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_LINUX_DELIMITER_U16){
			if(w>0&&path[w-1]!=SHINSEI_PATH_LINUX_DELIMITER_U16){
				path[w++]=SHINSEI_PATH_LINUX_DELIMITER_U16;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_LINUX_DELIMITER_U16);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_LINUX_DELIMITER_U16){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u'.'&&path[seg_start+1]==u'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u'.'&&path[rewind-2]==u'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_LINUX_DELIMITER_U16);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_LINUX_DELIMITER_U16){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_LINUX_DELIMITER_U16)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_LINUX_DELIMITER_U16) --w;
	if(!w&&!is_abs){
		path[0]=u'.';
		w=1;
	}
	*len=w;
	path[*len]=u'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int linuxPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_LINUX_DELIMITER_U32;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_LINUX_DELIMITER_U32;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_LINUX_DELIMITER_U32) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_LINUX_DELIMITER_U32){
			if(w>0&&path[w-1]!=SHINSEI_PATH_LINUX_DELIMITER_U32){
				path[w++]=SHINSEI_PATH_LINUX_DELIMITER_U32;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_LINUX_DELIMITER_U32);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_LINUX_DELIMITER_U32){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==U'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==U'.'&&path[seg_start+1]==U'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==U'.'&&path[rewind-2]==U'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_LINUX_DELIMITER_U32);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_LINUX_DELIMITER_U32){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_LINUX_DELIMITER_U32)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_LINUX_DELIMITER_U32) --w;
	if(!w&&!is_abs){
		path[0]=U'.';
		w=1;
	}
	*len=w;
	path[*len]=U'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int linuxPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return linuxPathNormalizeNoTraversalU32((char32_t*)path,len);
	#else
		return linuxPathNormalizeNoTraversalU16((char16_t*)path,len);
	#endif
}

_SHINSEI_OS_INLINE static int linuxPathNormalizeNoTraversalCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char dot=(char)(ebcdic*0x4B+!ebcdic*'.');
	register const char delim=(char)(ebcdic*SHINSEI_PATH_LINUX_DELIMITER_EBCDIC+!ebcdic*SHINSEI_PATH_LINUX_DELIMITER_ASCII);
	register const char null_char='\0';
	
	register const bool is_abs=path[0]==delim;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=delim;
		++r;
		while(r<cnt&&path[r]==delim) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==delim){
			if(w>0&&path[w-1]!=delim){
				path[w++]=delim;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==delim);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=delim){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==dot){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==dot&&path[seg_start+1]==dot){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==dot&&path[rewind-2]==dot&&(rewind==2||path[rewind-3]==delim);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=delim){
						--rewind;
					}
					w=(path[rewind]==delim)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==delim) --w;
	if(!w&&!is_abs){
		path[0]=dot;
		w=1;
	}
	*len=w;
	path[*len]=null_char;
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

int shinsei_linuxPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return linuxPathNormalizeNoTraversalW(path,len);
}
int shinsei_linuxPathNormalizeNoTraversalCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return linuxPathNormalizeNoTraversalCP(code_page,path,len);
}
int shinsei_linuxPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return linuxPathNormalizeNoTraversalU8(path,len);
}
int shinsei_linuxPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return linuxPathNormalizeNoTraversalU16(path,len);
}
int shinsei_linuxPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return linuxPathNormalizeNoTraversalU32(path,len);
}

_SHINSEI_OS_INLINE static int applePathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_APPLE_DELIMITER_U8;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_APPLE_DELIMITER_U8;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_APPLE_DELIMITER_U8) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_APPLE_DELIMITER_U8){
			if(w>0&&path[w-1]!=SHINSEI_PATH_APPLE_DELIMITER_U8){
				path[w++]=SHINSEI_PATH_APPLE_DELIMITER_U8;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_APPLE_DELIMITER_U8);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_APPLE_DELIMITER_U8){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u8'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u8'.'&&path[seg_start+1]==u8'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u8'.'&&path[rewind-2]==u8'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_APPLE_DELIMITER_U8);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_APPLE_DELIMITER_U8){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_APPLE_DELIMITER_U8)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_APPLE_DELIMITER_U8) --w;
	if(!w&&!is_abs){
		path[0]=u8'.';
		w=1;
	}
	*len=w;
	path[*len]=u8'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int applePathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_APPLE_DELIMITER_U16;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_APPLE_DELIMITER_U16;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_APPLE_DELIMITER_U16) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_APPLE_DELIMITER_U16){
			if(w>0&&path[w-1]!=SHINSEI_PATH_APPLE_DELIMITER_U16){
				path[w++]=SHINSEI_PATH_APPLE_DELIMITER_U16;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_APPLE_DELIMITER_U16);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_APPLE_DELIMITER_U16){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u'.'&&path[seg_start+1]==u'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u'.'&&path[rewind-2]==u'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_APPLE_DELIMITER_U16);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_APPLE_DELIMITER_U16){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_APPLE_DELIMITER_U16)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_APPLE_DELIMITER_U16) --w;
	if(!w&&!is_abs){
		path[0]=u'.';
		w=1;
	}
	*len=w;
	path[*len]=u'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int applePathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_APPLE_DELIMITER_U32;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_APPLE_DELIMITER_U32;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_APPLE_DELIMITER_U32) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_APPLE_DELIMITER_U32){
			if(w>0&&path[w-1]!=SHINSEI_PATH_APPLE_DELIMITER_U32){
				path[w++]=SHINSEI_PATH_APPLE_DELIMITER_U32;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_APPLE_DELIMITER_U32);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_APPLE_DELIMITER_U32){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==U'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==U'.'&&path[seg_start+1]==U'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==U'.'&&path[rewind-2]==U'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_APPLE_DELIMITER_U32);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_APPLE_DELIMITER_U32){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_APPLE_DELIMITER_U32)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_APPLE_DELIMITER_U32) --w;
	if(!w&&!is_abs){
		path[0]=U'.';
		w=1;
	}
	*len=w;
	path[*len]=U'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int applePathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return applePathNormalizeNoTraversalU32((char32_t*)path,len);
	#else
		return applePathNormalizeNoTraversalU16((char16_t*)path,len);
	#endif
}

_SHINSEI_OS_INLINE static int applePathNormalizeNoTraversalCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char dot=(char)(ebcdic*0x4B+!ebcdic*'.');
	register const char delim=(char)(ebcdic*SHINSEI_PATH_APPLE_DELIMITER_EBCDIC+!ebcdic*SHINSEI_PATH_APPLE_DELIMITER_ASCII);
	register const char null_char='\0';
	
	register const bool is_abs=path[0]==delim;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=delim;
		++r;
		while(r<cnt&&path[r]==delim) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==delim){
			if(w>0&&path[w-1]!=delim){
				path[w++]=delim;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==delim);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=delim){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==dot){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==dot&&path[seg_start+1]==dot){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==dot&&path[rewind-2]==dot&&(rewind==2||path[rewind-3]==delim);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=delim){
						--rewind;
					}
					w=(path[rewind]==delim)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==delim) --w;
	if(!w&&!is_abs){
		path[0]=dot;
		w=1;
	}
	*len=w;
	path[*len]=null_char;
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

int shinsei_applePathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return applePathNormalizeNoTraversalW(path,len);
}
int shinsei_applePathNormalizeNoTraversalCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return applePathNormalizeNoTraversalCP(code_page,path,len);
}
int shinsei_applePathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return applePathNormalizeNoTraversalU8(path,len);
}
int shinsei_applePathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return applePathNormalizeNoTraversalU16(path,len);
}
int shinsei_applePathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return applePathNormalizeNoTraversalU32(path,len);
}

_SHINSEI_OS_INLINE static int sunPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_SUN_DELIMITER_U8;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_SUN_DELIMITER_U8;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_SUN_DELIMITER_U8) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_SUN_DELIMITER_U8){
			if(w>0&&path[w-1]!=SHINSEI_PATH_SUN_DELIMITER_U8){
				path[w++]=SHINSEI_PATH_SUN_DELIMITER_U8;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_SUN_DELIMITER_U8);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_SUN_DELIMITER_U8){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u8'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u8'.'&&path[seg_start+1]==u8'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u8'.'&&path[rewind-2]==u8'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_SUN_DELIMITER_U8);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_SUN_DELIMITER_U8){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_SUN_DELIMITER_U8)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_SUN_DELIMITER_U8) --w;
	if(!w&&!is_abs){
		path[0]=u8'.';
		w=1;
	}
	*len=w;
	path[*len]=u8'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int sunPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_SUN_DELIMITER_U16;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_SUN_DELIMITER_U16;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_SUN_DELIMITER_U16) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_SUN_DELIMITER_U16){
			if(w>0&&path[w-1]!=SHINSEI_PATH_SUN_DELIMITER_U16){
				path[w++]=SHINSEI_PATH_SUN_DELIMITER_U16;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_SUN_DELIMITER_U16);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_SUN_DELIMITER_U16){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u'.'&&path[seg_start+1]==u'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u'.'&&path[rewind-2]==u'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_SUN_DELIMITER_U16);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_SUN_DELIMITER_U16){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_SUN_DELIMITER_U16)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_SUN_DELIMITER_U16) --w;
	if(!w&&!is_abs){
		path[0]=u'.';
		w=1;
	}
	*len=w;
	path[*len]=u'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int sunPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_SUN_DELIMITER_U32;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_SUN_DELIMITER_U32;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_SUN_DELIMITER_U32) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_SUN_DELIMITER_U32){
			if(w>0&&path[w-1]!=SHINSEI_PATH_SUN_DELIMITER_U32){
				path[w++]=SHINSEI_PATH_SUN_DELIMITER_U32;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_SUN_DELIMITER_U32);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_SUN_DELIMITER_U32){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==U'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==U'.'&&path[seg_start+1]==U'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==U'.'&&path[rewind-2]==U'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_SUN_DELIMITER_U32);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_SUN_DELIMITER_U32){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_SUN_DELIMITER_U32)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_SUN_DELIMITER_U32) --w;
	if(!w&&!is_abs){
		path[0]=U'.';
		w=1;
	}
	*len=w;
	path[*len]=U'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int sunPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return sunPathNormalizeNoTraversalU32((char32_t*)path,len);
	#else
		return sunPathNormalizeNoTraversalU16((char16_t*)path,len);
	#endif
}

_SHINSEI_OS_INLINE static int sunPathNormalizeNoTraversalCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char dot=(char)(ebcdic*0x4B+!ebcdic*'.');
	register const char delim=(char)(ebcdic*SHINSEI_PATH_SUN_DELIMITER_EBCDIC+!ebcdic*SHINSEI_PATH_SUN_DELIMITER_ASCII);
	register const char null_char='\0';
	
	register const bool is_abs=path[0]==delim;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=delim;
		++r;
		while(r<cnt&&path[r]==delim) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==delim){
			if(w>0&&path[w-1]!=delim){
				path[w++]=delim;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==delim);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=delim){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==dot){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==dot&&path[seg_start+1]==dot){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==dot&&path[rewind-2]==dot&&(rewind==2||path[rewind-3]==delim);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=delim){
						--rewind;
					}
					w=(path[rewind]==delim)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==delim) --w;
	if(!w&&!is_abs){
		path[0]=dot;
		w=1;
	}
	*len=w;
	path[*len]=null_char;
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

int shinsei_sunPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return sunPathNormalizeNoTraversalW(path,len);
}
int shinsei_sunPathNormalizeNoTraversalCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return sunPathNormalizeNoTraversalCP(code_page,path,len);
}
int shinsei_sunPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return sunPathNormalizeNoTraversalU8(path,len);
}
int shinsei_sunPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return sunPathNormalizeNoTraversalU16(path,len);
}
int shinsei_sunPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return sunPathNormalizeNoTraversalU32(path,len);
}

_SHINSEI_OS_INLINE static int freeBSDPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_FREEBSD_DELIMITER_U8;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_FREEBSD_DELIMITER_U8;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U8) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U8){
			if(w>0&&path[w-1]!=SHINSEI_PATH_FREEBSD_DELIMITER_U8){
				path[w++]=SHINSEI_PATH_FREEBSD_DELIMITER_U8;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U8);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_FREEBSD_DELIMITER_U8){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u8'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u8'.'&&path[seg_start+1]==u8'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u8'.'&&path[rewind-2]==u8'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_FREEBSD_DELIMITER_U8);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_FREEBSD_DELIMITER_U8){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_FREEBSD_DELIMITER_U8)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_FREEBSD_DELIMITER_U8) --w;
	if(!w&&!is_abs){
		path[0]=u8'.';
		w=1;
	}
	*len=w;
	path[*len]=u8'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int freeBSDPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_FREEBSD_DELIMITER_U16;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_FREEBSD_DELIMITER_U16;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U16) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U16){
			if(w>0&&path[w-1]!=SHINSEI_PATH_FREEBSD_DELIMITER_U16){
				path[w++]=SHINSEI_PATH_FREEBSD_DELIMITER_U16;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U16);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_FREEBSD_DELIMITER_U16){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u'.'&&path[seg_start+1]==u'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u'.'&&path[rewind-2]==u'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_FREEBSD_DELIMITER_U16);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_FREEBSD_DELIMITER_U16){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_FREEBSD_DELIMITER_U16)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_FREEBSD_DELIMITER_U16) --w;
	if(!w&&!is_abs){
		path[0]=u'.';
		w=1;
	}
	*len=w;
	path[*len]=u'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int freeBSDPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_FREEBSD_DELIMITER_U32;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_FREEBSD_DELIMITER_U32;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U32) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U32){
			if(w>0&&path[w-1]!=SHINSEI_PATH_FREEBSD_DELIMITER_U32){
				path[w++]=SHINSEI_PATH_FREEBSD_DELIMITER_U32;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_FREEBSD_DELIMITER_U32);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_FREEBSD_DELIMITER_U32){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==U'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==U'.'&&path[seg_start+1]==U'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==U'.'&&path[rewind-2]==U'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_FREEBSD_DELIMITER_U32);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_FREEBSD_DELIMITER_U32){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_FREEBSD_DELIMITER_U32)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_FREEBSD_DELIMITER_U32) --w;
	if(!w&&!is_abs){
		path[0]=U'.';
		w=1;
	}
	*len=w;
	path[*len]=U'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int freeBSDPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return freeBSDPathNormalizeNoTraversalU32((char32_t*)path,len);
	#else
		return freeBSDPathNormalizeNoTraversalU16((char16_t*)path,len);
	#endif
}

_SHINSEI_OS_INLINE static int freeBSDPathNormalizeNoTraversalCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char dot=(char)(ebcdic*0x4B+!ebcdic*'.');
	register const char delim=(char)(ebcdic*SHINSEI_PATH_FREEBSD_DELIMITER_EBCDIC+!ebcdic*SHINSEI_PATH_FREEBSD_DELIMITER_ASCII);
	register const char null_char='\0';
	
	register const bool is_abs=path[0]==delim;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=delim;
		++r;
		while(r<cnt&&path[r]==delim) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==delim){
			if(w>0&&path[w-1]!=delim){
				path[w++]=delim;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==delim);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=delim){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==dot){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==dot&&path[seg_start+1]==dot){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==dot&&path[rewind-2]==dot&&(rewind==2||path[rewind-3]==delim);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=delim){
						--rewind;
					}
					w=(path[rewind]==delim)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==delim) --w;
	if(!w&&!is_abs){
		path[0]=dot;
		w=1;
	}
	*len=w;
	path[*len]=null_char;
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

int shinsei_freeBSDPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return freeBSDPathNormalizeNoTraversalW(path,len);
}
int shinsei_freeBSDPathNormalizeNoTraversalCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return freeBSDPathNormalizeNoTraversalCP(code_page,path,len);
}
int shinsei_freeBSDPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return freeBSDPathNormalizeNoTraversalU8(path,len);
}
int shinsei_freeBSDPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return freeBSDPathNormalizeNoTraversalU16(path,len);
}
int shinsei_freeBSDPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return freeBSDPathNormalizeNoTraversalU32(path,len);
}

_SHINSEI_OS_INLINE static int cygwinPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_CYGWIN_DELIMITER_U8;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_CYGWIN_DELIMITER_U8;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U8) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U8){
			if(w>0&&path[w-1]!=SHINSEI_PATH_CYGWIN_DELIMITER_U8){
				path[w++]=SHINSEI_PATH_CYGWIN_DELIMITER_U8;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U8);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_CYGWIN_DELIMITER_U8){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u8'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u8'.'&&path[seg_start+1]==u8'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u8'.'&&path[rewind-2]==u8'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_CYGWIN_DELIMITER_U8);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_CYGWIN_DELIMITER_U8){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_CYGWIN_DELIMITER_U8)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_CYGWIN_DELIMITER_U8) --w;
	if(!w&&!is_abs){
		path[0]=u8'.';
		w=1;
	}
	*len=w;
	path[*len]=u8'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int cygwinPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_CYGWIN_DELIMITER_U16;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_CYGWIN_DELIMITER_U16;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U16) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U16){
			if(w>0&&path[w-1]!=SHINSEI_PATH_CYGWIN_DELIMITER_U16){
				path[w++]=SHINSEI_PATH_CYGWIN_DELIMITER_U16;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U16);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_CYGWIN_DELIMITER_U16){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u'.'&&path[seg_start+1]==u'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u'.'&&path[rewind-2]==u'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_CYGWIN_DELIMITER_U16);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_CYGWIN_DELIMITER_U16){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_CYGWIN_DELIMITER_U16)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_CYGWIN_DELIMITER_U16) --w;
	if(!w&&!is_abs){
		path[0]=u'.';
		w=1;
	}
	*len=w;
	path[*len]=u'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int cygwinPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_CYGWIN_DELIMITER_U32;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_CYGWIN_DELIMITER_U32;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U32) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U32){
			if(w>0&&path[w-1]!=SHINSEI_PATH_CYGWIN_DELIMITER_U32){
				path[w++]=SHINSEI_PATH_CYGWIN_DELIMITER_U32;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_CYGWIN_DELIMITER_U32);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_CYGWIN_DELIMITER_U32){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==U'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==U'.'&&path[seg_start+1]==U'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==U'.'&&path[rewind-2]==U'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_CYGWIN_DELIMITER_U32);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_CYGWIN_DELIMITER_U32){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_CYGWIN_DELIMITER_U32)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_CYGWIN_DELIMITER_U32) --w;
	if(!w&&!is_abs){
		path[0]=U'.';
		w=1;
	}
	*len=w;
	path[*len]=U'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int cygwinPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		return cygwinPathNormalizeNoTraversalU32((char32_t*)path,len);
	#else
		return cygwinPathNormalizeNoTraversalU16((char16_t*)path,len);
	#endif
}

_SHINSEI_OS_INLINE static int cygwinPathNormalizeNoTraversalCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char dot=(char)(ebcdic*0x4B+!ebcdic*'.');
	register const char delim=(char)(ebcdic*SHINSEI_PATH_CYGWIN_DELIMITER_EBCDIC+!ebcdic*SHINSEI_PATH_CYGWIN_DELIMITER_ASCII);
	register const char null_char='\0';
	
	register const bool is_abs=path[0]==delim;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=delim;
		++r;
		while(r<cnt&&path[r]==delim) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==delim){
			if(w>0&&path[w-1]!=delim){
				path[w++]=delim;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==delim);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=delim){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==dot){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==dot&&path[seg_start+1]==dot){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==dot&&path[rewind-2]==dot&&(rewind==2||path[rewind-3]==delim);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=delim){
						--rewind;
					}
					w=(path[rewind]==delim)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==delim) --w;
	if(!w&&!is_abs){
		path[0]=dot;
		w=1;
	}
	*len=w;
	path[*len]=null_char;
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

int shinsei_cygwinPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return cygwinPathNormalizeNoTraversalW(path,len);
}
int shinsei_cygwinPathNormalizeNoTraversalCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return cygwinPathNormalizeNoTraversalCP(code_page,path,len);
}
int shinsei_cygwinPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return cygwinPathNormalizeNoTraversalU8(path,len);
}
int shinsei_cygwinPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return cygwinPathNormalizeNoTraversalU16(path,len);
}
int shinsei_cygwinPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return cygwinPathNormalizeNoTraversalU32(path,len);
}

_SHINSEI_OS_INLINE static int uRLPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_URL_DELIMITER_U8;
	if(*len==1){
		return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
	}
	register const bool end_with_slash=path[*len-1]==SHINSEI_PATH_URL_DELIMITER_U8;
	register const size_t cnt=*len-(size_t)end_with_slash;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_URL_DELIMITER_U8;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_URL_DELIMITER_U8) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_URL_DELIMITER_U8){
			if(w>0&&path[w-1]!=SHINSEI_PATH_URL_DELIMITER_U8){
				path[w++]=SHINSEI_PATH_URL_DELIMITER_U8;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_URL_DELIMITER_U8);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_URL_DELIMITER_U8){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u8'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u8'.'&&path[seg_start+1]==u8'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u8'.'&&path[rewind-2]==u8'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_URL_DELIMITER_U8);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_URL_DELIMITER_U8){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_URL_DELIMITER_U8)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_URL_DELIMITER_U8) --w;
	if(!w&&!is_abs){
		path[0]=u8'.';
		w=1;
	}
	if(end_with_slash&&!(is_abs&&w==1)){
		path[w++]=SHINSEI_PATH_URL_DELIMITER_U8;
	}
	*len=w;
	path[*len]=u8'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}
_SHINSEI_OS_INLINE static int uRLPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_URL_DELIMITER_U16;
	if(*len==1){
		return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
	}
	register const bool end_with_slash=path[*len-1]==SHINSEI_PATH_URL_DELIMITER_U16;
	register const size_t cnt=*len-(size_t)end_with_slash;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_URL_DELIMITER_U16;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_URL_DELIMITER_U16) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_URL_DELIMITER_U16){
			if(w>0&&path[w-1]!=SHINSEI_PATH_URL_DELIMITER_U16){
				path[w++]=SHINSEI_PATH_URL_DELIMITER_U16;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_URL_DELIMITER_U16);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_URL_DELIMITER_U16){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==u'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==u'.'&&path[seg_start+1]==u'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==u'.'&&path[rewind-2]==u'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_URL_DELIMITER_U16);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_URL_DELIMITER_U16){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_URL_DELIMITER_U16)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_URL_DELIMITER_U16) --w;
	if(!w&&!is_abs){
		path[0]=u'.';
		w=1;
	}
	if(end_with_slash&&!(is_abs&&w==1)){
		path[w++]=SHINSEI_PATH_URL_DELIMITER_U16;
	}
	*len=w;
	path[*len]=u'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

int shinsei_uRLPathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	#ifdef _SHINSEI_WCHAR_U32
		return shinsei_uRLPathNormalizeNoTraversalU32((char32_t*)path,len);
	#else
		return uRLPathNormalizeNoTraversalU16((char16_t*)path,len);
	#endif
}
int shinsei_uRLPathNormalizeNoTraversalCP(const uint_fast32_t code_page,char*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char dot=(char)(ebcdic*0x4B+!ebcdic*'.');
	register const char delim=(char)(ebcdic*SHINSEI_PATH_URL_DELIMITER_EBCDIC+!ebcdic*SHINSEI_PATH_URL_DELIMITER_ASCII);
	register const char null_char='\0';
	
	register const bool is_abs=path[0]==delim;
	if(*len==1){
		return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
	}
	register const bool end_with_slash=path[*len-1]==delim;
	register const size_t cnt=*len-(size_t)end_with_slash;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=delim;
		++r;
		while(r<cnt&&path[r]==delim) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==delim){
			if(w>0&&path[w-1]!=delim){
				path[w++]=delim;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==delim);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=delim){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==dot){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==dot&&path[seg_start+1]==dot){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==dot&&path[rewind-2]==dot&&(rewind==2||path[rewind-3]==delim);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=delim){
						--rewind;
					}
					w=(path[rewind]==delim)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==delim) --w;
	if(!w&&!is_abs){
		path[0]=dot;
		w=1;
	}
	if(end_with_slash&&!(is_abs&&w==1)){
		path[w++]=delim;
	}
	*len=w;
	path[*len]=null_char;
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}
int shinsei_uRLPathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return uRLPathNormalizeNoTraversalU8(path,len);
}
int shinsei_uRLPathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return uRLPathNormalizeNoTraversalU16(path,len);
}
int shinsei_uRLPathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len)_SHINSEI_OS_NOEXCEPT{
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_URL_DELIMITER_U32;
	if(*len==1){
		return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
	}
	register const bool end_with_slash=path[*len-1]==SHINSEI_PATH_URL_DELIMITER_U32;
	register const size_t cnt=*len-(size_t)end_with_slash;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_URL_DELIMITER_U32;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_URL_DELIMITER_U32) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_URL_DELIMITER_U32){
			if(w>0&&path[w-1]!=SHINSEI_PATH_URL_DELIMITER_U32){
				path[w++]=SHINSEI_PATH_URL_DELIMITER_U32;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_URL_DELIMITER_U32);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_URL_DELIMITER_U32){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==U'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==U'.'&&path[seg_start+1]==U'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==U'.'&&path[rewind-2]==U'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_URL_DELIMITER_U32);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_URL_DELIMITER_U32){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_URL_DELIMITER_U32)*(rewind+1);
				}
			}
			else if(!is_abs){
				// Relative path. Keep "..".
				return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
			}
			else{
				// Can't get parent any more
				w=seg_start;
			}
		}
		else{
			// Push segment
			pos[back]=seg_start;
			back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
			if(back==front){
				front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
			}
		}
	}
	if(w>1&&path[w-1]==SHINSEI_PATH_URL_DELIMITER_U32) --w;
	if(!w&&!is_abs){
		path[0]=U'.';
		w=1;
	}
	if(end_with_slash&&!(is_abs&&w==1)){
		path[w++]=SHINSEI_PATH_URL_DELIMITER_U32;
	}
	*len=w;
	path[*len]=U'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static size_t windowsPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=L'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const wchar_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const wchar_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(wchar_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(wchar_t));
			last+=part_len[i];
		}
		des_buf[res]=L'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_WINDOWS_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(wchar_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const wchar_t*const cur_part=va_arg(args_copy,const wchar_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(wchar_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=L'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const wchar_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(wchar_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const wchar_t*const cur_part=va_arg(args_copy,const wchar_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(wchar_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=L'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t windowsPathJoinCPV(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf='\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	
	register const char delimiter=isEBCDICCodePage(code_page)?SHINSEI_PATH_WINDOWS_DELIMITER_EBCDIC:SHINSEI_PATH_WINDOWS_DELIMITER_ASCII;
	register size_t res=first_part_len;
	
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=delimiter;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char));
			last+=part_len[i];
		}
		des_buf[res]='\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_WINDOWS_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char*const cur_part=va_arg(args_copy,const char*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=delimiter;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]='\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char*const cur_part=va_arg(args_copy,const char*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=delimiter;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]='\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t windowsPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u8'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char8_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char8_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char8_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char8_t));
			last+=part_len[i];
		}
		des_buf[res]=u8'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_WINDOWS_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char8_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char8_t*const cur_part=va_arg(args_copy,const char8_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char8_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=u8'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char8_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char8_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char8_t*const cur_part=va_arg(args_copy,const char8_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_U8;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char8_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=u8'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t windowsPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char16_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char16_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char16_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char16_t));
			last+=part_len[i];
		}
		des_buf[res]=u'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_WINDOWS_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char16_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char16_t*const cur_part=va_arg(args_copy,const char16_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char16_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=u'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char16_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char16_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char16_t*const cur_part=va_arg(args_copy,const char16_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_U16;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char16_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=u'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t windowsPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=U'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char32_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char32_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char32_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char32_t));
			last+=part_len[i];
		}
		des_buf[res]=U'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_WINDOWS_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char32_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char32_t*const cur_part=va_arg(args_copy,const char32_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char32_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=U'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char32_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char32_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char32_t*const cur_part=va_arg(args_copy,const char32_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_U32;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char32_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=U'\0';
	return res;
}

size_t shinsei_windowsPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return windowsPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_windowsPathJoinW(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=windowsPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_windowsPathJoinCPV(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return windowsPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_windowsPathJoinCP(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=windowsPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_windowsPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return windowsPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_windowsPathJoinU8(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=windowsPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_windowsPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return windowsPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_windowsPathJoinU16(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=windowsPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_windowsPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return windowsPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_windowsPathJoinU32(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=windowsPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

_SHINSEI_OS_INLINE static size_t unixPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=L'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const wchar_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const wchar_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(wchar_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_UNIX_DELIMITER_W;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(wchar_t));
			last+=part_len[i];
		}
		des_buf[res]=L'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_UNIX_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(wchar_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const wchar_t*const cur_part=va_arg(args_copy,const wchar_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_UNIX_DELIMITER_W;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(wchar_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=L'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const wchar_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(wchar_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const wchar_t*const cur_part=va_arg(args_copy,const wchar_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_UNIX_DELIMITER_W;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(wchar_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=L'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t unixPathJoinCPV(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf='\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	
	register const char delimiter=isEBCDICCodePage(code_page)?SHINSEI_PATH_UNIX_DELIMITER_EBCDIC:SHINSEI_PATH_UNIX_DELIMITER_ASCII;
	register size_t res=first_part_len;
	
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=delimiter;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char));
			last+=part_len[i];
		}
		des_buf[res]='\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_UNIX_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char*const cur_part=va_arg(args_copy,const char*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=delimiter;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]='\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char*const cur_part=va_arg(args_copy,const char*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=delimiter;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]='\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t unixPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u8'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char8_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char8_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char8_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_UNIX_DELIMITER_U8;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char8_t));
			last+=part_len[i];
		}
		des_buf[res]=u8'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_UNIX_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char8_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char8_t*const cur_part=va_arg(args_copy,const char8_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_UNIX_DELIMITER_U8;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char8_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=u8'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char8_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char8_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char8_t*const cur_part=va_arg(args_copy,const char8_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_UNIX_DELIMITER_U8;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char8_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=u8'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t unixPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char16_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char16_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char16_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_UNIX_DELIMITER_U16;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char16_t));
			last+=part_len[i];
		}
		des_buf[res]=u'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_UNIX_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char16_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char16_t*const cur_part=va_arg(args_copy,const char16_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_UNIX_DELIMITER_U16;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char16_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=u'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char16_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char16_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char16_t*const cur_part=va_arg(args_copy,const char16_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_UNIX_DELIMITER_U16;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char16_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=u'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t unixPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=U'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char32_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char32_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char32_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_UNIX_DELIMITER_U32;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char32_t));
			last+=part_len[i];
		}
		des_buf[res]=U'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_UNIX_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char32_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char32_t*const cur_part=va_arg(args_copy,const char32_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_UNIX_DELIMITER_U32;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char32_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=U'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char32_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char32_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char32_t*const cur_part=va_arg(args_copy,const char32_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_UNIX_DELIMITER_U32;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char32_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=U'\0';
	return res;
}
size_t shinsei_unixPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_unixPathJoinW(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_unixPathJoinCPV(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return unixPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_unixPathJoinCP(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=unixPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_unixPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return unixPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_unixPathJoinU8(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=unixPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_unixPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return unixPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_unixPathJoinU16(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=unixPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_unixPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return unixPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_unixPathJoinU32(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=unixPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

_SHINSEI_OS_INLINE static size_t linuxPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=L'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const wchar_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const wchar_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(wchar_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_LINUX_DELIMITER_W;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(wchar_t));
			last+=part_len[i];
		}
		des_buf[res]=L'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_LINUX_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(wchar_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const wchar_t*const cur_part=va_arg(args_copy,const wchar_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_LINUX_DELIMITER_W;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(wchar_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=L'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const wchar_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(wchar_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const wchar_t*const cur_part=va_arg(args_copy,const wchar_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_LINUX_DELIMITER_W;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(wchar_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=L'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t linuxPathJoinCPV(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf='\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	
	register const char delimiter=isEBCDICCodePage(code_page)?SHINSEI_PATH_LINUX_DELIMITER_EBCDIC:SHINSEI_PATH_LINUX_DELIMITER_ASCII;
	register size_t res=first_part_len;
	
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=delimiter;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char));
			last+=part_len[i];
		}
		des_buf[res]='\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_LINUX_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char*const cur_part=va_arg(args_copy,const char*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=delimiter;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]='\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char*const cur_part=va_arg(args_copy,const char*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=delimiter;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]='\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t linuxPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u8'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char8_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char8_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char8_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_LINUX_DELIMITER_U8;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char8_t));
			last+=part_len[i];
		}
		des_buf[res]=u8'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_LINUX_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char8_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char8_t*const cur_part=va_arg(args_copy,const char8_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_LINUX_DELIMITER_U8;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char8_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=u8'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char8_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char8_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char8_t*const cur_part=va_arg(args_copy,const char8_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_LINUX_DELIMITER_U8;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char8_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=u8'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t linuxPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char16_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char16_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char16_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_LINUX_DELIMITER_U16;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char16_t));
			last+=part_len[i];
		}
		des_buf[res]=u'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_LINUX_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char16_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char16_t*const cur_part=va_arg(args_copy,const char16_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_LINUX_DELIMITER_U16;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char16_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=u'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char16_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char16_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char16_t*const cur_part=va_arg(args_copy,const char16_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_LINUX_DELIMITER_U16;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char16_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=u'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t linuxPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=U'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char32_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char32_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char32_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_LINUX_DELIMITER_U32;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char32_t));
			last+=part_len[i];
		}
		des_buf[res]=U'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_LINUX_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char32_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char32_t*const cur_part=va_arg(args_copy,const char32_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_LINUX_DELIMITER_U32;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char32_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=U'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char32_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char32_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char32_t*const cur_part=va_arg(args_copy,const char32_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_LINUX_DELIMITER_U32;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char32_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=U'\0';
	return res;
}
size_t shinsei_linuxPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return linuxPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_linuxPathJoinW(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=linuxPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_linuxPathJoinCPV(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return linuxPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_linuxPathJoinCP(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=linuxPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_linuxPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return linuxPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_linuxPathJoinU8(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=linuxPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_linuxPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return linuxPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_linuxPathJoinU16(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=linuxPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_linuxPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return linuxPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_linuxPathJoinU32(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=linuxPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

_SHINSEI_OS_INLINE static size_t applePathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=L'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const wchar_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const wchar_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(wchar_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_APPLE_DELIMITER_W;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(wchar_t));
			last+=part_len[i];
		}
		des_buf[res]=L'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_APPLE_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(wchar_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const wchar_t*const cur_part=va_arg(args_copy,const wchar_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_APPLE_DELIMITER_W;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(wchar_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=L'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const wchar_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(wchar_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const wchar_t*const cur_part=va_arg(args_copy,const wchar_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_APPLE_DELIMITER_W;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(wchar_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=L'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t applePathJoinCPV(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf='\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	
	register const char delimiter=isEBCDICCodePage(code_page)?SHINSEI_PATH_APPLE_DELIMITER_EBCDIC:SHINSEI_PATH_APPLE_DELIMITER_ASCII;
	register size_t res=first_part_len;
	
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=delimiter;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char));
			last+=part_len[i];
		}
		des_buf[res]='\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_APPLE_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char*const cur_part=va_arg(args_copy,const char*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=delimiter;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]='\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char*const cur_part=va_arg(args_copy,const char*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=delimiter;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]='\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t applePathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u8'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char8_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char8_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char8_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_APPLE_DELIMITER_U8;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char8_t));
			last+=part_len[i];
		}
		des_buf[res]=u8'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_APPLE_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char8_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char8_t*const cur_part=va_arg(args_copy,const char8_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_APPLE_DELIMITER_U8;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char8_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=u8'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char8_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char8_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char8_t*const cur_part=va_arg(args_copy,const char8_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_APPLE_DELIMITER_U8;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char8_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=u8'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t applePathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char16_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char16_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char16_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_APPLE_DELIMITER_U16;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char16_t));
			last+=part_len[i];
		}
		des_buf[res]=u'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_APPLE_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char16_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char16_t*const cur_part=va_arg(args_copy,const char16_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_APPLE_DELIMITER_U16;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char16_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=u'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char16_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char16_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char16_t*const cur_part=va_arg(args_copy,const char16_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_APPLE_DELIMITER_U16;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char16_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=u'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t applePathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=U'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char32_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char32_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char32_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_APPLE_DELIMITER_U32;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char32_t));
			last+=part_len[i];
		}
		des_buf[res]=U'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_APPLE_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char32_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char32_t*const cur_part=va_arg(args_copy,const char32_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_APPLE_DELIMITER_U32;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char32_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=U'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char32_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char32_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char32_t*const cur_part=va_arg(args_copy,const char32_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_APPLE_DELIMITER_U32;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char32_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=U'\0';
	return res;
}
size_t shinsei_applePathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return applePathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_applePathJoinW(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=applePathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_applePathJoinCPV(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return applePathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_applePathJoinCP(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=applePathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_applePathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return applePathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_applePathJoinU8(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=applePathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_applePathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return applePathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_applePathJoinU16(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=applePathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_applePathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return applePathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_applePathJoinU32(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=applePathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

_SHINSEI_OS_INLINE static size_t sunPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=L'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const wchar_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const wchar_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(wchar_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_SUN_DELIMITER_W;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(wchar_t));
			last+=part_len[i];
		}
		des_buf[res]=L'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_SUN_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(wchar_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const wchar_t*const cur_part=va_arg(args_copy,const wchar_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_SUN_DELIMITER_W;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(wchar_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=L'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const wchar_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(wchar_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const wchar_t*const cur_part=va_arg(args_copy,const wchar_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_SUN_DELIMITER_W;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(wchar_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=L'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t sunPathJoinCPV(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf='\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	
	register const char delimiter=isEBCDICCodePage(code_page)?SHINSEI_PATH_SUN_DELIMITER_EBCDIC:SHINSEI_PATH_SUN_DELIMITER_ASCII;
	register size_t res=first_part_len;
	
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=delimiter;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char));
			last+=part_len[i];
		}
		des_buf[res]='\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_SUN_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char*const cur_part=va_arg(args_copy,const char*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=delimiter;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]='\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char*const cur_part=va_arg(args_copy,const char*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=delimiter;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]='\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t sunPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u8'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char8_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char8_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char8_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_SUN_DELIMITER_U8;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char8_t));
			last+=part_len[i];
		}
		des_buf[res]=u8'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_SUN_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char8_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char8_t*const cur_part=va_arg(args_copy,const char8_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_SUN_DELIMITER_U8;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char8_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=u8'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char8_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char8_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char8_t*const cur_part=va_arg(args_copy,const char8_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_SUN_DELIMITER_U8;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char8_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=u8'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t sunPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char16_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char16_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char16_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_SUN_DELIMITER_U16;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char16_t));
			last+=part_len[i];
		}
		des_buf[res]=u'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_SUN_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char16_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char16_t*const cur_part=va_arg(args_copy,const char16_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_SUN_DELIMITER_U16;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char16_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=u'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char16_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char16_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char16_t*const cur_part=va_arg(args_copy,const char16_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_SUN_DELIMITER_U16;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char16_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=u'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t sunPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=U'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char32_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char32_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char32_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_SUN_DELIMITER_U32;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char32_t));
			last+=part_len[i];
		}
		des_buf[res]=U'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_SUN_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char32_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char32_t*const cur_part=va_arg(args_copy,const char32_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_SUN_DELIMITER_U32;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char32_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=U'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char32_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char32_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char32_t*const cur_part=va_arg(args_copy,const char32_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_SUN_DELIMITER_U32;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char32_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=U'\0';
	return res;
}
size_t shinsei_sunPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return sunPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_sunPathJoinW(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=sunPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_sunPathJoinCPV(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return sunPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_sunPathJoinCP(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=sunPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_sunPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return sunPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_sunPathJoinU8(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=sunPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_sunPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return sunPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_sunPathJoinU16(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=sunPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_sunPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return sunPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_sunPathJoinU32(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=sunPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

_SHINSEI_OS_INLINE static size_t freeBSDPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=L'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const wchar_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const wchar_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(wchar_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_FREEBSD_DELIMITER_W;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(wchar_t));
			last+=part_len[i];
		}
		des_buf[res]=L'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_FREEBSD_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(wchar_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const wchar_t*const cur_part=va_arg(args_copy,const wchar_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_FREEBSD_DELIMITER_W;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(wchar_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=L'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const wchar_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(wchar_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const wchar_t*const cur_part=va_arg(args_copy,const wchar_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_FREEBSD_DELIMITER_W;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(wchar_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=L'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t freeBSDPathJoinCPV(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf='\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	
	register const char delimiter=isEBCDICCodePage(code_page)?SHINSEI_PATH_FREEBSD_DELIMITER_EBCDIC:SHINSEI_PATH_FREEBSD_DELIMITER_ASCII;
	register size_t res=first_part_len;
	
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=delimiter;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char));
			last+=part_len[i];
		}
		des_buf[res]='\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_FREEBSD_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char*const cur_part=va_arg(args_copy,const char*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=delimiter;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]='\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char*const cur_part=va_arg(args_copy,const char*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=delimiter;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]='\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t freeBSDPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u8'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char8_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char8_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char8_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_FREEBSD_DELIMITER_U8;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char8_t));
			last+=part_len[i];
		}
		des_buf[res]=u8'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_FREEBSD_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char8_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char8_t*const cur_part=va_arg(args_copy,const char8_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_FREEBSD_DELIMITER_U8;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char8_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=u8'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char8_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char8_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char8_t*const cur_part=va_arg(args_copy,const char8_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_FREEBSD_DELIMITER_U8;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char8_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=u8'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t freeBSDPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char16_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char16_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char16_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_FREEBSD_DELIMITER_U16;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char16_t));
			last+=part_len[i];
		}
		des_buf[res]=u'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_FREEBSD_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char16_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char16_t*const cur_part=va_arg(args_copy,const char16_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_FREEBSD_DELIMITER_U16;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char16_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=u'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char16_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char16_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char16_t*const cur_part=va_arg(args_copy,const char16_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_FREEBSD_DELIMITER_U16;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char16_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=u'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t freeBSDPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=U'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char32_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char32_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char32_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_FREEBSD_DELIMITER_U32;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char32_t));
			last+=part_len[i];
		}
		des_buf[res]=U'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_FREEBSD_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char32_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char32_t*const cur_part=va_arg(args_copy,const char32_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_FREEBSD_DELIMITER_U32;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char32_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=U'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char32_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char32_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char32_t*const cur_part=va_arg(args_copy,const char32_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_FREEBSD_DELIMITER_U32;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char32_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=U'\0';
	return res;
}
size_t shinsei_freeBSDPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return freeBSDPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_freeBSDPathJoinW(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=freeBSDPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_freeBSDPathJoinCPV(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return freeBSDPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_freeBSDPathJoinCP(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=freeBSDPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_freeBSDPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return freeBSDPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_freeBSDPathJoinU8(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=freeBSDPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_freeBSDPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return freeBSDPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_freeBSDPathJoinU16(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=freeBSDPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_freeBSDPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return freeBSDPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_freeBSDPathJoinU32(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=freeBSDPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

_SHINSEI_OS_INLINE static size_t cygwinPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=L'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const wchar_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const wchar_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(wchar_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_CYGWIN_DELIMITER_W;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(wchar_t));
			last+=part_len[i];
		}
		des_buf[res]=L'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_CYGWIN_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(wchar_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const wchar_t*const cur_part=va_arg(args_copy,const wchar_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_CYGWIN_DELIMITER_W;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(wchar_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=L'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const wchar_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(wchar_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const wchar_t*const cur_part=va_arg(args_copy,const wchar_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_CYGWIN_DELIMITER_W;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(wchar_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=L'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t cygwinPathJoinCPV(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf='\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	
	register const char delimiter=isEBCDICCodePage(code_page)?SHINSEI_PATH_CYGWIN_DELIMITER_EBCDIC:SHINSEI_PATH_CYGWIN_DELIMITER_ASCII;
	register size_t res=first_part_len;
	
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=delimiter;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char));
			last+=part_len[i];
		}
		des_buf[res]='\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_CYGWIN_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char*const cur_part=va_arg(args_copy,const char*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=delimiter;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]='\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char*const cur_part=va_arg(args_copy,const char*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=delimiter;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]='\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t cygwinPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u8'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char8_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char8_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char8_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_CYGWIN_DELIMITER_U8;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char8_t));
			last+=part_len[i];
		}
		des_buf[res]=u8'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_CYGWIN_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char8_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char8_t*const cur_part=va_arg(args_copy,const char8_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_CYGWIN_DELIMITER_U8;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char8_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=u8'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char8_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char8_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char8_t*const cur_part=va_arg(args_copy,const char8_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_CYGWIN_DELIMITER_U8;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char8_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=u8'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t cygwinPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char16_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char16_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char16_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_CYGWIN_DELIMITER_U16;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char16_t));
			last+=part_len[i];
		}
		des_buf[res]=u'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_CYGWIN_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char16_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char16_t*const cur_part=va_arg(args_copy,const char16_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_CYGWIN_DELIMITER_U16;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char16_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=u'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char16_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char16_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char16_t*const cur_part=va_arg(args_copy,const char16_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_CYGWIN_DELIMITER_U16;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char16_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=u'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t cygwinPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=U'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char32_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char32_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char32_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_CYGWIN_DELIMITER_U32;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char32_t));
			last+=part_len[i];
		}
		des_buf[res]=U'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_CYGWIN_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char32_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char32_t*const cur_part=va_arg(args_copy,const char32_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_CYGWIN_DELIMITER_U32;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char32_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=U'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char32_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char32_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char32_t*const cur_part=va_arg(args_copy,const char32_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_CYGWIN_DELIMITER_U32;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char32_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=U'\0';
	return res;
}
size_t shinsei_cygwinPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return cygwinPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_cygwinPathJoinW(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=cygwinPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_cygwinPathJoinCPV(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return cygwinPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_cygwinPathJoinCP(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=cygwinPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_cygwinPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return cygwinPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_cygwinPathJoinU8(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=cygwinPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_cygwinPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return cygwinPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_cygwinPathJoinU16(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=cygwinPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_cygwinPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return cygwinPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_cygwinPathJoinU32(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=cygwinPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

_SHINSEI_OS_INLINE static size_t uRLPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=L'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const wchar_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const wchar_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(wchar_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_URL_DELIMITER_W;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(wchar_t));
			last+=part_len[i];
		}
		des_buf[res]=L'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_UNIX_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(wchar_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const wchar_t*const cur_part=va_arg(args_copy,const wchar_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_URL_DELIMITER_W;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(wchar_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=L'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const wchar_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(wchar_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const wchar_t*const cur_part=va_arg(args_copy,const wchar_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_URL_DELIMITER_W;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(wchar_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=L'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t uRLPathJoinCPV(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf='\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	
	register const char delimiter=isEBCDICCodePage(code_page)?SHINSEI_PATH_URL_DELIMITER_EBCDIC:SHINSEI_PATH_URL_DELIMITER_ASCII;
	register size_t res=first_part_len;
	
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=delimiter;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char));
			last+=part_len[i];
		}
		des_buf[res]='\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_UNIX_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char*const cur_part=va_arg(args_copy,const char*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=delimiter;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]='\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char*const cur_part=va_arg(args_copy,const char*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=delimiter;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]='\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t uRLPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u8'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char8_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char8_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char8_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_URL_DELIMITER_U8;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char8_t));
			last+=part_len[i];
		}
		des_buf[res]=u8'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_UNIX_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char8_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char8_t*const cur_part=va_arg(args_copy,const char8_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_URL_DELIMITER_U8;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char8_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=u8'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char8_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char8_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char8_t*const cur_part=va_arg(args_copy,const char8_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_URL_DELIMITER_U8;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char8_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=u8'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t uRLPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char16_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char16_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char16_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_URL_DELIMITER_U16;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char16_t));
			last+=part_len[i];
		}
		des_buf[res]=u'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_UNIX_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char16_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char16_t*const cur_part=va_arg(args_copy,const char16_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_URL_DELIMITER_U16;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char16_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=u'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char16_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char16_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char16_t*const cur_part=va_arg(args_copy,const char16_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_URL_DELIMITER_U16;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char16_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=u'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t uRLPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=U'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des_buf==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		const char32_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args_copy,const char32_t*);
			part_len[i]=va_arg(args_copy,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args_copy);
		if(res>=des_buf_len) return res;
		register size_t last=first_part_len;
		if(des_buf!=first_part){
			__builtin_memcpy(des_buf,part[0],part_len[0]*sizeof(char32_t));
		}
		for(register int i=1;i<path_cnt;++i){
			des_buf[last++]=SHINSEI_PATH_URL_DELIMITER_U32;
			__builtin_memcpy(des_buf+last,part[i],part_len[i]*sizeof(char32_t));
			last+=part_len[i];
		}
		des_buf[res]=U'\0';
		return res;
	}
	if(des_buf_len>=SHINSEI_PATH_UNIX_MAX||des_buf_len<=SHINSEI_PATH_MINIMAL){
		if(des_buf!=first_part&&res<des_buf_len) __builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char32_t));
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args_copy;
		va_copy(args_copy,args);
		for(register int i=1;i<path_cnt;++i){
			register const char32_t*const cur_part=va_arg(args_copy,const char32_t*const);
			register const size_t cur_part_len=va_arg(args_copy,const size_t);
			res+=cur_part_len+1;
			if(res<des_buf_len){
				des_buf[last++]=SHINSEI_PATH_URL_DELIMITER_U32;
				__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char32_t));
			}
			last=res;
		}
		va_end(args_copy);
		if(res<des_buf_len) des_buf[res]=U'\0';
		return res;
	}
	va_list args_copy;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args_copy,const char32_t*const);
		res+=va_arg(args_copy,const size_t)+1;
	}
	va_end(args_copy);
	if(res>=des_buf_len) return res;
	if(des_buf!=first_part){
		__builtin_memcpy(des_buf,first_part,first_part_len*sizeof(char32_t));
	}
	register size_t last=first_part_len;
	va_copy(args_copy,args);
	for(register int i=1;i<path_cnt;++i){
		register const char32_t*const cur_part=va_arg(args_copy,const char32_t*const);
		register const size_t cur_part_len=va_arg(args_copy,const size_t);
		des_buf[last++]=SHINSEI_PATH_URL_DELIMITER_U32;
		__builtin_memcpy(des_buf+last,cur_part,cur_part_len*sizeof(char32_t));
		last+=cur_part_len;
	}
	va_end(args_copy);
	des_buf[res]=U'\0';
	return res;
}
size_t shinsei_uRLPathJoinWV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return uRLPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_uRLPathJoinW(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=uRLPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_uRLPathJoinCPV(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return uRLPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_uRLPathJoinCP(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=uRLPathJoinCPV(code_page,des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_uRLPathJoinU8V(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return uRLPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_uRLPathJoinU8(char8_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char8_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=uRLPathJoinU8V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_uRLPathJoinU16V(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return uRLPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_uRLPathJoinU16(char16_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char16_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=uRLPathJoinU16V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_uRLPathJoinU32V(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,va_list args)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return uRLPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_uRLPathJoinU32(char32_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char32_t*const restrict first_part,const size_t first_part_len,...)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=uRLPathJoinU32V(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// Copy from str/str.c
_SHINSEI_OS_INLINE static size_t splitStringToPartsW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const wchar_t delimiter)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!part_len,0)) return 0;
	if(__builtin_expect(!src_len,0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=L'\0';
		return 0;
	}
	register size_t expected_delims=(src_len-1)/part_len;
	if(expected_delims>max_part_cnt) expected_delims=max_part_cnt;
	register const size_t res=src_len+expected_delims;
	if(__builtin_expect(des_buf_len<=res,0)) return res;
	size_t now=0;
	size_t cnt=0;
	for(size_t i=0;i<src_len;++i){
		des_buf[now++]=src[i];
		if(cnt<max_part_cnt&&!((i+1)%part_len)){
			des_buf[now++]=delimiter;
			++cnt;
		}
	}
	if(des_buf[now-1]==delimiter) --now;
	des_buf[now]=L'\0';
	return res;
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static size_t splitStringToPartsCP(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char delimiter)_SHINSEI_OS_NOEXCEPT{
	(void)code_page;
	if(__builtin_expect(!part_len,0)) return 0;
	if(__builtin_expect(!src_len,0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf='\0';
		return 0;
	}
	register size_t expected_delims=(src_len-1)/part_len;
	if(expected_delims>max_part_cnt) expected_delims=max_part_cnt;
	register const size_t res=src_len+expected_delims;
	if(__builtin_expect(des_buf_len<=res,0)) return res;
	size_t now=0;
	size_t cnt=0;
	for(size_t i=0;i<src_len;++i){
		des_buf[now++]=src[i];
		if(cnt<max_part_cnt&&!((i+1)%part_len)){
			des_buf[now++]=delimiter;
			++cnt;
		}
	}
	if(des_buf[now-1]==delimiter) --now;
	des_buf[now]='\0';
	return res;
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static size_t splitStringToPartsU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char8_t delimiter)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!part_len,0)) return 0;
	if(__builtin_expect(!src_len,0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u8'\0';
		return 0;
	}
	register size_t expected_delims=(src_len-1)/part_len;
	if(expected_delims>max_part_cnt) expected_delims=max_part_cnt;
	register const size_t res=src_len+expected_delims;
	if(__builtin_expect(des_buf_len<=res,0)) return res;
	size_t now=0;
	size_t cnt=0;
	for(size_t i=0;i<src_len;++i){
		des_buf[now++]=src[i];
		if(cnt<max_part_cnt&&!((i+1)%part_len)){
			des_buf[now++]=delimiter;
			++cnt;
		}
	}
	if(des_buf[now-1]==delimiter) --now;
	des_buf[now]=u8'\0';
	return res;
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static size_t splitStringToPartsU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char16_t delimiter)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!part_len,0)) return 0;
	if(__builtin_expect(!src_len,0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=u'\0';
		return 0;
	}
	register size_t expected_delims=(src_len-1)/part_len;
	if(expected_delims>max_part_cnt) expected_delims=max_part_cnt;
	register const size_t res=src_len+expected_delims;
	if(__builtin_expect(des_buf_len<=res,0)) return res;
	size_t now=0;
	size_t cnt=0;
	for(size_t i=0;i<src_len;++i){
		des_buf[now++]=src[i];
		if(cnt<max_part_cnt&&!((i+1)%part_len)){
			des_buf[now++]=delimiter;
			++cnt;
		}
	}
	if(des_buf[now-1]==delimiter) --now;
	des_buf[now]=u'\0';
	return res;
}
// Copy from str/str.c
_SHINSEI_OS_INLINE static size_t splitStringToPartsU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char32_t delimiter)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!part_len,0)) return 0;
	if(__builtin_expect(!src_len,0)){
		if(__builtin_expect(des_buf_len>0,1)) *des_buf=U'\0';
		return 0;
	}
	register size_t expected_delims=(src_len-1)/part_len;
	if(expected_delims>max_part_cnt) expected_delims=max_part_cnt;
	register const size_t res=src_len+expected_delims;
	if(__builtin_expect(des_buf_len<=res,0)) return res;
	size_t now=0;
	size_t cnt=0;
	for(size_t i=0;i<src_len;++i){
		des_buf[now++]=src[i];
		if(cnt<max_part_cnt&&!((i+1)%part_len)){
			des_buf[now++]=delimiter;
			++cnt;
		}
	}
	if(des_buf[now-1]==delimiter) --now;
	des_buf[now]=U'\0';
	return res;
}

// Windows
size_t shinsei_splitStringToWindowsPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_WINDOWS_DELIMITER_W);
}
size_t shinsei_splitStringToWindowsPathCP(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	register const char delimiter=isEBCDICCodePage(code_page)?SHINSEI_PATH_WINDOWS_DELIMITER_EBCDIC:SHINSEI_PATH_WINDOWS_DELIMITER_ASCII;
	return splitStringToPartsCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,delimiter);
}
size_t shinsei_splitStringToWindowsPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_WINDOWS_DELIMITER_U8);
}
size_t shinsei_splitStringToWindowsPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_WINDOWS_DELIMITER_U16);
}
size_t shinsei_splitStringToWindowsPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_WINDOWS_DELIMITER_U32);
}

// Unix
size_t shinsei_splitStringToUnixPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_UNIX_DELIMITER_W);
}
size_t shinsei_splitStringToUnixPathCP(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	register const char delimiter=isEBCDICCodePage(code_page)?SHINSEI_PATH_UNIX_DELIMITER_EBCDIC:SHINSEI_PATH_UNIX_DELIMITER_ASCII;
	return splitStringToPartsCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,delimiter);
}
size_t shinsei_splitStringToUnixPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_UNIX_DELIMITER_U8);
}
size_t shinsei_splitStringToUnixPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_UNIX_DELIMITER_U16);
}
size_t shinsei_splitStringToUnixPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_UNIX_DELIMITER_U32);
}

// Linux
size_t shinsei_splitStringToLinuxPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_LINUX_DELIMITER_W);
}
size_t shinsei_splitStringToLinuxPathCP(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	register const char delimiter=isEBCDICCodePage(code_page)?SHINSEI_PATH_LINUX_DELIMITER_EBCDIC:SHINSEI_PATH_LINUX_DELIMITER_ASCII;
	return splitStringToPartsCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,delimiter);
}
size_t shinsei_splitStringToLinuxPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_LINUX_DELIMITER_U8);
}
size_t shinsei_splitStringToLinuxPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_LINUX_DELIMITER_U16);
}
size_t shinsei_splitStringToLinuxPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_LINUX_DELIMITER_U32);
}

// Apple
size_t shinsei_splitStringToApplePathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_APPLE_DELIMITER_W);
}
size_t shinsei_splitStringToApplePathCP(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	register const char delimiter=isEBCDICCodePage(code_page)?SHINSEI_PATH_APPLE_DELIMITER_EBCDIC:SHINSEI_PATH_APPLE_DELIMITER_ASCII;
	return splitStringToPartsCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,delimiter);
}
size_t shinsei_splitStringToApplePathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_APPLE_DELIMITER_U8);
}
size_t shinsei_splitStringToApplePathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_APPLE_DELIMITER_U16);
}
size_t shinsei_splitStringToApplePathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_APPLE_DELIMITER_U32);
}

// Sun
size_t shinsei_splitStringToSunPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_SUN_DELIMITER_W);
}
size_t shinsei_splitStringToSunPathCP(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	register const char delimiter=isEBCDICCodePage(code_page)?SHINSEI_PATH_SUN_DELIMITER_EBCDIC:SHINSEI_PATH_SUN_DELIMITER_ASCII;
	return splitStringToPartsCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,delimiter);
}
size_t shinsei_splitStringToSunPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_SUN_DELIMITER_U8);
}
size_t shinsei_splitStringToSunPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_SUN_DELIMITER_U16);
}
size_t shinsei_splitStringToSunPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_SUN_DELIMITER_U32);
}

// FreeBSD
size_t shinsei_splitStringToFreeBSDPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_FREEBSD_DELIMITER_W);
}
size_t shinsei_splitStringToFreeBSDPathCP(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	register const char delimiter=isEBCDICCodePage(code_page)?SHINSEI_PATH_FREEBSD_DELIMITER_EBCDIC:SHINSEI_PATH_FREEBSD_DELIMITER_ASCII;
	return splitStringToPartsCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,delimiter);
}
size_t shinsei_splitStringToFreeBSDPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_FREEBSD_DELIMITER_U8);
}
size_t shinsei_splitStringToFreeBSDPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_FREEBSD_DELIMITER_U16);
}
size_t shinsei_splitStringToFreeBSDPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_FREEBSD_DELIMITER_U32);
}

// Cygwin
size_t shinsei_splitStringToCygwinPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_CYGWIN_DELIMITER_W);
}
size_t shinsei_splitStringToCygwinPathCP(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	register const char delimiter=isEBCDICCodePage(code_page)?SHINSEI_PATH_CYGWIN_DELIMITER_EBCDIC:SHINSEI_PATH_CYGWIN_DELIMITER_ASCII;
	return splitStringToPartsCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,delimiter);
}
size_t shinsei_splitStringToCygwinPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_CYGWIN_DELIMITER_U8);
}
size_t shinsei_splitStringToCygwinPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_CYGWIN_DELIMITER_U16);
}
size_t shinsei_splitStringToCygwinPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_CYGWIN_DELIMITER_U32);
}

// URL
size_t shinsei_splitStringToURLPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_URL_DELIMITER_W);
}
size_t shinsei_splitStringToURLPathCP(const uint_fast32_t code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	register const char delimiter=isEBCDICCodePage(code_page)?SHINSEI_PATH_URL_DELIMITER_EBCDIC:SHINSEI_PATH_URL_DELIMITER_ASCII;
	return splitStringToPartsCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,delimiter);
}
size_t shinsei_splitStringToURLPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_URL_DELIMITER_U8);
}
size_t shinsei_splitStringToURLPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_URL_DELIMITER_U16);
}
size_t shinsei_splitStringToURLPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt,SHINSEI_PATH_URL_DELIMITER_U32);
}

#include"shinsei/.internal/cpp_term_source.hpp"
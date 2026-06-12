#include"shinsei/minimal/str.h"

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

bool shinsei_isANSICodePage(const unsigned int id)_SHINSEI_OS_NOEXCEPT{
	switch(id){
		// Count: 152
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
		case SHINSEI_CODE_PAGE_SHIFT_JIS:
		case SHINSEI_CODE_PAGE_GB2312:
		case SHINSEI_CODE_PAGE_KS_C_5601_1987:
		case SHINSEI_CODE_PAGE_BIG5:
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
		case SHINSEI_CODE_PAGE_UTF_16:
		case SHINSEI_CODE_PAGE_UNICODEFFFE:
		case SHINSEI_CODE_PAGE_WINDOWS_1250:
		case SHINSEI_CODE_PAGE_WINDOWS_1251:
		case SHINSEI_CODE_PAGE_WINDOWS_1252:
		case SHINSEI_CODE_PAGE_WINDOWS_1253:
		case SHINSEI_CODE_PAGE_WINDOWS_1254:
		case SHINSEI_CODE_PAGE_WINDOWS_1255:
		case SHINSEI_CODE_PAGE_WINDOWS_1256:
		case SHINSEI_CODE_PAGE_WINDOWS_1257:
		case SHINSEI_CODE_PAGE_WINDOWS_1258:
		case SHINSEI_CODE_PAGE_JOHAB:
		case SHINSEI_CODE_PAGE_MACINTOSH:
		case SHINSEI_CODE_PAGE_X_MAC_JAPANESE:
		case SHINSEI_CODE_PAGE_X_MAC_CHINESETRAD:
		case SHINSEI_CODE_PAGE_X_MAC_KOREAN:
		case SHINSEI_CODE_PAGE_X_MAC_ARABIC:
		case SHINSEI_CODE_PAGE_X_MAC_HEBREW:
		case SHINSEI_CODE_PAGE_X_MAC_GREEK:
		case SHINSEI_CODE_PAGE_X_MAC_CYRILLIC:
		case SHINSEI_CODE_PAGE_X_MAC_CHINESESIMP:
		case SHINSEI_CODE_PAGE_X_MAC_ROMANIAN:
		case SHINSEI_CODE_PAGE_X_MAC_UKRAINIAN:
		case SHINSEI_CODE_PAGE_X_MAC_THAI:
		case SHINSEI_CODE_PAGE_X_MAC_MAC_CE:
		case SHINSEI_CODE_PAGE_X_MAC_ICELANDIC:
		case SHINSEI_CODE_PAGE_X_MAC_TURKISH:
		case SHINSEI_CODE_PAGE_X_MAC_CROATIAN:
		case SHINSEI_CODE_PAGE_UTF_32:
		case SHINSEI_CODE_PAGE_UTF_32BE:
		case SHINSEI_CODE_PAGE_X_CHINESE_CNS:
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
		case SHINSEI_CODE_PAGE_X_EBCDIC_KOREANEXTENDED:
		case SHINSEI_CODE_PAGE_IBM_THAI:
		case SHINSEI_CODE_PAGE_KOI8_R:
		case SHINSEI_CODE_PAGE_IBM871:
		case SHINSEI_CODE_PAGE_IBM880:
		case SHINSEI_CODE_PAGE_IBM905:
		case SHINSEI_CODE_PAGE_IBM00924:
		case SHINSEI_CODE_PAGE_EUC_JP_LEGACY:
		case SHINSEI_CODE_PAGE_X_CP20936:
		case SHINSEI_CODE_PAGE_X_CP20949:
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
		case SHINSEI_CODE_PAGE_ISO_8859_8_I:
		case SHINSEI_CODE_PAGE_ISO_2022_JP:
		case SHINSEI_CODE_PAGE_CSISO2022JP:
		case SHINSEI_CODE_PAGE_ISO_2022_JP_EXT:
		case SHINSEI_CODE_PAGE_ISO_2022_KR:
		case SHINSEI_CODE_PAGE_X_CP50227:
		case SHINSEI_CODE_PAGE_ISO_2022_TC:
		case SHINSEI_CODE_PAGE_EBCDIC_JA_KATAKANA_EXTENDED:
		case SHINSEI_CODE_PAGE_EBCDIC_US_CA_JP:
		case SHINSEI_CODE_PAGE_EBCDIC_KO_EXTENDED:
		case SHINSEI_CODE_PAGE_EBCDIC_SC_EXTENDED:
		case SHINSEI_CODE_PAGE_EBCDIC_SC:
		case SHINSEI_CODE_PAGE_EBCDIC_US_CA_TC:
		case SHINSEI_CODE_PAGE_EBCDIC_JA_LATIN_EXTENDED:
		case SHINSEI_CODE_PAGE_EUC_JP:
		case SHINSEI_CODE_PAGE_EUC_CN:
		case SHINSEI_CODE_PAGE_EUC_KR:
		case SHINSEI_CODE_PAGE_EUC_TC:
		case SHINSEI_CODE_PAGE_HZ_GB_2312:
		case SHINSEI_CODE_PAGE_GB18030:
		case SHINSEI_CODE_PAGE_X_ISCII_DE:
		case SHINSEI_CODE_PAGE_X_ISCII_BE:
		case SHINSEI_CODE_PAGE_X_ISCII_TA:
		case SHINSEI_CODE_PAGE_X_ISCII_TE:
		case SHINSEI_CODE_PAGE_X_ISCII_AS:
		case SHINSEI_CODE_PAGE_X_ISCII_OR:
		case SHINSEI_CODE_PAGE_X_ISCII_KA:
		case SHINSEI_CODE_PAGE_X_ISCII_MA:
		case SHINSEI_CODE_PAGE_X_ISCII_GU:
		case SHINSEI_CODE_PAGE_X_ISCII_PA:
		case SHINSEI_CODE_PAGE_UTF_7:
		case SHINSEI_CODE_PAGE_UTF_8:{
			return true;
		}
	}
	return false;
}
_SHINSEI_OS_INLINE static bool isEBCDICCodePage(const unsigned int id)_SHINSEI_OS_NOEXCEPT{
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
bool shinsei_isEBCDICCodePage(const unsigned int id)_SHINSEI_OS_NOEXCEPT{
	return isEBCDICCodePage(id);
}

_SHINSEI_OS_INLINE static int charSizeU8(const char8_t starter_ch)_SHINSEI_OS_NOEXCEPT{
	return (starter_ch<=0x7F)+(((starter_ch&0xE0)==0xC0)<<1)+((starter_ch&0xF0)==0xE0)*3+(((starter_ch&0xF8)==0xF0)<<2);
}
_SHINSEI_OS_INLINE static int charSizeU16(const char16_t starter_ch)_SHINSEI_OS_NOEXCEPT{
	return (starter_ch<0xD800||starter_ch>0xDFFF)+((starter_ch>=0xD800&&starter_ch<=0xDBFF)<<1);
}
_SHINSEI_OS_INLINE static int charSizeCP(const unsigned int code_page,const int starter_ch,const int second_ch,const int third_ch,int*const restrict status)_SHINSEI_OS_NOEXCEPT{
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
int shinsei_charSizeW(const wint_t starter_ch)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		(void)starter_ch;
		return 1;
	#else
		return charSizeU16((char16_t)starter_ch);
	#endif
}
int shinsei_charSizeCP(const unsigned int code_page,const int starter_ch,const int second_ch,const int third_ch,int*const restrict status)_SHINSEI_OS_NOEXCEPT{
	return charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
}
int shinsei_charSizeU8(const char8_t starter_ch)_SHINSEI_OS_NOEXCEPT{
	return charSizeU8(starter_ch);
}
int shinsei_charSizeU16(const char16_t starter_ch)_SHINSEI_OS_NOEXCEPT{
	return charSizeU16(starter_ch);
}
int shinsei_charSizeU32(const char32_t starter_ch)_SHINSEI_OS_NOEXCEPT{
	(void)starter_ch;
	return 1;
}

_SHINSEI_OS_INLINE static bool isBDigitASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-'0')<=1;
}
_SHINSEI_OS_INLINE static bool isBDigitCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*((unsigned int)(ch-0xF0)<=1)+!ebcdic*isBDigitASCII(ch);
}
_SHINSEI_OS_INLINE static bool isBDigitU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-u8'0')<=1;
}
_SHINSEI_OS_INLINE static bool isBDigitU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]-u8'0'<=1;
}
_SHINSEI_OS_INLINE static bool isBDigitU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-u'0')<=1;
}
_SHINSEI_OS_INLINE static bool isBDigitU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]-u'0'<=1;
}
_SHINSEI_OS_INLINE static bool isBDigitU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-U'0')<=1;
}
_SHINSEI_OS_INLINE static bool isBDigitU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]-U'0'<=1;
}
bool shinsei_isBDigitW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-L'0')<=1;
}
bool shinsei_isBDigitWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isBDigitU32M((const char32_t**)str_ptr,len);
	#else
		return isBDigitU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isBDigitCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isBDigitCP(code_page,ch);
}
bool shinsei_isBDigitCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
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
	return isBDigitCP(code_page,starter_ch);
}
bool shinsei_isBDigitU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isBDigitU8(ch);
}
bool shinsei_isBDigitU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isBDigitU8M(str_ptr,len);
}
bool shinsei_isBDigitU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isBDigitU16(ch);
}
bool shinsei_isBDigitU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isBDigitU16M(str_ptr,len);
}
bool shinsei_isBDigitU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isBDigitU32(ch);
}
bool shinsei_isBDigitU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isBDigitU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isODigitASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-'0')<=7;
}
_SHINSEI_OS_INLINE static bool isODigitEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0xF0)<=7;
}
_SHINSEI_OS_INLINE static bool isODigitCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isODigitEBCDIC(ch)+!ebcdic*isODigitASCII(ch);
}
_SHINSEI_OS_INLINE static bool isODigitU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-u8'0')<=7;
}
_SHINSEI_OS_INLINE static bool isODigitU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]-u8'0'<=7;
}
_SHINSEI_OS_INLINE static bool isODigitU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-u'0')<=7;
}
_SHINSEI_OS_INLINE static bool isODigitU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]-u'0'<=7;
}
_SHINSEI_OS_INLINE static bool isODigitU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-U'0')<=7;
}
_SHINSEI_OS_INLINE static bool isODigitU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]-U'0'<=7;
}
bool shinsei_isODigitW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-L'0')<=7;
}
bool shinsei_isODigitWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isODigitU32M((const char32_t**)str_ptr,len);
	#else
		return isODigitU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isODigitCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isODigitCP(code_page,ch);
}
bool shinsei_isODigitCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
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
	return isODigitCP(code_page,starter_ch);
}
bool shinsei_isODigitU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isODigitU8(ch);
}
bool shinsei_isODigitU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isODigitU8M(str_ptr,len);
}
bool shinsei_isODigitU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isODigitU16(ch);
}
bool shinsei_isODigitU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isODigitU16M(str_ptr,len);
}
bool shinsei_isODigitU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isODigitU32(ch);
}
bool shinsei_isODigitU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isODigitU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isDigitASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-'0')<=9;
}
_SHINSEI_OS_INLINE static bool isDigitEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0xF0)<=9;
}
_SHINSEI_OS_INLINE static bool isDigitCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isDigitEBCDIC(ch)+!ebcdic*isDigitASCII(ch);
}
_SHINSEI_OS_INLINE static bool isDigitU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-u8'0')<=9;
}
_SHINSEI_OS_INLINE static bool isDigitU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1]-u8'0')<=9;
}
_SHINSEI_OS_INLINE static bool isDigitU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-u'0')<=9;
}
_SHINSEI_OS_INLINE static bool isDigitU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1]-u'0')<=9;
}
_SHINSEI_OS_INLINE static bool isDigitU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-U'0')<=9;
}
_SHINSEI_OS_INLINE static bool isDigitU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (unsigned int)((*str_ptr)[-1]-U'0')<=9;
}
bool shinsei_isDigitW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-L'0')<=9;
}
bool shinsei_isDigitWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isDigitU32M((const char32_t**)str_ptr,len);
	#else
		return isDigitU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isDigitCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isDigitCP(code_page,ch);
}
bool shinsei_isDigitCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
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
	return isDigitCP(code_page,starter_ch);
}
bool shinsei_isDigitU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isDigitU8(ch);
}
bool shinsei_isDigitU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isDigitU8M(str_ptr,len);
}
bool shinsei_isDigitU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isDigitU16(ch);
}
bool shinsei_isDigitU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isDigitU16M(str_ptr,len);
}
bool shinsei_isDigitU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isDigitU32(ch);
}
bool shinsei_isDigitU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isDigitU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isXDigitASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return isDigitASCII(ch)||(unsigned int)((ch|0x20)-'a')<=5;
}
_SHINSEI_OS_INLINE static bool isXDigitEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return isDigitEBCDIC(ch)||(unsigned int)(ch-0x81)<=5||(unsigned int)(ch-0xC1)<=5;
}
_SHINSEI_OS_INLINE static bool isXDigitCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isXDigitEBCDIC(ch)+!ebcdic*isXDigitASCII(ch);
}
_SHINSEI_OS_INLINE static bool isXDigitW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{ // Used in isHexColor
	return (unsigned int)(ch-L'0')<=9||(unsigned int)((ch|0x20)-L'a')<=5;
}
_SHINSEI_OS_INLINE static bool isXDigitU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-u8'0')<=9||(unsigned int)((ch|0x20)-u8'a')<=5;
}
_SHINSEI_OS_INLINE static bool isXDigitU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1]-u8'0')<=9||(unsigned int)(((*str_ptr)[-1]|0x20)-u8'a')<=5;
}
_SHINSEI_OS_INLINE static bool isXDigitU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-u'0')<=9||(unsigned int)((ch|0x20)-u'a')<=5;
}
_SHINSEI_OS_INLINE static bool isXDigitU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1]-u'0')<=9||(unsigned int)(((*str_ptr)[-1]|0x20)-u'a')<=5;
}
_SHINSEI_OS_INLINE static bool isXDigitU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-U'0')<=9||(unsigned int)((ch|0x20)-U'a')<=5;
}
_SHINSEI_OS_INLINE static bool isXDigitU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (unsigned int)((*str_ptr)[-1]-U'0')<=9||(unsigned int)(((*str_ptr)[-1]|0x20)-U'a')<=5;
}
bool shinsei_isXDigitW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isXDigitW(ch);
}
bool shinsei_isXDigitWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isXDigitU32M((const char32_t**)str_ptr,len);
	#else
		return isXDigitU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isXDigitCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isXDigitCP(code_page,ch);
}
bool shinsei_isXDigitCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
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
	return isXDigitCP(code_page,starter_ch);
}
bool shinsei_isXDigitU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isXDigitU8(ch);
}
bool shinsei_isXDigitU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isXDigitU8M(str_ptr,len);
}
bool shinsei_isXDigitU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isXDigitU16(ch);
}
bool shinsei_isXDigitU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isXDigitU16M(str_ptr,len);
}
bool shinsei_isXDigitU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isXDigitU32(ch);
}
bool shinsei_isXDigitU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isXDigitU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isUpperASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-'A')<=25;
}
_SHINSEI_OS_INLINE static bool isUpperEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0xC1)<=8||(unsigned int)(ch-0xD1)<=8||(unsigned int)(ch-0xE2)<=7;
}
_SHINSEI_OS_INLINE static bool isUpperCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isUpperEBCDIC(ch)+!ebcdic*isUpperASCII(ch);
}
_SHINSEI_OS_INLINE static bool isUpperW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{ // Used in toLower
	return (unsigned int)(ch-L'A')<=25;
}
_SHINSEI_OS_INLINE static bool isUpperU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-u8'A')<=25;
}
_SHINSEI_OS_INLINE static bool isUpperU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1]-u8'A')<=25;
}
_SHINSEI_OS_INLINE static bool isUpperU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-u'A')<=25;
}
_SHINSEI_OS_INLINE static bool isUpperU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1]-u'A')<=25;
}
_SHINSEI_OS_INLINE static bool isUpperU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-U'A')<=25;
}
_SHINSEI_OS_INLINE static bool isUpperU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (unsigned int)((*str_ptr)[-1]-U'A')<=25;
}
bool shinsei_isUpperW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isUpperW(ch);
}
bool shinsei_isUpperWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isUpperU32M((const char32_t**)str_ptr,len);
	#else
		return isUpperU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isUpperCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isUpperCP(code_page,ch);
}
bool shinsei_isUpperCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
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
	return isUpperCP(code_page,starter_ch);
}
bool shinsei_isUpperU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isUpperU8(ch);
}
bool shinsei_isUpperU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isUpperU8M(str_ptr,len);
}
bool shinsei_isUpperU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isUpperU16(ch);
}
bool shinsei_isUpperU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isUpperU16M(str_ptr,len);
}
bool shinsei_isUpperU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isUpperU32(ch);
}
bool shinsei_isUpperU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isUpperU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isLowerASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-'a')<=25;
}
_SHINSEI_OS_INLINE static bool isLowerEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0x81)<=8||(unsigned int)(ch-0x91)<=8||(unsigned int)(ch-0xA2)<=7;
}
_SHINSEI_OS_INLINE static bool isLowerCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isLowerEBCDIC(ch)+!ebcdic*isLowerASCII(ch);
}
_SHINSEI_OS_INLINE static bool isLowerW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{ // Used in toUpper
	return (unsigned int)(ch-L'a')<=25;
}
_SHINSEI_OS_INLINE static bool isLowerU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-u8'a')<=25;
}
_SHINSEI_OS_INLINE static bool isLowerU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1]-u8'a')<=25;
}
_SHINSEI_OS_INLINE static bool isLowerU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-u'a')<=25;
}
_SHINSEI_OS_INLINE static bool isLowerU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1]-u'a')<=25;
}
_SHINSEI_OS_INLINE static bool isLowerU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-U'a')<=25;
}
_SHINSEI_OS_INLINE static bool isLowerU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (unsigned int)((*str_ptr)[-1]-U'a')<=25;
}
bool shinsei_isLowerW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return isLowerW(ch);
}
bool shinsei_isLowerWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isLowerU32M((const char32_t**)str_ptr,len);
	#else
		return isLowerU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isLowerCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isLowerCP(code_page,ch);
}
bool shinsei_isLowerCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
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
	return isLowerCP(code_page,starter_ch);
}
bool shinsei_isLowerU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isLowerU8(ch);
}
bool shinsei_isLowerU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isLowerU8M(str_ptr,len);
}
bool shinsei_isLowerU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isLowerU16(ch);
}
bool shinsei_isLowerU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isLowerU16M(str_ptr,len);
}
bool shinsei_isLowerU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isLowerU32(ch);
}
bool shinsei_isLowerU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isLowerU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isAlphaASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)((ch|0x20)-'a')<=25;
}
_SHINSEI_OS_INLINE static bool isAlphaEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return isUpperEBCDIC(ch)||isLowerEBCDIC(ch);
}
_SHINSEI_OS_INLINE static bool isAlphaCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isAlphaEBCDIC(ch)+!ebcdic*isAlphaASCII(ch);
}
_SHINSEI_OS_INLINE static bool isAlphaU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)((ch|0x20)-u8'a')<=25;
}
_SHINSEI_OS_INLINE static bool isAlphaU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)(((*str_ptr)[-1]|0x20)-u8'a')<=25;
}
_SHINSEI_OS_INLINE static bool isAlphaU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)((ch|0x20)-u'a')<=25;
}
_SHINSEI_OS_INLINE static bool isAlphaU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)(((*str_ptr)[-1]|0x20)-u'a')<=25;
}
_SHINSEI_OS_INLINE static bool isAlphaU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)((ch|0x20)-U'a')<=25;
}
_SHINSEI_OS_INLINE static bool isAlphaU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (unsigned int)(((*str_ptr)[-1]|0x20)-U'a')<=25;
}
bool shinsei_isAlphaW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)((ch|0x20)-L'a')<=25;
}
bool shinsei_isAlphaWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isAlphaU32M((const char32_t**)str_ptr,len);
	#else
		return isAlphaU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isAlphaCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isAlphaCP(code_page,ch);
}
bool shinsei_isAlphaCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
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
	return isAlphaCP(code_page,starter_ch);
}
bool shinsei_isAlphaU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isAlphaU8(ch);
}
bool shinsei_isAlphaU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isAlphaU8M(str_ptr,len);
}
bool shinsei_isAlphaU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isAlphaU16(ch);
}
bool shinsei_isAlphaU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isAlphaU16M(str_ptr,len);
}
bool shinsei_isAlphaU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isAlphaU32(ch);
}
bool shinsei_isAlphaU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isAlphaU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isAlnumASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return isDigitASCII(ch)||isAlphaASCII(ch);
}
_SHINSEI_OS_INLINE static bool isAlnumEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return isDigitEBCDIC(ch)||isAlphaEBCDIC(ch);
}
_SHINSEI_OS_INLINE static bool isAlnumCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isAlnumEBCDIC(ch)+!ebcdic*isAlnumASCII(ch);
}
_SHINSEI_OS_INLINE static bool isAlnumU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-u8'0')<=9||(unsigned int)((ch|0x20)-u8'a')<=25;
}
_SHINSEI_OS_INLINE static bool isAlnumU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1]-u8'0')<=9||(unsigned int)(((*str_ptr)[-1]|0x20)-u8'a')<=25;
}
_SHINSEI_OS_INLINE static bool isAlnumU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-u'0')<=9||(unsigned int)((ch|0x20)-u'a')<=25;
}
_SHINSEI_OS_INLINE static bool isAlnumU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1]-u'0')<=9||(unsigned int)(((*str_ptr)[-1]|0x20)-u'a')<=25;
}
_SHINSEI_OS_INLINE static bool isAlnumU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-U'0')<=9||(unsigned int)((ch|0x20)-U'a')<=25;
}
_SHINSEI_OS_INLINE static bool isAlnumU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (unsigned int)((*str_ptr)[-1]-U'0')<=9||(unsigned int)(((*str_ptr)[-1]|0x20)-U'a')<=25;
}
bool shinsei_isAlnumW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-L'0')<=9||(unsigned int)((ch|0x20)-L'a')<=25;
}
bool shinsei_isAlnumWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isAlnumU32M((const char32_t**)str_ptr,len);
	#else
		return isAlnumU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isAlnumCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isAlnumCP(code_page,ch);
}
bool shinsei_isAlnumCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
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
	return isAlnumCP(code_page,starter_ch);
}
bool shinsei_isAlnumU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isAlnumU8(ch);
}
bool shinsei_isAlnumU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isAlnumU8M(str_ptr,len);
}
bool shinsei_isAlnumU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isAlnumU16(ch);
}
bool shinsei_isAlnumU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isAlnumU16M(str_ptr,len);
}
bool shinsei_isAlnumU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isAlnumU32(ch);
}
bool shinsei_isAlnumU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isAlnumU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isBlankASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x20||ch==0x09;
}
_SHINSEI_OS_INLINE static bool isBlankEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x40||ch==0x05;
}
_SHINSEI_OS_INLINE static bool isBlankCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isBlankEBCDIC(ch)+!ebcdic*isBlankASCII(ch);
}
_SHINSEI_OS_INLINE static bool isBlankU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x20||ch==0x09;
}
_SHINSEI_OS_INLINE static bool isBlankU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==0x20||(*str_ptr)[-1]==0x09;
}
_SHINSEI_OS_INLINE static bool isBlankU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x20||ch==0x09;
}
_SHINSEI_OS_INLINE static bool isBlankU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==0x20||(*str_ptr)[-1]==0x09;
}
_SHINSEI_OS_INLINE static bool isBlankU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x20||ch==0x09;
}
_SHINSEI_OS_INLINE static bool isBlankU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]==0x20||(*str_ptr)[-1]==0x09;
}
bool shinsei_isBlankW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x20||ch==0x09;
}
bool shinsei_isBlankWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isBlankU32M((const char32_t**)str_ptr,len);
	#else
		return isBlankU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isBlankCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isBlankCP(code_page,ch);
}
bool shinsei_isBlankCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
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
	return isBlankCP(code_page,starter_ch);
}
bool shinsei_isBlankU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isBlankU8(ch);
}
bool shinsei_isBlankU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isBlankU8M(str_ptr,len);
}
bool shinsei_isBlankU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isBlankU16(ch);
}
bool shinsei_isBlankU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isBlankU16M(str_ptr,len);
}
bool shinsei_isBlankU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isBlankU32(ch);
}
bool shinsei_isBlankU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isBlankU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isCntrlASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)ch<=0x1F||ch==0x7F;
}
_SHINSEI_OS_INLINE static bool isCntrlEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)ch<=0x3F||ch==0xFF;
}
_SHINSEI_OS_INLINE static bool isCntrlCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isCntrlEBCDIC(ch)+!ebcdic*isCntrlASCII(ch);
}
_SHINSEI_OS_INLINE static bool isCntrlU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)ch<=0x1F||ch==0x7F;
}
_SHINSEI_OS_INLINE static bool isCntrlU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1])<=0x1F||(*str_ptr)[-1]==0x7F;
}
_SHINSEI_OS_INLINE static bool isCntrlU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)ch<=0x1F||ch==0x7F;
}
_SHINSEI_OS_INLINE static bool isCntrlU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1])<=0x1F||(*str_ptr)[-1]==0x7F;
}
_SHINSEI_OS_INLINE static bool isCntrlU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)ch<=0x1F||ch==0x7F;
}
_SHINSEI_OS_INLINE static bool isCntrlU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (unsigned int)((*str_ptr)[-1])<=0x1F||(*str_ptr)[-1]==0x7F;
}
bool shinsei_isCntrlW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)ch<=0x1F||ch==0x7F;
}
bool shinsei_isCntrlWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isCntrlU32M((const char32_t**)str_ptr,len);
	#else
		return isCntrlU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isCntrlCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isCntrlCP(code_page,ch);
}
bool shinsei_isCntrlCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
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
	return isCntrlCP(code_page,starter_ch);
}
bool shinsei_isCntrlU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isCntrlU8(ch);
}
bool shinsei_isCntrlU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isCntrlU8M(str_ptr,len);
}
bool shinsei_isCntrlU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isCntrlU16(ch);
}
bool shinsei_isCntrlU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isCntrlU16M(str_ptr,len);
}
bool shinsei_isCntrlU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isCntrlU32(ch);
}
bool shinsei_isCntrlU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isCntrlU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isPrintASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0x20)<=0x5E;
}
_SHINSEI_OS_INLINE static bool isPrintEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return !isCntrlEBCDIC(ch);
}
_SHINSEI_OS_INLINE static bool isPrintCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isPrintEBCDIC(ch)+!ebcdic*isPrintASCII(ch);
}
_SHINSEI_OS_INLINE static bool isPrintU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0x20)<=0x5E;
}
_SHINSEI_OS_INLINE static bool isPrintU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1]-0x20)<=0x5E;
}
_SHINSEI_OS_INLINE static bool isPrintU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0x20)<=0x5E;
}
_SHINSEI_OS_INLINE static bool isPrintU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1]-0x20)<=0x5E;
}
_SHINSEI_OS_INLINE static bool isPrintU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0x20)<=0x5E;
}
_SHINSEI_OS_INLINE static bool isPrintU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (unsigned int)((*str_ptr)[-1]-0x20)<=0x5E;
}
bool shinsei_isPrintW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0x20)<=0x5E;
}
bool shinsei_isPrintWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isPrintU32M((const char32_t**)str_ptr,len);
	#else
		return isPrintU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isPrintCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isPrintCP(code_page,ch);
}
bool shinsei_isPrintCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
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
	return isPrintCP(code_page,starter_ch);
}
bool shinsei_isPrintU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isPrintU8(ch);
}
bool shinsei_isPrintU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isPrintU8M(str_ptr,len);
}
bool shinsei_isPrintU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isPrintU16(ch);
}
bool shinsei_isPrintU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isPrintU16M(str_ptr,len);
}
bool shinsei_isPrintU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isPrintU32(ch);
}
bool shinsei_isPrintU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isPrintU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isGraphASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0x21)<=0x5D;
}
_SHINSEI_OS_INLINE static bool isGraphEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return isPrintEBCDIC(ch)&&ch!=0x40;
}
_SHINSEI_OS_INLINE static bool isGraphCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isGraphEBCDIC(ch)+!ebcdic*isGraphASCII(ch);
}
_SHINSEI_OS_INLINE static bool isGraphU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0x21)<=0x5D;
}
_SHINSEI_OS_INLINE static bool isGraphU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1]-0x21)<=0x5D;
}
_SHINSEI_OS_INLINE static bool isGraphU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0x21)<=0x5D;
}
_SHINSEI_OS_INLINE static bool isGraphU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1]-0x21)<=0x5D;
}
_SHINSEI_OS_INLINE static bool isGraphU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0x21)<=0x5D;
}
_SHINSEI_OS_INLINE static bool isGraphU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (unsigned int)((*str_ptr)[-1]-0x21)<=0x5D;
}
bool shinsei_isGraphW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0x21)<=0x5D;
}
bool shinsei_isGraphWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isGraphU32M((const char32_t**)str_ptr,len);
	#else
		return isGraphU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isGraphCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isGraphCP(code_page,ch);
}
bool shinsei_isGraphCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
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
	return isGraphCP(code_page,starter_ch);
}
bool shinsei_isGraphU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isGraphU8(ch);
}
bool shinsei_isGraphU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isGraphU8M(str_ptr,len);
}
bool shinsei_isGraphU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isGraphU16(ch);
}
bool shinsei_isGraphU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isGraphU16M(str_ptr,len);
}
bool shinsei_isGraphU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isGraphU32(ch);
}
bool shinsei_isGraphU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isGraphU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isPunctASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return isGraphASCII(ch)&&!isAlnumASCII(ch);
}
_SHINSEI_OS_INLINE static bool isPunctEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return isGraphEBCDIC(ch)&&!isAlnumEBCDIC(ch);
}
_SHINSEI_OS_INLINE static bool isPunctCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isPunctEBCDIC(ch)+!ebcdic*isPunctASCII(ch);
}
_SHINSEI_OS_INLINE static bool isPunctU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0x21)<=0x5D&&!((unsigned int)(ch-u8'0')<=9||(unsigned int)((ch|0x20)-u8'a')<=25);
}
_SHINSEI_OS_INLINE static bool isPunctU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1]-0x21)<=0x5D&&!((unsigned int)((*str_ptr)[-1]-u8'0')<=9||(unsigned int)(((*str_ptr)[-1]|0x20)-u8'a')<=25);
}
_SHINSEI_OS_INLINE static bool isPunctU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0x21)<=0x5D&&!((unsigned int)(ch-u'0')<=9||(unsigned int)((ch|0x20)-u'a')<=25);
}
_SHINSEI_OS_INLINE static bool isPunctU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (unsigned int)((*str_ptr)[-1]-0x21)<=0x5D&&!((unsigned int)((*str_ptr)[-1]-u'0')<=9||(unsigned int)(((*str_ptr)[-1]|0x20)-u'a')<=25);
}
_SHINSEI_OS_INLINE static bool isPunctU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0x21)<=0x5D&&!((unsigned int)(ch-U'0')<=9||(unsigned int)((ch|0x20)-U'a')<=25);
}
_SHINSEI_OS_INLINE static bool isPunctU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (unsigned int)((*str_ptr)[-1]-0x21)<=0x5D&&!((unsigned int)((*str_ptr)[-1]-U'0')<=9||(unsigned int)(((*str_ptr)[-1]|0x20)-U'a')<=25);
}
bool shinsei_isPunctW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0x21)<=0x5D&&!((unsigned int)(ch-L'0')<=9||(unsigned int)((ch|0x20)-L'a')<=25);
}
bool shinsei_isPunctWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isPunctU32M((const char32_t**)str_ptr,len);
	#else
		return isPunctU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isPunctCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isPunctCP(code_page,ch);
}
bool shinsei_isPunctCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
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
	return isPunctCP(code_page,starter_ch);
}
bool shinsei_isPunctU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isPunctU8(ch);
}
bool shinsei_isPunctU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isPunctU8M(str_ptr,len);
}
bool shinsei_isPunctU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isPunctU16(ch);
}
bool shinsei_isPunctU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isPunctU16M(str_ptr,len);
}
bool shinsei_isPunctU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isPunctU32(ch);
}
bool shinsei_isPunctU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isPunctU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isSpaceASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x20||(unsigned int)(ch-0x09)<=4;
}
_SHINSEI_OS_INLINE static bool isSpaceEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x40||ch==0x05||ch==0x25||ch==0x0B||ch==0x0C||ch==0x0D;
}
_SHINSEI_OS_INLINE static bool isSpaceCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isSpaceEBCDIC(ch)+!ebcdic*isSpaceASCII(ch);
}
_SHINSEI_OS_INLINE static bool isSpaceU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x20||(unsigned int)(ch-0x09)<=4;
}
_SHINSEI_OS_INLINE static bool isSpaceU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==0x20||(unsigned int)((*str_ptr)[-1]-0x09)<=4;
}
_SHINSEI_OS_INLINE static bool isSpaceU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x20||(unsigned int)(ch-0x09)<=4;
}
_SHINSEI_OS_INLINE static bool isSpaceU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==0x20||(unsigned int)((*str_ptr)[-1]-0x09)<=4;
}
_SHINSEI_OS_INLINE static bool isSpaceU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x20||(unsigned int)(ch-0x09)<=4;
}
_SHINSEI_OS_INLINE static bool isSpaceU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]==0x20||(unsigned int)((*str_ptr)[-1]-0x09)<=4;
}

bool shinsei_isSpaceW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x20||(unsigned int)(ch-0x09)<=4;
}
bool shinsei_isSpaceWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isSpaceU32M((const char32_t**)str_ptr,len);
	#else
		return isSpaceU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isSpaceCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isSpaceCP(code_page,ch);
}
bool shinsei_isSpaceCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
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
	return isSpaceCP(code_page,starter_ch);
}
bool shinsei_isSpaceU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isSpaceU8(ch);
}
bool shinsei_isSpaceU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isSpaceU8M(str_ptr,len);
}
bool shinsei_isSpaceU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isSpaceU16(ch);
}
bool shinsei_isSpaceU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isSpaceU16M(str_ptr,len);
}
bool shinsei_isSpaceU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isSpaceU32(ch);
}
bool shinsei_isSpaceU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isSpaceU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static bool isJSONWhitespaceASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x20||ch==0x09||ch==0x0A||ch==0x0D;
}
_SHINSEI_OS_INLINE static bool isJSONWhitespaceEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x40||ch==0x05||ch==0x25||ch==0x0D;
}
_SHINSEI_OS_INLINE static bool isJSONWhitespaceCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*isJSONWhitespaceEBCDIC(ch)+!ebcdic*isJSONWhitespaceASCII(ch);
}
_SHINSEI_OS_INLINE static bool isJSONWhitespaceU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x20||ch==0x09||ch==0x0A||ch==0x0D;
}
_SHINSEI_OS_INLINE static bool isJSONWhitespaceU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==0x20||(*str_ptr)[-1]==0x09||(*str_ptr)[-1]==0x0A||(*str_ptr)[-1]==0x0D;
}
_SHINSEI_OS_INLINE static bool isJSONWhitespaceU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x20||ch==0x09||ch==0x0A||ch==0x0D;
}
_SHINSEI_OS_INLINE static bool isJSONWhitespaceU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr)[-1]==0x20||(*str_ptr)[-1]==0x09||(*str_ptr)[-1]==0x0A||(*str_ptr)[-1]==0x0D;
}
_SHINSEI_OS_INLINE static bool isJSONWhitespaceU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x20||ch==0x09||ch==0x0A||ch==0x0D;
}
_SHINSEI_OS_INLINE static bool isJSONWhitespaceU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return false;
	*str_ptr+=1;
	return (*str_ptr)[-1]==0x20||(*str_ptr)[-1]==0x09||(*str_ptr)[-1]==0x0A||(*str_ptr)[-1]==0x0D;
}
bool shinsei_isJSONWhitespaceW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch==0x20||ch==0x09||ch==0x0A||ch==0x0D;
}
bool shinsei_isJSONWhitespaceWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return isJSONWhitespaceU32M((const char32_t**)str_ptr,len);
	#else
		return isJSONWhitespaceU16M((const char16_t**)str_ptr,len);
	#endif
}
bool shinsei_isJSONWhitespaceCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return isJSONWhitespaceCP(code_page,ch);
}
bool shinsei_isJSONWhitespaceCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
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
	return isJSONWhitespaceCP(code_page,starter_ch);
}
bool shinsei_isJSONWhitespaceU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return isJSONWhitespaceU8(ch);
}
bool shinsei_isJSONWhitespaceU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isJSONWhitespaceU8M(str_ptr,len);
}
bool shinsei_isJSONWhitespaceU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return isJSONWhitespaceU16(ch);
}
bool shinsei_isJSONWhitespaceU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isJSONWhitespaceU16M(str_ptr,len);
}
bool shinsei_isJSONWhitespaceU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return isJSONWhitespaceU32(ch);
}
bool shinsei_isJSONWhitespaceU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return isJSONWhitespaceU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static int toUpperASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch-(isLowerASCII(ch)<<5);
}
_SHINSEI_OS_INLINE static int toUpperEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch+(isLowerEBCDIC(ch)<<6);
}
_SHINSEI_OS_INLINE static int toUpperCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*toUpperEBCDIC(ch)+!ebcdic*toUpperASCII(ch);
}
_SHINSEI_OS_INLINE static char8_t toUpperU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch-(char8_t)(isLowerU8(ch)<<5);
}
_SHINSEI_OS_INLINE static char8_t toUpperU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return 0;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	register const char8_t ch=**str_ptr;
	*str_ptr+=size;
	if(size>1) return ch;
	return ch-(char8_t)(isLowerU8(ch)<<5);
}
_SHINSEI_OS_INLINE static char16_t toUpperU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch-(char16_t)(isLowerU16(ch)<<5);
}
_SHINSEI_OS_INLINE static char16_t toUpperU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return 0;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	register const char16_t ch=**str_ptr;
	*str_ptr+=size;
	if(size>1) return ch;
	return ch-(char16_t)(isLowerU16(ch)<<5);
}
_SHINSEI_OS_INLINE static char32_t toUpperU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch-(isLowerU32(ch)<<5);
}
_SHINSEI_OS_INLINE static char32_t toUpperU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return 0;
	register const char32_t ch=**str_ptr;
	*str_ptr+=1;
	return ch-(isLowerU32(ch)<<5);
}

wint_t shinsei_toUpperW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch-(wint_t)(isLowerW(ch)<<5);
}
wint_t shinsei_toUpperWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return toUpperU32M((const char32_t**)str_ptr,len);
	#else
		return toUpperU16M((const char16_t**)str_ptr,len);
	#endif
}
int shinsei_toUpperCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return toUpperCP(code_page,ch);
}
int shinsei_toUpperCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return 0;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return starter_ch;
	return toUpperCP(code_page,starter_ch);
}
char8_t shinsei_toUpperU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return toUpperU8(ch);
}
char8_t shinsei_toUpperU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return toUpperU8M(str_ptr,len);
}
char16_t shinsei_toUpperU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return toUpperU16(ch);
}
char16_t shinsei_toUpperU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return toUpperU16M(str_ptr,len);
}
char32_t shinsei_toUpperU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return toUpperU32(ch);
}
char32_t shinsei_toUpperU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return toUpperU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static int toLowerASCII(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch+(isUpperASCII(ch)<<5);
}
_SHINSEI_OS_INLINE static int toLowerEBCDIC(const int ch)_SHINSEI_OS_NOEXCEPT{
	return ch-(isUpperEBCDIC(ch)<<6);
}
_SHINSEI_OS_INLINE static int toLowerCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic*toLowerEBCDIC(ch)+!ebcdic*toLowerASCII(ch);
}
_SHINSEI_OS_INLINE static char8_t toLowerU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch+(char8_t)(isUpperU8(ch)<<5);
}
_SHINSEI_OS_INLINE static char8_t toLowerU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return 0;
	register const size_t size=(size_t)charSizeU8(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	register const char8_t ch=**str_ptr;
	*str_ptr+=size;
	if(size>1) return ch;
	return ch+(char8_t)(isUpperU8(ch)<<5);
}
_SHINSEI_OS_INLINE static char16_t toLowerU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch+(char16_t)(isUpperU16(ch)<<5);
}
_SHINSEI_OS_INLINE static char16_t toLowerU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!len,0)) return 0;
	register const size_t size=(size_t)charSizeU16(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	register const char16_t ch=**str_ptr;
	*str_ptr+=size;
	if(size>1) return ch;
	return ch+(char16_t)(isUpperU16(ch)<<5);
}
_SHINSEI_OS_INLINE static char32_t toLowerU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch+(isUpperU32(ch)<<5);
}
_SHINSEI_OS_INLINE static char32_t toLowerU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(len<1,0)) return 0;
	register const char32_t ch=**str_ptr;
	*str_ptr+=1;
	return ch+(isUpperU32(ch)<<5);
}

wint_t shinsei_toLowerW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return ch+(wint_t)(isUpperW(ch)<<5);
}
wint_t shinsei_toLowerWM(const wchar_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	#ifdef _SHINSEI_WCHAR_U32
		return toLowerU32M((const char32_t**)str_ptr,len);
	#else
		return toLowerU16M((const char16_t**)str_ptr,len);
	#endif
}
int shinsei_toLowerCP(const unsigned int code_page,const int ch)_SHINSEI_OS_NOEXCEPT{
	return toLowerCP(code_page,ch);
}
int shinsei_toLowerCPM(const unsigned int code_page,const char** const restrict str_ptr,const size_t len,int* const restrict status)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	if(__builtin_expect(!len,0)) return 0;
	register const char* p=*str_ptr;
	register const int starter_ch=(unsigned char)p[0];
	register const int second_ch=(len>1)*(unsigned char)p[1];
	register const int third_ch=(len>2)*(unsigned char)p[2];
	register const int size=charSizeCP(code_page,starter_ch,second_ch,third_ch,status);
	if(__builtin_expect(len<(size_t)size||!size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return starter_ch;
	return toLowerCP(code_page,starter_ch);
}
char8_t shinsei_toLowerU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return toLowerU8(ch);
}
char8_t shinsei_toLowerU8M(const char8_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return toLowerU8M(str_ptr,len);
}
char16_t shinsei_toLowerU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return toLowerU16(ch);
}
char16_t shinsei_toLowerU16M(const char16_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return toLowerU16M(str_ptr,len);
}
char32_t shinsei_toLowerU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return toLowerU32(ch);
}
char32_t shinsei_toLowerU32M(const char32_t**const restrict str_ptr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return toLowerU32M(str_ptr,len);
}

_SHINSEI_OS_INLINE static int isHexColorU8(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// Posiable length: 3 ("123"), 4 ("#123"), 6("123456") and 7("#123456")
	if(len!=7&&len!=4&&len!=6&&len!=3) return 0;
	register const char8_t* ptr=str+(*str==u8'#');
	register const int res=(!isXDigitU8(ptr[0])||!isXDigitU8(ptr[1])||!isXDigitU8(ptr[2]))||(len>=6&&(!isXDigitU8(ptr[3])||!isXDigitU8(ptr[4])||!isXDigitU8(ptr[5])));
	return !res*(int)len;
}
_SHINSEI_OS_INLINE static int isHexColorU16(const char16_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// Posiable length: 3 ("123"), 4 ("#123"), 6("123456") and 7("#123456")
	if(len!=7&&len!=4&&len!=6&&len!=3) return 0;
	register const char16_t* ptr=str+(*str==u'#');
	register const int res=(!isXDigitU16(ptr[0])||!isXDigitU16(ptr[1])||!isXDigitU16(ptr[2]))||(len>=6&&(!isXDigitU16(ptr[3])||!isXDigitU16(ptr[4])||!isXDigitU16(ptr[5])));
	return !res*(int)len;
}
_SHINSEI_OS_INLINE static int isHexColorU32(const char32_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// Posiable length: 3 ("123"), 4 ("#123"), 6("123456") and 7("#123456")
	if(len!=7&&len!=4&&len!=6&&len!=3) return 0;
	register const char32_t* ptr=str+(*str==U'#');
	register const int res=(!isXDigitU32(ptr[0])||!isXDigitU32(ptr[1])||!isXDigitU32(ptr[2]))||(len>=6&&(!isXDigitU32(ptr[3])||!isXDigitU32(ptr[4])||!isXDigitU32(ptr[5])));
	return !res*(int)len;
}
_SHINSEI_OS_INLINE static int isHexColorCP(const unsigned int code_page,const char*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// Posiable length: 3 ("123"), 4 ("#123"), 6("123456") and 7("#123456")
	if(len!=7&&len!=4&&len!=6&&len!=3) return 0;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char* ptr=str+(*str==(ebcdic*0x7B+!ebcdic*0x23));
	register const int res=(!isXDigitCP(code_page,ptr[0])||!isXDigitCP(code_page,ptr[1])||!isXDigitCP(code_page,ptr[2]))||(len>=6&&(!isXDigitCP(code_page,ptr[3])||!isXDigitCP(code_page,ptr[4])||!isXDigitCP(code_page,ptr[5])));
	return !res*(int)len;
}

int shinsei_isHexColorW(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// len: Size of the string buffer in character units.
	// Possible length: 3 ("123"), 4 ("#123"), 6("123456") and 7("#123456")
	if(len!=7&&len!=4&&len!=6&&len!=3) return 0;
	register const wchar_t* ptr=str+(*str==L'#');
	register const int res=(!isXDigitW(ptr[0])||!isXDigitW(ptr[1])||!isXDigitW(ptr[2]))||(len>=6&&(!isXDigitW(ptr[3])||!isXDigitW(ptr[4])||!isXDigitW(ptr[5])));
	return !res*(int)len;
}
int shinsei_isHexColorCP(const unsigned int code_page,const char*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// len: Size of the string buffer in character units.
	// Possible length: 3 ("123"), 4 ("#123"), 6("123456") and 7("#123456")
	return isHexColorCP(code_page,str,len);
}
int shinsei_isHexColorU8(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// len: Size of the string buffer in character units.
	// Possible length: 3 ("123"), 4 ("#123"), 6("123456") and 7("#123456")
	return isHexColorU8(str,len);
}
int shinsei_isHexColorU16(const char16_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// len: Size of the string buffer in character units.
	// Possible length: 3 ("123"), 4 ("#123"), 6("123456") and 7("#123456")
	return isHexColorU16(str,len);
}
int shinsei_isHexColorU32(const char32_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// len: Size of the string buffer in character units.
	// Possible length: 3 ("123"), 4 ("#123"), 6("123456") and 7("#123456")
	return isHexColorU32(str,len);
}

_SHINSEI_OS_INLINE static int uTF32CharToUTF16Char(char16_t*const restrict des,const char32_t src)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(src<0x10000,1)){
		des[0]=(char16_t)src;
		return 1;
	}
	register const char32_t res=src-0x10000;
	des[0]=(char16_t)((res>>10)+0xD800);
	des[1]=(char16_t)((res&0x3FF)+0xDC00);
	return 2;
}
int shinsei_uTF32CharToUTF16Char(char16_t*const restrict des,const char32_t src)_SHINSEI_OS_NOEXCEPT{
	// des: Destination buffer. Requires a capacity of at least 2 char16_t.
	return uTF32CharToUTF16Char(des,src);
}

_SHINSEI_OS_INLINE static int uTF32CharToUTF8Char(char8_t*const restrict des,const char32_t src)_SHINSEI_OS_NOEXCEPT{
	if(src<=0x7F){
		des[0]=(char8_t)src;
		return 1;
	}
	if(src<=0x7FF){
		des[0]=(char8_t)(0xC0|(src>>6));
		des[1]=(char8_t)(0x80|(src&0x3F));
		return 2;
	}
	if(src<=0xFFFF){
		des[0]=(char8_t)(0xE0|(src>>12));
		des[1]=(char8_t)(0x80|((src>>6)&0x3F));
		des[2]=(char8_t)(0x80|(src&0x3F));
		return 3;
	}
	if(src<=0x10FFFF){
		des[0]=(char8_t)(0xF0|(src>>18));
		des[1]=(char8_t)(0x80|((src>>12)&0x3F));
		des[2]=(char8_t)(0x80|((src>>6)&0x3F));
		des[3]=(char8_t)(0x80|(src&0x3F));
		return 4;
	}
	return 0;
}
int shinsei_uTF32CharToUTF8Char(char8_t*const restrict des,const char32_t src)_SHINSEI_OS_NOEXCEPT{
	// des: Destination buffer. Requires a capacity of at least 4 char8_t.
	return uTF32CharToUTF8Char(des,src);
}

_SHINSEI_OS_INLINE static int uTF16CharToUTF8Char(char8_t*const restrict des,const char16_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	register char32_t buf;
	if(src[0]>=0xD800&&src[0]<=0xDBFF){
		if(src_len>=2&&src[1]>=0xDC00&&src[1]<=0xDFFF){
			buf=(((char32_t)(src[0]&0x3FF)<<10)|(src[1]&0x3FF))+0x10000;
		}
		else return 0;
	}
	else buf=(char32_t)src[0];
	return uTF32CharToUTF8Char(des,buf);
}
int shinsei_uTF16CharToUTF8Char(char8_t*const restrict des,const char16_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	// des: Destination buffer. Requires a capacity of at least 4 char8_t.
	// src_len: Size of the source string buffer in character units. 0 or more.
	return uTF16CharToUTF8Char(des,src,src_len);
}

_SHINSEI_OS_INLINE static int uTF16CharToUTF32Char(char32_t*const restrict des,const char16_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(src[0]<0xD800||src[0]>0xDFFF){
		*des=src[0];
		return 1;
	}
	if(src[0]>=0xD800&&src[0]<=0xDBFF&&src_len>=2){
		if(src[1]>=0xDC00&&src[1]<=0xDFFF){
			*des=(((char32_t)(src[0]&0x3FF)<<10)|(src[1]&0x3FF))+0x10000;
			return 2;
		}
	}
	return 0;
}
int shinsei_uTF16CharToUTF32Char(char32_t*const restrict des,const char16_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	// des: Destination buffer. Requires a capacity of at least 1 char32_t.
	// src_len: Size of the source string buffer in character units. 0 or more.
	return uTF16CharToUTF32Char(des,src,src_len);
}

_SHINSEI_OS_INLINE static int uTF8CharToUTF32Char(char32_t*const restrict des,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(src[0]<0x80){
		*des=(char32_t)src[0];
		return 1;
	}
	if((src[0]&0xE0)==0xC0&&src_len>=2){
		*des=(((char32_t)(src[0]&0x1F)<<6)|(src[1]&0x3F));
		return 2;
	}
	if((src[0]&0xF0)==0xE0&&src_len>=3){
		*des=(((char32_t)(src[0]&0x0F)<<12)|((src[1]&0x3F)<<6)|(src[2]&0x3F));
		return 3;
	}
	if((src[0]&0xF8)==0xF0&&src_len>=4){
		*des=(((char32_t)(src[0]&0x07)<<18)|((src[1]&0x3F)<<12)|((src[2]&0x3F)<<6)|(src[3]&0x3F));
		return 4;
	}
	return 0;
}
int shinsei_uTF8CharToUTF32Char(char32_t*const restrict des,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	// des: Destination buffer. Requires a capacity of at least 1 char32_t.
	// src_len: Size of the source string buffer in character units. 0 or more.
	return uTF8CharToUTF32Char(des,src,src_len);
}

_SHINSEI_OS_INLINE static int uTF8CharToUTF16Char(char16_t*const restrict des,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	char32_t buf;
	register const int res=uTF8CharToUTF32Char(&buf,src,src_len);
	if(__builtin_expect(!res,0)) return 0;
	if(__builtin_expect(buf<=0xFFFF,1)){
		*des=(char16_t)buf;
		return 1;
	}
	buf-=0x10000;
	des[0]=(char16_t)((buf>>10)+0xD800);
	des[1]=(char16_t)((buf&0x3FF)+0xDC00);
	return 2;
}
int shinsei_uTF8CharToUTF16Char(char16_t*const restrict des,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	// des: Destination buffer. Requires a capacity of at least 2 char16_t.
	return uTF8CharToUTF16Char(des,src,src_len);
}

size_t shinsei_uTF32ToUTF16(char16_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: Size of the source string.
	register size_t si=0;
	register size_t di=0;
	while(si<src_len){
		register const char32_t cp=src[si++];
		char16_t tmp[2];
		register const size_t w=(size_t)uTF32CharToUTF16Char(tmp,cp);
		if(__builtin_expect(!w,0)) return 0;
		if(di+w>des_buf_len){
			di+=w;
			while(si<src_len){
				register const size_t nw=(size_t)uTF32CharToUTF16Char(tmp,src[si++]);
				if(!nw) return 0;
				di+=nw;
			}
			return di;
		}
		for(register size_t i=0;i<w;++i) des_buf[di++]=tmp[i];
	}
	if(di<des_buf_len) des_buf[di]=0;
	return di;
}

size_t shinsei_uTF32ToUTF8(char8_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: Size of the source string.
	register size_t si=0;
	register size_t di=0;
	while(si<src_len){
		register const char32_t cp=src[si++];
		char8_t tmp[4];
		register const size_t w=(size_t)uTF32CharToUTF8Char(tmp,cp);
		if(__builtin_expect(!w,0)) return 0;
		if(di+w>des_buf_len){
			di+=w;
			while(si<src_len){
				register const size_t nw=(size_t)uTF32CharToUTF8Char(tmp,src[si++]);
				if(!nw) return 0;
				di+=nw;
			}
			return di;
		}
		for(register size_t i=0;i<w;++i) des_buf[di++]=tmp[i];
	}
	if(di<des_buf_len) des_buf[di]=0;
	return di;
}

size_t shinsei_uTF16ToUTF8(char8_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: Size of the source string.
	register size_t si=0;
	register size_t di=0;
	while(si<src_len){
		char32_t cp;
		register const size_t r=(size_t)uTF16CharToUTF32Char(&cp,src+si,src_len-si);
		if(__builtin_expect(!r,0)) return 0;
		si+=r;
		char8_t tmp[4];
		register const size_t w=(size_t)uTF32CharToUTF8Char(tmp,cp);
		if(di+w>des_buf_len){
			di+=w;
			while(si<src_len){
				register const size_t nr=(size_t)uTF16CharToUTF32Char(&cp,src+si,src_len-si);
				if(!nr) return 0;
				si+=nr;
				di+=(size_t)uTF32CharToUTF8Char(tmp,cp);
			}
			return di;
		}
		for(register size_t i=0;i<w;++i) des_buf[di++]=tmp[i];
	}
	if(di<des_buf_len) des_buf[di]=0;
	return di;
}

size_t shinsei_uTF16ToUTF32(char32_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: Size of the source string.
	register size_t si=0;
	register size_t di=0;
	while(si<src_len){
		char32_t cp;
		register const size_t r=(size_t)uTF16CharToUTF32Char(&cp,src+si,src_len-si);
		if(__builtin_expect(!r,0)) return 0;
		si+=r;
		if(di+1>des_buf_len){
			di+=1;
			while(si<src_len){
				register const size_t nr=(size_t)uTF16CharToUTF32Char(&cp,src+si,src_len-si);
				if(!nr) return 0;
				si+=nr;
				di+=1;
			}
			return di;
		}
		des_buf[di++]=cp;
	}
	if(di<des_buf_len) des_buf[di]=0;
	return di;
}

size_t shinsei_uTF8ToUTF32(char32_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: Size of the source string.
	register size_t si=0;
	register size_t di=0;
	while(si<src_len){
		char32_t cp;
		register const size_t r=(size_t)uTF8CharToUTF32Char(&cp,src+si,src_len-si);
		if(__builtin_expect(!r,0)) return 0;
		si+=r;
		if(di+1>des_buf_len){
			di+=1;
			while(si<src_len){
				register const size_t nr=(size_t)uTF8CharToUTF32Char(&cp,src+si,src_len-si);
				if(!nr) return 0;
				si+=nr;
				di+=1;
			}
			return di;
		}
		des_buf[di++]=cp;
	}
	if(di<des_buf_len) des_buf[di]=0;
	return di;
}

size_t shinsei_uTF8ToUTF16(char16_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: Size of the source string.
	register size_t si=0;
	register size_t di=0;
	while(si<src_len){
		char32_t cp;
		register const size_t r=(size_t)uTF8CharToUTF32Char(&cp,src+si,src_len-si);
		if(__builtin_expect(!r,0)) return 0;
		si+=r;
		char16_t tmp[2];
		register const size_t w=(size_t)uTF32CharToUTF16Char(tmp,cp);
		if(di+w>des_buf_len){
			di+=w;
			while(si<src_len){
				register const size_t nr=(size_t)uTF8CharToUTF32Char(&cp,src+si,src_len-si);
				if(!nr) return 0;
				si+=nr;
				di+=(size_t)uTF32CharToUTF16Char(tmp,cp);
			}
			return di;
		}
		for(register size_t i=0;i<w;++i) des_buf[di++]=tmp[i];
	}
	if(di<des_buf_len) des_buf[di]=0;
	return di;
}

size_t shinsei_stringLinesW(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	if(__builtin_expect(!str_len,0)) return 0;
	register size_t i=0;
	register size_t pre=0;
	register size_t res=0;
	while(__builtin_expect(i<str_len,1)){
		if(__builtin_expect(str[i]==L'\n',0)){
			str[i]=L'\0';
			if(i>0&&str[i-1]==L'\r') str[i-1]=L'\0';
			if(res<idx_buf_len){
				idx_buf[res]=pre;
				pre=i+1;
			}
			++res;
		}
		++i;
	}
	if(res<idx_buf_len) idx_buf[res]=pre;
	str[str_len+1]=L'\0';
	return res+1;
}
size_t shinsei_stringLinesCP(const unsigned int code_page,size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	if(__builtin_expect(!str_len,0)) return 0;
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char nl=(char)(ebcdic*0x15+!ebcdic*'\n');
	register const char cr=(char)(ebcdic*0x0D+!ebcdic*'\r');
	register size_t i=0;
	register size_t pre=0;
	register size_t res=0;
	while(__builtin_expect(i<str_len,1)){
		if(__builtin_expect(str[i]==nl,0)){
			str[i]='\0';
			if(i>0&&str[i-1]==cr) str[i-1]='\0';
			if(res<idx_buf_len){
				idx_buf[res]=pre;
				pre=i+1;
			}
			++res;
		}
		++i;
	}
	if(res<idx_buf_len) idx_buf[res]=pre;
	str[str_len+1]='\0';
	return res+1;
}
size_t shinsei_stringLinesU8(size_t*restrict idx_buf,size_t idx_buf_len,char8_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	if(__builtin_expect(!str_len,0)) return 0;
	register size_t i=0;
	register size_t pre=0;
	register size_t res=0;
	while(__builtin_expect(i<str_len,1)){
		if(__builtin_expect(str[i]==u8'\n',0)){
			str[i]=u8'\0';
			if(i>0&&str[i-1]==u8'\r') str[i-1]=u8'\0';
			if(res<idx_buf_len){
				idx_buf[res]=pre;
				pre=i+1;
			}
			++res;
		}
		++i;
	}
	if(res<idx_buf_len) idx_buf[res]=pre;
	str[str_len+1]=u8'\0';
	return res+1;
}
size_t shinsei_stringLinesU16(size_t*restrict idx_buf,size_t idx_buf_len,char16_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	if(__builtin_expect(!str_len,0)) return 0;
	register size_t i=0;
	register size_t pre=0;
	register size_t res=0;
	while(__builtin_expect(i<str_len,1)){
		if(__builtin_expect(str[i]==u'\n',0)){
			str[i]=u'\0';
			if(i>0&&str[i-1]==u'\r') str[i-1]=u'\0';
			if(res<idx_buf_len){
				idx_buf[res]=pre;
				pre=i+1;
			}
			++res;
		}
		++i;
	}
	if(res<idx_buf_len) idx_buf[res]=pre;
	str[str_len+1]=u'\0';
	return res+1;
}
size_t shinsei_stringLinesU32(size_t*restrict idx_buf,size_t idx_buf_len,char32_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	if(__builtin_expect(!str_len,0)) return 0;
	register size_t i=0;
	register size_t pre=0;
	register size_t res=0;
	while(__builtin_expect(i<str_len,1)){
		if(__builtin_expect(str[i]==U'\n',0)){
			str[i]=U'\0';
			if(i>0&&str[i-1]==U'\r') str[i-1]=U'\0';
			if(res<idx_buf_len){
				idx_buf[res]=pre;
				pre=i+1;
			}
			++res;
		}
		++i;
	}
	if(res<idx_buf_len) idx_buf[res]=pre;
	str[str_len+1]=U'\0';
	return res+1;
}

size_t shinsei_findStringsW(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	if(__builtin_expect(!str_len,0)) return 0;
	register size_t i=0;
	register size_t pre=0;
	register size_t res=0;
	while(__builtin_expect(i<str_len,1)){
		if(__builtin_expect(str[i]==L'\0',0)){
			if(res<idx_buf_len){
				idx_buf[res]=pre;
				pre=i+1;
			}
			++res;
			if(__builtin_expect(i+1>=str_len||str[i+1]==L'\0',0)) break;
		}
		++i;
	}
	if(res<idx_buf_len) idx_buf[res]=pre;
	str[str_len+1]=L'\0';
	return res+1;
}
size_t shinsei_findStringsCP(const unsigned int code_page,size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	(void)code_page;
	if(__builtin_expect(!str_len,0)) return 0;
	register size_t i=0;
	register size_t pre=0;
	register size_t res=0;
	while(__builtin_expect(i<str_len,1)){
		if(__builtin_expect(str[i]=='\0',0)){
			if(res<idx_buf_len){
				idx_buf[res]=pre;
				pre=i+1;
			}
			++res;
			if(__builtin_expect(i+1>=str_len||str[i+1]=='\0',0)) break;
		}
		++i;
	}
	if(res<idx_buf_len) idx_buf[res]=pre;
	str[str_len+1]='\0';
	return res+1;
}
size_t shinsei_findStringsU8(size_t*restrict idx_buf,size_t idx_buf_len,char8_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	if(__builtin_expect(!str_len,0)) return 0;
	register size_t i=0;
	register size_t pre=0;
	register size_t res=0;
	while(__builtin_expect(i<str_len,1)){
		if(__builtin_expect(str[i]==u8'\0',0)){
			if(res<idx_buf_len){
				idx_buf[res]=pre;
				pre=i+1;
			}
			++res;
			if(__builtin_expect(i+1>=str_len||str[i+1]==u8'\0',0)) break;
		}
		++i;
	}
	if(res<idx_buf_len) idx_buf[res]=pre;
	str[str_len+1]=u8'\0';
	return res+1;
}
size_t shinsei_findStringsU16(size_t*restrict idx_buf,size_t idx_buf_len,char16_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	if(__builtin_expect(!str_len,0)) return 0;
	register size_t i=0;
	register size_t pre=0;
	register size_t res=0;
	while(__builtin_expect(i<str_len,1)){
		if(__builtin_expect(str[i]==u'\0',0)){
			if(res<idx_buf_len){
				idx_buf[res]=pre;
				pre=i+1;
			}
			++res;
			if(__builtin_expect(i+1>=str_len||str[i+1]==u'\0',0)) break;
		}
		++i;
	}
	if(res<idx_buf_len) idx_buf[res]=pre;
	str[str_len+1]=u'\0';
	return res+1;
}
size_t shinsei_findStringsU32(size_t*restrict idx_buf,size_t idx_buf_len,char32_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// idx_buf_len: Size of the index buffer. 0 or more.
	// str_len: Size of the string buffer. The value is size of string + 2 for 2 terminator 0.
	if(__builtin_expect(!str_len,0)) return 0;
	register size_t i=0;
	register size_t pre=0;
	register size_t res=0;
	while(__builtin_expect(i<str_len,1)){
		if(__builtin_expect(str[i]==U'\0',0)){
			if(res<idx_buf_len){
				idx_buf[res]=pre;
				pre=i+1;
			}
			++res;
			if(__builtin_expect(i+1>=str_len||str[i+1]==U'\0',0)) break;
		}
		++i;
	}
	if(res<idx_buf_len) idx_buf[res]=pre;
	str[str_len+1]=U'\0';
	return res+1;
}

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
_SHINSEI_OS_INLINE static size_t splitStringToPartsCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char delimiter)_SHINSEI_OS_NOEXCEPT{
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
size_t shinsei_splitStringToPartsW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const wchar_t delimiter)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsW(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
}
size_t shinsei_splitStringToPartsCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char delimiter)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsCP(code_page,des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
}
size_t shinsei_splitStringToPartsU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char8_t delimiter)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU8(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
}
size_t shinsei_splitStringToPartsU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char16_t delimiter)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU16(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
}
size_t shinsei_splitStringToPartsU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t part_len,const size_t max_part_cnt,const char32_t delimiter)_SHINSEI_OS_NOEXCEPT{
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return splitStringToPartsU32(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
}

// Int8/UInt8 string converters (W)
void shinsei_uInt8ToStringW(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt8ToBinStringW(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt8ToOctStringW(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt8ToHexStringW(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt8To36BaseStringW(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt8To62BaseStringW(wchar_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	return;
}
void shinsei_int8ToStringW(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int8ToBinStringW(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int8ToOctStringW(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int8ToHexStringW(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int8To36BaseStringW(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int8To62BaseStringW(wchar_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	if(neg) des[0]=L'-';
	return;
}

// Int8/UInt8 string converters (U8)
void shinsei_uInt8ToStringU8(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt8ToBinStringU8(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt8ToOctStringU8(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt8ToHexStringU8(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt8To36BaseStringU8(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt8To62BaseStringU8(char8_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	return;
}
void shinsei_int8ToStringU8(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int8ToBinStringU8(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int8ToOctStringU8(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int8ToHexStringU8(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int8To36BaseStringU8(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int8To62BaseStringU8(char8_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	if(neg) des[0]=u8'-';
	return;
}

// Int8/UInt8 string converters (U16)
void shinsei_uInt8ToStringU16(char16_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt8ToBinStringU16(char16_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt8ToOctStringU16(char16_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt8ToHexStringU16(char16_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt8To36BaseStringU16(char16_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt8To62BaseStringU16(char16_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	return;
}
void shinsei_int8ToStringU16(char16_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int8ToBinStringU16(char16_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int8ToOctStringU16(char16_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int8ToHexStringU16(char16_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int8To36BaseStringU16(char16_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int8To62BaseStringU16(char16_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	if(neg) des[0]=u'-';
	return;
}

// Int8/UInt8 string converters (U32)
void shinsei_uInt8ToStringU32(char32_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt8ToBinStringU32(char32_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt8ToOctStringU32(char32_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt8ToHexStringU32(char32_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt8To36BaseStringU32(char32_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt8To62BaseStringU32(char32_t*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	return;
}
void shinsei_int8ToStringU32(char32_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int8ToBinStringU32(char32_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int8ToOctStringU32(char32_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int8ToHexStringU32(char32_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int8To36BaseStringU32(char32_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int8To62BaseStringU32(char32_t*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	if(neg) des[0]=U'-';
	return;
}

// Int8/UInt8 string converters (CP)
void shinsei_uInt8ToStringCP(const unsigned int code_page,char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt8ToBinStringCP(const unsigned int code_page,char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt8ToOctStringCP(const unsigned int code_page,char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt8ToHexStringCP(const unsigned int code_page,char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt8To36BaseStringCP(const unsigned int code_page,char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt8To62BaseStringCP(const unsigned int code_page,char*const restrict des,const uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast8_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v%62];
		v/=62;
	}
	return;
}
void shinsei_int8ToStringCP(const unsigned int code_page,char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v%10];
		v/=10;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int8ToBinStringCP(const unsigned int code_page,char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v&1];
		v>>=1;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int8ToOctStringCP(const unsigned int code_page,char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v&7];
		v>>=3;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int8ToHexStringCP(const unsigned int code_page,char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v&15];
		v>>=4;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int8To36BaseStringCP(const unsigned int code_page,char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v%36];
		v/=36;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int8To62BaseStringCP(const unsigned int code_page,char*const restrict des,const int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast8_t v=(uint_fast8_t)(neg*(uint_fast8_t)((uint_fast8_t)-src)+!neg*(uint_fast8_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast8_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v%62];
		v/=62;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}

// Int16/UInt16 string converters (W)
void shinsei_uInt16ToStringW(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt16ToBinStringW(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt16ToOctStringW(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt16ToHexStringW(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt16To36BaseStringW(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt16To62BaseStringW(wchar_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	return;
}
void shinsei_int16ToStringW(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int16ToBinStringW(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int16ToOctStringW(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int16ToHexStringW(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int16To36BaseStringW(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int16To62BaseStringW(wchar_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	if(neg) des[0]=L'-';
	return;
}

// Int16/UInt16 string converters (U8)
void shinsei_uInt16ToStringU8(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt16ToBinStringU8(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt16ToOctStringU8(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt16ToHexStringU8(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt16To36BaseStringU8(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt16To62BaseStringU8(char8_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	return;
}
void shinsei_int16ToStringU8(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int16ToBinStringU8(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int16ToOctStringU8(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int16ToHexStringU8(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int16To36BaseStringU8(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int16To62BaseStringU8(char8_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	if(neg) des[0]=u8'-';
	return;
}

// Int16/UInt16 string converters (U16)
void shinsei_uInt16ToStringU16(char16_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt16ToBinStringU16(char16_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt16ToOctStringU16(char16_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt16ToHexStringU16(char16_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt16To36BaseStringU16(char16_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt16To62BaseStringU16(char16_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	return;
}
void shinsei_int16ToStringU16(char16_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int16ToBinStringU16(char16_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int16ToOctStringU16(char16_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int16ToHexStringU16(char16_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int16To36BaseStringU16(char16_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int16To62BaseStringU16(char16_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	if(neg) des[0]=u'-';
	return;
}

// Int16/UInt16 string converters (U32)
void shinsei_uInt16ToStringU32(char32_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt16ToBinStringU32(char32_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt16ToOctStringU32(char32_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt16ToHexStringU32(char32_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt16To36BaseStringU32(char32_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt16To62BaseStringU32(char32_t*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	return;
}
void shinsei_int16ToStringU32(char32_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int16ToBinStringU32(char32_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int16ToOctStringU32(char32_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int16ToHexStringU32(char32_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int16To36BaseStringU32(char32_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int16To62BaseStringU32(char32_t*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	if(neg) des[0]=U'-';
	return;
}

// Int16/UInt16 string converters (CP)
void shinsei_uInt16ToStringCP(const unsigned int code_page,char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt16ToBinStringCP(const unsigned int code_page,char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt16ToOctStringCP(const unsigned int code_page,char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt16ToHexStringCP(const unsigned int code_page,char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt16To36BaseStringCP(const unsigned int code_page,char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt16To62BaseStringCP(const unsigned int code_page,char*const restrict des,const uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast16_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v%62];
		v/=62;
	}
	return;
}
void shinsei_int16ToStringCP(const unsigned int code_page,char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v%10];
		v/=10;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int16ToBinStringCP(const unsigned int code_page,char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v&1];
		v>>=1;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int16ToOctStringCP(const unsigned int code_page,char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v&7];
		v>>=3;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int16ToHexStringCP(const unsigned int code_page,char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v&15];
		v>>=4;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int16To36BaseStringCP(const unsigned int code_page,char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v%36];
		v/=36;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int16To62BaseStringCP(const unsigned int code_page,char*const restrict des,const int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast16_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v%62];
		v/=62;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}

// Int32/UInt32 string converters (W)
void shinsei_uInt32ToStringW(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt32ToBinStringW(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt32ToOctStringW(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt32ToHexStringW(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt32To36BaseStringW(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt32To62BaseStringW(wchar_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	return;
}
void shinsei_int32ToStringW(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast32_t v=(uint_fast32_t)(neg*(uint_fast32_t)((uint_fast32_t)-src)+!neg*(uint_fast32_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int32ToBinStringW(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int32ToOctStringW(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int32ToHexStringW(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int32To36BaseStringW(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int32To62BaseStringW(wchar_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	if(neg) des[0]=L'-';
	return;
}

// Int32/UInt32 string converters (U8)
void shinsei_uInt32ToStringU8(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt32ToBinStringU8(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt32ToOctStringU8(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt32ToHexStringU8(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt32To36BaseStringU8(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt32To62BaseStringU8(char8_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	return;
}
void shinsei_int32ToStringU8(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int32ToBinStringU8(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int32ToOctStringU8(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int32ToHexStringU8(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int32To36BaseStringU8(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int32To62BaseStringU8(char8_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	if(neg) des[0]=u8'-';
	return;
}

// Int32/UInt32 string converters (U16)
void shinsei_uInt32ToStringU16(char16_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt32ToBinStringU16(char16_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt32ToOctStringU16(char16_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt32ToHexStringU16(char16_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt32To36BaseStringU16(char16_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt32To62BaseStringU16(char16_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	return;
}
void shinsei_int32ToStringU16(char16_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int32ToBinStringU16(char16_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int32ToOctStringU16(char16_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int32ToHexStringU16(char16_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int32To36BaseStringU16(char16_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int32To62BaseStringU16(char16_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	if(neg) des[0]=u'-';
	return;
}

// Int32/UInt32 string converters (U32)
void shinsei_uInt32ToStringU32(char32_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt32ToBinStringU32(char32_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt32ToOctStringU32(char32_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt32ToHexStringU32(char32_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt32To36BaseStringU32(char32_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt32To62BaseStringU32(char32_t*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	return;
}
void shinsei_int32ToStringU32(char32_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int32ToBinStringU32(char32_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int32ToOctStringU32(char32_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int32ToHexStringU32(char32_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int32To36BaseStringU32(char32_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int32To62BaseStringU32(char32_t*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	if(neg) des[0]=U'-';
	return;
}

// Int32/UInt32 string converters (CP)
void shinsei_uInt32ToStringCP(const unsigned int code_page,char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt32ToBinStringCP(const unsigned int code_page,char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt32ToOctStringCP(const unsigned int code_page,char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt32ToHexStringCP(const unsigned int code_page,char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt32To36BaseStringCP(const unsigned int code_page,char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt32To62BaseStringCP(const unsigned int code_page,char*const restrict des,const uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast32_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v%62];
		v/=62;
	}
	return;
}
void shinsei_int32ToStringCP(const unsigned int code_page,char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v%10];
		v/=10;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int32ToBinStringCP(const unsigned int code_page,char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v&1];
		v>>=1;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int32ToOctStringCP(const unsigned int code_page,char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v&7];
		v>>=3;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int32ToHexStringCP(const unsigned int code_page,char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v&15];
		v>>=4;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int32To36BaseStringCP(const unsigned int code_page,char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v%36];
		v/=36;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int32To62BaseStringCP(const unsigned int code_page,char*const restrict des,const int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast32_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v%62];
		v/=62;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}

// Int64/UInt64 string converters (W)
void shinsei_uInt64ToStringW(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt64ToBinStringW(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt64ToOctStringW(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt64ToHexStringW(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt64To36BaseStringW(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt64To62BaseStringW(wchar_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]=L'\0';
	v=src;
	while(len--){
		des[len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	return;
}
void shinsei_int64ToStringW(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast64_t v=(uint_fast64_t)(neg*(uint_fast64_t)((uint_fast64_t)-src)+!neg*(uint_fast64_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int64ToBinStringW(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int64ToOctStringW(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int64ToHexStringW(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int64To36BaseStringW(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	if(neg) des[0]=L'-';
	return;
}
void shinsei_int64To62BaseStringW(wchar_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=L'0';
		des[1]=L'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]=L'\0';
	while(v){
		des[--len]=(wchar_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	if(neg) des[0]=L'-';
	return;
}

// Int64/UInt64 string converters (U8)
void shinsei_uInt64ToStringU8(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt64ToBinStringU8(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt64ToOctStringU8(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt64ToHexStringU8(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt64To36BaseStringU8(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt64To62BaseStringU8(char8_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]=u8'\0';
	v=src;
	while(len--){
		des[len]=(char8_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	return;
}
void shinsei_int64ToStringU8(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int64ToBinStringU8(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int64ToOctStringU8(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int64ToHexStringU8(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int64To36BaseStringU8(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	if(neg) des[0]=u8'-';
	return;
}
void shinsei_int64To62BaseStringU8(char8_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u8'0';
		des[1]=u8'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]=u8'\0';
	while(v){
		des[--len]=(char8_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	if(neg) des[0]=u8'-';
	return;
}

// Int64/UInt64 string converters (U16)
void shinsei_uInt64ToStringU16(char16_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt64ToBinStringU16(char16_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt64ToOctStringU16(char16_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt64ToHexStringU16(char16_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt64To36BaseStringU16(char16_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt64To62BaseStringU16(char16_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]=u'\0';
	v=src;
	while(len--){
		des[len]=(char16_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	return;
}
void shinsei_int64ToStringU16(char16_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int64ToBinStringU16(char16_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int64ToOctStringU16(char16_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int64ToHexStringU16(char16_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int64To36BaseStringU16(char16_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	if(neg) des[0]=u'-';
	return;
}
void shinsei_int64To62BaseStringU16(char16_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=u'0';
		des[1]=u'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]=u'\0';
	while(v){
		des[--len]=(char16_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	if(neg) des[0]=u'-';
	return;
}

// Int64/UInt64 string converters (U32)
void shinsei_uInt64ToStringU32(char32_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt64ToBinStringU32(char32_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt64ToOctStringU32(char32_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt64ToHexStringU32(char32_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt64To36BaseStringU32(char32_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt64To62BaseStringU32(char32_t*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	if(!src){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]=U'\0';
	v=src;
	while(len--){
		des[len]=(char32_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	return;
}
void shinsei_int64ToStringU32(char32_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v%10];
		v/=10;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int64ToBinStringU32(char32_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v&1];
		v>>=1;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int64ToOctStringU32(char32_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v&7];
		v>>=3;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int64ToHexStringU32(char32_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v&15];
		v>>=4;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int64To36BaseStringU32(char32_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v%36];
		v/=36;
	}
	if(neg) des[0]=U'-';
	return;
}
void shinsei_int64To62BaseStringU32(char32_t*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=U'0';
		des[1]=U'\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]=U'\0';
	while(v){
		des[--len]=(char32_t)SHINSEI_DIGITS_ASCII[v%62];
		v/=62;
	}
	if(neg) des[0]=U'-';
	return;
}

// Int64/UInt64 string converters (CP)
void shinsei_uInt64ToStringCP(const unsigned int code_page,char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v/=10;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v%10];
		v/=10;
	}
	return;
}
void shinsei_uInt64ToBinStringCP(const unsigned int code_page,char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v>>=1;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v&1];
		v>>=1;
	}
	return;
}
void shinsei_uInt64ToOctStringCP(const unsigned int code_page,char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v>>=3;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v&7];
		v>>=3;
	}
	return;
}
void shinsei_uInt64ToHexStringCP(const unsigned int code_page,char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v>>=4;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v&15];
		v>>=4;
	}
	return;
}
void shinsei_uInt64To36BaseStringCP(const unsigned int code_page,char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v/=36;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v%36];
		v/=36;
	}
	return;
}
void shinsei_uInt64To62BaseStringCP(const unsigned int code_page,char*const restrict des,const uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	if(!src){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=0;
	register uint_fast64_t v=src;
	while(v){
		++len;
		v/=62;
	}
	des[len]='\0';
	v=src;
	while(len--){
		des[len]=(char)digits[v%62];
		v/=62;
	}
	return;
}
void shinsei_int64ToStringCP(const unsigned int code_page,char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t/=10;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v%10];
		v/=10;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int64ToBinStringCP(const unsigned int code_page,char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t>>=1;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v&1];
		v>>=1;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int64ToOctStringCP(const unsigned int code_page,char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t>>=3;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v&7];
		v>>=3;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int64ToHexStringCP(const unsigned int code_page,char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t>>=4;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v&15];
		v>>=4;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int64To36BaseStringCP(const unsigned int code_page,char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t/=36;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v%36];
		v/=36;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}
void shinsei_int64To62BaseStringCP(const unsigned int code_page,char*const restrict des,const int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=shinsei_isEBCDICCodePage(code_page);
	register const char*const digits=(const char*)(ebcdic*(uintptr_t)SHINSEI_DIGITS_EBCDIC+!ebcdic*(uintptr_t)SHINSEI_DIGITS_ASCII);
	register const bool neg=src<0;
	register uint_fast16_t v=(uint_fast16_t)(neg*(uint_fast16_t)((uint_fast16_t)-src)+!neg*(uint_fast16_t)src);
	if(!v){
		des[0]=(char)digits[0];
		des[1]='\0';
		return;
	}
	register size_t len=neg;
	register uint_fast64_t t=v;
	while(t){
		++len;
		t/=62;
	}
	des[len]='\0';
	while(v){
		des[--len]=(char)digits[v%62];
		v/=62;
	}
	if(neg) des[0]=(char)(ebcdic*0x60+!ebcdic*'-');
	return;
}

// strLen
size_t shinsei_strLenW(const wchar_t*const restrict str)_SHINSEI_OS_NOEXCEPT{
	return wcslen(str);
}

size_t shinsei_strLenU8(const char8_t*const restrict str)_SHINSEI_OS_NOEXCEPT{
	return __builtin_strlen((const char*)str);
}

size_t shinsei_strLenU16(const char16_t*const restrict str)_SHINSEI_OS_NOEXCEPT{
#ifndef _SHINSEI_WCHAR_U32
	return wcslen((const wchar_t*)str);
#else
	register const char16_t* ptr=str;
	while(*ptr) ++ptr;
	return (size_t)(ptr-str);
#endif
}

size_t shinsei_strLenU32(const char32_t*const restrict str)_SHINSEI_OS_NOEXCEPT{
#ifdef _SHINSEI_WCHAR_U32
	return wcslen((const wchar_t*)str);
#else
	register const char32_t* ptr=str;
	while(*ptr) ++ptr;
	return (size_t)(ptr-str);
#endif
}

size_t shinsei_strLenCP(const unsigned int code_page,const char*const restrict str)_SHINSEI_OS_NOEXCEPT{
	(void)code_page;
	return __builtin_strlen(str);
}

void shinsei_strCpyW(wchar_t*const restrict des,const wchar_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	__builtin_memcpy(des,src,len*sizeof(wchar_t));
	des[len]=0;
	return;
}
void shinsei_strCpyCP(const unsigned int code_page,char*const restrict des,const char*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	(void)code_page;
	__builtin_memcpy(des,src,len*sizeof(char));
	des[len]=0;
	return;
}
void shinsei_strCpyU8(char8_t*const restrict des,const char8_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	__builtin_memcpy(des,src,len*sizeof(char8_t));
	des[len]=0;
	return;
}
void shinsei_strCpyU16(char16_t*const restrict des,const char16_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	__builtin_memcpy(des,src,len*sizeof(char16_t));
	des[len]=0;
	return;
}
void shinsei_strCpyU32(char32_t*const restrict des,const char32_t*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	__builtin_memcpy(des,src,len*sizeof(char32_t));
	des[len]=0;
	return;
}

// strCat
size_t shinsei_strCatW(wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	__builtin_memcpy(des+des_len,src,src_len*sizeof(wchar_t));
	register const size_t res=des_len+src_len;
	des[res]=0;
	return res;
}
size_t shinsei_strCatCP(const unsigned int code_page,char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	(void)code_page;
	__builtin_memcpy(des+des_len,src,src_len*sizeof(char));
	register const size_t res=des_len+src_len;
	des[res]=0;
	return res;
}
size_t shinsei_strCatU8(char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	__builtin_memcpy(des+des_len,src,src_len*sizeof(char8_t));
	register const size_t res=des_len+src_len;
	des[res]=0;
	return res;
}
size_t shinsei_strCatU16(char16_t*const restrict des,const size_t des_len,const char16_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	__builtin_memcpy(des+des_len,src,src_len*sizeof(char16_t));
	register const size_t res=des_len+src_len;
	des[res]=0;
	return res;
}
size_t shinsei_strCatU32(char32_t*const restrict des,const size_t des_len,const char32_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	__builtin_memcpy(des+des_len,src,src_len*sizeof(char32_t));
	register const size_t res=des_len+src_len;
	des[res]=0;
	return res;
}

// strCmp
int shinsei_strCmpW(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	register const size_t min_len=(des_len<src_len)*des_len+(des_len>=src_len)*src_len;
	register const int res=__builtin_memcmp(des,src,min_len*sizeof(wchar_t));
	return (res>0)-(res<0)+!res*((des_len>src_len)-(des_len<src_len));
}
int shinsei_strCmpCP(const unsigned int code_page,const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	(void)code_page;
	register const size_t min_len=(des_len<src_len)*des_len+(des_len>=src_len)*src_len;
	register const int res=__builtin_memcmp(des,src,min_len*sizeof(char));
	return (res>0)-(res<0)+!res*((des_len>src_len)-(des_len<src_len));
}
int shinsei_strCmpU8(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	register const size_t min_len=(des_len<src_len)*des_len+(des_len>=src_len)*src_len;
	register const int res=__builtin_memcmp(des,src,min_len*sizeof(char8_t));
	return (res>0)-(res<0)+!res*((des_len>src_len)-(des_len<src_len));
}
int shinsei_strCmpU16(const char16_t*const restrict des,const size_t des_len,const char16_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	register const size_t min_len=(des_len<src_len)*des_len+(des_len>=src_len)*src_len;
	register const int res=__builtin_memcmp(des,src,min_len*sizeof(char16_t));
	return (res>0)-(res<0)+!res*((des_len>src_len)-(des_len<src_len));
}
int shinsei_strCmpU32(const char32_t*const restrict des,const size_t des_len,const char32_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	register const size_t min_len=(des_len<src_len)*des_len+(des_len>=src_len)*src_len;
	register const int res=__builtin_memcmp(des,src,min_len*sizeof(char32_t));
	return (res>0)-(res<0)+!res*((des_len>src_len)-(des_len<src_len));
}

// strChr
size_t shinsei_strChrW(const wchar_t*const restrict des,const size_t des_len,const wchar_t src)_SHINSEI_OS_NOEXCEPT{
	register const void* res=(const void*)(size_t)wmemchr((const wchar_t*)des,src,des_len);
	return (res==nullptr)*SIZE_MAX+(res!=nullptr)*(size_t)((const wchar_t*)res-des);
}
size_t shinsei_strChrCP(const unsigned int code_page,const char*const restrict des,const size_t des_len,const char src)_SHINSEI_OS_NOEXCEPT{
	(void)code_page;
	register const void* res=__builtin_memchr(des,src,des_len);
	return (res==nullptr)*SIZE_MAX+(res!=nullptr)*(size_t)((const char*)res-des);
}
size_t shinsei_strChrU8(const char8_t*const restrict des,const size_t des_len,const char8_t src)_SHINSEI_OS_NOEXCEPT{
	register const void* res=__builtin_memchr(des,src,des_len);
	return (res==nullptr)*SIZE_MAX+(res!=nullptr)*(size_t)((const char8_t*)res-des);
}
size_t shinsei_strChrU16(const char16_t*const restrict des,const size_t des_len,const char16_t src)_SHINSEI_OS_NOEXCEPT{
#ifndef _SHINSEI_WCHAR_U32
	register const void* res=(const void*)(size_t)wmemchr((const wchar_t*)des,src,des_len);
	return (res==nullptr)*SIZE_MAX+(res!=nullptr)*(size_t)((const char16_t*)res-des);
#else
	for(register size_t i=0;i<des_len;++i){
		if(des[i]==src) return i;
	}
	return SIZE_MAX;
#endif
}
size_t shinsei_strChrU32(const char32_t*const restrict des,const size_t des_len,const char32_t src)_SHINSEI_OS_NOEXCEPT{
#ifdef _SHINSEI_WCHAR_U32
	register const void* res=(const void*)(size_t)__builtin_wmemchr((const wchar_t*)des,src,des_len);
	return (res==nullptr)*SIZE_MAX+(res!=nullptr)*(size_t)((const char32_t*)res-des);
#else
	for(register size_t i=0;i<des_len;++i){
		if(des[i]==src) return i;
	}
	return SIZE_MAX;
#endif
}

// strStr
size_t shinsei_strStrW(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(__builtin_expect(des_len<src_len,0)) return SIZE_MAX;
	register const size_t limit=des_len-src_len;
	for(register size_t i=0;i<=limit;++i){
		if(!__builtin_memcmp(des+i,src,src_len*sizeof(wchar_t))) return i;
	}
	return SIZE_MAX;
}
size_t shinsei_strStrCP(const unsigned int code_page,const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	(void)code_page;
	if(__builtin_expect(!src_len,0)) return 0;
	if(__builtin_expect(des_len<src_len,0)) return SIZE_MAX;
	register const size_t limit=des_len-src_len;
	for(register size_t i=0;i<=limit;++i){
		if(!__builtin_memcmp(des+i,src,src_len*sizeof(char))) return i;
	}
	return SIZE_MAX;
}
size_t shinsei_strStrU8(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(__builtin_expect(des_len<src_len,0)) return SIZE_MAX;
	register const size_t limit=des_len-src_len;
	for(register size_t i=0;i<=limit;++i){
		if(!__builtin_memcmp(des+i,src,src_len*sizeof(char8_t))) return i;
	}
	return SIZE_MAX;
}
size_t shinsei_strStrU16(const char16_t*const restrict des,const size_t des_len,const char16_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(__builtin_expect(des_len<src_len,0)) return SIZE_MAX;
	register const size_t limit=des_len-src_len;
	for(register size_t i=0;i<=limit;++i){
		if(!__builtin_memcmp(des+i,src,src_len*sizeof(char16_t))) return i;
	}
	return SIZE_MAX;
}
size_t shinsei_strStrU32(const char32_t*const restrict des,const size_t des_len,const char32_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(__builtin_expect(des_len<src_len,0)) return SIZE_MAX;
	register const size_t limit=des_len-src_len;
	for(register size_t i=0;i<=limit;++i){
		if(!__builtin_memcmp(des+i,src,src_len*sizeof(char32_t))) return i;
	}
	return SIZE_MAX;
}

// strKMP
size_t shinsei_strKMPW(const wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(__builtin_expect(des_len<src_len,0)) return SIZE_MAX;
	if(__builtin_expect(buf_len<src_len,0)) return SIZE_MAX;
	buf[0]=0;
	register size_t len=0;
	for(register size_t i=1;i<src_len;){
		if(src[i]==src[len]) buf[i++]=++len;
		else if(len) len=buf[len-1];
		else buf[i++]=0;
	}
	register size_t i=0,j=0;
	while(i<des_len){
		if(src[j]==des[i]){
			++i;
			++j;
		}
		if(j==src_len) return i-j;
		else if(i<des_len&&src[j]!=des[i]){
			if(j) j=buf[j-1];
			else ++i;
		}
	}
	return SIZE_MAX;
}
size_t shinsei_strKMPCP(const unsigned int code_page,const char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT{
	(void)code_page;
	if(__builtin_expect(!src_len,0)) return 0;
	if(__builtin_expect(des_len<src_len,0)) return SIZE_MAX;
	if(__builtin_expect(buf_len<src_len,0)) return SIZE_MAX;
	buf[0]=0;
	register size_t len=0;
	for(register size_t i=1;i<src_len;){
		if(src[i]==src[len]) buf[i++]=++len;
		else if(len) len=buf[len-1];
		else buf[i++]=0;
	}
	register size_t i=0,j=0;
	while(i<des_len){
		if(src[j]==des[i]){
			++i;
			++j;
		}
		if(j==src_len) return i-j;
		else if(i<des_len&&src[j]!=des[i]){
			if(j) j=buf[j-1];
			else ++i;
		}
	}
	return SIZE_MAX;
}
size_t shinsei_strKMPU8(const char8_t*const restrict des,const size_t des_len,const char8_t*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(__builtin_expect(des_len<src_len,0)) return SIZE_MAX;
	if(__builtin_expect(buf_len<src_len,0)) return SIZE_MAX;
	buf[0]=0;
	register size_t len=0;
	for(register size_t i=1;i<src_len;){
		if(src[i]==src[len]) buf[i++]=++len;
		else if(len) len=buf[len-1];
		else buf[i++]=0;
	}
	register size_t i=0,j=0;
	while(i<des_len){
		if(src[j]==des[i]){
			++i;
			++j;
		}
		if(j==src_len) return i-j;
		else if(i<des_len&&src[j]!=des[i]){
			if(j) j=buf[j-1];
			else ++i;
		}
	}
	return SIZE_MAX;
}
size_t shinsei_strKMPU16(const char16_t*const restrict des,const size_t des_len,const char16_t*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(__builtin_expect(des_len<src_len,0)) return SIZE_MAX;
	if(__builtin_expect(buf_len<src_len,0)) return SIZE_MAX;
	buf[0]=0;
	register size_t len=0;
	for(register size_t i=1;i<src_len;){
		if(src[i]==src[len]) buf[i++]=++len;
		else if(len) len=buf[len-1];
		else buf[i++]=0;
	}
	register size_t i=0,j=0;
	while(i<des_len){
		if(src[j]==des[i]){
			++i;
			++j;
		}
		if(j==src_len) return i-j;
		else if(i<des_len&&src[j]!=des[i]){
			if(j) j=buf[j-1];
			else ++i;
		}
	}
	return SIZE_MAX;
}
size_t shinsei_strKMPU32(const char32_t*const restrict des,const size_t des_len,const char32_t*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(__builtin_expect(des_len<src_len,0)) return SIZE_MAX;
	if(__builtin_expect(buf_len<src_len,0)) return SIZE_MAX;
	buf[0]=0;
	register size_t len=0;
	for(register size_t i=1;i<src_len;){
		if(src[i]==src[len]) buf[i++]=++len;
		else if(len) len=buf[len-1];
		else buf[i++]=0;
	}
	register size_t i=0,j=0;
	while(i<des_len){
		if(src[j]==des[i]){
			++i;
			++j;
		}
		if(j==src_len) return i-j;
		else if(i<des_len&&src[j]!=des[i]){
			if(j) j=buf[j-1];
			else ++i;
		}
	}
	return SIZE_MAX;
}

// string_t

// [Internal, const] Check if elements are inlined
_SHINSEI_OS_INLINE static bool str_inlined(const shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}

// [Internal, const] Get the element data
_SHINSEI_OS_INLINE static char* str_data(const shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return (char*)((uintptr_t)&this->data*str_inlined(this)+!str_inlined(this)*(uintptr_t)this->data);
}

// [Internal] Set Null Terminator
_SHINSEI_OS_INLINE static void str_setNull(shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	__builtin_memset(str_data(this)+this->size*this->char_size,0,this->char_size);
}

// [Internal] Expand capacity
_SHINSEI_OS_INLINE static bool str_expand(shinsei_string_t*const restrict this,const size_t more_cap)_SHINSEI_OS_NOEXCEPT{
	if(str_inlined(this)){
		this->cap+=more_cap;
		return true;
	}
	register char*const ptr=(char*)__builtin_realloc(this->data,(this->cap+more_cap+1)*this->char_size);
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap+=more_cap;
	this->data=ptr;
	return true;
}

// [Internal] Shrink capacity
_SHINSEI_OS_INLINE static bool str_shrink(shinsei_string_t*const restrict this,const size_t less_cap)_SHINSEI_OS_NOEXCEPT{
	if(str_inlined(this)){
		this->cap-=less_cap;
		return true;
	}
	register char*const ptr=(char*)__builtin_realloc(this->data,(this->cap-less_cap+1)*this->char_size);
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap-=less_cap;
	this->data=ptr;
	return true;
}

// [Internal] Default constructor
_SHINSEI_OS_INLINE static bool str_con(shinsei_string_t*const restrict this,const size_t char_size)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	this->code_page=0;
	this->size=0;
	this->cap=shinsei_string_t_DEF_CAP;
	this->char_size=char_size;
	this->data=(char*)__builtin_malloc((this->cap+1)*this->char_size);
	if(__builtin_expect(this->data==nullptr,0)) return false;
	str_setNull(this);
	return true;
}

// [Internal] Assign constructor
_SHINSEI_OS_INLINE static bool str_asAssign(shinsei_string_t*const restrict this,const shinsei_string_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl;
	this->code_page=src->code_page;
	this->size=src->size;
	this->cap=src->cap;
	this->char_size=src->char_size;
	if(!str_inlined(this)){
		this->data=(char*)__builtin_malloc((this->cap+1)*this->char_size);
		if(__builtin_expect(this->data==nullptr,0)) return false;
	}
	__builtin_memcpy(str_data(this),str_data(src),(this->size+1)*this->char_size);
	return true;
}

// [Internal] Move constructor
_SHINSEI_OS_INLINE static void str_asMove(shinsei_string_t*const restrict this,shinsei_string_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl;
	this->code_page=src->code_page;
	this->size=src->size;
	this->cap=src->cap;
	this->char_size=src->char_size;
	if(str_inlined(src)){
		__builtin_memcpy(str_data(this),str_data(src),(this->size+1)*this->char_size);
	}
	else this->data=src->data;
	src->ctrl=0;
	src->code_page=0;
	src->size=0;
	src->cap=0;
	src->data=nullptr;
	return;
}

// [Internal] Free
_SHINSEI_OS_INLINE static void str_freeData(shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	__builtin_free(this->data);
	return;
}

// [Internal] Batch Add
_SHINSEI_OS_INLINE static bool str_pushBackArray(shinsei_string_t*const restrict this,const void*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(!len) return true;
	if(this->size+len>this->cap){
		if(str_inlined(this)) return false;
		register size_t needed=(this->cap<<1>=shinsei_string_t_DEF_CAP)*this->cap+(this->cap<<1<shinsei_string_t_DEF_CAP)*(shinsei_string_t_DEF_CAP-this->cap);
		needed=(needed<=len)*len+!(needed<=len)*needed;
		if(!str_expand(this,needed)) return false;
	}
	__builtin_memcpy(str_data(this)+this->size*this->char_size,arr,len*this->char_size);
	this->size+=len;
	str_setNull(this);
	return true;
}

_SHINSEI_OS_INLINE static bool str_pushBackChar(shinsei_string_t*const restrict this,const void*const restrict val,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
	if(!cnt) return true;
	if(this->size+cnt>this->cap){
		if(str_inlined(this)) return false;
		register size_t needed=(this->cap<<1>=shinsei_string_t_DEF_CAP)*this->cap+(this->cap<<1<shinsei_string_t_DEF_CAP)*(shinsei_string_t_DEF_CAP-this->cap);
		needed=(needed<=cnt)*cnt+!(needed<=cnt)*needed;
		if(!str_expand(this,needed)) return false;
	}
	register char*const dst=str_data(this);
	for(register size_t i=0;i<cnt;++i) __builtin_memcpy(dst+(this->size+i)*this->char_size,val,this->char_size);
	this->size+=cnt;
	str_setNull(this);
	return true;
}

// [Internal] Batch Remove
_SHINSEI_OS_INLINE static void str_popBackArray(shinsei_string_t*const restrict this,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
	this->size-=cnt;
	str_setNull(this);
	if(str_inlined(this)) return;
	if(__builtin_expect(this->size>=this->cap>>2,1)) return;
	str_shrink(this,(this->cap>>1>=shinsei_string_t_DEF_CAP)*(this->cap>>1)+(this->cap>>1<shinsei_string_t_DEF_CAP)*(this->cap-shinsei_string_t_DEF_CAP));
}

// [Internal] Insert/Erase
_SHINSEI_OS_INLINE static bool str_insertArray(shinsei_string_t*const restrict this,const size_t idx,const void*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(!len) return true;
	if(this->size+len>this->cap){
		if(str_inlined(this)) return false;
		register size_t needed=(this->cap<<1>=shinsei_string_t_DEF_CAP)*this->cap+(this->cap<<1<shinsei_string_t_DEF_CAP)*(shinsei_string_t_DEF_CAP-this->cap);
		needed=(needed<=len)*len+!(needed<=len)*needed;
		if(!str_expand(this,needed)) return false;
	}
	if(__builtin_expect(idx<this->size,1)){
		__builtin_memmove(str_data(this)+(idx+len)*this->char_size,str_data(this)+idx*this->char_size,(this->size-idx)*this->char_size);
	}
	__builtin_memcpy(str_data(this)+idx*this->char_size,src,len*this->char_size);
	this->size+=len;
	str_setNull(this);
	return true;
}

_SHINSEI_OS_INLINE static bool str_insertChar(shinsei_string_t*const restrict this,const size_t idx,const void*const restrict val,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
	if(!cnt) return true;
	if(this->size+cnt>this->cap){
		if(str_inlined(this)) return false;
		register size_t needed=(this->cap<<1>=shinsei_string_t_DEF_CAP)*this->cap+(this->cap<<1<shinsei_string_t_DEF_CAP)*(shinsei_string_t_DEF_CAP-this->cap);
		needed=(needed<=cnt)*cnt+!(needed<=cnt)*needed;
		if(!str_expand(this,needed)) return false;
	}
	if(__builtin_expect(idx<this->size,1)){
		__builtin_memmove(str_data(this)+(idx+cnt)*this->char_size,str_data(this)+idx*this->char_size,(this->size-idx)*this->char_size);
	}
	register char*const dst=str_data(this);
	for(register size_t i=0;i<cnt;++i) __builtin_memcpy(dst+(idx+i)*this->char_size,val,this->char_size);
	this->size+=cnt;
	str_setNull(this);
	return true;
}

_SHINSEI_OS_INLINE static void str_eraseArray(shinsei_string_t*const restrict this,const size_t idx,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(!len) return;
	if(__builtin_expect(idx+len<this->size,1)){
		__builtin_memmove(str_data(this)+idx*this->char_size,str_data(this)+(idx+len)*this->char_size,(this->size-idx-len)*this->char_size);
	}
	this->size-=len;
	str_setNull(this);
	if(str_inlined(this)) return;
	if(__builtin_expect(this->size>=this->cap>>2,1)) return;
	str_shrink(this,(this->cap>>1>=shinsei_string_t_DEF_CAP)*(this->cap>>1)+(this->cap>>1<shinsei_string_t_DEF_CAP)*(this->cap-shinsei_string_t_DEF_CAP));
}

// [Internal] Constructors
_SHINSEI_OS_INLINE static bool str_conCapacity(shinsei_string_t*const restrict this,const size_t cap,const size_t char_size)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	this->code_page=0;
	this->size=0;
	this->cap=cap;
	this->char_size=char_size;
	this->data=(char*)__builtin_malloc((this->cap+1)*this->char_size);
	if(__builtin_expect(this->data==nullptr,0)) return false;
	str_setNull(this);
	return true;
}

_SHINSEI_OS_INLINE static bool str_asElement(shinsei_string_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t char_size)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	this->code_page=0;
	this->size=cnt;
	this->cap=cnt+!cnt*shinsei_string_t_DEF_CAP;
	this->char_size=char_size;
	this->data=(char*)__builtin_malloc((this->cap+1)*this->char_size);
	if(__builtin_expect(this->data==nullptr,0)) return false;
	register char*const dst=str_data(this);
	for(register size_t i=0;i<cnt;++i) __builtin_memcpy(dst+i*char_size,val,char_size);
	str_setNull(this);
	return true;
}

_SHINSEI_OS_INLINE static void str_inl(shinsei_string_t*const restrict this,const size_t cap,const size_t char_size)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->code_page=0;
	this->size=0;
	this->cap=cap;
	this->char_size=char_size;
	str_setNull(this);
	return;
}

_SHINSEI_OS_INLINE static bool str_asArray(shinsei_string_t*const restrict this,const void*const restrict arr,const size_t len,const size_t char_size)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	this->code_page=0;
	this->size=len;
	this->cap=len+!len*shinsei_string_t_DEF_CAP;
	this->char_size=char_size;
	this->data=(char*)__builtin_malloc((this->cap+1)*this->char_size);
	if(__builtin_expect(this->data==nullptr,0)) return false;
	__builtin_memcpy(str_data(this),arr,len*char_size);
	str_setNull(this);
	return true;
}

// Exports
shinsei_string_t* shinsei_string_t_con(const size_t char_size)_SHINSEI_OS_NOEXCEPT{
	register shinsei_string_t*const this=(shinsei_string_t*const)__builtin_malloc(sizeof(shinsei_string_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!str_con(this,char_size),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}

shinsei_string_t* shinsei_string_t_conCapacity(const size_t cap,const size_t char_size)_SHINSEI_OS_NOEXCEPT{
	register shinsei_string_t*const this=(shinsei_string_t*const)__builtin_malloc(sizeof(shinsei_string_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!str_conCapacity(this,cap,char_size),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}

shinsei_string_t* shinsei_string_t_conAssign(const shinsei_string_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	register shinsei_string_t*const this=(shinsei_string_t*const)__builtin_malloc(sizeof(shinsei_string_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!str_asAssign(this,src),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}

shinsei_string_t* shinsei_string_t_conMove(shinsei_string_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	register shinsei_string_t*const this=(shinsei_string_t*const)__builtin_malloc(sizeof(shinsei_string_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	str_asMove(this,src);
	return this;
}

shinsei_string_t* shinsei_string_t_conChar(const void*const restrict ch,const size_t repeat_cnt,const size_t char_size)_SHINSEI_OS_NOEXCEPT{
	register shinsei_string_t*const this=(shinsei_string_t*const)__builtin_malloc(sizeof(shinsei_string_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!str_asElement(this,ch,repeat_cnt,char_size),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}

shinsei_string_t* shinsei_string_t_conSubstr(const shinsei_string_t*const restrict src,const size_t idx,const size_t len)_SHINSEI_OS_NOEXCEPT{
	register const size_t safe_idx=(idx>src->size)*src->size+(idx<=src->size)*idx;
	register const size_t real_len=(safe_idx+len>src->size)*(src->size-safe_idx)+(safe_idx+len<=src->size)*len;
	register shinsei_string_t*const this=(shinsei_string_t*const)__builtin_malloc(sizeof(shinsei_string_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!str_conCapacity(this,real_len,src->char_size),0)){
		__builtin_free(this);
		return nullptr;
	}
	str_pushBackArray(this,str_data(src)+safe_idx*src->char_size,real_len);
	this->code_page=src->code_page;
	this->ctrl=(src->ctrl&_SHINSEI_CTRL_CODE_PAGE)|(this->ctrl&~_SHINSEI_CTRL_CODE_PAGE);
	return this;
}

void shinsei_string_t_freeData(shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	str_freeData(this);
	return;
}

void shinsei_string_t_dec(shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(!str_inlined(this)&&this->data!=nullptr) str_freeData(this);
	__builtin_free(this);
	return;
}

bool shinsei_string_t_expand(shinsei_string_t*const restrict this,const size_t more_cap)_SHINSEI_OS_NOEXCEPT{
	return str_expand(this,more_cap);
}

bool shinsei_string_t_shrink(shinsei_string_t*const restrict this,const size_t less_cap)_SHINSEI_OS_NOEXCEPT{
	return str_shrink(this,less_cap);
}

bool shinsei_string_t_reserve(shinsei_string_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT{
	if(str_inlined(this)){
		this->cap=cap;
		return true;
	}
	register char*const ptr=(char*)__builtin_realloc(this->data,(cap+1)*this->char_size);
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap=cap;
	this->data=ptr;
	return true;
}

bool shinsei_string_t_shrinkToFit(shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(str_inlined(this)){
		this->cap=this->size;
		return true;
	}
	register char*const ptr=(char*)__builtin_realloc(this->data,(this->size+1)*this->char_size);
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap=this->size;
	this->data=ptr;
	return true;
}

bool shinsei_string_t_empty(const shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return !this->size;
}

size_t shinsei_string_t_size(const shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->size;
}

size_t shinsei_string_t_length(const shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->size;
}

size_t shinsei_string_t_capacity(const shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->cap;
}

void* shinsei_string_t_at(const shinsei_string_t*const restrict this,const size_t idx)_SHINSEI_OS_NOEXCEPT{
	return str_data(this)+idx*this->char_size;
}

void* shinsei_string_t_front(const shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return str_data(this);
}

void* shinsei_string_t_back(const shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return str_data(this)+(this->size-1)*this->char_size;
}

void* shinsei_string_t_data(const shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return str_data(this);
}

void* shinsei_string_t_cStr(const shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return str_data(this);
}

bool shinsei_string_t_assign(shinsei_string_t*const restrict this,const shinsei_string_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	if(!str_inlined(this)&&str_inlined(src)){
		if(this->data!=nullptr) str_freeData(this);
	}
	else if(!str_inlined(this)&&!str_inlined(src)){
		if(this->cap!=src->cap){
			register char* ptr=(char*)__builtin_realloc(this->data,(src->cap+1)*this->char_size);
			if(__builtin_expect(ptr==nullptr,0)) return false;
			this->data=ptr;
		}
	}
	else if(str_inlined(this)&&!str_inlined(src)){
		this->data=(char*)__builtin_malloc((src->cap+1)*this->char_size);
		if(__builtin_expect(this->data==nullptr,0)) return false;
	}
	this->ctrl=src->ctrl;
	this->code_page=src->code_page;
	this->size=src->size;
	this->cap=src->cap;
	__builtin_memcpy(str_data(this),str_data(src),(this->size+1)*this->char_size);
	return true;
}

bool shinsei_string_t_assignRaw(shinsei_string_t*const restrict this,const void*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(this->cap<len){
		if(!shinsei_string_t_reserve(this,len)) return false;
	}
	this->size=len;
	__builtin_memcpy(str_data(this),src,len*this->char_size);
	str_setNull(this);
	return true;
}

bool shinsei_string_t_assignChar(shinsei_string_t*const restrict this,const void*const restrict ch,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(this->cap<len){
		if(!shinsei_string_t_reserve(this,len)) return false;
	}
	this->size=len;
	register char*const dst=str_data(this);
	for(register size_t i=0;i<len;++i) __builtin_memcpy(dst+i*this->char_size,ch,this->char_size);
	str_setNull(this);
	return true;
}

bool shinsei_string_t_append(shinsei_string_t*const restrict this,const shinsei_string_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	return str_pushBackArray(this,str_data(src),src->size);
}

bool shinsei_string_t_appendRaw(shinsei_string_t*const restrict this,const void*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return str_pushBackArray(this,src,len);
}

bool shinsei_string_t_appendChar(shinsei_string_t*const restrict this,const void*const restrict ch,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return str_pushBackChar(this,ch,len);
}

bool shinsei_string_t_pushBack(shinsei_string_t*const restrict this,const void*const restrict ch)_SHINSEI_OS_NOEXCEPT{
	return str_pushBackChar(this,ch,1);
}

bool shinsei_string_t_pushBackArray(shinsei_string_t*const restrict this,const void*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return str_pushBackArray(this,src,len);
}

bool shinsei_string_t_pushBackChar(shinsei_string_t*const restrict this,const void*const restrict ch,const size_t repeat_cnt)_SHINSEI_OS_NOEXCEPT{
	return str_pushBackChar(this,ch,repeat_cnt);
}

void shinsei_string_t_popBack(shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	str_popBackArray(this,1);
	return;
}

void shinsei_string_t_popBackArray(shinsei_string_t*const restrict this,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
	str_popBackArray(this,cnt);
	return;
}

bool shinsei_string_t_insert(shinsei_string_t*const restrict this,const size_t idx,const void*const restrict ch)_SHINSEI_OS_NOEXCEPT{
	return str_insertChar(this,idx,ch,1);
}

bool shinsei_string_t_insertArray(shinsei_string_t*const restrict this,const size_t idx,const void*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return str_insertArray(this,idx,src,len);
}

bool shinsei_string_t_insertChar(shinsei_string_t*const restrict this,const size_t idx,const void*const restrict ch,const size_t repeat_cnt)_SHINSEI_OS_NOEXCEPT{
	return str_insertChar(this,idx,ch,repeat_cnt);
}

void shinsei_string_t_erase(shinsei_string_t*const restrict this,const size_t idx)_SHINSEI_OS_NOEXCEPT{
	str_eraseArray(this,idx,1);
	return;
}

void shinsei_string_t_eraseArray(shinsei_string_t*const restrict this,const size_t idx,const size_t len)_SHINSEI_OS_NOEXCEPT{
	str_eraseArray(this,idx,len);
	return;
}

size_t shinsei_string_t_find(const shinsei_string_t*const restrict this,const void*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(__builtin_expect(this->size<src_len,0)) return SIZE_MAX;
	register const size_t limit=this->size-src_len;
	register const char*const ptr=str_data(this);
	for(register size_t i=0;i<=limit;++i){
		if(!__builtin_memcmp(ptr+i*this->char_size,src,src_len*this->char_size)) return i;
	}
	return SIZE_MAX;
}

size_t shinsei_string_t_findChar(const shinsei_string_t*const restrict this,const void*const restrict ch)_SHINSEI_OS_NOEXCEPT{
	register const char*const ptr=str_data(this);
	for(register size_t i=0;i<this->size;++i){
		if(!__builtin_memcmp(ptr+i*this->char_size,ch,this->char_size)) return i;
	}
	return SIZE_MAX;
}

size_t shinsei_string_t_kMP(const shinsei_string_t*const restrict this,const void*const restrict src,const size_t src_len,size_t*const restrict buf,const size_t buf_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	if(__builtin_expect(this->size<src_len,0)) return SIZE_MAX;
	if(__builtin_expect(buf_len<src_len,0)) return SIZE_MAX;
	buf[0]=0;
	register size_t len=0;
	register const char*const s_ptr=(const char*)src;
	for(register size_t i=1;i<src_len;){
		if(!__builtin_memcmp(s_ptr+i*this->char_size,s_ptr+len*this->char_size,this->char_size)) buf[i++]=++len;
		else if(len) len=buf[len-1];
		else buf[i++]=0;
	}
	register size_t i=0,j=0;
	register const char*const ptr=str_data(this);
	while(i<this->size){
		if(!__builtin_memcmp(s_ptr+j*this->char_size,ptr+i*this->char_size,this->char_size)){
			++i;
			++j;
		}
		if(j==src_len) return i-j;
		else if(i<this->size&&__builtin_memcmp(s_ptr+j*this->char_size,ptr+i*this->char_size,this->char_size)){
			if(j) j=buf[j-1];
			else ++i;
		}
	}
	return SIZE_MAX;
}

int shinsei_string_t_compare(const shinsei_string_t*const restrict this,const void*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	register const size_t min_len=(this->size<src_len)*this->size+(this->size>=src_len)*src_len;
	register const int res=__builtin_memcmp(str_data(this),src,min_len*this->char_size);
	return (res>0)-(res<0)+!res*((this->size>src_len)-(this->size<src_len));
}

shinsei_string_t* shinsei_string_t_substr(const shinsei_string_t*const restrict this,const size_t idx,const size_t len)_SHINSEI_OS_NOEXCEPT{
	register const size_t safe_idx=(idx>this->size)*this->size+(idx<=this->size)*idx;
	register const size_t real_len=(safe_idx+len>this->size)*(this->size-safe_idx)+(safe_idx+len<=this->size)*len;
	register shinsei_string_t*const res=(shinsei_string_t*const)__builtin_malloc(sizeof(shinsei_string_t));
	if(__builtin_expect(res==nullptr,0)) return nullptr;
	if(__builtin_expect(!str_conCapacity(res,real_len,this->char_size),0)){
		__builtin_free(res);
		return nullptr;
	}
	str_pushBackArray(res,str_data(this)+safe_idx*this->char_size,real_len);
	res->code_page=this->code_page;
	res->ctrl=(this->ctrl&_SHINSEI_CTRL_CODE_PAGE)|(res->ctrl&~_SHINSEI_CTRL_CODE_PAGE);
	return res;
}

void shinsei_string_t_swap(shinsei_string_t*const restrict this,shinsei_string_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	shinsei_string_t tmp;
	__builtin_memcpy(&tmp,src,sizeof(shinsei_string_t));
	__builtin_memcpy(src,this,sizeof(shinsei_string_t));
	__builtin_memcpy(this,&tmp,sizeof(shinsei_string_t));
	return;
}

bool shinsei_string_t_clear(shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	this->size=0;
	str_setNull(this);
	if(!str_inlined(this)){
		register char*const new_ptr=(char*)__builtin_realloc(this->data,(shinsei_string_t_DEF_CAP+1)*this->char_size);
		if(__builtin_expect(new_ptr==nullptr,0)) return false;
		this->cap=shinsei_string_t_DEF_CAP;
		this->data=new_ptr;
	}
	return true;
}

bool shinsei_string_t_setSize(shinsei_string_t*const restrict this,const size_t size)_SHINSEI_OS_NOEXCEPT{
	if(size>this->cap){
		if(!shinsei_string_t_reserve(this,size)) return false;
	}
	this->size=size;
	str_setNull(this);
	return true;
}

void shinsei_string_t_move(shinsei_string_t*const restrict this,shinsei_string_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	if(!str_inlined(this)&&this->data!=nullptr) str_freeData(this);
	str_asMove(this,src);
	return;
}

// Attach the string from another one
bool shinsei_string_t_attach(shinsei_string_t*const restrict this,const shinsei_string_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	register const bool des_inlined=str_inlined(this);
	if(!des_inlined){
		if(this->cap<src->cap){
			register char* ptr=(char*)__builtin_realloc(this->data,(src->cap+1)*this->char_size);
			if(__builtin_expect(ptr==nullptr,0)) return false;
			this->data=ptr;
			this->cap=src->cap;
		}
	}
	this->ctrl=(src->ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->code_page=src->code_page;
	this->size=src->size;
	__builtin_memcpy(str_data(this),str_data(src),(this->size+1)*this->char_size);
	return true;
}

// Attach the string from values
bool shinsei_string_t_attachValue(shinsei_string_t*const restrict this,const int_fast32_t ctrl,const unsigned int code_page,const size_t size,const size_t cap,void*const ptr,const size_t char_size)_SHINSEI_OS_NOEXCEPT{
	register const bool des_inlined=str_inlined(this);
	this->char_size=char_size;
	if(!des_inlined){
		if(this->cap<cap){
			register char* new_ptr=(char*)__builtin_realloc(this->data,(cap+1)*this->char_size);
			if(__builtin_expect(new_ptr==nullptr,0)) return false;
			this->data=new_ptr;
			this->cap=cap;
		}
	}
	this->ctrl=(ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->code_page=code_page;
	this->size=size;
	__builtin_memcpy(str_data(this),ptr,this->size*this->char_size);
	str_setNull(this);
	return true;
}

bool shinsei_string_t_isCodepage(const shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_CODE_PAGE;
}

unsigned int shinsei_string_t_getCodePage(const shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->code_page;
}

void shinsei_string_t_enableCodePage(shinsei_string_t*const restrict this,const bool enabled)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=(this->ctrl&~_SHINSEI_CTRL_CODE_PAGE)|(enabled*_SHINSEI_CTRL_CODE_PAGE);
	return;
}

void shinsei_string_t_setCodePage(shinsei_string_t*const restrict this,const unsigned int code_page)_SHINSEI_OS_NOEXCEPT{
	this->code_page=code_page;
	return;
}

void shinsei_string_t_codePage(shinsei_string_t*const restrict this,const bool enabled,const unsigned int code_page)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=(this->ctrl&~_SHINSEI_CTRL_CODE_PAGE)|(enabled*_SHINSEI_CTRL_CODE_PAGE);
	this->code_page=code_page;
	return;
}

bool shinsei_string_t_as(shinsei_string_t*const restrict this,const size_t char_size)_SHINSEI_OS_NOEXCEPT{
	return str_con(this,char_size);
}

bool shinsei_string_t_asCapacity(shinsei_string_t*const restrict this,const size_t cap,const size_t char_size)_SHINSEI_OS_NOEXCEPT{
	return str_conCapacity(this,cap,char_size);
}

bool shinsei_string_t_asAssign(shinsei_string_t*const restrict this,const shinsei_string_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	return str_asAssign(this,src);
}

void shinsei_string_t_asMove(shinsei_string_t*const restrict this,shinsei_string_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	str_asMove(this,src);
	return;
}

bool shinsei_string_t_asChar(shinsei_string_t*const restrict this,const void*const restrict ch,const size_t repeat_cnt,const size_t char_size)_SHINSEI_OS_NOEXCEPT{
	return str_asElement(this,ch,repeat_cnt,char_size);
}

bool shinsei_string_t_asArray(shinsei_string_t*const restrict this,const void*const restrict arr,const size_t len,const size_t char_size)_SHINSEI_OS_NOEXCEPT{
	return str_asArray(this,arr,len,char_size);
}

bool shinsei_string_t_asSubstr(shinsei_string_t*const restrict this,const shinsei_string_t*const restrict src,const size_t idx,const size_t len)_SHINSEI_OS_NOEXCEPT{
	register const size_t safe_idx=(idx>src->size)*src->size+(idx<=src->size)*idx;
	register const size_t real_len=(safe_idx+len>src->size)*(src->size-safe_idx)+(safe_idx+len<=src->size)*len;
	if(!shinsei_string_t_asCapacity(this,real_len,src->char_size)) return false;
	str_pushBackArray(this,str_data(src)+safe_idx*src->char_size,real_len);
	this->code_page=src->code_page;
	this->ctrl=(src->ctrl&_SHINSEI_CTRL_CODE_PAGE)|(this->ctrl&~_SHINSEI_CTRL_CODE_PAGE);
	return true;
}

void shinsei_string_t_inl(shinsei_string_t*const restrict this,const size_t cap,const size_t char_size)_SHINSEI_OS_NOEXCEPT{
	str_inl(this,cap,char_size);
	return;
}

void shinsei_string_t_inlCapacity(shinsei_string_t*const restrict this,const size_t cap,const size_t char_size)_SHINSEI_OS_NOEXCEPT{
	str_inl(this,cap,char_size);
	return;
}

void shinsei_string_t_inlAssign(shinsei_string_t*const restrict this,const shinsei_string_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->code_page=src->code_page;
	this->size=src->size;
	this->cap=src->cap;
	this->char_size=src->char_size;
	__builtin_memcpy(str_data(this),str_data(src),(this->size+1)*this->char_size);
	return;
}

void shinsei_string_t_inlMove(shinsei_string_t*const restrict this,shinsei_string_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->code_page=src->code_page;
	this->size=src->size;
	this->cap=src->cap;
	this->char_size=src->char_size;
	__builtin_memcpy(str_data(this),str_data(src),(this->size+1)*this->char_size);
	if(!str_inlined(src)&&src->data!=nullptr) str_freeData(src);
	src->ctrl=0;
	src->code_page=0;
	src->size=0;
	src->cap=0;
	src->data=nullptr;
	return;
}

void shinsei_string_t_inlChar(shinsei_string_t*const restrict this,const void*const restrict ch,const size_t repeat_cnt,const size_t char_size)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->code_page=0;
	this->size=repeat_cnt;
	this->cap=repeat_cnt;
	this->char_size=char_size;
	register char*const dst=str_data(this);
	for(register size_t i=0;i<repeat_cnt;++i) __builtin_memcpy(dst+i*char_size,ch,char_size);
	str_setNull(this);
	return;
}

void shinsei_string_t_inlArray(shinsei_string_t*const restrict this,const void*const restrict arr,const size_t len,const size_t char_size)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->code_page=0;
	this->size=len;
	this->cap=len;
	this->char_size=char_size;
	__builtin_memcpy(str_data(this),arr,len*char_size);
	str_setNull(this);
	return;
}

void shinsei_string_t_inlSubstr(shinsei_string_t*const restrict this,const shinsei_string_t*const restrict src,const size_t idx,const size_t len)_SHINSEI_OS_NOEXCEPT{
	register const size_t safe_idx=(idx>src->size)*src->size+(idx<=src->size)*idx;
	register const size_t real_len=(safe_idx+len>src->size)*(src->size-safe_idx)+(safe_idx+len<=src->size)*len;
	this->ctrl=_SHINSEI_CTRL_INLINED|(src->ctrl&_SHINSEI_CTRL_CODE_PAGE);
	this->code_page=src->code_page;
	this->size=real_len;
	this->cap=real_len;
	this->char_size=src->char_size;
	__builtin_memcpy(str_data(this),str_data(src)+safe_idx*src->char_size,real_len*this->char_size);
	str_setNull(this);
	return;
}

bool shinsei_string_t_inlined(const shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return str_inlined(this);
}

int_fast32_t shinsei_string_t_getCtrl(const shinsei_string_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl;
}

void shinsei_string_t_setCtrl(shinsei_string_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=ctrl;
	return;
}

// legacy

size_t shinsei_parseEscapedCharA(char*const restrict des,const char*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!src_len,0)) return 0;
	switch(src[0]){
		case 'a':{
			*des='\a';
			break;
		}
		case 'b':{
			*des='\b';
			break;
		}
		case 'e':{
			// Non-ISO-standard escape sequence
			*des='\033';
			break;
		}
		case 'f':{
			*des='\f';
			break;
		}
		case 'n':{
			*des='\n';
			break;
		}
		case 'r':{
			*des='\r';
			break;
		}
		case 't':{
			*des='\t';
			break;
		}
		case 'v':{
			*des='\v';
			break;
		}
		case '\\':{
			*des='\\';
			break;
		}
		case '\'':{
			*des='\'';
			break;
		}
		case '"':{
			*des='"';
			break;
		}
		case '?':{
			*des='?';
			break;
		}
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':{
			// Unimplemented. Placeholder.
			break;
		}
		case 'u':{
			
			break;
		}
		case 'U':{
			
			break;
		}
		case 'N':{
			
			break;
		}
	}
	return 0;
}
size_t shinsei_parseEscapedCharW(wchar_t**restrict des,const wchar_t*restrict src,size_t src_len)_SHINSEI_OS_NOEXCEPT{
	// May be legacy
	if(__builtin_expect(!src_len,0)) return 0;
	switch(src[0]){
		case L'a':{
			**des=L'\a';
			break;
		}
		case L'b':{
			**des=L'\b';
			break;
		}
		
		case L'e':{
			// Non-ISO-standard escape sequence
			**des=L'\033';
			break;
		}
		case L'f':{
			**des=L'\f';
			break;
		}
		case L'n':{
			**des=L'\n';
			break;
		}
		case L'r':{
			**des=L'\r';
			break;
		}
		case L't':{
			**des=L'\t';
			break;
		}
		case L'v':{
			**des=L'\v';
			break;
		}
		case L'\\':{
			**des=L'\\';
			break;
		}
		case L'\'':{
			**des=L'\'';
			break;
		}
		case L'"':{
			**des=L'"';
			break;
		}
		case L'?':{
			**des=L'?';
			break;
		}
		case L'0':
		case L'1':
		case L'2':
		case L'3':
		case L'4':
		case L'5':
		case L'6':
		case L'7':{
			**des=src[0]-L'0';
			if(src_len<=1||!shinsei_isODigitW(src[1])){
				++*des;
				return 1;
			}
			**des=(wchar_t)((**des<<3)+(src[1]-L'0'));
			if(src_len<=2||!shinsei_isODigitW(src[2])){
				++*des;
				return 2;
			}
			**des=(wchar_t)((**des<<3)+(src[2]-L'0'));
			++*des;
			return 3;
		}
		case L'o':{
			if(__builtin_expect(src_len<2,0)) return 0;
			src_len-=2;
			if(__builtin_expect(*++src!=L'{',0)) return 0;
			if(__builtin_expect(*++src==L'}',0)) return 0;
			register char32_t ch=0;
			register int i=3;
			while(*src!=L'}'){
				if(__builtin_expect(++i>19||!shinsei_isODigitW(*src),0)) return 0;
				ch=(ch<<3)+(*src-L'0');
				if(__builtin_expect(!src_len,0)) return 0;
				--src_len;
				++src;
			}
			*des+=shinsei_uTF32CharToUTF16Char(*des,ch);
			return (size_t)i;
		}
		case L'x':{
			if(*++src==L'{'){
				if(__builtin_expect(src_len<2,0)) return 0;
				src_len-=2;
				if(__builtin_expect(*++src==L'}',0)) return 0;
				register char32_t ch=0;
				register int i=3;
				register const int mx=((sizeof(unsigned int)*CHAR_BIT)>>2)+3;
				while(*src!=L'}'){
					if(__builtin_expect(++i>mx||!iswxdigit(*src),0)) return 0;
					ch=(ch<<4)+(iswdigit(*src)?*src-L'0':towupper(*src)-L'A'+10);
					if(__builtin_expect(!src_len,0)) return 0;
					--src_len;
					++src;
				}
				*des+=shinsei_uTF32CharToUTF16Char(*des,ch);
				return (size_t)i;
			}
			register char32_t ch=0;
			register int i=1;
			if(__builtin_expect(!src_len,0)) return 0;
			--src_len;
			if(__builtin_expect(!iswxdigit(*++src),0)) return 0;
			while(iswxdigit(*src)){
				ch=(ch<<4)+(iswdigit(*src)?*src-L'0':towupper(*src)-L'A'+10);
				if(__builtin_expect(!src_len,0)) return 0;
				--src_len;
				++src;
				++i;
			}
			*des+=shinsei_uTF32CharToUTF16Char(*des,ch);
			return (size_t)i;
		}
		case L'u':{
			if(__builtin_expect(src_len<2,0)) return 0;
			if(*++src==L'{'){
				src_len-=2;
				if(__builtin_expect(*++src==L'}',0)) return 0;
				register char32_t ch=0;
				register int i=3;
				while(*src!=L'}'){
					if(__builtin_expect(++i>9||!iswxdigit(*src),0)) return 0;
					ch=(ch<<4)+(iswdigit(*src)?*src-L'0':towupper(*src)-L'A'+10);
					if(__builtin_expect(!src_len,0)) return 0;
					--src_len;
					++src;
				}
				if(ch>0x10FFFF||(ch>=0xD800&&ch<=0xDFFF)) return 0;
				*des+=shinsei_uTF32CharToUTF16Char(*des,ch);
				return (size_t)i;
			}
			if(__builtin_expect(src_len<5,0)) return 0;
			register int i=0;
			**des=0;
			while(__builtin_expect(i<4,1)){
				if(__builtin_expect(!iswxdigit(*++src),0)) return 0;
				**des=(wchar_t)((**des<<4)+(iswdigit(*src)?*src-L'0':towupper(*src)-L'A'+10));
				++i;
			}
			++*des;
			return 5;
		}
		case L'U':{
			if(__builtin_expect(src_len<9,0)) return 0;
			register char32_t ch=0;
			register int i=0;
			while(__builtin_expect(i<8,1)){
				if(__builtin_expect(!iswxdigit(*++src),0)) return 0;
				ch=(ch<<4)+((bool)iswdigit(*src)*(char32_t)(*src-L'0')+!iswdigit(*src)*((char32_t)towupper(*src)-L'A'+10));
				++i;
			}
			if(ch>0x10FFFF||(ch>=0xD800&&ch<=0xDFFF)) return 0;
			*des+=shinsei_uTF32CharToUTF16Char(*des,ch);
			return 9;
		}
		case L'N':{
			return 0;
			if(__builtin_expect(*++src!=L'{',0)) return 0;
			while(__builtin_expect(*++src!=L'}',1)){
				// Unimplemented. Placeholder.
			}
			break;
		}
	}
	++*des;
	return 1;
}

size_t shinsei_readEscapedLineA(char*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// Legacy
	register size_t res=0;
	register size_t i=0;
	while(__builtin_expect(i<len,1)){
		if(__builtin_expect(str[i]=='\\',0)){
			if(__builtin_expect(!shinsei_parseEscapedCharA(str+res,str+i+1,len-i-1),0)) return 0;
			if(str[res]=='\0') return res;
			++res;
			++i;
			continue;
		}
		str[res++]=str[i++];
	}
	str[res]='\0';
	return res;
}
size_t shinsei_readEscapedLineW(wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	// Legacy
	register size_t i=0;
	wchar_t* des=str;
	while(__builtin_expect(i<len,1)){
		if(__builtin_expect(str[i]==L'\\',0)){
			const size_t now=shinsei_parseEscapedCharW((wchar_t**)&des,str+i+1,len-i-1);
			if(__builtin_expect(!now,0)) return 0;
			i+=now+1;
			continue;
		}
		*des++=str[i++];
	}
	*des=L'\0';
	return (size_t)(des-str);
}

size_t shinsei_escapedLineToStringsA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// Unimplemented. Placeholder.
	(void)idx_buf;
	(void)idx_buf_len;
	(void)str;
	(void)str_len;
	return 0;
}
size_t shinsei_escapedLineToStringsW(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len)_SHINSEI_OS_NOEXCEPT{
	// Legacy
	register size_t i=0;
	register size_t pre=0;
	register size_t res=0;
	register size_t now;
	wchar_t* des=str;
	while(__builtin_expect(i<str_len,1)){
		if(__builtin_expect(str[i]==L'\\',0)){
			now=shinsei_parseEscapedCharW((wchar_t**)&des,str+i+1,str_len-i-1);
			if(__builtin_expect(!now,0)) return 0;
			if(__builtin_expect(des[-now]==L'\n',0)){
				des[-now]=L'\0';
				if(des>str&&des[-now-1]==L'\r') des[-now-1]=L'\0';
				if(res<idx_buf_len){
					idx_buf[res]=pre;
					pre=(size_t)(des-now-str+1);
				}
				++res;
			}
			i+=now+1;
			continue;
		}
		*des++=str[i++];
	}
	if(res<idx_buf_len) idx_buf[res]=pre;
	*des=des[1]=L'\0';
	return res+1;
}

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif
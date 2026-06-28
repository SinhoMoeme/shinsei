#pragma once

#include"shinsei/minimal/str.h"
#include"shinsei/.internal/tag.hpp"
#include<new>

namespace shinsei{
	// Size
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UTF16_OF_UTF32=::SHINSEI_MAX_UTF16_OF_UTF32;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UTF8_OF_UTF32=::SHINSEI_MAX_UTF8_OF_UTF32;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UTF8_OF_UTF16=::SHINSEI_MAX_UTF8_OF_UTF16;
	static _SHINSEI_OS_CONSTEXPR ::size_t POINTER_BIT=::SHINSEI_POINTER_BIT;
	static _SHINSEI_OS_CONSTEXPR ::size_t POINTER_OF_CHAR=::SHINSEI_POINTER_OF_CHAR;
	static _SHINSEI_OS_CONSTEXPR ::size_t POINTER_OF_WCHAR=::SHINSEI_POINTER_OF_WCHAR;
	
	// ANSI code pages
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_AUTO=::SHINSEI_CODE_PAGE_AUTO;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM037=::SHINSEI_CODE_PAGE_IBM037;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM437=::SHINSEI_CODE_PAGE_IBM437;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM500=::SHINSEI_CODE_PAGE_IBM500;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ASMO_708=::SHINSEI_CODE_PAGE_ASMO_708;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ASMO_449=::SHINSEI_CODE_PAGE_ASMO_449;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_TRANSPARENT_ARABIC=::SHINSEI_CODE_PAGE_TRANSPARENT_ARABIC;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_DOS_720=::SHINSEI_CODE_PAGE_DOS_720;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM737=::SHINSEI_CODE_PAGE_IBM737;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM775=::SHINSEI_CODE_PAGE_IBM775;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM850=::SHINSEI_CODE_PAGE_IBM850;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM852=::SHINSEI_CODE_PAGE_IBM852;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM855=::SHINSEI_CODE_PAGE_IBM855;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM857=::SHINSEI_CODE_PAGE_IBM857;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM00858=::SHINSEI_CODE_PAGE_IBM00858;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM860=::SHINSEI_CODE_PAGE_IBM860;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM861=::SHINSEI_CODE_PAGE_IBM861;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM862=::SHINSEI_CODE_PAGE_IBM862;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM863=::SHINSEI_CODE_PAGE_IBM863;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM864=::SHINSEI_CODE_PAGE_IBM864;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM865=::SHINSEI_CODE_PAGE_IBM865;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_CP866=::SHINSEI_CODE_PAGE_CP866;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM869=::SHINSEI_CODE_PAGE_IBM869;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM870=::SHINSEI_CODE_PAGE_IBM870;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_WINDOWS_874=::SHINSEI_CODE_PAGE_WINDOWS_874;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_CP875=::SHINSEI_CODE_PAGE_CP875;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_SHIFT_JIS=::SHINSEI_CODE_PAGE_SHIFT_JIS;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_GB2312=::SHINSEI_CODE_PAGE_GB2312;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_KS_C_5601_1987=::SHINSEI_CODE_PAGE_KS_C_5601_1987;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_BIG5=::SHINSEI_CODE_PAGE_BIG5;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM1026=::SHINSEI_CODE_PAGE_IBM1026;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM01047=::SHINSEI_CODE_PAGE_IBM01047;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM01140=::SHINSEI_CODE_PAGE_IBM01140;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM01141=::SHINSEI_CODE_PAGE_IBM01141;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM01142=::SHINSEI_CODE_PAGE_IBM01142;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM01143=::SHINSEI_CODE_PAGE_IBM01143;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM01144=::SHINSEI_CODE_PAGE_IBM01144;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM01145=::SHINSEI_CODE_PAGE_IBM01145;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM01146=::SHINSEI_CODE_PAGE_IBM01146;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM01147=::SHINSEI_CODE_PAGE_IBM01147;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM01148=::SHINSEI_CODE_PAGE_IBM01148;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM01149=::SHINSEI_CODE_PAGE_IBM01149;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_UTF_16=::SHINSEI_CODE_PAGE_UTF_16;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_UNICODEFFFE=::SHINSEI_CODE_PAGE_UNICODEFFFE;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_WINDOWS_1250=::SHINSEI_CODE_PAGE_WINDOWS_1250;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_WINDOWS_1251=::SHINSEI_CODE_PAGE_WINDOWS_1251;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_WINDOWS_1252=::SHINSEI_CODE_PAGE_WINDOWS_1252;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_WINDOWS_1253=::SHINSEI_CODE_PAGE_WINDOWS_1253;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_WINDOWS_1254=::SHINSEI_CODE_PAGE_WINDOWS_1254;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_WINDOWS_1255=::SHINSEI_CODE_PAGE_WINDOWS_1255;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_WINDOWS_1256=::SHINSEI_CODE_PAGE_WINDOWS_1256;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_WINDOWS_1257=::SHINSEI_CODE_PAGE_WINDOWS_1257;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_WINDOWS_1258=::SHINSEI_CODE_PAGE_WINDOWS_1258;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_JOHAB=::SHINSEI_CODE_PAGE_JOHAB;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_MACINTOSH=::SHINSEI_CODE_PAGE_MACINTOSH;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_MAC_JAPANESE=::SHINSEI_CODE_PAGE_X_MAC_JAPANESE;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_MAC_CHINESETRAD=::SHINSEI_CODE_PAGE_X_MAC_CHINESETRAD;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_MAC_KOREAN=::SHINSEI_CODE_PAGE_X_MAC_KOREAN;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_MAC_ARABIC=::SHINSEI_CODE_PAGE_X_MAC_ARABIC;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_MAC_HEBREW=::SHINSEI_CODE_PAGE_X_MAC_HEBREW;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_MAC_GREEK=::SHINSEI_CODE_PAGE_X_MAC_GREEK;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_MAC_CYRILLIC=::SHINSEI_CODE_PAGE_X_MAC_CYRILLIC;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_MAC_CHINESESIMP=::SHINSEI_CODE_PAGE_X_MAC_CHINESESIMP;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_MAC_ROMANIAN=::SHINSEI_CODE_PAGE_X_MAC_ROMANIAN;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_MAC_UKRAINIAN=::SHINSEI_CODE_PAGE_X_MAC_UKRAINIAN;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_MAC_THAI=::SHINSEI_CODE_PAGE_X_MAC_THAI;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_MAC_MAC_CE=::SHINSEI_CODE_PAGE_X_MAC_MAC_CE;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_MAC_ICELANDIC=::SHINSEI_CODE_PAGE_X_MAC_ICELANDIC;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_MAC_TURKISH=::SHINSEI_CODE_PAGE_X_MAC_TURKISH;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_MAC_CROATIAN=::SHINSEI_CODE_PAGE_X_MAC_CROATIAN;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_UTF_32=::SHINSEI_CODE_PAGE_UTF_32;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_UTF_32BE=::SHINSEI_CODE_PAGE_UTF_32BE;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_CHINESE_CNS=::SHINSEI_CODE_PAGE_X_CHINESE_CNS;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_CP20001=::SHINSEI_CODE_PAGE_X_CP20001;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_CHINESE_ETEN=::SHINSEI_CODE_PAGE_X_CHINESE_ETEN;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_CP20003=::SHINSEI_CODE_PAGE_X_CP20003;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_CP20004=::SHINSEI_CODE_PAGE_X_CP20004;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_CP20005=::SHINSEI_CODE_PAGE_X_CP20005;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_IA5=::SHINSEI_CODE_PAGE_X_IA5;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_IA5_GERMAN=::SHINSEI_CODE_PAGE_X_IA5_GERMAN;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_IA5_SWEDISH=::SHINSEI_CODE_PAGE_X_IA5_SWEDISH;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_IA5_NORWEGIAN=::SHINSEI_CODE_PAGE_X_IA5_NORWEGIAN;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_US_ASCII=::SHINSEI_CODE_PAGE_US_ASCII;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_CP20261=::SHINSEI_CODE_PAGE_X_CP20261;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_CP20269=::SHINSEI_CODE_PAGE_X_CP20269;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM273=::SHINSEI_CODE_PAGE_IBM273;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM277=::SHINSEI_CODE_PAGE_IBM277;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM278=::SHINSEI_CODE_PAGE_IBM278;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM280=::SHINSEI_CODE_PAGE_IBM280;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM284=::SHINSEI_CODE_PAGE_IBM284;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM285=::SHINSEI_CODE_PAGE_IBM285;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM290=::SHINSEI_CODE_PAGE_IBM290;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM297=::SHINSEI_CODE_PAGE_IBM297;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM420=::SHINSEI_CODE_PAGE_IBM420;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM423=::SHINSEI_CODE_PAGE_IBM423;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM424=::SHINSEI_CODE_PAGE_IBM424;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_EBCDIC_KOREANEXTENDED=::SHINSEI_CODE_PAGE_X_EBCDIC_KOREANEXTENDED;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM_THAI=::SHINSEI_CODE_PAGE_IBM_THAI;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_KOI8_R=::SHINSEI_CODE_PAGE_KOI8_R;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM871=::SHINSEI_CODE_PAGE_IBM871;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM880=::SHINSEI_CODE_PAGE_IBM880;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM905=::SHINSEI_CODE_PAGE_IBM905;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_IBM00924=::SHINSEI_CODE_PAGE_IBM00924;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_EUC_JP_LEGACY=::SHINSEI_CODE_PAGE_EUC_JP_LEGACY;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_CP20936=::SHINSEI_CODE_PAGE_X_CP20936;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_CP20949=::SHINSEI_CODE_PAGE_X_CP20949;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_CP1025=::SHINSEI_CODE_PAGE_CP1025;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_DEPRECATED=::SHINSEI_CODE_PAGE_DEPRECATED;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_KOI8_U=::SHINSEI_CODE_PAGE_KOI8_U;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ISO_8859_1=::SHINSEI_CODE_PAGE_ISO_8859_1;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ISO_8859_2=::SHINSEI_CODE_PAGE_ISO_8859_2;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ISO_8859_3=::SHINSEI_CODE_PAGE_ISO_8859_3;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ISO_8859_4=::SHINSEI_CODE_PAGE_ISO_8859_4;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ISO_8859_5=::SHINSEI_CODE_PAGE_ISO_8859_5;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ISO_8859_6=::SHINSEI_CODE_PAGE_ISO_8859_6;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ISO_8859_7=::SHINSEI_CODE_PAGE_ISO_8859_7;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ISO_8859_8=::SHINSEI_CODE_PAGE_ISO_8859_8;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ISO_8859_9=::SHINSEI_CODE_PAGE_ISO_8859_9;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ISO_8859_13=::SHINSEI_CODE_PAGE_ISO_8859_13;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ISO_8859_15=::SHINSEI_CODE_PAGE_ISO_8859_15;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_EUROPA=::SHINSEI_CODE_PAGE_X_EUROPA;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ISO_8859_8_I=::SHINSEI_CODE_PAGE_ISO_8859_8_I;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ISO_2022_JP=::SHINSEI_CODE_PAGE_ISO_2022_JP;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_CSISO2022JP=::SHINSEI_CODE_PAGE_CSISO2022JP;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ISO_2022_JP_EXT=::SHINSEI_CODE_PAGE_ISO_2022_JP_EXT;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ISO_2022_KR=::SHINSEI_CODE_PAGE_ISO_2022_KR;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_CP50227=::SHINSEI_CODE_PAGE_X_CP50227;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_ISO_2022_TC=::SHINSEI_CODE_PAGE_ISO_2022_TC;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_EBCDIC_JA_KATAKANA_EXTENDED=::SHINSEI_CODE_PAGE_EBCDIC_JA_KATAKANA_EXTENDED;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_EBCDIC_US_CA_JP=::SHINSEI_CODE_PAGE_EBCDIC_US_CA_JP;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_EBCDIC_KO_EXTENDED=::SHINSEI_CODE_PAGE_EBCDIC_KO_EXTENDED;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_EBCDIC_SC_EXTENDED=::SHINSEI_CODE_PAGE_EBCDIC_SC_EXTENDED;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_EBCDIC_SC=::SHINSEI_CODE_PAGE_EBCDIC_SC;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_EBCDIC_US_CA_TC=::SHINSEI_CODE_PAGE_EBCDIC_US_CA_TC;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_EBCDIC_JA_LATIN_EXTENDED=::SHINSEI_CODE_PAGE_EBCDIC_JA_LATIN_EXTENDED;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_EUC_JP=::SHINSEI_CODE_PAGE_EUC_JP;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_EUC_CN=::SHINSEI_CODE_PAGE_EUC_CN;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_EUC_KR=::SHINSEI_CODE_PAGE_EUC_KR;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_EUC_TC=::SHINSEI_CODE_PAGE_EUC_TC;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_HZ_GB_2312=::SHINSEI_CODE_PAGE_HZ_GB_2312;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_GB18030=::SHINSEI_CODE_PAGE_GB18030;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_ISCII_DE=::SHINSEI_CODE_PAGE_X_ISCII_DE;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_ISCII_BE=::SHINSEI_CODE_PAGE_X_ISCII_BE;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_ISCII_TA=::SHINSEI_CODE_PAGE_X_ISCII_TA;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_ISCII_TE=::SHINSEI_CODE_PAGE_X_ISCII_TE;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_ISCII_AS=::SHINSEI_CODE_PAGE_X_ISCII_AS;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_ISCII_OR=::SHINSEI_CODE_PAGE_X_ISCII_OR;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_ISCII_KA=::SHINSEI_CODE_PAGE_X_ISCII_KA;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_ISCII_MA=::SHINSEI_CODE_PAGE_X_ISCII_MA;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_ISCII_GU=::SHINSEI_CODE_PAGE_X_ISCII_GU;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_X_ISCII_PA=::SHINSEI_CODE_PAGE_X_ISCII_PA;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_UTF_7=::SHINSEI_CODE_PAGE_UTF_7;
	static _SHINSEI_OS_CONSTEXPR unsigned int CODE_PAGE_UTF_8=::SHINSEI_CODE_PAGE_UTF_8;
	
	// ANSI status
	static _SHINSEI_OS_CONSTEXPR int STATUS_SBCS=::SHINSEI_STATUS_SBCS; // Standard 1-byte mode
	static _SHINSEI_OS_CONSTEXPR int STATUS_DBCS=::SHINSEI_STATUS_DBCS; // Standard 2-byte mode
	static _SHINSEI_OS_CONSTEXPR int STATUS_UTF7_ASCII=::SHINSEI_STATUS_UTF7_ASCII; // UTF-7 standard mode
	static _SHINSEI_OS_CONSTEXPR int STATUS_UTF7_BASE64=::SHINSEI_STATUS_UTF7_BASE64; // UTF-7 shifted mode (+)
	
	// ISCII-1991 status
	static _SHINSEI_OS_CONSTEXPR int STATUS_ISCII_DEVANAGARI=::SHINSEI_STATUS_ISCII_DEVANAGARI; // Hindi,Marathi,Sanskrit
	static _SHINSEI_OS_CONSTEXPR int STATUS_ISCII_BENGALI=::SHINSEI_STATUS_ISCII_BENGALI; // Bengali,Assamese
	static _SHINSEI_OS_CONSTEXPR int STATUS_ISCII_GURMUKHI=::SHINSEI_STATUS_ISCII_GURMUKHI; // Punjabi
	static _SHINSEI_OS_CONSTEXPR int STATUS_ISCII_GUJARATI=::SHINSEI_STATUS_ISCII_GUJARATI; // Gujarati
	static _SHINSEI_OS_CONSTEXPR int STATUS_ISCII_ODIA=::SHINSEI_STATUS_ISCII_ODIA; // Odia (Oriya)
	static _SHINSEI_OS_CONSTEXPR int STATUS_ISCII_TAMIL=::SHINSEI_STATUS_ISCII_TAMIL; // Tamil
	static _SHINSEI_OS_CONSTEXPR int STATUS_ISCII_TELUGU=::SHINSEI_STATUS_ISCII_TELUGU; // Telugu
	static _SHINSEI_OS_CONSTEXPR int STATUS_ISCII_KANNADA=::SHINSEI_STATUS_ISCII_KANNADA; // Kannada
	static _SHINSEI_OS_CONSTEXPR int STATUS_ISCII_MALAYALAM=::SHINSEI_STATUS_ISCII_MALAYALAM; // Malayalam
	static _SHINSEI_OS_CONSTEXPR int STATUS_ISCII_ROMAN=::SHINSEI_STATUS_ISCII_ROMAN; //Roman
	
	// Buffer size
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT8_STR_BUF=::SHINSEI_MAX_INT8_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT8_BIN_STR_BUF=::SHINSEI_MAX_INT8_BIN_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT8_OCT_STR_BUF=::SHINSEI_MAX_INT8_OCT_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT8_HEX_STR_BUF=::SHINSEI_MAX_INT8_HEX_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT8_36BASE_STR_BUF=::SHINSEI_MAX_INT8_36BASE_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT8_62BASE_STR_BUF=::SHINSEI_MAX_INT8_62BASE_STR_BUF;
	
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT8_STR_BUF=::SHINSEI_MAX_UINT8_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT8_BIN_STR_BUF=::SHINSEI_MAX_UINT8_BIN_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT8_OCT_STR_BUF=::SHINSEI_MAX_UINT8_OCT_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT8_HEX_STR_BUF=::SHINSEI_MAX_UINT8_HEX_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT8_36BASE_STR_BUF=::SHINSEI_MAX_UINT8_36BASE_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT8_62BASE_STR_BUF=::SHINSEI_MAX_UINT8_62BASE_STR_BUF;
	
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT16_STR_BUF=::SHINSEI_MAX_INT16_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT16_BIN_STR_BUF=::SHINSEI_MAX_INT16_BIN_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT16_OCT_STR_BUF=::SHINSEI_MAX_INT16_OCT_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT16_HEX_STR_BUF=::SHINSEI_MAX_INT16_HEX_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT16_36BASE_STR_BUF=::SHINSEI_MAX_INT16_36BASE_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT16_62BASE_STR_BUF=::SHINSEI_MAX_INT16_62BASE_STR_BUF;
	
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT16_STR_BUF=::SHINSEI_MAX_UINT16_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT16_BIN_STR_BUF=::SHINSEI_MAX_UINT16_BIN_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT16_OCT_STR_BUF=::SHINSEI_MAX_UINT16_OCT_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT16_HEX_STR_BUF=::SHINSEI_MAX_UINT16_HEX_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT16_36BASE_STR_BUF=::SHINSEI_MAX_UINT16_36BASE_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT16_62BASE_STR_BUF=::SHINSEI_MAX_UINT16_62BASE_STR_BUF;
	
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT32_STR_BUF=::SHINSEI_MAX_INT32_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT32_BIN_STR_BUF=::SHINSEI_MAX_INT32_BIN_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT32_OCT_STR_BUF=::SHINSEI_MAX_INT32_OCT_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT32_HEX_STR_BUF=::SHINSEI_MAX_INT32_HEX_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT32_36BASE_STR_BUF=::SHINSEI_MAX_INT32_36BASE_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT32_62BASE_STR_BUF=::SHINSEI_MAX_INT32_62BASE_STR_BUF;
	
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT32_STR_BUF=::SHINSEI_MAX_UINT32_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT32_BIN_STR_BUF=::SHINSEI_MAX_UINT32_BIN_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT32_OCT_STR_BUF=::SHINSEI_MAX_UINT32_OCT_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT32_HEX_STR_BUF=::SHINSEI_MAX_UINT32_HEX_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT32_36BASE_STR_BUF=::SHINSEI_MAX_UINT32_36BASE_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT32_62BASE_STR_BUF=::SHINSEI_MAX_UINT32_62BASE_STR_BUF;
	
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT64_STR_BUF=::SHINSEI_MAX_INT64_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT64_BIN_STR_BUF=::SHINSEI_MAX_INT64_BIN_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT64_OCT_STR_BUF=::SHINSEI_MAX_INT64_OCT_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT64_HEX_STR_BUF=::SHINSEI_MAX_INT64_HEX_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT64_36BASE_STR_BUF=::SHINSEI_MAX_INT64_36BASE_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_INT64_62BASE_STR_BUF=::SHINSEI_MAX_INT64_62BASE_STR_BUF;
	
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT64_STR_BUF=::SHINSEI_MAX_UINT64_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT64_BIN_STR_BUF=::SHINSEI_MAX_UINT64_BIN_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT64_OCT_STR_BUF=::SHINSEI_MAX_UINT64_OCT_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT64_HEX_STR_BUF=::SHINSEI_MAX_UINT64_HEX_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT64_36BASE_STR_BUF=::SHINSEI_MAX_UINT64_36BASE_STR_BUF;
	static _SHINSEI_OS_CONSTEXPR ::size_t MAX_UINT64_62BASE_STR_BUF=::SHINSEI_MAX_UINT64_62BASE_STR_BUF;
	
	_SHINSEI_OS_INLINE bool isANSICodePage(const unsigned int id)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isANSICodePage(id);
	}
	_SHINSEI_OS_INLINE bool isEBCDICCodePage(const unsigned int id)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isEBCDICCodePage(id);
	}
	
	_SHINSEI_OS_INLINE int charSizeW(const wint_t starter_ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_charSizeW(starter_ch);
	}
	_SHINSEI_OS_INLINE int charSizeCP(const unsigned int cp,const int starter_ch,const int second_ch=0,const int third_ch=0,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_charSizeCP(cp,starter_ch,second_ch,third_ch,status);
	}
	_SHINSEI_OS_INLINE int charSizeU8(const char8_t starter_ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_charSizeU8(starter_ch);
	}
	_SHINSEI_OS_INLINE int charSizeU16(const char16_t starter_ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_charSizeU16(starter_ch);
	}
	_SHINSEI_OS_INLINE int charSizeU32(const char32_t starter_ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_charSizeU32(starter_ch);
	}
	_SHINSEI_OS_INLINE int charSize(const wint_t starter_ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_charSizeW(starter_ch);
	}
	_SHINSEI_OS_INLINE int charSize(const unsigned int cp,const int starter_ch,const int second_ch=0,const int third_ch=0,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_charSizeCP(cp,starter_ch,second_ch,third_ch,status);
	}
	_SHINSEI_OS_INLINE int charSize(const char8_t starter_ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_charSizeU8(starter_ch);
	}
	_SHINSEI_OS_INLINE int charSize(const char16_t starter_ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_charSizeU16(starter_ch);
	}
	_SHINSEI_OS_INLINE int charSize(const char32_t starter_ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_charSizeU32(starter_ch);
	}
	
	_SHINSEI_OS_INLINE bool isBDigitW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitW(ch);
	}
	_SHINSEI_OS_INLINE bool isBDigitWM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isBDigitCP(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isBDigitCPM(const unsigned int cp,const char** const restrict str_ptr,const ::size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isBDigitU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitU8(ch);
	}
	_SHINSEI_OS_INLINE bool isBDigitU8M(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isBDigitU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitU16(ch);
	}
	_SHINSEI_OS_INLINE bool isBDigitU16M(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isBDigitU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitU32(ch);
	}
	_SHINSEI_OS_INLINE bool isBDigitU32M(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isBDigit(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitW(ch);
	}
	_SHINSEI_OS_INLINE bool isBDigitM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isBDigit(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isBDigitM(const unsigned int cp,const char** const restrict str_ptr,const ::size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isBDigit(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitU8(ch);
	}
	_SHINSEI_OS_INLINE bool isBDigitM(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isBDigit(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitU16(ch);
	}
	_SHINSEI_OS_INLINE bool isBDigitM(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isBDigit(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitU32(ch);
	}
	_SHINSEI_OS_INLINE bool isBDigitM(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBDigitU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isODigitW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitW(ch);
	}
	_SHINSEI_OS_INLINE bool isODigitWM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isODigitCP(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isODigitCPM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isODigitU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitU8(ch);
	}
	_SHINSEI_OS_INLINE bool isODigitU8M(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isODigitU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitU16(ch);
	}
	_SHINSEI_OS_INLINE bool isODigitU16M(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isODigitU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitU32(ch);
	}
	_SHINSEI_OS_INLINE bool isODigitU32M(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isODigit(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitW(ch);
	}
	_SHINSEI_OS_INLINE bool isODigitM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isODigit(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isODigitM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isODigit(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitU8(ch);
	}
	_SHINSEI_OS_INLINE bool isODigitM(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isODigit(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitU16(ch);
	}
	_SHINSEI_OS_INLINE bool isODigitM(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isODigit(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitU32(ch);
	}
	_SHINSEI_OS_INLINE bool isODigitM(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isODigitU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isDigitW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitW(ch);
	}
	_SHINSEI_OS_INLINE bool isDigitWM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isDigitCP(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isDigitCPM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isDigitU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitU8(ch);
	}
	_SHINSEI_OS_INLINE bool isDigitU8M(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isDigitU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitU16(ch);
	}
	_SHINSEI_OS_INLINE bool isDigitU16M(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isDigitU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitU32(ch);
	}
	_SHINSEI_OS_INLINE bool isDigitU32M(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isDigit(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitW(ch);
	}
	_SHINSEI_OS_INLINE bool isDigitM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isDigit(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isDigitM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isDigit(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitU8(ch);
	}
	_SHINSEI_OS_INLINE bool isDigitM(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isDigit(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitU16(ch);
	}
	_SHINSEI_OS_INLINE bool isDigitM(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isDigit(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitU32(ch);
	}
	_SHINSEI_OS_INLINE bool isDigitM(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isDigitU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isXDigitW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitW(ch);
	}
	_SHINSEI_OS_INLINE bool isXDigitWM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isXDigitCP(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isXDigitCPM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isXDigitU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitU8(ch);
	}
	_SHINSEI_OS_INLINE bool isXDigitU8M(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isXDigitU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitU16(ch);
	}
	_SHINSEI_OS_INLINE bool isXDigitU16M(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isXDigitU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitU32(ch);
	}
	_SHINSEI_OS_INLINE bool isXDigitU32M(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isXDigit(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitW(ch);
	}
	_SHINSEI_OS_INLINE bool isXDigitM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isXDigit(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isXDigitM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isXDigit(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitU8(ch);
	}
	_SHINSEI_OS_INLINE bool isXDigitM(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isXDigit(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitU16(ch);
	}
	_SHINSEI_OS_INLINE bool isXDigitM(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isXDigit(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitU32(ch);
	}
	_SHINSEI_OS_INLINE bool isXDigitM(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isXDigitU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isUpperW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperW(ch);
	}
	_SHINSEI_OS_INLINE bool isUpperWM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUpperCP(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isUpperCPM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isUpperU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperU8(ch);
	}
	_SHINSEI_OS_INLINE bool isUpperU8M(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUpperU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperU16(ch);
	}
	_SHINSEI_OS_INLINE bool isUpperU16M(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUpperU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperU32(ch);
	}
	_SHINSEI_OS_INLINE bool isUpperU32M(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUpper(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperW(ch);
	}
	_SHINSEI_OS_INLINE bool isUpperM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUpper(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isUpperM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isUpper(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperU8(ch);
	}
	_SHINSEI_OS_INLINE bool isUpperM(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUpper(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperU16(ch);
	}
	_SHINSEI_OS_INLINE bool isUpperM(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isUpper(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperU32(ch);
	}
	_SHINSEI_OS_INLINE bool isUpperM(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isUpperU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isLowerW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerW(ch);
	}
	_SHINSEI_OS_INLINE bool isLowerWM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLowerCP(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isLowerCPM(const unsigned int cp,const char** const restrict str_ptr,const ::size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isLowerU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerU8(ch);
	}
	_SHINSEI_OS_INLINE bool isLowerU8M(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLowerU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerU16(ch);
	}
	_SHINSEI_OS_INLINE bool isLowerU16M(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLowerU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerU32(ch);
	}
	_SHINSEI_OS_INLINE bool isLowerU32M(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLower(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerW(ch);
	}
	_SHINSEI_OS_INLINE bool isLowerM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLower(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isLowerM(const unsigned int cp,const char** const restrict str_ptr,const ::size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isLower(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerU8(ch);
	}
	_SHINSEI_OS_INLINE bool isLowerM(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLower(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerU16(ch);
	}
	_SHINSEI_OS_INLINE bool isLowerM(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isLower(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerU32(ch);
	}
	_SHINSEI_OS_INLINE bool isLowerM(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isLowerU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isAlphaW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaW(ch);
	}
	_SHINSEI_OS_INLINE bool isAlphaWM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isAlphaCP(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isAlphaCPM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isAlphaU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaU8(ch);
	}
	_SHINSEI_OS_INLINE bool isAlphaU8M(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isAlphaU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaU16(ch);
	}
	_SHINSEI_OS_INLINE bool isAlphaU16M(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isAlphaU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaU32(ch);
	}
	_SHINSEI_OS_INLINE bool isAlphaU32M(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isAlpha(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaW(ch);
	}
	_SHINSEI_OS_INLINE bool isAlphaM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isAlpha(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isAlphaM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isAlpha(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaU8(ch);
	}
	_SHINSEI_OS_INLINE bool isAlphaM(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isAlpha(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaU16(ch);
	}
	_SHINSEI_OS_INLINE bool isAlphaM(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isAlpha(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaU32(ch);
	}
	_SHINSEI_OS_INLINE bool isAlphaM(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlphaU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isAlnumW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumW(ch);
	}
	_SHINSEI_OS_INLINE bool isAlnumWM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isAlnumCP(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isAlnumCPM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isAlnumU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumU8(ch);
	}
	_SHINSEI_OS_INLINE bool isAlnumU8M(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isAlnumU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumU16(ch);
	}
	_SHINSEI_OS_INLINE bool isAlnumU16M(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isAlnumU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumU32(ch);
	}
	_SHINSEI_OS_INLINE bool isAlnumU32M(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isAlnum(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumW(ch);
	}
	_SHINSEI_OS_INLINE bool isAlnumM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isAlnum(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isAlnumM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isAlnum(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumU8(ch);
	}
	_SHINSEI_OS_INLINE bool isAlnumM(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isAlnum(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumU16(ch);
	}
	_SHINSEI_OS_INLINE bool isAlnumM(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isAlnum(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumU32(ch);
	}
	_SHINSEI_OS_INLINE bool isAlnumM(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isAlnumU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isBlankW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankW(ch);
	}
	_SHINSEI_OS_INLINE bool isBlankWM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isBlankCP(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isBlankCPM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isBlankU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankU8(ch);
	}
	_SHINSEI_OS_INLINE bool isBlankU8M(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isBlankU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankU16(ch);
	}
	_SHINSEI_OS_INLINE bool isBlankU16M(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isBlankU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankU32(ch);
	}
	_SHINSEI_OS_INLINE bool isBlankU32M(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isBlank(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankW(ch);
	}
	_SHINSEI_OS_INLINE bool isBlankM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isBlank(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isBlankM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isBlank(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankU8(ch);
	}
	_SHINSEI_OS_INLINE bool isBlankM(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isBlank(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankU16(ch);
	}
	_SHINSEI_OS_INLINE bool isBlankM(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isBlank(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankU32(ch);
	}
	_SHINSEI_OS_INLINE bool isBlankM(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isBlankU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isCntrlW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlW(ch);
	}
	_SHINSEI_OS_INLINE bool isCntrlWM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCntrlCP(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isCntrlCPM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isCntrlU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlU8(ch);
	}
	_SHINSEI_OS_INLINE bool isCntrlU8M(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCntrlU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlU16(ch);
	}
	_SHINSEI_OS_INLINE bool isCntrlU16M(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCntrlU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlU32(ch);
	}
	_SHINSEI_OS_INLINE bool isCntrlU32M(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCntrl(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlW(ch);
	}
	_SHINSEI_OS_INLINE bool isCntrlM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCntrl(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isCntrlM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isCntrl(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlU8(ch);
	}
	_SHINSEI_OS_INLINE bool isCntrlM(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCntrl(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlU16(ch);
	}
	_SHINSEI_OS_INLINE bool isCntrlM(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isCntrl(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlU32(ch);
	}
	_SHINSEI_OS_INLINE bool isCntrlM(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isCntrlU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isPrintW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintW(ch);
	}
	_SHINSEI_OS_INLINE bool isPrintWM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isPrintCP(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isPrintCPM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isPrintU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintU8(ch);
	}
	_SHINSEI_OS_INLINE bool isPrintU8M(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isPrintU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintU16(ch);
	}
	_SHINSEI_OS_INLINE bool isPrintU16M(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isPrintU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintU32(ch);
	}
	_SHINSEI_OS_INLINE bool isPrintU32M(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isPrint(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintW(ch);
	}
	_SHINSEI_OS_INLINE bool isPrintM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isPrint(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isPrintM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isPrint(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintU8(ch);
	}
	_SHINSEI_OS_INLINE bool isPrintM(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isPrint(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintU16(ch);
	}
	_SHINSEI_OS_INLINE bool isPrintM(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isPrint(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintU32(ch);
	}
	_SHINSEI_OS_INLINE bool isPrintM(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPrintU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isGraphW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphW(ch);
	}
	_SHINSEI_OS_INLINE bool isGraphWM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isGraphCP(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isGraphCPM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isGraphU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphU8(ch);
	}
	_SHINSEI_OS_INLINE bool isGraphU8M(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isGraphU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphU16(ch);
	}
	_SHINSEI_OS_INLINE bool isGraphU16M(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isGraphU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphU32(ch);
	}
	_SHINSEI_OS_INLINE bool isGraphU32M(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isGraph(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphW(ch);
	}
	_SHINSEI_OS_INLINE bool isGraphM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isGraph(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isGraphM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isGraph(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphU8(ch);
	}
	_SHINSEI_OS_INLINE bool isGraphM(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isGraph(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphU16(ch);
	}
	_SHINSEI_OS_INLINE bool isGraphM(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isGraph(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphU32(ch);
	}
	_SHINSEI_OS_INLINE bool isGraphM(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isGraphU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isPunctW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctW(ch);
	}
	_SHINSEI_OS_INLINE bool isPunctWM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isPunctCP(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isPunctCPM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isPunctU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctU8(ch);
	}
	_SHINSEI_OS_INLINE bool isPunctU8M(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isPunctU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctU16(ch);
	}
	_SHINSEI_OS_INLINE bool isPunctU16M(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isPunctU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctU32(ch);
	}
	_SHINSEI_OS_INLINE bool isPunctU32M(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isPunct(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctW(ch);
	}
	_SHINSEI_OS_INLINE bool isPunctM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isPunct(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isPunctM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isPunct(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctU8(ch);
	}
	_SHINSEI_OS_INLINE bool isPunctM(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isPunct(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctU16(ch);
	}
	_SHINSEI_OS_INLINE bool isPunctM(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isPunct(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctU32(ch);
	}
	_SHINSEI_OS_INLINE bool isPunctM(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isPunctU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isSpaceW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceW(ch);
	}
	_SHINSEI_OS_INLINE bool isSpaceWM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSpaceCP(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isSpaceCPM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isSpaceU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceU8(ch);
	}
	_SHINSEI_OS_INLINE bool isSpaceU8M(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSpaceU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceU16(ch);
	}
	_SHINSEI_OS_INLINE bool isSpaceU16M(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSpaceU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceU32(ch);
	}
	_SHINSEI_OS_INLINE bool isSpaceU32M(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSpace(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceW(ch);
	}
	_SHINSEI_OS_INLINE bool isSpaceM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSpace(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isSpaceM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isSpace(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceU8(ch);
	}
	_SHINSEI_OS_INLINE bool isSpaceM(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSpace(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceU16(ch);
	}
	_SHINSEI_OS_INLINE bool isSpaceM(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isSpace(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceU32(ch);
	}
	_SHINSEI_OS_INLINE bool isSpaceM(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isSpaceU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE bool isJSONWhitespaceW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceW(ch);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespaceWM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespaceCP(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespaceCPM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespaceU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceU8(ch);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespaceU8M(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespaceU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceU16(ch);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespaceU16M(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespaceU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceU32(ch);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespaceU32M(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespace(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceW(ch);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespaceM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespace(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceCP(cp,ch);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespaceM(const unsigned int cp,const char**const restrict str_ptr,const ::size_t len,int*const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespace(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceU8(ch);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespaceM(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespace(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceU16(ch);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespaceM(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespace(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceU32(ch);
	}
	_SHINSEI_OS_INLINE bool isJSONWhitespaceM(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isJSONWhitespaceU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE wint_t toUpperW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperW(ch);
	}
	_SHINSEI_OS_INLINE wint_t toUpperWM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE int toUpperCP(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperCP(cp,ch);
	}
	_SHINSEI_OS_INLINE int toUpperCPM(const unsigned int cp,const char** const restrict str_ptr,const ::size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE char8_t toUpperU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperU8(ch);
	}
	_SHINSEI_OS_INLINE char8_t toUpperU8M(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE char16_t toUpperU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperU16(ch);
	}
	_SHINSEI_OS_INLINE char16_t toUpperU16M(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE char32_t toUpperU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperU32(ch);
	}
	_SHINSEI_OS_INLINE char32_t toUpperU32M(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE wint_t toUpper(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperW(ch);
	}
	_SHINSEI_OS_INLINE wint_t toUpperM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE int toUpper(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperCP(cp,ch);
	}
	_SHINSEI_OS_INLINE int toUpperM(const unsigned int cp,const char** const restrict str_ptr,const ::size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE char8_t toUpper(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperU8(ch);
	}
	_SHINSEI_OS_INLINE char8_t toUpperM(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE char16_t toUpper(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperU16(ch);
	}
	_SHINSEI_OS_INLINE char16_t toUpperM(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE char32_t toUpper(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperU32(ch);
	}
	_SHINSEI_OS_INLINE char32_t toUpperM(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toUpperU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE wint_t toLowerW(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerW(ch);
	}
	_SHINSEI_OS_INLINE wint_t toLowerWM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE int toLowerCP(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerCP(cp,ch);
	}
	_SHINSEI_OS_INLINE int toLowerCPM(const unsigned int cp,const char** const restrict str_ptr,const ::size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE char8_t toLowerU8(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerU8(ch);
	}
	_SHINSEI_OS_INLINE char8_t toLowerU8M(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE char16_t toLowerU16(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerU16(ch);
	}
	_SHINSEI_OS_INLINE char16_t toLowerU16M(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE char32_t toLowerU32(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerU32(ch);
	}
	_SHINSEI_OS_INLINE char32_t toLowerU32M(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerU32M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE wint_t toLower(const wint_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerW(ch);
	}
	_SHINSEI_OS_INLINE wint_t toLowerM(const wchar_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerWM(str_ptr,len);
	}
	_SHINSEI_OS_INLINE int toLower(const unsigned int cp,const int ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerCP(cp,ch);
	}
	_SHINSEI_OS_INLINE int toLowerM(const unsigned int cp,const char** const restrict str_ptr,const ::size_t len,int* const restrict status=nullptr)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerCPM(cp,str_ptr,len,status);
	}
	_SHINSEI_OS_INLINE char8_t toLower(const char8_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerU8(ch);
	}
	_SHINSEI_OS_INLINE char8_t toLowerM(const char8_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerU8M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE char16_t toLower(const char16_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerU16(ch);
	}
	_SHINSEI_OS_INLINE char16_t toLowerM(const char16_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerU16M(str_ptr,len);
	}
	_SHINSEI_OS_INLINE char32_t toLower(const char32_t ch)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerU32(ch);
	}
	_SHINSEI_OS_INLINE char32_t toLowerM(const char32_t**const restrict str_ptr,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_toLowerU32M(str_ptr,len);
	}
	
	_SHINSEI_OS_INLINE int isHexColorW(const wchar_t*const restrict str,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isHexColorW(str,len);
	}
	_SHINSEI_OS_INLINE int isHexColorCP(const unsigned int cp,const char*const restrict str,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isHexColorCP(cp,str,len);
	}
	_SHINSEI_OS_INLINE int isHexColorU8(const char8_t*const restrict str,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isHexColorU8(str,len);
	}
	_SHINSEI_OS_INLINE int isHexColorU16(const char16_t*const restrict str,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isHexColorU16(str,len);
	}
	_SHINSEI_OS_INLINE int isHexColorU32(const char32_t*const restrict str,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isHexColorU32(str,len);
	}
	_SHINSEI_OS_INLINE int isHexColor(const wchar_t*const restrict str,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isHexColorW(str,len);
	}
	_SHINSEI_OS_INLINE int isHexColor(const unsigned int cp,const char*const restrict str,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isHexColorCP(cp,str,len);
	}
	_SHINSEI_OS_INLINE int isHexColor(const char8_t*const restrict str,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isHexColorU8(str,len);
	}
	_SHINSEI_OS_INLINE int isHexColor(const char16_t*const restrict str,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isHexColorU16(str,len);
	}
	_SHINSEI_OS_INLINE int isHexColor(const char32_t*const restrict str,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_isHexColorU32(str,len);
	}
	
	_SHINSEI_OS_INLINE int uTF32CharToUTF16Char(char16_t*const restrict des,const char32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uTF32CharToUTF16Char(des,src);
	}
	_SHINSEI_OS_INLINE int uTF32CharToUTF8Char(char8_t*const restrict des,const char32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uTF32CharToUTF8Char(des,src);
	}
	_SHINSEI_OS_INLINE int uTF16CharToUTF8Char(char8_t*const restrict des,const char16_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uTF16CharToUTF8Char(des,src,src_len);
	}
	_SHINSEI_OS_INLINE int uTF16CharToUTF32Char(char32_t*const restrict des,const char16_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uTF16CharToUTF32Char(des,src,src_len);
	}
	_SHINSEI_OS_INLINE int uTF8CharToUTF32Char(char32_t*const restrict des,const char8_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uTF8CharToUTF32Char(des,src,src_len);
	}
	_SHINSEI_OS_INLINE int uTF8CharToUTF16Char(char16_t*const restrict des,const char8_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uTF8CharToUTF16Char(des,src,src_len);
	}
	
	_SHINSEI_OS_INLINE ::size_t uTF32ToUTF16(char16_t*const restrict des,const ::size_t des_len,const char32_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uTF32ToUTF16(des,des_len,src,src_len);
	}
	_SHINSEI_OS_INLINE ::size_t uTF32ToUTF8(char8_t*const restrict des,const ::size_t des_len,const char32_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uTF32ToUTF8(des,des_len,src,src_len);
	}
	_SHINSEI_OS_INLINE ::size_t uTF16ToUTF8(char8_t*const restrict des,const ::size_t des_len,const char16_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uTF16ToUTF8(des,des_len,src,src_len);
	}
	_SHINSEI_OS_INLINE ::size_t uTF16ToUTF32(char32_t*const restrict des,const ::size_t des_len,const char16_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uTF16ToUTF32(des,des_len,src,src_len);
	}
	_SHINSEI_OS_INLINE ::size_t uTF8ToUTF32(char32_t*const restrict des,const ::size_t des_len,const char8_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uTF8ToUTF32(des,des_len,src,src_len);
	}
	_SHINSEI_OS_INLINE ::size_t uTF8ToUTF16(char16_t*const restrict des,const ::size_t des_len,const char8_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uTF8ToUTF16(des,des_len,src,src_len);
	}
	
	_SHINSEI_OS_INLINE ::size_t stringLinesW(::size_t*restrict idx_buf,::size_t idx_buf_len,wchar_t*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringLinesW(idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t stringLinesCP(const unsigned int cp,::size_t*restrict idx_buf,::size_t idx_buf_len,char*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringLinesCP(cp,idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t stringLinesU8(::size_t*restrict idx_buf,::size_t idx_buf_len,char8_t*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringLinesU8(idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t stringLinesU16(::size_t*restrict idx_buf,::size_t idx_buf_len,char16_t*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringLinesU16(idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t stringLinesU32(::size_t*restrict idx_buf,::size_t idx_buf_len,char32_t*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringLinesU32(idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t stringLines(::size_t*restrict idx_buf,::size_t idx_buf_len,wchar_t*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringLinesW(idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t stringLines(const unsigned int cp,::size_t*restrict idx_buf,::size_t idx_buf_len,char*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringLinesCP(cp,idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t stringLines(::size_t*restrict idx_buf,::size_t idx_buf_len,char8_t*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringLinesU8(idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t stringLines(::size_t*restrict idx_buf,::size_t idx_buf_len,char16_t*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringLinesU16(idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t stringLines(::size_t*restrict idx_buf,::size_t idx_buf_len,char32_t*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringLinesU32(idx_buf,idx_buf_len,str,str_len);
	}
	
	_SHINSEI_OS_INLINE ::size_t findStringsW(::size_t*restrict idx_buf,::size_t idx_buf_len,wchar_t*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_findStringsW(idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t findStringsCP(const unsigned int cp,::size_t*restrict idx_buf,::size_t idx_buf_len,char*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_findStringsCP(cp,idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t findStringsU8(::size_t*restrict idx_buf,::size_t idx_buf_len,char8_t*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_findStringsU8(idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t findStringsU16(::size_t*restrict idx_buf,::size_t idx_buf_len,char16_t*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_findStringsU16(idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t findStringsU32(::size_t*restrict idx_buf,::size_t idx_buf_len,char32_t*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_findStringsU32(idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t findStrings(::size_t*restrict idx_buf,::size_t idx_buf_len,wchar_t*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_findStringsW(idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t findStrings(const unsigned int cp,::size_t*restrict idx_buf,::size_t idx_buf_len,char*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_findStringsCP(cp,idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t findStrings(::size_t*restrict idx_buf,::size_t idx_buf_len,char8_t*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_findStringsU8(idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t findStrings(::size_t*restrict idx_buf,::size_t idx_buf_len,char16_t*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_findStringsU16(idx_buf,idx_buf_len,str,str_len);
	}
	_SHINSEI_OS_INLINE ::size_t findStrings(::size_t*restrict idx_buf,::size_t idx_buf_len,char32_t*restrict str,const ::size_t str_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_findStringsU32(idx_buf,idx_buf_len,str,str_len);
	}
	
	_SHINSEI_OS_INLINE ::size_t splitStringToPartsW(wchar_t*const restrict des_buf,const ::size_t des_buf_len,const wchar_t*const restrict src,const ::size_t src_len,const ::size_t part_len,const ::size_t max_part_cnt,const wchar_t delimiter)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToPartsW(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
	}
	_SHINSEI_OS_INLINE ::size_t splitStringToParts(wchar_t*const restrict des_buf,const ::size_t des_buf_len,const wchar_t*const restrict src,const ::size_t src_len,const ::size_t part_len,const ::size_t max_part_cnt,const wchar_t delimiter)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToPartsW(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
	}
	_SHINSEI_OS_INLINE ::size_t splitStringToPartsCP(const unsigned int cp,char*const restrict des_buf,const ::size_t des_buf_len,const char*const restrict src,const ::size_t src_len,const ::size_t part_len,const ::size_t max_part_cnt,const char delimiter)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToPartsCP(cp,des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
	}
	_SHINSEI_OS_INLINE ::size_t splitStringToParts(const unsigned int cp,char*const restrict des_buf,const ::size_t des_buf_len,const char*const restrict src,const ::size_t src_len,const ::size_t part_len,const ::size_t max_part_cnt,const char delimiter)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToPartsCP(cp,des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
	}
	_SHINSEI_OS_INLINE ::size_t splitStringToPartsU8(char8_t*const restrict des_buf,const ::size_t des_buf_len,const char8_t*const restrict src,const ::size_t src_len,const ::size_t part_len,const ::size_t max_part_cnt,const char8_t delimiter)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToPartsU8(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
	}
	_SHINSEI_OS_INLINE ::size_t splitStringToParts(char8_t*const restrict des_buf,const ::size_t des_buf_len,const char8_t*const restrict src,const ::size_t src_len,const ::size_t part_len,const ::size_t max_part_cnt,const char8_t delimiter)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToPartsU8(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
	}
	_SHINSEI_OS_INLINE ::size_t splitStringToPartsU16(char16_t*const restrict des_buf,const ::size_t des_buf_len,const char16_t*const restrict src,const ::size_t src_len,const ::size_t part_len,const ::size_t max_part_cnt,const char16_t delimiter)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToPartsU16(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
	}
	_SHINSEI_OS_INLINE ::size_t splitStringToParts(char16_t*const restrict des_buf,const ::size_t des_buf_len,const char16_t*const restrict src,const ::size_t src_len,const ::size_t part_len,const ::size_t max_part_cnt,const char16_t delimiter)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToPartsU16(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
	}
	_SHINSEI_OS_INLINE ::size_t splitStringToPartsU32(char32_t*const restrict des_buf,const ::size_t des_buf_len,const char32_t*const restrict src,const ::size_t src_len,const ::size_t part_len,const ::size_t max_part_cnt,const char32_t delimiter)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToPartsU32(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
	}
	_SHINSEI_OS_INLINE ::size_t splitStringToParts(char32_t*const restrict des_buf,const ::size_t des_buf_len,const char32_t*const restrict src,const ::size_t src_len,const ::size_t part_len,const ::size_t max_part_cnt,const char32_t delimiter)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_splitStringToPartsU32(des_buf,des_buf_len,src,src_len,part_len,max_part_cnt,delimiter);
	}
	
	// strLen
	inline ::size_t strLenW(const wchar_t*const restrict str)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strLenW(str);
	}
	inline ::size_t strLen(const wchar_t*const restrict str)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strLenW(str);
	}
	inline ::size_t strLenCP(const unsigned int cp,const char*const restrict str)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strLenCP(cp,str);
	}
	inline ::size_t strLen(const unsigned int cp,const char*const restrict str)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strLenCP(cp,str);
	}
	inline ::size_t strLenU8(const char8_t*const restrict str)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strLenU8(str);
	}
	inline ::size_t strLen(const char8_t*const restrict str)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strLenU8(str);
	}
	inline ::size_t strLenU16(const char16_t*const restrict str)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strLenU16(str);
	}
	inline ::size_t strLen(const char16_t*const restrict str)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strLenU16(str);
	}
	inline ::size_t strLenU32(const char32_t*const restrict str)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strLenU32(str);
	}
	inline ::size_t strLen(const char32_t*const restrict str)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strLenU32(str);
	}
	
	// strCpy
	inline void strCpyW(wchar_t*const restrict des,const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_strCpyW(des,src,len);
	}
	inline void strCpy(wchar_t*const restrict des,const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_strCpyW(des,src,len);
	}
	inline void strCpyCP(const unsigned int cp,char*const restrict des,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_strCpyCP(cp,des,src,len);
	}
	inline void strCpy(const unsigned int cp,char*const restrict des,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_strCpyCP(cp,des,src,len);
	}
	inline void strCpyU8(char8_t*const restrict des,const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_strCpyU8(des,src,len);
	}
	inline void strCpy(char8_t*const restrict des,const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_strCpyU8(des,src,len);
	}
	inline void strCpyU16(char16_t*const restrict des,const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_strCpyU16(des,src,len);
	}
	inline void strCpy(char16_t*const restrict des,const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_strCpyU16(des,src,len);
	}
	inline void strCpyU32(char32_t*const restrict des,const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_strCpyU32(des,src,len);
	}
	inline void strCpy(char32_t*const restrict des,const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		::shinsei_strCpyU32(des,src,len);
	}
	
	// strCat
	inline ::size_t strCatW(wchar_t*const restrict des,const ::size_t des_len,const wchar_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCatW(des,des_len,src,src_len);
	}
	inline ::size_t strCat(wchar_t*const restrict des,const ::size_t des_len,const wchar_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCatW(des,des_len,src,src_len);
	}
	inline ::size_t strCatCP(const unsigned int cp,char*const restrict des,const ::size_t des_len,const char*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCatCP(cp,des,des_len,src,src_len);
	}
	inline ::size_t strCat(const unsigned int cp,char*const restrict des,const ::size_t des_len,const char*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCatCP(cp,des,des_len,src,src_len);
	}
	inline ::size_t strCatU8(char8_t*const restrict des,const ::size_t des_len,const char8_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCatU8(des,des_len,src,src_len);
	}
	inline ::size_t strCat(char8_t*const restrict des,const ::size_t des_len,const char8_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCatU8(des,des_len,src,src_len);
	}
	inline ::size_t strCatU16(char16_t*const restrict des,const ::size_t des_len,const char16_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCatU16(des,des_len,src,src_len);
	}
	inline ::size_t strCat(char16_t*const restrict des,const ::size_t des_len,const char16_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCatU16(des,des_len,src,src_len);
	}
	inline ::size_t strCatU32(char32_t*const restrict des,const ::size_t des_len,const char32_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCatU32(des,des_len,src,src_len);
	}
	inline ::size_t strCat(char32_t*const restrict des,const ::size_t des_len,const char32_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCatU32(des,des_len,src,src_len);
	}
	
	// strCmp
	inline int strCmpW(const wchar_t*const restrict des,const ::size_t des_len,const wchar_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCmpW(des,des_len,src,src_len);
	}
	inline int strCmp(const wchar_t*const restrict des,const ::size_t des_len,const wchar_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCmpW(des,des_len,src,src_len);
	}
	inline int strCmpCP(const unsigned int cp,const char*const restrict des,const ::size_t des_len,const char*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCmpCP(cp,des,des_len,src,src_len);
	}
	inline int strCmp(const unsigned int cp,const char*const restrict des,const ::size_t des_len,const char*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCmpCP(cp,des,des_len,src,src_len);
	}
	inline int strCmpU8(const char8_t*const restrict des,const ::size_t des_len,const char8_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCmpU8(des,des_len,src,src_len);
	}
	inline int strCmp(const char8_t*const restrict des,const ::size_t des_len,const char8_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCmpU8(des,des_len,src,src_len);
	}
	inline int strCmpU16(const char16_t*const restrict des,const ::size_t des_len,const char16_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCmpU16(des,des_len,src,src_len);
	}
	inline int strCmp(const char16_t*const restrict des,const ::size_t des_len,const char16_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCmpU16(des,des_len,src,src_len);
	}
	inline int strCmpU32(const char32_t*const restrict des,const ::size_t des_len,const char32_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCmpU32(des,des_len,src,src_len);
	}
	inline int strCmp(const char32_t*const restrict des,const ::size_t des_len,const char32_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strCmpU32(des,des_len,src,src_len);
	}
	
	// strChr
	inline ::size_t strChrW(const wchar_t*const restrict des,const ::size_t des_len,const wchar_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strChrW(des,des_len,src);
	}
	inline ::size_t strChr(const wchar_t*const restrict des,const ::size_t des_len,const wchar_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strChrW(des,des_len,src);
	}
	inline ::size_t strChrCP(const unsigned int cp,const char*const restrict des,const ::size_t des_len,const char src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strChrCP(cp,des,des_len,src);
	}
	inline ::size_t strChr(const unsigned int cp,const char*const restrict des,const ::size_t des_len,const char src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strChrCP(cp,des,des_len,src);
	}
	inline ::size_t strChrU8(const char8_t*const restrict des,const ::size_t des_len,const char8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strChrU8(des,des_len,src);
	}
	inline ::size_t strChr(const char8_t*const restrict des,const ::size_t des_len,const char8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strChrU8(des,des_len,src);
	}
	inline ::size_t strChrU16(const char16_t*const restrict des,const ::size_t des_len,const char16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strChrU16(des,des_len,src);
	}
	inline ::size_t strChr(const char16_t*const restrict des,const ::size_t des_len,const char16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strChrU16(des,des_len,src);
	}
	inline ::size_t strChrU32(const char32_t*const restrict des,const ::size_t des_len,const char32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strChrU32(des,des_len,src);
	}
	inline ::size_t strChr(const char32_t*const restrict des,const ::size_t des_len,const char32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strChrU32(des,des_len,src);
	}
	
	// strStr
	inline ::size_t strStrW(const wchar_t*const restrict des,const ::size_t des_len,const wchar_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strStrW(des,des_len,src,src_len);
	}
	inline ::size_t strStr(const wchar_t*const restrict des,const ::size_t des_len,const wchar_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strStrW(des,des_len,src,src_len);
	}
	inline ::size_t strStrCP(const unsigned int cp,const char*const restrict des,const ::size_t des_len,const char*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strStrCP(cp,des,des_len,src,src_len);
	}
	inline ::size_t strStr(const unsigned int cp,const char*const restrict des,const ::size_t des_len,const char*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strStrCP(cp,des,des_len,src,src_len);
	}
	inline ::size_t strStrU8(const char8_t*const restrict des,const ::size_t des_len,const char8_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strStrU8(des,des_len,src,src_len);
	}
	inline ::size_t strStr(const char8_t*const restrict des,const ::size_t des_len,const char8_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strStrU8(des,des_len,src,src_len);
	}
	inline ::size_t strStrU16(const char16_t*const restrict des,const ::size_t des_len,const char16_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strStrU16(des,des_len,src,src_len);
	}
	inline ::size_t strStr(const char16_t*const restrict des,const ::size_t des_len,const char16_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strStrU16(des,des_len,src,src_len);
	}
	inline ::size_t strStrU32(const char32_t*const restrict des,const ::size_t des_len,const char32_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strStrU32(des,des_len,src,src_len);
	}
	inline ::size_t strStr(const char32_t*const restrict des,const ::size_t des_len,const char32_t*const restrict src,const ::size_t src_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strStrU32(des,des_len,src,src_len);
	}
	
	// strKMP
	inline ::size_t strKMPW(const wchar_t*const restrict des,const ::size_t des_len,const wchar_t*const restrict src,const ::size_t src_len,::size_t*const restrict buf,const ::size_t buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strKMPW(des,des_len,src,src_len,buf,buf_len);
	}
	inline ::size_t strKMP(const wchar_t*const restrict des,const ::size_t des_len,const wchar_t*const restrict src,const ::size_t src_len,::size_t*const restrict buf,const ::size_t buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strKMPW(des,des_len,src,src_len,buf,buf_len);
	}
	inline ::size_t strKMPCP(const unsigned int cp,const char*const restrict des,const ::size_t des_len,const char*const restrict src,const ::size_t src_len,::size_t*const restrict buf,const ::size_t buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strKMPCP(cp,des,des_len,src,src_len,buf,buf_len);
	}
	inline ::size_t strKMP(const unsigned int cp,const char*const restrict des,const ::size_t des_len,const char*const restrict src,const ::size_t src_len,::size_t*const restrict buf,const ::size_t buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strKMPCP(cp,des,des_len,src,src_len,buf,buf_len);
	}
	inline ::size_t strKMPU8(const char8_t*const restrict des,const ::size_t des_len,const char8_t*const restrict src,const ::size_t src_len,::size_t*const restrict buf,const ::size_t buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strKMPU8(des,des_len,src,src_len,buf,buf_len);
	}
	inline ::size_t strKMP(const char8_t*const restrict des,const ::size_t des_len,const char8_t*const restrict src,const ::size_t src_len,::size_t*const restrict buf,const ::size_t buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strKMPU8(des,des_len,src,src_len,buf,buf_len);
	}
	inline ::size_t strKMPU16(const char16_t*const restrict des,const ::size_t des_len,const char16_t*const restrict src,const ::size_t src_len,::size_t*const restrict buf,const ::size_t buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strKMPU16(des,des_len,src,src_len,buf,buf_len);
	}
	inline ::size_t strKMP(const char16_t*const restrict des,const ::size_t des_len,const char16_t*const restrict src,const ::size_t src_len,::size_t*const restrict buf,const ::size_t buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strKMPU16(des,des_len,src,src_len,buf,buf_len);
	}
	inline ::size_t strKMPU32(const char32_t*const restrict des,const ::size_t des_len,const char32_t*const restrict src,const ::size_t src_len,::size_t*const restrict buf,const ::size_t buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strKMPU32(des,des_len,src,src_len,buf,buf_len);
	}
	inline ::size_t strKMP(const char32_t*const restrict des,const ::size_t des_len,const char32_t*const restrict src,const ::size_t src_len,::size_t*const restrict buf,const ::size_t buf_len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_strKMPU32(des,des_len,src,src_len,buf,buf_len);
	}
	
	// Int8/UInt8 string converters (W)
	inline ::size_t uInt8ToStringW(wchar_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToStringW(des,src);
	}
	inline ::size_t uInt8ToBinStringW(wchar_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBinStringW(des,src);
	}
	inline ::size_t uInt8ToOctStringW(wchar_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToOctStringW(des,src);
	}
	inline ::size_t uInt8ToHexStringW(wchar_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToHexStringW(des,src);
	}
	inline ::size_t uInt8ToBase36StringW(wchar_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBase36StringW(des,src);
	}
	inline ::size_t uInt8ToBase62StringW(wchar_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBase62StringW(des,src);
	}

	inline ::size_t int8ToStringW(wchar_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToStringW(des,src);
	}
	inline ::size_t int8ToBinStringW(wchar_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBinStringW(des,src);
	}
	inline ::size_t int8ToOctStringW(wchar_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToOctStringW(des,src);
	}
	inline ::size_t int8ToHexStringW(wchar_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToHexStringW(des,src);
	}
	inline ::size_t int8ToBase36StringW(wchar_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBase36StringW(des,src);
	}
	inline ::size_t int8ToBase62StringW(wchar_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBase62StringW(des,src);
	}

	// Int8/UInt8 string converters (U8)
	inline ::size_t uInt8ToStringU8(char8_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToStringU8(des,src);
	}
	inline ::size_t uInt8ToBinStringU8(char8_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBinStringU8(des,src);
	}
	inline ::size_t uInt8ToOctStringU8(char8_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToOctStringU8(des,src);
	}
	inline ::size_t uInt8ToHexStringU8(char8_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToHexStringU8(des,src);
	}
	inline ::size_t uInt8ToBase36StringU8(char8_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBase36StringU8(des,src);
	}
	inline ::size_t uInt8ToBase62StringU8(char8_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBase62StringU8(des,src);
	}

	inline ::size_t int8ToStringU8(char8_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToStringU8(des,src);
	}
	inline ::size_t int8ToBinStringU8(char8_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBinStringU8(des,src);
	}
	inline ::size_t int8ToOctStringU8(char8_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToOctStringU8(des,src);
	}
	inline ::size_t int8ToHexStringU8(char8_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToHexStringU8(des,src);
	}
	inline ::size_t int8ToBase36StringU8(char8_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBase36StringU8(des,src);
	}
	inline ::size_t int8ToBase62StringU8(char8_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBase62StringU8(des,src);
	}

	// Int8/UInt8 string converters (U16)
	inline ::size_t uInt8ToStringU16(char16_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToStringU16(des,src);
	}
	inline ::size_t uInt8ToBinStringU16(char16_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBinStringU16(des,src);
	}
	inline ::size_t uInt8ToOctStringU16(char16_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToOctStringU16(des,src);
	}
	inline ::size_t uInt8ToHexStringU16(char16_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToHexStringU16(des,src);
	}
	inline ::size_t uInt8ToBase36StringU16(char16_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBase36StringU16(des,src);
	}
	inline ::size_t uInt8ToBase62StringU16(char16_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBase62StringU16(des,src);
	}

	inline ::size_t int8ToStringU16(char16_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToStringU16(des,src);
	}
	inline ::size_t int8ToBinStringU16(char16_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBinStringU16(des,src);
	}
	inline ::size_t int8ToOctStringU16(char16_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToOctStringU16(des,src);
	}
	inline ::size_t int8ToHexStringU16(char16_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToHexStringU16(des,src);
	}
	inline ::size_t int8ToBase36StringU16(char16_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBase36StringU16(des,src);
	}
	inline ::size_t int8ToBase62StringU16(char16_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBase62StringU16(des,src);
	}

	// Int8/UInt8 string converters (U32)
	inline ::size_t uInt8ToStringU32(char32_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToStringU32(des,src);
	}
	inline ::size_t uInt8ToBinStringU32(char32_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBinStringU32(des,src);
	}
	inline ::size_t uInt8ToOctStringU32(char32_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToOctStringU32(des,src);
	}
	inline ::size_t uInt8ToHexStringU32(char32_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToHexStringU32(des,src);
	}
	inline ::size_t uInt8ToBase36StringU32(char32_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBase36StringU32(des,src);
	}
	inline ::size_t uInt8ToBase62StringU32(char32_t*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBase62StringU32(des,src);
	}

	inline ::size_t int8ToStringU32(char32_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToStringU32(des,src);
	}
	inline ::size_t int8ToBinStringU32(char32_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBinStringU32(des,src);
	}
	inline ::size_t int8ToOctStringU32(char32_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToOctStringU32(des,src);
	}
	inline ::size_t int8ToHexStringU32(char32_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToHexStringU32(des,src);
	}
	inline ::size_t int8ToBase36StringU32(char32_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBase36StringU32(des,src);
	}
	inline ::size_t int8ToBase62StringU32(char32_t*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBase62StringU32(des,src);
	}

	// Int8/UInt8 string converters (CP)
	inline ::size_t uInt8ToStringCP(const unsigned int cp,char*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToStringCP(cp,des,src);
	}
	inline ::size_t uInt8ToBinStringCP(const unsigned int cp,char*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBinStringCP(cp,des,src);
	}
	inline ::size_t uInt8ToOctStringCP(const unsigned int cp,char*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToOctStringCP(cp,des,src);
	}
	inline ::size_t uInt8ToHexStringCP(const unsigned int cp,char*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToHexStringCP(cp,des,src);
	}
	inline ::size_t uInt8ToBase36StringCP(const unsigned int cp,char*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBase36StringCP(cp,des,src);
	}
	inline ::size_t uInt8ToBase62StringCP(const unsigned int cp,char*const restrict des,const ::uint_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt8ToBase62StringCP(cp,des,src);
	}

	inline ::size_t int8ToStringCP(const unsigned int cp,char*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToStringCP(cp,des,src);
	}
	inline ::size_t int8ToBinStringCP(const unsigned int cp,char*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBinStringCP(cp,des,src);
	}
	inline ::size_t int8ToOctStringCP(const unsigned int cp,char*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToOctStringCP(cp,des,src);
	}
	inline ::size_t int8ToHexStringCP(const unsigned int cp,char*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToHexStringCP(cp,des,src);
	}
	inline ::size_t int8ToBase36StringCP(const unsigned int cp,char*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBase36StringCP(cp,des,src);
	}
	inline ::size_t int8ToBase62StringCP(const unsigned int cp,char*const restrict des,const ::int_fast8_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int8ToBase62StringCP(cp,des,src);
	}
	
	// Int16/UInt16 string converters (W)
	inline ::size_t uInt16ToStringW(wchar_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToStringW(des,src);
	}
	inline ::size_t uInt16ToBinStringW(wchar_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBinStringW(des,src);
	}
	inline ::size_t uInt16ToOctStringW(wchar_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToOctStringW(des,src);
	}
	inline ::size_t uInt16ToHexStringW(wchar_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToHexStringW(des,src);
	}
	inline ::size_t uInt16ToBase36StringW(wchar_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBase36StringW(des,src);
	}
	inline ::size_t uInt16ToBase62StringW(wchar_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBase62StringW(des,src);
	}
	
	inline ::size_t int16ToStringW(wchar_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToStringW(des,src);
	}
	inline ::size_t int16ToBinStringW(wchar_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBinStringW(des,src);
	}
	inline ::size_t int16ToOctStringW(wchar_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToOctStringW(des,src);
	}
	inline ::size_t int16ToHexStringW(wchar_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToHexStringW(des,src);
	}
	inline ::size_t int16ToBase36StringW(wchar_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBase36StringW(des,src);
	}
	inline ::size_t int16ToBase62StringW(wchar_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBase62StringW(des,src);
	}
	
	// Int16/UInt16 string converters (U8)
	inline ::size_t uInt16ToStringU8(char8_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToStringU8(des,src);
	}
	inline ::size_t uInt16ToBinStringU8(char8_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBinStringU8(des,src);
	}
	inline ::size_t uInt16ToOctStringU8(char8_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToOctStringU8(des,src);
	}
	inline ::size_t uInt16ToHexStringU8(char8_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToHexStringU8(des,src);
	}
	inline ::size_t uInt16ToBase36StringU8(char8_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBase36StringU8(des,src);
	}
	inline ::size_t uInt16ToBase62StringU8(char8_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBase62StringU8(des,src);
	}
	
	inline ::size_t int16ToStringU8(char8_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToStringU8(des,src);
	}
	inline ::size_t int16ToBinStringU8(char8_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBinStringU8(des,src);
	}
	inline ::size_t int16ToOctStringU8(char8_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToOctStringU8(des,src);
	}
	inline ::size_t int16ToHexStringU8(char8_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToHexStringU8(des,src);
	}
	inline ::size_t int16ToBase36StringU8(char8_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBase36StringU8(des,src);
	}
	inline ::size_t int16ToBase62StringU8(char8_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBase62StringU8(des,src);
	}
	
	// Int16/UInt16 string converters (U16)
	inline ::size_t uInt16ToStringU16(char16_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToStringU16(des,src);
	}
	inline ::size_t uInt16ToBinStringU16(char16_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBinStringU16(des,src);
	}
	inline ::size_t uInt16ToOctStringU16(char16_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToOctStringU16(des,src);
	}
	inline ::size_t uInt16ToHexStringU16(char16_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToHexStringU16(des,src);
	}
	inline ::size_t uInt16ToBase36StringU16(char16_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBase36StringU16(des,src);
	}
	inline ::size_t uInt16ToBase62StringU16(char16_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBase62StringU16(des,src);
	}
	
	inline ::size_t int16ToStringU16(char16_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToStringU16(des,src);
	}
	inline ::size_t int16ToBinStringU16(char16_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBinStringU16(des,src);
	}
	inline ::size_t int16ToOctStringU16(char16_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToOctStringU16(des,src);
	}
	inline ::size_t int16ToHexStringU16(char16_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToHexStringU16(des,src);
	}
	inline ::size_t int16ToBase36StringU16(char16_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBase36StringU16(des,src);
	}
	inline ::size_t int16ToBase62StringU16(char16_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBase62StringU16(des,src);
	}
	
	// Int16/UInt16 string converters (U32)
	inline ::size_t uInt16ToStringU32(char32_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToStringU32(des,src);
	}
	inline ::size_t uInt16ToBinStringU32(char32_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBinStringU32(des,src);
	}
	inline ::size_t uInt16ToOctStringU32(char32_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToOctStringU32(des,src);
	}
	inline ::size_t uInt16ToHexStringU32(char32_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToHexStringU32(des,src);
	}
	inline ::size_t uInt16ToBase36StringU32(char32_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBase36StringU32(des,src);
	}
	inline ::size_t uInt16ToBase62StringU32(char32_t*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBase62StringU32(des,src);
	}
	
	inline ::size_t int16ToStringU32(char32_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToStringU32(des,src);
	}
	inline ::size_t int16ToBinStringU32(char32_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBinStringU32(des,src);
	}
	inline ::size_t int16ToOctStringU32(char32_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToOctStringU32(des,src);
	}
	inline ::size_t int16ToHexStringU32(char32_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToHexStringU32(des,src);
	}
	inline ::size_t int16ToBase36StringU32(char32_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBase36StringU32(des,src);
	}
	inline ::size_t int16ToBase62StringU32(char32_t*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBase62StringU32(des,src);
	}
	
	// Int16/UInt16 string converters (CP)
	inline ::size_t uInt16ToStringCP(const unsigned int cp,char*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToStringCP(cp,des,src);
	}
	inline ::size_t uInt16ToBinStringCP(const unsigned int cp,char*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBinStringCP(cp,des,src);
	}
	inline ::size_t uInt16ToOctStringCP(const unsigned int cp,char*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToOctStringCP(cp,des,src);
	}
	inline ::size_t uInt16ToHexStringCP(const unsigned int cp,char*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToHexStringCP(cp,des,src);
	}
	inline ::size_t uInt16ToBase36StringCP(const unsigned int cp,char*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBase36StringCP(cp,des,src);
	}
	inline ::size_t uInt16ToBase62StringCP(const unsigned int cp,char*const restrict des,const ::uint_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt16ToBase62StringCP(cp,des,src);
	}
	
	inline ::size_t int16ToStringCP(const unsigned int cp,char*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToStringCP(cp,des,src);
	}
	inline ::size_t int16ToBinStringCP(const unsigned int cp,char*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBinStringCP(cp,des,src);
	}
	inline ::size_t int16ToOctStringCP(const unsigned int cp,char*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToOctStringCP(cp,des,src);
	}
	inline ::size_t int16ToHexStringCP(const unsigned int cp,char*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToHexStringCP(cp,des,src);
	}
	inline ::size_t int16ToBase36StringCP(const unsigned int cp,char*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBase36StringCP(cp,des,src);
	}
	inline ::size_t int16ToBase62StringCP(const unsigned int cp,char*const restrict des,const ::int_fast16_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int16ToBase62StringCP(cp,des,src);
	}
	
	// Int32/UInt32 string converters (W)
	inline ::size_t uInt32ToStringW(wchar_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToStringW(des,src);
	}
	inline ::size_t uInt32ToBinStringW(wchar_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBinStringW(des,src);
	}
	inline ::size_t uInt32ToOctStringW(wchar_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToOctStringW(des,src);
	}
	inline ::size_t uInt32ToHexStringW(wchar_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToHexStringW(des,src);
	}
	inline ::size_t uInt32ToBase36StringW(wchar_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBase36StringW(des,src);
	}
	inline ::size_t uInt32ToBase62StringW(wchar_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBase62StringW(des,src);
	}
	
	inline ::size_t int32ToStringW(wchar_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToStringW(des,src);
	}
	inline ::size_t int32ToBinStringW(wchar_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBinStringW(des,src);
	}
	inline ::size_t int32ToOctStringW(wchar_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToOctStringW(des,src);
	}
	inline ::size_t int32ToHexStringW(wchar_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToHexStringW(des,src);
	}
	inline ::size_t int32ToBase36StringW(wchar_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBase36StringW(des,src);
	}
	inline ::size_t int32ToBase62StringW(wchar_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBase62StringW(des,src);
	}
	
	// Int32/UInt32 string converters (U8)
	inline ::size_t uInt32ToStringU8(char8_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToStringU8(des,src);
	}
	inline ::size_t uInt32ToBinStringU8(char8_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBinStringU8(des,src);
	}
	inline ::size_t uInt32ToOctStringU8(char8_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToOctStringU8(des,src);
	}
	inline ::size_t uInt32ToHexStringU8(char8_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToHexStringU8(des,src);
	}
	inline ::size_t uInt32ToBase36StringU8(char8_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBase36StringU8(des,src);
	}
	inline ::size_t uInt32ToBase62StringU8(char8_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBase62StringU8(des,src);
	}
	
	inline ::size_t int32ToStringU8(char8_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToStringU8(des,src);
	}
	inline ::size_t int32ToBinStringU8(char8_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBinStringU8(des,src);
	}
	inline ::size_t int32ToOctStringU8(char8_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToOctStringU8(des,src);
	}
	inline ::size_t int32ToHexStringU8(char8_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToHexStringU8(des,src);
	}
	inline ::size_t int32ToBase36StringU8(char8_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBase36StringU8(des,src);
	}
	inline ::size_t int32ToBase62StringU8(char8_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBase62StringU8(des,src);
	}
	
	// Int32/UInt32 string converters (U16)
	inline ::size_t uInt32ToStringU16(char16_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToStringU16(des,src);
	}
	inline ::size_t uInt32ToBinStringU16(char16_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBinStringU16(des,src);
	}
	inline ::size_t uInt32ToOctStringU16(char16_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToOctStringU16(des,src);
	}
	inline ::size_t uInt32ToHexStringU16(char16_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToHexStringU16(des,src);
	}
	inline ::size_t uInt32ToBase36StringU16(char16_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBase36StringU16(des,src);
	}
	inline ::size_t uInt32ToBase62StringU16(char16_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBase62StringU16(des,src);
	}
	
	inline ::size_t int32ToStringU16(char16_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToStringU16(des,src);
	}
	inline ::size_t int32ToBinStringU16(char16_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBinStringU16(des,src);
	}
	inline ::size_t int32ToOctStringU16(char16_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToOctStringU16(des,src);
	}
	inline ::size_t int32ToHexStringU16(char16_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToHexStringU16(des,src);
	}
	inline ::size_t int32ToBase36StringU16(char16_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBase36StringU16(des,src);
	}
	inline ::size_t int32ToBase62StringU16(char16_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBase62StringU16(des,src);
	}
	
	// Int32/UInt32 string converters (U32)
	inline ::size_t uInt32ToStringU32(char32_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToStringU32(des,src);
	}
	inline ::size_t uInt32ToBinStringU32(char32_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBinStringU32(des,src);
	}
	inline ::size_t uInt32ToOctStringU32(char32_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToOctStringU32(des,src);
	}
	inline ::size_t uInt32ToHexStringU32(char32_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToHexStringU32(des,src);
	}
	inline ::size_t uInt32ToBase36StringU32(char32_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBase36StringU32(des,src);
	}
	inline ::size_t uInt32ToBase62StringU32(char32_t*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBase62StringU32(des,src);
	}
	
	inline ::size_t int32ToStringU32(char32_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToStringU32(des,src);
	}
	inline ::size_t int32ToBinStringU32(char32_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBinStringU32(des,src);
	}
	inline ::size_t int32ToOctStringU32(char32_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToOctStringU32(des,src);
	}
	inline ::size_t int32ToHexStringU32(char32_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToHexStringU32(des,src);
	}
	inline ::size_t int32ToBase36StringU32(char32_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBase36StringU32(des,src);
	}
	inline ::size_t int32ToBase62StringU32(char32_t*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBase62StringU32(des,src);
	}
	
	// Int32/UInt32 string converters (CP)
	inline ::size_t uInt32ToStringCP(const unsigned int cp,char*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToStringCP(cp,des,src);
	}
	inline ::size_t uInt32ToBinStringCP(const unsigned int cp,char*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBinStringCP(cp,des,src);
	}
	inline ::size_t uInt32ToOctStringCP(const unsigned int cp,char*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToOctStringCP(cp,des,src);
	}
	inline ::size_t uInt32ToHexStringCP(const unsigned int cp,char*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToHexStringCP(cp,des,src);
	}
	inline ::size_t uInt32ToBase36StringCP(const unsigned int cp,char*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBase36StringCP(cp,des,src);
	}
	inline ::size_t uInt32ToBase62StringCP(const unsigned int cp,char*const restrict des,const ::uint_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt32ToBase62StringCP(cp,des,src);
	}
	
	inline ::size_t int32ToStringCP(const unsigned int cp,char*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToStringCP(cp,des,src);
	}
	inline ::size_t int32ToBinStringCP(const unsigned int cp,char*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBinStringCP(cp,des,src);
	}
	inline ::size_t int32ToOctStringCP(const unsigned int cp,char*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToOctStringCP(cp,des,src);
	}
	inline ::size_t int32ToHexStringCP(const unsigned int cp,char*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToHexStringCP(cp,des,src);
	}
	inline ::size_t int32ToBase36StringCP(const unsigned int cp,char*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBase36StringCP(cp,des,src);
	}
	inline ::size_t int32ToBase62StringCP(const unsigned int cp,char*const restrict des,const ::int_fast32_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int32ToBase62StringCP(cp,des,src);
	}
	
	// Int64/UInt64 string converters (W)
	inline ::size_t uInt64ToBinStringW(wchar_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBinStringW(des,src);
	}
	inline ::size_t uInt64ToOctStringW(wchar_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToOctStringW(des,src);
	}
	inline ::size_t uInt64ToHexStringW(wchar_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToHexStringW(des,src);
	}
	inline ::size_t uInt64ToBase36StringW(wchar_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBase36StringW(des,src);
	}
	inline ::size_t uInt64ToBase62StringW(wchar_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBase62StringW(des,src);
	}
	
	inline ::size_t int64ToStringW(wchar_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToStringW(des,src);
	}
	inline ::size_t int64ToBinStringW(wchar_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBinStringW(des,src);
	}
	inline ::size_t int64ToOctStringW(wchar_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToOctStringW(des,src);
	}
	inline ::size_t int64ToHexStringW(wchar_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToHexStringW(des,src);
	}
	inline ::size_t int64ToBase36StringW(wchar_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBase36StringW(des,src);
	}
	inline ::size_t int64ToBase62StringW(wchar_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBase62StringW(des,src);
	}
	
	// Int64/UInt64 string converters (U8)
	inline ::size_t uInt64ToStringU8(char8_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToStringU8(des,src);
	}
	inline ::size_t uInt64ToBinStringU8(char8_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBinStringU8(des,src);
	}
	inline ::size_t uInt64ToOctStringU8(char8_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToOctStringU8(des,src);
	}
	inline ::size_t uInt64ToHexStringU8(char8_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToHexStringU8(des,src);
	}
	inline ::size_t uInt64ToBase36StringU8(char8_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBase36StringU8(des,src);
	}
	inline ::size_t uInt64ToBase62StringU8(char8_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBase62StringU8(des,src);
	}
	
	inline ::size_t int64ToStringU8(char8_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToStringU8(des,src);
	}
	inline ::size_t int64ToBinStringU8(char8_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBinStringU8(des,src);
	}
	inline ::size_t int64ToOctStringU8(char8_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToOctStringU8(des,src);
	}
	inline ::size_t int64ToHexStringU8(char8_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToHexStringU8(des,src);
	}
	inline ::size_t int64ToBase36StringU8(char8_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBase36StringU8(des,src);
	}
	inline ::size_t int64ToBase62StringU8(char8_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBase62StringU8(des,src);
	}
	
	// Int64/UInt64 string converters (U16)
	inline ::size_t uInt64ToStringU16(char16_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToStringU16(des,src);
	}
	inline ::size_t uInt64ToBinStringU16(char16_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBinStringU16(des,src);
	}
	inline ::size_t uInt64ToOctStringU16(char16_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToOctStringU16(des,src);
	}
	inline ::size_t uInt64ToHexStringU16(char16_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToHexStringU16(des,src);
	}
	inline ::size_t uInt64ToBase36StringU16(char16_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBase36StringU16(des,src);
	}
	inline ::size_t uInt64ToBase62StringU16(char16_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBase62StringU16(des,src);
	}
	
	inline ::size_t int64ToStringU16(char16_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToStringU16(des,src);
	}
	inline ::size_t int64ToBinStringU16(char16_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBinStringU16(des,src);
	}
	inline ::size_t int64ToOctStringU16(char16_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToOctStringU16(des,src);
	}
	inline ::size_t int64ToHexStringU16(char16_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToHexStringU16(des,src);
	}
	inline ::size_t int64ToBase36StringU16(char16_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBase36StringU16(des,src);
	}
	inline ::size_t int64ToBase62StringU16(char16_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBase62StringU16(des,src);
	}
	
	// Int64/UInt64 string converters (U32)
	inline ::size_t uInt64ToStringU32(char32_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToStringU32(des,src);
	}
	inline ::size_t uInt64ToBinStringU32(char32_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBinStringU32(des,src);
	}
	inline ::size_t uInt64ToOctStringU32(char32_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToOctStringU32(des,src);
	}
	inline ::size_t uInt64ToHexStringU32(char32_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToHexStringU32(des,src);
	}
	inline ::size_t uInt64ToBase36StringU32(char32_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBase36StringU32(des,src);
	}
	inline ::size_t uInt64ToBase62StringU32(char32_t*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBase62StringU32(des,src);
	}
	
	inline ::size_t int64ToStringU32(char32_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToStringU32(des,src);
	}
	inline ::size_t int64ToBinStringU32(char32_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBinStringU32(des,src);
	}
	inline ::size_t int64ToOctStringU32(char32_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToOctStringU32(des,src);
	}
	inline ::size_t int64ToHexStringU32(char32_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToHexStringU32(des,src);
	}
	inline ::size_t int64ToBase36StringU32(char32_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBase36StringU32(des,src);
	}
	inline ::size_t int64ToBase62StringU32(char32_t*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBase62StringU32(des,src);
	}
	
	// Int64/UInt64 string converters (CP)
	inline ::size_t uInt64ToStringCP(const unsigned int cp,char*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToStringCP(cp,des,src);
	}
	inline ::size_t uInt64ToBinStringCP(const unsigned int cp,char*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBinStringCP(cp,des,src);
	}
	inline ::size_t uInt64ToOctStringCP(const unsigned int cp,char*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToOctStringCP(cp,des,src);
	}
	inline ::size_t uInt64ToHexStringCP(const unsigned int cp,char*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToHexStringCP(cp,des,src);
	}
	inline ::size_t uInt64ToBase36StringCP(const unsigned int cp,char*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBase36StringCP(cp,des,src);
	}
	inline ::size_t uInt64ToBase62StringCP(const unsigned int cp,char*const restrict des,const ::uint_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_uInt64ToBase62StringCP(cp,des,src);
	}
	
	inline ::size_t int64ToStringCP(const unsigned int cp,char*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToStringCP(cp,des,src);
	}
	inline ::size_t int64ToBinStringCP(const unsigned int cp,char*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBinStringCP(cp,des,src);
	}
	inline ::size_t int64ToOctStringCP(const unsigned int cp,char*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToOctStringCP(cp,des,src);
	}
	inline ::size_t int64ToHexStringCP(const unsigned int cp,char*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToHexStringCP(cp,des,src);
	}
	inline ::size_t int64ToBase36StringCP(const unsigned int cp,char*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBase36StringCP(cp,des,src);
	}
	inline ::size_t int64ToBase62StringCP(const unsigned int cp,char*const restrict des,const ::int_fast64_t src)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_int64ToBase62StringCP(cp,des,src);
	}
	
	// String to int8/uint8 converters (W)
	inline ::uint_fast8_t stringToUInt8W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt8W(src,len);
	}
	inline ::uint_fast8_t binStringToUInt8W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt8W(src,len);
	}
	inline ::uint_fast8_t octStringToUInt8W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt8W(src,len);
	}
	inline ::uint_fast8_t hexStringToUInt8W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt8W(src,len);
	}
	inline ::uint_fast8_t base36StringToUInt8W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt8W(src,len);
	}
	inline ::uint_fast8_t base62StringToUInt8W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt8W(src,len);
	}
	
	inline ::int_fast8_t stringToInt8W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt8W(src,len);
	}
	inline ::int_fast8_t binStringToInt8W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt8W(src,len);
	}
	inline ::int_fast8_t octStringToInt8W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt8W(src,len);
	}
	inline ::int_fast8_t hexStringToInt8W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt8W(src,len);
	}
	inline ::int_fast8_t base36StringToInt8W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt8W(src,len);
	}
	inline ::int_fast8_t base62StringToInt8W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt8W(src,len);
	}
	
	// String to int8/uint8 converters (U8)
	inline ::uint_fast8_t stringToUInt8U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt8U8(src,len);
	}
	inline ::uint_fast8_t binStringToUInt8U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt8U8(src,len);
	}
	inline ::uint_fast8_t octStringToUInt8U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt8U8(src,len);
	}
	inline ::uint_fast8_t hexStringToUInt8U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt8U8(src,len);
	}
	inline ::uint_fast8_t base36StringToUInt8U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt8U8(src,len);
	}
	inline ::uint_fast8_t base62StringToUInt8U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt8U8(src,len);
	}
	
	inline ::int_fast8_t stringToInt8U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt8U8(src,len);
	}
	inline ::int_fast8_t binStringToInt8U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt8U8(src,len);
	}
	inline ::int_fast8_t octStringToInt8U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt8U8(src,len);
	}
	inline ::int_fast8_t hexStringToInt8U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt8U8(src,len);
	}
	inline ::int_fast8_t base36StringToInt8U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt8U8(src,len);
	}
	inline ::int_fast8_t base62StringToInt8U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt8U8(src,len);
	}
	
	// String to int8/uint8 converters (U16)
	inline ::uint_fast8_t stringToUInt8U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt8U16(src,len);
	}
	inline ::uint_fast8_t binStringToUInt8U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt8U16(src,len);
	}
	inline ::uint_fast8_t octStringToUInt8U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt8U16(src,len);
	}
	inline ::uint_fast8_t hexStringToUInt8U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt8U16(src,len);
	}
	inline ::uint_fast8_t base36StringToUInt8U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt8U16(src,len);
	}
	inline ::uint_fast8_t base62StringToUInt8U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt8U16(src,len);
	}
	
	inline ::int_fast8_t stringToInt8U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt8U16(src,len);
	}
	inline ::int_fast8_t binStringToInt8U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt8U16(src,len);
	}
	inline ::int_fast8_t octStringToInt8U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt8U16(src,len);
	}
	inline ::int_fast8_t hexStringToInt8U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt8U16(src,len);
	}
	inline ::int_fast8_t base36StringToInt8U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt8U16(src,len);
	}
	inline ::int_fast8_t base62StringToInt8U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt8U16(src,len);
	}
	
	// String to int8/uint8 converters (U32)
	inline ::uint_fast8_t stringToUInt8U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt8U32(src,len);
	}
	inline ::uint_fast8_t binStringToUInt8U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt8U32(src,len);
	}
	inline ::uint_fast8_t octStringToUInt8U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt8U32(src,len);
	}
	inline ::uint_fast8_t hexStringToUInt8U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt8U32(src,len);
	}
	inline ::uint_fast8_t base36StringToUInt8U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt8U32(src,len);
	}
	inline ::uint_fast8_t base62StringToUInt8U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt8U32(src,len);
	}
	
	inline ::int_fast8_t stringToInt8U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt8U32(src,len);
	}
	inline ::int_fast8_t binStringToInt8U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt8U32(src,len);
	}
	inline ::int_fast8_t octStringToInt8U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt8U32(src,len);
	}
	inline ::int_fast8_t hexStringToInt8U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt8U32(src,len);
	}
	inline ::int_fast8_t base36StringToInt8U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt8U32(src,len);
	}
	inline ::int_fast8_t base62StringToInt8U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt8U32(src,len);
	}
	
	// String to int8/uint8 converters (CP)
	inline ::uint_fast8_t stringToUInt8CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt8CP(cp,src,len);
	}
	inline ::uint_fast8_t binStringToUInt8CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt8CP(cp,src,len);
	}
	inline ::uint_fast8_t octStringToUInt8CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt8CP(cp,src,len);
	}
	inline ::uint_fast8_t hexStringToUInt8CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt8CP(cp,src,len);
	}
	inline ::uint_fast8_t base36StringToUInt8CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt8CP(cp,src,len);
	}
	inline ::uint_fast8_t base62StringToUInt8CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt8CP(cp,src,len);
	}
	
	inline ::int_fast8_t stringToInt8CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt8CP(cp,src,len);
	}
	inline ::int_fast8_t binStringToInt8CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt8CP(cp,src,len);
	}
	inline ::int_fast8_t octStringToInt8CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt8CP(cp,src,len);
	}
	inline ::int_fast8_t hexStringToInt8CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt8CP(cp,src,len);
	}
	inline ::int_fast8_t base36StringToInt8CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt8CP(cp,src,len);
	}
	inline ::int_fast8_t base62StringToInt8CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt8CP(cp,src,len);
	}
	
	// String to int16/uint16 converters (W)
	inline ::uint_fast16_t stringToUInt16W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt16W(src,len);
	}
	inline ::uint_fast16_t binStringToUInt16W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt16W(src,len);
	}
	inline ::uint_fast16_t octStringToUInt16W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt16W(src,len);
	}
	inline ::uint_fast16_t hexStringToUInt16W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt16W(src,len);
	}
	inline ::uint_fast16_t base36StringToUInt16W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt16W(src,len);
	}
	inline ::uint_fast16_t base62StringToUInt16W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt16W(src,len);
	}
	
	inline ::int_fast16_t stringToInt16W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt16W(src,len);
	}
	inline ::int_fast16_t binStringToInt16W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt16W(src,len);
	}
	inline ::int_fast16_t octStringToInt16W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt16W(src,len);
	}
	inline ::int_fast16_t hexStringToInt16W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt16W(src,len);
	}
	inline ::int_fast16_t base36StringToInt16W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt16W(src,len);
	}
	inline ::int_fast16_t base62StringToInt16W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt16W(src,len);
	}
	
	// String to int16/uint16 converters (U8)
	inline ::uint_fast16_t stringToUInt16U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt16U8(src,len);
	}
	inline ::uint_fast16_t binStringToUInt16U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt16U8(src,len);
	}
	inline ::uint_fast16_t octStringToUInt16U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt16U8(src,len);
	}
	inline ::uint_fast16_t hexStringToUInt16U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt16U8(src,len);
	}
	inline ::uint_fast16_t base36StringToUInt16U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt16U8(src,len);
	}
	inline ::uint_fast16_t base62StringToUInt16U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt16U8(src,len);
	}
	
	inline ::int_fast16_t stringToInt16U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt16U8(src,len);
	}
	inline ::int_fast16_t binStringToInt16U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt16U8(src,len);
	}
	inline ::int_fast16_t octStringToInt16U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt16U8(src,len);
	}
	inline ::int_fast16_t hexStringToInt16U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt16U8(src,len);
	}
	inline ::int_fast16_t base36StringToInt16U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt16U8(src,len);
	}
	inline ::int_fast16_t base62StringToInt16U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt16U8(src,len);
	}
	
	// String to int16/uint16 converters (U16)
	inline ::uint_fast16_t stringToUInt16U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt16U16(src,len);
	}
	inline ::uint_fast16_t binStringToUInt16U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt16U16(src,len);
	}
	inline ::uint_fast16_t octStringToUInt16U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt16U16(src,len);
	}
	inline ::uint_fast16_t hexStringToUInt16U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt16U16(src,len);
	}
	inline ::uint_fast16_t base36StringToUInt16U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt16U16(src,len);
	}
	inline ::uint_fast16_t base62StringToUInt16U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt16U16(src,len);
	}
	
	inline ::int_fast16_t stringToInt16U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt16U16(src,len);
	}
	inline ::int_fast16_t binStringToInt16U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt16U16(src,len);
	}
	inline ::int_fast16_t octStringToInt16U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt16U16(src,len);
	}
	inline ::int_fast16_t hexStringToInt16U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt16U16(src,len);
	}
	inline ::int_fast16_t base36StringToInt16U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt16U16(src,len);
	}
	inline ::int_fast16_t base62StringToInt16U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt16U16(src,len);
	}
	
	// String to int16/uint16 converters (U32)
	inline ::uint_fast16_t stringToUInt16U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt16U32(src,len);
	}
	inline ::uint_fast16_t binStringToUInt16U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt16U32(src,len);
	}
	inline ::uint_fast16_t octStringToUInt16U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt16U32(src,len);
	}
	inline ::uint_fast16_t hexStringToUInt16U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt16U32(src,len);
	}
	inline ::uint_fast16_t base36StringToUInt16U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt16U32(src,len);
	}
	inline ::uint_fast16_t base62StringToUInt16U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt16U32(src,len);
	}
	
	inline ::int_fast16_t stringToInt16U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt16U32(src,len);
	}
	inline ::int_fast16_t binStringToInt16U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt16U32(src,len);
	}
	inline ::int_fast16_t octStringToInt16U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt16U32(src,len);
	}
	inline ::int_fast16_t hexStringToInt16U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt16U32(src,len);
	}
	inline ::int_fast16_t base36StringToInt16U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt16U32(src,len);
	}
	inline ::int_fast16_t base62StringToInt16U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt16U32(src,len);
	}
	
	// String to int16/uint16 converters (CP)
	inline ::uint_fast16_t stringToUInt16CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt16CP(cp,src,len);
	}
	inline ::uint_fast16_t binStringToUInt16CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt16CP(cp,src,len);
	}
	inline ::uint_fast16_t octStringToUInt16CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt16CP(cp,src,len);
	}
	inline ::uint_fast16_t hexStringToUInt16CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt16CP(cp,src,len);
	}
	inline ::uint_fast16_t base36StringToUInt16CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt16CP(cp,src,len);
	}
	inline ::uint_fast16_t base62StringToUInt16CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt16CP(cp,src,len);
	}
	
	inline ::int_fast16_t stringToInt16CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt16CP(cp,src,len);
	}
	inline ::int_fast16_t binStringToInt16CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt16CP(cp,src,len);
	}
	inline ::int_fast16_t octStringToInt16CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt16CP(cp,src,len);
	}
	inline ::int_fast16_t hexStringToInt16CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt16CP(cp,src,len);
	}
	inline ::int_fast16_t base36StringToInt16CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt16CP(cp,src,len);
	}
	inline ::int_fast16_t base62StringToInt16CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt16CP(cp,src,len);
	}
	
	// String to int32/uint32 converters (W)
	inline ::uint_fast32_t stringToUInt32W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt32W(src,len);
	}
	inline ::uint_fast32_t binStringToUInt32W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt32W(src,len);
	}
	inline ::uint_fast32_t octStringToUInt32W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt32W(src,len);
	}
	inline ::uint_fast32_t hexStringToUInt32W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt32W(src,len);
	}
	inline ::uint_fast32_t base36StringToUInt32W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt32W(src,len);
	}
	inline ::uint_fast32_t base62StringToUInt32W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt32W(src,len);
	}
	
	inline ::int_fast32_t stringToInt32W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt32W(src,len);
	}
	inline ::int_fast32_t binStringToInt32W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt32W(src,len);
	}
	inline ::int_fast32_t octStringToInt32W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt32W(src,len);
	}
	inline ::int_fast32_t hexStringToInt32W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt32W(src,len);
	}
	inline ::int_fast32_t base36StringToInt32W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt32W(src,len);
	}
	inline ::int_fast32_t base62StringToInt32W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt32W(src,len);
	}
	
	// String to int32/uint32 converters (U8)
	inline ::uint_fast32_t stringToUInt32U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt32U8(src,len);
	}
	inline ::uint_fast32_t binStringToUInt32U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt32U8(src,len);
	}
	inline ::uint_fast32_t octStringToUInt32U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt32U8(src,len);
	}
	inline ::uint_fast32_t hexStringToUInt32U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt32U8(src,len);
	}
	inline ::uint_fast32_t base36StringToUInt32U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt32U8(src,len);
	}
	inline ::uint_fast32_t base62StringToUInt32U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt32U8(src,len);
	}
	
	inline ::int_fast32_t stringToInt32U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt32U8(src,len);
	}
	inline ::int_fast32_t binStringToInt32U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt32U8(src,len);
	}
	inline ::int_fast32_t octStringToInt32U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt32U8(src,len);
	}
	inline ::int_fast32_t hexStringToInt32U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt32U8(src,len);
	}
	inline ::int_fast32_t base36StringToInt32U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt32U8(src,len);
	}
	inline ::int_fast32_t base62StringToInt32U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt32U8(src,len);
	}
	
	// String to int32/uint32 converters (U16)
	inline ::uint_fast32_t stringToUInt32U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt32U16(src,len);
	}
	inline ::uint_fast32_t binStringToUInt32U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt32U16(src,len);
	}
	inline ::uint_fast32_t octStringToUInt32U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt32U16(src,len);
	}
	inline ::uint_fast32_t hexStringToUInt32U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt32U16(src,len);
	}
	inline ::uint_fast32_t base36StringToUInt32U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt32U16(src,len);
	}
	inline ::uint_fast32_t base62StringToUInt32U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt32U16(src,len);
	}
	
	inline ::int_fast32_t stringToInt32U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt32U16(src,len);
	}
	inline ::int_fast32_t binStringToInt32U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt32U16(src,len);
	}
	inline ::int_fast32_t octStringToInt32U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt32U16(src,len);
	}
	inline ::int_fast32_t hexStringToInt32U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt32U16(src,len);
	}
	inline ::int_fast32_t base36StringToInt32U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt32U16(src,len);
	}
	inline ::int_fast32_t base62StringToInt32U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt32U16(src,len);
	}
	
	// String to int32/uint32 converters (U32)
	inline ::uint_fast32_t stringToUInt32U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt32U32(src,len);
	}
	inline ::uint_fast32_t binStringToUInt32U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt32U32(src,len);
	}
	inline ::uint_fast32_t octStringToUInt32U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt32U32(src,len);
	}
	inline ::uint_fast32_t hexStringToUInt32U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt32U32(src,len);
	}
	inline ::uint_fast32_t base36StringToUInt32U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt32U32(src,len);
	}
	inline ::uint_fast32_t base62StringToUInt32U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt32U32(src,len);
	}
	
	inline ::int_fast32_t stringToInt32U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt32U32(src,len);
	}
	inline ::int_fast32_t binStringToInt32U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt32U32(src,len);
	}
	inline ::int_fast32_t octStringToInt32U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt32U32(src,len);
	}
	inline ::int_fast32_t hexStringToInt32U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt32U32(src,len);
	}
	inline ::int_fast32_t base36StringToInt32U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt32U32(src,len);
	}
	inline ::int_fast32_t base62StringToInt32U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt32U32(src,len);
	}
	
	// String to int32/uint32 converters (CP)
	inline ::uint_fast32_t stringToUInt32CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt32CP(cp,src,len);
	}
	inline ::uint_fast32_t binStringToUInt32CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt32CP(cp,src,len);
	}
	inline ::uint_fast32_t octStringToUInt32CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt32CP(cp,src,len);
	}
	inline ::uint_fast32_t hexStringToUInt32CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt32CP(cp,src,len);
	}
	inline ::uint_fast32_t base36StringToUInt32CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt32CP(cp,src,len);
	}
	inline ::uint_fast32_t base62StringToUInt32CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt32CP(cp,src,len);
	}
	
	inline ::int_fast32_t stringToInt32CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt32CP(cp,src,len);
	}
	inline ::int_fast32_t binStringToInt32CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt32CP(cp,src,len);
	}
	inline ::int_fast32_t octStringToInt32CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt32CP(cp,src,len);
	}
	inline ::int_fast32_t hexStringToInt32CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt32CP(cp,src,len);
	}
	inline ::int_fast32_t base36StringToInt32CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt32CP(cp,src,len);
	}
	inline ::int_fast32_t base62StringToInt32CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt32CP(cp,src,len);
	}
	
	// String to int64/uint64 converters (W)
	inline ::uint_fast64_t stringToUInt64W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt64W(src,len);
	}
	inline ::uint_fast64_t binStringToUInt64W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt64W(src,len);
	}
	inline ::uint_fast64_t octStringToUInt64W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt64W(src,len);
	}
	inline ::uint_fast64_t hexStringToUInt64W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt64W(src,len);
	}
	inline ::uint_fast64_t base36StringToUInt64W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt64W(src,len);
	}
	inline ::uint_fast64_t base62StringToUInt64W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt64W(src,len);
	}
	
	inline ::int_fast64_t stringToInt64W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt64W(src,len);
	}
	inline ::int_fast64_t binStringToInt64W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt64W(src,len);
	}
	inline ::int_fast64_t octStringToInt64W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt64W(src,len);
	}
	inline ::int_fast64_t hexStringToInt64W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt64W(src,len);
	}
	inline ::int_fast64_t base36StringToInt64W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt64W(src,len);
	}
	inline ::int_fast64_t base62StringToInt64W(const wchar_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt64W(src,len);
	}
	
	// String to int64/uint64 converters (U8)
	inline ::uint_fast64_t stringToUInt64U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt64U8(src,len);
	}
	inline ::uint_fast64_t binStringToUInt64U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt64U8(src,len);
	}
	inline ::uint_fast64_t octStringToUInt64U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt64U8(src,len);
	}
	inline ::uint_fast64_t hexStringToUInt64U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt64U8(src,len);
	}
	inline ::uint_fast64_t base36StringToUInt64U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt64U8(src,len);
	}
	inline ::uint_fast64_t base62StringToUInt64U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt64U8(src,len);
	}
	
	inline ::int_fast64_t stringToInt64U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt64U8(src,len);
	}
	inline ::int_fast64_t binStringToInt64U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt64U8(src,len);
	}
	inline ::int_fast64_t octStringToInt64U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt64U8(src,len);
	}
	inline ::int_fast64_t hexStringToInt64U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt64U8(src,len);
	}
	inline ::int_fast64_t base36StringToInt64U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt64U8(src,len);
	}
	inline ::int_fast64_t base62StringToInt64U8(const char8_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt64U8(src,len);
	}
	
	// String to int64/uint64 converters (U16)
	inline ::uint_fast64_t stringToUInt64U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt64U16(src,len);
	}
	inline ::uint_fast64_t binStringToUInt64U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt64U16(src,len);
	}
	inline ::uint_fast64_t octStringToUInt64U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt64U16(src,len);
	}
	inline ::uint_fast64_t hexStringToUInt64U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt64U16(src,len);
	}
	inline ::uint_fast64_t base36StringToUInt64U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt64U16(src,len);
	}
	inline ::uint_fast64_t base62StringToUInt64U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt64U16(src,len);
	}
	
	inline ::int_fast64_t stringToInt64U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt64U16(src,len);
	}
	inline ::int_fast64_t binStringToInt64U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt64U16(src,len);
	}
	inline ::int_fast64_t octStringToInt64U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt64U16(src,len);
	}
	inline ::int_fast64_t hexStringToInt64U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt64U16(src,len);
	}
	inline ::int_fast64_t base36StringToInt64U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt64U16(src,len);
	}
	inline ::int_fast64_t base62StringToInt64U16(const char16_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt64U16(src,len);
	}
	
	// String to int64/uint64 converters (U32)
	inline ::uint_fast64_t stringToUInt64U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt64U32(src,len);
	}
	inline ::uint_fast64_t binStringToUInt64U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt64U32(src,len);
	}
	inline ::uint_fast64_t octStringToUInt64U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt64U32(src,len);
	}
	inline ::uint_fast64_t hexStringToUInt64U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt64U32(src,len);
	}
	inline ::uint_fast64_t base36StringToUInt64U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt64U32(src,len);
	}
	inline ::uint_fast64_t base62StringToUInt64U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt64U32(src,len);
	}
	
	inline ::int_fast64_t stringToInt64U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt64U32(src,len);
	}
	inline ::int_fast64_t binStringToInt64U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt64U32(src,len);
	}
	inline ::int_fast64_t octStringToInt64U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt64U32(src,len);
	}
	inline ::int_fast64_t hexStringToInt64U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt64U32(src,len);
	}
	inline ::int_fast64_t base36StringToInt64U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt64U32(src,len);
	}
	inline ::int_fast64_t base62StringToInt64U32(const char32_t*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt64U32(src,len);
	}
	
	// String to int64/uint64 converters (CP)
	inline ::uint_fast64_t stringToUInt64CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToUInt64CP(cp,src,len);
	}
	inline ::uint_fast64_t binStringToUInt64CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToUInt64CP(cp,src,len);
	}
	inline ::uint_fast64_t octStringToUInt64CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToUInt64CP(cp,src,len);
	}
	inline ::uint_fast64_t hexStringToUInt64CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToUInt64CP(cp,src,len);
	}
	inline ::uint_fast64_t base36StringToUInt64CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToUInt64CP(cp,src,len);
	}
	inline ::uint_fast64_t base62StringToUInt64CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToUInt64CP(cp,src,len);
	}
	
	inline ::int_fast64_t stringToInt64CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_stringToInt64CP(cp,src,len);
	}
	inline ::int_fast64_t binStringToInt64CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_binStringToInt64CP(cp,src,len);
	}
	inline ::int_fast64_t octStringToInt64CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_octStringToInt64CP(cp,src,len);
	}
	inline ::int_fast64_t hexStringToInt64CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_hexStringToInt64CP(cp,src,len);
	}
	inline ::int_fast64_t base36StringToInt64CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base36StringToInt64CP(cp,src,len);
	}
	inline ::int_fast64_t base62StringToInt64CP(const unsigned int cp,const char*const restrict src,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_base62StringToInt64CP(cp,src,len);
	}
	
	template<typename T>
	class string_t{
	private:
		::shinsei_string_t obj;
		
		// Raw internal construct helper
		string_t(::shinsei_string_t* ptr)_SHINSEI_OS_NOEXCEPT{
			__builtin_memcpy(&obj,ptr,sizeof(::shinsei_string_t));
			free(ptr); // Only freeing the outer struct wrapper,taking over data ownership
			return;
		}
	
	public:
		static _SHINSEI_OS_CONSTEXPR ::size_t DEF_CAP=::shinsei_string_t_DEF_CAP;
		
		// Default constructor
		string_t(){
			if(!::shinsei_string_t_as(&obj,sizeof(T))) throw std::bad_alloc();
			return;
		}
		// Code Page constructor
		explicit string_t(shinsei::code_page_t,unsigned int cp){
			if(!::shinsei_string_t_as(&obj,sizeof(T))) throw std::bad_alloc();
			codePage(true,cp);
			return;
		}
		// Capacity constructor
		explicit string_t(const ::size_t cap){
			if(!::shinsei_string_t_asCapacity(&obj,cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		// Copy constructor
		string_t(const string_t& src){
			if(!::shinsei_string_t_asCopy(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		// Move constructor
		string_t(string_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_asMove(&obj,src.cObj());
			return;
		}
		// From Char
		string_t(const ::size_t repeat_cnt,const T& ch){
			if(!::shinsei_string_t_asChar(&obj,&ch,repeat_cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		// Substring constructor
		string_t(const string_t& src,const ::size_t idx,const ::size_t len){
			if(!::shinsei_string_t_asSubstr(&obj,src.cObj(),idx,len)) throw std::bad_alloc();
			return;
		}
		string_t(const ::shinsei_string_t& src,const ::size_t idx,const ::size_t len){
			if(!::shinsei_string_t_asSubstr(&obj,&src,idx,len)) throw std::bad_alloc();
			return;
		}
		
		// In-place Constructors
		explicit string_t(shinsei::in_place_t){
			if(!::shinsei_string_t_as(&obj,sizeof(T))) throw std::bad_alloc();
			return;
		}
		explicit string_t(shinsei::in_place_t,const ::size_t cap){
			if(!::shinsei_string_t_asCapacity(&obj,cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		explicit string_t(shinsei::in_place_t,const string_t& src){
			if(!::shinsei_string_t_asCopy(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		explicit string_t(shinsei::in_place_t,string_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_asMove(&obj,src.cObj());
			return;
		}
		explicit string_t(shinsei::in_place_t,const ::size_t repeat_cnt,const T& ch){
			if(!::shinsei_string_t_asChar(&obj,&ch,repeat_cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		explicit string_t(shinsei::in_place_t,const string_t& src,const ::size_t idx,const ::size_t len){
			if(!::shinsei_string_t_asSubstr(&obj,src.cObj(),idx,len)) throw std::bad_alloc();
			return;
		}
		
		// Inlined Constructors
		explicit string_t(shinsei::inlined_t,const ::size_t cap)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_inl(&obj,cap,sizeof(T));
			return;
		}
		explicit string_t(shinsei::inlined_t,const string_t& src){
			if(!::shinsei_string_t_inlCopy(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		explicit string_t(shinsei::inlined_t,string_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_inlMove(&obj,src.cObj());
			return;
		}
		explicit string_t(shinsei::inlined_t,const ::size_t repeat_cnt,const T& ch)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_inlChar(&obj,&ch,repeat_cnt,sizeof(T));
			return;
		}
		explicit string_t(shinsei::inlined_t,const string_t& src,const ::size_t idx,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_inlSubstr(&obj,src.cObj(),idx,len);
			return;
		}
		
		// Destructor
		~string_t()_SHINSEI_OS_NOEXCEPT{
			if(!inlined()){
				::shinsei_string_t_freeData(&obj);
				// obj.data=nullptr;
			}
			return;
		}
		
		// Capacity & Size
		void expand(const ::size_t more_cap){
			if(!::shinsei_string_t_expand(&obj,more_cap)) throw std::bad_alloc();
			return;
		}
		void shrink(const ::size_t less_cap){
			if(!::shinsei_string_t_shrink(&obj,less_cap)) throw std::bad_alloc();
			return;
		}
		void reserve(const ::size_t cap){
			if(!::shinsei_string_t_reserve(&obj,cap)) throw std::bad_alloc();
			return;
		}
		void shrinkToFit(){
			if(!::shinsei_string_t_shrinkToFit(&obj)) throw std::bad_alloc();
			return;
		}
		bool empty()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_string_t_empty(&obj);
		}
		::size_t size()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_string_t_size(&obj);
		}
		::size_t length()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_string_t_length(&obj);
		}
		::size_t capacity()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_string_t_capacity(&obj);
		}
		
		// Element Access
		T& front()const _SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_string_t_front(&obj);
		}
		T& back()const _SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_string_t_back(&obj);
		}
		T& at(const ::size_t idx)_SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_string_t_at(&obj,idx);
		}
		const T& at(const ::size_t idx)const _SHINSEI_OS_NOEXCEPT{
			return *(const T*)::shinsei_string_t_at(&obj,idx);
		}
		T& operator[](const ::size_t idx)_SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_string_t_at(&obj,idx);
		}
		const T& operator[](const ::size_t idx)const _SHINSEI_OS_NOEXCEPT{
			return *(const T*)::shinsei_string_t_at(&obj,idx);
		}
		
		T* data()_SHINSEI_OS_NOEXCEPT{
			return (T*)::shinsei_string_t_data(&obj);
		}
		const T* data()const _SHINSEI_OS_NOEXCEPT{
			return (const T*)::shinsei_string_t_data(&obj);
		}
		const T* cStr()const _SHINSEI_OS_NOEXCEPT{
			return data();
		}
		const T* operator*()const _SHINSEI_OS_NOEXCEPT{
			return data();
		}
		
		// Unified Assignment
		void assign(const string_t& src){
			if(!::shinsei_string_t_assign(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		void assign(const T*const restrict src,const ::size_t len){
			if(!::shinsei_string_t_assignRaw(&obj,src,len)) throw std::bad_alloc();
			return;
		}
		void assign(const T& ch,const ::size_t len){
			if(!::shinsei_string_t_assignChar(&obj,&ch,len)) throw std::bad_alloc();
			return;
		}
		void copy(const string_t& src){
			assign(src);
			return;
		}
		
		string_t& operator=(const string_t& src){
			if(this==&src) return *this;
			assign(src);
			return *this;
		}
		string_t& operator=(string_t&& src)_SHINSEI_OS_NOEXCEPT{
			if(this==&src) return *this;
			this->move(src);
			return *this;
		}
		
		string_t& operator=(const T*const restrict src){
			::size_t len=0; while(src[len]) ++len;
			assign(src,len);
			return *this;
		}
		string_t& operator=(const T& ch){
			assign(ch,1);
			return *this;
		}
		
		// Unified Append
		void append(const string_t& src){
			if(!::shinsei_string_t_append(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		void append(const T*const restrict src,const ::size_t len){
			if(!::shinsei_string_t_appendRaw(&obj,src,len)) throw std::bad_alloc();
			return;
		}
		void append(const T& ch,const ::size_t len){
			if(!::shinsei_string_t_appendChar(&obj,&ch,len)) throw std::bad_alloc();
			return;
		}
		
		string_t& operator+=(const string_t& src){
			append(src);
			return *this;
		}
		string_t& operator+=(const T*const restrict src){
			::size_t len=0;
			while(src[len]) ++len;
			append(src,len);
			return *this;
		}
		string_t& operator+=(const T& ch){
			append(ch,1);
			return *this;
		}
		
		// Unified Push / Pop
		void pushBack(const T& val){
			if(!::shinsei_string_t_pushBack(&obj,&val)) throw std::bad_alloc();
			return;
		}
		void pushBack(const T*const restrict src,const ::size_t len){
			if(!::shinsei_string_t_pushBackArray(&obj,src,len)) throw std::bad_alloc();
			return;
		}
		void pushBack(const T& ch,const ::size_t repeat_cnt){
			if(!::shinsei_string_t_pushBackChar(&obj,&ch,repeat_cnt)) throw std::bad_alloc();
			return;
		}
		
		void popBack()_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_popBack(&obj);
			return;
		}
		void popBack(const ::size_t cnt)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_popBackArray(&obj,cnt);
			return;
		}
		
		// Unified Insert / Erase
		void insert(const ::size_t idx,const T& val){
			if(!::shinsei_string_t_insert(&obj,idx,&val)) throw std::bad_alloc();
			return;
		}
		void insert(const ::size_t idx,const T*const restrict src,const ::size_t len){
			if(!::shinsei_string_t_insertArray(&obj,idx,src,len)) throw std::bad_alloc();
			return;
		}
		void insert(const ::size_t idx,const T& ch,const ::size_t repeat_cnt){
			if(!::shinsei_string_t_insertChar(&obj,idx,&ch,repeat_cnt)) throw std::bad_alloc();
			return;
		}
		
		void erase(const ::size_t idx)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_erase(&obj,idx);
			return;
		}
		void erase(const ::size_t idx,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_eraseArray(&obj,idx,len);
			return;
		}
		
		// Unified Attach
		void attach(const string_t& src){
			if(!::shinsei_string_t_attach(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		void attach(const ::int_fast32_t ctrl,const unsigned int cp,const ::size_t size,const ::size_t cap,T*const ptr){
			if(!::shinsei_string_t_attachValue(&obj,ctrl,cp,size,cap,ptr,sizeof(T))) throw std::bad_alloc();
			return;
		}
		
		void swap(string_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_swap(&obj,src.cObj());
			return;
		}
		void clear(){
			if(!::shinsei_string_t_clear(&obj)) throw std::bad_alloc();
			return;
		}
		void setSize(const ::size_t size){
			if(!::shinsei_string_t_setSize(&obj,size)) throw std::bad_alloc();
			return;
		}
		void move(string_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_move(&obj,src.cObj());
			return;
		}
		
		// String Search / Ops
		::size_t find(const T*const restrict src,const ::size_t src_len)const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_string_t_find(&obj,src,src_len);
		}
		::size_t find(const T& ch)const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_string_t_findChar(&obj,&ch);
		}
		::size_t kMP(const T*const restrict src,const ::size_t src_len,::size_t*const restrict buf,const ::size_t buf_len)const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_string_t_kMP(&obj,src,src_len,buf,buf_len);
		}
		int compare(const T*const restrict src,const ::size_t src_len)const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_string_t_compare(&obj,src,src_len);
		}
		
		string_t substr(const ::size_t idx,const ::size_t len)const{
			::shinsei_string_t* new_ptr=::shinsei_string_t_substr(&obj,idx,len);
			if(!new_ptr) throw std::bad_alloc();
			return string_t(new_ptr); // Takes ownership safely
		}
		
		// Code Page Operations
		bool isCodepage()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_string_t_isCodepage(&obj);
		}
		unsigned int getCodePage()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_string_t_getCodePage(&obj);
		}
		void enableCodePage(const bool enabled)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_enableCodePage(&obj,enabled);
			return;
		}
		void setCodePage(const unsigned int cp)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_setCodePage(&obj,cp);
			return;
		}
		void codePage(const bool enabled,const unsigned int cp)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_codePage(&obj,enabled,cp);
			return;
		}
		
		// Unified Static Constructors (as)
		static void as(string_t*const restrict ptr){
			if(!::shinsei_string_t_as(ptr->cObj(),sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_string_t*const restrict ptr){
			if(!::shinsei_string_t_as(ptr,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(string_t*const restrict ptr,const ::size_t cap){
			if(!::shinsei_string_t_asCapacity(ptr->cObj(),cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_string_t*const restrict ptr,const ::size_t cap){
			if(!::shinsei_string_t_asCapacity(ptr,cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(string_t*const restrict ptr,const string_t& src){
			if(!::shinsei_string_t_asCopy(ptr->cObj(),src.cObj())) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_string_t*const restrict ptr,const ::shinsei_string_t& src){
			if(!::shinsei_string_t_asCopy(ptr,&src)) throw std::bad_alloc();
			return;
		}
		static void as(string_t*const restrict ptr,string_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_asMove(ptr->cObj(),src.cObj());
			return;
		}
		static void as(::shinsei_string_t*const restrict ptr,::shinsei_string_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_asMove(ptr,&src);
			return;
		}
		static void as(string_t*const restrict ptr,const T& ch,const ::size_t repeat_cnt){
			if(!::shinsei_string_t_asChar(ptr->cObj(),&ch,repeat_cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_string_t*const restrict ptr,const T& ch,const ::size_t repeat_cnt){
			if(!::shinsei_string_t_asChar(ptr,&ch,repeat_cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(string_t*const restrict ptr,const string_t& src,const ::size_t idx,const ::size_t len){
			if(!::shinsei_string_t_asSubstr(ptr->cObj(),src.cObj(),idx,len)) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_string_t*const restrict ptr,const ::shinsei_string_t& src,const ::size_t idx,const ::size_t len){
			if(!::shinsei_string_t_asSubstr(ptr,&src,idx,len)) throw std::bad_alloc();
			return;
		}
		
		// Unified Static Constructors (inl)
		static void inl(string_t*const restrict ptr,const ::size_t cap)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_inl(ptr->cObj(),cap,sizeof(T));
			return;
		}
		static void inl(::shinsei_string_t*const restrict ptr,const ::size_t cap)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_inl(ptr,cap,sizeof(T));
			return;
		}
		static void inl(string_t*const restrict ptr,const string_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_inlCopy(ptr->cObj(),src.cObj());
			return;
		}
		static void inl(::shinsei_string_t*const restrict ptr,const ::shinsei_string_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_inlCopy(ptr,&src);
			return;
		}
		static void inl(string_t*const restrict ptr,string_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_inlMove(ptr->cObj(),src.cObj());
			return;
		}
		static void inl(::shinsei_string_t*const restrict ptr,::shinsei_string_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_inlMove(ptr,&src);
			return;
		}
		static void inl(string_t*const restrict ptr,const T& ch,const ::size_t repeat_cnt)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_inlChar(ptr->cObj(),&ch,repeat_cnt,sizeof(T));
			return;
		}
		static void inl(::shinsei_string_t*const restrict ptr,const T& ch,const ::size_t repeat_cnt)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_inlChar(ptr,&ch,repeat_cnt,sizeof(T));
			return;
		}
		static void inl(string_t*const restrict ptr,const string_t& src,const ::size_t idx,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_inlSubstr(ptr->cObj(),src.cObj(),idx,len);
			return;
		}
		static void inl(::shinsei_string_t*const restrict ptr,const ::shinsei_string_t& src,const ::size_t idx,const ::size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_inlSubstr(ptr,&src,idx,len);
			return;
		}
		
		// Core Identity Controls
		bool inlined()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_string_t_inlined(&obj);
		}
		::int_fast32_t getCtrl()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_string_t_getCtrl(&obj);
		}
		void setCtrl(const ::int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
			::shinsei_string_t_setCtrl(&obj,ctrl);
		}
		
		// Type Casting / Access
		::shinsei_string_t* cObj()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		const ::shinsei_string_t* cObj()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator ::shinsei_string_t*()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator const ::shinsei_string_t*()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		
	};

	// Aliases
	using string_w_t=string_t<wchar_t>;
	using string_u8_t=string_t<char8_t>;
	using string_u16_t=string_t<char16_t>;
	using string_u32_t=string_t<char32_t>;
	using string_cp_t=string_t<char>; // Used logically with shinsei::code_page_t constructor
}
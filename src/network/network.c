#include"shinsei/minimal/network.h"

#include"shinsei/.internal/cpp_init.hpp"

#include"shinsei/.internal/str/ebcdic.h"

// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isEBCDICCodePage(register const uint_fast32_t id)_SHINSEI_OS_NOEXCEPT{
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
_SHINSEI_OS_INLINE static bool isDigitASCII(register const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-'0')<=9;
}
_SHINSEI_OS_INLINE static bool isDigitEBCDIC(register const int ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-0xF0)<=9;
}
_SHINSEI_OS_INLINE static bool isDigitCP(register const uint_fast32_t code_page,register const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic?isDigitEBCDIC(ch):isDigitASCII(ch);
}
_SHINSEI_OS_INLINE static bool isDigitU8(register const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return (ch-u8'0')<=9;
}
_SHINSEI_OS_INLINE static bool isDigitU16(register const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return (ch-u'0')<=9;
}
_SHINSEI_OS_INLINE static bool isDigitU32(register const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return (ch-U'0')<=9;
}

// Copy from str/str.c
_SHINSEI_OS_INLINE static bool isXDigitASCII(register const int ch)_SHINSEI_OS_NOEXCEPT{
	return isDigitASCII(ch)||(unsigned int)((ch|0x20)-'a')<=5;
}
_SHINSEI_OS_INLINE static bool isXDigitEBCDIC(register const int ch)_SHINSEI_OS_NOEXCEPT{
	return isDigitEBCDIC(ch)||(unsigned int)(ch-0x81)<=5||(unsigned int)(ch-0xC1)<=5;
}
_SHINSEI_OS_INLINE static bool isXDigitCP(register const uint_fast32_t code_page,register const int ch)_SHINSEI_OS_NOEXCEPT{
	register const bool ebcdic=isEBCDICCodePage(code_page);
	return ebcdic?isXDigitEBCDIC(ch):isXDigitASCII(ch);
}
_SHINSEI_OS_INLINE static bool isXDigitW(register const wint_t ch)_SHINSEI_OS_NOEXCEPT{
	return (unsigned int)(ch-L'0')<=9||(unsigned int)((ch|0x20)-L'a')<=5;
}
_SHINSEI_OS_INLINE static bool isXDigitU8(register const char8_t ch)_SHINSEI_OS_NOEXCEPT{
	return (ch-u8'0')<=9||(unsigned int)((ch|0x20)-u8'a')<=5;
}
_SHINSEI_OS_INLINE static bool isXDigitU16(register const char16_t ch)_SHINSEI_OS_NOEXCEPT{
	return (ch-u'0')<=9||(unsigned int)((ch|0x20)-u'a')<=5;
}
_SHINSEI_OS_INLINE static bool isXDigitU32(register const char32_t ch)_SHINSEI_OS_NOEXCEPT{
	return (ch-U'0')<=9||(unsigned int)((ch|0x20)-U'a')<=5;
}

// Convert string to IPv4 address
_SHINSEI_OS_INLINE static bool stringToIPv4CP(register const uint_fast32_t code_page,register uint32_t*const restrict des,register const char*const restrict src,register const size_t src_len){
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register uint_fast16_t res=0;
	register uint_fast8_t dot_cnt=0;
	register const char dot=ebcdic?0x4B:'.';
	register const char zero=(char)(ebcdic?0xF0:'0');
	*des=0;
	for(register size_t i=0;i<src_len;++i){
		if(isDigitCP(code_page,src[i])){
			res=(uint_fast16_t)((res<<3)+(res<<1)+(src[i]-zero));
			if(res>255) return false;
		}
		else if(src[i]==dot){
			if(dot_cnt++>=3) return false;
			*des=(*des<<8)|res;
			res=0;
		}
		else return false;
	}
	if(dot_cnt<3) return false;
	*des=(*des<<8)|res;
	return true;
}
_SHINSEI_OS_INLINE static bool stringToIPv4U8(register uint32_t*const restrict des,register const char8_t*const restrict src,register const size_t src_len){
	register uint_fast16_t res=0;
	register uint_fast8_t dot_cnt=0;
	*des=0;
	for(register size_t i=0;i<src_len;++i){
		if(isDigitU8(src[i])){
			res=(uint_fast16_t)((res<<3)+(res<<1)+(src[i]-u8'0'));
			if(res>255) return false;
		}
		else if(src[i]==u8'.'){
			if(dot_cnt++>=3) return false;
			*des=(*des<<8)|res;
			res=0;
		}
		else return false;
	}
	if(dot_cnt<3) return false;
	*des=(*des<<8)|res;
	return true;
}
_SHINSEI_OS_INLINE static bool stringToIPv4U16(register uint32_t*const restrict des,register const char16_t*const restrict src,register const size_t src_len){
	register uint_fast16_t res=0;
	register uint_fast8_t dot_cnt=0;
	*des=0;
	for(register size_t i=0;i<src_len;++i){
		if(isDigitU16(src[i])){
			res=(uint_fast16_t)((res<<3)+(res<<1)+(src[i]-u'0'));
			if(res>255) return false;
		}
		else if(src[i]==u'.'){
			if(dot_cnt++>=2) return false;
			*des=(*des<<8)|res;
			res=0;
		}
		else return false;
	}
	if(dot_cnt<3) return false;
	*des=(*des<<8)|res;
	return true;
}
_SHINSEI_OS_INLINE static bool stringToIPv4U32(register uint32_t*const restrict des,register const char32_t*const restrict src,register const size_t src_len){
	register uint_fast16_t res=0;
	register uint_fast8_t dot_cnt=0;
	*des=0;
	for(register size_t i=0;i<src_len;++i){
		if(isDigitU32(src[i])){
			res=(uint_fast16_t)((uint_fast16_t)(res<<3)+(uint_fast16_t)(res<<1)+(src[i]-U'0'));
			if(res>255) return false;
		}
		else if(src[i]==U'.'){
			if(dot_cnt++>=3) return false;
			*des=(*des<<8)|res;
			res=0;
		}
		else return false;
	}
	if(dot_cnt<3) return false;
	*des=(*des<<8)|res;
	return true;
}
_SHINSEI_OS_INLINE static bool stringToIPv4W(register uint32_t*const restrict des,register const wchar_t*const restrict src,register const size_t src_len){
	#ifdef _SHINSEI_WCHAR_U32
		return stringToIPv4U32(des,(const char32_t*)src,src_len);
	#else
		return stringToIPv4U16(des,(const char16_t*)src,src_len);
	#endif
}
bool shinsei_stringToIPv4CP(register const uint_fast32_t code_page,register uint32_t*const restrict des,register const char*const restrict src,register const size_t src_len){
	return stringToIPv4CP(code_page,des,src,src_len);
}
bool shinsei_stringToIPv4W(register uint32_t*const restrict des,register const wchar_t*const restrict src,register const size_t src_len){
	return stringToIPv4W(des,src,src_len);
}
bool shinsei_stringToIPv4U8(register uint32_t*const restrict des,register const char8_t*const restrict src,register const size_t src_len){
	return stringToIPv4U8(des,src,src_len);
}
bool shinsei_stringToIPv4U16(register uint32_t*const restrict des,register const char16_t*const restrict src,register const size_t src_len){
	return stringToIPv4U16(des,src,src_len);
}
bool shinsei_stringToIPv4U32(register uint32_t*const restrict des,register const char32_t*const restrict src,register const size_t src_len){
	return stringToIPv4U32(des,src,src_len);
}

// Convert IPv4 address to string
_SHINSEI_OS_INLINE static size_t iPv4ToStringU16(register char16_t*const restrict des,register const uint32_t*const restrict src){
	register size_t res=0;
	for(register int_fast8_t i=24;i>=0;i-=8){
		register uint_fast8_t now=(*src>>i)&255;
		register uint_fast8_t cnt=0;
		do{
			des[res+cnt]=u'0'+now%10;
			++cnt;
			now/=10;
		}
		while(now);
		for(register size_t j=0;j<cnt>>1;++j){
			register const char16_t tmp=des[res+j];
			des[res+j]=des[res+cnt-j-1];
			des[res+cnt-j-1]=tmp;
		}
		res+=cnt;
		if(__builtin_expect_with_probability(i,1,0.75)) des[res++]=u'.';
	}
	des[res]=u'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t iPv4ToStringU32(register char32_t*const restrict des,register const uint32_t*const restrict src){
	register size_t res=0;
	for(register int_fast8_t i=24;i>=0;i-=8){
		register uint_fast8_t now=(*src>>i)&255;
		register uint_fast8_t cnt=0;
		do{
			des[res+cnt]=U'0'+now%10;
			++cnt;
			now/=10;
		}while(now);
		for(register size_t j=0;j<cnt>>1;++j){
			register const char32_t tmp=des[res+j];
			des[res+j]=des[res+cnt-j-1];
			des[res+cnt-j-1]=tmp;
		}
		res+=cnt;
		if(__builtin_expect_with_probability(i,1,0.75)) des[res++]=U'.';
	}
	des[res]=U'\0';
	return res;
}
size_t shinsei_iPv4ToStringCP(register const uint_fast32_t code_page,register char*const restrict des,register const uint32_t*const restrict src){
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char dot=ebcdic?0x4B:'.';
	register const char zero=(char)(ebcdic?0xF0:'0');
	register size_t res=0;
	for(register int_fast8_t i=24;i>=0;i-=8){
		register uint_fast8_t now=(*src>>i)&255;
		register uint_fast8_t cnt=0;
		do{
			des[res+cnt]=(char)(zero+now%10);
			++cnt;
			now/=10;
		}while(now);
		for(register size_t j=0;j<cnt>>1;++j){
			register const char tmp=des[res+j];
			des[res+j]=des[res+cnt-j-1];
			des[res+cnt-j-1]=tmp;
		}
		res+=cnt;
		if(__builtin_expect_with_probability(i,1,0.75)) des[res++]=dot;
	}
	des[res]='\0';
	return res;
}
size_t shinsei_iPv4ToStringW(register wchar_t*const restrict des,register const uint32_t*const restrict src){
	#ifdef _SHINSEI_WCHAR_U32
		return iPv4ToStringU32((char32_t*)des,src);
	#else
		return iPv4ToStringU16((char16_t*)des,src);
	#endif
}
size_t shinsei_iPv4ToStringU8(register char8_t*const restrict des,register const uint32_t*const restrict src){
	register size_t res=0;
	for(register int_fast8_t i=24;i>=0;i-=8){
		register uint_fast8_t now=(*src>>i)&255;
		register uint_fast8_t cnt=0;
		do{
			des[res+cnt]=u8'0'+now%10;
			++cnt;
			now/=10;
		}while(now);
		for(register size_t j=0;j<cnt>>1;++j){
			register const char8_t tmp=des[res+j];
			des[res+j]=des[res+cnt-j-1];
			des[res+cnt-j-1]=tmp;
		}
		res+=cnt;
		if(__builtin_expect_with_probability(i,1,0.75)) des[res++]=u8'.';
	}
	des[res]=u8'\0';
	return res;
}
size_t shinsei_iPv4ToStringU16(register char16_t*const restrict des,register const uint32_t*const restrict src){
	return iPv4ToStringU16(des,src);
}
size_t shinsei_iPv4ToStringU32(register char32_t*const restrict des,register const uint32_t*const restrict src){
	return iPv4ToStringU32(des,src);
}

// Convert string to IPv6 address
_SHINSEI_OS_INLINE static bool stringToIPv6U16(register uint32_t*const restrict des,register const char16_t*const restrict src,register const size_t src_len){
	uint_fast16_t parts[8]={0};
	register size_t part_idx=0;
	register size_t double_colon_idx=9;
	register uint_fast32_t val=0;
	register bool has_val=false;
	for(register size_t i=0;i<src_len;++i){
		if(isXDigitU16(src[i])){
			register const uint_fast8_t digit=(uint_fast8_t)(isDigitU16(src[i])?src[i]-u'0':(src[i]|0x20)-u'a'+10);
			val=(val<<4)|digit;
			if(val>0xFFFF) return false;
			has_val=true;
		}
		else if(src[i]==u':'){
			if(has_val){
				if(part_idx>=8) return false;
				parts[part_idx++]=(uint_fast16_t)val;
				val=0;
				has_val=false;
			}
			else{
				if(!i){
					if(i+1>=src_len||src[i+1]!=u':') return false;
				}
				else if(double_colon_idx!=9){
					return false;
				}
				else{
					double_colon_idx=part_idx;
				}
			}
		}
		else return false;
	}
	if(has_val){
		if(part_idx>=8) return false;
		parts[part_idx++]=(uint_fast16_t)(val);
	}
	else if(double_colon_idx==9&&part_idx!=8){
		return false;
	}
	if(double_colon_idx!=9){
		if(part_idx>=8) return false;
		register const size_t to_shift=part_idx-double_colon_idx;
		register const size_t zeros=8-part_idx;
		for(register size_t i=to_shift;i;--i){
			parts[double_colon_idx+zeros+i-1]=parts[double_colon_idx+i-1];
		}
		for(register size_t i=0;i<zeros;++i){
			parts[double_colon_idx+i]=0;
		}
	}
	else if(part_idx!=8){
		return false;
	}
	des[0]=((uint32_t)parts[0]<<16)|parts[1];
	des[1]=((uint32_t)parts[2]<<16)|parts[3];
	des[2]=((uint32_t)parts[4]<<16)|parts[5];
	des[3]=((uint32_t)parts[6]<<16)|parts[7];
	return true;
}
_SHINSEI_OS_INLINE static bool stringToIPv6U32(register uint32_t*const restrict des,register const char32_t*const restrict src,register const size_t src_len){
	uint_fast16_t parts[8]={0};
	register size_t part_idx=0;
	register size_t double_colon_idx=9;
	register uint_fast32_t val=0;
	register bool has_val=false;
	for(register size_t i=0;i<src_len;++i){
		if(isXDigitU32(src[i])){
			register const uint_fast8_t digit=(uint_fast8_t)(isDigitU32(src[i])?src[i]-U'0':(src[i]|0x20)-U'a'+10);
			val=(val<<4)|digit;
			if(val>0xFFFF) return false;
			has_val=true;
		}
		else if(src[i]==U':'){
			if(has_val){
				if(part_idx>=8) return false;
				parts[part_idx++]=(uint_fast16_t)val;
				val=0;
				has_val=false;
			}
			else{
				if(!i){
					if(i+1>=src_len||src[i+1]!=U':') return false;
				}
				else if(double_colon_idx!=9){
					return false;
				}
				else{
					double_colon_idx=part_idx;
				}
			}
		}
		else return false;
	}
	if(has_val){
		if(part_idx>=8) return false;
		parts[part_idx++]=(uint_fast16_t)(val);
	}
	else if(double_colon_idx==9&&part_idx!=8){
		return false;
	}
	if(double_colon_idx!=9){
		if(part_idx>=8) return false;
		register const size_t to_shift=part_idx-double_colon_idx;
		register const size_t zeros=8-part_idx;
		for(register size_t i=to_shift;i;--i){
			parts[double_colon_idx+zeros+i-1]=parts[double_colon_idx+i-1];
		}
		for(register size_t i=0;i<zeros;++i){
			parts[double_colon_idx+i]=0;
		}
	}
	else if(part_idx!=8){
		return false;
	}
	des[0]=((uint32_t)parts[0]<<16)|parts[1];
	des[1]=((uint32_t)parts[2]<<16)|parts[3];
	des[2]=((uint32_t)parts[4]<<16)|parts[5];
	des[3]=((uint32_t)parts[6]<<16)|parts[7];
	return true;
}
bool shinsei_stringToIPv6CP(register const uint_fast32_t code_page,register uint32_t*const restrict des,register const char*const restrict src,register const size_t src_len){
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char colon=(char)(ebcdic?0x7A:':');
	register const char zero=(char)(ebcdic?0xF0:'0');
	uint_fast16_t parts[8]={0};
	register size_t part_idx=0;
	register size_t double_colon_idx=9;
	register uint_fast32_t val=0;
	register bool has_val=false;
	for(register size_t i=0;i<src_len;++i){
		if(isXDigitCP(code_page,src[i])){
			register const uint_fast8_t digit=(uint_fast8_t)(isDigitCP(code_page,src[i])?src[i]-zero:ebcdic?(src[i]&0xBF)-0x81+10:(src[i]|0x20)-'a'+10);
			val=(val<<4)|digit;
			if(val>0xFFFF) return false;
			has_val=true;
		}
		else if(src[i]==colon){
			if(has_val){
				if(part_idx>=8) return false;
				parts[part_idx++]=(uint_fast16_t)val;
				val=0;
				has_val=false;
			}
			else{
				if(!i){
					if(i+1>=src_len||src[i+1]!=colon) return false;
				}
				else if(double_colon_idx!=9){
					return false;
				}
				else{
					double_colon_idx=part_idx;
				}
			}
		}
		else return false;
	}
	if(has_val){
		if(part_idx>=8) return false;
		parts[part_idx++]=(uint_fast16_t)(val);
	}
	else if(double_colon_idx==9&&part_idx!=8){
		return false;
	}
	if(double_colon_idx!=9){
		if(part_idx>=8) return false;
		register const size_t to_shift=part_idx-double_colon_idx;
		register const size_t zeros=8-part_idx;
		for(register size_t i=to_shift;i;--i){
			parts[double_colon_idx+zeros+i-1]=parts[double_colon_idx+i-1];
		}
		for(register size_t i=0;i<zeros;++i){
			parts[double_colon_idx+i]=0;
		}
	}
	else if(part_idx!=8){
		return false;
	}
	des[0]=((uint32_t)parts[0]<<16)|parts[1];
	des[1]=((uint32_t)parts[2]<<16)|parts[3];
	des[2]=((uint32_t)parts[4]<<16)|parts[5];
	des[3]=((uint32_t)parts[6]<<16)|parts[7];
	return true;
}
bool shinsei_stringToIPv6W(register uint32_t*const restrict des,register const wchar_t*const restrict src,register const size_t src_len){
	#ifdef _SHINSEI_WCHAR_U32
		return stringToIPv6U32(des,(const char32_t*)src,src_len);
	#else
		return stringToIPv6U16(des,(const char16_t*)src,src_len);
	#endif
}
bool shinsei_stringToIPv6U8(register uint32_t*const restrict des,register const char8_t*const restrict src,register const size_t src_len){
	uint_fast16_t parts[8]={0};
	register size_t part_idx=0;
	register size_t double_colon_idx=9;
	register uint_fast32_t val=0;
	register bool has_val=false;
	for(register size_t i=0;i<src_len;++i){
		if(isXDigitU8(src[i])){
			register const uint_fast8_t digit=(uint_fast8_t)(isDigitU8(src[i])?src[i]-u8'0':(src[i]|0x20)-u8'a'+10);
			val=(val<<4)|digit;
			if(val>0xFFFF) return false;
			has_val=true;
		}
		else if(src[i]==u8':'){
			if(has_val){
				if(part_idx>=8) return false;
				parts[part_idx++]=(uint_fast16_t)val;
				val=0;
				has_val=false;
			}
			else{
				if(!i){
					if(i+1>=src_len||src[i+1]!=u8':') return false;
				}
				else if(double_colon_idx!=9){
					return false;
				}
				else{
					double_colon_idx=part_idx;
				}
			}
		}
		else return false;
	}
	if(has_val){
		if(part_idx>=8) return false;
		parts[part_idx++]=(uint_fast16_t)(val);
	}
	else if(double_colon_idx==9&&part_idx!=8){
		return false;
	}
	if(double_colon_idx!=9){
		if(part_idx>=8) return false;
		register const size_t to_shift=part_idx-double_colon_idx;
		register const size_t zeros=8-part_idx;
		for(register size_t i=to_shift;i;--i){
			parts[double_colon_idx+zeros+i-1]=parts[double_colon_idx+i-1];
		}
		for(register size_t i=0;i<zeros;++i){
			parts[double_colon_idx+i]=0;
		}
	}
	else if(part_idx!=8){
		return false;
	}
	des[0]=((uint32_t)parts[0]<<16)|parts[1];
	des[1]=((uint32_t)parts[2]<<16)|parts[3];
	des[2]=((uint32_t)parts[4]<<16)|parts[5];
	des[3]=((uint32_t)parts[6]<<16)|parts[7];
	return true;
}
bool shinsei_stringToIPv6U16(register uint32_t*const restrict des,register const char16_t*const restrict src,register const size_t src_len){
	return stringToIPv6U16(des,src,src_len);
}
bool shinsei_stringToIPv6U32(register uint32_t*const restrict des,register const char32_t*const restrict src,register const size_t src_len){
	return stringToIPv6U32(des,src,src_len);
}

// Convert IPv6 address to string
_SHINSEI_OS_INLINE static size_t iPv6ToStringU16(register char16_t*const restrict des,register const uint32_t*const restrict src){
	uint_fast16_t parts[8];
	parts[0]=(uint_fast16_t)(src[0]>>16);
	parts[1]=(uint_fast16_t)(src[0]&0xFFFF);
	parts[2]=(uint_fast16_t)(src[1]>>16);
	parts[3]=(uint_fast16_t)(src[1]&0xFFFF);
	parts[4]=(uint_fast16_t)(src[2]>>16);
	parts[5]=(uint_fast16_t)(src[2]&0xFFFF);
	parts[6]=(uint_fast16_t)(src[3]>>16);
	parts[7]=(uint_fast16_t)(src[3]&0xFFFF);
	register size_t max_zero_start=8;
	register size_t max_zero_len=0;
	register size_t current_zero_start=8;
	register size_t current_zero_len=0;
	for(register size_t i=0;i<8;++i){
		if(!parts[i]){
			if(!current_zero_len) current_zero_start=i;
			++current_zero_len;
		}
		else{
			if(current_zero_len>max_zero_len){
				max_zero_len=current_zero_len;
				max_zero_start=current_zero_start;
			}
			current_zero_len=0;
		}
	}
	if(current_zero_len>max_zero_len){
		max_zero_len=current_zero_len;
		max_zero_start=current_zero_start;
	}
	if(max_zero_len<2) max_zero_len=0;
	register size_t res=0;
	for(register size_t i=0;i<8;++i){
		if(max_zero_len&&i>=max_zero_start&&i<max_zero_start+max_zero_len){
			if(i==max_zero_start){
				des[res++]=u':';
				if(!i) des[res++]=u':';
			}
			continue;
		}
		if(i&&!(max_zero_len&&i==max_zero_start+max_zero_len)) des[res++]=u':';
		register uint_fast16_t val=parts[i];
		register bool print=false;
		for(register int_fast8_t shift=12;shift>=0;shift-=4){
			register uint_fast8_t digit=(val>>shift)&0xF;
			if(digit||print||!shift){
				des[res++]=digit<10?u'0'+digit:u'a'+digit-10;
				print=true;
			}
		}
	}
	if(max_zero_len&&max_zero_start+max_zero_len==8) des[res++]=u':';
	des[res]=u'\0';
	return res;
}
_SHINSEI_OS_INLINE static size_t iPv6ToStringU32(register char32_t*const restrict des,register const uint32_t*const restrict src){
	uint_fast16_t parts[8];
	parts[0]=(uint_fast16_t)(src[0]>>16);
	parts[1]=(uint_fast16_t)(src[0]&0xFFFF);
	parts[2]=(uint_fast16_t)(src[1]>>16);
	parts[3]=(uint_fast16_t)(src[1]&0xFFFF);
	parts[4]=(uint_fast16_t)(src[2]>>16);
	parts[5]=(uint_fast16_t)(src[2]&0xFFFF);
	parts[6]=(uint_fast16_t)(src[3]>>16);
	parts[7]=(uint_fast16_t)(src[3]&0xFFFF);
	register size_t max_zero_start=8;
	register size_t max_zero_len=0;
	register size_t current_zero_start=8;
	register size_t current_zero_len=0;
	for(register size_t i=0;i<8;++i){
		if(!parts[i]){
			if(!current_zero_len) current_zero_start=i;
			++current_zero_len;
		}
		else{
			if(current_zero_len>max_zero_len){
				max_zero_len=current_zero_len;
				max_zero_start=current_zero_start;
			}
			current_zero_len=0;
		}
	}
	if(current_zero_len>max_zero_len){
		max_zero_len=current_zero_len;
		max_zero_start=current_zero_start;
	}
	if(max_zero_len<2) max_zero_len=0;
	register size_t res=0;
	for(register size_t i=0;i<8;++i){
		if(max_zero_len&&i>=max_zero_start&&i<max_zero_start+max_zero_len){
			if(i==max_zero_start){
				des[res++]=U':';
				if(!i) des[res++]=U':';
			}
			continue;
		}
		if(i&&!(max_zero_len&&i==max_zero_start+max_zero_len)) des[res++]=U':';
		register uint_fast16_t val=parts[i];
		register bool print=false;
		for(register int_fast8_t shift=12;shift>=0;shift-=4){
			register uint_fast8_t digit=(val>>shift)&0xF;
			if(digit||print||!shift){
				des[res++]=digit<10?U'0'+digit:U'a'+digit-10;
				print=true;
			}
		}
	}
	if(max_zero_len&&max_zero_start+max_zero_len==8) des[res++]=U':';
	des[res]=U'\0';
	return res;
}
size_t shinsei_iPv6ToStringCP(register const uint_fast32_t code_page,register char*const restrict des,register const uint32_t*const restrict src){
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char colon=(char)(ebcdic?0x7A:':');
	register const char zero=(char)(ebcdic?0xF0:'0');
	register const char a_lower=(char)(ebcdic?0x81:'a');
	uint_fast16_t parts[8];
	parts[0]=(uint_fast16_t)(src[0]>>16);
	parts[1]=(uint_fast16_t)(src[0]&0xFFFF);
	parts[2]=(uint_fast16_t)(src[1]>>16);
	parts[3]=(uint_fast16_t)(src[1]&0xFFFF);
	parts[4]=(uint_fast16_t)(src[2]>>16);
	parts[5]=(uint_fast16_t)(src[2]&0xFFFF);
	parts[6]=(uint_fast16_t)(src[3]>>16);
	parts[7]=(uint_fast16_t)(src[3]&0xFFFF);
	register size_t max_zero_start=8;
	register size_t max_zero_len=0;
	register size_t current_zero_start=8;
	register size_t current_zero_len=0;
	for(register size_t i=0;i<8;++i){
		if(!parts[i]){
			if(!current_zero_len) current_zero_start=i;
			++current_zero_len;
		}
		else{
			if(current_zero_len>max_zero_len){
				max_zero_len=current_zero_len;
				max_zero_start=current_zero_start;
			}
			current_zero_len=0;
		}
	}
	if(current_zero_len>max_zero_len){
		max_zero_len=current_zero_len;
		max_zero_start=current_zero_start;
	}
	if(max_zero_len<2) max_zero_len=0;
	register size_t res=0;
	for(register size_t i=0;i<8;++i){
		if(max_zero_len&&i>=max_zero_start&&i<max_zero_start+max_zero_len){
			if(i==max_zero_start){
				des[res++]=colon;
				if(!i) des[res++]=colon;
			}
			continue;
		}
		if(i&&!(max_zero_len&&i==max_zero_start+max_zero_len)) des[res++]=colon;
		register uint_fast16_t val=parts[i];
		register bool print=false;
		for(register int_fast8_t shift=12;shift>=0;shift-=4){
			register uint_fast8_t digit=(val>>shift)&0xF;
			if(digit||print||!shift){
				des[res++]=(char)(digit<10?zero+digit:a_lower+digit-10);
				print=true;
			}
		}
	}
	if(max_zero_len&&max_zero_start+max_zero_len==8) des[res++]=colon;
	des[res]='\0';
	return res;
}
size_t shinsei_iPv6ToStringW(register wchar_t*const restrict des,register const uint32_t*const restrict src){
	#ifdef _SHINSEI_WCHAR_U32
		return iPv6ToStringU32((char32_t*)des,src);
	#else
		return iPv6ToStringU16((char16_t*)des,src);
	#endif
}
size_t shinsei_iPv6ToStringU8(register char8_t*const restrict des,register const uint32_t*const restrict src){
	uint_fast16_t parts[8];
	parts[0]=(uint_fast16_t)(src[0]>>16);
	parts[1]=(uint_fast16_t)(src[0]&0xFFFF);
	parts[2]=(uint_fast16_t)(src[1]>>16);
	parts[3]=(uint_fast16_t)(src[1]&0xFFFF);
	parts[4]=(uint_fast16_t)(src[2]>>16);
	parts[5]=(uint_fast16_t)(src[2]&0xFFFF);
	parts[6]=(uint_fast16_t)(src[3]>>16);
	parts[7]=(uint_fast16_t)(src[3]&0xFFFF);
	register size_t max_zero_start=8;
	register size_t max_zero_len=0;
	register size_t current_zero_start=8;
	register size_t current_zero_len=0;
	for(register size_t i=0;i<8;++i){
		if(!parts[i]){
			if(!current_zero_len) current_zero_start=i;
			++current_zero_len;
		}
		else{
			if(current_zero_len>max_zero_len){
				max_zero_len=current_zero_len;
				max_zero_start=current_zero_start;
			}
			current_zero_len=0;
		}
	}
	if(current_zero_len>max_zero_len){
		max_zero_len=current_zero_len;
		max_zero_start=current_zero_start;
	}
	if(max_zero_len<2) max_zero_len=0;
	register size_t res=0;
	for(register size_t i=0;i<8;++i){
		if(max_zero_len&&i>=max_zero_start&&i<max_zero_start+max_zero_len){
			if(i==max_zero_start){
				des[res++]=u8':';
				if(!i) des[res++]=u8':';
			}
			continue;
		}
		if(i&&!(max_zero_len&&i==max_zero_start+max_zero_len)) des[res++]=u8':';
		register uint_fast16_t val=parts[i];
		register bool print=false;
		for(register int_fast8_t shift=12;shift>=0;shift-=4){
			register uint_fast8_t digit=(val>>shift)&0xF;
			if(digit||print||!shift){
				des[res++]=digit<10?u8'0'+digit:u8'a'+digit-10;
				print=true;
			}
		}
	}
	if(max_zero_len&&max_zero_start+max_zero_len==8) des[res++]=u8':';
	des[res]=u8'\0';
	return res;
}
size_t shinsei_iPv6ToStringU16(register char16_t*const restrict des,register const uint32_t*const restrict src){
	return iPv6ToStringU16(des,src);
}
size_t shinsei_iPv6ToStringU32(register char32_t*const restrict des,register const uint32_t*const restrict src){
	return iPv6ToStringU32(des,src);
}

// Convert mapped IPv6 address to string
_SHINSEI_OS_INLINE static size_t mappedIPv6ToStringU16(register char16_t*const restrict des,register const uint32_t*const restrict src){
	uint_fast16_t parts[8];
	parts[0]=(uint_fast16_t)(src[0]>>16);
	parts[1]=(uint_fast16_t)(src[0]&0xFFFF);
	parts[2]=(uint_fast16_t)(src[1]>>16);
	parts[3]=(uint_fast16_t)(src[1]&0xFFFF);
	parts[4]=(uint_fast16_t)(src[2]>>16);
	parts[5]=(uint_fast16_t)(src[2]&0xFFFF);
	parts[6]=(uint_fast16_t)(src[3]>>16);
	parts[7]=(uint_fast16_t)(src[3]&0xFFFF);
	register const bool is_mapped=(!parts[0]&&!parts[1]&&!parts[2]&&!parts[3]&&!parts[4]&&parts[5]==0xFFFF);
	register const size_t loop_end=is_mapped?6:8;
	register size_t max_zero_start=8;
	register size_t max_zero_len=0;
	register size_t current_zero_start=8;
	register size_t current_zero_len=0;
	for(register size_t i=0;i<8;++i){
		if(!parts[i]){
			if(!current_zero_len) current_zero_start=i;
			++current_zero_len;
		}
		else{
			if(current_zero_len>max_zero_len){
				max_zero_len=current_zero_len;
				max_zero_start=current_zero_start;
			}
			current_zero_len=0;
		}
	}
	if(current_zero_len>max_zero_len){
		max_zero_len=current_zero_len;
		max_zero_start=current_zero_start;
	}
	if(max_zero_len<2) max_zero_len=0;
	register size_t res=0;
	for(register size_t i=0;i<loop_end;++i){
		if(max_zero_len&&i>=max_zero_start&&i<max_zero_start+max_zero_len){
			if(i==max_zero_start){
				des[res++]=u':';
				if(!i) des[res++]=u':';
			}
			continue;
		}
		if(i&&!(max_zero_len&&i==max_zero_start+max_zero_len)) des[res++]=u':';
		register uint_fast16_t val=parts[i];
		register bool print=false;
		for(register int_fast8_t shift=12;shift>=0;shift-=4){
			register uint_fast8_t digit=(val>>shift)&0xF;
			if(digit||print||!shift){
				des[res++]=digit<10?u'0'+digit:u'a'+digit-10;
				print=true;
			}
		}
	}
	if(is_mapped){
		des[res++]=u':';
		res+=iPv4ToStringU16(des+res,&src[3]);
	}
	else{
		if(max_zero_len&&max_zero_start+max_zero_len==8) des[res++]=u':';
		des[res]=u'\0';
	}
	return res;
}
_SHINSEI_OS_INLINE static size_t mappedIPv6ToStringU32(register char32_t*const restrict des,register const uint32_t*const restrict src){
	uint_fast16_t parts[8];
	parts[0]=(uint_fast16_t)(src[0]>>16);
	parts[1]=(uint_fast16_t)(src[0]&0xFFFF);
	parts[2]=(uint_fast16_t)(src[1]>>16);
	parts[3]=(uint_fast16_t)(src[1]&0xFFFF);
	parts[4]=(uint_fast16_t)(src[2]>>16);
	parts[5]=(uint_fast16_t)(src[2]&0xFFFF);
	parts[6]=(uint_fast16_t)(src[3]>>16);
	parts[7]=(uint_fast16_t)(src[3]&0xFFFF);
	register const bool is_mapped=(!parts[0]&&!parts[1]&&!parts[2]&&!parts[3]&&!parts[4]&&parts[5]==0xFFFF);
	register const size_t loop_end=is_mapped?6:8;
	register size_t max_zero_start=8;
	register size_t max_zero_len=0;
	register size_t current_zero_start=8;
	register size_t current_zero_len=0;
	for(register size_t i=0;i<8;++i){
		if(!parts[i]){
			if(!current_zero_len) current_zero_start=i;
			++current_zero_len;
		}
		else{
			if(current_zero_len>max_zero_len){
				max_zero_len=current_zero_len;
				max_zero_start=current_zero_start;
			}
			current_zero_len=0;
		}
	}
	if(current_zero_len>max_zero_len){
		max_zero_len=current_zero_len;
		max_zero_start=current_zero_start;
	}
	if(max_zero_len<2) max_zero_len=0;
	register size_t res=0;
	for(register size_t i=0;i<loop_end;++i){
		if(max_zero_len&&i>=max_zero_start&&i<max_zero_start+max_zero_len){
			if(i==max_zero_start){
				des[res++]=U':';
				if(!i) des[res++]=U':';
			}
			continue;
		}
		if(i&&!(max_zero_len&&i==max_zero_start+max_zero_len)) des[res++]=U':';
		register uint_fast16_t val=parts[i];
		register bool print=false;
		for(register int_fast8_t shift=12;shift>=0;shift-=4){
			register uint_fast8_t digit=(val>>shift)&0xF;
			if(digit||print||!shift){
				des[res++]=digit<10?U'0'+digit:U'a'+digit-10;
				print=true;
			}
		}
	}
	if(is_mapped){
		des[res++]=U':';
		res+=iPv4ToStringU32(des+res,&src[3]);
	}
	else{
		if(max_zero_len&&max_zero_start+max_zero_len==8) des[res++]=U':';
		des[res]=U'\0';
	}
	return res;
}
size_t shinsei_mappedIPv6ToStringCP(register const uint_fast32_t code_page,register char*const restrict des,register const uint32_t*const restrict src){
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char colon=(char)(ebcdic?0x7A:':');
	register const char zero=(char)(ebcdic?0xF0:'0');
	register const char a_lower=(char)(ebcdic?0x81:'a');
	uint_fast16_t parts[8];
	parts[0]=(uint_fast16_t)(src[0]>>16);
	parts[1]=(uint_fast16_t)(src[0]&0xFFFF);
	parts[2]=(uint_fast16_t)(src[1]>>16);
	parts[3]=(uint_fast16_t)(src[1]&0xFFFF);
	parts[4]=(uint_fast16_t)(src[2]>>16);
	parts[5]=(uint_fast16_t)(src[2]&0xFFFF);
	parts[6]=(uint_fast16_t)(src[3]>>16);
	parts[7]=(uint_fast16_t)(src[3]&0xFFFF);
	register const bool is_mapped=(!parts[0]&&!parts[1]&&!parts[2]&&!parts[3]&&!parts[4]&&parts[5]==0xFFFF);
	register const size_t loop_end=is_mapped?6:8;
	register size_t max_zero_start=8;
	register size_t max_zero_len=0;
	register size_t current_zero_start=8;
	register size_t current_zero_len=0;
	for(register size_t i=0;i<8;++i){
		if(!parts[i]){
			if(!current_zero_len) current_zero_start=i;
			++current_zero_len;
		}
		else{
			if(current_zero_len>max_zero_len){
				max_zero_len=current_zero_len;
				max_zero_start=current_zero_start;
			}
			current_zero_len=0;
		}
	}
	if(current_zero_len>max_zero_len){
		max_zero_len=current_zero_len;
		max_zero_start=current_zero_start;
	}
	if(max_zero_len<2) max_zero_len=0;
	register size_t res=0;
	for(register size_t i=0;i<loop_end;++i){
		if(max_zero_len&&i>=max_zero_start&&i<max_zero_start+max_zero_len){
			if(i==max_zero_start){
				des[res++]=colon;
				if(!i) des[res++]=colon;
			}
			continue;
		}
		if(i&&!(max_zero_len&&i==max_zero_start+max_zero_len)) des[res++]=colon;
		register uint_fast16_t val=parts[i];
		register bool print=false;
		for(register int_fast8_t shift=12;shift>=0;shift-=4){
			register uint_fast8_t digit=(val>>shift)&0xF;
			if(digit||print||!shift){
				des[res++]=(char)(digit<10?zero+digit:a_lower+digit-10);
				print=true;
			}
		}
	}
	if(is_mapped){
		des[res++]=colon;
		res+=shinsei_iPv4ToStringCP(code_page,des+res,&src[3]);
	}
	else{
		if(max_zero_len&&max_zero_start+max_zero_len==8) des[res++]=colon;
		des[res]='\0';
	}
	return res;
}
size_t shinsei_mappedIPv6ToStringW(register wchar_t*const restrict des,register const uint32_t*const restrict src){
	#ifdef _SHINSEI_WCHAR_U32
		return mappedIPv6ToStringU32((char32_t*)des,src);
	#else
		return mappedIPv6ToStringU16((char16_t*)des,src);
	#endif
}
size_t shinsei_mappedIPv6ToStringU8(register char8_t*const restrict des,register const uint32_t*const restrict src){
	uint_fast16_t parts[8];
	parts[0]=(uint_fast16_t)(src[0]>>16);
	parts[1]=(uint_fast16_t)(src[0]&0xFFFF);
	parts[2]=(uint_fast16_t)(src[1]>>16);
	parts[3]=(uint_fast16_t)(src[1]&0xFFFF);
	parts[4]=(uint_fast16_t)(src[2]>>16);
	parts[5]=(uint_fast16_t)(src[2]&0xFFFF);
	parts[6]=(uint_fast16_t)(src[3]>>16);
	parts[7]=(uint_fast16_t)(src[3]&0xFFFF);
	register const bool is_mapped=(!parts[0]&&!parts[1]&&!parts[2]&&!parts[3]&&!parts[4]&&parts[5]==0xFFFF);
	register const size_t loop_end=is_mapped?6:8;
	register size_t max_zero_start=8;
	register size_t max_zero_len=0;
	register size_t current_zero_start=8;
	register size_t current_zero_len=0;
	for(register size_t i=0;i<8;++i){
		if(!parts[i]){
			if(!current_zero_len) current_zero_start=i;
			++current_zero_len;
		}
		else{
			if(current_zero_len>max_zero_len){
				max_zero_len=current_zero_len;
				max_zero_start=current_zero_start;
			}
			current_zero_len=0;
		}
	}
	if(current_zero_len>max_zero_len){
		max_zero_len=current_zero_len;
		max_zero_start=current_zero_start;
	}
	if(max_zero_len<2) max_zero_len=0;
	register size_t res=0;
	for(register size_t i=0;i<loop_end;++i){
		if(max_zero_len&&i>=max_zero_start&&i<max_zero_start+max_zero_len){
			if(i==max_zero_start){
				des[res++]=u8':';
				if(!i) des[res++]=u8':';
			}
			continue;
		}
		if(i&&!(max_zero_len&&i==max_zero_start+max_zero_len)) des[res++]=u8':';
		register uint_fast16_t val=parts[i];
		register bool print=false;
		for(register int_fast8_t shift=12;shift>=0;shift-=4){
			register uint_fast8_t digit=(val>>shift)&0xF;
			if(digit||print||!shift){
				des[res++]=digit<10?u8'0'+digit:u8'a'+digit-10;
				print=true;
			}
		}
	}
	if(is_mapped){
		des[res++]=u8':';
		res+=shinsei_iPv4ToStringU8(des+res,&src[3]);
	}
	else{
		if(max_zero_len&&max_zero_start+max_zero_len==8) des[res++]=u8':';
		des[res]=u8'\0';
	}
	return res;
}
size_t shinsei_mappedIPv6ToStringU16(register char16_t*const restrict des,register const uint32_t*const restrict src){
	return mappedIPv6ToStringU16(des,src);
}
size_t shinsei_mappedIPv6ToStringU32(register char32_t*const restrict des,register const uint32_t*const restrict src){
	return mappedIPv6ToStringU32(des,src);
}

// Convert string to mapped IPv6 address
_SHINSEI_OS_INLINE static bool stringToMappedIPv6U16(register uint32_t*const restrict des,register const char16_t*const restrict src,register const size_t src_len){
	uint_fast16_t parts[8]={0};
	register size_t part_idx=0;
	register size_t double_colon_idx=9;
	register uint_fast32_t val=0;
	register bool has_val=false;
	for(register size_t i=0;i<src_len;++i){
		if(isXDigitU16(src[i])){
			register const uint_fast8_t digit=(uint_fast8_t)(isDigitU16(src[i])?src[i]-u'0':(src[i]|0x20)-u'a'+10);
			val=(val<<4)|digit;
			if(val>0xFFFF) return false;
			has_val=true;
		}
		else if(src[i]==u':'){
			if(has_val){
				if(part_idx>=8) return false;
				parts[part_idx++]=(uint_fast16_t)val;
				val=0;
				has_val=false;
			}
			else{
				if(!i){
					if(i+1>=src_len||src[i+1]!=u':') return false;
				}
				else if(double_colon_idx!=9){
					return false;
				}
				else{
					double_colon_idx=part_idx;
				}
			}
		}
		else if(src[i]==u'.'){
			if(!has_val||part_idx>6) return false;
			register size_t ipv4_start=i;
			while(ipv4_start&&src[ipv4_start-1]!=u':') --ipv4_start;
			uint32_t ipv4;
			if(!stringToIPv4U16(&ipv4,src+ipv4_start,src_len-ipv4_start)) return false;
			parts[part_idx++]=(uint_fast16_t)(ipv4>>16);
			parts[part_idx++]=(uint_fast16_t)(ipv4&0xFFFF);
			has_val=false;
			break;
		}
		else return false;
	}
	if(has_val){
		if(part_idx>=8) return false;
		parts[part_idx++]=(uint_fast16_t)(val);
	}
	else if(double_colon_idx==9&&part_idx!=8){
		return false;
	}
	if(double_colon_idx!=9){
		if(part_idx>=8) return false;
		register const size_t to_shift=part_idx-double_colon_idx;
		register const size_t zeros=8-part_idx;
		for(register size_t i=to_shift;i;--i){
			parts[double_colon_idx+zeros+i-1]=parts[double_colon_idx+i-1];
		}
		for(register size_t i=0;i<zeros;++i){
			parts[double_colon_idx+i]=0;
		}
	}
	else if(part_idx!=8){
		return false;
	}
	des[0]=((uint32_t)parts[0]<<16)|parts[1];
	des[1]=((uint32_t)parts[2]<<16)|parts[3];
	des[2]=((uint32_t)parts[4]<<16)|parts[5];
	des[3]=((uint32_t)parts[6]<<16)|parts[7];
	return true;
}
_SHINSEI_OS_INLINE static bool stringToMappedIPv6U32(register uint32_t*const restrict des,register const char32_t*const restrict src,register const size_t src_len){
	uint_fast16_t parts[8]={0};
	register size_t part_idx=0;
	register size_t double_colon_idx=9;
	register uint_fast32_t val=0;
	register bool has_val=false;
	for(register size_t i=0;i<src_len;++i){
		if(isXDigitU32(src[i])){
			register const uint_fast8_t digit=(uint_fast8_t)(isDigitU32(src[i])?src[i]-U'0':(src[i]|0x20)-U'a'+10);
			val=(val<<4)|digit;
			if(val>0xFFFF) return false;
			has_val=true;
		}
		else if(src[i]==U':'){
			if(has_val){
				if(part_idx>=8) return false;
				parts[part_idx++]=(uint_fast16_t)val;
				val=0;
				has_val=false;
			}
			else{
				if(!i){
					if(i+1>=src_len||src[i+1]!=U':') return false;
				}
				else if(double_colon_idx!=9){
					return false;
				}
				else{
					double_colon_idx=part_idx;
				}
			}
		}
		else if(src[i]==U'.'){
			if(!has_val||part_idx>6) return false;
			register size_t ipv4_start=i;
			while(ipv4_start&&src[ipv4_start-1]!=U':') --ipv4_start;
			uint32_t ipv4;
			if(!stringToIPv4U32(&ipv4,src+ipv4_start,src_len-ipv4_start)) return false;
			parts[part_idx++]=(uint_fast16_t)(ipv4>>16);
			parts[part_idx++]=(uint_fast16_t)(ipv4&0xFFFF);
			has_val=false;
			break;
		}
		else return false;
	}
	if(has_val){
		if(part_idx>=8) return false;
		parts[part_idx++]=(uint_fast16_t)(val);
	}
	else if(double_colon_idx==9&&part_idx!=8){
		return false;
	}
	if(double_colon_idx!=9){
		if(part_idx>=8) return false;
		register const size_t to_shift=part_idx-double_colon_idx;
		register const size_t zeros=8-part_idx;
		for(register size_t i=to_shift;i;--i){
			parts[double_colon_idx+zeros+i-1]=parts[double_colon_idx+i-1];
		}
		for(register size_t i=0;i<zeros;++i){
			parts[double_colon_idx+i]=0;
		}
	}
	else if(part_idx!=8){
		return false;
	}
	des[0]=((uint32_t)parts[0]<<16)|parts[1];
	des[1]=((uint32_t)parts[2]<<16)|parts[3];
	des[2]=((uint32_t)parts[4]<<16)|parts[5];
	des[3]=((uint32_t)parts[6]<<16)|parts[7];
	return true;
}
bool shinsei_stringToMappedIPv6CP(register const uint_fast32_t code_page,register uint32_t*const restrict des,register const char*const restrict src,register const size_t src_len){
	register const bool ebcdic=isEBCDICCodePage(code_page);
	register const char colon=(char)(ebcdic?0x7A:':');
	register const char dot=(char)(ebcdic?0x4B:'.');
	register const char zero=(char)(ebcdic?0xF0:'0');
	uint_fast16_t parts[8]={0};
	register size_t part_idx=0;
	register size_t double_colon_idx=9;
	register uint_fast32_t val=0;
	register bool has_val=false;
	for(register size_t i=0;i<src_len;++i){
		if(isXDigitCP(code_page,src[i])){
			register const uint_fast8_t digit=(uint_fast8_t)(isDigitCP(code_page,src[i])?src[i]-zero:ebcdic?(src[i]&0xBF)-0x81+10:(src[i]|0x20)-'a'+10);
			val=(val<<4)|digit;
			if(val>0xFFFF) return false;
			has_val=true;
		}
		else if(src[i]==colon){
			if(has_val){
				if(part_idx>=8) return false;
				parts[part_idx++]=(uint_fast16_t)val;
				val=0;
				has_val=false;
			}
			else{
				if(!i){
					if(i+1>=src_len||src[i+1]!=colon) return false;
				}
				else if(double_colon_idx!=9){
					return false;
				}
				else{
					double_colon_idx=part_idx;
				}
			}
		}
		else if(src[i]==dot){
			if(!has_val||part_idx>6) return false;
			register size_t ipv4_start=i;
			while(ipv4_start&&src[ipv4_start-1]!=colon) --ipv4_start;
			uint32_t ipv4;
			if(!stringToIPv4CP(code_page,&ipv4,src+ipv4_start,src_len-ipv4_start)) return false;
			parts[part_idx++]=(uint_fast16_t)(ipv4>>16);
			parts[part_idx++]=(uint_fast16_t)(ipv4&0xFFFF);
			has_val=false;
			break;
		}
		else return false;
	}
	if(has_val){
		if(part_idx>=8) return false;
		parts[part_idx++]=(uint_fast16_t)(val);
	}
	else if(double_colon_idx==9&&part_idx!=8){
		return false;
	}
	if(double_colon_idx!=9){
		if(part_idx>=8) return false;
		register const size_t to_shift=part_idx-double_colon_idx;
		register const size_t zeros=8-part_idx;
		for(register size_t i=to_shift;i;--i){
			parts[double_colon_idx+zeros+i-1]=parts[double_colon_idx+i-1];
		}
		for(register size_t i=0;i<zeros;++i){
			parts[double_colon_idx+i]=0;
		}
	}
	else if(part_idx!=8){
		return false;
	}
	des[0]=((uint32_t)parts[0]<<16)|parts[1];
	des[1]=((uint32_t)parts[2]<<16)|parts[3];
	des[2]=((uint32_t)parts[4]<<16)|parts[5];
	des[3]=((uint32_t)parts[6]<<16)|parts[7];
	return true;
}
bool shinsei_stringToMappedIPv6W(register uint32_t*const restrict des,register const wchar_t*const restrict src,register const size_t src_len){
	#ifdef _SHINSEI_WCHAR_U32
		return stringToMappedIPv6U32(des,(const char32_t*)src,src_len);
	#else
		return stringToMappedIPv6U16(des,(const char16_t*)src,src_len);
	#endif
}
bool shinsei_stringToMappedIPv6U8(register uint32_t*const restrict des,register const char8_t*const restrict src,register const size_t src_len){
	uint_fast16_t parts[8]={0};
	register size_t part_idx=0;
	register size_t double_colon_idx=9;
	register uint_fast32_t val=0;
	register bool has_val=false;
	for(register size_t i=0;i<src_len;++i){
		if(isXDigitU8(src[i])){
			register const uint_fast8_t digit=(uint_fast8_t)(isDigitU8(src[i])?src[i]-u8'0':(src[i]|0x20)-u8'a'+10);
			val=(val<<4)|digit;
			if(val>0xFFFF) return false;
			has_val=true;
		}
		else if(src[i]==u8':'){
			if(has_val){
				if(part_idx>=8) return false;
				parts[part_idx++]=(uint_fast16_t)val;
				val=0;
				has_val=false;
			}
			else{
				if(!i){
					if(i+1>=src_len||src[i+1]!=u8':') return false;
				}
				else if(double_colon_idx!=9){
					return false;
				}
				else{
					double_colon_idx=part_idx;
				}
			}
		}
		else if(src[i]==u8'.'){
			if(!has_val||part_idx>6) return false;
			register size_t ipv4_start=i;
			while(ipv4_start&&src[ipv4_start-1]!=u8':') --ipv4_start;
			uint32_t ipv4;
			if(!stringToIPv4U8(&ipv4,src+ipv4_start,src_len-ipv4_start)) return false;
			parts[part_idx++]=(uint_fast16_t)(ipv4>>16);
			parts[part_idx++]=(uint_fast16_t)(ipv4&0xFFFF);
			has_val=false;
			break;
		}
		else return false;
	}
	if(has_val){
		if(part_idx>=8) return false;
		parts[part_idx++]=(uint_fast16_t)(val);
	}
	else if(double_colon_idx==9&&part_idx!=8){
		return false;
	}
	if(double_colon_idx!=9){
		if(part_idx>=8) return false;
		register const size_t to_shift=part_idx-double_colon_idx;
		register const size_t zeros=8-part_idx;
		for(register size_t i=to_shift;i;--i){
			parts[double_colon_idx+zeros+i-1]=parts[double_colon_idx+i-1];
		}
		for(register size_t i=0;i<zeros;++i){
			parts[double_colon_idx+i]=0;
		}
	}
	else if(part_idx!=8){
		return false;
	}
	des[0]=((uint32_t)parts[0]<<16)|parts[1];
	des[1]=((uint32_t)parts[2]<<16)|parts[3];
	des[2]=((uint32_t)parts[4]<<16)|parts[5];
	des[3]=((uint32_t)parts[6]<<16)|parts[7];
	return true;
}
bool shinsei_stringToMappedIPv6U16(register uint32_t*const restrict des,register const char16_t*const restrict src,register const size_t src_len){
	return stringToMappedIPv6U16(des,src,src_len);
}
bool shinsei_stringToMappedIPv6U32(register uint32_t*const restrict des,register const char32_t*const restrict src,register const size_t src_len){
	return stringToMappedIPv6U32(des,src,src_len);
}

#include"shinsei/.internal/cpp_term.hpp"
#include"shinsei/minimal/str.h"

int shinsei_utf8CharSize(const char8_t starter_ch){
	if(starter_ch<=0x7F) return 1;
    else if((starter_ch&0xE0)==0xC0) return 2;
    else if((starter_ch&0xF0)==0xE0) return 3;
    else if((starter_ch&0xF8)==0xF0) return 4;
    return 0;   
}
int shinsei_utf16CharSize(const char16_t starter_ch){
	if(starter_ch<0xD800||starter_ch>0xDFFF) return 1;
	if(starter_ch>=0xD800&&starter_ch<=0xDBFF) return 2;
	return 0;
}

bool shinsei_isBDigitA(const int ch){
	return (unsigned int)(ch-'0')<=1;
}
bool shinsei_isBDigitW(const wint_t ch){
	return (unsigned int)(ch-L'0')<=1;
}
bool shinsei_isBDigitU8S(const char8_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]-u8'0'<=1;
}
bool shinsei_isBDigitU16S(const char16_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]-u'0'<=1;
}
bool shinsei_isBDigitU32(const char32_t ch){
	return ch-U'0'<=1;
}

bool shinsei_isODigitA(const int ch){
	return (unsigned int)(ch-'0')<=7;
}
bool shinsei_isODigitW(const wint_t ch){
	return (unsigned int)(ch-L'0')<=7;
}
bool shinsei_isODigitU8S(const char8_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]-u8'0'<=7;
}
bool shinsei_isODigitU16S(const char16_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]-u'0'<=7;
}
bool shinsei_isODigitU32(const char32_t ch){
	return ch-U'0'<=7;
}

bool shinsei_isDigitA(const int ch){
	return (unsigned int)(ch-'0')<=9;
}
bool shinsei_isDigitW(const wint_t ch){
	return (unsigned int)(ch-L'0')<=9;
}
bool shinsei_isDigitU8S(const char8_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]-u8'0'<=9;
}
bool shinsei_isDigitU16S(const char16_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]-u'0'<=9;
}
bool shinsei_isDigitU32(const char32_t ch){
	return ch-U'0'<=9;
}

bool shinsei_isXDigitA(const int ch){
	if((unsigned int)(ch-'0')<=9) return true;
    return (unsigned int)((ch|0x20)-'a')<=5;
}
bool shinsei_isXDigitW(const wint_t ch){
	if((unsigned int)(ch-L'0')<=9) return true;
    return (unsigned int)((ch|0x20)-L'a')<=5;
}
bool shinsei_isXDigitU8S(const char8_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	if(*str_ptr[-1]-u8'0'<=9) return true;
    return (*str_ptr[-1]|0x20)-u8'a'<=5;
}
bool shinsei_isXDigitU16S(const char16_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	if(*str_ptr[-1]-u'0'<=9) return true;
    return (*str_ptr[-1]|0x20)-u'a'<=5;
}
bool shinsei_isXDigitU32(const char32_t ch){
	if(ch-U'0'<=9) return true;
    return (ch|0x20)-U'a'<=5;
}

bool shinsei_isUpperA(const int ch){
	return (unsigned int)(ch-'A')<=25;
}
bool shinsei_isUpperW(const wint_t ch){
	return (unsigned int)(ch-L'A')<=25;
}
bool shinsei_isUpperU8S(const char8_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]-u8'A'<=25;
}
bool shinsei_isUpperU16S(const char16_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]-u'A'<=25;
}
bool shinsei_isUpperU32(const char32_t ch){
	return ch-L'A'<=25;
}

bool shinsei_isLowerA(const int ch){
	return (unsigned int)(ch-'a')<=25;
}
bool shinsei_isLowerW(const wint_t ch){
	return (unsigned int)(ch-L'a')<=25;
}
bool shinsei_isLowerU8S(const char8_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]-u8'a'<=25;
}
bool shinsei_isLowerU16S(const char16_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]-u'a'<=25;
}
bool shinsei_isLowerU32(const char32_t ch){
	return ch-L'a'<=25;
}

bool shinsei_isAlphaA(const int ch){
	return (unsigned int)((ch|0x20)-'a')<=25;
}
bool shinsei_isAlphaW(const wint_t ch){
	return (unsigned int)((ch|0x20)-L'a')<=25;
}
bool shinsei_isAlphaU8S(const char8_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr[-1]|0x20)-u8'a'<=25;
}
bool shinsei_isAlphaU16S(const char16_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr[-1]|0x20)-u'a'<=25;
}
bool shinsei_isAlphaU32(const char32_t ch){
	return (ch|0x20)-L'a'<=25;
}

bool shinsei_isAlnumA(const int ch){
	if((unsigned int)(ch-'0')<=9) return true;
    return (unsigned int)((ch|0x20)-'a')<=25;
}
bool shinsei_isAlnumW(const wint_t ch){
	if((unsigned int)(ch-L'0')<=9) return true;
    return (unsigned int)((ch|0x20)-L'a')<=25;
}
bool shinsei_isAlnumU8S(const char8_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	if(*str_ptr[-1]-u8'0'<=9) return true;
	return ((*str_ptr[-1]|0x20)-u8'a')<=25;
}
bool shinsei_isAlnumU16S(const char16_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	if(*str_ptr[-1]-u'0'<=9) return true;
	return ((*str_ptr[-1]|0x20)-u'a')<=25;
}
bool shinsei_isAlnumU32(const char32_t ch){
	if(ch-U'0'<=9) return true;
	return (ch|0x20)-L'a'<=25;
}

int shinsei_toUpperA(const int ch){
	if((unsigned int)(ch-'a')<=25) return ch-32;
	return ch;
}
wint_t shinsei_toUpperW(const wint_t ch){
	if((unsigned int)(ch-L'a')<=25) return ch-32;
	return ch;
}
char8_t shinsei_toUpperU8S(const char8_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	register const char8_t ch=**str_ptr;
	*str_ptr+=size;
	if(size>1) return ch;
	if(ch-u8'a'<=25) return ch-32;
	return ch;
}
char16_t shinsei_toUpperU16S(const char16_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const size_t size=(size_t)shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	register const char16_t ch=**str_ptr;
	*str_ptr+=size;
	if(size>1) return ch;
	if(ch-u'a'<=25) return ch-32;
	return ch;
}
char32_t shinsei_toUpperU32(const char32_t ch){
	if(ch-U'a'<=25) return ch-32;
	return ch;
}

int shinsei_isHexColorA(const char*const restrict str){
	// May be legacy
	if(str==nullptr) return 0;
	register int res;
	register const char* ptr=str;
	if(str[0]=='#'){
		res=1;
		++ptr;
	}
	else res=0;
	register int r=res+3;
	while(res<r){
		if(shinsei_isXDigitA(*ptr)) ++ptr;
		else return 0;
		++res;
	}
	if(*ptr=='\0') return res;
	r+=3;
	while(res<r){
		if(shinsei_isXDigitA(*ptr)) ++ptr;
		else return 0;
		++res;
	}
	if(*ptr=='\0') return res;
	return 0;
}
int shinsei_isHexColorW(const wchar_t*const restrict str){
	if(str==nullptr) return 0;
	register int res;
	register const wchar_t* ptr=str;
	if(str[0]==L'#'){
		res=1;
		++ptr;
	}
	else res=0;
	register int r=res+3;
	while(res<r){
		if(shinsei_isXDigitW(*ptr)) ++ptr;
		else return 0;
		++res;
	}
	if(*ptr==L'\0') return res;
	r+=3;
	while(res<r){
		if(shinsei_isXDigitW(*ptr)) ++ptr;
		else return 0;
		++res;
	}
	if(*ptr==L'\0') return res;
	return 0;
}

int shinsei_utf32CharToUtf16Char(char16_t*const restrict des,const char32_t src){
	if(__builtin_expect(src<0x10000,1)){
		des[0]=(char16_t)src;
		return 1;
	}
	const char32_t res=src-0x10000;
	des[0]=(char16_t)((res>>10)+0xD800);
	des[1]=(char16_t)((res&0x3FF)+0xDC00);
	return 2;
}
int shinsei_utf32CharToUtf8Char(char8_t*const restrict des,const char32_t src){
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
int shinsei_utf16CharToUtf8Char(char8_t*const restrict des,const char16_t*const restrict src,const size_t src_len){
	if(__builtin_expect(!src_len,0)) return 0;
	register char32_t buf;
	if(src[0]>=0xD800&&src[0]<=0xDBFF){
		if(src_len>=2&&src[1]>=0xDC00&&src[1]<=0xDFFF){
			buf=(((char32_t)(src[0]&0x3FF)<<10)|(src[1]&0x3FF))+0x10000;
		}
		else return 0;
	}
	else buf=(char32_t)src[0];
	return shinsei_utf32CharToUtf8Char(des,buf);
}

int shinsei_utf16CharToUtf32Char(char32_t*const restrict des,const char16_t*const restrict src,const size_t src_len){
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
int shinsei_utf8CharToUtf32Char(char32_t*const restrict des,const char8_t*const restrict src,const size_t src_len){
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
	*des=((char32_t)(src[0]&0x0F)<<12)|((src[1]&0x3F)<<6)|(src[2]&0x3F);
		return 3;
	}
	if((src[0]&0xF8)==0xF0&&src_len>=4){
		*des=(((char32_t)src[0]&0x07)<<18)|((src[1]&0x3F)<<12)|((src[2]&0x3F)<<6)|(src[3]&0x3F);
		return 4;
	}
	return 0;
}
int shinsei_utf8CharToUtf16Char(char16_t*const restrict des,const char8_t*const restrict src,const size_t src_len){
	char32_t buf;
	register const int res=shinsei_utf8CharToUtf32Char(&buf,src,src_len);
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

size_t shinsei_utf16ToUtf8(char8_t *const restrict des,const size_t des_len,const char16_t *const restrict src,const size_t src_len){
	register size_t si=0;
	register size_t di=0;
	while(si<src_len){
		char32_t cp;
		register const size_t r=(size_t)shinsei_utf16CharToUtf32Char(&cp,src+si,src_len-si);
		if(__builtin_expect(!r,0)) return 0;
		si+=r;
		char8_t tmp[4];
		register const size_t w=(size_t)shinsei_utf32CharToUtf8Char(tmp,cp);
		if(di+w>des_len) return di+w;
		for(register size_t i=0;i<w;i++) des[di++]=tmp[i];
	}
	if(di<des_len) des[di]=0;
	return di;
}
char8_t* shinsei_utf16ToUtf8B(const char16_t*const restrict src,const size_t src_len){
	register const size_t cap=src_len*4+1;
	register char8_t*const buf=(char8_t*)malloc(cap);
	if(!buf) return nullptr;
	const size_t len=shinsei_utf16ToUtf8(buf,cap,src,src_len);
	if(!len){
		free(buf);
		return nullptr;
	}
	return buf;
}

int shinsei_parseEscapedCharA(char*const restrict des,const char*const restrict src,const size_t src_len){
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
size_t shinsei_parseEscapedCharW(wchar_t**restrict des,const wchar_t*restrict src,size_t src_len){
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
			*des+=shinsei_utf32CharToUtf16Char(*des,ch);
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
				*des+=shinsei_utf32CharToUtf16Char(*des,ch);
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
			*des+=shinsei_utf32CharToUtf16Char(*des,ch);
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
				*des+=shinsei_utf32CharToUtf16Char(*des,ch);
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
				ch=(ch<<4)+(iswdigit(*src)?*src-L'0':towupper(*src)-L'A'+10);
				++i;
			}
			if(ch>0x10FFFF||(ch>=0xD800&&ch<=0xDFFF)) return 0;
			*des+=shinsei_utf32CharToUtf16Char(*des,ch);
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

size_t shinsei_readEscapedLineA(char*const restrict str,const size_t len){
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

size_t shinsei_readEscapedLineW(wchar_t*const restrict str,const size_t len){
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

size_t shinsei_stringLinesA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len){
	// May be legacy
	if(__builtin_expect(!str_len,0)) return 0;
	register size_t i=0;
	register size_t pre=0;
	register size_t res=0;
	while(__builtin_expect(i<str_len,1)){
		if(__builtin_expect(str[i]=='\n',0)){
			str[i]='\0';
			if(i>0&&str[i-1]=='\r') str[i-1]='\0';
			if(res<idx_buf_len){
				idx_buf[res]=pre;
				pre=i+1;
			}
			++res;
		}
		++i;
	}
	if(res<idx_buf_len) idx_buf[res]=pre;
	++res;
	str[str_len+1]='\0';
	return res;
}
size_t shinsei_stringLinesW(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len){
	// May be legacy
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

size_t shinsei_findStringsA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len){
	// May be legacy
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
size_t shinsei_findStringsW(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len){
	// May be legacy
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

size_t shinsei_escapedLineToStringsA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len){
	// Unimplemented. Placeholder.
	(void)idx_buf;
	(void)idx_buf_len;
	(void)str;
	(void)str_len;
	return 0;
}
size_t shinsei_escapedLineToStringsW(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len){
	// May be legacy
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
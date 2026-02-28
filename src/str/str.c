#include"shinsei/minimal/str.h"

int shinsei_utf8CharSize(const unsigned char starter_ch){
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
	return ch=='0'||ch=='1';
}
bool shinsei_isBDigitW(const wint_t ch){
	return ch==L'0'||ch==L'1';
}
bool shinsei_isBDigitU8(const unsigned char**restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]==u8'0'||*str_ptr[-1]==u8'1';
}
bool shinsei_isBDigitU16(const char16_t**restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]==u'0'||*str_ptr[-1]==u'1';
}
bool shinsei_isBDigitU32(const char32_t ch){
	return ch==U'0'||ch==U'1';
}

bool shinsei_isODigitA(const int ch){
	return ch>='0'&&ch<='7';
}
bool shinsei_isODigitW(const wint_t ch){
	return ch>=L'0'&&ch<=L'7';
}
bool shinsei_isODigitU8(const unsigned char**restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]>=u8'0'&&*str_ptr[-1]<=u8'7';
}
bool shinsei_isODigitU16(const char16_t**restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]>=u'0'&&*str_ptr[-1]<=u'7';
}
bool shinsei_isODigitU32(const char32_t ch){
	return ch>=U'0'&&ch<=U'7';
}

bool shinsei_isDigitA(const int ch){
	return isdigit(ch);
}
bool shinsei_isDigitW(const wint_t ch){
	return iswdigit(ch);
}
bool shinsei_isDigitU8(const unsigned char**restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]>=u8'0'&&*str_ptr[-1]<=u8'9';
}
bool shinsei_isDigitU16(const char16_t**restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]>=u'0'&&*str_ptr[-1]<=u'9';
}
bool shinsei_isDigitU32(const char32_t ch){
	return ch>=U'0'&&ch<=U'9';
}

bool shinsei_isXDigitA(const int ch){
	return isxdigit(ch);
}
bool shinsei_isXDigitW(const wint_t ch){
	return iswxdigit(ch);
}
bool shinsei_isXDigitU8(const unsigned char**restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr[-1]>=u8'0'&&*str_ptr[-1]<=u8'9')||(*str_ptr[-1]>=u8'A'&&*str_ptr[-1]<=u8'F')||(*str_ptr[-1]>=u8'a'&&*str_ptr[-1]<=u8'f');
}
bool shinsei_isXDigitU16(const char16_t**restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr[-1]>=u'0'&&*str_ptr[-1]<=u'9')||(*str_ptr[-1]>=u'A'&&*str_ptr[-1]<=u'F')||(*str_ptr[-1]>=u'a'&&*str_ptr[-1]<=u'f');
}
bool shinsei_isXDigitU32(const char32_t ch){
	return (ch>=U'0'&&ch<=U'9')||(ch>=U'A'&&ch<=U'F')||(ch>=u'a'&&ch<=u'f');
}

bool shinsei_isUpperA(const int ch){
	return isupper(ch);
}
bool shinsei_isUpperW(const wint_t ch){
	return iswupper(ch);
}
bool shinsei_isUpperU8(const unsigned char**restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]>=u8'A'&&*str_ptr[-1]<=u8'Z';
}
bool shinsei_isUpperU16(const char16_t**restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]>=u'A'&&*str_ptr[-1]<=u'Z';
}
bool shinsei_isUpperU32(const char32_t ch){
	return ch>=U'A'&&ch<=U'Z';
}

bool shinsei_isLowerA(const int ch){
	return islower(ch);
}
bool shinsei_isLowerW(const wint_t ch){
	return iswlower(ch);
}
bool shinsei_isLowerU8(const unsigned char**restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]>=u8'a'&&*str_ptr[-1]<=u8'z';
}
bool shinsei_isLowerU16(const char16_t**restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]>=u'a'&&*str_ptr[-1]<=u'z';
}
bool shinsei_isLowerU32(const char32_t ch){
	return ch>=U'a'&&ch<=U'z';
}

bool shinsei_isAlphaA(const int ch){
	return isalpha(ch);
}
bool shinsei_isAlphaW(const wint_t ch){
	return iswalpha(ch);
}
bool shinsei_isAlphaU8(const unsigned char**restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr[-1]>=u8'A'&&*str_ptr[-1]<=u8'Z')||(*str_ptr[-1]>=u8'a'&&*str_ptr[-1]<=u8'z');
}
bool shinsei_isAlphaU16(const char16_t**restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr[-1]>=u'A'&&*str_ptr[-1]<=u'Z')||(*str_ptr[-1]>=u'a'&&*str_ptr[-1]<=u'z');
}
bool shinsei_isAlphaU32(const char32_t ch){
	return (ch>=U'A'&&ch<=U'Z')||(ch>=U'a'&&ch<=U'z');
}

bool shinsei_isAlnumA(const int ch){
	return isalnum(ch);
}
bool shinsei_isAlnumW(const wint_t ch){
	return iswalnum(ch);
}
bool shinsei_isAlnumU8(const unsigned char**restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr[-1]>=u8'A'&&*str_ptr[-1]<=u8'Z')||(*str_ptr[-1]>=u8'a'&&*str_ptr[-1]<=u8'z')||(*str_ptr[-1]>=u8'0'&&*str_ptr[-1]<=u8'9');
}
bool shinsei_isAlnumU16(const char16_t**restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr[-1]>=u'A'&&*str_ptr[-1]<=u'Z')||(*str_ptr[-1]>=u'a'&&*str_ptr[-1]<=u'z')||(*str_ptr[-1]>=u'0'&&*str_ptr[-1]<=u'9');
}
bool shinsei_isAlnumU32(const char32_t ch){
	return (ch>=U'A'&&ch<=U'Z')||(ch>=U'a'&&ch<=U'z')||(ch>=U'0'&&ch<=U'9');
}

int shinsei_isHexColorA(const char*restrict str){
	if(str==nullptr) return 0;
	register int res;
	if(str[0]=='#'){
		res=1;
		++str;
	}
	else res=0;
	register int r=res+3;
	while(res<r){
		if(isxdigit(*str)) ++str;
		else return 0;
		++res;
	}
	if(*str=='\0') return res;
	r+=3;
	while(res<r){
		if(isxdigit(*str)) ++str;
		else return 0;
		++res;
	}
	if(*str=='\0') return res;
	return 0;
}
int shinsei_isHexColorW(const wchar_t*restrict str){
	if(str==nullptr) return 0;
	register int res;
	if(str[0]==L'#'){
		res=1;
		++str;
	}
	else res=0;
	register int r=res+3;
	while(res<r){
		if(iswxdigit(*str)) ++str;
		else return 0;
		++res;
	}
	if(*str==L'\0') return res;
	r+=3;
	while(res<r){
		if(iswxdigit(*str)) ++str;
		else return 0;
		++res;
	}
	if(*str==L'\0') return res;
	return 0;
}

int shinsei_utf32CharToUtf16Char(char16_t*restrict des,char32_t src){
	if(__builtin_expect(src<0x10000,1)){
		des[0]=(char16_t)src;
		return 1;
	}
	src-=0x10000;
	des[0]=(char16_t)((src>>10)+0xD800);
	des[1]=(char16_t)((src&0x3FF)+0xDC00);
	return 2;
}
int shinsei_utf32CharToUtf8Char(unsigned char*restrict des,const char32_t src){
	if(src<=0x7F){
		des[0]=(char)src;
		return 1;
	}
	if(src<=0x7FF){
		des[0]=(char)(0xC0|(src>>6));
		des[1]=(char)(0x80|(src&0x3F));
		return 2;
	}
	if(src<=0xFFFF){
		des[0]=(char)(0xE0|(src>>12));
		des[1]=(char)(0x80|((src>>6)&0x3F));
		des[2]=(char)(0x80|(src&0x3F));
		return 3;
	}
	if(src<=0x10FFFF){
		des[0]=(char)(0xF0|(src>>18));
		des[1]=(char)(0x80|((src>>12)&0x3F));
		des[2]=(char)(0x80|((src>>6)&0x3F));
		des[3]=(char)(0x80|(src&0x3F));
		return 4;
	}
	return 0;
}
int shinsei_utf16CharToUtf8Char(unsigned char*restrict des,const char16_t*restrict src,const size_t src_len){
	if(__builtin_expect(!src_len,0)) return 0;
	uint32_t buf;
	if(src[0]>=0xD800&&src[0]<=0xDBFF){
		if(src_len>=2&&src[1]>=0xDC00&&src[1]<=0xDFFF){
			buf=(((char32_t)(src[0]&0x3FF)<<10)|(src[1]&0x3FF))+0x10000;
		}
		else return 0;
	}
	else buf=(char32_t)src[0];
	return shinsei_utf32CharToUtf8Char(des,buf);
}

int shinsei_utf16CharToUtf32Char(char32_t*restrict des,const char16_t* src,const size_t src_len){
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
int shinsei_utf8CharToUtf32Char(char32_t*restrict des,const unsigned char* src,const size_t src_len){
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
int shinsei_utf8CharToUtf16Char(char16_t*restrict des,const unsigned char* src,const size_t src_len){
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

int shinsei_parseEscapedCharA(char*restrict des,const char*restrict src,const size_t src_len){
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
			*des='\e';
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
			**des=L'\e';
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
			**des=(**des<<3)+(src[1]-L'0');
			if(src_len<=2||!shinsei_isODigitW(src[2])){
				++*des;
				return 2;
			}
			**des=(**des<<3)+(src[2]-L'0');
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
			return i;
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
				return i;
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
			return i;
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
				return i;
			}
			if(__builtin_expect(src_len<5,0)) return 0;
			register int i=0;
			**des=0;
			while(__builtin_expect(i<4,1)){
				if(__builtin_expect(!iswxdigit(*++src),0)) return 0;
				**des=(**des<<4)+(iswdigit(*src)?*src-L'0':towupper(*src)-L'A'+10);
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
				//
			}
			break;
		}
	}
	++*des;
	return 1;
}

size_t shinsei_readEscapedLineA(char*restrict str,const size_t len){
	size_t res=0;
	size_t i=0;
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

size_t shinsei_readEscapedLineW(wchar_t*restrict str,const size_t len){
	size_t i=0;
	wchar_t*restrict des=str;
	while(__builtin_expect(i<len,1)){
		if(__builtin_expect(str[i]==L'\\',0)){
			size_t now=shinsei_parseEscapedCharW((wchar_t**restrict)&des,str+i+1,len-i-1);
			if(__builtin_expect(!now,0)) return 0;
			i+=now+1;
			continue;
		}
		*des++=str[i++];
	}
	*des=L'\0';
	return des-str;
}

size_t shinsei_stringLinesA(size_t*restrict idx_buf,size_t idx_buf_len,char*restrict str,const size_t str_len){
	if(__builtin_expect(!str_len,0)) return 0;
	size_t i=0;
	size_t pre=0;
	size_t res=0;
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
	if(__builtin_expect(!str_len,0)) return 0;
	size_t i=0;
	size_t pre=0;
	size_t res=0;
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
	if(__builtin_expect(!str_len,0)) return 0;
	size_t i=0;
	size_t pre=0;
	size_t res=0;
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
	if(__builtin_expect(!str_len,0)) return 0;
	size_t i=0;
	size_t pre=0;
	size_t res=0;
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
	return 0;
}
size_t shinsei_escapedLineToStringsW(size_t*restrict idx_buf,size_t idx_buf_len,wchar_t*restrict str,const size_t str_len){
	size_t i=0;
	size_t pre=0;
	size_t res=0;
	size_t now;
	wchar_t*restrict des=str;
	while(__builtin_expect(i<str_len,1)){
		if(__builtin_expect(str[i]=='\\',0)){
			now=shinsei_parseEscapedCharW((wchar_t**restrict)&des,str+i+1,str_len-i-1);
			if(__builtin_expect(!now,0)) return 0;
			if(__builtin_expect(des[-now]==L'\n',0)){
				des[-now]=L'\0';
				if(des>str&&des[-now-1]==L'\r') des[-now-1]=L'\0';
				if(res<idx_buf_len){
					idx_buf[res]=pre;
					pre=des-now-str+1;
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
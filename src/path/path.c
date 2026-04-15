#include"shinsei/minimal/path.h"

bool shinsei_isWindowsPathDelimiterA(const char ch){
	return (ch|0x20)=='/';
}
bool shinsei_isWindowsPathDelimiterW(const wchar_t ch){
	return (ch|0x20)==L'/';
}
bool shinsei_isWindowsPathDelimiterU8(const char8_t ch){
	return (ch|0x20)==u8'/';
}
bool shinsei_isWindowsPathDelimiterU8S(const char8_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const int size=shinsei_uTF8CharSize(**str_ptr);
	if(__builtin_expect(len<(size_t)size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr[-1]|0x20)==u8'/';
}
bool shinsei_isWindowsPathDelimiterU16(const char16_t ch){
	return (ch|0x20)==u'/';
}
bool shinsei_isWindowsPathDelimiterU16S(const char16_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const int size=shinsei_uTF16CharSize(**str_ptr);
	if(__builtin_expect(len<(size_t)size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr[-1]|0x20)==u'/';
}
bool shinsei_isWindowsPathDelimiterU32(const char32_t ch){
	return (ch|0x20)==U'/';
}

bool shinsei_isLinuxPathDelimiterA(const char ch){
	return ch==SHINSEI_PATH_UNIX_DELIMITER_A;
}
bool shinsei_isLinuxPathDelimiterW(const wchar_t ch){
	return ch==SHINSEI_PATH_UNIX_DELIMITER_W;
}
bool shinsei_isLinuxPathDelimiterU8(const char8_t ch){
	return ch==SHINSEI_PATH_UNIX_DELIMITER_U8;
}
bool shinsei_isLinuxPathDelimiterU8S(const char8_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const int size=shinsei_uTF8CharSize(**str_ptr);
	if(__builtin_expect(len<(size_t)size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]==SHINSEI_PATH_UNIX_DELIMITER_U8;
}
bool shinsei_isLinuxPathDelimiterU16(const char18_t ch){
	return ch==SHINSEI_PATH_UNIX_DELIMITER_U16;
}
bool shinsei_isLinuxPathDelimiterU16S(const char16_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const int size=shinsei_uTF16CharSize(**str_ptr);
	if(__builtin_expect(len<(size_t)size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]==SHINSEI_PATH_UNIX_DELIMITER_U16;
}
bool shinsei_isLinuxPathDelimiterU32(const char32_t ch){
	return ch==SHINSEI_PATH_UNIX_DELIMITER_U32;
}

bool shinsei_isWindowsPathIllegalCharA(const char ch){
	if((unsigned char)ch<32) return true;
	switch(ch){
		case '"':
		case '*':
		case '/':
		case '\\':
		case ':':
		case '<':
		case '>':
		case '?':
		case '|':{
			return true;
		}
	}
	return false;
}
bool shinsei_isWindowsPathIllegalCharW(const wchar_t ch){
	if((unsigned int)ch<32) return true;
	switch(ch){
		case L'"':
		case L'*':
		case L'/':
		case L'\\':
		case L':':
		case L'<':
		case L'>':
		case L'?':
		case L'|':{
			return true;
		}
	}
	return false;
}
bool shinsei_isWindowsPathIllegalCharU8(const char8_t ch){
	if(ch<32) return true;
	switch(ch){
		case u8'"':
		case u8'*':
		case u8'/':
		case u8'\\':
		case u8':':
		case u8'<':
		case u8'>':
		case u8'?':
		case u8'|':{
			return true;
		}
	}
	return false;
}
bool shinsei_isWindowsPathDelimiterU8S(const char8_t**const restrict str_ptr,const size_t len){
	is(__builtin_expect(!len,0)) return false;
	register const int size=shinsei_uTF8CharSize(**str_ptr);
	if(__builtin_expect(len<(size_t)size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	switch(*str_ptr[-1]){
		case u8'"':
		case u8'*':
		case u8'/':
		case u8'\\':
		case u8':':
		case u8'<':
		case u8'>':
		case u8'?':
		case u8'|':{
			return true;
		}
	}
	return false;
}
bool shinsei_isWindowsPathIllegalCharU16(const char16_t ch){
	if(ch<32) return true;
	switch(ch){
		case u'"':
		case u'*':
		case u'/':
		case u'\\':
		case u':':
		case u'<':
		case u'>':
		case u'?':
		case u'|':{
			return true;
		}
	}
	return false;
}
bool shinsei_isWindowsPathIllegalCharU16S(const char16_t**const const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const int size=shinsei_uTF16CharSize(**str_ptr);
	if(__builtin_expect(len<(size_t)size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	switch(*str_ptr[-1]){
		case u'"':
		case u'*':
		case u'/':
		case u'\\':
		case u':':
		case u'<':
		case u'>':
		case u'?':
		case u'|':{
			return true;
		}
	}
	return false;
}
bool shinsei_isWindowsPathIllegalCharU32(const char32_t ch){
	if(ch<32) return true;
	switch(ch){
		case U'"':
		case U'*':
		case U'/':
		case U'\\':
		case U':':
		case U'<':
		case U'>':
		case U'?':
		case U'|':{
			return true;
		}
	}
	return false;
}

bool shinsei_isLinuxPathIllegalCharA(const char ch){
	return ch=='\0'||ch==SHINSEI_PATH_UNIX_DELIMITER_A;
}
bool shinsei_isLinuxPathIllegalCharW(const wchar_t ch){
	return ch==L'\0'||ch==SHINSEI_PATH_UNIX_DELIMITER_W;
}
bool shinsei_isLinuxPathIllegalCharU8(const char8_t ch){
	return ch==u8'\0'||ch==SHINSEI_PATH_UNIX_DELIMITER_U8;
}
bool shinsei_isLinuxPathDelimiterU8S(const char8_t**const restrict str_ptr,const size_t len){
	is(__builtin_expect(!len,0)) return false;
	register const int size=shinsei_uTF8CharSize(**str_ptr);
	if(__builtin_expect(len<(size_t)size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]==u8'\0'||*str_ptr[-1]==SHINSEI_PATH_UNIX_DELIMITER_U8;
}
bool shinsei_isLinuxPathIllegalCharU16(const char16_t ch){
	return ch==u'\0'||ch==SHINSEI_PATH_UNIX_DELIMITER_U16;
}
bool shinsei_isLinuxPathIllegalCharU16S(const char16_t**const const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register const int size=shinsei_uTF16CharSize(**str_ptr);
	if(__builtin_expect(len<(size_t)size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]==u'\0'||*str_ptr[-1]==SHINSEI_PATH_UNIX_DELIMITER_U16;
}
bool shinsei_isLinuxPathIllegalCharU32(const char32_t ch){
	return ch==U'0'||ch==SHINSEI_PATH_UNIX_DELIMITER_U32;
}

int shinsei_windowsPathNormalizeA(char*const restrict path,size_t*const restrict len){
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register bool can_traverse=false;
	register bool device_path=false;
	register int res;
	register char* ptr;
	register const size_t cnt=*len;
	if(shinsei_isWindowsPathDelimiterA(path[0])){
		path[0]=SHINSEI_PATH_WINDOWS_DELIMITER_A;
		if(*len>=2&&shinsei_isWindowsPathDelimiterA(path[1])){
			path[1]=SHINSEI_PATH_WINDOWS_DELIMITER_A;
			// Device path "\\?\xxx" or DOS device path "\\.\xxx"
			if(*len>=4&&(path[2]=='?'||path[2]=='.')&&shinsei_isWindowsPathDelimiterA(path[3])){
				// Prevent nested device prefix like "\\?\\?\"
				if(__builtin_expect(*len>=6&&shinsei_isWindowsPathDelimiterA(path[4])&&(path[5]=='?'||path[5]=='.')&&shinsei_isWindowsPathDelimiterA(path[6]),0)){
					return SHINSEI_PATH_ILLEGAL;
				}
				path[3]=SHINSEI_PATH_WINDOWS_DELIMITER_A;
				device_path=true;
				// Extended UNC path "\\?\UNC\server\share\xxx"
				if(path[2]=='?'&&*len>=8&&(path[4]=='U'||path[4]=='u')&&(path[5]=='N'||path[5]=='n')&&(path[6]=='C'||path[6]=='c')&&shinsei_isWindowsPathDelimiterA(path[7])){
					path[4]='U';
					path[5]='N';
					path[6]='C';
					path[7]=SHINSEI_PATH_WINDOWS_DELIMITER_A;
					register size_t i=8;
					// Parse server
					if(__builtin_expect(i>=*len||shinsei_isWindowsPathDelimiterA(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!shinsei_isWindowsPathDelimiterA(path[i])){
						if(__builtin_expect(shinsei_isWindowsPathIllegalCharA(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
					path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_A;
					++i;
					// Parse share
					if(__builtin_expect(i>=*len||shinsei_isWindowsPathDelimiterA(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!shinsei_isWindowsPathDelimiterA(path[i])){
						if(__builtin_expect(shinsei_isWindowsPathIllegalCharA(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(i<*len){
						path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_A;
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
				if(__builtin_expect(i>=*len||shinsei_isWindowsPathDelimiterA(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!shinsei_isWindowsPathDelimiterA(path[i])){
					if(__builtin_expect(shinsei_isWindowsPathIllegalCharA(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
				path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_A;
				++i;
				// Parse share
				if(__builtin_expect(i>=*len||shinsei_isWindowsPathDelimiterA(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!shinsei_isWindowsPathDelimiterA(path[i])){
					if(__builtin_expect(shinsei_isWindowsPathIllegalCharA(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				// Set root
				if(i<*len){
					path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_A;
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
				path[1]='\0';
				return SHINSEI_PATH_RELATIVE;
			}
			ptr=path+1;
			--cnt;
			while(*ptr=='.'){
				if(*len==2){
					path[1]='\0';
					*len=1;
					return SHINSEI_PATH_RELATIVE;
				}
				if(ptr[1]=='.'){
					if(*len==3){
						path[1]='\0';
						*len=1;
						return SHINSEI_PATH_RELATIVE;
					}
					if(__builtin_expect(ptr[2]=='.',0)) return SHINSEI_PATH_ILLEGAL;
					if(shinsei_isWindowsPathDelimiterA(ptr[2])){
						// First segment is "..". Can't get parent any more.
						ptr[2]=SHINSEI_PATH_WINDOWS_DELIMITER_A;
						ptr+=3;
						cnt-=3;
						continue;
					}
					// First segment is "..xxx"
					break;
				}
				if(shinsei_isWindowsPathDelimiterA(ptr[1])){
					// First segment is "."
					ptr[1]=SHINSEI_PATH_WINDOWS_DELIMITER_A;
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
		if(*len>=2&&path[1]==':'){
			// Local path with drive prefix
			if(__builtin_expect(!shinsei_isAlphaA(path[0]),0)) return SHINSEI_PATH_ILLEGAL;
			path[0]=(char)shinsei_toUpperA(path[0]);
			if(*len==2){
				// Drive only "X:".
				path[2]='\0';
				return SHINSEI_PATH_RELATIVE;
			}
			if(shinsei_isWindowsPathDelimiterA(path[2])){
				// Local absolute path "X:\". Root is "X:\".
				path[2]=SHINSEI_PATH_WINDOWS_DELIMITER_A;
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
		if(shinsei_isWindowsPathDelimiterA(ptr[r])){
			ptr[w++]=SHINSEI_PATH_WINDOWS_DELIMITER_A;
			// Collapse multiple delimiters
			while(++r<cnt&&shinsei_isWindowsPathDelimiterA(ptr[r]));
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&!shinsei_isWindowsPathDelimiterA(ptr[r])){
			if(!device_path&&__builtin_expect(shinsei_isWindowsPathIllegalCharA(ptr[r]),0)) return SHINSEI_PATH_ILLEGAL;
			ptr[w++]=ptr[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&ptr[seg_start]=='.'){
			// Ignore "."
			w=seg_start;
		}
		if(seg_len==2&&ptr[seg_start]=='.'&&ptr[seg_start+1]=='.'){
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
	path[*len]='\0';
	return res;
}
int shinsei_windowsPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len){
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register bool can_traverse=false;
	register bool device_path=false;
	register int res;
	register wchar_t* ptr;
	register const size_t cnt=*len;
	if(shinsei_isWindowsPathDelimiterW(path[0])){
		path[0]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
		if(*len>=2&&shinsei_isWindowsPathDelimiterW(path[1])){
			path[1]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
			// Device path "\\?\xxx" or DOS device path "\\.\xxx"
			if(*len>=4&&(path[2]==L'?'||path[2]==L'.')&&shinsei_isWindowsPathDelimiterW(path[3])){
				// Prevent nested device prefix like "\\?\\?\"
				if(__builtin_expect(*len>=6&&shinsei_isWindowsPathDelimiterW(path[4])&&(path[5]==L'?'||path[5]==L'.')&&shinsei_isWindowsPathDelimiterW(path[6]),0)){
					return SHINSEI_PATH_ILLEGAL;
				}
				path[3]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
				device_path=true;
				// Extended UNC path "\\?\UNC\server\share\xxx"
				if(path[2]==L'?'&&*len>=8&&(path[4]==L'U'||path[4]==L'u')&&(path[5]==L'N'||path[5]==L'n')&&(path[6]==L'C'||path[6]==L'c')&&shinsei_isWindowsPathDelimiterW(path[7])){
					path[4]=L'U';
					path[5]=L'N';
					path[6]=L'C';
					path[7]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
					register size_t i=8;
					// Parse server
					if(__builtin_expect(i>=*len||shinsei_isWindowsPathDelimiterW(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!shinsei_isWindowsPathDelimiterW(path[i])){
						if(__builtin_expect(shinsei_isWindowsPathIllegalCharW(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
					path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
					++i;
					// Parse share
					if(__builtin_expect(i>=*len||shinsei_isWindowsPathDelimiterW(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					while(i<*len&&!shinsei_isWindowsPathDelimiterW(path[i])){
						if(__builtin_expect(shinsei_isWindowsPathIllegalCharW(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
						++i;
					}
					if(i<*len){
						path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
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
				if(__builtin_expect(i>=*len||shinsei_isWindowsPathDelimiterW(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!shinsei_isWindowsPathDelimiterW(path[i])){
					if(__builtin_expect(shinsei_isWindowsPathIllegalCharW(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				if(__builtin_expect(i>=*len,0)) return SHINSEI_PATH_ILLEGAL;
				path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
				++i;
				// Parse share
				if(__builtin_expect(i>=*len||shinsei_isWindowsPathDelimiterW(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
				while(i<*len&&!shinsei_isWindowsPathDelimiterW(path[i])){
					if(__builtin_expect(shinsei_isWindowsPathIllegalCharW(path[i]),0)) return SHINSEI_PATH_ILLEGAL;
					++i;
				}
				// Set root
				if(i<*len){
					path[i]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
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
				path[1]=L'\0';
				return SHINSEI_PATH_RELATIVE;
			}
			ptr=path+1;
			--cnt;
			while(*ptr==L'.'){
				if(*len==2){
					path[1]=L'\0';
					*len=1;
					return SHINSEI_PATH_RELATIVE;
				}
				if(ptr[1]==L'.'){
					if(*len==3){
						path[1]=L'\0';
						*len=1;
						return SHINSEI_PATH_RELATIVE;
					}
					if(__builtin_expect(ptr[2]==L'.',0)) return SHINSEI_PATH_ILLEGAL;
					if(shinsei_isWindowsPathDelimiterW(ptr[2])){
						// First segment is "..". Can't get parent any more.
						ptr[2]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
						ptr+=3;
						cnt-=3;
						continue;
					}
					// First segment is "..xxx"
					break;
				}
				if(shinsei_isWindowsPathDelimiterW(ptr[1])){
					// First segment is "."
					ptr[1]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
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
		if(*len>=2&&path[1]==L':'){
			// Local path with drive prefix
			if(__builtin_expect(!shinsei_isAlphaW(path[0]),0)) return SHINSEI_PATH_ILLEGAL;
			path[0]=shinsei_toUpperW(path[0]);
			if(*len==2){
				// Drive only "X:".
				path[2]=L'\0';
				return SHINSEI_PATH_RELATIVE;
			}
			if(shinsei_isWindowsPathDelimiterW(path[2])){
				// Local absolute path "X:\". Root is "X:\".
				path[2]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
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
		if(shinsei_isWindowsPathDelimiterW(ptr[r])){
			ptr[w++]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
			// Collapse multiple delimiters
			while(++r<cnt&&shinsei_isWindowsPathDelimiterW(ptr[r]));
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&!shinsei_isWindowsPathDelimiterW(ptr[r])){
			if(!device_path&&__builtin_expect(shinsei_isWindowsPathIllegalCharW(ptr[r]),0)) return SHINSEI_PATH_ILLEGAL;
			ptr[w++]=ptr[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&ptr[seg_start]==L'.'){
			// Ignore "."
			w=seg_start;
		}
		if(seg_len==2&&ptr[seg_start]==L'.'&&ptr[seg_start+1]==L'.'){
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
	path[*len]=L'\0';
	return res;
}

_SHINSEI_OS_INLINE static int unixPathNormalizeA(char*const restrict path,size_t*const restrict len){
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_UNIX_DELIMITER_A;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_UNIX_DELIMITER_A;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_A) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_UNIX_DELIMITER_A){
			if(w>0&&path[w-1]!=SHINSEI_PATH_UNIX_DELIMITER_A){
				path[w++]=SHINSEI_PATH_UNIX_DELIMITER_A;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_A);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_UNIX_DELIMITER_A){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]=='.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]=='.'&&path[seg_start+1]=='.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]=='.'&&path[rewind-2]=='.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_UNIX_DELIMITER_A);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_UNIX_DELIMITER_A){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_UNIX_DELIMITER_A)?rewind+1:0;
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
	if(w>1&&path[w-1]==SHINSEI_PATH_UNIX_DELIMITER_A) --w;
	if(!w&&!is_abs){
        path[0]='.';
        w=1;
    }
	*len=w;
	path[*len]='\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}
_SHINSEI_OS_INLINE static int unixPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len){
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_UNIX_DELIMITER_W;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_UNIX_DELIMITER_W;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_W) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_UNIX_DELIMITER_W){
			if(w>0&&path[w-1]!=SHINSEI_PATH_UNIX_DELIMITER_W){
				path[w++]=SHINSEI_PATH_UNIX_DELIMITER_W;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_W);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_UNIX_DELIMITER_W){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]==L'.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]==L'.'&&path[seg_start+1]==L'.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]==L'.'&&path[rewind-2]==L'.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_UNIX_DELIMITER_W);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_UNIX_DELIMITER_W){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_UNIX_DELIMITER_W)?rewind+1:0;
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
	if(w>1&&path[w-1]==SHINSEI_PATH_UNIX_DELIMITER_W) --w;
	if(!w&&!is_abs){
        path[0]=L'.';
        w=1;
    }
	*len=w;
	path[*len]=L'\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}
_SHINSEI_OS_INLINE static int unixPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len){
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
					w=(path[rewind]==SHINSEI_PATH_UNIX_DELIMITER_U8)?rewind+1:0;
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
_SHINSEI_OS_INLINE static int unixPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len){
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
					w=(path[rewind]==SHINSEI_PATH_UNIX_DELIMITER_U16)?rewind+1:0;
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
_SHINSEI_OS_INLINE static int unixPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len){
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
					w=(path[rewind]==SHINSEI_PATH_UNIX_DELIMITER_U32)?rewind+1:0;
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
#if defined(_SHINSEI_OS_WINDOWS)
_SHINSEI_OS_INLINE static int unixPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeW(path,len);
}
#elif defined(_SHINSEI_OS_UNIX)
_SHINSEI_OS_INLINE static int unixPathNormalizeN(char8_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU8(path,len);
}
#endif

int shinsei_unixPathNormalizeA(char*const restrict path,size_t*const restrict len){
	return unixPathNormalizeA(path,len);
}
int shinsei_unixPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeW(path,len);
}
int shinsei_unixPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU8(path,len);
}
int shinsei_unixPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU16(path,len);
}
int shinsei_unixPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU32(path,len);
}
#if defined(_SHINSEI_OS_WINDOWS)
int shinsei_unixPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeN(path,len);
}
#elif defined(_SHINSEI_OS_UNIX)
int shinsei_unixPathNormalizeN(char8_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeN(path,len);
}
#endif

int shinsei_linuxPathNormalizeA(char*const restrict path,size_t*const restrict len){
	return unixPathNormalizeA(path,len);
}
int shinsei_linuxPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeW(path,len);
}
int shinsei_linuxPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU8(path,len);
}
int shinsei_linuxPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU16(path,len);
}
int shinsei_linuxPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU32(path,len);
}
#if defined(_SHINSEI_OS_WINDOWS)
int shinsei_linuxPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeN(path,len);
}
#elif defined(_SHINSEI_OS_UNIX)
int shinsei_linuxPathNormalizeN(char8_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeN(path,len);
}
#endif

int shinsei_applePathNormalizeA(char*const restrict path,size_t*const restrict len){
	return unixPathNormalizeA(path,len);
}
int shinsei_applePathNormalizeW(wchar_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeW(path,len);
}
int shinsei_applePathNormalizeU8(char8_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU8(path,len);
}
int shinsei_applePathNormalizeU16(char16_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU16(path,len);
}
int shinsei_applePathNormalizeU32(char32_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU32(path,len);
}
#if defined(_SHINSEI_OS_WINDOWS)
int shinsei_applePathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeN(path,len);
}
#elif defined(_SHINSEI_OS_UNIX)
int shinsei_applePathNormalizeN(char8_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeN(path,len);
}
#endif

int shinsei_sunPathNormalizeA(char*const restrict path,size_t*const restrict len){
	return unixPathNormalizeA(path,len);
}
int shinsei_sunPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeW(path,len);
}
int shinsei_sunPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU8(path,len);
}
int shinsei_sunPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU16(path,len);
}
int shinsei_sunPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU32(path,len);
}
#if defined(_SHINSEI_OS_WINDOWS)
int shinsei_sunPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeN(path,len);
}
#elif defined(_SHINSEI_OS_UNIX)
int shinsei_sunPathNormalizeN(char8_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeN(path,len);
}
#endif

int shinsei_freeBSDPathNormalizeA(char*const restrict path,size_t*const restrict len){
	return unixPathNormalizeA(path,len);
}
int shinsei_freeBSDPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeW(path,len);
}
int shinsei_freeBSDPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU8(path,len);
}
int shinsei_freeBSDPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU16(path,len);
}
int shinsei_freeBSDPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU32(path,len);
}
#if defined(_SHINSEI_OS_WINDOWS)
int shinsei_freeBSDPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeN(path,len);
}
#elif defined(_SHINSEI_OS_UNIX)
int shinsei_freeBSDPathNormalizeN(char8_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeN(path,len);
}
#endif

int shinsei_cygwinPathNormalizeA(char*const restrict path,size_t*const restrict len){
	return unixPathNormalizeA(path,len);
}
int shinsei_cygwinPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeW(path,len);
}
int shinsei_cygwinPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU8(path,len);
}
int shinsei_cygwinPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU16(path,len);
}
int shinsei_cygwinPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU32(path,len);
}
#if defined(_SHINSEI_OS_WINDOWS)
int shinsei_cygwinPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeN(path,len);
}
#elif defined(_SHINSEI_OS_UNIX)
int shinsei_cygwinPathNormalizeN(char8_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeN(path,len);
}
#endif

#if defined(_SHINSEI_OS_WINDOWS)
int shinsei_nativePathNormalizeA(char*const restrict path,size_t*const restrict len){
	return windowsPathNormalizeA(path,len);
}
int shinsei_nativePathNormalizeW(wchar_t*const restrict path,size_t*const restrict len){
	return windowsPathNormalizeW(path,len);
}
int shinsei_nativePathNormalizeU8(char8_t*const restrict path,size_t*const restrict len){
	return windowsPathNormalizeU8(path,len);
}
int shinsei_nativePathNormalizeU16(char16_t*const restrict path,size_t*const restrict len){
	return windowsPathNormalizeU16(path,len);
}
int shinsei_nativePathNormalizeU32(char32_t*const restrict path,size_t*const restrict len){
	return windowsPathNormalizeU32(path,len);
}
int shinsei_nativePathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	return windowsPathNormalizeN(path,len);
}
#elif defined(_SHINSEI_OS_UNIX)
int shinsei_nativePathNormalizeA(char*const restrict path,size_t*const restrict len){
	return unixPathNormalizeA(path,len);
}
int shinsei_nativePathNormalizeW(wchar_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeW(path,len);
}
int shinsei_nativePathNormalizeU8(char8_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU8(path,len);
}
int shinsei_nativePathNormalizeU16(char16_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU16(path,len);
}
int shinsei_nativePathNormalizeU32(char32_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU32(path,len);
}
int shinsei_nativePathNormalizeN(char8_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeN(path,len);
}
#endif

_SHINSEI_OS_INLINE static int uRLPathNormalizeA(char*const restrict path,size_t*const restrict len){
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_URL_DELIMITER_A;
	if(*len==1){
		return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
	}
	register const bool end_with_slash=path[*len-1]==SHINSEI_PATH_URL_DELIMITER_A;
	register const size_t cnt=*len-(size_t)end_with_slash;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_URL_DELIMITER_A;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_URL_DELIMITER_A) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_URL_DELIMITER_A){
			if(w>0&&path[w-1]!=SHINSEI_PATH_URL_DELIMITER_A){
				path[w++]=SHINSEI_PATH_URL_DELIMITER_A;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_URL_DELIMITER_A);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_URL_DELIMITER_A){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]=='.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]=='.'&&path[seg_start+1]=='.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]=='.'&&path[rewind-2]=='.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_URL_DELIMITER_A);
				if(is_prev_back){
					pos[back]=seg_start;
					back=(back+1)%(SHINSEI_PATH_SBO_CNT+1);
					if(back==front) front=(front+1)%(SHINSEI_PATH_SBO_CNT+1);
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_URL_DELIMITER_A){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_URL_DELIMITER_A)?rewind+1:0;
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
	if(w>1&&path[w-1]==SHINSEI_PATH_URL_DELIMITER_A) --w;
	if(!w&&!is_abs){
        path[0]='.';
        w=1;
    }
	if(end_with_slash){
		if(is_abs&&w==1){
			path[1]='\0';
			*len=1;
			return SHINSEI_PATH_ABSOLUTE;
		}
		path[w]=SHINSEI_PATH_URL_DELIMITER_A;
	}
	*len=w+(size_t)end_with_slash;
	path[*len]='\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

int shinsei_uRLPathNormalizeA(char*const restrict path,size_t*const restrict len){
	return unixPathNormalizeA(path,len);
}
int shinsei_uRLPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeW(path,len);
}
int shinsei_uRLPathNormalizeU8(char8_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU8(path,len);
}
int shinsei_uRLPathNormalizeU16(char16_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU16(path,len);
}
int shinsei_uRLPathNormalizeU32(char32_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeU32(path,len);
}
#if defined(_SHINSEI_OS_WINDOWS)
int shinsei_uRLPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeN(path,len);
}
#elif defined(_SHINSEI_OS_UNIX)
int shinsei_uRLPathNormalizeN(char8_t*const restrict path,size_t*const restrict len){
	return unixPathNormalizeN(path,len);
}
#endif

_SHINSEI_OS_INLINE static int unixPathNormalizeNotraversalA(char*const restrict path,size_t*const restrict len){
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_UNIX_DELIMITER_A;
	register const size_t cnt=*len;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_UNIX_DELIMITER_A;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_A) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_UNIX_DELIMITER_A){
			if(w>0&&path[w-1]!=SHINSEI_PATH_UNIX_DELIMITER_A){
				path[w++]=SHINSEI_PATH_UNIX_DELIMITER_A;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_UNIX_DELIMITER_A);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_UNIX_DELIMITER_A){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]=='.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]=='.'&&path[seg_start+1]=='.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]=='.'&&path[rewind-2]=='.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_UNIX_DELIMITER_A);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_UNIX_DELIMITER_A){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_UNIX_DELIMITER_A)?rewind+1:0;
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
	if(w>1&&path[w-1]==SHINSEI_PATH_UNIX_DELIMITER_A) --w;
	if(!w&&!is_abs){
        path[0]='.';
        w=1;
    }
	*len=w;
	path[*len]='\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

_SHINSEI_OS_INLINE static int uRLPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len){
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register const bool is_abs=path[0]==SHINSEI_PATH_URL_DELIMITER_A;
	if(*len==1){
		return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
	}
	register const bool end_with_slash=path[*len-1]==SHINSEI_PATH_URL_DELIMITER_A;
	register const size_t cnt=*len-(size_t)end_with_slash;
	register size_t r=0;
	register size_t w=0;
	if(is_abs){
		// Absolute path. Root is '/'.
		path[w++]=SHINSEI_PATH_URL_DELIMITER_A;
		++r;
		while(r<cnt&&path[r]==SHINSEI_PATH_URL_DELIMITER_A) ++r;
	}
	size_t pos[SHINSEI_PATH_SBO_CNT+1];
	register size_t front=0;
	register size_t back=0;
	while(r<cnt){
		// Unify delimiter
		if(path[r]==SHINSEI_PATH_URL_DELIMITER_A){
			if(w>0&&path[w-1]!=SHINSEI_PATH_URL_DELIMITER_A){
				path[w++]=SHINSEI_PATH_URL_DELIMITER_A;
			}
			// Collapse multiple delimiter
			while(++r<cnt&&path[r]==SHINSEI_PATH_URL_DELIMITER_A);
			continue;
		}
		register const size_t seg_start=w;
		while(r<cnt&&path[r]!=SHINSEI_PATH_URL_DELIMITER_A){
			path[w++]=path[r++];
		}
		register const size_t seg_len=w-seg_start;
		if(seg_len==1&&path[seg_start]=='.'){
			// Ignore "."
			w=seg_start;
		}
		else if(seg_len==2&&path[seg_start]=='.'&&path[seg_start+1]=='.'){
			// Parse ".."
			if(front!=back){
				// Pop previous segment
				back=(back+SHINSEI_PATH_SBO_CNT)%(SHINSEI_PATH_SBO_CNT+1);
				w=pos[back];
			}
			else if(w>!!is_abs){
				// Manual backtrace
				register size_t rewind=w-1;
				register const bool is_prev_back=!is_abs&&rewind>=2&&path[rewind-1]=='.'&&path[rewind-2]=='.'&&(rewind==2||path[rewind-3]==SHINSEI_PATH_URL_DELIMITER_A);
				if(is_prev_back){
					return SHINSEI_PATH_ILLEGAL|SHINSEI_PATH_TRAVERSAL;
				}
				else{
					while(rewind>0&&path[rewind]!=SHINSEI_PATH_URL_DELIMITER_A){
						--rewind;
					}
					w=(path[rewind]==SHINSEI_PATH_URL_DELIMITER_A)?rewind+1:0;
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
	if(w>1&&path[w-1]==SHINSEI_PATH_URL_DELIMITER_A) --w;
	if(!w&&!is_abs){
        path[0]='.';
        w=1;
    }
	if(end_with_slash&&!(is_abs&&w==1)){
		path[w++]=SHINSEI_PATH_URL_DELIMITER_A;
	}
	*len=w;
	path[*len]='\0';
	return is_abs*SHINSEI_PATH_ABSOLUTE+!is_abs*SHINSEI_PATH_RELATIVE;
}

size_t shinsei_windowsPathJoinA(char*const restrict des,const size_t des_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...){
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(!!des_len,1)) *des='\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		// SBO path
		const char* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args;
		va_start(args,first_part_len);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args,const char*);
			part_len[i]=va_arg(args,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args);
		if(res>des_len) return res;
		register size_t last=first_part_len;
        if(des!=first_part){
            __builtin_memcpy(des,part[0],part_len[0]);
        }
        for(register int i=1;i<path_cnt;++i){
            des[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_A;
            __builtin_memcpy(des+last,part[i],part_len[i]);
            last+=part_len[i];
        }
		des[res]='\0';
		return res;
	}
	if(des_len>=SHINSEI_PATH_WINDOWS_MAX||des_len<=SHINSEI_PATH_MINIMAL){
		// Minimal or overkill path
		if(des!=first_part&&res<des_len) __builtin_memcpy(des,first_part,first_part_len);
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args;
		va_start(args,first_part_len);
		for(register int i=1;i<path_cnt;++i){
			register const char*const cur_part=va_arg(args,const char*const);
			register const size_t cur_part_len=va_arg(args,const size_t);
			res+=cur_part_len+1;
			if(res<=des_len){
				des[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_A;
				__builtin_memcpy(des+last,cur_part,cur_part_len);
			}
			last=res;
		}
		va_end(args);
		if(res<=des_len) des[res]='\0';
		return res;
	}
	// Normal path
	va_list args;
	va_start(args,first_part_len);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args,const char*const);
		res+=va_arg(args,const size_t)+1;
	}
	va_end(args);
	if(res>des_len) return res;
	if(des!=first_part){
        __builtin_memcpy(des,first_part,first_part_len);
    }
	register size_t last=first_part_len;
	va_start(args,first_part_len);
	for(register int i=1;i<path_cnt;++i){
		register const char*const cur_part=va_arg(args,const char*const);
		register const size_t cur_part_len=va_arg(args,const size_t);
		des[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_A;
		__builtin_memcpy(des+last,cur_part,cur_part_len);
		last+=cur_part_len;
	}
	va_end(args);
	if(res<=des_len) des[res]='\0';
	return res;
}
size_t shinsei_windowsPathJoinW(wchar_t*const restrict des,const size_t des_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...){
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(!!des_len,1)) *des=L'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		// SBO path
		const wchar_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args;
		va_start(args,first_part_len);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args,const wchar_t*);
			part_len[i]=va_arg(args,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args);
		if(res>des_len) return res;
		register size_t last=first_part_len;
        if(des!=first_part){
            __builtin_memcpy(des,part[0],part_len[0]);
        }
        for(register int i=1;i<path_cnt;++i){
            des[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
            __builtin_memcpy(des+last,part[i],part_len[i]);
            last+=part_len[i];
        }
		des[res]=L'\0';
		return res;
	}
	if(des_len>=SHINSEI_PATH_WINDOWS_MAX||des_len<=SHINSEI_PATH_MINIMAL){
		// Minimal or overkill path
		if(des!=first_part&&res<des_len) __builtin_memcpy(des,first_part,first_part_len);
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args;
		va_start(args,first_part_len);
		for(register int i=1;i<path_cnt;++i){
			register const wchar_t*const cur_part=va_arg(args,const wchar_t*const);
			register const size_t cur_part_len=va_arg(args,const size_t);
			res+=cur_part_len+1;
			if(res<=des_len){
				des[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
				__builtin_memcpy(des+last,cur_part,cur_part_len);
			}
			last=res;
		}
		va_end(args);
		if(res<=des_len) des[res]=L'\0';
		return res;
	}
	// Normal path
	va_list args;
	va_start(args,first_part_len);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args,const wchar_t*const);
		res+=va_arg(args,const size_t)+1;
	}
	va_end(args);
	if(res>des_len) return res;
	if(des!=first_part){
        __builtin_memcpy(des,first_part,first_part_len);
    }
	register size_t last=first_part_len;
	va_start(args,first_part_len);
	for(register int i=1;i<path_cnt;++i){
		register const wchar_t*const cur_part=va_arg(args,const wchar_t*const);
		register const size_t cur_part_len=va_arg(args,const size_t);
		des[last++]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
		__builtin_memcpy(des+last,cur_part,cur_part_len);
		last+=cur_part_len;
	}
	va_end(args);
	if(res<=des_len) des[res]=L'\0';
	return res;
}

size_t shinsei_linuxPathJoinA(char*const restrict des,const size_t des_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...){
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(!!des_len,1)) *des='\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		// SBO path
		const char* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args;
		va_start(args,first_part_len);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args,const char*);
			part_len[i]=va_arg(args,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args);
		if(res>des_len) return res;
		register size_t last=first_part_len;
        if(des!=first_part){
            __builtin_memcpy(des,part[0],part_len[0]);
        }
        for(register int i=1;i<path_cnt;++i){
            des[last++]=SHINSEI_PATH_UNIX_DELIMITER_A;
            __builtin_memcpy(des+last,part[i],part_len[i]);
            last+=part_len[i];
        }
		des[res]='\0';
		return res;
	}
	if(des_len>=SHINSEI_PATH_WINDOWS_MAX||des_len<=SHINSEI_PATH_MINIMAL){
		// Minimal or overkill path
		if(des!=first_part&&res<des_len) __builtin_memcpy(des,first_part,first_part_len);
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args;
		va_start(args,first_part_len);
		for(register int i=1;i<path_cnt;++i){
			register const char*const cur_part=va_arg(args,const char*const);
			register const size_t cur_part_len=va_arg(args,const size_t);
			res+=cur_part_len+1;
			if(res<=des_len){
				des[last++]=SHINSEI_PATH_UNIX_DELIMITER_A;
				__builtin_memcpy(des+last,cur_part,cur_part_len);
			}
			last=res;
		}
		va_end(args);
		if(res<=des_len) des[res]='\0';
		return res;
	}
	// Normal path
	va_list args;
	va_start(args,first_part_len);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args,const char*const);
		res+=va_arg(args,const size_t)+1;
	}
	va_end(args);
	if(res>des_len) return res;
	if(des!=first_part){
        __builtin_memcpy(des,first_part,first_part_len);
    }
	register size_t last=first_part_len;
	va_start(args,first_part_len);
	for(register int i=1;i<path_cnt;++i){
		register const char*const cur_part=va_arg(args,const char*const);
		register const size_t cur_part_len=va_arg(args,const size_t);
		des[last++]=SHINSEI_PATH_UNIX_DELIMITER_A;
		__builtin_memcpy(des+last,cur_part,cur_part_len);
		last+=cur_part_len;
	}
	va_end(args);
	if(res<=des_len) des[res]='\0';
	return res;
}
size_t shinsei_linuxPathJoinW(wchar_t*const restrict des,const size_t des_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...){
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(!!des_len,1)) *des=L'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des==first_part,0)) return first_part_len;
	register size_t res=first_part_len;
	if(path_cnt<=(int)SHINSEI_PATH_SBO_CNT){
		// SBO path
		const wchar_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args;
		va_start(args,first_part_len);
		for(register int i=1;i<path_cnt;++i){
			part[i]=va_arg(args,const wchar_t*);
			part_len[i]=va_arg(args,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args);
		if(res>des_len) return res;
		register size_t last=first_part_len;
        if(des!=first_part){
            __builtin_memcpy(des,part[0],part_len[0]);
        }
        for(register int i=1;i<path_cnt;++i){
            des[last++]=SHINSEI_PATH_UNIX_DELIMITER_W;
            __builtin_memcpy(des+last,part[i],part_len[i]);
            last+=part_len[i];
        }
		des[res]=L'\0';
		return res;
	}
	if(des_len>=SHINSEI_PATH_WINDOWS_MAX||des_len<=SHINSEI_PATH_MINIMAL){
		// Minimal or overkill path
		if(des!=first_part&&res<des_len) __builtin_memcpy(des,first_part,first_part_len);
		if(__builtin_expect(path_cnt==1,0)) return res;
		register size_t last=res;
		va_list args;
		va_start(args,first_part_len);
		for(register int i=1;i<path_cnt;++i){
			register const wchar_t*const cur_part=va_arg(args,const wchar_t*const);
			register const size_t cur_part_len=va_arg(args,const size_t);
			res+=cur_part_len+1;
			if(res<=des_len){
				des[last++]=SHINSEI_PATH_UNIX_DELIMITER_W;
				__builtin_memcpy(des+last,cur_part,cur_part_len);
			}
			last=res;
		}
		va_end(args);
		if(res<=des_len) des[res]=L'\0';
		return res;
	}
	// Normal path
	va_list args;
	va_start(args,first_part_len);
	for(register int i=1;i<path_cnt;++i){
		(void)va_arg(args,const wchar_t*const);
		res+=va_arg(args,const size_t)+1;
	}
	va_end(args);
	if(res>des_len) return res;
	if(des!=first_part){
        __builtin_memcpy(des,first_part,first_part_len);
    }
	register size_t last=first_part_len;
	va_start(args,first_part_len);
	for(register int i=1;i<path_cnt;++i){
		register const wchar_t*const cur_part=va_arg(args,const wchar_t*const);
		register const size_t cur_part_len=va_arg(args,const size_t);
		des[last++]=SHINSEI_PATH_UNIX_DELIMITER_W;
		__builtin_memcpy(des+last,cur_part,cur_part_len);
		last+=cur_part_len;
	}
	va_end(args);
	if(res<=des_len) des[res]=L'\0';
	return res;
}

inline static size_t splitHashToPathA(char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt,const char delimiter){
	if(__builtin_expect(!src_len,0)){
		if(__builtin_expect(des!=nullptr,1)) *des='\0';
		return 0;
	}
	const size_t res=(src_len/folder_len>max_folder_cnt?max_folder_cnt:src_len/folder_len)+src_len;
	if(__builtin_expect(des_len<res,0)) return res;
	size_t now=0;
	size_t cnt=0;
	for(size_t i=0;i<src_len;++i){
		des[now++]=src[i];
		if(cnt<max_folder_cnt&&!((i+1)%folder_len)){
			des[now++]=delimiter;
			++cnt;
		}
	}
	if(des[now-1]==delimiter) --now;
	des[now]=0;
	return res;
}
inline static size_t splitHashToPathW(wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt,const wchar_t delimiter){
	if(__builtin_expect(!src_len,0)){
		if(__builtin_expect(des!=nullptr,1)) *des=L'\0';
		return 0;
	}
	const size_t res=(src_len/folder_len>max_folder_cnt?max_folder_cnt:src_len/folder_len)+src_len;
	if(__builtin_expect(des_len<res,0)) return res;
	size_t now=0;
	size_t cnt=0;
	for(size_t i=0;i<src_len;++i){
		des[now++]=src[i];
		if(cnt<max_folder_cnt&&!((i+1)%folder_len)){
			des[now++]=delimiter;
			++cnt;
		}
	}
	if(des[now-1]==delimiter) --now;
	des[now]=0;
	return res;
}

size_t shinsei_splitStrToWindowsPathA(char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	return splitHashToPathA(des,des_len,src,src_len,folder_len,max_folder_cnt,'\\');
}
size_t shinsei_splitStrToWindowsPathW(wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	return splitHashToPathW(des,des_len,src,src_len,folder_len,max_folder_cnt,L'\\');
}

size_t shinsei_splitStrToLinuxPathA(char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	return splitHashToPathA(des,des_len,src,src_len,folder_len,max_folder_cnt,'/');
}
size_t shinsei_splitStrToLinuxPathW(wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	return splitHashToPathW(des,des_len,src,src_len,folder_len,max_folder_cnt,L'/');
}
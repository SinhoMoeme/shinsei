#include"shinsei/minimal/path.h"

bool shinsei_isWindowsPathDelimiterA(const int ch){
	return (ch|0x20)=='/';
}
bool shinsei_isWindowsPathDelimiterW(const wint_t ch){
	return (ch|0x20)==L'/';
}
bool shinsei_isWindowsPathDelimiterU8S(const char8_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register int size=shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr[-1]|0x20)==u8'/';
}
bool shinsei_isWindowsPathDelimiterU16S(const char16_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register int size=shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return (*str_ptr[-1]|0x20)==u'/';
}
bool shinsei_isWindowsPathDelimiterU32(const char32_t ch){
	return (ch|0x20)==U'/';
}

bool shinsei_isLinuxPathDelimiterA(const int ch){
	return ch=='/';
}
bool shinsei_isLinuxPathDelimiterW(const wint_t ch){
	return ch==L'/';
}
bool shinsei_isLinuxPathDelimiterU8S(const char8_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register int size=shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]==u8'/';
}
bool shinsei_isLinuxPathDelimiterU16S(const char16_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return false;
	register int size=shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return false;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]==u'/';
}
bool shinsei_isLinuxPathDelimiterU32(const char32_t ch){
	return ch==U'/';
}

bool shinsei_isWindowsPathIllegalCharA(const int ch){
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
bool shinsei_isWindowsPathIllegalCharW(const wint_t ch){
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

bool shinsei_isLinuxPathIllegalCharA(const int ch){
	return !ch||ch==SHINSEI_PATH_LINUX_DELIMITER_A;
}
bool shinsei_isLinuxPathIllegalCharW(const wint_t ch){
	return !ch||ch==SHINSEI_PATH_LINUX_DELIMITER_W;
}
bool shinsei_isLinuxPathIllegalCharU8(const char8_t ch){
	return !ch||ch==SHINSEI_PATH_LINUX_DELIMITER_U8;
}
bool shinsei_isLinuxPathIllegalCharU16(const char16_t ch){
	return !ch||ch==SHINSEI_PATH_LINUX_DELIMITER_U8;
}
bool shinsei_isLinuxPathIllegalCharU32(const char32_t ch){
	return !ch||ch==SHINSEI_PATH_LINUX_DELIMITER_U8;
}

int shinsei_windowsPathNormalizeA(char*const restrict path,size_t*const restrict len){
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register bool can_traverse=false;
	register bool device_path=false;
	register int res;
	char* ptr;
	size_t cnt=*len;
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
				// Entended UNC path "\\?\UNC\server\share\xxx"
				if(path[2]=='?'&&*len>=8&&(path[4]=='U'||path[4]=='u')&&(path[5]=='N'||path[5]=='n')&&(path[6]=='C'||path[6]=='c')&&shinsei_isWindowsPathDelimiterA(path[7])){
					path[4]='U';
					path[5]='N';
					path[6]='C';
					path[7]=SHINSEI_PATH_WINDOWS_DELIMITER_A;
					size_t i=8;
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
				size_t i=2;
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
			path[0]=shinsei_toUpperA(path[0]);
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
	size_t front=0;
	size_t back=0;
	size_t r=0;
	size_t w=0;
	while(r<cnt){
		// Unify delimiter
		if(shinsei_isWindowsPathDelimiterA(ptr[r])){
			ptr[w++]=SHINSEI_PATH_WINDOWS_DELIMITER_A;
			// Collapse multiple delimiters
			while(++r<cnt&&shinsei_isWindowsPathDelimiterA(ptr[r]));
			continue;
		}
		size_t seg_start=w;
		while(r<cnt&&!shinsei_isWindowsPathDelimiterA(ptr[r])){
			if(!device_path&&__builtin_expect(shinsei_isWindowsPathIllegalCharA(ptr[r]),0)) return SHINSEI_PATH_ILLEGAL;
			ptr[w++]=ptr[r++];
		}
		size_t seg_len=w-seg_start;
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
	*len=(ptr-path)+w;
	path[*len]='\0';
	return res;
}
int shinsei_windowsPathNormalizeW(wchar_t*const restrict path,size_t*const restrict len){
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register bool can_traverse=false;
	register bool device_path=false;
	register int res;
	wchar_t* ptr;
	size_t cnt=*len;
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
				// Entended UNC path "\\?\UNC\server\share\xxx"
				if(path[2]==L'?'&&*len>=8&&(path[4]==L'U'||path[4]==L'u')&&(path[5]==L'N'||path[5]==L'n')&&(path[6]==L'C'||path[6]==L'c')&&shinsei_isWindowsPathDelimiterW(path[7])){
					path[4]=L'U';
					path[5]=L'N';
					path[6]=L'C';
					path[7]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
					size_t i=8;
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
				size_t i=2;
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
	size_t front=0;
	size_t back=0;
	size_t r=0;
	size_t w=0;
	while(r<cnt){
		// Unify delimiter
		if(shinsei_isWindowsPathDelimiterW(ptr[r])){
			ptr[w++]=SHINSEI_PATH_WINDOWS_DELIMITER_W;
			// Collapse multiple delimiters
			while(++r<cnt&&shinsei_isWindowsPathDelimiterW(ptr[r]));
			continue;
		}
		size_t seg_start=w;
		while(r<cnt&&!shinsei_isWindowsPathDelimiterW(ptr[r])){
			if(!device_path&&__builtin_expect(shinsei_isWindowsPathIllegalCharW(ptr[r]),0)) return SHINSEI_PATH_ILLEGAL;
			ptr[w++]=ptr[r++];
		}
		size_t seg_len=w-seg_start;
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
	*len=(ptr-path)+w;
	path[*len]=L'\0';
	return res;
}

int shinsei_linuxPathNormalizeA(char* path,size_t* len){
	return 0;
}
int shinsei_linuxPathNormalizeW(wchar_t* path,size_t* len){
	return 0;
}

size_t shinsei_windowsPathJoinA(char*const restrict des,const size_t des_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...){
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_len,1)) *des='\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des==first_part,0)) return first_part_len;
	size_t res=first_part_len;
	if(path_cnt<=SHINSEI_PATH_SBO_CNT){
		// SBO path
		const char* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args;
		va_start(args,first_part_len);
		for(size_t i=1;i<path_cnt;++i){
			part[i]=va_arg(args,const char*);
			part_len[i]=va_arg(args,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args);
		if(res>des_len) return res;
		size_t last=first_part_len;
        if(des!=first_part){
            __builtin_memcpy(des,part[0],part_len[0]);
        }
        for(size_t i=1;i<path_cnt;++i){
            des[last++]='\\';
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
		size_t last=res;
		va_list args;
		va_start(args,first_part_len);
		for(size_t i=1;i<path_cnt;++i){
			const char*const cur_part=va_arg(args,const char*const);
			const size_t cur_part_len=va_arg(args,const size_t);
			res+=cur_part_len+1;
			if(res<=des_len){
				des[last++]='\\';
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
	for(size_t i=1;i<path_cnt;++i){
		(void)va_arg(args,const char*const);
		res+=va_arg(args,const size_t)+1;
	}
	va_end(args);
	if(res>des_len) return res;
	if(des!=first_part){
        __builtin_memcpy(des,first_part,first_part_len);
    }
	size_t last=first_part_len;
	va_start(args,first_part_len);
	for(size_t i=1;i<path_cnt;++i){
		const char*const cur_part=va_arg(args,const char*const);
		const size_t cur_part_len=va_arg(args,const size_t);
		des[last++]='\\';
		__builtin_memcpy(des+last,cur_part,cur_part_len);
		last+=cur_part_len;
	}
	va_end(args);
	if(res<=des_len) des[res]='\0';
	return res;
}
size_t shinsei_windowsPathJoinW(wchar_t*const restrict des,const size_t des_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...){
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_len,1)) *des=L'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des==first_part,0)) return first_part_len;
	size_t res=first_part_len;
	if(path_cnt<=SHINSEI_PATH_SBO_CNT){
		// SBO path
		const wchar_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args;
		va_start(args,first_part_len);
		for(size_t i=1;i<path_cnt;++i){
			part[i]=va_arg(args,const wchar_t*);
			part_len[i]=va_arg(args,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args);
		if(res>des_len) return res;
		size_t last=first_part_len;
        if(des!=first_part){
            __builtin_memcpy(des,part[0],part_len[0]);
        }
        for(size_t i=1;i<path_cnt;++i){
            des[last++]=L'\\';
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
		size_t last=res;
		va_list args;
		va_start(args,first_part_len);
		for(size_t i=1;i<path_cnt;++i){
			const wchar_t*const cur_part=va_arg(args,const wchar_t*const);
			const size_t cur_part_len=va_arg(args,const size_t);
			res+=cur_part_len+1;
			if(res<=des_len){
				des[last++]=L'\\';
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
	for(size_t i=1;i<path_cnt;++i){
		(void)va_arg(args,const wchar_t*const);
		res+=va_arg(args,const size_t)+1;
	}
	va_end(args);
	if(res>des_len) return res;
	if(des!=first_part){
        __builtin_memcpy(des,first_part,first_part_len);
    }
	size_t last=first_part_len;
	va_start(args,first_part_len);
	for(size_t i=1;i<path_cnt;++i){
		const wchar_t*const cur_part=va_arg(args,const wchar_t*const);
		const size_t cur_part_len=va_arg(args,const size_t);
		des[last++]=L'\\';
		__builtin_memcpy(des+last,cur_part,cur_part_len);
		last+=cur_part_len;
	}
	va_end(args);
	if(res<=des_len) des[res]=L'\0';
	return res;
}

size_t shinsei_linuxPathJoinA(char*const restrict des,const size_t des_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...){
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_len,1)) *des='\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des==first_part,0)) return first_part_len;
	size_t res=first_part_len;
	if(path_cnt<=SHINSEI_PATH_SBO_CNT){
		// SBO path
		const char* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args;
		va_start(args,first_part_len);
		for(size_t i=1;i<path_cnt;++i){
			part[i]=va_arg(args,const char*);
			part_len[i]=va_arg(args,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args);
		if(res>des_len) return res;
		size_t last=first_part_len;
        if(des!=first_part){
            __builtin_memcpy(des,part[0],part_len[0]);
        }
        for(size_t i=1;i<path_cnt;++i){
            des[last++]='/';
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
		size_t last=res;
		va_list args;
		va_start(args,first_part_len);
		for(size_t i=1;i<path_cnt;++i){
			const char*const cur_part=va_arg(args,const char*const);
			const size_t cur_part_len=va_arg(args,const size_t);
			res+=cur_part_len+1;
			if(res<=des_len){
				des[last++]='/';
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
	for(size_t i=1;i<path_cnt;++i){
		(void)va_arg(args,const char*const);
		res+=va_arg(args,const size_t)+1;
	}
	va_end(args);
	if(res>des_len) return res;
	if(des!=first_part){
        __builtin_memcpy(des,first_part,first_part_len);
    }
	size_t last=first_part_len;
	va_start(args,first_part_len);
	for(size_t i=1;i<path_cnt;++i){
		const char*const cur_part=va_arg(args,const char*const);
		const size_t cur_part_len=va_arg(args,const size_t);
		des[last++]='/';
		__builtin_memcpy(des+last,cur_part,cur_part_len);
		last+=cur_part_len;
	}
	va_end(args);
	if(res<=des_len) des[res]='\0';
	return res;
}
size_t shinsei_linuxPathJoinW(wchar_t*const restrict des,const size_t des_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...){
	if(__builtin_expect(path_cnt<=0||(path_cnt==1&&!first_part_len),0)){
		if(__builtin_expect(des_len,1)) *des=L'\0';
		return 0;
	}
	if(__builtin_expect(path_cnt==1&&des==first_part,0)) return first_part_len;
	size_t res=first_part_len;
	if(path_cnt<=SHINSEI_PATH_SBO_CNT){
		// SBO path
		const wchar_t* part[SHINSEI_PATH_SBO_CNT];
		size_t part_len[SHINSEI_PATH_SBO_CNT];
		part[0]=first_part;
		part_len[0]=first_part_len;
		va_list args;
		va_start(args,first_part_len);
		for(size_t i=1;i<path_cnt;++i){
			part[i]=va_arg(args,const wchar_t*);
			part_len[i]=va_arg(args,const size_t);
			res+=part_len[i]+1;
		}
		va_end(args);
		if(res>des_len) return res;
		size_t last=first_part_len;
        if(des!=first_part){
            __builtin_memcpy(des,part[0],part_len[0]);
        }
        for(size_t i=1;i<path_cnt;++i){
            des[last++]=L'/';
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
		size_t last=res;
		va_list args;
		va_start(args,first_part_len);
		for(size_t i=1;i<path_cnt;++i){
			const wchar_t*const cur_part=va_arg(args,const wchar_t*const);
			const size_t cur_part_len=va_arg(args,const size_t);
			res+=cur_part_len+1;
			if(res<=des_len){
				des[last++]=L'/';
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
	for(size_t i=1;i<path_cnt;++i){
		(void)va_arg(args,const wchar_t*const);
		res+=va_arg(args,const size_t)+1;
	}
	va_end(args);
	if(res>des_len) return res;
	if(des!=first_part){
        __builtin_memcpy(des,first_part,first_part_len);
    }
	size_t last=first_part_len;
	va_start(args,first_part_len);
	for(size_t i=1;i<path_cnt;++i){
		const wchar_t*const cur_part=va_arg(args,const wchar_t*const);
		const size_t cur_part_len=va_arg(args,const size_t);
		des[last++]=L'/';
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

size_t shinsei_splitHashToWindowsPathA(char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	return splitHashToPathA(des,des_len,src,src_len,folder_len,max_folder_cnt,'\\');
}
size_t shinsei_splitHashToWindowsPathW(wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	return splitHashToPathW(des,des_len,src,src_len,folder_len,max_folder_cnt,L'\\');
}

size_t shinsei_splitHashToLinuxPathA(char*const restrict des,const size_t des_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	return splitHashToPathA(des,des_len,src,src_len,folder_len,max_folder_cnt,'/');
}
size_t shinsei_splitHashToLinuxPathW(wchar_t*const restrict des,const size_t des_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	return splitHashToPathW(des,des_len,src,src_len,folder_len,max_folder_cnt,L'/');
}
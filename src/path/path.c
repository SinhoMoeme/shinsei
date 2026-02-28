#include"shinsei/minimal/path.h"

bool shinsei_isWindowsPathDelimiterA(const char ch){
	return ch=='\\'||ch=='/';
}
bool shinsei_isWindowsPathDelimiterW(const wchar_t ch){
	return ch==L'\\'||ch==L'/';
}
bool shinsei_isWindowsPathDelimiterU8(const unsigned char**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]==u8'\\'||*str_ptr[-1]==u8'/';
}
bool shinsei_isWindowsPathDelimiterU16(const char16_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]==u'\\'||*str_ptr[-1]==u'/';
}
bool shinsei_isWindowsPathDelimiterU32(const char32_t ch){
	return ch==U'\\'||ch==U'/';
}

bool shinsei_isLinuxPathDelimiterA(const char ch){
	return ch=='/';
}
bool shinsei_isLinuxPathDelimiterW(const wchar_t ch){
	return ch==L'/';
}
bool shinsei_isLinuxPathDelimiterU8(const unsigned char**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf8CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]==u8'/';
}
bool shinsei_isLinuxPathDelimiterU16(const char16_t**const restrict str_ptr,const size_t len){
	if(__builtin_expect(!len,0)) return 0;
	register int size=shinsei_utf16CharSize(**str_ptr);
	if(__builtin_expect(len<size,0)) return 0;
	*str_ptr+=size;
	if(size>1) return false;
	return *str_ptr[-1]==u'/';
}
bool shinsei_isLinuxPathDelimiterU32(const char32_t ch){
	return ch==U'/';
}

int shinsei_windowsPathStandardizeA(char* path,size_t* len){
	if(__builtin_expect(!*len,0)) return SHINSEI_PATH_ILLEGAL;
	register int res;
	if(isalpha(*path)){
		if(*len>=2&&path[1]==':') res=SHINSEI_PATH_ABSOLUTE;
		else{
			if(*len<2) return 0;
		}
		return res;
	}
	return res;
}
int shinsei_windowsPathStandardizeW(wchar_t* path,size_t* len){
	return 0;
}

int shinsei_linuxPathStandardizeA(char* path,size_t* len){
	return 0;
}
int shinsei_linuxPathStandardizeW(wchar_t* path,size_t* len){
	return 0;
}

void shinsei_windowsPathJoinA(char* buf,const size_t buf_len,int part_cnt,const char* first_part,const size_t first_part_len,...){
	return;
}
void shinsei_windowsPathJoinW(wchar_t* buf,size_t buf_len,int path_cnt,const wchar_t* first_part,const size_t first_part_len,...){
	return;
}
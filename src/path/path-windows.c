#include"shinsei/path.h"

inline static shinsei_object_t* getKnownPathN(const REFKNOWNFOLDERID rfid){
	wchar_t* tmp=nullptr;
	register const int_fast32_t h_res=SHGetKnownFolderPath(rfid,0,nullptr,&tmp);
	if(__builtin_expect(h_res!=S_OK,0)){
		if(tmp!=nullptr) CoTaskMemFree(tmp);
		return nullptr;
	}
	return shinsei_object_t_con(tmp,CoTaskMemFree);
}
inline static size_t getKnownPathW(const REFKNOWNFOLDERID rfid,wchar_t *const buf,const size_t buf_len){
	wchar_t* tmp=nullptr;
	register const int_fast32_t h_res=SHGetKnownFolderPath(rfid,0,nullptr,&tmp);
	if(__builtin_expect(h_res!=S_OK,0)){
		if(tmp!=nullptr) CoTaskMemFree(tmp);
		return 0;
	}
	register const size_t len=wcslen(tmp);
	if(__builtin_expect(len>buf_len,0)) return len;
	__builtin_memcpy(buf,tmp,(len+1)*sizeof(wchar_t));
	CoTaskMemFree(tmp);
	return len;
}
inline static wchar_t* getKnownPathWB(const REFKNOWNFOLDERID rfid){
	wchar_t* tmp=nullptr;
	register const int_fast32_t h_res=SHGetKnownFolderPath(rfid,0,nullptr,&tmp);
	if(__builtin_expect(h_res!=S_OK,0)){
		if(tmp!=nullptr) CoTaskMemFree(tmp);
		return nullptr;
	}
	register const size_t len=wcslen(tmp);
	register wchar_t*const buf=(wchar_t*)malloc(sizeof(wchar_t)*(len+1));
	if(__builtin_expect(buf==nullptr,0)){
		CoTaskMemFree(tmp);
		return nullptr;
	}
	__builtin_memcpy(buf,tmp,(len+1)*sizeof(wchar_t));
	CoTaskMemFree(tmp);
	return buf;
}
inline static size_t getKnownPathU8(const REFKNOWNFOLDERID rfid,char8_t *const buf,const size_t buf_len){
	register wchar_t*const tmp=getKnownPathWB(rfid);
	if(__builtin_expect(tmp==nullptr,0)) return 0;
	register const size_t wlen=wcslen(tmp);
	register const size_t len=shinsei_utf16ToUtf8(buf,buf_len,(char16_t*)tmp,wlen);
	free(tmp);
	return len;
}
inline static char8_t* getKnownPathU8B(const REFKNOWNFOLDERID rfid){
	register wchar_t*const tmp=getKnownPathWB(rfid);
	if(__builtin_expect(tmp==nullptr,0)) return nullptr;
	register const size_t wlen=wcslen(tmp);
	register char8_t*const buf=shinsei_utf16ToUtf8B((char16_t*)tmp,wlen);
	free(tmp);
	return buf;
}

shinsei_object_t* shinsei_getUserDataPathN(){
	return getKnownPathN(&FOLDERID_RoamingAppData);
}
size_t shinsei_getUserDataPathW(wchar_t *const buf,const size_t buf_len){
	return getKnownPathW(&FOLDERID_RoamingAppData,buf,buf_len);
}
wchar_t* shinsei_getUserDataPathWB(){
	return getKnownPathWB(&FOLDERID_RoamingAppData);
}
size_t shinsei_getUserDataPathU8(char8_t *const buf,const size_t buf_len){
	return getKnownPathU8(&FOLDERID_RoamingAppData,buf,buf_len);
}
char8_t* shinsei_getUserDataPathU8B(){
	return getKnownPathU8B(&FOLDERID_RoamingAppData);
}

shinsei_object_t* shinsei_getSystemDataPathN(){
	return getKnownPathN(&FOLDERID_ProgramData);
}
size_t shinsei_getSystemDataPathW(wchar_t *const buf,const size_t buf_len){
	return getKnownPathW(&FOLDERID_ProgramData,buf,buf_len);
}
wchar_t* shinsei_getSystemDataPathWB(){
	return getKnownPathWB(&FOLDERID_ProgramData);
}
size_t shinsei_getSystemDataPathU8(char8_t *const buf,const size_t buf_len){
	return getKnownPathU8(&FOLDERID_ProgramData,buf,buf_len);
}
unsigned char* shinsei_getSystemDataPathU8B(){
	return getKnownPathU8B(&FOLDERID_ProgramData);
}

void shinsei_freeUserDataPathN(shinsei_object_t *const path_obj){
	if(shinsei_object_t_isLegal(path_obj)) shinsei_object_t_dec(path_obj);
	return;
}
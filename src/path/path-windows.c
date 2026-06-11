#include"shinsei/path.h"

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

#ifdef _SHINSEI_OS_ATOMIC
	static struct _SHINSEI_OS_ALIGN_BYTE{
		volatile uint32_t code_page;
	}cur_mem={0};
#else
	static struct _SHINSEI_OS_ALIGN_BYTE{
		INIT_ONCE init_ansi;
		unsigned int code_page;
	}cur_mem={
		.init_ansi=INIT_ONCE_STATIC_INIT
	};
	
	static BOOL WINAPI initANSICallback(PINIT_ONCE init_once,PVOID para,PVOID* ptr_context){
		(void)init_once;
		(void)para;
		(void)ptr_context;
		cur_mem.code_page=GetACP();
		return TRUE;
	}
#endif

_SHINSEI_OS_INLINE static unsigned int systemCP(){
	#ifdef _SHINSEI_OS_ATOMIC
		register unsigned int cp=cur_mem.code_page;
		if(__builtin_expect(!cp,0)){
			register unsigned int new_cp=GetACP();
			#ifdef _SHINSEI_OS_MSVC
				register uint32_t prev=(uint32_t)_InterlockedCompareExchange((volatile long*)&cur_mem.code_page,(long)new_cp,0);
				cp=(unsigned int)prev+!prev*new_cp;
			#else
				uint32_t expected=0;
				__atomic_compare_exchange_n(&cur_mem.code_page,&expected,new_cp,0,__ATOMIC_ACQ_REL,__ATOMIC_RELAXED);
				cp=(unsigned int)expected+!expected*new_cp;
			#endif
		}
		return cp;
	#else
		InitOnceExecuteOnce(&cur_mem.init_ansi,initANSICallback,nullptr,nullptr);
		return (unsigned int)cur_mem.code_page;
	#endif
}

bool shinsei_isWindowsPathDelimiterA(const int ch){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathDelimiterCP(systemCP(),ch);
}
bool shinsei_isWindowsPathDelimiterAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathDelimiterCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isWindowsPathDelimiterN(const wint_t ch){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathDelimiterW(ch);
}
bool shinsei_isWindowsPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathDelimiterWM(str_ptr,len);
}

bool shinsei_isUnixPathDelimiterA(const int ch){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isUnixPathDelimiterCP(systemCP(),ch);
}
bool shinsei_isUnixPathDelimiterAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isUnixPathDelimiterCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isUnixPathDelimiterN(const wint_t ch){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isUnixPathDelimiterW(ch);
}
bool shinsei_isUnixPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isUnixPathDelimiterWM(str_ptr,len);
}

bool shinsei_isLinuxPathDelimiterA(const int ch){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isLinuxPathDelimiterCP(systemCP(),ch);
}
bool shinsei_isLinuxPathDelimiterAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isLinuxPathDelimiterCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isLinuxPathDelimiterN(const wint_t ch){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isLinuxPathDelimiterW(ch);
}
bool shinsei_isLinuxPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isLinuxPathDelimiterWM(str_ptr,len);
}

bool shinsei_isApplePathDelimiterA(const int ch){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isApplePathDelimiterCP(systemCP(),ch);
}
bool shinsei_isApplePathDelimiterAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isApplePathDelimiterCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isApplePathDelimiterN(const wint_t ch){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isApplePathDelimiterW(ch);
}
bool shinsei_isApplePathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isApplePathDelimiterWM(str_ptr,len);
}

bool shinsei_isSunPathDelimiterA(const int ch){
	return shinsei_isSunPathDelimiterCP(systemCP(),ch);
}
bool shinsei_isSunPathDelimiterAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isSunPathDelimiterCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isSunPathDelimiterN(const wint_t ch){
	return shinsei_isSunPathDelimiterW(ch);
}
bool shinsei_isSunPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isSunPathDelimiterWM(str_ptr,len);
}

bool shinsei_isFreeBSDPathDelimiterA(const int ch){
	return shinsei_isFreeBSDPathDelimiterCP(systemCP(),ch);
}
bool shinsei_isFreeBSDPathDelimiterAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isFreeBSDPathDelimiterCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isFreeBSDPathDelimiterN(const wint_t ch){
	return shinsei_isFreeBSDPathDelimiterW(ch);
}
bool shinsei_isFreeBSDPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isFreeBSDPathDelimiterWM(str_ptr,len);
}

bool shinsei_isCygwinPathDelimiterA(const int ch){
	return shinsei_isCygwinPathDelimiterCP(systemCP(),ch);
}
bool shinsei_isCygwinPathDelimiterAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isCygwinPathDelimiterCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isCygwinPathDelimiterN(const wint_t ch){
	return shinsei_isCygwinPathDelimiterW(ch);
}
bool shinsei_isCygwinPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isCygwinPathDelimiterWM(str_ptr,len);
}

bool shinsei_isNativePathDelimiterA(const int ch){
	return shinsei_isNativePathDelimiterCP(systemCP(),ch);
}
bool shinsei_isNativePathDelimiterAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isNativePathDelimiterCPM(systemCP(),str_ptr,len,NULL);
}
bool shinsei_isNativePathDelimiterW(const wint_t ch){
	return shinsei_isWindowsPathDelimiterW(ch);
}
bool shinsei_isNativePathDelimiterWM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathDelimiterWM(str_ptr,len);
}
bool shinsei_isNativePathDelimiterCP(const unsigned int code_page,const int ch){
	return shinsei_isWindowsPathDelimiterCP(code_page,ch);
}
bool shinsei_isNativePathDelimiterCPM(const unsigned int code_page,const char**const restrict str_ptr,const size_t len,int*const restrict status){
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	return shinsei_isWindowsPathDelimiterCPM(code_page,str_ptr,len,status);
}
bool shinsei_isNativePathDelimiterU8(const char8_t ch){
	return shinsei_isWindowsPathDelimiterU8(ch);
}
bool shinsei_isNativePathDelimiterU8M(const char8_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathDelimiterU8M(str_ptr,len);
}
bool shinsei_isNativePathDelimiterU16(const char16_t ch){
	return shinsei_isWindowsPathDelimiterU16(ch);
}
bool shinsei_isNativePathDelimiterU16M(const char16_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathDelimiterU16M(str_ptr,len);
}
bool shinsei_isNativePathDelimiterU32(const char32_t ch){
	return shinsei_isWindowsPathDelimiterU32(ch);
}
bool shinsei_isNativePathDelimiterU32M(const char32_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathDelimiterU32M(str_ptr,len);
}
bool shinsei_isNativePathDelimiterN(const wint_t ch){
	return shinsei_isNativePathDelimiterW(ch);
}
bool shinsei_isNativePathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isNativePathDelimiterWM(str_ptr,len);
}

bool shinsei_isURLPathDelimiterA(const int ch){
	return shinsei_isURLPathDelimiterCP(systemCP(),ch);
}
bool shinsei_isURLPathDelimiterAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isURLPathDelimiterCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isURLPathDelimiterN(const wint_t ch){
	return shinsei_isURLPathDelimiterW(ch);
}
bool shinsei_isURLPathDelimiterNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isURLPathDelimiterWM(str_ptr,len);
}

bool shinsei_isWindowsPathIllegalCharA(const int ch){
	return shinsei_isWindowsPathIllegalCharCP(systemCP(),ch);
}
bool shinsei_isWindowsPathIllegalCharAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathIllegalCharCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isWindowsPathIllegalCharN(const wint_t ch){
	return shinsei_isWindowsPathIllegalCharW(ch);
}
bool shinsei_isWindowsPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathIllegalCharWM(str_ptr,len);
}

bool shinsei_isUnixPathIllegalCharA(const int ch){
	return shinsei_isUnixPathIllegalCharCP(systemCP(),ch);
}
bool shinsei_isUnixPathIllegalCharAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isUnixPathIllegalCharCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isUnixPathIllegalCharN(const wint_t ch){
	return shinsei_isUnixPathIllegalCharW(ch);
}
bool shinsei_isUnixPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isUnixPathIllegalCharWM(str_ptr,len);
}

bool shinsei_isLinuxPathIllegalCharA(const int ch){
	return shinsei_isLinuxPathIllegalCharCP(systemCP(),ch);
}
bool shinsei_isLinuxPathIllegalCharAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isLinuxPathIllegalCharCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isLinuxPathIllegalCharN(const wint_t ch){
	return shinsei_isLinuxPathIllegalCharW(ch);
}
bool shinsei_isLinuxPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isLinuxPathIllegalCharWM(str_ptr,len);
}

bool shinsei_isApplePathIllegalCharA(const int ch){
	return shinsei_isApplePathIllegalCharCP(systemCP(),ch);
}
bool shinsei_isApplePathIllegalCharAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isApplePathIllegalCharCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isApplePathIllegalCharN(const wint_t ch){
	return shinsei_isApplePathIllegalCharW(ch);
}
bool shinsei_isApplePathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isApplePathIllegalCharWM(str_ptr,len);
}

bool shinsei_isSunPathIllegalCharA(const int ch){
	return shinsei_isSunPathIllegalCharCP(systemCP(),ch);
}
bool shinsei_isSunPathIllegalCharAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isSunPathIllegalCharCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isSunPathIllegalCharN(const wint_t ch){
	return shinsei_isSunPathIllegalCharW(ch);
}
bool shinsei_isSunPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isSunPathIllegalCharWM(str_ptr,len);
}

bool shinsei_isFreeBSDPathIllegalCharA(const int ch){
	return shinsei_isFreeBSDPathIllegalCharCP(systemCP(),ch);
}
bool shinsei_isFreeBSDPathIllegalCharAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isFreeBSDPathIllegalCharCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isFreeBSDPathIllegalCharN(const wint_t ch){
	return shinsei_isFreeBSDPathIllegalCharW(ch);
}
bool shinsei_isFreeBSDPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isFreeBSDPathIllegalCharWM(str_ptr,len);
}

bool shinsei_isCygwinPathIllegalCharA(const int ch){
	return shinsei_isCygwinPathIllegalCharCP(systemCP(),ch);
}
bool shinsei_isCygwinPathIllegalCharAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isCygwinPathIllegalCharCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isCygwinPathIllegalCharN(const wint_t ch){
	return shinsei_isCygwinPathIllegalCharW(ch);
}
bool shinsei_isCygwinPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isCygwinPathIllegalCharWM(str_ptr,len);
}

bool shinsei_isNativePathIllegalCharA(const int ch){
	return shinsei_isNativePathIllegalCharCP(systemCP(),ch);
}
bool shinsei_isNativePathIllegalCharAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isNativePathIllegalCharCPM(systemCP(),str_ptr,len,NULL);
}
bool shinsei_isNativePathIllegalCharW(const wint_t ch){
	return shinsei_isWindowsPathIllegalCharW(ch);
}
bool shinsei_isNativePathIllegalCharWM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathIllegalCharWM(str_ptr,len);
}
bool shinsei_isNativePathIllegalCharCP(const unsigned int code_page,const int ch){
	return shinsei_isWindowsPathIllegalCharCP(code_page,ch);
}
bool shinsei_isNativePathIllegalCharCPM(const unsigned int code_page,const char**const restrict str_ptr,const size_t len,int*const restrict status){
	// str_ptr: Pointer to the string pointer, advanced safely by the CP character byte size.
	// len: Remaining size of the string buffer in bytes. 0 or more.
	return shinsei_isWindowsPathIllegalCharCPM(code_page,str_ptr,len,status);
}
bool shinsei_isNativePathIllegalCharU8(const char8_t ch){
	return shinsei_isWindowsPathIllegalCharU8(ch);
}
bool shinsei_isNativePathIllegalCharU8M(const char8_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathIllegalCharU8M(str_ptr,len);
}
bool shinsei_isNativePathIllegalCharU16(const char16_t ch){
	return shinsei_isWindowsPathIllegalCharU16(ch);
}
bool shinsei_isNativePathIllegalCharU16M(const char16_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathIllegalCharU16M(str_ptr,len);
}
bool shinsei_isNativePathIllegalCharU32(const char32_t ch){
	return shinsei_isWindowsPathIllegalCharU32(ch);
}
bool shinsei_isNativePathIllegalCharU32M(const char32_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isWindowsPathIllegalCharU32M(str_ptr,len);
}
bool shinsei_isNativePathIllegalCharN(const wint_t ch){
	return shinsei_isNativePathIllegalCharW(ch);
}
bool shinsei_isNativePathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isNativePathIllegalCharWM(str_ptr,len);
}

bool shinsei_isURLPathIllegalCharA(const int ch){
	return shinsei_isURLPathIllegalCharCP(systemCP(),ch);
}
bool shinsei_isURLPathIllegalCharAM(const char**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isURLPathIllegalCharCPM(systemCP(),str_ptr,len,nullptr);
}
bool shinsei_isURLPathIllegalCharN(const wint_t ch){
	return shinsei_isURLPathIllegalCharW(ch);
}
bool shinsei_isURLPathIllegalCharNM(const wchar_t**const restrict str_ptr,const size_t len){
	// str_ptr: Pointer to the string pointer, advanced safely by the character unit size.
	// len: Remaining size of the string buffer in character units. 0 or more.
	return shinsei_isURLPathIllegalCharWM(str_ptr,len);
}

int shinsei_windowsPathNormalizeA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeCP(systemCP(),path,len);
}
int shinsei_windowsPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeW(path,len);
}

int shinsei_unixPathNormalizeA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_unixPathNormalizeCP(systemCP(),path,len);
}
int shinsei_unixPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_unixPathNormalizeW(path,len);
}

int shinsei_linuxPathNormalizeA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_linuxPathNormalizeCP(systemCP(),path,len);
}
int shinsei_linuxPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_linuxPathNormalizeW(path,len);
}

int shinsei_applePathNormalizeA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_applePathNormalizeCP(systemCP(),path,len);
}
int shinsei_applePathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_applePathNormalizeW(path,len);
}

int shinsei_sunPathNormalizeA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_sunPathNormalizeCP(systemCP(),path,len);
}
int shinsei_sunPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_sunPathNormalizeW(path,len);
}

int shinsei_freeBSDPathNormalizeA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_freeBSDPathNormalizeCP(systemCP(),path,len);
}
int shinsei_freeBSDPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_freeBSDPathNormalizeW(path,len);
}

int shinsei_cygwinPathNormalizeA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_cygwinPathNormalizeCP(systemCP(),path,len);
}
int shinsei_cygwinPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_cygwinPathNormalizeW(path,len);
}

int shinsei_nativePathNormalizeW(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeW(path,len);
}
int shinsei_nativePathNormalizeCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeCP(code_page,path,len);
}
int shinsei_nativePathNormalizeU8(char8_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeU8(path,len);
}
int shinsei_nativePathNormalizeU16(char16_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeU16(path,len);
}
int shinsei_nativePathNormalizeU32(char32_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeU32(path,len);
}
int shinsei_nativePathNormalizeA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_nativePathNormalizeCP(systemCP(),path,len);
}
int shinsei_nativePathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_nativePathNormalizeW(path,len);
}

int shinsei_uRLPathNormalizeA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_uRLPathNormalizeCP(systemCP(),path,len);
}
int shinsei_uRLPathNormalizeN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_uRLPathNormalizeW(path,len);
}

int shinsei_windowsPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeNoTraversalCP(systemCP(),path,len);
}
int shinsei_windowsPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeNoTraversalW(path,len);
}

int shinsei_unixPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_unixPathNormalizeNoTraversalCP(systemCP(),path,len);
}
int shinsei_unixPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_unixPathNormalizeNoTraversalW(path,len);
}

int shinsei_linuxPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_linuxPathNormalizeNoTraversalCP(systemCP(),path,len);
}
int shinsei_linuxPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_linuxPathNormalizeNoTraversalW(path,len);
}

int shinsei_applePathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_applePathNormalizeNoTraversalCP(systemCP(),path,len);
}
int shinsei_applePathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_applePathNormalizeNoTraversalW(path,len);
}

int shinsei_sunPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_sunPathNormalizeNoTraversalCP(systemCP(),path,len);
}
int shinsei_sunPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_sunPathNormalizeNoTraversalW(path,len);
}

int shinsei_freeBSDPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_freeBSDPathNormalizeNoTraversalCP(systemCP(),path,len);
}
int shinsei_freeBSDPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_freeBSDPathNormalizeNoTraversalW(path,len);
}

int shinsei_cygwinPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_cygwinPathNormalizeNoTraversalCP(systemCP(),path,len);
}
int shinsei_cygwinPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_cygwinPathNormalizeNoTraversalW(path,len);
}

_SHINSEI_OS_INLINE static int nativePathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeNoTraversalU16(path,len);
}
_SHINSEI_OS_INLINE static int nativePathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeNoTraversalU32(path,len);
}

int shinsei_nativePathNormalizeNoTraversalW(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeNoTraversalW(path,len);
}
int shinsei_nativePathNormalizeNoTraversalCP(const unsigned int code_page,char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeNoTraversalCP(code_page,path,len);
}
int shinsei_nativePathNormalizeNoTraversalU8(char8_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_windowsPathNormalizeNoTraversalU8(path,len);
}
int shinsei_nativePathNormalizeNoTraversalU16(char16_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return nativePathNormalizeNoTraversalU16(path,len);
}
int shinsei_nativePathNormalizeNoTraversalU32(char32_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return nativePathNormalizeNoTraversalU32(path,len);
}
int shinsei_nativePathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_nativePathNormalizeNoTraversalCP(systemCP(),path,len);
}
int shinsei_nativePathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_nativePathNormalizeNoTraversalW(path,len);
}

int shinsei_uRLPathNormalizeNoTraversalA(char*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_uRLPathNormalizeNoTraversalCP(systemCP(),path,len);
}
int shinsei_uRLPathNormalizeNoTraversalN(wchar_t*const restrict path,size_t*const restrict len){
	// path: Buffer containing the string to normalize. Modified in-place.
	// len: Pointer to the length of the string. Updated to the new length.
	return shinsei_uRLPathNormalizeNoTraversalW(path,len);
}

// Copy from str/str.c
_SHINSEI_OS_INLINE static int uTF32CharToUTF8Char(char8_t*const restrict des,const char32_t src){
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

// Copy from str/str.c
_SHINSEI_OS_INLINE static int uTF16CharToUTF32Char(char32_t*const restrict des,const char16_t*const restrict src,const size_t src_len){
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

// Rewrite from str/str.c
_SHINSEI_OS_INLINE static size_t uTF16ToUTF8(char8_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len){
	register size_t si=0;
	register size_t di=0;
	while(si<src_len){
		char32_t cp;
		register const size_t r=(size_t)uTF16CharToUTF32Char(&cp,src+si,src_len-si);
		if(__builtin_expect(!r,0)) return 0;
		si+=r;
		char8_t tmp[4];
		register const size_t w=(size_t)uTF32CharToUTF8Char(tmp,cp);
		if(di+w>=des_buf_len) return 0;
		for(register size_t i=0;i<w;++i) des_buf[di++]=tmp[i];
	}
	des_buf[di]=u8'\0';
	return di;
}

// Rewrite from str/str.c
_SHINSEI_OS_INLINE static size_t uTF16ToUTF32(char32_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len){
	register size_t si=0;
	register size_t di=0;
	while(si<src_len){
		char32_t cp;
		register const size_t r=(size_t)uTF16CharToUTF32Char(&cp,src+si,src_len-si);
		if(__builtin_expect(!r,0)) return 0;
		si+=r;
		if(di+1>=des_buf_len) return 0;
		des_buf[di++]=cp;
	}
	des_buf[di]=U'\0';
	return di;
}

_SHINSEI_OS_INLINE static size_t getUserDataPathW(wchar_t*const restrict des_buf,const size_t des_buf_len){
	if(__builtin_expect(des_buf_len<2,0)) return 0;
	register const DWORD res=GetEnvironmentVariableW(L"APPDATA",(LPWSTR)des_buf,(DWORD)des_buf_len);
	if(__builtin_expect(!res,0)) return 0;
	if(__builtin_expect(res>=des_buf_len,0)) return (size_t)res;
	return (size_t)res;
}
size_t shinsei_getUserDataPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,wchar_t*const restrict convert_buf,const size_t convert_buf_len){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// convert_buf_len: Size of the convert string + 1 for terminator 0.
	(void)convert_buf;
	(void)convert_buf_len;
	return getUserDataPathW(des_buf,des_buf_len);
}
size_t shinsei_getUserDataPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,wchar_t*const restrict convert_buf,const size_t convert_buf_len){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// convert_buf_len: Size of the convert string + 1 for terminator 0.
	if(__builtin_expect(des_buf_len<2,0)) return 0;
	register const size_t wlen=getUserDataPathW(convert_buf,convert_buf_len);
	if(!wlen) return 0;
	return uTF16ToUTF8(des_buf,des_buf_len,(const char16_t*)convert_buf,wlen);
}
size_t shinsei_getUserDataPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,wchar_t*const restrict convert_buf,const size_t convert_buf_len){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// convert_buf_len: Size of the convert string + 1 for terminator 0.
	#ifdef _SHINSEI_WCHAR_U32
		if(__builtin_expect(des_buf_len<2,0)) return 0;
		register const size_t wlen=getUserDataPathW(convert_buf,convert_buf_len);
		if(!wlen) return 0;
		return uTF32ToUTF16(des_buf,des_buf_len,(const char32_t*)convert_buf,wlen);
	#else
		(void)convert_buf;
		(void)convert_buf_len;
		return getUserDataPathW((wchar_t*)des_buf,des_buf_len);
	#endif
}
size_t shinsei_getUserDataPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,wchar_t*const restrict convert_buf,const size_t convert_buf_len){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// convert_buf_len: Size of the convert string + 1 for terminator 0.
	#ifdef _SHINSEI_WCHAR_U32
		(void)convert_buf;
		(void)convert_buf_len;
		return getUserDataPathW((wchar_t*)des_buf,des_buf_len);
	#else
		if(__builtin_expect(des_buf_len<2,0)) return 0;
		register const size_t wlen=getUserDataPathW(convert_buf,convert_buf_len);
		if(!wlen) return 0;
		return uTF16ToUTF32(des_buf,des_buf_len,(const char16_t*)convert_buf,wlen);
	#endif
}
size_t shinsei_getUserDataPathN(wchar_t*const restrict des_buf,const size_t des_buf_len){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	return getUserDataPathW(des_buf,des_buf_len);
}

_SHINSEI_OS_INLINE static size_t getSystemApplicationPathW(wchar_t*const restrict des_buf,const size_t des_buf_len){
	if(__builtin_expect(des_buf_len<2,0)) return 0;
	// Priority: ProgramW6432 (to get 64-bit path even in WoW64), then ProgramFiles
	register DWORD res=GetEnvironmentVariableW(L"ProgramW6432",(LPWSTR)des_buf,(DWORD)des_buf_len);
	if(!res){
		res=GetEnvironmentVariableW(L"ProgramFiles",(LPWSTR)des_buf,(DWORD)des_buf_len);
	}
	if(!res||res>=des_buf_len) return 0;
	return (const size_t)res;
}

size_t shinsei_getSystemApplicationPathW(wchar_t*const restrict des_buf,const size_t des_buf_len,wchar_t*const restrict convert_buf,const size_t convert_buf_len){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// convert_buf_len: Size of the convert string + 1 for terminator 0.
	(void)convert_buf;
	(void)convert_buf_len;
	return getSystemApplicationPathW(des_buf,des_buf_len);
}
size_t shinsei_getSystemApplicationPathU8(char8_t*const restrict des_buf,const size_t des_buf_len,wchar_t*const restrict convert_buf,const size_t convert_buf_len){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// convert_buf_len: Size of the convert string + 1 for terminator 0.
	if(__builtin_expect(des_buf_len<2,0)) return 0;
	register const size_t wlen=getSystemApplicationPathW(convert_buf,convert_buf_len);
	if(!wlen) return 0;
	#ifdef _SHINSEI_WCHAR_U32
		return uTF32ToUTF8(des_buf,des_buf_len,(const char32_t*)convert_buf,wlen);
	#else
		return uTF16ToUTF8(des_buf,des_buf_len,(const char16_t*)convert_buf,wlen);
	#endif
}
size_t shinsei_getSystemApplicationPathU16(char16_t*const restrict des_buf,const size_t des_buf_len,wchar_t*const restrict convert_buf,const size_t convert_buf_len){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// convert_buf_len: Size of the convert string + 1 for terminator 0.
	#ifdef _SHINSEI_WCHAR_U32
		if(__builtin_expect(des_buf_len<2,0)) return 0;
		register const size_t wlen=getSystemApplicationPathW(convert_buf,convert_buf_len);
		if(!wlen) return 0;
		return uTF32ToUTF16(des_buf,des_buf_len,(const char32_t*)convert_buf,wlen);
	#else
		(void)convert_buf;
		(void)convert_buf_len;
		return getSystemApplicationPathW((wchar_t*)des_buf,des_buf_len);
	#endif
}
size_t shinsei_getSystemApplicationPathU32(char32_t*const restrict des_buf,const size_t des_buf_len,wchar_t*const restrict convert_buf,const size_t convert_buf_len){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// convert_buf_len: Size of the convert string + 1 for terminator 0.
	#ifdef _SHINSEI_WCHAR_U32
		(void)convert_buf;
		(void)convert_buf_len;
		return getSystemApplicationPathW((wchar_t*)des_buf,des_buf_len);
	#else
		if(__builtin_expect(des_buf_len<2,0)) return 0;
		register const size_t wlen=getSystemApplicationPathW(convert_buf,convert_buf_len);
		if(!wlen) return 0;
		return uTF16ToUTF32(des_buf,des_buf_len,(const char16_t*)convert_buf,wlen);
	#endif
}
size_t shinsei_getSystemApplicationPathN(wchar_t*const restrict des_buf,const size_t des_buf_len){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	return getSystemApplicationPathW(des_buf,des_buf_len);
}

// Windows
size_t shinsei_windowsPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_windowsPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_windowsPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_windowsPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_windowsPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_windowsPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_windowsPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_windowsPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// Unix
size_t shinsei_unixPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_unixPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_unixPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_unixPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// Linux
size_t shinsei_linuxPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_linuxPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_linuxPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_linuxPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// Apple
size_t shinsei_applePathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_applePathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_applePathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_applePathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// Sun
size_t shinsei_sunPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_sunPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_sunPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_sunPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// FreeBSD
size_t shinsei_freeBSDPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_freeBSDPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_freeBSDPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_freeBSDPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// Cygwin
size_t shinsei_cygwinPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_cygwinPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_cygwinPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_cygwinPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

// URL
size_t shinsei_uRLPathJoinAV(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,va_list args){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_uRLPathJoinA(char*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const char*const restrict first_part,const size_t first_part_len,...){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinCPV(systemCP(),des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}
size_t shinsei_uRLPathJoinNV(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,va_list args){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	return shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
}
size_t shinsei_uRLPathJoinN(wchar_t*const restrict des_buf,const size_t des_buf_len,const int path_cnt,const wchar_t*const restrict first_part,const size_t first_part_len,...){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// first_part_len: The char count of the first part.
	va_list args;
	va_start(args,first_part_len);
	register const size_t res=shinsei_unixPathJoinWV(des_buf,des_buf_len,path_cnt,first_part,first_part_len,args);
	va_end(args);
	return res;
}

size_t shinsei_splitStringToWindowsPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToWindowsPathCP(systemCP(),des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToWindowsPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToWindowsPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}

size_t shinsei_splitStringToUnixPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToUnixPathCP(systemCP(),des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToUnixPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToUnixPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}

size_t shinsei_splitStringToLinuxPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToLinuxPathCP(systemCP(),des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToLinuxPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToLinuxPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}

size_t shinsei_splitStringToApplePathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToApplePathCP(systemCP(),des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToApplePathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToApplePathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}

size_t shinsei_splitStringToSunPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToSunPathCP(systemCP(),des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToSunPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToSunPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}

size_t shinsei_splitStringToFreeBSDPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToFreeBSDPathCP(systemCP(),des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToFreeBSDPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToFreeBSDPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}

size_t shinsei_splitStringToCygwinPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToCygwinPathCP(systemCP(),des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToCygwinPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToCygwinPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}

size_t shinsei_splitStringToURLPathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToURLPathCP(systemCP(),des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToURLPathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToURLPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}

size_t shinsei_splitStringToNativePathW(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToWindowsPathW(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToNativePathCP(const unsigned int code_page,char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToWindowsPathCP(code_page,des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToNativePathU8(char8_t*const restrict des_buf,const size_t des_buf_len,const char8_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToWindowsPathU8(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToNativePathU16(char16_t*const restrict des_buf,const size_t des_buf_len,const char16_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToWindowsPathU16(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToNativePathU32(char32_t*const restrict des_buf,const size_t des_buf_len,const char32_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToWindowsPathU32(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToNativePathA(char*const restrict des_buf,const size_t des_buf_len,const char*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToWindowsPathA(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}
size_t shinsei_splitStringToNativePathN(wchar_t*const restrict des_buf,const size_t des_buf_len,const wchar_t*const restrict src,const size_t src_len,const size_t folder_len,const size_t max_folder_cnt){
	// des_buf_len: Size of the destination string + 1 for terminator 0.
	// src_len: The char count of the source string.
	return shinsei_splitStringToWindowsPathN(des_buf,des_buf_len,src,src_len,folder_len,max_folder_cnt);
}

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif
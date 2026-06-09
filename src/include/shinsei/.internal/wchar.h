#include<wchar.h>

#if(defined(__SIZEOF_WCHAR_T__)&&(__SIZEOF_WCHAR_T__==4)||(WCHAR_MAX>0xFFFF))
    #define _SHINSEI_WCHAR_U32
#else
    #define _SHINSEI_WCHAR_U16
#endif
#include"shinsei/io.h"

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

// Copy from minimal/str.c
_SHINSEI_OS_INLINE static int uTF32CharToUTF16Char(char16_t*const restrict des,const char32_t src)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(src<0x10000,1)){
		des[0]=(char16_t)src;
		return 1;
	}
	register const char32_t res=src-0x10000;
	des[0]=(char16_t)((res>>10)+0xD800);
	des[1]=(char16_t)((res&0x3FF)+0xDC00);
	return 2;
}
// Copy from minimal/str.c
_SHINSEI_OS_INLINE static int uTF8CharToUTF32Char(char32_t*const restrict des,const char8_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
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
		*des=(((char32_t)(src[0]&0x0F)<<12)|((src[1]&0x3F)<<6)|(src[2]&0x3F));
		return 3;
	}
	if((src[0]&0xF8)==0xF0&&src_len>=4){
		*des=(((char32_t)(src[0]&0x07)<<18)|((src[1]&0x3F)<<12)|((src[2]&0x3F)<<6)|(src[3]&0x3F));
		return 4;
	}
	return 0;
}
// Copy from minimal/str.c
_SHINSEI_OS_INLINE static int uTF16CharToUTF32Char(char32_t*const restrict des,const char16_t*const restrict src,const size_t src_len)_SHINSEI_OS_NOEXCEPT{
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

#ifdef _SHINSEI_OS_ATOMIC
	static struct _SHINSEI_OS_ALIGN_BYTE{
		#ifdef _SHINSEI_OS_MSVC
			volatile long init_flag;
		#else
			volatile int_fast32_t init_flag;
		#endif
	}cur_mem={0};
#else
	static struct _SHINSEI_OS_ALIGN_BYTE{
		INIT_ONCE init_once;
	}cur_mem={
		INIT_ONCE_STATIC_INIT
	};
	static BOOL __stdcall initModeCallback(PINIT_ONCE init_once,void* para,void** ptr_context)_SHINSEI_OS_NOEXCEPT{
		(void)init_once;
		(void)para;
		(void)ptr_context;
		_setmode(_fileno(stdout),_O_U16TEXT);
		cur_mem.init_flag=true;
		return TRUE;
	}
#endif

// [Internal] Setup Console output
_SHINSEI_OS_INLINE static void initOutputMode()_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_OS_ATOMIC
		#ifdef _SHINSEI_OS_MSVC
			register const bool res=!_InterlockedExchange(&cur_mem.init_flag,1);
		#else
			register const bool res=!__atomic_exchange_n(&cur_mem.init_flag,1,__ATOMIC_ACQ_REL);
		#endif
		if(__builtin_expect(res,0)){ // Only initialize once
			_setmode(_fileno(stdout),_O_U16TEXT);
		}
	#else
		InitOnceExecuteOnce(&cur_mem.init_once,initModeCallback,nullptr,nullptr);
	#endif
	return;
}

// [Internal] Native Output
_SHINSEI_OS_INLINE static void printWNative(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	initOutputMode();
	register HANDLE hOut=GetStdHandle((DWORD)-11);
	DWORD mode;
	if(GetConsoleMode(hOut,&mode)){
		DWORD written=0;
		WriteConsoleW(hOut,str,(DWORD)len,&written,nullptr);
	}
	else{
		DWORD written=0;
		WriteFile(hOut,str,(DWORD)(len*sizeof(wchar_t)),&written,nullptr);
	}
	return;
}

// [Internal] Chunk Streamers
_SHINSEI_OS_INLINE static void printU8Native(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		wchar_t buf[SHINSEI_PRINT_BUFFER_SIZE_U32];
		register size_t si=0;
		while(si<len){
			register size_t di=0;
			while(si<len){
				char32_t cp;
				register const size_t r=(size_t)uTF8CharToUTF32Char(&cp,str+si,len-si);
				if(__builtin_expect(!r,0)){
					++si;
					continue;
				}
				if(di+1>SHINSEI_PRINT_BUFFER_SIZE_U32) break;
				buf[di++]=(wchar_t)cp;
				si+=r;
			}
			printWNative(buf,di);
		}
	#else
		wchar_t buf[SHINSEI_PRINT_BUFFER_SIZE_U16];
		register size_t si=0;
		while(si<len){
			register size_t di=0;
			while(si<len){
				char32_t cp;
				register const size_t r=(size_t)uTF8CharToUTF32Char(&cp,str+si,len-si);
				if(__builtin_expect(!r,0)){
					++si;
					continue;
				}
				char16_t tmp[2];
				register const size_t w=(size_t)uTF32CharToUTF16Char(tmp,cp);
				if(di+w>SHINSEI_PRINT_BUFFER_SIZE_U16) break;
				for(register size_t i=0;i<w;++i) buf[di++]=(wchar_t)tmp[i];
				si+=r;
			}
			printWNative(buf,di);
		}
	#endif
	return;
}

_SHINSEI_OS_INLINE static void printU32Native(const char32_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		printWNative((const wchar_t*)str,len);
	#else
		wchar_t buf[SHINSEI_PRINT_BUFFER_SIZE_U16];
		register size_t si=0;
		while(si<len){
			register size_t di=0;
			while(si<len){
				char16_t tmp[2];
				register const size_t w=(size_t)uTF32CharToUTF16Char(tmp,str[si]);
				if(__builtin_expect(!w,0)){
					++si;
					continue;
				}
				if(di+w>SHINSEI_PRINT_BUFFER_SIZE_U16) break;
				for(register size_t i=0;i<w;++i) buf[di++]=(wchar_t)tmp[i];
				++si;
			}
			printWNative(buf,di);
		}
	#endif
	return;
}

_SHINSEI_OS_INLINE static void printU16Native(const char16_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	#ifdef _SHINSEI_WCHAR_U32
		wchar_t buf[SHINSEI_PRINT_BUFFER_SIZE_U32];
		register size_t si=0;
		while(si<len){
			register size_t di=0;
			while(si<len){
				char32_t cp;
				register const size_t r=(size_t)uTF16CharToUTF32Char(&cp,str+si,len-si);
				if(__builtin_expect(!r,0)){
					++si;
					continue;
				}
				if(di+1>SHINSEI_PRINT_BUFFER_SIZE_U32) break;
				buf[di++]=(wchar_t)cp;
				si+=r;
			}
			printWNative(buf,di);
		}
	#else
		printWNative((const wchar_t*)str,len);
	#endif
	return;
}

// [Internal] Formatters (Decimal)
_SHINSEI_OS_INLINE static void printUInt64NativeDec(uint64_t val)_SHINSEI_OS_NOEXCEPT{
	wchar_t buf[SHINSEI_PRINT_BUFFER_SIZE_UINT64];
	register size_t i=SHINSEI_PRINT_BUFFER_SIZE_UINT64-1;
	if(!val) buf[i--]=L'0';
	else{
		while(val){
			buf[i--]=(wchar_t)(L'0'+(val%10));
			val/=10;
		}
	}
	printWNative(buf+i+1,(SHINSEI_PRINT_BUFFER_SIZE_UINT64-1)-i);
	return;
}

_SHINSEI_OS_INLINE static void printInt64NativeDec(int64_t val)_SHINSEI_OS_NOEXCEPT{
	if(val<0){
		const wchar_t minus=L'-';
		printWNative(&minus,1);
		printUInt64NativeDec((uint64_t)(-(uint64_t)val));
	}
	else printUInt64NativeDec((uint64_t)val);
	return;
}

// [Internal] Formatters (Binary)
_SHINSEI_OS_INLINE static void printUInt64NativeBin(uint64_t val)_SHINSEI_OS_NOEXCEPT{
	wchar_t buf[64];
	register size_t i=63;
	if(!val) buf[i--]=L'0';
	else{
		while(val){
			buf[i--]=(wchar_t)(L'0'+(val&1));
			val>>=1;
		}
	}
	printWNative(buf+i+1,63-i);
	return;
}

// [Internal] Formatters (Octal)
_SHINSEI_OS_INLINE static void printUInt64NativeOct(uint64_t val)_SHINSEI_OS_NOEXCEPT{
	wchar_t buf[24];
	register size_t i=23;
	if(!val) buf[i--]=L'0';
	else{
		while(val){
			buf[i--]=(wchar_t)(L'0'+(val&7));
			val>>=3;
		}
	}
	printWNative(buf+i+1,23-i);
	return;
}

// [Internal] Formatters (Hexadecimal)
_SHINSEI_OS_INLINE static void printUInt64NativeHex(uint64_t val)_SHINSEI_OS_NOEXCEPT{
	wchar_t buf[16];
	register size_t i=15;
	if(!val) buf[i--]=L'0';
	else{
		while(val){
			register const uint8_t rem=val&15;
			buf[i--]=(wchar_t)(rem<10?(L'0'+rem):(L'A'+rem-10));
			val>>=4;
		}
	}
	printWNative(buf+i+1,15-i);
	return;
}

// N APIs
void shinsei_putcharN(const wchar_t c)_SHINSEI_OS_NOEXCEPT{
	printWNative(&c,1);
	return;
}
void shinsei_printN(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	printWNative(str,len);
	return;
}
void shinsei_printLnN(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	printWNative(str,len);
	const wchar_t nl=L'\n';
	printWNative(&nl,1);
	return;
}

// Char APIs
void shinsei_putcharW(const wchar_t c)_SHINSEI_OS_NOEXCEPT{
	printWNative(&c,1);
	return;
}
void shinsei_putcharU8(const char8_t c)_SHINSEI_OS_NOEXCEPT{
	printU8Native(&c,1);
	return;
}
void shinsei_putcharU16(const char16_t c)_SHINSEI_OS_NOEXCEPT{
	printU16Native(&c,1);
	return;
}
void shinsei_putcharU32(const char32_t c)_SHINSEI_OS_NOEXCEPT{
	printU32Native(&c,1);
	return;
}

// Print APIs
void shinsei_printW(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	printWNative(str,len);
	return;
}
void shinsei_printU8(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	printU8Native(str,len);
	return;
}
void shinsei_printU16(const char16_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	printU16Native(str,len);
	return;
}
void shinsei_printU32(const char32_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	printU32Native(str,len);
	return;
}

// PrintLn APIs
void shinsei_printLnW(const wchar_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	printWNative(str,len);
	const wchar_t nl=L'\n';
	printWNative(&nl,1);
	return;
}
void shinsei_printLnU8(const char8_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	printU8Native(str,len);
	const wchar_t nl=L'\n';
	printWNative(&nl,1);
	return;
}
void shinsei_printLnU16(const char16_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	printU16Native(str,len);
	const wchar_t nl=L'\n';
	printWNative(&nl,1);
	return;
}
void shinsei_printLnU32(const char32_t*const restrict str,const size_t len)_SHINSEI_OS_NOEXCEPT{
	printU32Native(str,len);
	const wchar_t nl=L'\n';
	printWNative(&nl,1);
	return;
}

// Int8
void shinsei_printInt8(const int8_t val)_SHINSEI_OS_NOEXCEPT{
	printInt64NativeDec((int64_t)val);
	return;
}
void shinsei_printInt8Bin(const int8_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeBin((uint8_t)val);
	return;
}
void shinsei_printInt8Oct(const int8_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeOct((uint8_t)val);
	return;
}
void shinsei_printInt8Hex(const int8_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeHex((uint8_t)val);
	return;
}

// Int16
void shinsei_printInt16(const int16_t val)_SHINSEI_OS_NOEXCEPT{
	printInt64NativeDec((int64_t)val);
	return;
}
void shinsei_printInt16Bin(const int16_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeBin((uint16_t)val);
	return;
}
void shinsei_printInt16Oct(const int16_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeOct((uint16_t)val);
	return;
}
void shinsei_printInt16Hex(const int16_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeHex((uint16_t)val);
	return;
}

// Int32
void shinsei_printInt32(const int32_t val)_SHINSEI_OS_NOEXCEPT{
	printInt64NativeDec((int64_t)val);
	return;
}
void shinsei_printInt32Bin(const int32_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeBin((uint32_t)val);
	return;
}
void shinsei_printInt32Oct(const int32_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeOct((uint32_t)val);
	return;
}
void shinsei_printInt32Hex(const int32_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeHex((uint32_t)val);
	return;
}

// Int64
void shinsei_printInt64(const int64_t val)_SHINSEI_OS_NOEXCEPT{
	printInt64NativeDec((int64_t)val);
	return;
}
void shinsei_printInt64Bin(const int64_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeBin((uint64_t)val);
	return;
}
void shinsei_printInt64Oct(const int64_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeOct((uint64_t)val);
	return;
}
void shinsei_printInt64Hex(const int64_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeHex((uint64_t)val);
	return;
}

// UInt8
void shinsei_printUInt8(const uint8_t val)_SHINSEI_OS_NOEXCEPT{
	wchar_t buf[SHINSEI_PRINT_BUFFER_SIZE_UINT8];
	register size_t i=SHINSEI_PRINT_BUFFER_SIZE_UINT8-1;
	register uint8_t v=val;
	if(!v) buf[i--]=L'0';
	else{
		while(v){
			buf[i--]=(wchar_t)(L'0'+(v%10));
			v/=10;
		}
	}
	printWNative(buf+i+1,(SHINSEI_PRINT_BUFFER_SIZE_UINT8-1)-i);
	return;
}
void shinsei_printUInt8Bin(const uint8_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeBin((uint64_t)val);
	return;
}
void shinsei_printUInt8Oct(const uint8_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeOct((uint64_t)val);
	return;
}
void shinsei_printUInt8Hex(const uint8_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeHex((uint64_t)val);
	return;
}

// UInt16
void shinsei_printUInt16(const uint16_t val)_SHINSEI_OS_NOEXCEPT{
	wchar_t buf[SHINSEI_PRINT_BUFFER_SIZE_UINT16];
	register size_t i=SHINSEI_PRINT_BUFFER_SIZE_UINT16-1;
	register uint16_t v=val;
	if(!v) buf[i--]=L'0';
	else{
		while(v){
			buf[i--]=(wchar_t)(L'0'+(v%10));
			v/=10;
		}
	}
	printWNative(buf+i+1,(SHINSEI_PRINT_BUFFER_SIZE_UINT16-1)-i);
	return;
}
void shinsei_printUInt16Bin(const uint16_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeBin((uint64_t)val);
	return;
}
void shinsei_printUInt16Oct(const uint16_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeOct((uint64_t)val);
	return;
}
void shinsei_printUInt16Hex(const uint16_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeHex((uint64_t)val);
	return;
}

// UInt32
void shinsei_printUInt32(const uint32_t val)_SHINSEI_OS_NOEXCEPT{
	wchar_t buf[SHINSEI_PRINT_BUFFER_SIZE_UINT32];
	register size_t i=SHINSEI_PRINT_BUFFER_SIZE_UINT32-1;
	register uint32_t v=val;
	if(!v) buf[i--]=L'0';
	else{
		while(v){
			buf[i--]=(wchar_t)(L'0'+(v%10));
			v/=10;
		}
	}
	printWNative(buf+i+1,(SHINSEI_PRINT_BUFFER_SIZE_UINT32-1)-i);
	return;
}
void shinsei_printUInt32Bin(const uint32_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeBin((uint64_t)val);
	return;
}
void shinsei_printUInt32Oct(const uint32_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeOct((uint64_t)val);
	return;
}
void shinsei_printUInt32Hex(const uint32_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeHex((uint64_t)val);
	return;
}

// UInt64
void shinsei_printUInt64(const uint64_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeDec(val);
	return;
}
void shinsei_printUInt64Bin(const uint64_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeBin(val);
	return;
}
void shinsei_printUInt64Oct(const uint64_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeOct(val);
	return;
}
void shinsei_printUInt64Hex(const uint64_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeHex(val);
	return;
}

// Size
void shinsei_printSize(const size_t val)_SHINSEI_OS_NOEXCEPT{
	wchar_t buf[SHINSEI_PRINT_BUFFER_SIZE_SIZE];
	register size_t i=SHINSEI_PRINT_BUFFER_SIZE_SIZE-1;
	register size_t v=val;
	if(!v) buf[i--]=L'0';
	else{
		while(v){
			buf[i--]=(wchar_t)(L'0'+(v%10));
			v/=10;
		}
	}
	printWNative(buf+i+1,(SHINSEI_PRINT_BUFFER_SIZE_SIZE-1)-i);
	return;
}
void shinsei_printSizeBin(const size_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeBin((uint64_t)val);
	return;
}
void shinsei_printSizeOct(const size_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeOct((uint64_t)val);
	return;
}
void shinsei_printSizeHex(const size_t val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeHex((uint64_t)val);
	return;
}

// Ptr
void shinsei_printPtr(const void*const val)_SHINSEI_OS_NOEXCEPT{
	wchar_t buf[SHINSEI_PRINT_BUFFER_SIZE_PTR];
	register size_t i=SHINSEI_PRINT_BUFFER_SIZE_PTR-1;
	register uintptr_t v=(uintptr_t)val;
	if(!v) buf[i--]=L'0';
	else{
		while(v){
			buf[i--]=(wchar_t)(L'0'+(v%10));
			v/=10;
		}
	}
	printWNative(buf+i+1,(SHINSEI_PRINT_BUFFER_SIZE_PTR-1)-i);
	return;
}
void shinsei_printPtrBin(const void*const val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeBin((uint64_t)(uintptr_t)val);
	return;
}
void shinsei_printPtrOct(const void*const val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeOct((uint64_t)(uintptr_t)val);
	return;
}
void shinsei_printPtrHex(const void*const val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeHex((uint64_t)(uintptr_t)val);
	return;
}

// UPtr
void shinsei_printUPtr(const void*const val)_SHINSEI_OS_NOEXCEPT{
	wchar_t buf[SHINSEI_PRINT_BUFFER_SIZE_PTR];
	register size_t i=SHINSEI_PRINT_BUFFER_SIZE_PTR-1;
	register uintptr_t v=(uintptr_t)val;
	if(!v) buf[i--]=L'0';
	else{
		while(v){
			buf[i--]=(wchar_t)(L'0'+(v%10));
			v/=10;
		}
	}
	printWNative(buf+i+1,(SHINSEI_PRINT_BUFFER_SIZE_PTR-1)-i);
	return;
}
void shinsei_printUPtrBin(const void*const val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeBin((uint64_t)(uintptr_t)val);
	return;
}
void shinsei_printUPtrOct(const void*const val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeOct((uint64_t)(uintptr_t)val);
	return;
}
void shinsei_printUPtrHex(const void*const val)_SHINSEI_OS_NOEXCEPT{
	printUInt64NativeHex((uint64_t)(uintptr_t)val);
	return;
}

// Bool
void shinsei_printBool(const bool val)_SHINSEI_OS_NOEXCEPT{
	printWNative((const wchar_t*)(val*(uintptr_t)SHINSEI_TEXT_TRUE_W+(!val)*(uintptr_t)SHINSEI_TEXT_FALSE_W),val*SHINSEI_TEXT_TRUE_LEN+(!val)*SHINSEI_TEXT_FALSE_LEN);
	return;
}
void shinsei_printBoolCustomW(const bool val,const wchar_t*const restrict true_text,const size_t true_len,const wchar_t*const restrict false_text,const size_t false_len)_SHINSEI_OS_NOEXCEPT{
	printWNative((const wchar_t*)(val*(uintptr_t)true_text+(!val)*(uintptr_t)false_text),val*true_len+(!val)*false_len);
	return;
}
void shinsei_printBoolCustomN(const bool val,const wchar_t*const restrict true_text,const size_t true_len,const wchar_t*const restrict false_text,const size_t false_len)_SHINSEI_OS_NOEXCEPT{
	printWNative((const wchar_t*)(val*(uintptr_t)true_text+(!val)*(uintptr_t)false_text),val*true_len+(!val)*false_len);
	return;
}

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif
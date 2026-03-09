#include"shinsei/io.h"
#include<fcntl.h>

_SHINSEI_COLD static void printA_uninitialized(const char*restrict const str,const size_t len);
_SHINSEI_COLD static void printW_uninitialized(const wchar_t*restrict const str,const size_t len);
static void printA_initialized(const char*restrict const str,const size_t len);
static void printW_initialized(const wchar_t*restrict const str,const size_t len);
static void(*_printA)(const char*restrict const,const size_t)=&printA_uninitialized;
static void(*_printW)(const wchar_t*restrict const,const size_t)=&printW_uninitialized;
static INIT_ONCE _print_init_once=INIT_ONCE_STATIC_INIT;

static BOOL __stdcall printInitOnce(PINIT_ONCE init_once,PVOID para,PVOID* content){
	(void)init_once;
	(void)para;
	(void)content;
	setlocale(LC_ALL,""); 
    _printA=printA_initialized;
	_printW=printW_initialized;
	return TRUE;
}
_SHINSEI_COLD static void printA_initialized(const char*restrict const str,const size_t len){
	_setmode(_fileno(stdout), _O_TEXT);
	for(register size_t i=0;i<len;++i){
		putchar(str[i]);
	}
	return;
}
_SHINSEI_COLD static void printW_initialized(const wchar_t*restrict const str,const size_t len){
	_setmode(_fileno(stdout),_O_U16TEXT);
	for(register size_t i=0;i<len;++i){
		putwchar(str[i]);
	}
	return;
}
static void printA_uninitialized(const char*restrict const str,const size_t len){
	InitOnceExecuteOnce(&_print_init_once,printInitOnce,nullptr,nullptr);
	printA_initialized(str,len);
	return;
}
static void printW_uninitialized(const wchar_t*restrict const str,const size_t len){
	InitOnceExecuteOnce(&_print_init_once,printInitOnce,nullptr,nullptr);
	printW_initialized(str,len);
	return;
}

void shinsei_printA(const char*restrict const str,const size_t len){
	_printA(str,len);
	return;
}
void shinsei_printW(const wchar_t*restrict const str,const size_t len){
	_printW(str,len);
	return;
}

void shinsei_printLnA(const char*restrict const str,const size_t len){
	_printA(str,len);
	putchar('\n');
	return;
}
void shinsei_printLnW(const wchar_t*restrict const str,const size_t len){
	_printW(str,len);
	putwchar(L'\n');
	return;
}
#include"shinsei/sys.h"

static void __stdcall flsCloseHandle(void* p){
	if(__builtin_expect(p!=nullptr,1)) CloseHandle((HANDLE)p);
	return;
}
static DWORD _sleep_ms_fls=FLS_OUT_OF_INDEXES;
static INIT_ONCE _sleep_ms_init_once=INIT_ONCE_STATIC_INIT;
static BOOL __stdcall sleepMsInitOnce(PINIT_ONCE init_once,PVOID para,PVOID* content){
	_sleep_ms_fls=FlsAlloc(flsCloseHandle);
	if(__builtin_expect(_sleep_ms_fls==FLS_OUT_OF_INDEXES,0)) return FALSE;
	return TRUE;
}
bool shinsei_sleepMs(unsigned long long ms){
	if(__builtin_expect(__builtin_mul_overflow(ms,10000,&ms),0)) return false;
	if(__builtin_expect(!InitOnceExecuteOnce(&_sleep_ms_init_once,sleepMsInitOnce,nullptr,nullptr),0)){
		return false;
	}
	HANDLE timer=(HANDLE)FlsGetValue(_sleep_ms_fls);
	if(__builtin_expect(timer==nullptr,1)){
        timer=CreateWaitableTimerExW(
            nullptr,nullptr,
            CREATE_WAITABLE_TIMER_HIGH_RESOLUTION,
            SYNCHRONIZE|TIMER_MODIFY_STATE
        );
        if(__builtin_expect(timer==nullptr,0)) return false;
        if(__builtin_expect(!FlsSetValue(_sleep_ms_fls,timer),0)){
			CloseHandle(timer);
			return false;
		}
    }
	LARGE_INTEGER due;
    due.QuadPart=-(long long)ms;
    if(__builtin_expect(SetWaitableTimer(timer,&due,0,nullptr,nullptr,FALSE)==FALSE,0)) return false;
	register const DWORD res=WaitForSingleObject(timer,INFINITE);
    if(__builtin_expect(res!=WAIT_OBJECT_0,0)) return false;
	return true;
}
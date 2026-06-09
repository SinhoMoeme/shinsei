#include"shinsei/sys.h"

int_fast64_t shinsei_currentTime()_SHINSEI_OS_NOEXCEPT{
	FILETIME ft;
	GetSystemTimeAsFileTime(&ft);
	ULARGE_INTEGER ull;
	ull.LowPart=ft.dwLowDateTime;
	ull.HighPart=ft.dwHighDateTime;
	return (int_fast64_t)((ull.QuadPart-116444736000000000ULL)/10000ULL);
}

// sleeper_t

// [Internal] Static Constructor
_SHINSEI_OS_INLINE static bool slp_as(shinsei_sleeper_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	this->ptr=CreateWaitableTimerExW(nullptr,nullptr,CREATE_WAITABLE_TIMER_HIGH_RESOLUTION,SYNCHRONIZE|TIMER_MODIFY_STATE);
	if(__builtin_expect(this->ptr==nullptr,0)) return false;
	return true;
}

// [Internal] Inline Constructor
_SHINSEI_OS_INLINE static bool slp_inl(shinsei_sleeper_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->ptr=CreateWaitableTimerExW(nullptr,nullptr,CREATE_WAITABLE_TIMER_HIGH_RESOLUTION,SYNCHRONIZE|TIMER_MODIFY_STATE);
	if(__builtin_expect(this->ptr==nullptr,0)) return false;
	return true;
}

// [Internal] Start (Blocking, MS Mode)
_SHINSEI_OS_INLINE static bool slp_blockingMS(shinsei_sleeper_t*const restrict this,const uint_fast64_t ms)_SHINSEI_OS_NOEXCEPT{
	register void*const timer=this->ptr;
	register uint_fast64_t remain=ms;
	LARGE_INTEGER due;
	while(remain){
		register uint_fast64_t cur=(remain>922337203685477ULL)*922337203685477ULL+(remain<=922337203685477ULL)*remain;
		register uint_fast64_t tick=cur*10000ULL;
		due.QuadPart=-(long long)tick;
		if(__builtin_expect(!SetWaitableTimer(timer,&due,0,nullptr,nullptr,0),0)) return false;
		register const uint_fast32_t res=WaitForSingleObject(timer,INFINITE);
		if(__builtin_expect(res!=WAIT_OBJECT_0,0)) return false;
		remain-=cur;
	}
	return true;
}

// [Internal] Start (Blocking, US Mode)
_SHINSEI_OS_INLINE static bool slp_blockingUS(shinsei_sleeper_t*const restrict this,const uint_fast64_t us)_SHINSEI_OS_NOEXCEPT{
	register void*const timer=this->ptr;
	register uint_fast64_t remain=us;
	LARGE_INTEGER due;
	while(remain){
		register uint_fast64_t cur=(remain>922337203685477580ULL)*922337203685477580ULL+(remain<=922337203685477580ULL)*remain;
		register uint_fast64_t tick=cur*10ULL;
		due.QuadPart=-(long long)tick;
		if(__builtin_expect(!SetWaitableTimer(timer,&due,0,nullptr,nullptr,0),0)) return false;
		register const uint_fast32_t res=WaitForSingleObject(timer,INFINITE);
		if(__builtin_expect(res!=WAIT_OBJECT_0,0)) return false;
		remain-=cur;
	}
	return true;
}

// [Internal] Start (Busy, MS Mode)
_SHINSEI_OS_INLINE static bool slp_busyMS(const uint_fast64_t ms)_SHINSEI_OS_NOEXCEPT{
	LARGE_INTEGER freq,start,current;
	QueryPerformanceFrequency(&freq);
	register uint_fast64_t remain=ms;
	register const uint_fast64_t limit=18446744073709551615ULL/(uint_fast64_t)freq.QuadPart;
	while(remain){
		register uint_fast64_t cur=(remain>limit)*limit+(remain<=limit)*remain;
		register const uint_fast64_t total=(cur*(uint_fast64_t)freq.QuadPart)/1000ULL;
		QueryPerformanceCounter(&start);
		do{
			QueryPerformanceCounter(&current);
		}
		while((uint_fast64_t)(current.QuadPart-start.QuadPart)<total);
		remain-=cur;
	}
	return true;
}

// [Internal] Start (Busy, US Mode)
_SHINSEI_OS_INLINE static bool slp_busyUS(const uint_fast64_t us)_SHINSEI_OS_NOEXCEPT{
	LARGE_INTEGER freq,start,current;
	QueryPerformanceFrequency(&freq);
	register uint_fast64_t remain=us;
	register const uint_fast64_t limit=18446744073709551615ULL/(uint_fast64_t)freq.QuadPart;
	while(remain){
		register uint_fast64_t cur=(remain>limit)*limit+(remain<=limit)*remain;
		register const uint_fast64_t total=(cur*(uint_fast64_t)freq.QuadPart)/1000000ULL;
		QueryPerformanceCounter(&start);
		do{
			QueryPerformanceCounter(&current);
		}
		while((uint_fast64_t)(current.QuadPart-start.QuadPart)<total);
		remain-=cur;
	}
	return true;
}

// Default Constructor
shinsei_sleeper_t* shinsei_sleeper_t_con()_SHINSEI_OS_NOEXCEPT{
	register shinsei_sleeper_t*const this=(shinsei_sleeper_t*const)malloc(sizeof(shinsei_sleeper_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!slp_as(this),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Destructor
void shinsei_sleeper_t_dec(shinsei_sleeper_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	CloseHandle(this->ptr);
	free(this);
	return;
}

// Static Constructor
bool shinsei_sleeper_t_as(shinsei_sleeper_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return slp_as(this);
}

// Inline Constructor
bool shinsei_sleeper_t_inl(shinsei_sleeper_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return slp_inl(this);
}

// Identity Controls
bool shinsei_sleeper_t_inlined(const shinsei_sleeper_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}
int_fast32_t shinsei_sleeper_t_getCtrl(const shinsei_sleeper_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl;
}
void shinsei_sleeper_t_setCtrl(shinsei_sleeper_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=ctrl;
	return;
}

// Start (Blocking, MS Mode)
bool shinsei_sleeper_t_blockingMS(shinsei_sleeper_t*const restrict this,const uint_fast64_t ms)_SHINSEI_OS_NOEXCEPT{
	return slp_blockingMS(this,ms);
}

// Start (Blocking, US Mode)
bool shinsei_sleeper_t_blockingUS(shinsei_sleeper_t*const restrict this,const uint_fast64_t us)_SHINSEI_OS_NOEXCEPT{
	return slp_blockingUS(this,us);
}

// Start (Busy, MS Mode)
bool shinsei_sleeper_t_busyMS(shinsei_sleeper_t*const restrict this,const uint_fast64_t ms)_SHINSEI_OS_NOEXCEPT{
	(void)this;
	return slp_busyMS(ms);
}

// Start (Busy, US Mode)
bool shinsei_sleeper_t_busyUS(shinsei_sleeper_t*const restrict this,const uint_fast64_t us)_SHINSEI_OS_NOEXCEPT{
	(void)this;
	return slp_busyUS(us);
}


// clock_t

// [Internal] Start (Blocking, MS Mode)
_SHINSEI_OS_INLINE static bool clk_blockingMS(shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	register void*const timer=this->internal_ptr;
	register uint_fast64_t remain=this->cycle;
	LARGE_INTEGER due;
	while(remain){
		register uint_fast64_t cur=(remain>922337203685477ULL)*922337203685477ULL+(remain<=922337203685477ULL)*remain;
		register uint_fast64_t tick=cur*10000ULL;
		due.QuadPart=-(long long)tick;
		if(__builtin_expect(!SetWaitableTimer(timer,&due,0,nullptr,nullptr,0),0)) return false;
		register const uint_fast32_t res=WaitForSingleObject(timer,INFINITE);
		if(__builtin_expect(res!=WAIT_OBJECT_0,0)) return false;
		remain-=cur;
	}
	return true;
}

// [Internal] Start (Blocking, US Mode)
_SHINSEI_OS_INLINE static bool clk_blockingUS(shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	register void*const timer=this->internal_ptr;
	register uint_fast64_t remain=this->cycle;
	LARGE_INTEGER due;
	while(remain){
		register uint_fast64_t cur=(remain>922337203685477580ULL)*922337203685477580ULL+(remain<=922337203685477580ULL)*remain;
		register uint_fast64_t tick=cur*10ULL;
		due.QuadPart=-(long long)tick;
		if(__builtin_expect(!SetWaitableTimer(timer,&due,0,nullptr,nullptr,0),0)) return false;
		register const uint_fast32_t res=WaitForSingleObject(timer,INFINITE);
		if(__builtin_expect(res!=WAIT_OBJECT_0,0)) return false;
		remain-=cur;
	}
	return true;
}

// [Internal] Loop Routine
static DWORD WINAPI clk_loop(LPVOID arg)_SHINSEI_OS_NOEXCEPT{
	shinsei_clock_t*const this=(shinsei_clock_t*)arg;
	while(this->ctrl&_SHINSEI_CTRL_RUNNING){
		(*this->callback)(this->arg);
		if(this->busy_mode){
			if(this->us_mode) slp_busyUS(this->cycle);
			else slp_busyMS(this->cycle);
		}else{
			if(this->us_mode) clk_blockingUS(this);
			else clk_blockingMS(this);
		}
	}
	return 0;
}

// [Internal] Static Constructor
_SHINSEI_OS_INLINE static bool clk_as(shinsei_clock_t*const restrict this,const uint_fast64_t cycle,const bool us_mode,shinsei_clock_callback_t*const callback,void*const arg)_SHINSEI_OS_NOEXCEPT{
	this->internal_ptr=CreateWaitableTimerExW(nullptr,nullptr,CREATE_WAITABLE_TIMER_HIGH_RESOLUTION,SYNCHRONIZE|TIMER_MODIFY_STATE);
	if(__builtin_expect(this->internal_ptr==nullptr,0)) return false;
	this->ctrl=0;
	this->callback=callback;
	this->arg=arg;
	this->cycle=cycle;
	this->us_mode=us_mode;
	this->busy_mode=false;
	this->ptr=nullptr;
	return true;
}

// [Internal] Inline Constructor
_SHINSEI_OS_INLINE static bool clk_inl(shinsei_clock_t*const restrict this,const uint_fast64_t cycle,const bool us_mode,shinsei_clock_callback_t*const callback,void*const arg)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!clk_as(this,cycle,us_mode,callback,arg),0)) return false;
	this->ctrl|=_SHINSEI_CTRL_INLINED;
	return true;
}

// [Internal] Stop
_SHINSEI_OS_INLINE static void clk_stop(shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	WaitForSingleObject((HANDLE)this->ptr,INFINITE);
	CloseHandle((HANDLE)this->ptr);
	return;
}

// Default Constructor
shinsei_clock_t* shinsei_clock_t_con(const uint_fast64_t cycle,const bool us_mode,shinsei_clock_callback_t*const callback,void*const arg)_SHINSEI_OS_NOEXCEPT{
	register shinsei_clock_t*const this=(shinsei_clock_t*const)malloc(sizeof(shinsei_clock_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!clk_as(this,cycle,us_mode,callback,arg),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Destructor
void shinsei_clock_t_dec(shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(this->ctrl&_SHINSEI_CTRL_RUNNING) clk_stop(this);
	if(this->internal_ptr!=nullptr) CloseHandle((HANDLE)this->internal_ptr);
	free(this);
	return;
}

// Static Constructor
bool shinsei_clock_t_as(shinsei_clock_t*const restrict this,const uint_fast64_t cycle,const bool us_mode,shinsei_clock_callback_t*const callback,void*const arg)_SHINSEI_OS_NOEXCEPT{
	return clk_as(this,cycle,us_mode,callback,arg);
}

// Inline Constructor
bool shinsei_clock_t_inl(shinsei_clock_t*const restrict this,const uint_fast64_t cycle,const bool us_mode,shinsei_clock_callback_t*const callback,void*const arg)_SHINSEI_OS_NOEXCEPT{
	return clk_inl(this,cycle,us_mode,callback,arg);
}

// Identity Controls
bool shinsei_clock_t_inlined(const shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}
int_fast32_t shinsei_clock_t_getCtrl(const shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl;
}
void shinsei_clock_t_setCtrl(shinsei_clock_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=ctrl;
	return;
}

// Start (Blocking Mode)
bool shinsei_clock_t_startBlocking(shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ctrl&_SHINSEI_CTRL_RUNNING,0)) return false;
	this->ctrl|=_SHINSEI_CTRL_RUNNING;
	this->busy_mode=false;
	this->ptr=CreateThread(nullptr,0,clk_loop,this,0,nullptr);
	if(__builtin_expect(this->ptr==nullptr,0)){
		this->ctrl&=~_SHINSEI_CTRL_RUNNING;
		return false;
	}
	return true;
}

// Start (Busy Mode)
bool shinsei_clock_t_startBusy(shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ctrl&_SHINSEI_CTRL_RUNNING,0)) return false;
	this->ctrl|=_SHINSEI_CTRL_RUNNING;
	this->busy_mode=true;
	this->ptr=CreateThread(nullptr,0,clk_loop,this,0,nullptr);
	if(__builtin_expect(this->ptr==nullptr,0)){
		this->ctrl&=~_SHINSEI_CTRL_RUNNING;
		return false;
	}
	return true;
}

// Stop
void shinsei_clock_t_stop(shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!(this->ctrl&_SHINSEI_CTRL_RUNNING),0)) return;
	clk_stop(this);
	this->ptr=nullptr;
	this->ctrl&=~_SHINSEI_CTRL_RUNNING;
	return;
}

// [Const] Is the clock running
bool shinsei_clock_t_running(const shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_RUNNING;
}

// Clock Setup
bool shinsei_clock_t_getUSMode(const shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->us_mode;
}
void shinsei_clock_t_setUSMode(shinsei_clock_t*const restrict this,const bool us_mode)_SHINSEI_OS_NOEXCEPT{
	this->us_mode=us_mode;
	return;
}
uint_fast64_t shinsei_clock_t_getCycle(const shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->cycle;
}
void shinsei_clock_t_setCycle(shinsei_clock_t*const restrict this,const uint_fast64_t cycle)_SHINSEI_OS_NOEXCEPT{
	this->cycle=cycle;
	return;
}
shinsei_clock_callback_t* shinsei_clock_t_getCallback(const shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->callback;
}
void* shinsei_clock_t_getArg(const shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->arg;
}
void shinsei_clock_t_setArg(shinsei_clock_t*const restrict this,void*const arg)_SHINSEI_OS_NOEXCEPT{
	this->arg=arg;
	return;
}
void shinsei_clock_t_setCallback(shinsei_clock_t*const restrict this,shinsei_clock_callback_t*const cb,void*const arg)_SHINSEI_OS_NOEXCEPT{
	this->callback=cb;
	this->arg=arg;
	return;
}


// thread_t

// [Internal] Loop Routine
static DWORD WINAPI thd_loop(LPVOID arg)_SHINSEI_OS_NOEXCEPT{
	shinsei_thread_t*const this=(shinsei_thread_t*)arg;
	if(__builtin_expect(this->callback!=nullptr,1)){
		this->ret=(*this->callback)(this->arg);
	}
	this->ctrl&=~_SHINSEI_CTRL_RUNNING;
	return 0;
}

// [Internal] Static Constructor
_SHINSEI_OS_INLINE static bool thd_as(shinsei_thread_t*const restrict this,shinsei_thread_callback_t*const cb,void*const arg,void*const ret)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	this->callback=cb;
	this->arg=arg;
	this->ret=ret;
	this->ptr=nullptr;
	return true;
}

// [Internal] Inline Constructor
_SHINSEI_OS_INLINE static bool thd_inl(shinsei_thread_t*const restrict this,shinsei_thread_callback_t*const cb,void*const arg,void*const ret)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!thd_as(this,cb,arg,ret),0)) return false;
	this->ctrl|=_SHINSEI_CTRL_INLINED;
	return true;
}

// [Internal] Stop
_SHINSEI_OS_INLINE static void thd_stop(shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	WaitForSingleObject((HANDLE)this->ptr,INFINITE);
	CloseHandle((HANDLE)this->ptr);
	return;
}

// Default Constructor
shinsei_thread_t* shinsei_thread_t_con(shinsei_thread_callback_t*const cb,void*const arg,void*const ret)_SHINSEI_OS_NOEXCEPT{
	register shinsei_thread_t*const this=(shinsei_thread_t*const)malloc(sizeof(shinsei_thread_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	thd_as(this,cb,arg,ret);
	return this;
}

// Destructor
void shinsei_thread_t_dec(shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(this->ctrl&_SHINSEI_CTRL_RUNNING) thd_stop(this);
	free(this);
	return;
}

// Static Constructor
bool shinsei_thread_t_as(shinsei_thread_t*const restrict this,shinsei_thread_callback_t*const cb,void*const arg,void*const ret)_SHINSEI_OS_NOEXCEPT{
	return thd_as(this,cb,arg,ret);
}

// Inline Constructor
bool shinsei_thread_t_inl(shinsei_thread_t*const restrict this,shinsei_thread_callback_t*const cb,void*const arg,void*const ret)_SHINSEI_OS_NOEXCEPT{
	return thd_inl(this,cb,arg,ret);
}

// Identity Controls
bool shinsei_thread_t_inlined(const shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}
int_fast32_t shinsei_thread_t_getCtrl(const shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl;
}
void shinsei_thread_t_setCtrl(shinsei_thread_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=ctrl;
	return;
}

// Start
bool shinsei_thread_t_start(shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ctrl&_SHINSEI_CTRL_RUNNING,0)) return false;
	this->ctrl|=_SHINSEI_CTRL_RUNNING;
	this->ptr=CreateThread(nullptr,0,thd_loop,this,0,nullptr);
	if(__builtin_expect(this->ptr==nullptr,0)){
		this->ctrl&=~_SHINSEI_CTRL_RUNNING;
		return false;
	}
	return true;
}

// Stop
void shinsei_thread_t_stop(shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!(this->ctrl&_SHINSEI_CTRL_RUNNING),0)) return;
	thd_stop(this);
	this->ctrl&=~_SHINSEI_CTRL_RUNNING;
	this->ptr=nullptr;
	return;
}

// [Const] Is the thread running
bool shinsei_thread_t_running(const shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_RUNNING;
}

// Join
void* shinsei_thread_t_join(shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(this->ctrl&_SHINSEI_CTRL_RUNNING) shinsei_thread_t_stop(this);
	return this->ret;
}

// Force Terminate
void shinsei_thread_t_forceTerminate(shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!(this->ctrl&_SHINSEI_CTRL_RUNNING),0)) return;
	TerminateThread((HANDLE)this->ptr,0);
	CloseHandle((HANDLE)this->ptr);
	this->ptr=nullptr;
	this->ctrl&=~_SHINSEI_CTRL_RUNNING;
	return;
}

// Thread Setup
shinsei_thread_callback_t* shinsei_thread_t_getCallback(const shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->callback;
}
void* shinsei_thread_t_getArg(const shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->arg;
}
void shinsei_thread_t_setArg(shinsei_thread_t*const restrict this,void*const arg)_SHINSEI_OS_NOEXCEPT{
	this->arg=arg;
	return;
}
void* shinsei_thread_t_getRet(const shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ret;
}
void shinsei_thread_t_setRet(shinsei_thread_t*const restrict this,void*const ret)_SHINSEI_OS_NOEXCEPT{
	this->ret=ret;
	return;
}
void shinsei_thread_t_setCallback(shinsei_thread_t*const restrict this,shinsei_thread_callback_t*const cb,void*const arg)_SHINSEI_OS_NOEXCEPT{
	this->callback=cb;
	this->arg=arg;
	return;
}
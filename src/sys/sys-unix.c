#include"shinsei/sys.h"

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

int_fast64_t shinsei_currentTime()_SHINSEI_OS_NOEXCEPT{
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME,&ts);
	return (int_fast64_t)ts.tv_sec*1000LL+(int_fast64_t)(ts.tv_nsec/1000000L);
}

// sleeper_t

// [Internal] Static Constructor
_SHINSEI_OS_INLINE static bool slp_as(shinsei_sleeper_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	this->ptr=nullptr;
	return true;
}

// [Internal] Inline Constructor
_SHINSEI_OS_INLINE static bool slp_inl(shinsei_sleeper_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->ptr=nullptr;
	return true;
}

// [Internal] Start (Blocking, MS Mode)
_SHINSEI_OS_INLINE static bool slp_blockingMS(const uint_fast64_t ms)_SHINSEI_OS_NOEXCEPT{
	register uint_fast64_t remain=ms;
	struct timespec req,rem;
	while(remain){
		register uint_fast64_t cur=(remain>2147483647000ULL)*2147483647000ULL+(remain<=2147483647000ULL)*remain;
		req.tv_sec=(time_t)(cur/1000ULL);
		req.tv_nsec=(long)((cur%1000ULL)*1000000ULL);
		while(__builtin_expect(nanosleep(&req,&rem)==-1,0)) req=rem;
		remain-=cur;
	}
	return true;
}

// [Internal] Start (Blocking, US Mode)
_SHINSEI_OS_INLINE static bool slp_blockingUS(const uint_fast64_t us)_SHINSEI_OS_NOEXCEPT{
	register uint_fast64_t remain=us;
	struct timespec req,rem;
	while(remain){
		register uint_fast64_t cur=(remain>2147483647000000ULL)*2147483647000000ULL+(remain<=2147483647000000ULL)*remain;
		req.tv_sec=(time_t)(cur/1000000ULL);
		req.tv_nsec=(long)((cur%1000000ULL)*1000ULL);
		while(__builtin_expect(nanosleep(&req,&rem)==-1,0)) req=rem;
		remain-=cur;
	}
	return true;
}

// [Internal] Start (Busy, MS Mode)
_SHINSEI_OS_INLINE static bool slp_busyMS(const uint_fast64_t ms)_SHINSEI_OS_NOEXCEPT{
	register uint_fast64_t remain=ms;
	struct timespec start,current;
	while(remain){
		register uint_fast64_t cur=(remain>10000000000000ULL)*10000000000000ULL+(remain<=10000000000000ULL)*remain;
		register const uint_fast64_t total_ns=cur*1000000ULL;
		clock_gettime(CLOCK_MONOTONIC,&start);
		do{
			clock_gettime(CLOCK_MONOTONIC,&current);
		}while(((uint_fast64_t)(current.tv_sec-start.tv_sec)*1000000000ULL+(uint_fast64_t)current.tv_nsec-(uint_fast64_t)start.tv_nsec)<total_ns);
		remain-=cur;
	}
	return true;
}

// [Internal] Start (Busy, US Mode)
_SHINSEI_OS_INLINE static bool slp_busyUS(const uint_fast64_t us)_SHINSEI_OS_NOEXCEPT{
	register uint_fast64_t remain=us;
	struct timespec start,current;
	while(remain){
		register uint_fast64_t cur=(remain>10000000000000000ULL)*10000000000000000ULL+(remain<=10000000000000000ULL)*remain;
		register const uint_fast64_t total_ns=cur*1000ULL;
		clock_gettime(CLOCK_MONOTONIC,&start);
		do{
			clock_gettime(CLOCK_MONOTONIC,&current);
		}while(((uint_fast64_t)(current.tv_sec-start.tv_sec)*1000000000ULL+(uint_fast64_t)current.tv_nsec-(uint_fast64_t)start.tv_nsec)<total_ns);
		remain-=cur;
	}
	return true;
}


// Default Constructor
shinsei_sleeper_t* shinsei_sleeper_t_con()_SHINSEI_OS_NOEXCEPT{
	register shinsei_sleeper_t*const this=(shinsei_sleeper_t*const)__builtin_malloc(sizeof(shinsei_sleeper_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	slp_as(this);
	return this;
}

// Free data (For C++ Destructor safe resource releasing without deallocating object memory)
void shinsei_sleeper_t_freeData(shinsei_sleeper_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	(void)this;
	return;
}

// Destructor
void shinsei_sleeper_t_dec(shinsei_sleeper_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	__builtin_free(this);
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
	(void)this;
	return slp_blockingMS(ms);
}

// Start (Blocking, US Mode)
bool shinsei_sleeper_t_blockingUS(shinsei_sleeper_t*const restrict this,const uint_fast64_t us)_SHINSEI_OS_NOEXCEPT{
	(void)this;
	return slp_blockingUS(us);
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

// [Internal] Loop Routine
static void* clk_loop(void* arg)_SHINSEI_OS_NOEXCEPT{
	shinsei_clock_t*const this=(shinsei_clock_t*)arg;
	while(this->ctrl&_SHINSEI_CTRL_RUNNING){
		if(__builtin_expect(this->callback!=nullptr,1)){
			(*this->callback)(this->arg);
		}
		if(this->busy_mode){
			if(this->us_mode) slp_busyUS(this->cycle);
			else slp_busyMS(this->cycle);
		}else{
			if(this->us_mode) slp_blockingUS(this->cycle);
			else slp_blockingMS(this->cycle);
		}
	}
	return nullptr;
}

// [Internal] Static Constructor
_SHINSEI_OS_INLINE static bool clk_as(shinsei_clock_t*const restrict this,const uint_fast64_t cycle,const bool us_mode,shinsei_clock_callback_t*const callback,void*const arg)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	this->callback=callback;
	this->arg=arg;
	this->cycle=cycle;
	this->us_mode=us_mode;
	this->busy_mode=false;
	this->ptr=nullptr;
	this->internal_ptr=nullptr;
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
	pthread_join(*(pthread_t*)this->ptr,nullptr);
	return;
}

// Default Constructor
shinsei_clock_t* shinsei_clock_t_con(const uint_fast64_t cycle,const bool us_mode,shinsei_clock_callback_t*const callback,void*const arg)_SHINSEI_OS_NOEXCEPT{
	register shinsei_clock_t*const this=(shinsei_clock_t*const)__builtin_malloc(sizeof(shinsei_clock_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!clk_as(this,cycle,us_mode,callback,arg),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}

// Free data (For C++ Destructor safe resource releasing without deallocating object memory)
void shinsei_clock_t_freeData(shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	shinsei_clock_t_stop(this);
	return;
}

// Destructor
void shinsei_clock_t_dec(shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	shinsei_clock_t_freeData(this);
	__builtin_free(this);
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
	if(__builtin_expect(this->ptr!=nullptr,0)) return false;
	this->ctrl|=_SHINSEI_CTRL_RUNNING;
	this->busy_mode=false;
	this->ptr=__builtin_malloc(sizeof(pthread_t));
	if(__builtin_expect(this->ptr==nullptr,0)){
		this->ctrl&=~_SHINSEI_CTRL_RUNNING;
		return false;
	}
	if(__builtin_expect(pthread_create((pthread_t*)this->ptr,nullptr,clk_loop,this)!=0,0)){
		this->ctrl&=~_SHINSEI_CTRL_RUNNING;
		__builtin_free(this->ptr);
		this->ptr=nullptr;
		return false;
	}
	return true;
}

// Start (Busy Mode)
bool shinsei_clock_t_startBusy(shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr!=nullptr,0)) return false;
	this->ctrl|=_SHINSEI_CTRL_RUNNING;
	this->busy_mode=true;
	this->ptr=__builtin_malloc(sizeof(pthread_t));
	if(__builtin_expect(this->ptr==nullptr,0)){
		this->ctrl&=~_SHINSEI_CTRL_RUNNING;
		return false;
	}
	if(__builtin_expect(pthread_create((pthread_t*)this->ptr,nullptr,clk_loop,this)!=0,0)){
		this->ctrl&=~_SHINSEI_CTRL_RUNNING;
		__builtin_free(this->ptr);
		this->ptr=nullptr;
		return false;
	}
	return true;
}

// Stop
void shinsei_clock_t_stop(shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return;
	this->ctrl&=~_SHINSEI_CTRL_RUNNING; // Flag cleared FIRST to safely abort loop
	clk_stop(this); // Then Join to guarantee sync
	__builtin_free(this->ptr); // Then safely free metadata memory
	this->ptr=nullptr;
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
static void* thd_loop(void* arg)_SHINSEI_OS_NOEXCEPT{
	shinsei_thread_t*const this=(shinsei_thread_t*)arg;
	if(__builtin_expect(this->callback!=nullptr,1)){
		this->ret=(*this->callback)(this->arg);
	}
	this->ctrl&=~_SHINSEI_CTRL_RUNNING;
	return nullptr;
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
	pthread_join(*(pthread_t*)this->ptr,nullptr);
	return;
}

// Default Constructor
shinsei_thread_t* shinsei_thread_t_con(shinsei_thread_callback_t*const cb,void*const arg,void*const ret)_SHINSEI_OS_NOEXCEPT{
	register shinsei_thread_t*const this=(shinsei_thread_t*const)__builtin_malloc(sizeof(shinsei_thread_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!thd_as(this,cb,arg,ret),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}

// Free data (For C++ Destructor safe resource releasing without deallocating object memory)
void shinsei_thread_t_freeData(shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	shinsei_thread_t_stop(this);
	return;
}

// Destructor
void shinsei_thread_t_dec(shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	shinsei_thread_t_freeData(this);
	__builtin_free(this);
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
	if(__builtin_expect(this->ptr!=nullptr,0)) return false;
	this->ctrl|=_SHINSEI_CTRL_RUNNING;
	this->ptr=__builtin_malloc(sizeof(pthread_t));
	if(__builtin_expect(this->ptr==nullptr,0)){
		this->ctrl&=~_SHINSEI_CTRL_RUNNING;
		return false;
	}
	if(__builtin_expect(pthread_create((pthread_t*)this->ptr,nullptr,thd_loop,this)!=0,0)){
		this->ctrl&=~_SHINSEI_CTRL_RUNNING;
		__builtin_free(this->ptr);
		this->ptr=nullptr;
		return false;
	}
	return true;
}

// Stop
void shinsei_thread_t_stop(shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return;
	this->ctrl&=~_SHINSEI_CTRL_RUNNING; // Not strictly needed to stop a thread, but safe tracking
	thd_stop(this); // Join guarantees no zombie leak
	__builtin_free(this->ptr); // Prevent Malloc leak
	this->ptr=nullptr;
	return;
}

// [Const] Is the thread running
bool shinsei_thread_t_running(const shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_RUNNING;
}

// Join
void* shinsei_thread_t_join(shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	shinsei_thread_t_stop(this);
	return this->ret;
}

// Force Terminate
void shinsei_thread_t_forceTerminate(shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->ptr==nullptr,0)) return;
	pthread_cancel(*(pthread_t*)this->ptr);
	this->ctrl&=~_SHINSEI_CTRL_RUNNING;
	thd_stop(this); // Must join after cancel to reap internal resources
	__builtin_free(this->ptr);
	this->ptr=nullptr;
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

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif
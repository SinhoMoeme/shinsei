#pragma once

#include"shinsei/minimal/sys.h"
#include"shinsei/.internal/std.h"
#include<stdint.h>

#ifdef _SHINSEI_OS_UNIX
	#include<time.h>
#endif

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

typedef void (*shinsei_clock_callback_t)(void*);
typedef void* (*shinsei_thread_callback_t)(void*);

typedef struct _SHINSEI_OS_ALIGN_BYTE{
	int_fast32_t ctrl;
	void* ptr;
}shinsei_sleeper_t;

typedef struct _SHINSEI_OS_ALIGN_BYTE{
	int_fast32_t ctrl;
	shinsei_clock_callback_t* callback;
	void* arg;
	uint_fast64_t cycle;
	void* ptr;
	void* internal_ptr;
	bool us_mode;
	bool busy_mode;
}shinsei_clock_t;

typedef struct _SHINSEI_OS_ALIGN_BYTE{
	int_fast32_t ctrl;
	shinsei_thread_callback_t* callback;
	void* arg;
	void* ret;
	void* ptr;
}shinsei_thread_t;

_SHINSEI_LIB_API int_fast64_t shinsei_currentTime()_SHINSEI_OS_NOEXCEPT;

// sleeper_t
_SHINSEI_LIB_API shinsei_sleeper_t* shinsei_sleeper_t_con()_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_sleeper_t_freeData(shinsei_sleeper_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_sleeper_t_dec(shinsei_sleeper_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_sleeper_t_as(shinsei_sleeper_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_sleeper_t_inl(shinsei_sleeper_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_sleeper_t_inlined(const shinsei_sleeper_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_sleeper_t_getCtrl(const shinsei_sleeper_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_sleeper_t_setCtrl(shinsei_sleeper_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_sleeper_t_blockingMS(shinsei_sleeper_t*const restrict this,const uint_fast64_t ms)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_sleeper_t_blockingUS(shinsei_sleeper_t*const restrict this,const uint_fast64_t us)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_sleeper_t_busyMS(shinsei_sleeper_t*const restrict this,const uint_fast64_t ms)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_sleeper_t_busyUS(shinsei_sleeper_t*const restrict this,const uint_fast64_t us)_SHINSEI_OS_NOEXCEPT;

// clock_t
_SHINSEI_LIB_API shinsei_clock_t* shinsei_clock_t_con(const uint_fast64_t cycle,const bool us_mode,shinsei_clock_callback_t*const cb,void*const arg)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_clock_t_freeData(shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_clock_t_dec(shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_clock_t_as(shinsei_clock_t*const restrict this,const uint_fast64_t cycle,const bool us_mode,shinsei_clock_callback_t*const cb,void*const arg)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_clock_t_inl(shinsei_clock_t*const restrict this,const uint_fast64_t cycle,const bool us_mode,shinsei_clock_callback_t*const cb,void*const arg)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_clock_t_inlined(const shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_clock_t_getCtrl(const shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_clock_t_setCtrl(shinsei_clock_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_clock_t_startBlocking(shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_clock_t_startBusy(shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_clock_t_stop(shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_clock_t_running(const shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_clock_t_getUSMode(const shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_clock_t_setUSMode(shinsei_clock_t*const restrict this,const bool us_mode)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API uint_fast64_t shinsei_clock_t_getCycle(const shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_clock_t_setCycle(shinsei_clock_t*const restrict this,const uint_fast64_t cycle)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_clock_callback_t* shinsei_clock_t_getCallback(const shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void* shinsei_clock_t_getArg(const shinsei_clock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_clock_t_setArg(shinsei_clock_t*const restrict this,void*const arg)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_clock_t_setCallback(shinsei_clock_t*const restrict this,shinsei_clock_callback_t*const cb,void*const arg)_SHINSEI_OS_NOEXCEPT;

// thread_t
_SHINSEI_LIB_API shinsei_thread_t* shinsei_thread_t_con(shinsei_thread_callback_t*const cb,void*const arg,void*const ret)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_thread_t_freeData(shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_thread_t_dec(shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_thread_t_as(shinsei_thread_t*const restrict this,shinsei_thread_callback_t*const cb,void*const arg,void*const ret)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_thread_t_inl(shinsei_thread_t*const restrict this,shinsei_thread_callback_t*const cb,void*const arg,void*const ret)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_thread_t_inlined(const shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_thread_t_getCtrl(const shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_thread_t_setCtrl(shinsei_thread_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_thread_t_start(shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_thread_t_stop(shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_thread_t_running(const shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void* shinsei_thread_t_join(shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_thread_t_forceTerminate(shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_thread_callback_t* shinsei_thread_t_getCallback(const shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void* shinsei_thread_t_getArg(const shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_thread_t_setArg(shinsei_thread_t*const restrict this,void*const arg)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void* shinsei_thread_t_getRet(const shinsei_thread_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_thread_t_setRet(shinsei_thread_t*const restrict this,void*const ret)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_thread_t_setCallback(shinsei_thread_t*const restrict this,shinsei_thread_callback_t*const cb,void*const arg)_SHINSEI_OS_NOEXCEPT;

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif
#pragma once

#include"shinsei/minimal/sys.hpp"
#include"shinsei/sys.h"
#include"shinsei/.internal/tag.hpp"
#include<new>

namespace shinsei{
	using clock_callback_t=::shinsei_clock_callback_t;
	using thread_callback_t=::shinsei_thread_callback_t;
	
	static inline int_fast64_t currentTime()_SHINSEI_OS_NOEXCEPT{
		return ::shinsei_currentTime();
	}
	
	class sleeper_t{
	private:
		::shinsei_sleeper_t obj;
	
	public:
		// Default constructor
		sleeper_t(){
			if(!::shinsei_sleeper_t_as(&obj)) throw std::bad_alloc();
			return;
		}
		
		// In-place Constructors
		explicit sleeper_t(shinsei::in_place_t){
			if(!::shinsei_sleeper_t_as(&obj)) throw std::bad_alloc();
			return;
		}
		
		// Inlined Constructors
		explicit sleeper_t(shinsei::inlined_t){
			if(!::shinsei_sleeper_t_inl(&obj)) throw std::bad_alloc();
			return;
		}
		
		// Destructor
		~sleeper_t()_SHINSEI_OS_NOEXCEPT{
			if(!inlined()) ::shinsei_sleeper_t_freeData(&obj);
			return;
		}
		
		// Disable Copy & Move
		sleeper_t(const sleeper_t&)=delete;
		sleeper_t(sleeper_t&&)=delete;
		sleeper_t& operator=(const sleeper_t&)=delete;
		sleeper_t& operator=(sleeper_t&&)=delete;
		
		// Sleep APIs
		bool blockingMS(const uint_fast64_t ms)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_sleeper_t_blockingMS(&obj,ms);
		}
		bool blockingUS(const uint_fast64_t us)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_sleeper_t_blockingUS(&obj,us);
		}
		bool busyMS(const uint_fast64_t ms)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_sleeper_t_busyMS(&obj,ms);
		}
		bool busyUS(const uint_fast64_t us)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_sleeper_t_busyUS(&obj,us);
		}
		
		// Static Helpers
		static void as(sleeper_t*const restrict ptr){
			if(!::shinsei_sleeper_t_as(ptr->cObj())) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_sleeper_t*const restrict ptr){
			if(!::shinsei_sleeper_t_as(ptr)) throw std::bad_alloc();
			return;
		}
		
		static void inl(sleeper_t*const restrict ptr){
			if(!::shinsei_sleeper_t_inl(ptr->cObj())) throw std::bad_alloc();
			return;
		}
		static void inl(::shinsei_sleeper_t*const restrict ptr){
			if(!::shinsei_sleeper_t_inl(ptr)) throw std::bad_alloc();
			return;
		}
		
		// Core Identity Controls
		bool inlined()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_sleeper_t_inlined(&obj);
		}
		int_fast32_t getCtrl()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_sleeper_t_getCtrl(&obj);
		}
		void setCtrl(const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
			::shinsei_sleeper_t_setCtrl(&obj,ctrl);
			return;
		}
		
		// Type Casting / Access
		::shinsei_sleeper_t* cObj()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		const ::shinsei_sleeper_t* cObj()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator ::shinsei_sleeper_t*()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator const ::shinsei_sleeper_t*()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
	};
	
	class clock_t{
	private:
		::shinsei_clock_t obj;
	
	public:
		// Default constructor
		clock_t(const uint_fast64_t cycle,const bool us_mode,clock_callback_t*const cb,void*const arg=nullptr){
			if(!::shinsei_clock_t_as(&obj,cycle,us_mode,cb,arg)) throw std::bad_alloc();
			return;
		}
		
		// In-place Constructors
		explicit clock_t(shinsei::in_place_t,const uint_fast64_t cycle,const bool us_mode,clock_callback_t*const cb,void*const arg=nullptr){
			if(!::shinsei_clock_t_as(&obj,cycle,us_mode,cb,arg)) throw std::bad_alloc();
			return;
		}
		
		// Inlined Constructors
		explicit clock_t(shinsei::inlined_t,const uint_fast64_t cycle,const bool us_mode,clock_callback_t*const cb,void*const arg=nullptr){
			if(!::shinsei_clock_t_inl(&obj,cycle,us_mode,cb,arg)) throw std::bad_alloc();
			return;
		}
		
		// Destructor
		~clock_t()_SHINSEI_OS_NOEXCEPT{
			if(!inlined()) ::shinsei_clock_t_freeData(&obj);
			return;
		}
		
		// Disable Copy & Move
		clock_t(const clock_t&)=delete;
		clock_t(clock_t&&)=delete;
		clock_t& operator=(const clock_t&)=delete;
		clock_t& operator=(clock_t&&)=delete;
		
		// Clock APIs
		bool startBlocking()_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_clock_t_startBlocking(&obj);
		}
		bool startBusy()_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_clock_t_startBusy(&obj);
		}
		void stop()_SHINSEI_OS_NOEXCEPT{
			::shinsei_clock_t_stop(&obj);
			return;
		}
		bool running()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_clock_t_running(&obj);
		}
		
		bool getUSMode()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_clock_t_getUSMode(&obj);
		}
		void setUSMode(const bool us_mode)_SHINSEI_OS_NOEXCEPT{
			::shinsei_clock_t_setUSMode(&obj,us_mode);
			return;
		}
		uint_fast64_t getCycle()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_clock_t_getCycle(&obj);
		}
		void setCycle(const uint_fast64_t cycle)_SHINSEI_OS_NOEXCEPT{
			::shinsei_clock_t_setCycle(&obj,cycle);
			return;
		}
		void* getArg()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_clock_t_getArg(&obj);
		}
		void setArg(void*const arg)_SHINSEI_OS_NOEXCEPT{
			::shinsei_clock_t_setArg(&obj,arg);
			return;
		}
		clock_callback_t* getCallback()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_clock_t_getCallback(&obj);
		}
		void setCallback(clock_callback_t*const cb,void*const arg=nullptr)_SHINSEI_OS_NOEXCEPT{
			::shinsei_clock_t_setCallback(&obj,cb,arg);
			return;
		}
		
		// Static Helpers
		static void as(clock_t*const restrict ptr,const uint_fast64_t cycle,const bool us_mode,clock_callback_t*const cb,void*const arg=nullptr){
			if(!::shinsei_clock_t_as(ptr->cObj(),cycle,us_mode,cb,arg)) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_clock_t*const restrict ptr,const uint_fast64_t cycle,const bool us_mode,clock_callback_t*const cb,void*const arg=nullptr){
			if(!::shinsei_clock_t_as(ptr,cycle,us_mode,cb,arg)) throw std::bad_alloc();
			return;
		}
		static void inl(clock_t*const restrict ptr,const uint_fast64_t cycle,const bool us_mode,clock_callback_t*const cb,void*const arg=nullptr){
			if(!::shinsei_clock_t_inl(ptr->cObj(),cycle,us_mode,cb,arg)) throw std::bad_alloc();
			return;
		}
		static void inl(::shinsei_clock_t*const restrict ptr,const uint_fast64_t cycle,const bool us_mode,clock_callback_t*const cb,void*const arg=nullptr){
			if(!::shinsei_clock_t_inl(ptr,cycle,us_mode,cb,arg)) throw std::bad_alloc();
			return;
		}
		
		// Core Identity Controls
		bool inlined()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_clock_t_inlined(&obj);
		}
		int_fast32_t getCtrl()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_clock_t_getCtrl(&obj);
		}
		void setCtrl(const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
			::shinsei_clock_t_setCtrl(&obj,ctrl);
			return;
		}
		
		// Type Casting / Access
		::shinsei_clock_t* cObj()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		const ::shinsei_clock_t* cObj()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator ::shinsei_clock_t*()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator const ::shinsei_clock_t*()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
	};
	
	class thread_t{
	private:
		::shinsei_thread_t obj;
	
	public:
		// Default constructor
		thread_t(thread_callback_t*const cb,void*const arg=nullptr,void*const ret=nullptr){
			if(!::shinsei_thread_t_as(&obj,cb,arg,ret)) throw std::bad_alloc();
			return;
		}
		
		// In-place Constructors
		explicit thread_t(shinsei::in_place_t,thread_callback_t*const cb,void*const arg=nullptr,void*const ret=nullptr){
			if(!::shinsei_thread_t_as(&obj,cb,arg,ret)) throw std::bad_alloc();
			return;
		}
		
		// Inlined Constructors
		explicit thread_t(shinsei::inlined_t,thread_callback_t*const cb,void*const arg=nullptr,void*const ret=nullptr){
			if(!::shinsei_thread_t_inl(&obj,cb,arg,ret)) throw std::bad_alloc();
			return;
		}
		
		// Destructor
		~thread_t()_SHINSEI_OS_NOEXCEPT{
			if(!inlined()) ::shinsei_thread_t_freeData(&obj);
			return;
		}
		
		// Disable Copy & Move
		thread_t(const thread_t&)=delete;
		thread_t(thread_t&&)=delete;
		thread_t& operator=(const thread_t&)=delete;
		thread_t& operator=(thread_t&&)=delete;
		
		// Thread APIs
		bool start()_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_thread_t_start(&obj);
		}
		void stop()_SHINSEI_OS_NOEXCEPT{
			::shinsei_thread_t_stop(&obj);
			return;
		}
		bool running()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_thread_t_running(&obj);
		}
		void* join()_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_thread_t_join(&obj);
		}
		void forceTerminate()_SHINSEI_OS_NOEXCEPT{
			::shinsei_thread_t_forceTerminate(&obj);
			return;
		}
		
		thread_callback_t* getCallback()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_thread_t_getCallback(&obj);
		}
		void* getArg()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_thread_t_getArg(&obj);
		}
		void setArg(void*const arg)_SHINSEI_OS_NOEXCEPT{
			::shinsei_thread_t_setArg(&obj,arg);
			return;
		}
		void* getRet()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_thread_t_getRet(&obj);
		}
		void setRet(void*const ret)_SHINSEI_OS_NOEXCEPT{
			::shinsei_thread_t_setRet(&obj,ret);
			return;
		}
		void setCallback(thread_callback_t*const cb,void*const arg=nullptr)_SHINSEI_OS_NOEXCEPT{
			::shinsei_thread_t_setCallback(&obj,cb,arg);
			return;
		}
		
		// Static Helpers
		static void as(thread_t*const restrict ptr,thread_callback_t*const cb,void*const arg=nullptr,void*const ret=nullptr){
			if(!::shinsei_thread_t_as(ptr->cObj(),cb,arg,ret)) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_thread_t*const restrict ptr,thread_callback_t*const cb,void*const arg=nullptr,void*const ret=nullptr){
			if(!::shinsei_thread_t_as(ptr,cb,arg,ret)) throw std::bad_alloc();
			return;
		}
		static void inl(thread_t*const restrict ptr,thread_callback_t*const cb,void*const arg=nullptr,void*const ret=nullptr){
			if(!::shinsei_thread_t_inl(ptr->cObj(),cb,arg,ret)) throw std::bad_alloc();
			return;
		}
		static void inl(::shinsei_thread_t*const restrict ptr,thread_callback_t*const cb,void*const arg=nullptr,void*const ret=nullptr){
			if(!::shinsei_thread_t_inl(ptr,cb,arg,ret)) throw std::bad_alloc();
			return;
		}
		
		// Core Identity Controls
		bool inlined()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_thread_t_inlined(&obj);
		}
		int_fast32_t getCtrl()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_thread_t_getCtrl(&obj);
		}
		void setCtrl(const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
			::shinsei_thread_t_setCtrl(&obj,ctrl);
			return;
		}
		
		// Type Casting / Access
		::shinsei_thread_t* cObj()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		const ::shinsei_thread_t* cObj()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator ::shinsei_thread_t*()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator const ::shinsei_thread_t*()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
	};
}
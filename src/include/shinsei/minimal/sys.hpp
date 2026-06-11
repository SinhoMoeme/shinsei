#pragma once

#include"shinsei/minimal/sys.h"
#include"shinsei/.internal/tag.hpp"
#include<new>

namespace shinsei{
	
	class arena_meta_t{
	private:
		::shinsei_arena_meta_t obj;
	public:
		// Constructors
		arena_meta_t(const size_t size=0,const bool used=false)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_as(&obj,size,used);
			return;
		}
		arena_meta_t(const arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_asAssign(&obj,src.cObj());
			return;
		}
		arena_meta_t(const ::shinsei_arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_asAssign(&obj,&src);
			return;
		}
		arena_meta_t(arena_meta_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_asMove(&obj,src.cObj());
			return;
		}
		arena_meta_t(::shinsei_arena_meta_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_asMove(&obj,&src);
			return;
		}
		
		// In-place constructors
		explicit arena_meta_t(shinsei::in_place_t,const size_t size=0,const bool used=false)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_as(&obj,size,used);
			return;
		}
		explicit arena_meta_t(shinsei::in_place_t,const arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_asAssign(&obj,src.cObj());
			return;
		}
		explicit arena_meta_t(shinsei::in_place_t,const ::shinsei_arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_asAssign(&obj,&src);
			return;
		}
		explicit arena_meta_t(shinsei::in_place_t,arena_meta_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_asMove(&obj,src.cObj());
			return;
		}
		explicit arena_meta_t(shinsei::in_place_t,::shinsei_arena_meta_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_asMove(&obj,&src);
			return;
		}
		
		// Inlined constructors
		explicit arena_meta_t(shinsei::inlined_t,const size_t size=0,const bool used=false)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_inl(&obj,size,used);
			return;
		}
		explicit arena_meta_t(shinsei::inlined_t,const arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_inlAssign(&obj,src.cObj());
			return;
		}
		explicit arena_meta_t(shinsei::inlined_t,const ::shinsei_arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_inlAssign(&obj,&src);
			return;
		}
		explicit arena_meta_t(shinsei::inlined_t,arena_meta_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_inlMove(&obj,src.cObj());
			return;
		}
		explicit arena_meta_t(shinsei::inlined_t,::shinsei_arena_meta_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_inlMove(&obj,&src);
			return;
		}
		
		// Destructor
		~arena_meta_t()_SHINSEI_OS_NOEXCEPT{
			return;
		}
		
		// Assignment / move
		void assign(const arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_assign(&obj,src.cObj());
			return;
		}
		void assign(const ::shinsei_arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_assign(&obj,&src);
			return;
		}
		arena_meta_t& operator=(const arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			if(this==&src) return *this;
			::shinsei_arena_meta_t_assign(&obj,src.cObj());
			return *this;
		}
		arena_meta_t& operator=(const ::shinsei_arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_assign(&obj,&src);
			return *this;
		}
		
		void move(arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_move(&obj,src.cObj());
			return;
		}
		void move(::shinsei_arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_move(&obj,&src);
			return;
		}
		arena_meta_t& operator=(arena_meta_t&& src)_SHINSEI_OS_NOEXCEPT{
			if(this==&src) return *this;
			::shinsei_arena_meta_t_move(&obj,src.cObj());
			return *this;
		}
		arena_meta_t& operator=(::shinsei_arena_meta_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_move(&obj,&src);
			return *this;
		}
		
		// Attach
		void attach(const arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_attach(&obj,src.cObj());
			return;
		}
		void attach(const ::shinsei_arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_attach(&obj,&src);
			return;
		}
		void attach(const int_fast32_t ctrl,const size_t size,const bool used)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_attachValue(&obj,ctrl,size,used);
			return;
		}
		
		// Static helpers
		static void as(arena_meta_t*const restrict ptr,const size_t size=0,const bool used=false)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_as(ptr->cObj(),size,used);
			return;
		}
		static void as(::shinsei_arena_meta_t*const restrict ptr,const size_t size=0,const bool used=false)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_as(ptr,size,used);
			return;
		}
		static void as(arena_meta_t*const restrict ptr,const arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_asAssign(ptr->cObj(),src.cObj());
			return;
		}
		static void as(arena_meta_t*const restrict ptr,const ::shinsei_arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_asAssign(ptr->cObj(),&src);
			return;
		}
		static void as(arena_meta_t*const restrict ptr,arena_meta_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_asMove(ptr->cObj(),src.cObj());
			return;
		}
		static void as(arena_meta_t*const restrict ptr,::shinsei_arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_asMove(ptr->cObj(),&src);
			return;
		}
		
		static void inl(arena_meta_t*const restrict ptr,const size_t size=0,const bool used=false)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_inl(ptr->cObj(),size,used);
			return;
		}
		static void inl(::shinsei_arena_meta_t*const restrict ptr,const size_t size=0,const bool used=false)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_inl(ptr,size,used);
			return;
		}
		static void inl(arena_meta_t*const restrict ptr,const arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_inlAssign(ptr->cObj(),src.cObj());
			return;
		}
		static void inl(arena_meta_t*const restrict ptr,const ::shinsei_arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_inlAssign(ptr->cObj(),&src);
			return;
		}
		static void inl(arena_meta_t*const restrict ptr,arena_meta_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_inlMove(ptr->cObj(),src.cObj());
			return;
		}
		static void inl(arena_meta_t*const restrict ptr,::shinsei_arena_meta_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_inlMove(ptr->cObj(),&src);
			return;
		}
		
		// Core identity controls
		bool inlined()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_meta_t_inlined(&obj);
		}
		int_fast32_t getCtrl()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_meta_t_getCtrl(&obj);
		}
		void setCtrl(const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_setCtrl(&obj,ctrl);
			return;
		}
		
		// Meta specific
		size_t getSize()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_meta_t_getSize(&obj);
		}
		void setSize(const size_t size)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_setSize(&obj,size);
			return;
		}
		bool getUsed()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_meta_t_getUsed(&obj);
		}
		void setUsed(const bool used)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_meta_t_setUsed(&obj,used);
			return;
		}
		
		// Type casting / access
		::shinsei_arena_meta_t* cObj()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		const ::shinsei_arena_meta_t* cObj()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator ::shinsei_arena_meta_t*()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator const ::shinsei_arena_meta_t*()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
	};
	
	class arena_t{
	private:
		::shinsei_arena_t obj;
	public:
		static _SHINSEI_OS_CONSTEXPR size_t DEF_CAP=::shinsei_arena_t_DEF_CAP;
		static _SHINSEI_OS_CONSTEXPR size_t BYTE_ALIGNMENT=::shinsei_arena_t_BYTE_ALIGNMENT;
		
		// Default constructor
		arena_t(const size_t cap=DEF_CAP){
			if(!::shinsei_arena_t_as(&obj,cap)) throw std::bad_alloc();
			return;
		}
		
		// In-place constructors
		explicit arena_t(shinsei::in_place_t,const size_t cap=DEF_CAP){
			if(!::shinsei_arena_t_as(&obj,cap)) throw std::bad_alloc();
			return;
		}
		
		// Inlined constructors
		explicit arena_t(shinsei::inlined_t,const size_t cap=DEF_CAP)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_t_inl(&obj,cap);
			return;
		}
		
		// Freedata
		void freeData()_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_t_freeData(&obj);
			return;
		}
		
		// Destructor
		~arena_t()_SHINSEI_OS_NOEXCEPT{
			if(!inlined()) ::shinsei_arena_t_freeData(&obj);
			return;
		}
		
		// Disable copy / move
		arena_t(const arena_t&)=delete;
		arena_t(arena_t&&)=delete;
		arena_t& operator=(const arena_t&)=delete;
		arena_t& operator=(arena_t&&)=delete;
		
		// Arena specific
		void* allocBack(const size_t needed_cap){
			void* ptr=::shinsei_arena_t_allocBack(&obj,needed_cap);
			if(!ptr) throw std::bad_alloc();
			return ptr;
		}
		void* allocFront(const size_t needed_cap){
			void* ptr=::shinsei_arena_t_allocFront(&obj,needed_cap);
			if(!ptr) throw std::bad_alloc();
			return ptr;
		}
		void freeBack()_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_t_freeBack(&obj);
			return;
		}
		void freeFront()_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_t_freeFront(&obj);
			return;
		}
		size_t refCount()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_t_refCount(&obj);
		}
		bool empty()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_t_empty(&obj);
		}
		size_t minSpaceCapacity()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_t_minSpaceCapacity(&obj);
		}
		size_t maxSpaceCapacity()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_t_maxSpaceCapacity(&obj);
		}
		void clear()_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_t_clear(&obj);
			return;
		}
		
		// Static helpers
		static bool as(arena_t*const restrict ptr,const size_t cap=DEF_CAP)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_t_as(ptr->cObj(),cap);
		}
		static bool as(::shinsei_arena_t*const restrict ptr,const size_t cap=DEF_CAP)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_t_as(ptr,cap);
		}
		
		static void inl(arena_t*const restrict ptr,const size_t cap=DEF_CAP)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_t_inl(ptr->cObj(),cap);
			return;
		}
		static void inl(::shinsei_arena_t*const restrict ptr,const size_t cap=DEF_CAP)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_t_inl(ptr,cap);
			return;
		}
		
		// Core identity controls
		bool inlined()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_t_inlined(&obj);
		}
		int_fast32_t getCtrl()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_t_getCtrl(&obj);
		}
		void setCtrl(const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_t_setCtrl(&obj,ctrl);
			return;
		}
		
		// Type casting / access
		::shinsei_arena_t* cObj()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		const ::shinsei_arena_t* cObj()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator ::shinsei_arena_t*()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator const ::shinsei_arena_t*()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
	};
	
	class arena_custom_t{
	private:
		::shinsei_arena_custom_t obj;
	public:
		static _SHINSEI_OS_CONSTEXPR size_t DEF_CAP=::shinsei_arena_custom_t_DEF_CAP;
		static _SHINSEI_OS_CONSTEXPR size_t BYTE_ALIGNMENT=::shinsei_arena_custom_t_BYTE_ALIGNMENT;
		
		// Default constructor
		arena_custom_t(shinsei::allocate_callback_t allocate_callback,shinsei::free_callback_t free_callback,const size_t cap=DEF_CAP){
			if(!::shinsei_arena_custom_t_as(&obj,cap,allocate_callback,free_callback)) throw std::bad_alloc();
			return;
		}
		
		// In-place constructors
		explicit arena_custom_t(shinsei::in_place_t,shinsei::allocate_callback_t allocate_callback,shinsei::free_callback_t free_callback,const size_t cap=DEF_CAP){
			if(!::shinsei_arena_custom_t_as(&obj,cap,allocate_callback,free_callback)) throw std::bad_alloc();
			return;
		}
		
		// Inlined constructors
		explicit arena_custom_t(shinsei::inlined_t,shinsei::allocate_callback_t allocate_callback,shinsei::free_callback_t free_callback,const size_t cap=DEF_CAP)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_custom_t_inl(&obj,cap,allocate_callback,free_callback);
			return;
		}
		
		// Destructor
		~arena_custom_t()_SHINSEI_OS_NOEXCEPT{
			if(!inlined()) ::shinsei_arena_custom_t_freeData(&obj);
			return;
		}
		
		// Disable copy / move
		arena_custom_t(const arena_custom_t&)=delete;
		arena_custom_t(arena_custom_t&&)=delete;
		arena_custom_t& operator=(const arena_custom_t&)=delete;
		arena_custom_t& operator=(arena_custom_t&&)=delete;
		
		// Arena specific
		void* allocBack(const size_t needed_cap){
			void* ptr=::shinsei_arena_custom_t_allocBack(&obj,needed_cap);
			if(!ptr) throw std::bad_alloc();
			return ptr;
		}
		void* allocFront(const size_t needed_cap){
			void* ptr=::shinsei_arena_custom_t_allocFront(&obj,needed_cap);
			if(!ptr) throw std::bad_alloc();
			return ptr;
		}
		void freeBack()_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_custom_t_freeBack(&obj);
			return;
		}
		void freeFront()_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_custom_t_freeFront(&obj);
			return;
		}
		size_t refCount()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_custom_t_refCount(&obj);
		}
		bool empty()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_custom_t_empty(&obj);
		}
		size_t minSpaceCapacity()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_custom_t_minSpaceCapacity(&obj);
		}
		size_t maxSpaceCapacity()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_custom_t_maxSpaceCapacity(&obj);
		}
		void clear()_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_custom_t_clear(&obj);
			return;
		}
		
		// Callback
		shinsei::allocate_callback_t getAllocateCallback()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_custom_t_getAllocateCallback(&obj);
		}
		void setAllocateCallback(shinsei::allocate_callback_t cb)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_custom_t_setAllocateCallback(&obj,cb);
			return;
		}
		shinsei::free_callback_t getFreeCallback()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_custom_t_getFreeCallback(&obj);
		}
		void setFreeCallback(shinsei::free_callback_t cb)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_custom_t_setFreeCallback(&obj,cb);
			return;
		}
		
		// Static helpers
		static bool as(arena_custom_t* const restrict ptr,shinsei::allocate_callback_t alloc_cb,shinsei::free_callback_t free_cb,const size_t cap=DEF_CAP)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_custom_t_as(ptr->cObj(),cap,alloc_cb,free_cb);
		}
		static bool as(::shinsei_arena_custom_t* const restrict ptr,shinsei::allocate_callback_t alloc_cb,shinsei::free_callback_t free_cb,const size_t cap=DEF_CAP)_SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_custom_t_as(ptr,cap,alloc_cb,free_cb);
		}
		
		static void inl(arena_custom_t* const restrict ptr,shinsei::allocate_callback_t alloc_cb,shinsei::free_callback_t free_cb,const size_t cap=DEF_CAP)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_custom_t_inl(ptr->cObj(),cap,alloc_cb,free_cb);
			return;
		}
		static void inl(::shinsei_arena_custom_t* const restrict ptr,shinsei::allocate_callback_t alloc_cb,shinsei::free_callback_t free_cb,const size_t cap=DEF_CAP)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_custom_t_inl(ptr,cap,alloc_cb,free_cb);
			return;
		}
		
		// Core identity controls
		bool inlined()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_custom_t_inlined(&obj);
		}
		int_fast32_t getCtrl()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_arena_custom_t_getCtrl(&obj);
		}
		void setCtrl(const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
			::shinsei_arena_custom_t_setCtrl(&obj,ctrl);
			return;
		}
		
		// Type casting / access
		::shinsei_arena_custom_t* cObj()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		const ::shinsei_arena_custom_t* cObj()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator ::shinsei_arena_custom_t*()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator const ::shinsei_arena_custom_t*()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
	};
	
	class spinlock_t{
	private:
		::shinsei_spinlock_t obj;
	public:
		// Default constructor
		explicit spinlock_t(const bool instant_lock=false)_SHINSEI_OS_NOEXCEPT{
			::shinsei_spinlock_t_as(&obj,instant_lock);
			return;
		}
		
		// Destructor
		~spinlock_t()_SHINSEI_OS_NOEXCEPT{
			if(locked()) unlock();
			return;
		}
		
		// [Const] Check if the lock is using
		bool locked()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_spinlock_t_locked(&obj);
		}
		
		// Lock
		void lock()_SHINSEI_OS_NOEXCEPT{
			::shinsei_spinlock_t_lock(&obj);
			return;
		}
		
		// Unlock
		void unlock()_SHINSEI_OS_NOEXCEPT{
			::shinsei_spinlock_t_unlock(&obj);
			return;
		}
		
		// Static in-place constructor helpers
		static void as(spinlock_t*const restrict ptr,const bool instant_lock=false)_SHINSEI_OS_NOEXCEPT{
			::shinsei_spinlock_t_as(ptr->cObj(),instant_lock);
			return;
		}
		static void as(::shinsei_spinlock_t*const restrict ptr,const bool instant_lock=false)_SHINSEI_OS_NOEXCEPT{
			::shinsei_spinlock_t_as(ptr,instant_lock);
			return;
		}
		
		// In-place tag dispatcher
		explicit spinlock_t(shinsei::in_place_t,const bool instant_lock=false)_SHINSEI_OS_NOEXCEPT{
			::shinsei_spinlock_t_as(&obj,instant_lock);
			return;
		}
		
		// Static inline constructor helpers
		static void inl(spinlock_t*const restrict ptr,const bool instant_lock=false)_SHINSEI_OS_NOEXCEPT{
			::shinsei_spinlock_t_inl(ptr->cObj(),instant_lock);
			return;
		}
		static void inl(::shinsei_spinlock_t*const restrict ptr,const bool instant_lock=false)_SHINSEI_OS_NOEXCEPT{
			::shinsei_spinlock_t_inl(ptr,instant_lock);
			return;
		}
		
		// Inlined tag dispatcher
		explicit spinlock_t(shinsei::inlined_t,const bool instant_lock=false)_SHINSEI_OS_NOEXCEPT{
			::shinsei_spinlock_t_inl(&obj,instant_lock);
			return;
		}
		
		// [const] Check if elements are inlined
		bool inlined()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_spinlock_t_inlined(&obj);
		}
		
		// [Const] Get the ctrl code
		int_fast32_t getCtrl()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_spinlock_t_getCtrl(&obj);
		}
		
		// Set the ctrl code
		void setCtrl(const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
			::shinsei_spinlock_t_setCtrl(&obj,ctrl);
			return;
		}
		
		// [Const] C Object
		::shinsei_spinlock_t* cObj()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		const ::shinsei_spinlock_t* cObj()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		
		// Type casting
		operator ::shinsei_spinlock_t*()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator const ::shinsei_spinlock_t*()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		
		// Disable copy and move
		spinlock_t(const spinlock_t&)=delete;
		spinlock_t& operator=(const spinlock_t&)=delete;
		spinlock_t(spinlock_t&&)=delete;
		spinlock_t& operator=(spinlock_t&&)=delete;
	};
}
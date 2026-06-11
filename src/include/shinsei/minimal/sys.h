#pragma once

#include"shinsei/.internal/usage.h"
#include<stdbool.h>
#include<stdint.h>
#ifdef _SHINSEI_OS_MSVC
	#include<stdlib.h>
#endif

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

#ifdef _SHINSEI_OS_CONSTEXPR
	static _SHINSEI_OS_CONSTEXPR size_t shinsei_arena_t_DEF_CAP=(size_t)1<<20;
	#if(_SHINSEI_OS_BITS==8)
		static _SHINSEI_OS_CONSTEXPR size_t shinsei_arena_t_BYTE_ALIGNMENT=2;
	#else
		static _SHINSEI_OS_CONSTEXPR size_t shinsei_arena_t_BYTE_ALIGNMENT=_SHINSEI_OS_BYTE_ALIGNMENT;
	#endif
	static _SHINSEI_OS_CONSTEXPR size_t shinsei_arena_custom_t_DEF_CAP=shinsei_arena_t_DEF_CAP;
	static _SHINSEI_OS_CONSTEXPR size_t shinsei_arena_custom_t_BYTE_ALIGNMENT=shinsei_arena_t_BYTE_ALIGNMENT;
#else 
	#define shinsei_arena_t_DEF_CAP ((size_t)1<<20)
	#if(_SHINSEI_OS_BITS==8)
		#define shinsei_arena_t_BYTE_ALIGNMENT 2
	#else
		#define shinsei_arena_t_BYTE_ALIGNMENT _SHINSEI_OS_BYTE_ALIGNMENT
	#endif
	#define shinsei_arena_custom_t_DEF_CAP shinsei_arena_t_DEF_CAP
	#define shinsei_arena_custom_t_BYTE_ALIGNMENT shinsei_arena_t_BYTE_ALIGNMENT
#endif

typedef struct _SHINSEI_OS_ALIGN_BYTE{
	int_fast32_t ctrl;
	size_t size_and_used; // Size of current memory block (metadata + content). Last bit: if the memory block is used.
}
shinsei_arena_meta_t;

typedef struct _shinsei_arena_t shinsei_arena_t;
typedef struct _SHINSEI_OS_ALIGN_BYTE _shinsei_arena_t{
	int_fast32_t ctrl;
	size_t cap; // Size of data (all metadatas + all contents)
	size_t ref_count; // Count of allocated block
	size_t head; // Position of first element in chars
	size_t tail; // Postiion of last element in chars
	size_t min_space_cap; // Minimum empty block capacity of the part
	size_t max_space_cap; // Maximum empty block capacity of the part
	shinsei_arena_t* next; // Next part of arena
	shinsei_arena_t* last_part; // Last part of arena
	char* data; // Metadatas + contents
}
shinsei_arena_t;

typedef struct _shinsei_arena_custom_t shinsei_arena_custom_t;
typedef struct _SHINSEI_OS_ALIGN_BYTE _shinsei_arena_custom_t{
	int_fast32_t ctrl;
	size_t cap; // Size of data (all metadatas + all contents)
	size_t ref_count; // Count of allocated block
	size_t head; // Position of first element in chars
	size_t tail; // Postiion of last element in chars
	size_t min_space_cap; // Minimum empty block capacity of the part
	size_t max_space_cap; // Maximum empty block capacity of the part
	shinsei_arena_custom_t* next; // Next part of arena
	shinsei_arena_custom_t* last_part; // Last part of arena
	shinsei_allocate_callback_t allocate_callback; // Custom allocate callback
	shinsei_free_callback_t free_callback; // Custom free callback
	char* data; // Metadatas + contents
}
shinsei_arena_custom_t;

typedef struct _SHINSEI_OS_ALIGN_BYTE{
	int_fast32_t ctrl;
	bool lock_status;
	volatile int_fast32_t flag;
}shinsei_spinlock_t;

// arena_meta_t
_SHINSEI_LIB_API shinsei_arena_meta_t* shinsei_arena_meta_t_con(const size_t size,const bool used)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_arena_meta_t* shinsei_arena_meta_t_conAssign(const shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_arena_meta_t* shinsei_arena_meta_t_conMove(shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_arena_meta_t_dec(shinsei_arena_meta_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_arena_meta_t_assign(shinsei_arena_meta_t*const restrict this,const shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_meta_t_move(shinsei_arena_meta_t*const restrict this,shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_arena_meta_t_attach(shinsei_arena_meta_t*const restrict this,const shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_meta_t_attachValue(shinsei_arena_meta_t*const restrict this,const int_fast32_t ctrl,const size_t size,const bool used)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_arena_meta_t_as(shinsei_arena_meta_t*const restrict this,const size_t size,const bool used)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_meta_t_asAssign(shinsei_arena_meta_t*const restrict this,const shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_meta_t_asMove(shinsei_arena_meta_t*const restrict this,shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_arena_meta_t_inl(shinsei_arena_meta_t*const restrict this,const size_t size,const bool used)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_meta_t_inlAssign(shinsei_arena_meta_t*const restrict this,const shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_meta_t_inlMove(shinsei_arena_meta_t*const restrict this,shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_arena_meta_t_inlined(const shinsei_arena_meta_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_arena_meta_t_getCtrl(const shinsei_arena_meta_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_meta_t_setCtrl(shinsei_arena_meta_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_arena_meta_t_getSize(const shinsei_arena_meta_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_meta_t_setSize(shinsei_arena_meta_t*const restrict this,const size_t size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_arena_meta_t_getUsed(const shinsei_arena_meta_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_meta_t_setUsed(shinsei_arena_meta_t*const restrict this,const bool used)_SHINSEI_OS_NOEXCEPT;

// arena_t
_SHINSEI_LIB_API shinsei_arena_t* shinsei_arena_t_con(const size_t cap)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_arena_t_freeData(shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_t_dec(shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_arena_t_as(shinsei_arena_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_t_inl(shinsei_arena_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void* shinsei_arena_t_allocBack(shinsei_arena_t*const restrict this,const size_t needed_cap)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void* shinsei_arena_t_allocFront(shinsei_arena_t*const restrict this,const size_t needed_cap)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_t_freeBack(shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_t_freeFront(shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_arena_t_refCount(const shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_arena_t_empty(const shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_arena_t_minSpaceCapacity(const shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_arena_t_maxSpaceCapacity(const shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_t_clear(shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_arena_t_inlined(const shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_arena_t_getCtrl(const shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_t_setCtrl(shinsei_arena_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT;

// arena_custom_t
_SHINSEI_LIB_API shinsei_arena_custom_t* shinsei_arena_custom_t_con(const size_t cap,shinsei_allocate_callback_t allocate_callback,shinsei_free_callback_t free_callback)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_arena_custom_t_freeData(shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_custom_t_dec(shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_arena_custom_t_as(shinsei_arena_custom_t*const restrict this,const size_t cap,shinsei_allocate_callback_t allocate_callback,shinsei_free_callback_t free_callback)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_custom_t_inl(shinsei_arena_custom_t*const restrict this,const size_t cap,shinsei_allocate_callback_t allocate_callback,shinsei_free_callback_t free_callback)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void* shinsei_arena_custom_t_allocBack(shinsei_arena_custom_t*const restrict this,const size_t needed_cap)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void* shinsei_arena_custom_t_allocFront(shinsei_arena_custom_t*const restrict this,const size_t needed_cap)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_custom_t_freeBack(shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_custom_t_freeFront(shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API size_t shinsei_arena_custom_t_refCount(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_arena_custom_t_empty(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_arena_custom_t_minSpaceCapacity(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_arena_custom_t_maxSpaceCapacity(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_custom_t_clear(shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_arena_custom_t_inlined(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_arena_custom_t_getCtrl(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_custom_t_setCtrl(shinsei_arena_custom_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API shinsei_allocate_callback_t shinsei_arena_custom_t_getAllocateCallback(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_custom_t_setAllocateCallback(shinsei_arena_custom_t*const restrict this,shinsei_allocate_callback_t allocate_callback)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_free_callback_t shinsei_arena_custom_t_getFreeCallback(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_arena_custom_t_setFreeCallback(shinsei_arena_custom_t*const restrict this,shinsei_free_callback_t free_callback)_SHINSEI_OS_NOEXCEPT;

// Default constructor
_SHINSEI_LIB_API shinsei_spinlock_t* shinsei_spinlock_t_con(const bool instant_lock)_SHINSEI_OS_NOEXCEPT;

// Destructor
_SHINSEI_LIB_API void shinsei_spinlock_t_dec(shinsei_spinlock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// [Const] Check if the lock is using
_SHINSEI_LIB_API bool shinsei_spinlock_t_locked(const shinsei_spinlock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// Lock
_SHINSEI_LIB_API void shinsei_spinlock_t_lock(shinsei_spinlock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// Unlock
_SHINSEI_LIB_API void shinsei_spinlock_t_unlock(shinsei_spinlock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// Static default constructor
_SHINSEI_LIB_API void shinsei_spinlock_t_as(shinsei_spinlock_t*const restrict this,const bool instant_lock)_SHINSEI_OS_NOEXCEPT;

// Inline default constructor
_SHINSEI_LIB_API void shinsei_spinlock_t_inl(shinsei_spinlock_t*const restrict this,const bool instant_lock)_SHINSEI_OS_NOEXCEPT;

// [const] Check if elements are inlined
_SHINSEI_LIB_API bool shinsei_spinlock_t_inlined(const shinsei_spinlock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// [Const] Get the ctrl code
_SHINSEI_LIB_API int_fast32_t shinsei_spinlock_t_getCtrl(const shinsei_spinlock_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// Set the ctrl code
_SHINSEI_LIB_API void shinsei_spinlock_t_setCtrl(shinsei_spinlock_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT;

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif
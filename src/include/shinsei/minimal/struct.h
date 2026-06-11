#pragma once

#include"shinsei/.internal/usage.h"

#include<stdint.h>
#if defined(_SHINSEI_OS_MSVC)
	#include<string.h>
	#include<stdlib.h>
#endif

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

#ifdef _SHINSEI_OS_CONSTEXPR
	static _SHINSEI_OS_CONSTEXPR size_t shinsei_stack_t_DEF_CAP=8;
	static _SHINSEI_OS_CONSTEXPR size_t shinsei_queue_t_DEF_CAP=8;
	static _SHINSEI_OS_CONSTEXPR size_t shinsei_deque_t_DEF_CAP=8;
	static _SHINSEI_OS_CONSTEXPR size_t shinsei_vector_t_DEF_CAP=8;
#else 
	#define shinsei_stack_t_DEF_CAP (size_t)8
	#define shinsei_queue_t_DEF_CAP (size_t)8
	#define shinsei_deque_t_DEF_CAP (size_t)8
	#define shinsei_vector_t_DEF_CAP (size_t)8
#endif

typedef struct _SHINSEI_OS_ALIGN_BYTE{
	int_fast32_t ctrl;
	shinsei_allocate_assign_callback_t allocate_callback;
	shinsei_free_callback_t free_callback;
}shinsei_object_definition_t;

typedef struct _SHINSEI_OS_ALIGN_BYTE{
	int_fast32_t ctrl;
	const void* val;
	shinsei_object_definition_t definition;
}shinsei_object_t;

typedef struct _SHINSEI_OS_ALIGN_BYTE{
	int_fast32_t ctrl;
	size_t size;
	size_t cap;
	size_t element_size;
	char* data;
}shinsei_stack_t;

typedef struct _SHINSEI_OS_ALIGN_BYTE{
	int_fast32_t ctrl;
	size_t head;
	size_t tail;
	size_t cap;
	size_t element_size;
	char* data;
}shinsei_queue_t;

typedef struct _SHINSEI_OS_ALIGN_BYTE{
	int_fast32_t ctrl;
	size_t head;
	size_t tail;
	size_t cap;
	size_t element_size;
	char* data;
}shinsei_deque_t;

typedef struct _SHINSEI_OS_ALIGN_BYTE{
	int_fast32_t ctrl;
	size_t size;
	size_t cap;
	size_t element_size;
	char* data;
}shinsei_vector_t;

// object_definition_t
_SHINSEI_LIB_API shinsei_object_definition_t* shinsei_object_definition_t_con(shinsei_allocate_assign_callback_t allocate_callback,shinsei_free_callback_t free_callback)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_object_definition_t* shinsei_object_definition_t_conAssign(const shinsei_object_definition_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_object_definition_t* shinsei_object_definition_t_conMove(shinsei_object_definition_t* const restrict src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_object_definition_t_dec(shinsei_object_definition_t *const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_object_definition_t_hasAllocateCallback(const shinsei_object_definition_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_object_definition_t_hasFreeCallback(const shinsei_object_definition_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_object_definition_t_swap(shinsei_object_definition_t*const restrict this,shinsei_object_definition_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_definition_t_assign(shinsei_object_definition_t*const restrict this,const shinsei_object_definition_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_definition_t_move(shinsei_object_definition_t*const restrict this,shinsei_object_definition_t* const restrict src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_object_definition_t_attach(shinsei_object_definition_t*const restrict this,const shinsei_object_definition_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_definition_t_attachValue(shinsei_object_definition_t*const restrict this,const int_fast32_t ctrl,shinsei_allocate_assign_callback_t allocate_callback,shinsei_free_callback_t free_callback)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_object_definition_t_as(shinsei_object_definition_t*const restrict this,shinsei_allocate_assign_callback_t allocate_callback,shinsei_free_callback_t free_callback)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_definition_t_asAssign(shinsei_object_definition_t*const restrict this,const shinsei_object_definition_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_definition_t_asMove(shinsei_object_definition_t*const restrict this,shinsei_object_definition_t* const restrict src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_object_definition_t_inl(shinsei_object_definition_t*const restrict this,shinsei_allocate_assign_callback_t allocate_callback,shinsei_free_callback_t free_callback)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_definition_t_inlAssign(shinsei_object_definition_t*const restrict this,const shinsei_object_definition_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_definition_t_inlMove(shinsei_object_definition_t*const restrict this,shinsei_object_definition_t* const restrict src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_object_definition_t_inlined(const shinsei_object_definition_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_object_definition_t_getCtrl(const shinsei_object_definition_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_definition_t_setCtrl(shinsei_object_definition_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT;


// object_t
_SHINSEI_LIB_API shinsei_object_t* shinsei_object_t_con(const void *const val,shinsei_object_definition_t definition)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_object_t* shinsei_object_t_conAssign(const shinsei_object_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_object_t* shinsei_object_t_conMove(shinsei_object_t* const restrict src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_object_t_dec(shinsei_object_t *const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_object_t_hasAllocateCallback(const shinsei_object_t *const this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_object_t_hasFreeCallback(const shinsei_object_t *const this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_object_t_isNullptr(const shinsei_object_t *const this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API const void* shinsei_object_t_value(const shinsei_object_t *const this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_object_definition_t shinsei_object_t_getDefinition(const shinsei_object_t *const this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_object_t_alloc(shinsei_object_t *const this,const void *const val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_t_free(shinsei_object_t *const this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_t_setDefinition(shinsei_object_t *const this,shinsei_object_definition_t definition)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_object_t_swap(shinsei_object_t*const restrict this,shinsei_object_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_t_assign(shinsei_object_t*const restrict this,const shinsei_object_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_t_move(shinsei_object_t*const restrict this,shinsei_object_t* const restrict src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_object_t_attach(shinsei_object_t*const restrict this,const shinsei_object_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_t_attachValue(shinsei_object_t*const restrict this,const int_fast32_t ctrl,const void *const val,shinsei_object_definition_t definition)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_object_t_freeData(shinsei_object_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_object_t_as(shinsei_object_t*const restrict this,const void *const val,shinsei_object_definition_t definition)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_t_asAssign(shinsei_object_t*const restrict this,const shinsei_object_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_t_asMove(shinsei_object_t*const restrict this,shinsei_object_t* const restrict src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_object_t_inl(shinsei_object_t*const restrict this,const void *const val,shinsei_object_definition_t definition)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_t_inlAssign(shinsei_object_t*const restrict this,const shinsei_object_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_t_inlMove(shinsei_object_t*const restrict this,shinsei_object_t* const restrict src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_object_t_inlined(const shinsei_object_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_object_t_getCtrl(const shinsei_object_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_object_t_setCtrl(shinsei_object_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT;

// stack_t
_SHINSEI_LIB_API shinsei_stack_t* shinsei_stack_t_con(const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_stack_t* shinsei_stack_t_conCapacity(const size_t cap,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_stack_t* shinsei_stack_t_conAssign(const shinsei_stack_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_stack_t* shinsei_stack_t_conMove(shinsei_stack_t* const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_stack_t* shinsei_stack_t_conElement(const void*const restrict val,const size_t cnt,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_stack_t* shinsei_stack_t_conArray(const void*const restrict arr,const size_t len,const size_t element_size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_stack_t_dec(shinsei_stack_t *const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_stack_t_expand(shinsei_stack_t*const restrict this,const size_t more_cap)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_stack_t_shrink(shinsei_stack_t*const restrict this,const size_t less_cap)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_stack_t_reserve(shinsei_stack_t* const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_stack_t_shrinkToFit(shinsei_stack_t* const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_stack_t_empty(const shinsei_stack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_stack_t_size(const shinsei_stack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_stack_t_capacity(const shinsei_stack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void* shinsei_stack_t_top(const shinsei_stack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void* shinsei_stack_t_at(const shinsei_stack_t*const restrict this,const size_t idx)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void* shinsei_stack_t_data(const shinsei_stack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_stack_t_pop(shinsei_stack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_stack_t_popArray(shinsei_stack_t*const restrict this,const size_t cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_stack_t_push(shinsei_stack_t*const restrict this,const void*const restrict val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_stack_t_pushArray(shinsei_stack_t*const restrict this,const void*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_stack_t_pushElement(shinsei_stack_t*const restrict this,const void*const restrict val,const size_t cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_stack_t_swap(shinsei_stack_t*const restrict this,shinsei_stack_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_stack_t_clear(shinsei_stack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_stack_t_setSize(shinsei_stack_t*const restrict this,const size_t size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_stack_t_assign(shinsei_stack_t*const restrict this,const shinsei_stack_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_stack_t_move(shinsei_stack_t*const restrict this,shinsei_stack_t* const restrict src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_stack_t_attach(shinsei_stack_t*const restrict this,const shinsei_stack_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_stack_t_attachValue(shinsei_stack_t*const restrict this,const int_fast32_t ctrl,const size_t size,const size_t cap,void*const ptr,const size_t element_size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_stack_t_freeData(shinsei_stack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_stack_t_as(shinsei_stack_t*const restrict this,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_stack_t_asCapacity(shinsei_stack_t*const restrict this,const size_t cap,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_stack_t_asAssign(shinsei_stack_t*const restrict this,const shinsei_stack_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_stack_t_asMove(shinsei_stack_t*const restrict this,shinsei_stack_t* const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_stack_t_asElement(shinsei_stack_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_stack_t_asArray(shinsei_stack_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_stack_t_inl(shinsei_stack_t*const restrict this,const size_t cap,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_stack_t_inlCapacity(shinsei_stack_t*const restrict this,const size_t cap,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_stack_t_inlAssign(shinsei_stack_t*const restrict this,const shinsei_stack_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_stack_t_inlMove(shinsei_stack_t*const restrict this,shinsei_stack_t* const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_stack_t_inlElement(shinsei_stack_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_stack_t_inlArray(shinsei_stack_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_stack_t_inlined(const shinsei_stack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_stack_t_getCtrl(const shinsei_stack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_stack_t_setCtrl(shinsei_stack_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT;

// queue_t
_SHINSEI_LIB_API shinsei_queue_t* shinsei_queue_t_con(const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_queue_t* shinsei_queue_t_conCapacity(const size_t cap,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_queue_t* shinsei_queue_t_conAssign(const shinsei_queue_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_queue_t* shinsei_queue_t_conMove(shinsei_queue_t* const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_queue_t* shinsei_queue_t_conElement(const void*const restrict val,const size_t cnt,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_queue_t* shinsei_queue_t_conArray(const void*const restrict arr,const size_t len,const size_t element_size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_queue_t_dec(shinsei_queue_t *const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_queue_t_expand(shinsei_queue_t*const restrict this,const size_t more_cap)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_queue_t_shrink(shinsei_queue_t*const restrict this,const size_t less_cap)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_queue_t_reserve(shinsei_queue_t* const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_queue_t_shrinkToFit(shinsei_queue_t* const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_queue_t_empty(const shinsei_queue_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_queue_t_size(const shinsei_queue_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_queue_t_capacity(const shinsei_queue_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void* shinsei_queue_t_front(const shinsei_queue_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void* shinsei_queue_t_back(const shinsei_queue_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void* shinsei_queue_t_at(const shinsei_queue_t*const restrict this,const size_t idx)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void* shinsei_queue_t_data(const shinsei_queue_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_queue_t_pop(shinsei_queue_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_queue_t_popArray(shinsei_queue_t*const restrict this,const size_t cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_queue_t_push(shinsei_queue_t*const restrict this,const void*const restrict val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_queue_t_pushArray(shinsei_queue_t*const restrict this,const void*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_queue_t_pushElement(shinsei_queue_t*const restrict this,const void*const restrict val,const size_t cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_queue_t_swap(shinsei_queue_t*const restrict this,shinsei_queue_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_queue_t_clear(shinsei_queue_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_queue_t_setSize(shinsei_queue_t*const restrict this,const size_t size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_queue_t_assign(shinsei_queue_t*const restrict this,const shinsei_queue_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_queue_t_move(shinsei_queue_t*const restrict this,shinsei_queue_t* const restrict src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_queue_t_attach(shinsei_queue_t*const restrict this,const shinsei_queue_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_queue_t_attachValue(shinsei_queue_t*const restrict this,const int_fast32_t ctrl,const size_t head,const size_t tail,const size_t cap,void*const ptr,const size_t element_size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_queue_t_freeData(shinsei_queue_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_queue_t_as(shinsei_queue_t*const restrict this,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_queue_t_asCapacity(shinsei_queue_t*const restrict this,const size_t cap,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_queue_t_asAssign(shinsei_queue_t*const restrict this,const shinsei_queue_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_queue_t_asMove(shinsei_queue_t*const restrict this,shinsei_queue_t* const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_queue_t_asElement(shinsei_queue_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_queue_t_asArray(shinsei_queue_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_queue_t_inl(shinsei_queue_t*const restrict this,const size_t cap,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_queue_t_inlCapacity(shinsei_queue_t*const restrict this,const size_t cap,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_queue_t_inlAssign(shinsei_queue_t*const restrict this,const shinsei_queue_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_queue_t_inlMove(shinsei_queue_t*const restrict this,shinsei_queue_t* const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_queue_t_inlElement(shinsei_queue_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_queue_t_inlArray(shinsei_queue_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_queue_t_inlined(const shinsei_queue_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_queue_t_getCtrl(const shinsei_queue_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_queue_t_setCtrl(shinsei_queue_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT;

// deque_t
_SHINSEI_LIB_API shinsei_deque_t* shinsei_deque_t_con(const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_deque_t* shinsei_deque_t_conCapacity(const size_t cap,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_deque_t* shinsei_deque_t_conAssign(const shinsei_deque_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_deque_t* shinsei_deque_t_conMove(shinsei_deque_t* const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_deque_t* shinsei_deque_t_conElement(const void*const restrict val,const size_t cnt,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_deque_t* shinsei_deque_t_conArray(const void*const restrict arr,const size_t len,const size_t element_size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_deque_t_dec(shinsei_deque_t *const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_deque_t_expand(shinsei_deque_t*const restrict this,const size_t more_cap)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_deque_t_shrink(shinsei_deque_t*const restrict this,const size_t less_cap)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_deque_t_reserve(shinsei_deque_t* const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_deque_t_shrinkToFit(shinsei_deque_t* const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_deque_t_empty(const shinsei_deque_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_deque_t_size(const shinsei_deque_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_deque_t_capacity(const shinsei_deque_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void* shinsei_deque_t_front(const shinsei_deque_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void* shinsei_deque_t_back(const shinsei_deque_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void* shinsei_deque_t_at(const shinsei_deque_t*const restrict this,const size_t idx)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void* shinsei_deque_t_data(const shinsei_deque_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_deque_t_popFront(shinsei_deque_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_deque_t_popFrontArray(shinsei_deque_t*const restrict this,const size_t cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_deque_t_popBack(shinsei_deque_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_deque_t_popBackArray(shinsei_deque_t*const restrict this,const size_t cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_deque_t_pushFront(shinsei_deque_t*const restrict this,const void*const restrict val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_deque_t_pushFrontArray(shinsei_deque_t*const restrict this,const void*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_deque_t_pushFrontElement(shinsei_deque_t*const restrict this,const void*const restrict val,const size_t cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_deque_t_pushBack(shinsei_deque_t*const restrict this,const void*const restrict val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_deque_t_pushBackArray(shinsei_deque_t*const restrict this,const void*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_deque_t_pushBackElement(shinsei_deque_t*const restrict this,const void*const restrict val,const size_t cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_deque_t_swap(shinsei_deque_t*const restrict this,shinsei_deque_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_deque_t_clear(shinsei_deque_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_deque_t_setSize(shinsei_deque_t*const restrict this,const size_t size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_deque_t_assign(shinsei_deque_t*const restrict this,const shinsei_deque_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_deque_t_move(shinsei_deque_t*const restrict this,shinsei_deque_t* const restrict src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_deque_t_attach(shinsei_deque_t*const restrict this,const shinsei_deque_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_deque_t_attachValue(shinsei_deque_t*const restrict this,const int_fast32_t ctrl,const size_t head,const size_t tail,const size_t cap,void*const ptr,const size_t element_size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_deque_t_freeData(shinsei_deque_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_deque_t_as(shinsei_deque_t*const restrict this,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_deque_t_asCapacity(shinsei_deque_t*const restrict this,const size_t cap,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_deque_t_asAssign(shinsei_deque_t*const restrict this,const shinsei_deque_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_deque_t_asMove(shinsei_deque_t*const restrict this,shinsei_deque_t* const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_deque_t_asElement(shinsei_deque_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_deque_t_asArray(shinsei_deque_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_deque_t_inl(shinsei_deque_t*const restrict this,const size_t cap,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_deque_t_inlCapacity(shinsei_deque_t*const restrict this,const size_t cap,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_deque_t_inlAssign(shinsei_deque_t*const restrict this,const shinsei_deque_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_deque_t_inlMove(shinsei_deque_t*const restrict this,shinsei_deque_t* const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_deque_t_inlElement(shinsei_deque_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_deque_t_inlArray(shinsei_deque_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_deque_t_inlined(const shinsei_deque_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_deque_t_getCtrl(const shinsei_deque_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_deque_t_setCtrl(shinsei_deque_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT;

// vector_t
_SHINSEI_LIB_API shinsei_vector_t* shinsei_vector_t_con(const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_vector_t* shinsei_vector_t_conCapacity(const size_t cap,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_vector_t* shinsei_vector_t_conAssign(const shinsei_vector_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_vector_t* shinsei_vector_t_conMove(shinsei_vector_t* const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_vector_t* shinsei_vector_t_conElement(const void*const restrict val,const size_t cnt,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_vector_t* shinsei_vector_t_conArray(const void*const restrict arr,const size_t len,const size_t element_size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_vector_t_dec(shinsei_vector_t *const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_vector_t_expand(shinsei_vector_t*const restrict this,const size_t more_cap)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_vector_t_shrink(shinsei_vector_t*const restrict this,const size_t less_cap)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_vector_t_reserve(shinsei_vector_t* const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_vector_t_shrinkToFit(shinsei_vector_t* const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_vector_t_empty(const shinsei_vector_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_vector_t_size(const shinsei_vector_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API size_t shinsei_vector_t_capacity(const shinsei_vector_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void* shinsei_vector_t_at(const shinsei_vector_t*const restrict this,const size_t idx)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void* shinsei_vector_t_data(const shinsei_vector_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_vector_t_popBack(shinsei_vector_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_vector_t_popBackArray(shinsei_vector_t*const restrict this,const size_t cnt)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_vector_t_pushBack(shinsei_vector_t*const restrict this,const void*const restrict val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_vector_t_pushBackArray(shinsei_vector_t*const restrict this,const void*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_vector_t_pushBackElement(shinsei_vector_t*const restrict this,const void*const restrict val,const size_t cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_vector_t_erase(shinsei_vector_t*const restrict this,const size_t idx)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_vector_t_eraseArray(shinsei_vector_t*const restrict this,const size_t idx,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_vector_t_insert(shinsei_vector_t*const restrict this,const size_t idx,const void*const restrict val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_vector_t_insertArray(shinsei_vector_t*const restrict this,const size_t idx,const void*const restrict src,const size_t len)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_vector_t_insertElement(shinsei_vector_t*const restrict this,const size_t idx,const void*const restrict val,const size_t cnt)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_vector_t_swap(shinsei_vector_t*const restrict this,shinsei_vector_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_vector_t_clear(shinsei_vector_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_vector_t_setSize(shinsei_vector_t*const restrict this,const size_t size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_vector_t_assign(shinsei_vector_t*const restrict this,const shinsei_vector_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_vector_t_move(shinsei_vector_t*const restrict this,shinsei_vector_t* const restrict src)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_vector_t_attach(shinsei_vector_t*const restrict this,const shinsei_vector_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_vector_t_attachValue(shinsei_vector_t*const restrict this,const int_fast32_t ctrl,const size_t size,const size_t cap,void*const ptr,const size_t element_size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_vector_t_freeData(shinsei_vector_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_vector_t_as(shinsei_vector_t*const restrict this,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_vector_t_asCapacity(shinsei_vector_t*const restrict this,const size_t cap,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_vector_t_asAssign(shinsei_vector_t*const restrict this,const shinsei_vector_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_vector_t_asMove(shinsei_vector_t*const restrict this,shinsei_vector_t* const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_vector_t_asElement(shinsei_vector_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_vector_t_asArray(shinsei_vector_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API void shinsei_vector_t_inl(shinsei_vector_t*const restrict this,const size_t cap,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_vector_t_inlCapacity(shinsei_vector_t*const restrict this,const size_t cap,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_vector_t_inlAssign(shinsei_vector_t*const restrict this,const shinsei_vector_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_vector_t_inlMove(shinsei_vector_t*const restrict this,shinsei_vector_t* const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_vector_t_inlElement(shinsei_vector_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_vector_t_inlArray(shinsei_vector_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size)_SHINSEI_OS_NOEXCEPT;

_SHINSEI_LIB_API bool shinsei_vector_t_inlined(const shinsei_vector_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API int_fast32_t shinsei_vector_t_getCtrl(const shinsei_vector_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_vector_t_setCtrl(shinsei_vector_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT;

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif
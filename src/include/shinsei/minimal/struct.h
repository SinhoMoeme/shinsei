#pragma once

#include"shinsei/.internal/usage.h"

#include<stdint.h>
#include<stdlib.h>
#if defined(_SHINSEI_OS_MSVC)
	#include<string.h>
#endif

typedef void (*shinsei_deallocator_t)(void*);

typedef struct{
	const void* val;
	shinsei_deallocator_t deallocator;
}shinsei_object_t;

typedef struct{
	size_t obj_size;
	size_t size;
	size_t cap;
	void* data;
}shinsei_stack_t;

#ifdef _SHINSEI_OS_CPP
extern "C" {
#endif

// object_t
_SHINSEI_LIB_API shinsei_object_t* shinsei_object_t_con(const void *const val,shinsei_deallocator_t deallocator);

_SHINSEI_LIB_API void shinsei_object_t_dec(shinsei_object_t *const obj);

_SHINSEI_LIB_API bool shinsei_object_t_isLegal(const shinsei_object_t *const obj);

_SHINSEI_LIB_API bool shinsei_object_t_isNullptr(const shinsei_object_t *const obj);

_SHINSEI_LIB_API const void* shinsei_object_t_value(const shinsei_object_t *const obj);

_SHINSEI_LIB_API shinsei_deallocator_t shinsei_object_t_getDeallocator(const shinsei_object_t *const obj);

_SHINSEI_LIB_API void shinsei_object_t_alloc(shinsei_object_t *const obj,const void *const val);

_SHINSEI_LIB_API bool shinsei_object_t_free(shinsei_object_t *const obj);

_SHINSEI_LIB_API void shinsei_object_t_setDeallocator(shinsei_object_t *const obj,shinsei_deallocator_t deallocator);

// stack_t
_SHINSEI_LIB_API shinsei_stack_t* shinsei_stack_t_con();
_SHINSEI_LIB_API shinsei_stack_t* shinsei_stack_t_conAssign();
_SHINSEI_LIB_API void shinsei_stack_t_dec();


#ifdef _SHINSEI_OS_CPP
}
#endif
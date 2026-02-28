#pragma once

#include"shinsei/.internal/os.h"
#include"shinsei/.internal/usage.h"

#include<stdlib.h>
#include<string.h>

typedef void (*shinsei_deallocator_t)(const void *const);

typedef struct{
	const void* val;
	shinsei_deallocator_t deallocator;
}shinsei_object_t;

#ifdef __cplusplus
extern "C" {
#endif

shinsei_object_t* shinsei_object_t_con(const void *const val,shinsei_deallocator_t deallocator);

_SHINSEI_LIB_API void shinsei_object_t_dec(shinsei_object_t *const obj);

_SHINSEI_LIB_API bool shinsei_object_t_isLegal(const shinsei_object_t *const obj);

_SHINSEI_LIB_API bool shinsei_object_t_isNullptr(const shinsei_object_t *const obj);

_SHINSEI_LIB_API const void* shinsei_object_t_value(const shinsei_object_t *const obj);

_SHINSEI_LIB_API shinsei_deallocator_t shinsei_object_t_getDeallocator(const shinsei_object_t *const obj);

_SHINSEI_LIB_API void shinsei_object_t_alloc(shinsei_object_t *const obj,const void *const val);

_SHINSEI_LIB_API bool shinsei_object_t_free(shinsei_object_t *const obj);

_SHINSEI_LIB_API void shinsei_object_t_setDeallocator(shinsei_object_t *const obj,shinsei_deallocator_t deallocator);

#ifdef __cplusplus
}
#endif
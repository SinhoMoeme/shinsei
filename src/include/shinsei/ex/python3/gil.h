#pragma once

#define HAVE_SSIZE_T 1
#include"python3/Python.h"

typedef struct{
	bool used;
	char __padding[3];
	PyGILState_STATE g_state;
}shinsei_ex_gil_guard_t;

#ifdef _SHINSEI_OS_CPP
extern "C"{
#endif

// Default constructor
_SHINSEI_LIB_API shinsei_ex_gil_guard_t* shinsei_ex_gil_guard_t_con(const bool instant_alloc);

// Destructor
_SHINSEI_LIB_API void shinsei_ex_gil_guard_t_dec(shinsei_ex_gil_guard_t*const restrict this);

// [Const] Check if the GIL is using
_SHINSEI_LIB_API bool shinsei_ex_gil_guard_t_isUsing(const shinsei_ex_gil_guard_t*const restrict this);

// Allocate the GIL
_SHINSEI_LIB_API void shinsei_ex_gil_guard_t_alloc(shinsei_ex_gil_guard_t*const restrict this);

// Free the GIL
_SHINSEI_LIB_API void shinsei_ex_gil_guard_t_free(shinsei_ex_gil_guard_t*const restrict this);

// Static default constructor
_SHINSEI_LIB_API void shinsei_ex_gil_guard_t_as(shinsei_ex_gil_guard_t*const restrict this,const bool instant_alloc);

// Inline default constructor
_SHINSEI_LIB_API void shinsei_ex_gil_guard_t_inl(shinsei_ex_gil_guard_t*const restrict this,const bool instant_alloc);

#ifdef _SHINSEI_OS_CPP
}
#endif
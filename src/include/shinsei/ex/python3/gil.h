#pragma once

#define HAVE_SSIZE_T 1
#include"python3/Python.h"

#ifdef _SHINSEI_OS_CPP
extern "C"{
#endif

typedef struct _SHINSEI_OS_ALIGN_BYTE{
	int_fast32_t ctrl;
	bool used;
	PyGILState_STATE g_state;
}shinsei_ex_gil_guard_t;

// Default constructor
_SHINSEI_LIB_API shinsei_ex_gil_guard_t* shinsei_ex_gil_guard_t_con(const bool instant_alloc)_SHINSEI_OS_NOEXCEPT;

// Destructor
_SHINSEI_LIB_API void shinsei_ex_gil_guard_t_dec(shinsei_ex_gil_guard_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// [Const] Check if the GIL is using
_SHINSEI_LIB_API bool shinsei_ex_gil_guard_t_isUsing(const shinsei_ex_gil_guard_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// Allocate the GIL
_SHINSEI_LIB_API void shinsei_ex_gil_guard_t_alloc(shinsei_ex_gil_guard_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// Free the GIL
_SHINSEI_LIB_API void shinsei_ex_gil_guard_t_free(shinsei_ex_gil_guard_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// Static default constructor
_SHINSEI_LIB_API void shinsei_ex_gil_guard_t_as(shinsei_ex_gil_guard_t*const restrict this,const bool instant_alloc)_SHINSEI_OS_NOEXCEPT;

// Inline default constructor
_SHINSEI_LIB_API void shinsei_ex_gil_guard_t_inl(shinsei_ex_gil_guard_t*const restrict this,const bool instant_alloc)_SHINSEI_OS_NOEXCEPT;

// [const] Check if elements are inlined
_SHINSEI_LIB_API bool shinsei_ex_gil_guard_t_inlined(const shinsei_ex_gil_guard_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// [Const] Get the ctrl code
_SHINSEI_LIB_API int_fast32_t shinsei_ex_gil_guard_t_getCtrl(const shinsei_ex_gil_guard_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// Set the ctrl code
_SHINSEI_LIB_API void shinsei_ex_gil_guard_t_setCtrl(shinsei_ex_gil_guard_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT;

#ifdef _SHINSEI_OS_CPP
}
#endif
#pragma once

#include"shinsei/struct.h"
#define HAVE_SSIZE_T 1
#include"python3/Python.h"

#ifdef _SHINSEI_OS_CONSTEXPR
	static _SHINSEI_OS_CONSTEXPR size_t SHINSEI_EX_PYSTACK_T_DEF_CAP=8;
#else
	#define SHINSEI_EX_PYSTACK_T_DEF_CAP (size_t)8
#endif

typedef struct{
	PyObject** data;
	size_t size;
	size_t cap;
}pystack_t;

#ifdef _SHINSEI_OS_CPP
extern "C" {
#endif

_SHINSEI_LIB_API pystack_t* shinsei_ex_pystack_t_con();
_SHINSEI_LIB_API pystack_t* shinsei_ex_pystack_t_conAssign(PyObject **const restrict data,const size_t size,const size_t cap);

_SHINSEI_LIB_API void shinsei_ex_pystack_t_dec(pystack_t *const restrict this);

_SHINSEI_LIB_API bool shinsei_ex_pystack_t_expand(pystack_t*const restrict this,const size_t more_cap);

_SHINSEI_LIB_API bool shinsei_ex_pystack_t_shrink(pystack_t*const restrict this,const size_t less_cap);

_SHINSEI_LIB_API PyObject* shinsei_ex_pystack_t_top(const pystack_t*const restrict this);

_SHINSEI_LIB_API bool shinsei_ex_pystack_t_empty(const pystack_t*const restrict this);

_SHINSEI_LIB_API size_t shinsei_ex_pystack_t_size(const pystack_t*const restrict this);

_SHINSEI_LIB_API void shinsei_ex_pystack_t_pop(pystack_t*const restrict this);
                                                        
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_push(pystack_t*const restrict this,const PyObject*const val);

_SHINSEI_LIB_API void shinsei_ex_pystack_t_swap(pystack_t*const restrict this,pystack_t*const restrict src);

_SHINSEI_LIB_API void shinsei_ex_pystack_t_clear(pystack_t*const restrict this);

#ifdef _SHINSEI_OS_CPP
}
#endif
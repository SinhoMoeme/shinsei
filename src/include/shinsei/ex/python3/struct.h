#pragma once

#include"shinsei/struct.h"
#define HAVE_SSIZE_T 1
#include"python3/Python.h"

#ifdef _SHINSEI_OS_CONSTEXPR
	static _SHINSEI_OS_CONSTEXPR size_t shinsei_ex_pystack_t_DEF_CAP=8;
#else
	#define shinsei_ex_pystack_t_DEF_CAP (size_t)8
#endif

typedef struct{
	int_fast32_t ctrl;
	size_t size;
	size_t cap;
	PyObject** data;
}shinsei_ex_pystack_t;

#ifdef _SHINSEI_OS_CPP
extern "C" {
#endif

// Default constructor
_SHINSEI_LIB_API shinsei_ex_pystack_t* shinsei_ex_pystack_t_con();
// Copy constructor
_SHINSEI_LIB_API shinsei_ex_pystack_t* shinsei_ex_pystack_t_conAssign(const shinsei_ex_pystack_t*const restrict src);
// Move constructor
_SHINSEI_LIB_API shinsei_ex_pystack_t* shinsei_ex_pystack_t_conMove(shinsei_ex_pystack_t** const restrict src);

// Destructor
_SHINSEI_LIB_API void shinsei_ex_pystack_t_dec(shinsei_ex_pystack_t *const restrict this);

// Expand capacity by more_cap
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_expand(shinsei_ex_pystack_t*const restrict this,const size_t more_cap);

// Shrink capacity by less_cap
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_shrink(shinsei_ex_pystack_t*const restrict this,const size_t less_cap);

// Reserve for the elements
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_reserve(shinsei_ex_pystack_t* const restrict this,const size_t cap);

// Shrink capacity to fit
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_shrinkToFit(shinsei_ex_pystack_t* const restrict this);

// [Const] Check if stack is empty
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_empty(const shinsei_ex_pystack_t*const restrict this);

// [Const] Get stack size
_SHINSEI_LIB_API size_t shinsei_ex_pystack_t_size(const shinsei_ex_pystack_t*const restrict this);

// [Const] Get stack capacity
_SHINSEI_LIB_API size_t shinsei_ex_pystack_t_capacity(const shinsei_ex_pystack_t*const restrict this);

// [Const] Get the top element
_SHINSEI_LIB_API PyObject* shinsei_ex_pystack_t_top(const shinsei_ex_pystack_t*const restrict this);

// [Const] Get the element at idx
_SHINSEI_LIB_API PyObject* shinsei_ex_pystack_t_at(const shinsei_ex_pystack_t*const restrict this,const size_t idx);

// [Const] Get the element data
_SHINSEI_LIB_API PyObject** shinsei_ex_pystack_t_data(const shinsei_ex_pystack_t*const restrict this);

// Pop the top element
_SHINSEI_LIB_API void shinsei_ex_pystack_t_pop(shinsei_ex_pystack_t*const restrict this);
            
// Push an element to the top			
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_push(shinsei_ex_pystack_t*const restrict this,const PyObject*const restrict val);

// Swap 2 stacks
_SHINSEI_LIB_API void shinsei_ex_pystack_t_swap(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t*const restrict src);

// Clear all elements
_SHINSEI_LIB_API void shinsei_ex_pystack_t_clear(shinsei_ex_pystack_t*const restrict this);

// Set stack size
_SHINSEI_LIB_API void shinsei_ex_pystack_t_setSize(shinsei_ex_pystack_t*const restrict this,const size_t size);

// Assign the stack and all elements
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_assign(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src);

// Move the ownership to another stack
_SHINSEI_LIB_API void shinsei_ex_pystack_t_move(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t* const restrict src);

// Attach the stack from another one
_SHINSEI_LIB_API void shinsei_ex_pystack_t_attach(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src);
_SHINSEI_LIB_API void shinsei_ex_pystack_t_attachValue(shinsei_ex_pystack_t*const restrict this,const int_fast32_t ctrl,const size_t size,const size_t cap,PyObject** data);

// Free all elements
_SHINSEI_LIB_API void shinsei_ex_pystack_t_freeData(shinsei_ex_pystack_t*const restrict this);

// Static default constructor
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_as(shinsei_ex_pystack_t*const restrict this);
// Static copy constructor
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_asAssign(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src);
// Static move constructor
_SHINSEI_LIB_API void shinsei_ex_pystack_t_asMove(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t* const restrict src);

#ifdef _SHINSEI_OS_CPP
}
#endif
#pragma once

#include"shinsei/struct.h"
#include"shinsei/ex/python3/gil.h"

#ifdef _SHINSEI_OS_CPP
extern "C" {
#endif

#ifdef _SHINSEI_OS_CONSTEXPR
	static _SHINSEI_OS_CONSTEXPR size_t shinsei_ex_pystack_t_DEF_CAP=8;
#else
	#define shinsei_ex_pystack_t_DEF_CAP (size_t)8
#endif

typedef struct _SHINSEI_OS_ALIGN_BYTE{
	int_fast32_t ctrl;
	size_t size;
	size_t cap;
	PyObject** data;
}shinsei_ex_pystack_t;

// Default constructor
_SHINSEI_LIB_API shinsei_ex_pystack_t* shinsei_ex_pystack_t_con()_SHINSEI_OS_NOEXCEPT;
// Capacity constructor
_SHINSEI_LIB_API shinsei_ex_pystack_t* shinsei_ex_pystack_t_conCapacity(const size_t cap)_SHINSEI_OS_NOEXCEPT;
// Copy constructors
_SHINSEI_LIB_API shinsei_ex_pystack_t* shinsei_ex_pystack_t_conCopy(const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API shinsei_ex_pystack_t* shinsei_ex_pystack_t_conCopyUnsafe(const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
// Move constructor
_SHINSEI_LIB_API shinsei_ex_pystack_t* shinsei_ex_pystack_t_conMove(shinsei_ex_pystack_t* const restrict src)_SHINSEI_OS_NOEXCEPT;

// Destructor
_SHINSEI_LIB_API void shinsei_ex_pystack_t_dec(shinsei_ex_pystack_t *const restrict this)_SHINSEI_OS_NOEXCEPT;

// Expand capacity by more_cap
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_expand(shinsei_ex_pystack_t*const restrict this,const size_t more_cap)_SHINSEI_OS_NOEXCEPT;

// Shrink capacity by less_cap
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_shrink(shinsei_ex_pystack_t*const restrict this,const size_t less_cap)_SHINSEI_OS_NOEXCEPT;

// Reserve for the elements
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_reserve(shinsei_ex_pystack_t* const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT;

// Shrink capacity to fit
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_shrinkToFit(shinsei_ex_pystack_t* const restrict this)_SHINSEI_OS_NOEXCEPT;

// [Const] Check if stack is empty
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_empty(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// [Const] Get stack size
_SHINSEI_LIB_API size_t shinsei_ex_pystack_t_size(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// [Const] Get stack capacity
_SHINSEI_LIB_API size_t shinsei_ex_pystack_t_capacity(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// [Const] Get the top element
_SHINSEI_LIB_API PyObject* shinsei_ex_pystack_t_top(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API PyObject* shinsei_ex_pystack_t_topUnsafe(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// [Const] Get the element at idx
_SHINSEI_LIB_API PyObject* shinsei_ex_pystack_t_at(const shinsei_ex_pystack_t*const restrict this,const size_t idx)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API PyObject* shinsei_ex_pystack_t_atUnsafe(const shinsei_ex_pystack_t*const restrict this,const size_t idx)_SHINSEI_OS_NOEXCEPT;

// [Const] Get the element data
_SHINSEI_LIB_API PyObject** shinsei_ex_pystack_t_data(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// Pop the top element
_SHINSEI_LIB_API void shinsei_ex_pystack_t_pop(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_ex_pystack_t_popUnsafe(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// Push an element to the top
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_push(shinsei_ex_pystack_t*const restrict this,const PyObject*const restrict val)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_pushUnsafe(shinsei_ex_pystack_t*const restrict this,const PyObject*const restrict val)_SHINSEI_OS_NOEXCEPT;

// Swap 2 stacks
_SHINSEI_LIB_API void shinsei_ex_pystack_t_swap(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT;

// Clear all elements
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_clear(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_clearUnsafe(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// Set stack size
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_setSize(shinsei_ex_pystack_t*const restrict this,const size_t size)_SHINSEI_OS_NOEXCEPT;

// Assign the stack and all elements
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_assign(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_assignUnsafe(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT;

// Move the ownership to another stack
_SHINSEI_LIB_API void shinsei_ex_pystack_t_move(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t* const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_ex_pystack_t_moveUnsafe(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t* const restrict src)_SHINSEI_OS_NOEXCEPT;

// Attach the stack from another one
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_attach(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_attachUnsafe(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_attachValue(shinsei_ex_pystack_t*const restrict this,const int_fast32_t ctrl,const size_t size,const size_t cap,PyObject**const ptr)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_attachValueUnsafe(shinsei_ex_pystack_t*const restrict this,const int_fast32_t ctrl,const size_t size,const size_t cap,PyObject**const ptr)_SHINSEI_OS_NOEXCEPT;

// Free all elements
_SHINSEI_LIB_API void shinsei_ex_pystack_t_freeData(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API void shinsei_ex_pystack_t_freeDataUnsafe(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// Static default constructor
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_as(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;
// Static capacity constructor
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_asCapacity(shinsei_ex_pystack_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT;
// Static copy constructors
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_asCopy(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_asCopyUnsafe(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT;

// Static move constructor
_SHINSEI_LIB_API void shinsei_ex_pystack_t_asMove(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t* const restrict src)_SHINSEI_OS_NOEXCEPT;

// Inline default constructor
_SHINSEI_LIB_API void shinsei_ex_pystack_t_inl(shinsei_ex_pystack_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT;
// Inline capacity constructor
_SHINSEI_LIB_API void shinsei_ex_pystack_t_inlCapacity(shinsei_ex_pystack_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT;
// Inline copy constructors
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_inlCopy(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_inlCopyUnsafe(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT;
// Inline move constructor
_SHINSEI_LIB_API void shinsei_ex_pystack_t_inlMove(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t* const restrict src)_SHINSEI_OS_NOEXCEPT;

// [const] Check if elements are inlined
_SHINSEI_LIB_API bool shinsei_ex_pystack_t_inlined(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// [Const] Get the ctrl code
_SHINSEI_LIB_API int_fast32_t shinsei_ex_pystack_t_getCtrl(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT;

// Set the ctrl code
_SHINSEI_LIB_API void shinsei_ex_pystack_t_setCtrl(shinsei_ex_pystack_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT;

#ifdef _SHINSEI_OS_CPP
}
#endif
#include"shinsei/.internal/usage.h"
#include"shinsei/ex/python3/gil.h"

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

// [Internal, const] Check if elements are gil_inlined
_SHINSEI_OS_INLINE static bool gil_inlined(const shinsei_ex_gil_guard_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}

// [Internal] Allocate the GIL
_SHINSEI_OS_INLINE static void gil_alloc(shinsei_ex_gil_guard_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	this->g_state=PyGILState_Ensure();
	return;
}

// [Internal] Free the GIL
_SHINSEI_OS_INLINE static void gil_free(shinsei_ex_gil_guard_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	PyGILState_Release(this->g_state);
	return;
}

// [Internal] Default constructor
_SHINSEI_OS_INLINE static void gil_as(shinsei_ex_gil_guard_t*const restrict this,const bool instant_alloc,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=ctrl;
	if(instant_alloc){
		this->used=true;
		gil_alloc(this);
	}
	else this->used=false;
	return;
}

// Default constructor
shinsei_ex_gil_guard_t* shinsei_ex_gil_guard_t_con(const bool instant_alloc)_SHINSEI_OS_NOEXCEPT{
	shinsei_ex_gil_guard_t*const this=(shinsei_ex_gil_guard_t*)__builtin_malloc(sizeof(shinsei_ex_gil_guard_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	gil_as(this,instant_alloc,0);
	return this;
}

// Destructor
void shinsei_ex_gil_guard_t_dec(shinsei_ex_gil_guard_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(this->used) gil_free(this);
	__builtin_free(this);
	return;
}

// [Const] Check if the GIL is using
bool shinsei_ex_gil_guard_t_isUsing(const shinsei_ex_gil_guard_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->used;
}

// Allocate the GIL
void shinsei_ex_gil_guard_t_alloc(shinsei_ex_gil_guard_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	this->used=true;
	gil_alloc(this);
	return;
}

// Free the GIL
void shinsei_ex_gil_guard_t_free(shinsei_ex_gil_guard_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	this->used=false;
	gil_free(this);
	return;
}

// Static default constructor
void shinsei_ex_gil_guard_t_as(shinsei_ex_gil_guard_t*const restrict this,const bool instant_alloc)_SHINSEI_OS_NOEXCEPT{
	gil_as(this,instant_alloc,0);
	return;
}

// Inline default constructor
void shinsei_ex_gil_guard_t_inl(shinsei_ex_gil_guard_t*const restrict this,const bool instant_alloc)_SHINSEI_OS_NOEXCEPT{
	gil_as(this,instant_alloc,_SHINSEI_CTRL_INLINED);
	return;
}

// [const] Check if elements are gil_inlined
bool shinsei_ex_gil_guard_t_inlined(const shinsei_ex_gil_guard_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return gil_inlined(this);
}

// [Const] Get the ctrl code
int_fast32_t shinsei_ex_gil_guard_t_getCtrl(const shinsei_ex_gil_guard_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl;
}
// Set the ctrl code
void shinsei_ex_gil_guard_t_setCtrl(shinsei_ex_gil_guard_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=ctrl;
	return;
}

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif
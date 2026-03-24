#include"shinsei/.internal/usage.h"
#include"shinsei/ex/python3/gil.h"

// [Internal] Allocate the GIL
_SHINSEI_OS_INLINE static void gilAlloc(shinsei_ex_gil_guard_t*const restrict this){
	this->g_state=PyGILState_Ensure();
	return;
}

// [Internal] Free the GIL
_SHINSEI_OS_INLINE static void gilFree(shinsei_ex_gil_guard_t*const restrict this){
	PyGILState_Release(this->g_state);
	return;
}

// [Internal] Default constructor
_SHINSEI_OS_INLINE static void con(shinsei_ex_gil_guard_t*const restrict this,const bool instant_alloc){
	if(instant_alloc){
		this->used=true;
		gilAlloc(this);
	}
	else this->used=false;
	return;
}

// Default constructor
shinsei_ex_gil_guard_t* shinsei_ex_gil_guard_t_con(const bool instant_alloc){
	shinsei_ex_gil_guard_t*const this=(shinsei_ex_gil_guard_t*)malloc(sizeof(shinsei_ex_gil_guard_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	con(this,instant_alloc);
	return this;
}

// Destructor
void shinsei_ex_gil_guard_t_dec(shinsei_ex_gil_guard_t*const restrict this){
	if(this->used) gilFree(this);
    free(this);
	return;
}

// [Const] Check if the GIL is using
bool shinsei_ex_gil_guard_t_isUsing(const shinsei_ex_gil_guard_t*const restrict this){
	return this->used;
}

// Allocate the GIL
void shinsei_ex_gil_guard_t_alloc(shinsei_ex_gil_guard_t*const restrict this){
	this->used=true;
	gilAlloc(this);
	return;
}

// Free the GIL
void shinsei_ex_gil_guard_t_free(shinsei_ex_gil_guard_t*const restrict this){
	this->used=false;
	gilFree(this);
	return;
}

// Static default constructor
void shinsei_ex_gil_guard_t_as(shinsei_ex_gil_guard_t*const restrict this,const bool instant_alloc){
	con(this,instant_alloc);
	return;
}

// Inline default constructor
void shinsei_ex_gil_guard_t_inl(shinsei_ex_gil_guard_t*const restrict this,const bool instant_alloc){
	con(this,instant_alloc);
	return;
}
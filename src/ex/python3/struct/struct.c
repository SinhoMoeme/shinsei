#include "shinsei/ex/python3/struct.h"

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

// [Internal, const] Check if elements are inlined
_SHINSEI_OS_INLINE static bool stk_inlined(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}

// [Internal, const] Get the element data
_SHINSEI_OS_INLINE static PyObject** stk_data(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return (PyObject**)((uintptr_t)&this->data*stk_inlined(this)+!stk_inlined(this)*(uintptr_t)this->data);
}

// [Internal] Default constructor
_SHINSEI_OS_INLINE static bool stk_con(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	this->size=0;
	this->cap=shinsei_ex_pystack_t_DEF_CAP;
	this->data=(PyObject**)__builtin_malloc(this->cap*sizeof(PyObject*));
	return this->data!=nullptr;
}

// [Internal] Static assign constructor
_SHINSEI_OS_INLINE static bool stk_asAssign(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl;
	this->size=src->size;
	this->cap=src->cap;
	if(!stk_inlined(this)){
		this->data=(PyObject**)__builtin_malloc(this->cap*sizeof(PyObject*));
		if(__builtin_expect(this->data==nullptr,0)) return false;
	}
	register PyObject**const dst=stk_data(this);
	register PyObject**const src_ptr=stk_data(src);
	for(register size_t i=0;i<this->size;++i) dst[i]=Py_NewRef(src_ptr[i]);
	return true;
}

// [Internal] Static move constructor
_SHINSEI_OS_INLINE static void stk_asMove(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl;
	this->size=src->size;
	this->cap=src->cap;
	if(stk_inlined(src)){
		__builtin_memcpy(stk_data(this),stk_data(src),this->size*sizeof(PyObject*));
	}
	else this->data=src->data;
	src->ctrl=0;
	src->size=0;
	src->cap=0;
	src->data=nullptr;
	return;
}

// [Internal] Expand capacity by more_cap
_SHINSEI_OS_INLINE static bool stk_expand(shinsei_ex_pystack_t*const restrict this,const size_t more_cap)_SHINSEI_OS_NOEXCEPT{
	if(stk_inlined(this)){
		this->cap+=more_cap;
		return true;
	}
	register PyObject**const ptr=(PyObject**)__builtin_realloc(this->data,(this->cap+more_cap)*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap+=more_cap;
	this->data=ptr;
	return true;
}

// [Internal] Shrink capacity by less_cap
_SHINSEI_OS_INLINE static bool stk_shrink(shinsei_ex_pystack_t*const restrict this,const size_t less_cap)_SHINSEI_OS_NOEXCEPT{
	if(stk_inlined(this)){
		this->cap-=less_cap;
		return true;
	}
	register PyObject**const ptr=(PyObject**)__builtin_realloc(this->data,(this->cap-less_cap)*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap-=less_cap;
	this->data=ptr;
	return true;
}

// [Internal] Free all elements
_SHINSEI_OS_INLINE static void stk_freeData(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	register PyObject**const ptr=stk_data(this);
	for(register size_t i=0;i<this->size;++i) Py_DecRef(ptr[i]);
	if(!stk_inlined(this)) __builtin_free(this->data);
	return;
}

// [Internal] Batch Add
_SHINSEI_OS_INLINE static bool stk_pushArray(shinsei_ex_pystack_t*const restrict this,const PyObject**const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	if(!len) return true;
	if(this->size+len>this->cap){
		if(stk_inlined(this)) return false;
		register size_t needed=(this->cap<<1>=shinsei_ex_pystack_t_DEF_CAP)*this->cap+(this->cap<<1<shinsei_ex_pystack_t_DEF_CAP)*(shinsei_ex_pystack_t_DEF_CAP-this->cap);
		needed=(needed<=len)*len+!(needed<=len)*needed;
		if(!stk_expand(this,needed)) return false;
	}
	register PyObject**const dst=stk_data(this);
	for(register size_t i=0;i<len;++i) dst[this->size+i]=Py_NewRef(arr[i]);
	this->size+=len;
	return true;
}

_SHINSEI_OS_INLINE static bool stk_pushElement(shinsei_ex_pystack_t*const restrict this,const PyObject*const restrict val,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
	if(!cnt) return true;
	if(this->size+cnt>this->cap){
		if(stk_inlined(this)) return false;
		register size_t needed=(this->cap<<1>=shinsei_ex_pystack_t_DEF_CAP)*this->cap+(this->cap<<1<shinsei_ex_pystack_t_DEF_CAP)*(shinsei_ex_pystack_t_DEF_CAP-this->cap);
		needed=(needed<=cnt)*cnt+!(needed<=cnt)*needed;
		if(!stk_expand(this,needed)) return false;
	}
	register PyObject**const dst=stk_data(this);
	for(register size_t i=0;i<cnt;++i) dst[this->size+i]=Py_NewRef((PyObject*)val);
	this->size+=cnt;
	return true;
}

// [Internal] Batch remove
_SHINSEI_OS_INLINE static void stk_popArray(shinsei_ex_pystack_t*const restrict this,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
	register PyObject**const ptr=stk_data(this);
	for(register size_t i=0;i<cnt;++i) Py_DecRef(ptr[this->size-1-i]);
	this->size-=cnt;
	if(stk_inlined(this)) return;
	if(__builtin_expect(this->size>=this->cap>>2,1)) return;
	stk_shrink(this,(this->cap>>1>=shinsei_ex_pystack_t_DEF_CAP)*(this->cap>>1)+(this->cap>>1<shinsei_ex_pystack_t_DEF_CAP)*(this->cap-shinsei_ex_pystack_t_DEF_CAP));
	return;
}

// [Internal] Constructors
_SHINSEI_OS_INLINE static bool stk_conCapacity(shinsei_ex_pystack_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	this->size=0;
	this->cap=cap;
	this->data=(PyObject**)__builtin_malloc(this->cap*sizeof(PyObject*));
	return this->data!=nullptr;
}

_SHINSEI_OS_INLINE static bool stk_asElement(shinsei_ex_pystack_t*const restrict this,const PyObject*const restrict val,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	this->size=cnt;
	this->cap=cnt+!cnt*shinsei_ex_pystack_t_DEF_CAP;
	this->data=(PyObject**)__builtin_malloc(this->cap*sizeof(PyObject*));
	if(__builtin_expect(this->data==nullptr,0)) return false;
	register PyObject**const dst=stk_data(this);
	for(register size_t i=0;i<cnt;++i) dst[i]=Py_NewRef((PyObject*)val);
	return true;
}

_SHINSEI_OS_INLINE static bool stk_asArray(shinsei_ex_pystack_t*const restrict this,const PyObject**const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	this->size=len;
	this->cap=len+!len*shinsei_ex_pystack_t_DEF_CAP;
	this->data=(PyObject**)__builtin_malloc(this->cap*sizeof(PyObject*));
	if(__builtin_expect(this->data==nullptr,0)) return false;
	register PyObject**const dst=stk_data(this);
	for(register size_t i=0;i<len;++i) dst[i]=Py_NewRef(arr[i]);
	return true;
}

// Default constructor
shinsei_ex_pystack_t* shinsei_ex_pystack_t_con()_SHINSEI_OS_NOEXCEPT{
	register shinsei_ex_pystack_t*const this=(shinsei_ex_pystack_t*const)__builtin_malloc(sizeof(shinsei_ex_pystack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!stk_con(this),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}

// Capacity constructor
shinsei_ex_pystack_t* shinsei_ex_pystack_t_conCapacity(const size_t cap)_SHINSEI_OS_NOEXCEPT{
	register shinsei_ex_pystack_t*const this=(shinsei_ex_pystack_t*const)__builtin_malloc(sizeof(shinsei_ex_pystack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!stk_conCapacity(this,cap),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}

// Assign constructor
shinsei_ex_pystack_t* shinsei_ex_pystack_t_conAssign(const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	register shinsei_ex_pystack_t*const this=(shinsei_ex_pystack_t*const)__builtin_malloc(sizeof(shinsei_ex_pystack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	register PyGILState_STATE g_state=PyGILState_Ensure();
	if(__builtin_expect(!stk_asAssign(this,src),0)){
		PyGILState_Release(g_state);
		__builtin_free(this);
		return nullptr;
	}
	PyGILState_Release(g_state);
	return this;
}
shinsei_ex_pystack_t* shinsei_ex_pystack_t_conAssignUnsafe(const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	register shinsei_ex_pystack_t*const this=(shinsei_ex_pystack_t*const)__builtin_malloc(sizeof(shinsei_ex_pystack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!stk_asAssign(this,src),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}

// Move constructor
shinsei_ex_pystack_t* shinsei_ex_pystack_t_conMove(shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	register shinsei_ex_pystack_t*const this=(shinsei_ex_pystack_t*const)__builtin_malloc(sizeof(shinsei_ex_pystack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	stk_asMove(this,src);
	return this;
}

// Element constructor
shinsei_ex_pystack_t* shinsei_ex_pystack_t_conElement(const PyObject*const restrict val,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
	register shinsei_ex_pystack_t*const this=(shinsei_ex_pystack_t*const)__builtin_malloc(sizeof(shinsei_ex_pystack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	register PyGILState_STATE g_state=PyGILState_Ensure();
	if(__builtin_expect(!stk_asElement(this,val,cnt),0)){
		PyGILState_Release(g_state);
		__builtin_free(this);
		return nullptr;
	}
	PyGILState_Release(g_state);
	return this;
}
shinsei_ex_pystack_t* shinsei_ex_pystack_t_conElementUnsafe(const PyObject*const restrict val,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
	register shinsei_ex_pystack_t*const this=(shinsei_ex_pystack_t*const)__builtin_malloc(sizeof(shinsei_ex_pystack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!stk_asElement(this,val,cnt),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}

// Array constructor
shinsei_ex_pystack_t* shinsei_ex_pystack_t_conArray(const PyObject**const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	register shinsei_ex_pystack_t*const this=(shinsei_ex_pystack_t*const)__builtin_malloc(sizeof(shinsei_ex_pystack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	register PyGILState_STATE g_state=PyGILState_Ensure();
	if(__builtin_expect(!stk_asArray(this,arr,len),0)){
		PyGILState_Release(g_state);
		__builtin_free(this);
		return nullptr;
	}
	PyGILState_Release(g_state);
	return this;
}
shinsei_ex_pystack_t* shinsei_ex_pystack_t_conArrayUnsafe(const PyObject**const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	register shinsei_ex_pystack_t*const this=(shinsei_ex_pystack_t*const)__builtin_malloc(sizeof(shinsei_ex_pystack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!stk_asArray(this,arr,len),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}

// Destructor
void shinsei_ex_pystack_t_dec(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	register PyGILState_STATE g_state=PyGILState_Ensure();
	if(!stk_inlined(this)&&this->data!=nullptr) stk_freeData(this);
	PyGILState_Release(g_state);
	__builtin_free(this);
	return;
}
void shinsei_ex_pystack_t_decUnsafe(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(!stk_inlined(this)&&this->data!=nullptr) stk_freeData(this);
	__builtin_free(this);
	return;
}

// Expand capacity by more_cap
bool shinsei_ex_pystack_t_expand(shinsei_ex_pystack_t*const restrict this,const size_t more_cap)_SHINSEI_OS_NOEXCEPT{
	return stk_expand(this,more_cap);
}

// Shrink capacity by less_cap
bool shinsei_ex_pystack_t_shrink(shinsei_ex_pystack_t*const restrict this,const size_t less_cap)_SHINSEI_OS_NOEXCEPT{
	return stk_shrink(this,less_cap);
}

// Reserve for the elements
bool shinsei_ex_pystack_t_reserve(shinsei_ex_pystack_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT{
	if(stk_inlined(this)){
		this->cap=cap;
		return true;
	}
	register PyObject**const ptr=(PyObject**)__builtin_realloc(this->data,cap*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap=cap;
	this->data=ptr;
	return true;
}

// Shrink capacity to fit
bool shinsei_ex_pystack_t_shrinkToFit(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(stk_inlined(this)){
		this->cap=this->size;
		return true;
	}
	register PyObject**const ptr=(PyObject**)__builtin_realloc(this->data,this->size*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap=this->size;
	this->data=ptr;
	return true;
}

// [Const] Check if stack is empty
bool shinsei_ex_pystack_t_empty(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return !this->size;
}

// [Const] Get stack size
size_t shinsei_ex_pystack_t_size(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->size;
}

// [Const] Get stack capacity
size_t shinsei_ex_pystack_t_capacity(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->cap;
}

// [Const] Get the top element
PyObject* shinsei_ex_pystack_t_top(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	register PyGILState_STATE g_state=PyGILState_Ensure();
	register PyObject* res=Py_NewRef(stk_data(this)[this->size-1]);
	PyGILState_Release(g_state);
	return res;
}
PyObject* shinsei_ex_pystack_t_topUnsafe(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return Py_NewRef(stk_data(this)[this->size-1]);
}

// [Const] Get the element at idx
PyObject* shinsei_ex_pystack_t_at(const shinsei_ex_pystack_t*const restrict this,const size_t idx)_SHINSEI_OS_NOEXCEPT{
	register PyGILState_STATE g_state=PyGILState_Ensure();
	register PyObject* res=Py_NewRef(stk_data(this)[idx]);
	PyGILState_Release(g_state);
	return res;
}
PyObject* shinsei_ex_pystack_t_atUnsafe(const shinsei_ex_pystack_t*const restrict this,const size_t idx)_SHINSEI_OS_NOEXCEPT{
	return Py_NewRef(stk_data(this)[idx]);
}

// [Const] Get the element data
PyObject** shinsei_ex_pystack_t_data(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return stk_data(this);
}

// Pop the top element
void shinsei_ex_pystack_t_pop(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	register PyGILState_STATE g_state=PyGILState_Ensure();
	stk_popArray(this,1);
	PyGILState_Release(g_state);
	return;
}
void shinsei_ex_pystack_t_popUnsafe(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	stk_popArray(this,1);
	return;
}

void shinsei_ex_pystack_t_popArray(shinsei_ex_pystack_t*const restrict this,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
	register PyGILState_STATE g_state=PyGILState_Ensure();
	stk_popArray(this,cnt);
	PyGILState_Release(g_state);
	return;
}
void shinsei_ex_pystack_t_popArrayUnsafe(shinsei_ex_pystack_t*const restrict this,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
	stk_popArray(this,cnt);
	return;
}

// Push an element to the top
bool shinsei_ex_pystack_t_push(shinsei_ex_pystack_t*const restrict this,const PyObject*const restrict val)_SHINSEI_OS_NOEXCEPT{
	register PyGILState_STATE g_state=PyGILState_Ensure();
	register bool res=stk_pushElement(this,val,1);
	PyGILState_Release(g_state);
	return res;
}
bool shinsei_ex_pystack_t_pushUnsafe(shinsei_ex_pystack_t*const restrict this,const PyObject*const restrict val)_SHINSEI_OS_NOEXCEPT{
	return stk_pushElement(this,val,1);
}

bool shinsei_ex_pystack_t_pushArray(shinsei_ex_pystack_t*const restrict this,const PyObject**const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	register PyGILState_STATE g_state=PyGILState_Ensure();
	register bool res=stk_pushArray(this,arr,len);
	PyGILState_Release(g_state);
	return res;
}
bool shinsei_ex_pystack_t_pushArrayUnsafe(shinsei_ex_pystack_t*const restrict this,const PyObject**const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
	return stk_pushArray(this,arr,len);
}

bool shinsei_ex_pystack_t_pushElement(shinsei_ex_pystack_t*const restrict this,const PyObject*const restrict val,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
	register PyGILState_STATE g_state=PyGILState_Ensure();
	register bool res=stk_pushElement(this,val,cnt);
	PyGILState_Release(g_state);
	return res;
}
bool shinsei_ex_pystack_t_pushElementUnsafe(shinsei_ex_pystack_t*const restrict this,const PyObject*const restrict val,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
	return stk_pushElement(this,val,cnt);
}

// Swap 2 stacks
void shinsei_ex_pystack_t_swap(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	shinsei_ex_pystack_t tmp;
	__builtin_memcpy(&tmp,src,sizeof(shinsei_ex_pystack_t));
	__builtin_memcpy(src,this,sizeof(shinsei_ex_pystack_t));
	__builtin_memcpy(this,&tmp,sizeof(shinsei_ex_pystack_t));
	return;
}

// Clear all elements
bool shinsei_ex_pystack_t_clear(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	register PyGILState_STATE g_state=PyGILState_Ensure();
	register PyObject**const ptr=stk_data(this);
	for(register size_t i=0;i<this->size;++i) Py_DecRef(ptr[i]);
	this->size=0;
	if(!stk_inlined(this)){
		register PyObject**const new_ptr=(PyObject**)__builtin_realloc(this->data,shinsei_ex_pystack_t_DEF_CAP*sizeof(PyObject*));
		if(__builtin_expect(new_ptr==nullptr,0)){
			PyGILState_Release(g_state);
			return false;
		}
		this->cap=shinsei_ex_pystack_t_DEF_CAP;
		this->data=new_ptr;
	}
	PyGILState_Release(g_state);
	return true;
}
bool shinsei_ex_pystack_t_clearUnsafe(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	register PyObject**const ptr=stk_data(this);
	for(register size_t i=0;i<this->size;++i) Py_DecRef(ptr[i]);
	this->size=0;
	if(!stk_inlined(this)){
		register PyObject**const new_ptr=(PyObject**)__builtin_realloc(this->data,shinsei_ex_pystack_t_DEF_CAP*sizeof(PyObject*));
		if(__builtin_expect(new_ptr==nullptr,0)) return false;
		this->cap=shinsei_ex_pystack_t_DEF_CAP;
		this->data=new_ptr;
	}
	return true;
}

// Set stack size
bool shinsei_ex_pystack_t_setSize(shinsei_ex_pystack_t*const restrict this,const size_t size)_SHINSEI_OS_NOEXCEPT{
	if(size>this->cap){
		if(!shinsei_ex_pystack_t_reserve(this,size)) return false;
	}
	this->size=size;
	return true;
}

// Assign the stack and all elements
bool shinsei_ex_pystack_t_assign(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	register PyGILState_STATE g_state=PyGILState_Ensure();
	stk_freeData(this);
	if(!stk_inlined(this)&&stk_inlined(src)){
		if(this->data!=nullptr) __builtin_free(this->data);
	}
	else if(!stk_inlined(this)&&!stk_inlined(src)){
		if(this->cap!=src->cap){
			register PyObject** ptr=(PyObject**)__builtin_realloc(this->data,src->cap*sizeof(PyObject*));
			if(__builtin_expect(ptr==nullptr,0)){
				PyGILState_Release(g_state);
				return false;
			}
			this->data=ptr;
		}
	}
	else if(stk_inlined(this)&&!stk_inlined(src)){
		this->data=(PyObject**)__builtin_malloc(src->cap*sizeof(PyObject*));
		if(__builtin_expect(this->data==nullptr,0)){
			PyGILState_Release(g_state);
			return false;
		}
	}
	this->ctrl=src->ctrl;
	this->size=src->size;
	this->cap=src->cap;
	register PyObject**const dst=stk_data(this);
	register PyObject**const src_ptr=stk_data(src);
	for(register size_t i=0;i<this->size;++i) dst[i]=Py_NewRef(src_ptr[i]);
	PyGILState_Release(g_state);
	return true;
}
bool shinsei_ex_pystack_t_assignUnsafe(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	stk_freeData(this);
	if(!stk_inlined(this)&&stk_inlined(src)){
		if(this->data!=nullptr) __builtin_free(this->data);
	}
	else if(!stk_inlined(this)&&!stk_inlined(src)){
		if(this->cap!=src->cap){
			register PyObject** ptr=(PyObject**)__builtin_realloc(this->data,src->cap*sizeof(PyObject*));
			if(__builtin_expect(ptr==nullptr,0)) return false;
			this->data=ptr;
		}
	}
	else if(stk_inlined(this)&&!stk_inlined(src)){
		this->data=(PyObject**)__builtin_malloc(src->cap*sizeof(PyObject*));
		if(__builtin_expect(this->data==nullptr,0)) return false;
	}
	this->ctrl=src->ctrl;
	this->size=src->size;
	this->cap=src->cap;
	register PyObject**const dst=stk_data(this);
	register PyObject**const src_ptr=stk_data(src);
	for(register size_t i=0;i<this->size;++i) dst[i]=Py_NewRef(src_ptr[i]);
	return true;
}

// Move the ownership to another stack
void shinsei_ex_pystack_t_move(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	if(!stk_inlined(this)&&this->data!=nullptr) stk_freeData(this);
	stk_asMove(this,src);
	return;
}
void shinsei_ex_pystack_t_moveUnsafe(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	if(!stk_inlined(this)&&this->data!=nullptr) stk_freeData(this);
	stk_asMove(this,src);
	return;
}

// Attach the stack from another one
bool shinsei_ex_pystack_t_attach(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	register PyGILState_STATE g_state=PyGILState_Ensure();
	register PyObject** dst=stk_data(this);
	for(register size_t i=0;i<this->size;++i) Py_DecRef(dst[i]);
	register const bool des_inlined=stk_inlined(this);
	if(!des_inlined){
		if(this->cap<src->cap){
			register PyObject** ptr=(PyObject**)__builtin_realloc(this->data,src->cap*sizeof(PyObject*));
			if(__builtin_expect(ptr==nullptr,0)){
				PyGILState_Release(g_state);
				return false;
			}
			this->data=ptr;
			this->cap=src->cap;
		}
	}
	this->ctrl=(src->ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->size=src->size;
	dst=stk_data(this);
	register PyObject**const src_ptr=stk_data(src);
	for(register size_t i=0;i<this->size;++i) dst[i]=Py_NewRef(src_ptr[i]);
	PyGILState_Release(g_state);
	return true;
}

bool shinsei_ex_pystack_t_attachUnsafe(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	register PyObject** dst=stk_data(this);
	for(register size_t i=0;i<this->size;++i) Py_DecRef(dst[i]);
	register const bool des_inlined=stk_inlined(this);
	if(!des_inlined){
		if(this->cap<src->cap){
			register PyObject** ptr=(PyObject**)__builtin_realloc(this->data,src->cap*sizeof(PyObject*));
			if(__builtin_expect(ptr==nullptr,0)) return false;
			this->data=ptr;
			this->cap=src->cap;
		}
	}
	this->ctrl=(src->ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->size=src->size;
	dst=stk_data(this);
	register PyObject**const src_ptr=stk_data(src);
	for(register size_t i=0;i<this->size;++i) dst[i]=Py_NewRef(src_ptr[i]);
	return true;
}

// Attach the stack from values
bool shinsei_ex_pystack_t_attachValue(shinsei_ex_pystack_t*const restrict this,const int_fast32_t ctrl,const size_t size,const size_t cap,PyObject**const ptr)_SHINSEI_OS_NOEXCEPT{
	register PyGILState_STATE g_state=PyGILState_Ensure();
	register PyObject** dst=stk_data(this);
	for(register size_t i=0;i<this->size;++i) Py_DecRef(dst[i]);
	register const bool des_inlined=stk_inlined(this);
	if(!des_inlined){
		if(this->cap<cap){
			register PyObject** new_ptr=(PyObject**)__builtin_realloc(this->data,cap*sizeof(PyObject*));
			if(__builtin_expect(new_ptr==nullptr,0)){
				PyGILState_Release(g_state);
				return false;
			}
			this->data=new_ptr;
			this->cap=cap;
		}
	}
	this->ctrl=(ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->size=size;
	dst=stk_data(this);
	for(register size_t i=0;i<this->size;++i) dst[i]=Py_NewRef(ptr[i]);
	PyGILState_Release(g_state);
	return true;
}

bool shinsei_ex_pystack_t_attachValueUnsafe(shinsei_ex_pystack_t*const restrict this,const int_fast32_t ctrl,const size_t size,const size_t cap,PyObject**const ptr)_SHINSEI_OS_NOEXCEPT{
	register PyObject** dst=stk_data(this);
	for(register size_t i=0;i<this->size;++i) Py_DecRef(dst[i]);
	register const bool des_inlined=stk_inlined(this);
	if(!des_inlined){
		if(this->cap<cap){
			register PyObject** new_ptr=(PyObject**)__builtin_realloc(this->data,cap*sizeof(PyObject*));
			if(__builtin_expect(new_ptr==nullptr,0)) return false;
			this->data=new_ptr;
			this->cap=cap;
		}
	}
	this->ctrl=(ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->size=size;
	dst=stk_data(this);
	for(register size_t i=0;i<this->size;++i) dst[i]=Py_NewRef(ptr[i]);
	return true;
}

// Static default constructor
bool shinsei_ex_pystack_t_as(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return stk_con(this);
}
// Static capacity constructor
bool shinsei_ex_pystack_t_asCapacity(shinsei_ex_pystack_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT{
	return stk_conCapacity(this,cap);
}
// Static assign constructor
bool shinsei_ex_pystack_t_asAssign(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	register PyGILState_STATE g_state=PyGILState_Ensure();
	register bool res=stk_asAssign(this,src);
	PyGILState_Release(g_state);
	return res;
}
bool shinsei_ex_pystack_t_asAssignUnsafe(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	return stk_asAssign(this,src);
}

// Static move constructor
void shinsei_ex_pystack_t_asMove(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	stk_asMove(this,src);
	return;
}

// Inline default constructor
void shinsei_ex_pystack_t_inl(shinsei_ex_pystack_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->size=0;
	this->cap=cap;
	return;
}
// Inline capacity constructor
void shinsei_ex_pystack_t_inlCapacity(shinsei_ex_pystack_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT{
	shinsei_ex_pystack_t_inl(this,cap);
	return;
}
// Inline assign constructor
void shinsei_ex_pystack_t_inlAssign(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->size=src->size;
	this->cap=src->cap;
	register PyObject**const dst=stk_data(this);
	register PyObject**const src_ptr=stk_data(src);
	register PyGILState_STATE g_state=PyGILState_Ensure();
	for(register size_t i=0;i<this->size;++i) dst[i]=Py_NewRef(src_ptr[i]);
	PyGILState_Release(g_state);
	return;
}
void shinsei_ex_pystack_t_inlAssignUnsafe(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->size=src->size;
	this->cap=src->cap;
	register PyObject**const dst=stk_data(this);
	register PyObject**const src_ptr=stk_data(src);
	for(register size_t i=0;i<this->size;++i) dst[i]=Py_NewRef(src_ptr[i]);
	return;
}

// Inline move constructor
void shinsei_ex_pystack_t_inlMove(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->size=src->size;
	this->cap=src->cap;
	__builtin_memcpy(stk_data(this),stk_data(src),this->size*sizeof(PyObject*));
	if(!stk_inlined(src)) __builtin_free(src->data);
	src->ctrl=0;
	src->size=0;
	src->cap=0;
	src->data=nullptr;
	return;
}

// [const] Check if elements are inlined
bool shinsei_ex_pystack_t_inlined(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return stk_inlined(this);
}

// [Const] Get the ctrl code
int_fast32_t shinsei_ex_pystack_t_getCtrl(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl;
}

// Set the ctrl code
void shinsei_ex_pystack_t_setCtrl(shinsei_ex_pystack_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=ctrl;
	return;
}

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif
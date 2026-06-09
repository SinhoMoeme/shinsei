#include"shinsei/ex/python3/struct.h"

// [Internal, const] Check if elements are stk_inlined
_SHINSEI_OS_INLINE static bool stk_inlined(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}

// [Internal, const] Get the element stk_data
_SHINSEI_OS_INLINE static PyObject** stk_data(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return (PyObject**)((uintptr_t)&this->data*stk_inlined(this)+!stk_inlined(this)*(uintptr_t)this->data);
}

// [Internal] Default constructor
_SHINSEI_OS_INLINE static bool stk_as(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	this->size=0;
	this->cap=shinsei_ex_pystack_t_DEF_CAP;
	this->data=(PyObject**)__builtin_malloc(this->cap*sizeof(PyObject*));
	return this->data!=nullptr;
}

// [Internal] Static copy constructor
_SHINSEI_OS_INLINE static bool stk_asCopy(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl;
	this->size=src->size;
	this->cap=src->cap;
	if(!stk_inlined(this)){
		this->data=(PyObject**)__builtin_malloc(this->cap*sizeof(PyObject*));
		if(__builtin_expect(this->data==nullptr,0)) return false;
	}
	register PyObject**const dst_ptr=stk_data(this);
	register PyObject**const src_ptr=stk_data(src);
	register PyGILState_STATE g_state=PyGILState_Ensure();
	for(register size_t i=0;i<this->size;++i) dst_ptr[i]=Py_NewRef(src_ptr[i]);
	PyGILState_Release(g_state);
	return true;
}
_SHINSEI_OS_INLINE static bool stk_asCopyUnsafe(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl;
	this->size=src->size;
	this->cap=src->cap;
	if(!stk_inlined(this)){
		this->data=(PyObject**)__builtin_malloc(this->cap*sizeof(PyObject*));
		if(__builtin_expect(this->data==nullptr,0)) return false;
	}
	register PyObject**const dst_ptr=stk_data(this);
	register PyObject**const src_ptr=stk_data(src);
	for(register size_t i=0;i<this->size;++i) dst_ptr[i]=Py_NewRef(src_ptr[i]);
	return true;
}

// [Internal] Copy constructor
_SHINSEI_OS_INLINE static shinsei_ex_pystack_t* conCopy(const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	register shinsei_ex_pystack_t *const this=(shinsei_ex_pystack_t *const)__builtin_malloc(sizeof(shinsei_ex_pystack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!stk_asCopy(this,src),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}
_SHINSEI_OS_INLINE static shinsei_ex_pystack_t* conCopyUnsafe(const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	register shinsei_ex_pystack_t *const this=(shinsei_ex_pystack_t *const)__builtin_malloc(sizeof(shinsei_ex_pystack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!stk_asCopyUnsafe(this,src),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}

// [Internal] Static move constructor
_SHINSEI_OS_INLINE static void asMove(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t* const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl;
	this->size=src->size;
	this->cap=src->cap;
	if(stk_inlined(src)){
		register PyObject**const dst_ptr=stk_data(this);
		register PyObject**const src_ptr=stk_data(src);
		for(register size_t i=0;i<this->size;++i) dst_ptr[i]=src_ptr[i];
	}else{
		this->data=src->data;
	}
	src->ctrl=0;
	src->size=0;
	src->cap=0;
	src->data=nullptr;
	return;
}

// [Internal] Free all elements
_SHINSEI_OS_INLINE static void __builtin_freeData(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	register PyObject**const ptr=stk_data(this);
	register PyGILState_STATE g_state=PyGILState_Ensure();
	for(register size_t i=0;i<this->size;++i) Py_DecRef(ptr[i]);
	PyGILState_Release(g_state);
	if(!stk_inlined(this)) __builtin_free(this->data);
	return;
}

_SHINSEI_OS_INLINE static void __builtin_freeDataUnsafe(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	register PyObject**const ptr=stk_data(this);
	for(register size_t i=0;i<this->size;++i) Py_DecRef(ptr[i]);
	if(!stk_inlined(this)) __builtin_free(this->data);
	return;
}

// [Internal] Capacity constructor
_SHINSEI_OS_INLINE static bool conCapacity(shinsei_ex_pystack_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	this->size=0;
	this->cap=cap;
	this->data=(PyObject**)__builtin_malloc(this->cap*sizeof(PyObject*));
	return this->data!=nullptr;
}

// [Internal] Inline default constructor
void inl(shinsei_ex_pystack_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->size=0;
	this->cap=cap;
	return;
}

// Default constructor
shinsei_ex_pystack_t* shinsei_ex_pystack_t_con()_SHINSEI_OS_NOEXCEPT{
	register shinsei_ex_pystack_t *const this=(shinsei_ex_pystack_t *const)__builtin_malloc(sizeof(shinsei_ex_pystack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!stk_as(this),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}

// Capacity constructor
shinsei_ex_pystack_t* shinsei_ex_pystack_t_conCapacity(const size_t cap)_SHINSEI_OS_NOEXCEPT{
	register shinsei_ex_pystack_t *const this=(shinsei_ex_pystack_t *const)__builtin_malloc(sizeof(shinsei_ex_pystack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!conCapacity(this,cap),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}

// Copy constructor
shinsei_ex_pystack_t* shinsei_ex_pystack_t_conCopy(const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	return conCopy(src);
}
shinsei_ex_pystack_t* shinsei_ex_pystack_t_conCopyUnsafe(const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	return conCopyUnsafe(src);
}

// Move constructor
shinsei_ex_pystack_t* shinsei_ex_pystack_t_conMove(shinsei_ex_pystack_t* const restrict src)_SHINSEI_OS_NOEXCEPT{
	register shinsei_ex_pystack_t *const this=(shinsei_ex_pystack_t *const)__builtin_malloc(sizeof(shinsei_ex_pystack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	asMove(this,src);
	return this;
}

// Destructor
void shinsei_ex_pystack_t_dec(shinsei_ex_pystack_t *const restrict this)_SHINSEI_OS_NOEXCEPT{
	__builtin_freeData(this);
	__builtin_free(this);
	return;
}

// Expand capacity by more_cap
bool shinsei_ex_pystack_t_expand(shinsei_ex_pystack_t*const restrict this,const size_t more_cap)_SHINSEI_OS_NOEXCEPT{
	if(stk_inlined(this)){
		this->cap+=more_cap;
		return true;
	}
	register PyObject **const ptr=(PyObject **const)realloc(this->data,(this->cap+more_cap)*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap+=more_cap;
	this->data=ptr;
	return true;
}

// Shrink capacity by less_cap
bool shinsei_ex_pystack_t_shrink(shinsei_ex_pystack_t*const restrict this,const size_t less_cap)_SHINSEI_OS_NOEXCEPT{
	if(stk_inlined(this)){
		this->cap-=less_cap;
		return true;
	}
	register PyObject **const ptr=(PyObject **const)realloc(this->data,(this->cap-less_cap)*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap-=less_cap;
	this->data=ptr;
	return true;
}

// Reserve for the elements
bool shinsei_ex_pystack_t_reserve(shinsei_ex_pystack_t* const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT{
	if(stk_inlined(this)){
		this->cap=cap;
		return true;
	}
	register PyObject **const ptr=(PyObject **const)realloc(this->data,cap*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap=cap;
	this->data=ptr;
	return true;
}

// Shrink capacity to fit
bool shinsei_ex_pystack_t_shrinkToFit(shinsei_ex_pystack_t* const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(stk_inlined(this)){
		this->cap=this->size;
		return true;
	}
	register PyObject **const ptr=(PyObject **const)realloc(this->data,this->size*sizeof(PyObject*));
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

// [Const] Get the element stk_data
PyObject** shinsei_ex_pystack_t_data(const shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return stk_data(this);
}

// Pop the top element
void shinsei_ex_pystack_t_pop(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	register PyGILState_STATE g_state=PyGILState_Ensure();
	Py_DecRef(stk_data(this)[--this->size]);
	PyGILState_Release(g_state);
	if(stk_inlined(this)) return;
	if(__builtin_expect(this->size>=this->cap>>2,1)) return;
	shinsei_ex_pystack_t_shrink(this,this->cap>>1);
	return;
}
void shinsei_ex_pystack_t_popUnsafe(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	Py_DecRef(stk_data(this)[--this->size]);
	if(stk_inlined(this)) return;
	if(__builtin_expect(this->size>=this->cap>>2,1)) return;
	shinsei_ex_pystack_t_shrink(this,this->cap>>1);
	return;
}

// Push an element to the top
bool shinsei_ex_pystack_t_push(shinsei_ex_pystack_t*const restrict this,const PyObject*const restrict val)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->size==this->cap,0)){
		if(stk_inlined(this)) return false;
		if(__builtin_expect(!shinsei_ex_pystack_t_expand(this,this->cap?this->cap:shinsei_ex_pystack_t_DEF_CAP),0)) return false;
	}
	register PyGILState_STATE g_state=PyGILState_Ensure();
	register PyObject* res=Py_NewRef((PyObject*)val);
	PyGILState_Release(g_state);
	stk_data(this)[this->size++]=res;
	return true;
}

bool shinsei_ex_pystack_t_pushUnsafe(shinsei_ex_pystack_t*const restrict this,const PyObject*const restrict val)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(this->size==this->cap,0)){
		if(stk_inlined(this)) return false;
		if(__builtin_expect(!shinsei_ex_pystack_t_expand(this,this->cap?this->cap:shinsei_ex_pystack_t_DEF_CAP),0)) return false;
	}
	stk_data(this)[this->size++]=Py_NewRef((PyObject*)val);
	return true;
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
	register PyObject**const ptr=stk_data(this);
	register PyGILState_STATE g_state=PyGILState_Ensure();
	for(register size_t i=0;i<this->size;++i) Py_DecRef(ptr[i]);
	PyGILState_Release(g_state);
	this->size=0;
	if(!stk_inlined(this)){
		register PyObject **const new_ptr=(PyObject **const)realloc(this->data,shinsei_ex_pystack_t_DEF_CAP*sizeof(PyObject*));
		if(__builtin_expect(new_ptr==nullptr,0)) return false;
		this->cap=shinsei_ex_pystack_t_DEF_CAP;
		this->data=new_ptr;
	}
	return true;
}

bool shinsei_ex_pystack_t_clearUnsafe(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	register PyObject**const ptr=stk_data(this);
	for(register size_t i=0;i<this->size;++i) Py_DecRef(ptr[i]);
	this->size=0;
	if(!stk_inlined(this)){
		register PyObject **const new_ptr=(PyObject **const)realloc(this->data,shinsei_ex_pystack_t_DEF_CAP*sizeof(PyObject*));
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
	__builtin_freeData(this);
	if(!stk_inlined(this)&&!stk_inlined(src)){
		if(this->cap!=src->cap){
			register PyObject** ptr=(PyObject**)realloc(this->data,src->cap*sizeof(PyObject*));
			if(__builtin_expect(ptr==nullptr,0)) return false;
			this->data=ptr;
		}
	}
	else if(!stk_inlined(this)&&stk_inlined(src)){
		__builtin_free(this->data);
	}
	else if(stk_inlined(this)&&!stk_inlined(src)){
		this->data=(PyObject**)__builtin_malloc(src->cap*sizeof(PyObject*));
		if(__builtin_expect(this->data==nullptr,0)) return false;
	}
	this->ctrl=src->ctrl;
	this->size=src->size;
	this->cap=src->cap;
	register PyObject**const dst_ptr=stk_data(this);
	register PyObject**const src_ptr=stk_data(src);
	register PyGILState_STATE g_state=PyGILState_Ensure();
	for(register size_t i=0;i<this->size;++i) dst_ptr[i]=Py_NewRef(src_ptr[i]);
	PyGILState_Release(g_state);
	return true;
}
bool shinsei_ex_pystack_t_assignUnsafe(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	__builtin_freeDataUnsafe(this);
	if(!stk_inlined(this)&&!stk_inlined(src)){
		if(this->cap!=src->cap){
			register PyObject** ptr=(PyObject**)realloc(this->data,src->cap*sizeof(PyObject*));
			if(__builtin_expect(ptr==nullptr,0)) return false;
			this->data=ptr;
		}
	}
	else if(!stk_inlined(this)&&stk_inlined(src)){
		__builtin_free(this->data);
	}
	else if(stk_inlined(this)&&!stk_inlined(src)){
		this->data=(PyObject**)__builtin_malloc(src->cap*sizeof(PyObject*));
		if(__builtin_expect(this->data==nullptr,0)) return false;
	}
	this->ctrl=src->ctrl;
	this->size=src->size;
	this->cap=src->cap;
	register PyObject**const dst_ptr=stk_data(this);
	register PyObject**const src_ptr=stk_data(src);
	for(register size_t i=0;i<this->size;++i) dst_ptr[i]=Py_NewRef(src_ptr[i]);
	return true;
}

// Move the ownership to another stack
void shinsei_ex_pystack_t_move(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	__builtin_freeData(this);
	asMove(this,src);
	return;
}
void shinsei_ex_pystack_t_moveUnsafe(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	__builtin_freeDataUnsafe(this);
	asMove(this,src);
	return;
}

// Attach the stack from another one
bool shinsei_ex_pystack_t_attach(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	register PyObject** dst_ptr=stk_data(this);
	register PyGILState_STATE g_state=PyGILState_Ensure();
	for(register size_t i=0;i<this->size;++i) Py_DecRef(dst_ptr[i]);
	register const bool des_inlined=stk_inlined(this);
	if(!des_inlined){
		if(this->cap<src->size){
			register PyObject** ptr=(PyObject**)realloc(this->data,src->size*sizeof(PyObject*));
			if(__builtin_expect(ptr==nullptr,0)){
				PyGILState_Release(g_state);
				return false;
			}
			this->data=ptr;
			this->cap=src->size;
		}
	}
	this->ctrl=(src->ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->size=src->size;
	dst_ptr=stk_data(this);
	register PyObject**const src_ptr=stk_data(src);
	for(register size_t i=0;i<this->size;++i) dst_ptr[i]=Py_NewRef(src_ptr[i]);
	PyGILState_Release(g_state);
	return true;
}

bool shinsei_ex_pystack_t_attachUnsafe(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	register PyObject** dst_ptr=stk_data(this);
	for(register size_t i=0;i<this->size;++i) Py_DecRef(dst_ptr[i]);
	register const bool des_inlined=stk_inlined(this);
	if(!des_inlined){
		if(this->cap<src->size){
			register PyObject** ptr=(PyObject**)realloc(this->data,src->size*sizeof(PyObject*));
			if(__builtin_expect(ptr==nullptr,0)) return false;
			this->data=ptr;
			this->cap=src->size;
		}
	}
	this->ctrl=(src->ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->size=src->size;
	dst_ptr=stk_data(this);
	register PyObject**const src_ptr=stk_data(src);
	for(register size_t i=0;i<this->size;++i) dst_ptr[i]=Py_NewRef(src_ptr[i]);
	return true;
}

bool shinsei_ex_pystack_t_attachValue(shinsei_ex_pystack_t*const restrict this,const int_fast32_t ctrl,const size_t size,const size_t cap,PyObject**const ptr)_SHINSEI_OS_NOEXCEPT{
	(void)cap;
	register PyObject** dst_ptr=stk_data(this);
	register PyGILState_STATE g_state=PyGILState_Ensure();
	for(register size_t i=0;i<this->size;++i) Py_DecRef(dst_ptr[i]);
	register const bool des_inlined=stk_inlined(this);
	if(!des_inlined){
		if(this->cap<size){
			register PyObject** new_ptr=(PyObject**)realloc(this->data,size*sizeof(PyObject*));
			if(__builtin_expect(new_ptr==nullptr,0)){
				PyGILState_Release(g_state);
				return false;
			}
			this->data=new_ptr;
			this->cap=size;
		}
	}
	this->ctrl=(ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->size=size;
	dst_ptr=stk_data(this);
	for(register size_t i=0;i<this->size;++i) dst_ptr[i]=Py_NewRef(ptr[i]);
	PyGILState_Release(g_state);
	return true;
}

bool shinsei_ex_pystack_t_attachValueUnsafe(shinsei_ex_pystack_t*const restrict this,const int_fast32_t ctrl,const size_t size,const size_t cap,PyObject**const ptr)_SHINSEI_OS_NOEXCEPT{
	(void)cap;
	register PyObject** dst_ptr=stk_data(this);
	for(register size_t i=0;i<this->size;++i) Py_DecRef(dst_ptr[i]);
	register const bool des_inlined=stk_inlined(this);
	if(!des_inlined){
		if(this->cap<size){
			register PyObject** new_ptr=(PyObject**)realloc(this->data,size*sizeof(PyObject*));
			if(__builtin_expect(new_ptr==nullptr,0)) return false;
			this->data=new_ptr;
			this->cap=size;
		}
	}
	this->ctrl=(ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->size=size;
	dst_ptr=stk_data(this);
	for(register size_t i=0;i<this->size;++i) dst_ptr[i]=Py_NewRef(ptr[i]);
	return true;
}

// Free all elements
void shinsei_ex_pystack_t___builtin_freeData(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	__builtin_freeData(this);
	return;
}
void shinsei_ex_pystack_t___builtin_freeDataUnsafe(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	__builtin_freeDataUnsafe(this);
	return;
}

// Static default constructor
bool shinsei_ex_pystack_t_as(shinsei_ex_pystack_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return stk_as(this);
}

// Static capacity constructor
bool shinsei_ex_pystack_t_asCapacity(shinsei_ex_pystack_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT{
	return conCapacity(this,cap);
}

// Static copy constructor
bool shinsei_ex_pystack_t_asCopy(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	return stk_asCopy(this,src);
}
bool shinsei_ex_pystack_t_asCopyUnsafe(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	return stk_asCopyUnsafe(this,src);
}

// Static move constructor
void shinsei_ex_pystack_t_asMove(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	asMove(this,src);
	return;
}

// Inline default constructor
void shinsei_ex_pystack_t_inl(shinsei_ex_pystack_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT{
	inl(this,cap);
	return;
}

// Inline capacity constructor
void shinsei_ex_pystack_t_inlCapacity(shinsei_ex_pystack_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT{
	inl(this,cap);
	return;
}

// Inline copy constructor
bool shinsei_ex_pystack_t_inlAssign(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->size=src->size;
	this->cap=src->cap;
	register PyObject**const dst_ptr=stk_data(this);
	register PyObject**const src_ptr=stk_data(src);
	register PyGILState_STATE g_state=PyGILState_Ensure();
	for(register size_t i=0;i<this->size;++i) dst_ptr[i]=Py_NewRef(src_ptr[i]);
	PyGILState_Release(g_state);
	return true;
}
bool shinsei_ex_pystack_t_inlAssignUnsafe(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->size=src->size;
	this->cap=src->cap;
	register PyObject**const dst_ptr=stk_data(this);
	register PyObject**const src_ptr=stk_data(src);
	for(register size_t i=0;i<this->size;++i) dst_ptr[i]=Py_NewRef(src_ptr[i]);
	return true;
}

// Inline move constructor
void shinsei_ex_pystack_t_inlMove(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t* const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->size=src->size;
	this->cap=src->cap;
	register PyObject**const dst_ptr=stk_data(this);
	register PyObject**const src_ptr=stk_data(src);
	for(register size_t i=0;i<this->size;++i) dst_ptr[i]=src_ptr[i];
	if(!stk_inlined(src)) __builtin_free(src->data);
	src->ctrl=0;
	src->size=0;
	src->cap=0;
	src->data=nullptr;
	return;
}

// [const] Check if elements are stk_inlined
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
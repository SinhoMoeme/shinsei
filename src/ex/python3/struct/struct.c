#include"shinsei/ex/python3/struct.h"

// [Internal, const] Check if elements are inlined
_SHINSEI_OS_INLINE static bool inlined(const shinsei_ex_pystack_t*const restrict this){
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}

// [Internal, const] Get the element data
_SHINSEI_OS_INLINE static PyObject** data(const shinsei_ex_pystack_t*const restrict this){
	return inlined(this)*(PyObject**)&this->data+!inlined(this)*this->data;
}

// [Internal] Copy the control code
_SHINSEI_OS_INLINE static void copyCtrlExceptsInlined(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src){
	// Copy everything excepts inline bit
	this->ctrl=(this->ctrl&inlined(this))|(src->ctrl&~_SHINSEI_CTRL_INLINED);
	return;
}

// [Internal] Decrease reference counts of all elements
_SHINSEI_OS_INLINE static void decreaseDataRef(shinsei_ex_pystack_t*const restrict this){
	register PyObject**const ptr=data(this);
	register PyGILState_STATE g_state=PyGILState_Ensure();
	for(register size_t i=0;i<this->size;++i) Py_DecRef(ptr[i]);
	PyGILState_Release(g_state);
	return;
}
_SHINSEI_OS_INLINE static void decreaseDataRefUnsafe(shinsei_ex_pystack_t*const restrict this){
	register PyObject**const ptr=data(this);
	for(register size_t i=0;i<this->size;++i) Py_DecRef(ptr[i]);
	return;
}

// [Internal] Free all elements
_SHINSEI_OS_INLINE static void freeData(shinsei_ex_pystack_t*const restrict this){
	decreaseDataRef(this);
	free(this->data);
	return;
}
_SHINSEI_OS_INLINE static void freeDataUnsafe(shinsei_ex_pystack_t*const restrict this){
	decreaseDataRefUnsafe(this);
	free(this->data);
	return;
}

// [Internal] Copy the stack
_SHINSEI_OS_INLINE static bool copyUnsafe(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src){
	if(inlined(this)) decreaseDataRefUnsafe(this);
	else freeDataUnsafe(this);
	this->ctrl=src->ctrl;
	this->size=src->size;
	this->cap=src->cap;
	register PyObject**const old_ptr=data(src);
	register PyObject**const new_ptr=data(this);
	for(register size_t i=0;i<this->size;++i){
		new_ptr[i]=Py_NewRef(old_ptr[i]);
	}
	return;
}

// [Internal] Copy the element values (No conversion)
_SHINSEI_OS_INLINE static void copyValueUnsafe(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src){
	if(inlined(this)) decreaseDataRefUnsafe(this);
	else freeDataUnsafe(this);
	this->size=src->size;
	register PyObject**const old=data(src);
	register PyObject**const new_ptr=data(this);
	for(register size_t i=0;i<this->size;++i){
		new_ptr[i]=Py_NewRef(old_ptr[i]);
	}
	copyCtrlExceptsInlined(this,src);
	return;
}

// [Internal] Move the element data and size
_SHINSEI_OS_INLINE static bool moveDataAndSize(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t*const restrict src){
	// Copy the buffer
	if(this->cap!=src->cap){
		register PyObject** new_data=(PyObject**)malloc(src->cap*sizeof(PyObject*));
		if(__builtin_expect(new_data==nullptr,0)) return false;
		freeDataUnsafe(this);
		this->data=new_data;
		this->cap=src->cap;
	}
	else decreaseDataRefUnsafe(this);
	// Move the content
	if(inlined(this)){
		// Inline source. n copy.
		
	}
	else{
		// Normal source. Zero copy.
		
	}
	// Clear the previous object
	
	return true;
}

// [Internal] Default constructor
_SHINSEI_OS_INLINE static bool con(shinsei_ex_pystack_t*const restrict this){
	this->ctrl=0;
	register size_t cap=shinsei_ex_pystack_t_DEF_CAP;
	do{
		this->data=(PyObject**)malloc(cap*sizeof(PyObject*));
		if(__builtin_expect(this->data!=nullptr,1)) break;
		cap>>=1;
	}
	while(cap);
	if(__builtin_expect(this->data==nullptr,0)) return false;
	this->size=0;
	this->cap=shinsei_ex_pystack_t_DEF_CAP;
	return true;
}

// [Internal] Assign the stack and all elements
_SHINSEI_OS_INLINE static bool assign(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src){
	register PyObject**const new_data=(PyObject**)malloc(src->cap*sizeof(PyObject*));
	if(__builtin_expect(new_data==nullptr,0)) return false;
	this->data=new_data;
	copyCtrl(this,src);
	this->size=src->size;
	this->cap=src->cap;
	register PyGILState_STATE g_state=PyGILState_Ensure();
	for(register size_t i=inlined(this);i<this->size;++i){
		register PyObject*const now=Py_NewRef(data(src)[i]);
		this->data[i]=now;
	}
	PyGILState_Release(g_state);
	return true;
}
_SHINSEI_OS_INLINE static bool assignUnsafe(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src){
	register PyObject**const new_data=(PyObject**)malloc(src->cap*sizeof(PyObject*));
	if(__builtin_expect(new_data==nullptr,0)) return false;
	this->data=new_data;
	copyCtrl(this,src);
	this->size=src->size;
	this->cap=src->cap;
	for(register size_t i=inlined(this);i<this->size;++i){
		register PyObject*const now=Py_NewRef(data(src)[i]);
		this->data[i]=now;
	}
	return true;
}

_SHINSEI_OS_INLINE static void inlFreeData(shinsei_ex_pystack_t*const restrict this){
	register size_t i=0;
	register PyGILState_STATE g_state=PyGILState_Ensure();
	while(i<this->size){
		Py_DecRef(data(this)[i]);
		++i;
	}
	PyGILState_Release(g_state);
	return;
}
_SHINSEI_OS_INLINE static void inlFreeDataUnsafe(shinsei_ex_pystack_t*const restrict this){
	register size_t i=0;
	while(i<this->size){
		Py_DecRef(data(this)[i]);
		++i;
	}
	return;
}
_SHINSEI_OS_INLINE static void genFreeData(shinsei_ex_pystack_t*const restrict this){
	(inlFreeData*inlined(this)+freeData*!inlined(this))(this);
	return;
}
_SHINSEI_OS_INLINE static void genFreeDataUnsafe(shinsei_ex_pystack_t*const restrict this){
	(inlFreeDataUnsafe*inlined(this)+freeDataUnsafe*!inlined(this))(this);
	return;
}

// [Internal] Move the ownership to another stack
_SHINSEI_OS_INLINE static void move(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t*const restrict src){
	copyCtrl(this,src);
	this->size=src->size;
	this->cap=src->cap;
	if(inlined(src)){
		this->data[0]=src->data;
		for(register size_t i=1;i<this->size;++i) this->data[i]=data(src)[i];
	}
	else this->data=src->data;
	src->data=nullptr;
	src->ctrl=0;
	src->size=src->cap=0;
	return;
}
_SHINSEI_OS_INLINE static void incMove(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t*const restrict src){
	__builtin_memcpy(this,src,sizeof(shinsei_ex_pystack_t));
	src->ctrl=_SHINSEI_CTRL_INLINED;
	src->size=0;
	return;
}
_SHINSEI_OS_INLINE static void genMove(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t*const restrict src){
	
}

// Default constructor
shinsei_ex_pystack_t* shinsei_ex_pystack_t_con(){
	register shinsei_ex_pystack_t *const this=(shinsei_ex_pystack_t *const)malloc(sizeof(shinsei_ex_pystack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!con(this),0)){
		free(this);
		return nullptr;
	}
	return this;
}
// Copy constructor
shinsei_ex_pystack_t* shinsei_ex_pystack_t_conAssign(const shinsei_ex_pystack_t*const restrict src){
	register shinsei_ex_pystack_t *const this=(shinsei_ex_pystack_t *const)malloc(sizeof(shinsei_ex_pystack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	this->data=(PyObject**)malloc(src->cap*sizeof(PyObject*));
	if(__builtin_expect(this->data==nullptr,0)){
		free(this);
		return nullptr;
	}
	if(__builtin_expect(!assign(this,src),0)){
		free(this);
		return nullptr;
	}
	return this;
}
// Move constructor
shinsei_ex_pystack_t* shinsei_ex_pystack_t_conMove(shinsei_ex_pystack_t* const restrict src){
	register shinsei_ex_pystack_t *const this=(shinsei_ex_pystack_t *const)malloc(sizeof(shinsei_ex_pystack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	move(this,src);
	return this;
}

// Destructor
void shinsei_ex_pystack_t_dec(shinsei_ex_pystack_t *const restrict this){
	freeData(this);
	free(this);
	return;
}

// Expand capacity by more_cap
bool shinsei_ex_pystack_t_expand(shinsei_ex_pystack_t*const restrict this,const size_t more_cap){
	register PyObject **const ptr=(PyObject **const)realloc(this->data,(this->cap+more_cap)*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap+=more_cap;
	this->data=ptr;
	return true;
}

// Shrink capacity by less_cap
bool shinsei_ex_pystack_t_shrink(shinsei_ex_pystack_t*const restrict this,const size_t less_cap){
	const bool min_triggered=this->cap<=less_cap||this->cap-less_cap<=shinsei_ex_pystack_t_DEF_CAP;
	const size_t new_cap=min_triggered*shinsei_ex_pystack_t_DEF_CAP+!min_triggered*(this->cap-less_cap);
	register PyObject **const ptr=(PyObject **const)realloc(this->data,new_cap*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap-=less_cap;
	this->data=ptr;
	return true;
}
// Reserve for the elements
bool shinsei_ex_pystack_t_reserve(shinsei_ex_pystack_t* const restrict this,const size_t cap){
	const bool min_triggered=cap<shinsei_ex_pystack_t_DEF_CAP;
	const size_t new_cap=min_triggered*shinsei_ex_pystack_t_DEF_CAP+!min_triggered*cap;
	register PyObject **const ptr=(PyObject **const)realloc(this->data,new_cap*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap=new_cap;
	this->data=ptr;
	return true;
}

// Shrink capacity to fit
bool shinsei_ex_pystack_t_shrinkToFit(shinsei_ex_pystack_t* const restrict this){
	const bool min_triggered=this->size<shinsei_ex_pystack_t_DEF_CAP;
	const size_t new_cap=min_triggered*shinsei_ex_pystack_t_DEF_CAP+!min_triggered*this->size;
	register PyObject **const ptr=(PyObject **const)realloc(this->data,new_cap*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap=new_cap;
	this->data=ptr;
	return true;
}

// [Const] Check if stack is empty
bool shinsei_ex_pystack_t_empty(const shinsei_ex_pystack_t*const restrict this){
	return !this->size;
}

// [Const] Get stack size
size_t shinsei_ex_pystack_t_size(const shinsei_ex_pystack_t*const restrict this){
	return this->size;
}

// [Const] Get stack capacity
size_t shinsei_ex_pystack_t_capacity(const shinsei_ex_pystack_t*const restrict this){
	return this->cap;
}

// [Const] Get the top element
PyObject* shinsei_ex_pystack_t_top(const shinsei_ex_pystack_t*const restrict this){
	PyGILState_STATE g_state=PyGILState_Ensure();
	Py_IncRef(this->data[this->size-1]);
	PyGILState_Release(g_state);
	return this->data[this->size-1];
}

// [Const] Get the element at idx
PyObject* shinsei_ex_pystack_t_at(const shinsei_ex_pystack_t*const restrict this,const size_t idx){
	PyGILState_STATE g_state=PyGILState_Ensure();
	Py_IncRef(this->data[idx]);
	PyGILState_Release(g_state);
	return this->data[idx];
}

// [Const] Get the element data
PyObject** shinsei_ex_pystack_t_data(const shinsei_ex_pystack_t*const restrict this){
	return this->data;
}

// Pop the top element
void shinsei_ex_pystack_t_pop(shinsei_ex_pystack_t*const restrict this){
	PyGILState_STATE g_state=PyGILState_Ensure();
	Py_DecRef(this->data[--this->size]);
	PyGILState_Release(g_state);
	if(__builtin_expect(this->size>=this->cap>>2,1)) return;
	shinsei_ex_pystack_t_shrink(this,this->cap>>1);
	return;
}
                 
// Push an element to the top					 
bool shinsei_ex_pystack_t_push(shinsei_ex_pystack_t*const restrict this,const PyObject*const restrict val){
	if(__builtin_expect(this->size==this->cap-1,0)){
		register size_t more_cap=this->cap;
		while(more_cap){
			if(__builtin_expect(shinsei_ex_pystack_t_expand(this,more_cap),1)) break;
			more_cap>>=1;
		}
		if(__builtin_expect(!more_cap,0)) return false;
	}
	PyGILState_STATE gstate=PyGILState_Ensure();
	register const PyObject*const res=Py_NewRef(val);
	PyGILState_Release(gstate);
	this->data[this->size++]=(PyObject*)res;
	return true;
}

// Swap 2 stacks
void shinsei_ex_pystack_t_swap(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t*const restrict src){
	shinsei_ex_pystack_t tmp;
	__builtin_memcpy(&tmp,src,sizeof(shinsei_ex_pystack_t));
	__builtin_memcpy(src,this,sizeof(shinsei_ex_pystack_t));
	__builtin_memcpy(this,&tmp,sizeof(shinsei_ex_pystack_t));
	return;
}

// Clear all elements
void shinsei_ex_pystack_t_clear(shinsei_ex_pystack_t*const restrict this){
	PyGILState_STATE gstate=PyGILState_Ensure();
	register size_t i=0;
	while(i<this->size){
		Py_DECREF(this->data[i]);
		++i;
	}
	PyGILState_Release(gstate);
	this->size=0;
	register PyObject **const ptr=(PyObject **const)realloc(this->data,shinsei_ex_pystack_t_DEF_CAP*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return;
	this->cap=shinsei_ex_pystack_t_DEF_CAP;
	this->data=ptr;
	return;
}

// Set stack size
void shinsei_ex_pystack_t_setSize(shinsei_ex_pystack_t*const restrict this,const size_t size){
	const bool max_triggered=size>this->cap;
	const size_t new_size=max_triggered*this->cap+!max_triggered*size;
	this->size=new_size;
	return;
}

// Assign the stack and all elements
bool shinsei_ex_pystack_t_assign(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src){
	if(this->data) freeData(this);
	return assign(this,src);
}

// Move the ownership to another stack
void shinsei_ex_pystack_t_move(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t* const restrict src){
	if(this->data) freeData(this);
	move(this,src);
	return;
}

// Attach the stack from another one
void shinsei_ex_pystack_t_attach(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src){
	__builtin_memcpy(this,src,sizeof(shinsei_ex_pystack_t));
	return;
}
void shinsei_ex_pystack_t_attachValue(shinsei_ex_pystack_t*const restrict this,const int_fast32_t ctrl,const size_t size,const size_t cap,PyObject**const data){
	this->ctrl=ctrl;
	this->size=size;
	this->cap=cap;
	this->data=data;
	return;
}

// Free all elements
void shinsei_ex_pystack_t_freeData(shinsei_ex_pystack_t*const restrict this){
	freeData(this);
	return;
}

// Static default constructor
bool shinsei_ex_pystack_t_as(shinsei_ex_pystack_t*const restrict this){
	return con(this);
}
// Static copy constructor
bool shinsei_ex_pystack_t_asAssign(shinsei_ex_pystack_t*const restrict this,const shinsei_ex_pystack_t*const restrict src){
	return assign(this,src);
}
// Static move constructor
void shinsei_ex_pystack_t_asMove(shinsei_ex_pystack_t*const restrict this,shinsei_ex_pystack_t* const restrict src){
	move(this,src);
	return;
}
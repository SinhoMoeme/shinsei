#include"shinsei/ex/python3/struct.h"

pystack_t* shinsei_ex_pystack_t_con(){
	pystack_t *const res=(pystack_t *const)malloc(sizeof(pystack_t));
	if(res==nullptr) return nullptr;
	size_t cap=SHINSEI_EX_PYSTACK_T_DEF_CAP;
	do{
		res->data=(PyObject**)malloc(cap*sizeof(PyObject*));
		if(res->data!=nullptr) break;
		cap>>=1;
	}
	while(cap);
	if(res->data==nullptr){
		free(res);
		return nullptr;
	}
	res->size=0;
	res->cap=SHINSEI_EX_PYSTACK_T_DEF_CAP;
	return res;
}
pystack_t* shinsei_ex_pystack_t_conCopy(PyObject **const restrict data,const size_t size,const size_t cap){
	pystack_t*const res=(pystack_t*const)malloc(sizeof(pystack_t));
	if(res==nullptr) return nullptr;
	res->data=data;
	if(__builtin_expect(data==nullptr,0)) res->size=res->cap=0;
	else{
		res->size=size;
		res->cap=cap;
	}
	return res;
}

void shinsei_ex_pystack_t_dec(pystack_t *const restrict this){
	if(__builtin_expect(this->data!=nullptr,1)){
		PyGILState_STATE gstate=PyGILState_Ensure();
		size_t i=0;
		while(__builtin_expect(i<this->size,1)){
			Py_DECREF(this->data[i]);
			++i;
		}
		PyGILState_Release(gstate);
		free(this->data);
	}
	free(this);
	return;
}

bool shinsei_ex_pystack_t_expand(pystack_t*const restrict this,const size_t more_cap){
	PyObject **const ptr=(PyObject**const)realloc(this->data,(this->cap+more_cap)*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap+=more_cap;
	this->data=ptr;
	return true;
}

bool shinsei_ex_pystack_t_shrink(pystack_t*const restrict this,const size_t less_cap){
	size_t new_size;
	if(__builtin_expect(this->cap<=less_cap,0)||this->cap-less_cap<=SHINSEI_EX_PYSTACK_T_DEF_CAP) new_size=SHINSEI_EX_PYSTACK_T_DEF_CAP;
	else new_size=this->cap-less_cap;
	PyObject **const ptr=(PyObject**const)realloc(this->data,new_size*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap-=less_cap;
	this->data=ptr;
	return true;
}

PyObject* shinsei_ex_pystack_t_top(const pystack_t*const restrict this){
	PyGILState_STATE gstate=PyGILState_Ensure();
	Py_IncRef(this->data[this->size-1]);
	PyGILState_Release(gstate);
	return this->data[this->size-1];
}

bool shinsei_ex_pystack_t_empty(const pystack_t*const restrict this){
	return !this->size;
}

size_t shinsei_ex_pystack_t_size(const pystack_t*const restrict this){
	return this->size;
}

void shinsei_ex_pystack_t_pop(pystack_t*const restrict this){
	PyGILState_STATE gstate=PyGILState_Ensure();
	Py_DecRef(this->data[--this->size]);
	PyGILState_Release(gstate);
	if(__builtin_expect(this->size>=this->cap>>2,1)) return;
	shinsei_ex_pystack_t_shrink(this,this->cap>>1);
	return;
}
                                                        
bool shinsei_ex_pystack_t_push(pystack_t*const restrict this,const PyObject*const val){
	if(__builtin_expect(this->size==this->cap-1,0)){
		size_t more_cap=this->cap;
		while(__builtin_expect(more_cap,1)){
			if(__builtin_expect(shinsei_ex_pystack_t_expand(this,more_cap),1)) break;
			more_cap>>=1;
		}
		if(__builtin_expect(!more_cap,0)) return false;
	}
	PyGILState_STATE gstate=PyGILState_Ensure();
	const PyObject*const res=Py_NewRef(val);
	PyGILState_Release(gstate);
	this->data[this->size++]=(PyObject*)res;
	return true;
}

void shinsei_ex_pystack_t_swap(pystack_t*const restrict this,pystack_t*const restrict src){
	pystack_t tmp;
	__builtin_memcpy(&tmp,src,sizeof(pystack_t));
	__builtin_memcpy(src,this,sizeof(pystack_t));
	__builtin_memcpy(this,&tmp,sizeof(pystack_t));
	return;
}

void shinsei_ex_pystack_t_clear(pystack_t*const restrict this){
	PyGILState_STATE gstate=PyGILState_Ensure();
	size_t i=0;
	while(__builtin_expect(i<this->size,1)){
		Py_DECREF(this->data[i]);
		++i;
	}
	PyGILState_Release(gstate);
	this->size=0;
	PyObject **const ptr=(PyObject **const)realloc(this->data,SHINSEI_EX_PYSTACK_T_DEF_CAP*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return;
	this->cap=SHINSEI_EX_PYSTACK_T_DEF_CAP;
	this->data=ptr;
	return;
}
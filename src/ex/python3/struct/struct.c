#include"shinsei/ex/python3/struct.h"

pystack_t* shinsei_ex_pystack_t_conA(){
	pystack_t* res=(pystack_t*)malloc(sizeof(pystack_t));
	res->data=(PyObject**)malloc(SHINSEI_EX_PYSTACK_T_DEF_CAP*sizeof(PyObject*));
	res->size=0;
	res->cap=SHINSEI_EX_PYSTACK_T_DEF_CAP;
	return res;
}
pystack_t* shinsei_ex_pystack_t_conB(PyObject**restrict data,const size_t size,const size_t cap){
	pystack_t* res=(pystack_t*)malloc(sizeof(pystack_t));
	res->data=data;
	if(__builtin_expect(data==nullptr,0)) res->size=res->cap=0;
	else{
		res->size=size;
		res->cap=cap;
	}
	return res;
}

void shinsei_ex_pystack_t_dec(pystack_t*restrict this){
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

bool shinsei_ex_pystack_t_expand(pystack_t*restrict this,const size_t more_cap){
	void* ptr=realloc(this->data,(this->cap+more_cap)*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap+=more_cap;
	this->data=(PyObject**)ptr;
	return true;
}

bool shinsei_ex_pystack_t_shrink(pystack_t*restrict this,const size_t less_cap){
	size_t new_size;
	if(__builtin_expect(this->cap<=less_cap,0)||this->cap-less_cap<=SHINSEI_EX_PYSTACK_T_DEF_CAP) new_size=SHINSEI_EX_PYSTACK_T_DEF_CAP;
	else new_size=this->cap-less_cap;
	void* ptr=realloc(this->data,new_size*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap-=less_cap;
	this->data=(PyObject**)ptr;
	return true;
}

PyObject* shinsei_ex_pystack_t_top(const pystack_t*restrict this){
	PyGILState_STATE gstate=PyGILState_Ensure();
	Py_IncRef(this->data[this->size-1]);
	PyGILState_Release(gstate);
	return this->data[this->size-1];
}

bool shinsei_ex_pystack_t_empty(const pystack_t*restrict this){
	return !this->size;
}

size_t shinsei_ex_pystack_t_size(const pystack_t*restrict this){
	return this->size;
}

void shinsei_ex_pystack_t_pop(pystack_t*restrict this){
	PyGILState_STATE gstate=PyGILState_Ensure();
	Py_DecRef(this->data[--this->size]);
	PyGILState_Release(gstate);
	if(__builtin_expect(this->size>=this->cap>>2,1)) return;
	shinsei_ex_pystack_t_shrink(this,this->cap>>1);
	return;
}
                                                        
bool shinsei_ex_pystack_t_push(pystack_t*restrict this,const PyObject* val){
	if(__builtin_expect(this->size==this->cap-1,0)){
		size_t more_cap=this->cap;
		while(__builtin_expect(more_cap,1)){
			if(__builtin_expect(shinsei_ex_pystack_t_expand(this,more_cap),1)) break;
			more_cap>>=1;
		}
		if(__builtin_expect(!more_cap,0)) return false;
	}
	PyGILState_STATE gstate=PyGILState_Ensure();
	val=Py_NewRef(val);
	PyGILState_Release(gstate);
	this->data[this->size++]=(PyObject*)val;
	return true;
}

void shinsei_ex_pystack_t_swap(pystack_t*restrict this,pystack_t*restrict src){
	pystack_t tmp;
	__builtin_memcpy(&tmp,src,sizeof(pystack_t));
	__builtin_memcpy(src,this,sizeof(pystack_t));
	__builtin_memcpy(this,&tmp,sizeof(pystack_t));
	return;
}

void shinsei_ex_pystack_t_clear(pystack_t*restrict this){
	PyGILState_STATE gstate=PyGILState_Ensure();
	size_t i=0;
	while(__builtin_expect(i<this->size,1)){
		Py_DECREF(this->data[i]);
		++i;
	}
	PyGILState_Release(gstate);
	this->size=0;
	void* ptr=realloc(this->data,SHINSEI_EX_PYSTACK_T_DEF_CAP*sizeof(PyObject*));
	if(__builtin_expect(ptr==nullptr,0)) return;
	this->cap=SHINSEI_EX_PYSTACK_T_DEF_CAP;
	this->data=ptr;
	return;
}
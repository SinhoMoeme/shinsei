#include"shinsei/minimal/struct.h"
#include<string.h>

// object_definition_t

// [Internal, const] Check if elements are inlined
_SHINSEI_OS_INLINE static bool def_inlined(const shinsei_object_definition_t*const restrict this){
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}

// [Internal] Static copy constructor
_SHINSEI_OS_INLINE static void def_asCopy(shinsei_object_definition_t*const restrict this,const shinsei_object_definition_t*const restrict src){
	this->ctrl=src->ctrl;
	this->allocate_callback=src->allocate_callback;
	this->free_callback=src->free_callback;
	return;
}

// [Internal] Static move constructor
_SHINSEI_OS_INLINE static void def_asMove(shinsei_object_definition_t*const restrict this,shinsei_object_definition_t*const restrict src){
	this->ctrl=src->ctrl;
	this->allocate_callback=src->allocate_callback;
	this->free_callback=src->free_callback;
	src->ctrl=0;
	src->allocate_callback=nullptr;
	src->free_callback=nullptr;
	return;
}

// Default constructor
shinsei_object_definition_t* shinsei_object_definition_t_con(shinsei_allocate_copy_callback_t allocate_callback,shinsei_free_callback_t free_callback){
	register shinsei_object_definition_t*const this=(shinsei_object_definition_t*const)malloc(sizeof(shinsei_object_definition_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	this->ctrl=0;
	this->allocate_callback=allocate_callback;
	this->free_callback=free_callback;
	return this;
}

// Copy constructor
shinsei_object_definition_t* shinsei_object_definition_t_conCopy(const shinsei_object_definition_t*const restrict src){
	register shinsei_object_definition_t*const this=(shinsei_object_definition_t*const)malloc(sizeof(shinsei_object_definition_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	def_asCopy(this,src);
	return this;
}

// Move constructor
shinsei_object_definition_t* shinsei_object_definition_t_conMove(shinsei_object_definition_t*const restrict src){
	register shinsei_object_definition_t*const this=(shinsei_object_definition_t*const)malloc(sizeof(shinsei_object_definition_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	def_asMove(this,src);
	return this;
}

// Destructor
void shinsei_object_definition_t_dec(shinsei_object_definition_t*const restrict this){
	free(this);
	return;
}

// [Const] Check if the object definition has an allocate_callback
bool shinsei_object_definition_t_hasAllocateCallback(const shinsei_object_definition_t*const restrict this){
	return this->allocate_callback!=nullptr;
}

// [Const] Check if the object definition has a free_callback
bool shinsei_object_definition_t_hasFreeCallback(const shinsei_object_definition_t*const restrict this){
	return this->free_callback!=nullptr;
}

// Swap 2 object definitions
void shinsei_object_definition_t_swap(shinsei_object_definition_t*const restrict this,shinsei_object_definition_t*const restrict src){
	shinsei_object_definition_t tmp;
	__builtin_memcpy(&tmp,src,sizeof(shinsei_object_definition_t));
	__builtin_memcpy(src,this,sizeof(shinsei_object_definition_t));
	__builtin_memcpy(this,&tmp,sizeof(shinsei_object_definition_t));
	return;
}

// Assign the object definition
void shinsei_object_definition_t_assign(shinsei_object_definition_t*const restrict this,const shinsei_object_definition_t*const restrict src){
	def_asCopy(this,src);
	return;
}

// Move the ownership to another object definition
void shinsei_object_definition_t_move(shinsei_object_definition_t*const restrict this,shinsei_object_definition_t*const restrict src){
	def_asMove(this,src);
	return;
}

// Attach the object definition from another one
void shinsei_object_definition_t_attach(shinsei_object_definition_t*const restrict this,const shinsei_object_definition_t*const restrict src){
	this->ctrl=(src->ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->allocate_callback=src->allocate_callback;
	this->free_callback=src->free_callback;
	return;
}

// Attach the object definition from values
void shinsei_object_definition_t_attachValue(shinsei_object_definition_t*const restrict this,const int_fast32_t ctrl,shinsei_allocate_copy_callback_t allocate_callback,shinsei_free_callback_t free_callback){
	this->ctrl=(ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->allocate_callback=allocate_callback;
	this->free_callback=free_callback;
	return;
}

// Static default constructor
void shinsei_object_definition_t_as(shinsei_object_definition_t*const restrict this,shinsei_allocate_copy_callback_t allocate_callback,shinsei_free_callback_t free_callback){
	this->ctrl=0;
	this->allocate_callback=allocate_callback;
	this->free_callback=free_callback;
	return;
}

// Static copy constructor
void shinsei_object_definition_t_asCopy(shinsei_object_definition_t*const restrict this,const shinsei_object_definition_t*const restrict src){
	def_asCopy(this,src);
	return;
}

// Static move constructor
void shinsei_object_definition_t_asMove(shinsei_object_definition_t*const restrict this,shinsei_object_definition_t*const restrict src){
	def_asMove(this,src);
	return;
}

// Inline default constructor
void shinsei_object_definition_t_inl(shinsei_object_definition_t*const restrict this,shinsei_allocate_copy_callback_t allocate_callback,shinsei_free_callback_t free_callback){
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->allocate_callback=allocate_callback;
	this->free_callback=free_callback;
	return;
}

// Inline copy constructor
void shinsei_object_definition_t_inlCopy(shinsei_object_definition_t*const restrict this,const shinsei_object_definition_t*const restrict src){
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->allocate_callback=src->allocate_callback;
	this->free_callback=src->free_callback;
	return;
}

// Inline move constructor
void shinsei_object_definition_t_inlMove(shinsei_object_definition_t*const restrict this,shinsei_object_definition_t*const restrict src){
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->allocate_callback=src->allocate_callback;
	this->free_callback=src->free_callback;
	src->ctrl=0;
	src->allocate_callback=nullptr;
	src->free_callback=nullptr;
	return;
}

// [const] Check if elements are inlined
bool shinsei_object_definition_t_inlined(const shinsei_object_definition_t*const restrict this){
	return def_inlined(this);
}

// [Const] Get the ctrl code
int_fast32_t shinsei_object_definition_t_getCtrl(const shinsei_object_definition_t*const restrict this){
	return this->ctrl;
}

// Set the ctrl code
void shinsei_object_definition_t_setCtrl(shinsei_object_definition_t*const restrict this,const int_fast32_t ctrl){
	this->ctrl=ctrl;
	return;
}

// object_t

// [Internal, const] Check if elements are inlined
_SHINSEI_OS_INLINE static bool obj_inlined(const shinsei_object_t*const restrict this){
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}

// [Internal] Static copy constructor
_SHINSEI_OS_INLINE static void obj_asCopy(shinsei_object_t*const restrict this,const shinsei_object_t*const restrict src){
	this->ctrl=src->ctrl;
	this->definition=src->definition;
	this->val=src->definition.allocate_callback(src->val);
	return;
}

// [Internal] Static move constructor
_SHINSEI_OS_INLINE static void obj_asMove(shinsei_object_t*const restrict this,shinsei_object_t*const restrict src){
	this->ctrl=src->ctrl;
	this->val=src->val;
	this->definition=src->definition;
	src->ctrl=0;
	src->val=nullptr;
	src->definition.allocate_callback=nullptr;
	src->definition.free_callback=nullptr;
	return;
}

// [Internal] Free all elements
_SHINSEI_OS_INLINE static void obj_freeData(shinsei_object_t*const restrict this){
	this->definition.free_callback((void*)this->val);
	return;
}

// Default constructor
shinsei_object_t* shinsei_object_t_con(const void*const val,shinsei_object_definition_t definition){
	register shinsei_object_t*const this=(shinsei_object_t*const)malloc(sizeof(shinsei_object_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	this->ctrl=0;
	this->val=val;
	this->definition=definition;
	return this;
}

// Copy constructor
shinsei_object_t* shinsei_object_t_conCopy(const shinsei_object_t*const restrict src){
	register shinsei_object_t*const this=(shinsei_object_t*const)malloc(sizeof(shinsei_object_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	obj_asCopy(this,src);
	return this;
}

// Move constructor
shinsei_object_t* shinsei_object_t_conMove(shinsei_object_t*const restrict src){
	register shinsei_object_t*const this=(shinsei_object_t*const)malloc(sizeof(shinsei_object_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	obj_asMove(this,src);
	return this;
}

// Destructor
void shinsei_object_t_dec(shinsei_object_t*const restrict this){
	if(this->val&&this->definition.free_callback) obj_freeData(this);
	free(this);
	return;
}

// [Const] Check if the object has an allocate_callback
bool shinsei_object_t_hasAllocateCallback(const shinsei_object_t*const this){
	return this->definition.allocate_callback!=nullptr;
}

// [Const] Check if the object has a free_callback
bool shinsei_object_t_hasFreeCallback(const shinsei_object_t*const this){
	return this->definition.free_callback!=nullptr;
}

// [Const] Check if the object value is null
bool shinsei_object_t_isNullptr(const shinsei_object_t*const this){
	return this->val==nullptr;
}

// [Const] Get the object value
const void* shinsei_object_t_value(const shinsei_object_t*const this){
	return this->val;
}

// [Const] Get the object definition
shinsei_object_definition_t shinsei_object_t_getDefinition(const shinsei_object_t*const this){
	return this->definition;
}

// Allocate the object
void shinsei_object_t_alloc(shinsei_object_t*const this,const void*const val){
	this->val=val;
	return;
}

// Free the object
void shinsei_object_t_free(shinsei_object_t*const this){
	this->definition.free_callback((void*)this->val);
	this->val=nullptr;
	return;
}

// Set the object definition
void shinsei_object_t_setDefinition(shinsei_object_t*const this,shinsei_object_definition_t definition){
	this->definition=definition;
	return;
}

// Swap 2 objects
void shinsei_object_t_swap(shinsei_object_t*const restrict this,shinsei_object_t*const restrict src){
	shinsei_object_t tmp;
	__builtin_memcpy(&tmp,src,sizeof(shinsei_object_t));
	__builtin_memcpy(src,this,sizeof(shinsei_object_t));
	__builtin_memcpy(this,&tmp,sizeof(shinsei_object_t));
	return;
}

// Assign the object and all elements
void shinsei_object_t_assign(shinsei_object_t*const restrict this,const shinsei_object_t*const restrict src){
	obj_freeData(this);
	obj_asCopy(this,src);
	return;
}

// Move the ownership to another object
void shinsei_object_t_move(shinsei_object_t*const restrict this,shinsei_object_t*const restrict src){
	obj_freeData(this);
	obj_asMove(this,src);
	return;
}

// Attach the object from another one
void shinsei_object_t_attach(shinsei_object_t*const restrict this,const shinsei_object_t*const restrict src){
	obj_freeData(this);
	this->ctrl=(src->ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->val=src->definition.allocate_callback(src->val);
	this->definition=src->definition;
	return;
}

// Attach the object from values
void shinsei_object_t_attachValue(shinsei_object_t*const restrict this,const int_fast32_t ctrl,const void*const val,shinsei_object_definition_t definition){
	obj_freeData(this);
	this->ctrl=(ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->val=definition.allocate_callback(val);
	this->definition=definition;
	return;
}

// Free all elements
void shinsei_object_t_freeData(shinsei_object_t*const restrict this){
	obj_freeData(this);
	return;
}

// Static default constructor
void shinsei_object_t_as(shinsei_object_t*const restrict this,const void*const val,shinsei_object_definition_t definition){
	this->ctrl=0;
	this->val=val;
	this->definition=definition;
	return;
}

// Static copy constructor
void shinsei_object_t_asCopy(shinsei_object_t*const restrict this,const shinsei_object_t*const restrict src){
	obj_asCopy(this,src);
	return;
}

// Static move constructor
void shinsei_object_t_asMove(shinsei_object_t*const restrict this,shinsei_object_t*const restrict src){
	obj_asMove(this,src);
	return;
}

// Inline default constructor
void shinsei_object_t_inl(shinsei_object_t*const restrict this,const void*const val,shinsei_object_definition_t definition){
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->val=val;
	this->definition=definition;
	return;
}

// Inline copy constructor
void shinsei_object_t_inlCopy(shinsei_object_t*const restrict this,const shinsei_object_t*const restrict src){
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->definition=src->definition;
	this->val=src->definition.allocate_callback(src->val);
	return;
}

// Inline move constructor
void shinsei_object_t_inlMove(shinsei_object_t*const restrict this,shinsei_object_t*const restrict src){
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->val=src->val;
	this->definition=src->definition;
	src->ctrl=0;
	src->val=nullptr;
	src->definition.allocate_callback=nullptr;
	src->definition.free_callback=nullptr;
	return;
}

// [const] Check if elements are inlined
bool shinsei_object_t_inlined(const shinsei_object_t*const restrict this){
	return obj_inlined(this);
}

// [Const] Get the ctrl code
int_fast32_t shinsei_object_t_getCtrl(const shinsei_object_t*const restrict this){
	return this->ctrl;
}

// Set the ctrl code
void shinsei_object_t_setCtrl(shinsei_object_t*const restrict this,const int_fast32_t ctrl){
	this->ctrl=ctrl;
	return;
}

// stack_t

// [Internal, const] Check if elements are inlined
_SHINSEI_OS_INLINE static bool stk_inlined(const shinsei_stack_t*const restrict this){
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}

// [Internal, const] Get the element data
_SHINSEI_OS_INLINE static char* stk_data(const shinsei_stack_t*const restrict this){
	return (char*)((uintptr_t)&this->data*stk_inlined(this)+!stk_inlined(this)*(uintptr_t)this->data);
}

// [Internal] Default constructor
_SHINSEI_OS_INLINE static bool stk_con(shinsei_stack_t*const restrict this,const size_t element_size){
	this->ctrl=0;
	this->size=0;
	this->cap=shinsei_stack_t_DEF_CAP;
	this->element_size=element_size;
	this->data=(char*)malloc(this->cap*this->element_size);
	return this->data!=nullptr;
}

// [Internal] Static copy constructor
_SHINSEI_OS_INLINE static bool stk_asCopy(shinsei_stack_t*const restrict this,const shinsei_stack_t*const restrict src){
	this->ctrl=src->ctrl;
	this->size=src->size;
	this->cap=src->cap;
	this->element_size=src->element_size;
	if(!stk_inlined(this)){
		this->data=(char*)malloc(this->cap*this->element_size);
		if(__builtin_expect(this->data==nullptr,0)) return false;
	}
	__builtin_memcpy(stk_data(this),stk_data(src),this->size*this->element_size);
	return true;
}

// [Internal] Static move constructor
_SHINSEI_OS_INLINE static void stk_asMove(shinsei_stack_t*const restrict this,shinsei_stack_t*const restrict src){
	this->ctrl=src->ctrl;
	this->size=src->size;
	this->cap=src->cap;
	this->element_size=src->element_size;
	if(stk_inlined(src)){
		__builtin_memcpy(stk_data(this),stk_data(src),this->size*this->element_size);
	}else{
		this->data=src->data;
	}
	src->ctrl=0;
	src->size=0;
	src->cap=0;
	src->data=nullptr;
	return;
}

// [Internal] Inline default constructor
_SHINSEI_OS_INLINE static void vec_inl(shinsei_vector_t*const restrict this,const size_t cap,const size_t element_size){
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->size=0;
	this->cap=cap;
	this->element_size=element_size;
	return;
}

// [Internal] Expand capacity by more_cap
_SHINSEI_OS_INLINE static bool stk_expand(shinsei_stack_t*const restrict this,const size_t more_cap){
	if(stk_inlined(this)){
		this->cap+=more_cap;
		return true;
	}
	register char*const ptr=(char*)realloc(this->data,(this->cap+more_cap)*this->element_size);
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap+=more_cap;
	this->data=ptr;
	return true;
}

// [Internal] Shrink capacity by less_cap
_SHINSEI_OS_INLINE static bool stk_shrink(shinsei_stack_t*const restrict this,const size_t less_cap){
	if(stk_inlined(this)){
		this->cap-=less_cap;
		return true;
	}
	register char*const ptr=(char*)realloc(this->data,(this->cap-less_cap)*this->element_size);
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap-=less_cap;
	this->data=ptr;
	return true;
}

// [Internal] Free all elements
_SHINSEI_OS_INLINE static void stk_freeData(shinsei_stack_t*const restrict this){
	free(this->data);
	return;
}

// [Internal] Batch Add
_SHINSEI_OS_INLINE static bool stk_pushArray(shinsei_stack_t*const restrict this,const void*const restrict arr,const size_t len){
	if(!len) return true;
	if(this->size+len>this->cap){
		register const size_t needed=this->size+len-this->cap;
		if(!stk_expand(this,(needed>shinsei_stack_t_DEF_CAP)*needed+(needed<=shinsei_stack_t_DEF_CAP)*shinsei_stack_t_DEF_CAP)) return false;
	}
	__builtin_memcpy(stk_data(this)+this->size*this->element_size,arr,len*this->element_size);
	this->size+=len;
	return true;
}
_SHINSEI_OS_INLINE static bool stk_pushElement(shinsei_stack_t*const restrict this,const void*const restrict val,const size_t cnt){
	if(!cnt) return true;
	if(this->size+cnt>this->cap){
		register const size_t needed=this->size+cnt-this->cap;
		if(!stk_expand(this,(needed>shinsei_stack_t_DEF_CAP)*needed+(needed<=shinsei_stack_t_DEF_CAP)*shinsei_stack_t_DEF_CAP)) return false;
	}
	register char*const dst=stk_data(this);
	for(register size_t i=0;i<cnt;++i) __builtin_memcpy(dst+(this->size+i)*this->element_size,val,this->element_size);
	this->size+=cnt;
	return true;
}

// [Internal] Batch Remove
_SHINSEI_OS_INLINE static void stk_popArray(shinsei_stack_t*const restrict this,const size_t cnt){
	register const size_t safe_cnt=(cnt>this->size)*this->size+(cnt<=this->size)*cnt;
	this->size-=safe_cnt;
	if(stk_inlined(this)) return;
	if(__builtin_expect(this->size>=this->cap>>2,1)) return;
	stk_shrink(this,this->cap>>1);
	return;
}

// [Internal] Capacity constructor
_SHINSEI_OS_INLINE static bool stk_conCapacity(shinsei_stack_t*const restrict this,const size_t cap,const size_t element_size){
	this->ctrl=0;
	this->size=0;
	this->cap=cap;
	this->element_size=element_size;
	this->data=(char*)malloc(this->cap*this->element_size);
	return this->data!=nullptr;
}

// [Internal] Element constructor
_SHINSEI_OS_INLINE static bool stk_asElement(shinsei_stack_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size){
	this->ctrl=0;
	this->size=cnt;
	this->cap=cnt+!cnt*shinsei_stack_t_DEF_CAP;
	this->element_size=element_size;
	this->data=(char*)malloc(this->cap*this->element_size);
	if(__builtin_expect(this->data==nullptr,0)) return false;
	register char*const dst=stk_data(this);
	for(register size_t i=0;i<cnt;++i) __builtin_memcpy(dst+i*element_size,val,element_size);
	return true;
}

// [Internal] Array constructor
_SHINSEI_OS_INLINE static bool stk_asArray(shinsei_stack_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size){
	this->ctrl=0;
	this->size=len;
	this->cap=len+!len*shinsei_stack_t_DEF_CAP;
	this->element_size=element_size;
	this->data=(char*)malloc(this->cap*this->element_size);
	if(__builtin_expect(this->data==nullptr,0)) return false;
	__builtin_memcpy(stk_data(this),arr,len*element_size);
	return true;
}

// Default constructor
shinsei_stack_t* shinsei_stack_t_con(const size_t element_size){
	register shinsei_stack_t*const this=(shinsei_stack_t*const)malloc(sizeof(shinsei_stack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!stk_con(this,element_size),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Capacity constructor
shinsei_stack_t* shinsei_stack_t_conCapacity(const size_t cap,const size_t element_size){
	register shinsei_stack_t*const this=(shinsei_stack_t*const)malloc(sizeof(shinsei_stack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!stk_conCapacity(this,cap,element_size),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Copy constructor
shinsei_stack_t* shinsei_stack_t_conCopy(const shinsei_stack_t*const restrict src){
	register shinsei_stack_t*const this=(shinsei_stack_t*const)malloc(sizeof(shinsei_stack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!stk_asCopy(this,src),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Move constructor
shinsei_stack_t* shinsei_stack_t_conMove(shinsei_stack_t*const restrict src){
	register shinsei_stack_t*const this=(shinsei_stack_t*const)malloc(sizeof(shinsei_stack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	stk_asMove(this,src);
	return this;
}

// Element constructor
shinsei_stack_t* shinsei_stack_t_conElement(const void*const restrict val,const size_t cnt,const size_t element_size){
	register shinsei_stack_t*const this=(shinsei_stack_t*const)malloc(sizeof(shinsei_stack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!stk_asElement(this,val,cnt,element_size),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Array constructor
shinsei_stack_t* shinsei_stack_t_conArray(const void*const restrict arr,const size_t len,const size_t element_size){
	register shinsei_stack_t*const this=(shinsei_stack_t*const)malloc(sizeof(shinsei_stack_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!stk_asArray(this,arr,len,element_size),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Destructor
void shinsei_stack_t_dec(shinsei_stack_t*const restrict this){
	if(!stk_inlined(this)) stk_freeData(this);
	free(this);
	return;
}

// Expand capacity by more_cap
bool shinsei_stack_t_expand(shinsei_stack_t*const restrict this,const size_t more_cap){
	return stk_expand(this,more_cap);
}

// Shrink capacity by less_cap
bool shinsei_stack_t_shrink(shinsei_stack_t*const restrict this,const size_t less_cap){
	return stk_shrink(this,less_cap);
}

// Reserve for the elements
bool shinsei_stack_t_reserve(shinsei_stack_t*const restrict this,const size_t cap){
	if(stk_inlined(this)){
		this->cap=cap;
		return true;
	}
	register char*const ptr=(char*)realloc(this->data,cap*this->element_size);
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap=cap;
	this->data=ptr;
	return true;
}

// Shrink capacity to fit
bool shinsei_stack_t_shrinkToFit(shinsei_stack_t*const restrict this){
	if(stk_inlined(this)){
		this->cap=this->size;
		return true;
	}
	register char*const ptr=(char*)realloc(this->data,this->size*this->element_size);
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap=this->size;
	this->data=ptr;
	return true;
}

// [Const] Check if stack is empty
bool shinsei_stack_t_empty(const shinsei_stack_t*const restrict this){
	return !this->size;
}

// [Const] Get stack size
size_t shinsei_stack_t_size(const shinsei_stack_t*const restrict this){
	return this->size;
}

// [Const] Get stack capacity
size_t shinsei_stack_t_capacity(const shinsei_stack_t*const restrict this){
	return this->cap;
}

// [Const] Get the top element
void* shinsei_stack_t_top(const shinsei_stack_t*const restrict this){
	return stk_data(this)+(this->size-1)*this->element_size;
}

// [Const] Get the element at idx
void* shinsei_stack_t_at(const shinsei_stack_t*const restrict this,const size_t idx){
	return stk_data(this)+idx*this->element_size;
}

// [Const] Get the element data
void* shinsei_stack_t_data(const shinsei_stack_t*const restrict this){
	return stk_data(this);
}

// Pop the top element
void shinsei_stack_t_pop(shinsei_stack_t*const restrict this){
	stk_popArray(this,1);
	return;
}
void shinsei_stack_t_popArray(shinsei_stack_t*const restrict this,const size_t cnt){
	stk_popArray(this,cnt);
	return;
}

// Push an element to the top
bool shinsei_stack_t_push(shinsei_stack_t*const restrict this,const void*const restrict val){
	return stk_pushElement(this,val,1);
}
bool shinsei_stack_t_pushArray(shinsei_stack_t*const restrict this,const void*const restrict arr,const size_t len){
	return stk_pushArray(this,arr,len);
}
bool shinsei_stack_t_pushElement(shinsei_stack_t*const restrict this,const void*const restrict val,const size_t cnt){
	return stk_pushElement(this,val,cnt);
}

// Swap 2 stacks
void shinsei_stack_t_swap(shinsei_stack_t*const restrict this,shinsei_stack_t*const restrict src){
	shinsei_stack_t tmp;
	__builtin_memcpy(&tmp,src,sizeof(shinsei_stack_t));
	__builtin_memcpy(src,this,sizeof(shinsei_stack_t));
	__builtin_memcpy(this,&tmp,sizeof(shinsei_stack_t));
	return;
}

// Clear all elements
bool shinsei_stack_t_clear(shinsei_stack_t*const restrict this){
	this->size=0;
	if(!stk_inlined(this)){
		register char*const new_ptr=(char*)realloc(this->data,shinsei_stack_t_DEF_CAP*this->element_size);
		if(__builtin_expect(new_ptr==nullptr,0)) return false;
		this->cap=shinsei_stack_t_DEF_CAP;
		this->data=new_ptr;
	}
	return true;
}

// Set stack size
bool shinsei_stack_t_setSize(shinsei_stack_t*const restrict this,const size_t size){
	if(size>this->cap){
		if(!shinsei_stack_t_reserve(this,size)) return false;
	}
	this->size=size;
	return true;
}

// Assign the stack and all elements
bool shinsei_stack_t_assign(shinsei_stack_t*const restrict this,const shinsei_stack_t*const restrict src){
	stk_freeData(this);
	if(!stk_inlined(this)&&!stk_inlined(src)){
		if(this->cap!=src->cap){
			register char* ptr=(char*)realloc(this->data,src->cap*this->element_size);
			if(__builtin_expect(ptr==nullptr,0)) return false;
			this->data=ptr;
		}
	}
	else if(!stk_inlined(this)&&stk_inlined(src)){
		free(this->data);
	}
	else if(stk_inlined(this)&&!stk_inlined(src)){
		this->data=(char*)malloc(src->cap*this->element_size);
		if(__builtin_expect(this->data==nullptr,0)) return false;
	}
	this->ctrl=src->ctrl;
	this->size=src->size;
	this->cap=src->cap;
	this->element_size=src->element_size;
	__builtin_memcpy(stk_data(this),stk_data(src),this->size*this->element_size);
	return true;
}

// Move the ownership to another stack
void shinsei_stack_t_move(shinsei_stack_t*const restrict this,shinsei_stack_t*const restrict src){
	stk_freeData(this);
	stk_asMove(this,src);
	return;
}

// Attach the stack from another one
bool shinsei_stack_t_attach(shinsei_stack_t*const restrict this,const shinsei_stack_t*const restrict src){
	register const bool des_inlined=stk_inlined(this);
	if(!des_inlined){
		if(this->cap<src->size){
			register char* ptr=(char*)realloc(this->data,src->size*this->element_size);
			if(__builtin_expect(ptr==nullptr,0)) return false;
			this->data=ptr;
			this->cap=src->size;
		}
	}
	this->ctrl=(src->ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->size=src->size;
	__builtin_memcpy(stk_data(this),stk_data(src),this->size*this->element_size);
	return true;
}

// Attach the stack from values
bool shinsei_stack_t_attachValue(shinsei_stack_t*const restrict this,const int_fast32_t ctrl,const size_t size,const size_t cap,void*const ptr,const size_t element_size){
	(void)cap;
	register const bool des_inlined=stk_inlined(this);
	this->element_size=element_size;
	if(!des_inlined){
		if(this->cap<size){
			register char* new_ptr=(char*)realloc(this->data,size*this->element_size);
			if(__builtin_expect(new_ptr==nullptr,0)) return false;
			this->data=new_ptr;
			this->cap=size;
		}
	}
	this->ctrl=(ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->size=size;
	__builtin_memcpy(stk_data(this),ptr,this->size*this->element_size);
	return true;
}

// Free all elements
void shinsei_stack_t_freeData(shinsei_stack_t*const restrict this){
	stk_freeData(this);
	return;
}

// Static default constructor
bool shinsei_stack_t_as(shinsei_stack_t*const restrict this,const size_t element_size){
	return stk_con(this,element_size);
}
// Static capacity constructor
bool shinsei_stack_t_asCapacity(shinsei_stack_t*const restrict this,const size_t cap,const size_t element_size){
	return stk_conCapacity(this,cap,element_size);
}
// Static copy constructor
bool shinsei_stack_t_asCopy(shinsei_stack_t*const restrict this,const shinsei_stack_t*const restrict src){
	return stk_asCopy(this,src);
}

// Static move constructor
void shinsei_stack_t_asMove(shinsei_stack_t*const restrict this,shinsei_stack_t*const restrict src){
	stk_asMove(this,src);
	return;
}

bool shinsei_stack_t_asElement(shinsei_stack_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size){
	return stk_asElement(this,val,cnt,element_size);
}

bool shinsei_stack_t_asArray(shinsei_stack_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size){
	return stk_asArray(this,arr,len,element_size);
}

// Inline default constructor
void shinsei_stack_t_inl(shinsei_stack_t*const restrict this,const size_t cap,const size_t element_size){
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->size=0;
	this->cap=cap;
	this->element_size=element_size;
	return;
}
// Inline capacity constructor
void shinsei_stack_t_inlCapacity(shinsei_stack_t*const restrict this,const size_t cap,const size_t element_size){
	shinsei_stack_t_inl(this,cap,element_size);
	return;
}
// Inline copy constructor
bool shinsei_stack_t_inlCopy(shinsei_stack_t*const restrict this,const shinsei_stack_t*const restrict src){
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->size=src->size;
	this->cap=src->cap;
	this->element_size=src->element_size;
	__builtin_memcpy(stk_data(this),stk_data(src),this->size*this->element_size);
	return true;
}

// Inline move constructor
void shinsei_stack_t_inlMove(shinsei_stack_t*const restrict this,shinsei_stack_t*const restrict src){
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->size=src->size;
	this->cap=src->cap;
	this->element_size=src->element_size;
	__builtin_memcpy(stk_data(this),stk_data(src),this->size*this->element_size);
	if(!stk_inlined(src)) free(src->data);
	src->ctrl=0;
	src->size=0;
	src->cap=0;
	src->data=nullptr;
	return;
}

void shinsei_stack_t_inlElement(shinsei_stack_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size){
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->size=cnt;
	this->cap=cnt;
	this->element_size=element_size;
	register char*const dst=stk_data(this);
	for(register size_t i=0;i<cnt;++i) __builtin_memcpy(dst+i*element_size,val,element_size);
	return;
}

void shinsei_stack_t_inlArray(shinsei_stack_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size){
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->size=len;
	this->cap=len;
	this->element_size=element_size;
	__builtin_memcpy(stk_data(this),arr,len*element_size);
	return;
}


// [const] Check if elements are inlined
bool shinsei_stack_t_inlined(const shinsei_stack_t*const restrict this){
	return stk_inlined(this);
}

// [Const] Get the ctrl code
int_fast32_t shinsei_stack_t_getCtrl(const shinsei_stack_t*const restrict this){
	return this->ctrl;
}

// Set the ctrl code
void shinsei_stack_t_setCtrl(shinsei_stack_t*const restrict this,const int_fast32_t ctrl){
	this->ctrl=ctrl;
	return;
}

// queue_t

// [Internal, const] Check if elements are inlined
_SHINSEI_OS_INLINE static bool que_inlined(const shinsei_queue_t*const restrict this){
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}

// [Internal, const] Get the element data
_SHINSEI_OS_INLINE static char* que_data(const shinsei_queue_t*const restrict this){
	return (char*)((uintptr_t)&this->data*que_inlined(this)+!que_inlined(this)*(uintptr_t)this->data);
}

// [Internal] Default constructor
_SHINSEI_OS_INLINE static bool que_con(shinsei_queue_t*const restrict this,const size_t element_size){
	this->ctrl=0;
	this->head=0;
	this->tail=0;
	this->cap=shinsei_queue_t_DEF_CAP;
	this->element_size=element_size;
	// Real capacity is cap+1 (1 is for distinguishing empty and full)
	this->data=(char*)malloc((this->cap+1)*this->element_size);
	return this->data!=nullptr;
}

// [Internal] Capacity constructor
_SHINSEI_OS_INLINE static bool que_conCapacity(shinsei_queue_t*const restrict this,const size_t cap,const size_t element_size){
	this->ctrl=0;
	this->head=0;
	this->tail=0;
	this->cap=cap;
	this->element_size=element_size;
	// Real capacity is cap+1 (1 is for distinguishing empty and full)
	this->data=(char*)malloc((this->cap+1)*this->element_size);
	return this->data!=nullptr;
}

// [Internal] Static copy constructor
_SHINSEI_OS_INLINE static bool que_asCopy(shinsei_queue_t*const restrict this,const shinsei_queue_t*const restrict src){
	this->ctrl=src->ctrl;
	this->head=src->head;
	this->tail=src->tail;
	this->cap=src->cap;
	this->element_size=src->element_size;
	if(!que_inlined(this)){
		this->data=(char*)malloc((this->cap+1)*this->element_size);
		if(__builtin_expect(this->data==nullptr,0)) return false;
	}
	__builtin_memcpy(que_data(this),que_data(src),(this->cap+1)*this->element_size);
	return true;
}

// [Internal] Static move constructor
_SHINSEI_OS_INLINE static void que_asMove(shinsei_queue_t*const restrict this,shinsei_queue_t*const restrict src){
	this->ctrl=src->ctrl;
	this->head=src->head;
	this->tail=src->tail;
	this->cap=src->cap;
	this->element_size=src->element_size;
	if(que_inlined(src)){
		__builtin_memcpy(que_data(this),que_data(src),(this->cap+1)*this->element_size);
	}else{
		this->data=src->data;
	}
	src->ctrl=0;
	src->head=0;
	src->tail=0;
	src->cap=0;
	src->data=nullptr;
	return;
}

// [Internal, Const] Get queue size
_SHINSEI_OS_INLINE static size_t que_size(const shinsei_queue_t*const restrict this){
	register const size_t res=(this->head<=this->tail)*(this->tail-this->head)+(this->head>this->tail)*(this->cap+1-this->head+this->tail);
	return res;
}

// [Internal] Free all elements
_SHINSEI_OS_INLINE static void que_freeData(shinsei_queue_t*const restrict this){
	free(this->data);
	return;
}

// [Internal] Reallocate and unwrap to contiguous block
_SHINSEI_OS_INLINE static bool que_reallocUnwrap(shinsei_queue_t*const restrict this,const size_t new_cap){
	register char*const new_data=(char*)malloc((new_cap+1)*this->element_size);
	if(__builtin_expect(new_data==nullptr,0)) return false;
	register const size_t sz=que_size(this);
	register char*const old_buf=que_data(this);
	for(register size_t i=0;i<sz;++i){
		__builtin_memcpy(new_data+i*this->element_size,old_buf+((this->head+i)%(this->cap+1))*this->element_size,this->element_size);
	}
	if(!que_inlined(this)) free(this->data);
	this->data=new_data;
	this->head=0;
	this->tail=sz;
	this->cap=new_cap;
	return true;
}

// [Internal] Batch Add
_SHINSEI_OS_INLINE static bool que_pushArray(shinsei_queue_t*const restrict this,const void*const restrict arr,const size_t len){
	if(!len) return true;
	register const size_t sz=que_size(this);
	if(sz+len>this->cap){
		register const size_t needed=sz+len-this->cap;
		if(!que_reallocUnwrap(this,this->cap+((needed>shinsei_queue_t_DEF_CAP)*needed+(needed<=shinsei_queue_t_DEF_CAP)*shinsei_queue_t_DEF_CAP))) return false;
	}
	register char*const dst=que_data(this);
	register const char*const src=(const char*)arr;
	for(register size_t i=0;i<len;++i){
		__builtin_memcpy(dst+this->tail*this->element_size,src+i*this->element_size,this->element_size);
		this->tail=(this->tail+1)%(this->cap+1);
	}
	return true;
}

_SHINSEI_OS_INLINE static bool que_pushElement(shinsei_queue_t*const restrict this,const void*const restrict val,const size_t cnt){
	if(!cnt) return true;
	register const size_t sz=que_size(this);
	if(sz+cnt>this->cap){
		register const size_t needed=sz+cnt-this->cap;
		if(!que_reallocUnwrap(this,this->cap+((needed>shinsei_queue_t_DEF_CAP)*needed+(needed<=shinsei_queue_t_DEF_CAP)*shinsei_queue_t_DEF_CAP))) return false;
	}
	register char*const dst=que_data(this);
	for(register size_t i=0;i<cnt;++i){
		__builtin_memcpy(dst+this->tail*this->element_size,val,this->element_size);
		this->tail=(this->tail+1)%(this->cap+1);
	}
	return true;
}

// [Internal] Batch Remove
_SHINSEI_OS_INLINE static void que_popArray(shinsei_queue_t*const restrict this,const size_t cnt){
	register const size_t sz=que_size(this);
	register const size_t safe_cnt=(cnt>sz)*sz+(cnt<=sz)*cnt;
	this->head=(this->head+safe_cnt)%(this->cap+1);
	if(que_inlined(this)) return;
	if(__builtin_expect(que_size(this)>=this->cap>>2,1)) return;
	shinsei_queue_t_shrink(this,this->cap>>1);
}

// [Internal] Element constructor
_SHINSEI_OS_INLINE static bool que_asElement(shinsei_queue_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size){
	this->ctrl=0;
	this->head=0;
	this->tail=cnt;
	this->cap=cnt+!cnt*shinsei_queue_t_DEF_CAP;
	this->element_size=element_size;
	this->data=(char*)malloc((this->cap+1)*this->element_size);
	if(__builtin_expect(this->data==nullptr,0)) return false;
	register char*const dst=que_data(this);
	for(register size_t i=0;i<cnt;++i) __builtin_memcpy(dst+i*element_size,val,element_size);
	return true;
}

// [Internal] Array constructor
_SHINSEI_OS_INLINE static bool que_asArray(shinsei_queue_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size){
	this->ctrl=0;
	this->head=0;
	this->tail=len;
	this->cap=len+!len*shinsei_queue_t_DEF_CAP;
	this->element_size=element_size;
	this->data=(char*)malloc((this->cap+1)*this->element_size);
	if(__builtin_expect(this->data==nullptr,0)) return false;
	__builtin_memcpy(que_data(this),arr,len*element_size);
	return true;
}

// Default constructor
shinsei_queue_t* shinsei_queue_t_con(const size_t element_size){
	register shinsei_queue_t*const this=(shinsei_queue_t*const)malloc(sizeof(shinsei_queue_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!que_con(this,element_size),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Capacity constructor
shinsei_queue_t* shinsei_queue_t_conCapacity(const size_t cap,const size_t element_size){
	register shinsei_queue_t*const this=(shinsei_queue_t*const)malloc(sizeof(shinsei_queue_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!que_conCapacity(this,cap,element_size),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Copy constructor
shinsei_queue_t* shinsei_queue_t_conCopy(const shinsei_queue_t*const restrict src){
	register shinsei_queue_t*const this=(shinsei_queue_t*const)malloc(sizeof(shinsei_queue_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!que_asCopy(this,src),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Move constructor
shinsei_queue_t* shinsei_queue_t_conMove(shinsei_queue_t*const restrict src){
	register shinsei_queue_t*const this=(shinsei_queue_t*const)malloc(sizeof(shinsei_queue_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	que_asMove(this,src);
	return this;
}

// Element constructor
shinsei_queue_t* shinsei_queue_t_conElement(const void*const restrict val,const size_t cnt,const size_t element_size){
	register shinsei_queue_t*const this=(shinsei_queue_t*const)malloc(sizeof(shinsei_queue_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!que_asElement(this,val,cnt,element_size),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Array constructor
shinsei_queue_t* shinsei_queue_t_conArray(const void*const restrict arr,const size_t len,const size_t element_size){
	register shinsei_queue_t*const this=(shinsei_queue_t*const)malloc(sizeof(shinsei_queue_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!que_asArray(this,arr,len,element_size),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Destructor
void shinsei_queue_t_dec(shinsei_queue_t*const restrict this){
	if(!que_inlined(this)) que_freeData(this);
	free(this);
	return;
}

// Expand capacity by more_cap
bool shinsei_queue_t_expand(shinsei_queue_t*const restrict this,const size_t more_cap){
	if(que_inlined(this)){
		this->cap+=more_cap;
		return true;
	}
	return que_reallocUnwrap(this,this->cap+more_cap);
}

// Shrink capacity by less_cap
bool shinsei_queue_t_shrink(shinsei_queue_t*const restrict this,const size_t less_cap){
	if(que_inlined(this)){
		this->cap-=less_cap;
		return true;
	}
	return que_reallocUnwrap(this,this->cap-less_cap);
}

// Reserve for the elements
bool shinsei_queue_t_reserve(shinsei_queue_t*const restrict this,const size_t cap){
	if(que_inlined(this)){
		this->cap=cap;
		return true;
	}
	return que_reallocUnwrap(this,cap);
}

// Shrink capacity to fit
bool shinsei_queue_t_shrinkToFit(shinsei_queue_t*const restrict this){
	register const size_t sz=que_size(this);
	if(que_inlined(this)){
		this->cap=sz;
		return true;
	}
	return que_reallocUnwrap(this,sz);
}

// [Const] Check if queue is empty
bool shinsei_queue_t_empty(const shinsei_queue_t*const restrict this){
	return this->head==this->tail;
}

// [Const] Get queue size
size_t shinsei_queue_t_size(const shinsei_queue_t*const restrict this){
	return que_size(this);
}

// [Const] Get queue capacity
size_t shinsei_queue_t_capacity(const shinsei_queue_t*const restrict this){
	return this->cap;
}

// [Const] Get the front element
void* shinsei_queue_t_front(const shinsei_queue_t*const restrict this){
	return que_data(this)+this->head*this->element_size;
}

// [Const] Get the back element
void* shinsei_queue_t_back(const shinsei_queue_t*const restrict this){
	return que_data(this)+((this->tail+this->cap)%(this->cap+1))*this->element_size;
}

// [Const] Get the element at idx
void* shinsei_queue_t_at(const shinsei_queue_t*const restrict this,const size_t idx){
	return que_data(this)+((this->head+idx)%(this->cap+1))*this->element_size;
}

// [Const] Get the element data buffer (raw wrapping array)
void* shinsei_queue_t_data(const shinsei_queue_t*const restrict this){
	return que_data(this);
}

// Pop the front element
void shinsei_queue_t_pop(shinsei_queue_t*const restrict this){
	que_popArray(this,1);
	return;
}
void shinsei_queue_t_popArray(shinsei_queue_t*const restrict this,const size_t cnt){
	que_popArray(this,cnt);
	return;
}

// Push an element to the back
bool shinsei_queue_t_push(shinsei_queue_t*const restrict this,const void*const restrict val){
	return que_pushElement(this,val,1);
}
bool shinsei_queue_t_pushArray(shinsei_queue_t*const restrict this,const void*const restrict arr,const size_t len){
	return que_pushArray(this,arr,len);
}
bool shinsei_queue_t_pushElement(shinsei_queue_t*const restrict this,const void*const restrict val,const size_t cnt){
	return que_pushElement(this,val,cnt);
}

// Swap 2 queues
void shinsei_queue_t_swap(shinsei_queue_t*const restrict this,shinsei_queue_t*const restrict src){
	shinsei_queue_t tmp;
	__builtin_memcpy(&tmp,src,sizeof(shinsei_queue_t));
	__builtin_memcpy(src,this,sizeof(shinsei_queue_t));
	__builtin_memcpy(this,&tmp,sizeof(shinsei_queue_t));
	return;
}

// Clear all elements
bool shinsei_queue_t_clear(shinsei_queue_t*const restrict this){
	this->head=0;
	this->tail=0;
	if(!que_inlined(this)){
		register char*const new_ptr=(char*)realloc(this->data,(shinsei_queue_t_DEF_CAP+1)*this->element_size);
		if(__builtin_expect(new_ptr==nullptr,0)) return false;
		this->cap=shinsei_queue_t_DEF_CAP;
		this->data=new_ptr;
	}
	return true;
}

// Set queue size (effectively shifts tail forward)
bool shinsei_queue_t_setSize(shinsei_queue_t*const restrict this,const size_t size){
	if(size>this->cap){
		if(!shinsei_queue_t_reserve(this,size)) return false;
	}
	this->tail=(this->head+size)%(this->cap+1);
	return true;
}

// Assign the queue and all elements
bool shinsei_queue_t_assign(shinsei_queue_t*const restrict this,const shinsei_queue_t*const restrict src){
	que_freeData(this);
	if(!que_inlined(this)&&!que_inlined(src)){
		if(this->cap!=src->cap){
			register char* ptr=(char*)realloc(this->data,(src->cap+1)*this->element_size);
			if(__builtin_expect(ptr==nullptr,0)) return false;
			this->data=ptr;
		}
	}
	else if(!que_inlined(this)&&que_inlined(src)){
		free(this->data);
	}
	else if(que_inlined(this)&&!que_inlined(src)){
		this->data=(char*)malloc((src->cap+1)*this->element_size);
		if(__builtin_expect(this->data==nullptr,0)) return false;
	}
	this->ctrl=src->ctrl;
	this->head=src->head;
	this->tail=src->tail;
	this->cap=src->cap;
	this->element_size=src->element_size;
	__builtin_memcpy(que_data(this),que_data(src),(this->cap+1)*this->element_size);
	return true;
}

// Move the ownership to another queue
void shinsei_queue_t_move(shinsei_queue_t*const restrict this,shinsei_queue_t*const restrict src){
	que_freeData(this);
	que_asMove(this,src);
	return;
}

// Attach the queue from another one
bool shinsei_queue_t_attach(shinsei_queue_t*const restrict this,const shinsei_queue_t*const restrict src){
	register const bool des_inlined=que_inlined(this);
	if(!des_inlined){
		if(this->cap<src->cap){
			register char* ptr=(char*)realloc(this->data,(src->cap+1)*this->element_size);
			if(__builtin_expect(ptr==nullptr,0)) return false;
			this->data=ptr;
			this->cap=src->cap;
		}
	}
	this->ctrl=(src->ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->head=src->head;
	this->tail=src->tail;
	__builtin_memcpy(que_data(this),que_data(src),(this->cap+1)*this->element_size);
	return true;
}

// Attach the queue from values
bool shinsei_queue_t_attachValue(shinsei_queue_t*const restrict this,const int_fast32_t ctrl,const size_t head,const size_t tail,const size_t cap,void*const ptr,const size_t element_size){
	register const bool des_inlined=que_inlined(this);
	this->element_size=element_size;
	if(!des_inlined){
		if(this->cap<cap){
			register char* new_ptr=(char*)realloc(this->data,(cap+1)*this->element_size);
			if(__builtin_expect(new_ptr==nullptr,0)) return false;
			this->data=new_ptr;
			this->cap=cap;
		}
	}
	this->ctrl=(ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->head=head;
	this->tail=tail;
	__builtin_memcpy(que_data(this),ptr,(this->cap+1)*this->element_size);
	return true;
}

// Free all elements
void shinsei_queue_t_freeData(shinsei_queue_t*const restrict this){
	que_freeData(this);
	return;
}

// Static default constructor
bool shinsei_queue_t_as(shinsei_queue_t*const restrict this,const size_t element_size){
	return que_con(this,element_size);
}

// Static capacity constructor
bool shinsei_queue_t_asCapacity(shinsei_queue_t*const restrict this,const size_t cap,const size_t element_size){
	return que_conCapacity(this,cap,element_size);
}

// Static copy constructor
bool shinsei_queue_t_asCopy(shinsei_queue_t*const restrict this,const shinsei_queue_t*const restrict src){
	return que_asCopy(this,src);
}

// Static move constructor
void shinsei_queue_t_asMove(shinsei_queue_t*const restrict this,shinsei_queue_t*const restrict src){
	que_asMove(this,src);
	return;
}

bool shinsei_queue_t_asElement(shinsei_queue_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size){
	return que_asElement(this,val,cnt,element_size);
}

bool shinsei_queue_t_asArray(shinsei_queue_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size){
	return que_asArray(this,arr,len,element_size);
}

// Inline default constructor
void shinsei_queue_t_inl(shinsei_queue_t*const restrict this,const size_t cap,const size_t element_size){
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->head=0;
	this->tail=0;
	this->cap=cap;
	this->element_size=element_size;
	return;
}

// Inline capacity constructor
void shinsei_queue_t_inlCapacity(shinsei_queue_t*const restrict this,const size_t cap,const size_t element_size){
	shinsei_queue_t_inl(this,cap,element_size);
	return;
}

// Inline copy constructor
bool shinsei_queue_t_inlCopy(shinsei_queue_t*const restrict this,const shinsei_queue_t*const restrict src){
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->head=src->head;
	this->tail=src->tail;
	this->cap=src->cap;
	this->element_size=src->element_size;
	__builtin_memcpy(que_data(this),que_data(src),(this->cap+1)*this->element_size);
	return true;
}

// Inline move constructor
void shinsei_queue_t_inlMove(shinsei_queue_t*const restrict this,shinsei_queue_t*const restrict src){
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->head=src->head;
	this->tail=src->tail;
	this->cap=src->cap;
	this->element_size=src->element_size;
	__builtin_memcpy(que_data(this),que_data(src),(this->cap+1)*this->element_size);
	if(!que_inlined(src)) free(src->data);
	src->ctrl=0;
	src->head=0;
	src->tail=0;
	src->cap=0;
	src->data=nullptr;
	return;
}

void shinsei_queue_t_inlElement(shinsei_queue_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size){
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->head=0;
	this->tail=cnt;
	this->cap=cnt;
	this->element_size=element_size;
	register char*const dst=que_data(this);
	for(register size_t i=0;i<cnt;++i) __builtin_memcpy(dst+i*element_size,val,element_size);
	return;
}

void shinsei_queue_t_inlArray(shinsei_queue_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size){
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->head=0;
	this->tail=len;
	this->cap=len;
	this->element_size=element_size;
	__builtin_memcpy(que_data(this),arr,len*element_size);
	return;
}

// [Const] Check if elements are inlined
bool shinsei_queue_t_inlined(const shinsei_queue_t*const restrict this){
	return que_inlined(this);
}

// [Const] Get the ctrl code
int_fast32_t shinsei_queue_t_getCtrl(const shinsei_queue_t*const restrict this){
	return this->ctrl;
}

// Set the ctrl code
void shinsei_queue_t_setCtrl(shinsei_queue_t*const restrict this,const int_fast32_t ctrl){
	this->ctrl=ctrl;
	return;
}

// deque_t

// [Internal, const] Check if elements are inlined
_SHINSEI_OS_INLINE static bool deq_inlined(const shinsei_deque_t*const restrict this){
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}

// [Internal, const] Get the element data
_SHINSEI_OS_INLINE static char* deq_data(const shinsei_deque_t*const restrict this){
	return (char*)((uintptr_t)&this->data*deq_inlined(this)+!deq_inlined(this)*(uintptr_t)this->data);
}

// [Internal] Default constructor
_SHINSEI_OS_INLINE static bool deq_con(shinsei_deque_t*const restrict this,const size_t element_size){
	this->ctrl=0;
	this->head=0;
	this->tail=0;
	this->cap=shinsei_deque_t_DEF_CAP;
	this->element_size=element_size;
	// Real capacity is cap+1 (1 is for distinguishing empty and full)
	this->data=(char*)malloc((this->cap+1)*this->element_size);
	return this->data!=nullptr;
}

// [Internal] Capacity constructor
_SHINSEI_OS_INLINE static bool deq_conCapacity(shinsei_deque_t*const restrict this,const size_t cap,const size_t element_size){
	this->ctrl=0;
	this->head=0;
	this->tail=0;
	this->cap=cap;
	this->element_size=element_size;
	// Real capacity is cap+1 (1 is for distinguishing empty and full)
	this->data=(char*)malloc((this->cap+1)*this->element_size);
	return this->data!=nullptr;
}

// [Internal] Static copy constructor
_SHINSEI_OS_INLINE static bool deq_asCopy(shinsei_deque_t*const restrict this,const shinsei_deque_t*const restrict src){
	this->ctrl=src->ctrl;
	this->head=src->head;
	this->tail=src->tail;
	this->cap=src->cap;
	this->element_size=src->element_size;
	if(!deq_inlined(this)){
		this->data=(char*)malloc((this->cap+1)*this->element_size);
		if(__builtin_expect(this->data==nullptr,0)) return false;
	}
	__builtin_memcpy(deq_data(this),deq_data(src),(this->cap+1)*this->element_size);
	return true;
}

// [Internal] Static move constructor
_SHINSEI_OS_INLINE static void deq_asMove(shinsei_deque_t*const restrict this,shinsei_deque_t*const restrict src){
	this->ctrl=src->ctrl;
	this->head=src->head;
	this->tail=src->tail;
	this->cap=src->cap;
	this->element_size=src->element_size;
	if(deq_inlined(src)){
		__builtin_memcpy(deq_data(this),deq_data(src),(this->cap+1)*this->element_size);
	}else{
		this->data=src->data;
	}
	src->ctrl=0;
	src->head=0;
	src->tail=0;
	src->cap=0;
	src->data=nullptr;
	return;
}

// [Internal, Const] Get deque size
_SHINSEI_OS_INLINE static size_t deq_size(const shinsei_deque_t*const restrict this){
	register const size_t res=(this->head<=this->tail)*(this->tail-this->head)+(this->head>this->tail)*(this->cap+1-this->head+this->tail);
	return res;
}

// [Internal] Free all elements
_SHINSEI_OS_INLINE static void deq_freeData(shinsei_deque_t*const restrict this){
	free(this->data);
	return;
}

// [Internal] Reallocate and unwrap to contiguous block
_SHINSEI_OS_INLINE static bool deq_reallocUnwrap(shinsei_deque_t*const restrict this,const size_t new_cap){
	register char*const new_data=(char*)malloc((new_cap+1)*this->element_size);
	if(__builtin_expect(new_data==nullptr,0)) return false;
	register const size_t sz=deq_size(this);
	register char*const old_buf=deq_data(this);
	for(register size_t i=0;i<sz;++i){
		__builtin_memcpy(new_data+i*this->element_size,old_buf+((this->head+i)%(this->cap+1))*this->element_size,this->element_size);
	}
	if(!deq_inlined(this)) free(this->data);
	this->data=new_data;
	this->head=0;
	this->tail=sz;
	this->cap=new_cap;
	return true;
}

// [Internal] Batch Add Front
_SHINSEI_OS_INLINE static bool deq_pushFrontArray(shinsei_deque_t*const restrict this,const void*const restrict arr,const size_t len){
	if(!len) return true;
	register const size_t sz=deq_size(this);
	if(sz+len>this->cap){
		register const size_t needed=sz+len-this->cap;
		if(!deq_reallocUnwrap(this,this->cap+((needed>shinsei_deque_t_DEF_CAP)*needed+(needed<=shinsei_deque_t_DEF_CAP)*shinsei_deque_t_DEF_CAP))) return false;
	}
	register char*const dst=deq_data(this);
	register const char*const src=(const char*)arr;
	for(register size_t i=len;i>0;--i){
		this->head=(this->head+this->cap)%(this->cap+1);
		__builtin_memcpy(dst+this->head*this->element_size,src+(i-1)*this->element_size,this->element_size);
	}
	return true;
}

_SHINSEI_OS_INLINE static bool deq_pushFrontElement(shinsei_deque_t*const restrict this,const void*const restrict val,const size_t cnt){
	if(!cnt) return true;
	register const size_t sz=deq_size(this);
	if(sz+cnt>this->cap){
		register const size_t needed=sz+cnt-this->cap;
		if(!deq_reallocUnwrap(this,this->cap+((needed>shinsei_deque_t_DEF_CAP)*needed+(needed<=shinsei_deque_t_DEF_CAP)*shinsei_deque_t_DEF_CAP))) return false;
	}
	register char*const dst=deq_data(this);
	for(register size_t i=0;i<cnt;++i){
		this->head=(this->head+this->cap)%(this->cap+1);
		__builtin_memcpy(dst+this->head*this->element_size,val,this->element_size);
	}
	return true;
}

// [Internal] Batch Add Back
_SHINSEI_OS_INLINE static bool deq_pushBackArray(shinsei_deque_t*const restrict this,const void*const restrict arr,const size_t len){
	if(!len) return true;
	register const size_t sz=deq_size(this);
	if(sz+len>this->cap){
		register const size_t needed=sz+len-this->cap;
		if(!deq_reallocUnwrap(this,this->cap+((needed>shinsei_deque_t_DEF_CAP)*needed+(needed<=shinsei_deque_t_DEF_CAP)*shinsei_deque_t_DEF_CAP))) return false;
	}
	register char*const dst=deq_data(this);
	register const char*const src=(const char*)arr;
	for(register size_t i=0;i<len;++i){
		__builtin_memcpy(dst+this->tail*this->element_size,src+i*this->element_size,this->element_size);
		this->tail=(this->tail+1)%(this->cap+1);
	}
	return true;
}

_SHINSEI_OS_INLINE static bool deq_pushBackElement(shinsei_deque_t*const restrict this,const void*const restrict val,const size_t cnt){
	if(!cnt) return true;
	register const size_t sz=deq_size(this);
	if(sz+cnt>this->cap){
		register const size_t needed=sz+cnt-this->cap;
		if(!deq_reallocUnwrap(this,this->cap+((needed>shinsei_deque_t_DEF_CAP)*needed+(needed<=shinsei_deque_t_DEF_CAP)*shinsei_deque_t_DEF_CAP))) return false;
	}
	register char*const dst=deq_data(this);
	for(register size_t i=0;i<cnt;++i){
		__builtin_memcpy(dst+this->tail*this->element_size,val,this->element_size);
		this->tail=(this->tail+1)%(this->cap+1);
	}
	return true;
}

// [Internal] Batch Remove
_SHINSEI_OS_INLINE static void deq_popFrontArray(shinsei_deque_t*const restrict this,const size_t cnt){
	register const size_t sz=deq_size(this);
	register const size_t safe_cnt=(cnt>sz)*sz+(cnt<=sz)*cnt;
	this->head=(this->head+safe_cnt)%(this->cap+1);
	if(deq_inlined(this)) return;
	if(__builtin_expect(deq_size(this)>=this->cap>>2,1)) return;
	shinsei_deque_t_shrink(this,this->cap>>1);
}

_SHINSEI_OS_INLINE static void deq_popBackArray(shinsei_deque_t*const restrict this,const size_t cnt){
	register const size_t sz=deq_size(this);
	register const size_t safe_cnt=(cnt>sz)*sz+(cnt<=sz)*cnt;
	this->tail=(this->tail+this->cap+1-(safe_cnt%(this->cap+1)))%(this->cap+1);
	if(deq_inlined(this)) return;
	if(__builtin_expect(deq_size(this)>=this->cap>>2,1)) return;
	shinsei_deque_t_shrink(this,this->cap>>1);
}

// [Internal] Element constructor
_SHINSEI_OS_INLINE static bool deq_asElement(shinsei_deque_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size){
	this->ctrl=0;
	this->head=0;
	this->tail=cnt;
	this->cap=cnt+!cnt*shinsei_deque_t_DEF_CAP;
	this->element_size=element_size;
	this->data=(char*)malloc((this->cap+1)*this->element_size);
	if(__builtin_expect(this->data==nullptr,0)) return false;
	register char*const dst=deq_data(this);
	for(register size_t i=0;i<cnt;++i) __builtin_memcpy(dst+i*element_size,val,element_size);
	return true;
}

// [Internal] Array constructor
_SHINSEI_OS_INLINE static bool deq_asArray(shinsei_deque_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size){
	this->ctrl=0;
	this->head=0;
	this->tail=len;
	this->cap=len+!len*shinsei_deque_t_DEF_CAP;
	this->element_size=element_size;
	this->data=(char*)malloc((this->cap+1)*this->element_size);
	if(__builtin_expect(this->data==nullptr,0)) return false;
	__builtin_memcpy(deq_data(this),arr,len*element_size);
	return true;
}

// Default constructor
shinsei_deque_t* shinsei_deque_t_con(const size_t element_size){
	register shinsei_deque_t*const this=(shinsei_deque_t*const)malloc(sizeof(shinsei_deque_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!deq_con(this,element_size),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Capacity constructor
shinsei_deque_t* shinsei_deque_t_conCapacity(const size_t cap,const size_t element_size){
	register shinsei_deque_t*const this=(shinsei_deque_t*const)malloc(sizeof(shinsei_deque_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!deq_conCapacity(this,cap,element_size),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Copy constructor
shinsei_deque_t* shinsei_deque_t_conCopy(const shinsei_deque_t*const restrict src){
	register shinsei_deque_t*const this=(shinsei_deque_t*const)malloc(sizeof(shinsei_deque_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!deq_asCopy(this,src),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Move constructor
shinsei_deque_t* shinsei_deque_t_conMove(shinsei_deque_t*const restrict src){
	register shinsei_deque_t*const this=(shinsei_deque_t*const)malloc(sizeof(shinsei_deque_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	deq_asMove(this,src);
	return this;
}

// Element constructor
shinsei_deque_t* shinsei_deque_t_conElement(const void*const restrict val,const size_t cnt,const size_t element_size){
	register shinsei_deque_t*const this=(shinsei_deque_t*const)malloc(sizeof(shinsei_deque_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!deq_asElement(this,val,cnt,element_size),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Array constructor
shinsei_deque_t* shinsei_deque_t_conArray(const void*const restrict arr,const size_t len,const size_t element_size){
	register shinsei_deque_t*const this=(shinsei_deque_t*const)malloc(sizeof(shinsei_deque_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!deq_asArray(this,arr,len,element_size),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Destructor
void shinsei_deque_t_dec(shinsei_deque_t*const restrict this){
	if(!deq_inlined(this)) deq_freeData(this);
	free(this);
	return;
}

// Expand capacity by more_cap
bool shinsei_deque_t_expand(shinsei_deque_t*const restrict this,const size_t more_cap){
	if(deq_inlined(this)){
		this->cap+=more_cap;
		return true;
	}
	return deq_reallocUnwrap(this,this->cap+more_cap);
}

// Shrink capacity by less_cap
bool shinsei_deque_t_shrink(shinsei_deque_t*const restrict this,const size_t less_cap){
	if(deq_inlined(this)){
		this->cap-=less_cap;
		return true;
	}
	return deq_reallocUnwrap(this,this->cap-less_cap);
}

// Reserve for the elements
bool shinsei_deque_t_reserve(shinsei_deque_t*const restrict this,const size_t cap){
	if(deq_inlined(this)){
		this->cap=cap;
		return true;
	}
	return deq_reallocUnwrap(this,cap);
}

// Shrink capacity to fit
bool shinsei_deque_t_shrinkToFit(shinsei_deque_t*const restrict this){
	register const size_t sz=deq_size(this);
	if(deq_inlined(this)){
		this->cap=sz;
		return true;
	}
	return deq_reallocUnwrap(this,sz);
}

// [Const] Check if deque is empty
bool shinsei_deque_t_empty(const shinsei_deque_t*const restrict this){
	return this->head==this->tail;
}

// [Const] Get deque size
size_t shinsei_deque_t_size(const shinsei_deque_t*const restrict this){
	return deq_size(this);
}

// [Const] Get deque capacity
size_t shinsei_deque_t_capacity(const shinsei_deque_t*const restrict this){
	return this->cap;
}

// [Const] Get the front element
void* shinsei_deque_t_front(const shinsei_deque_t*const restrict this){
	return deq_data(this)+this->head*this->element_size;
}

// [Const] Get the back element
void* shinsei_deque_t_back(const shinsei_deque_t*const restrict this){
	return deq_data(this)+((this->tail+this->cap)%(this->cap+1))*this->element_size;
}

// [Const] Get the element at idx
void* shinsei_deque_t_at(const shinsei_deque_t*const restrict this,const size_t idx){
	return deq_data(this)+((this->head+idx)%(this->cap+1))*this->element_size;
}

// [Const] Get the element data buffer (raw wrapping array)
void* shinsei_deque_t_data(const shinsei_deque_t*const restrict this){
	return deq_data(this);
}

// Pop the front element
void shinsei_deque_t_popFront(shinsei_deque_t*const restrict this){
	deq_popFrontArray(this,1);
	return;
}
void shinsei_deque_t_popFrontArray(shinsei_deque_t*const restrict this,const size_t cnt){
	deq_popFrontArray(this,cnt);
	return;
}

// Pop the back element
void shinsei_deque_t_popBack(shinsei_deque_t*const restrict this){
	deq_popBackArray(this,1);
	return;
}
void shinsei_deque_t_popBackArray(shinsei_deque_t*const restrict this,const size_t cnt){
	deq_popBackArray(this,cnt);
	return;
}

// Push an element to the front
bool shinsei_deque_t_pushFront(shinsei_deque_t*const restrict this,const void*const restrict val){
	return deq_pushFrontElement(this,val,1);
}
bool shinsei_deque_t_pushFrontArray(shinsei_deque_t*const restrict this,const void*const restrict arr,const size_t len){
	return deq_pushFrontArray(this,arr,len);
}
bool shinsei_deque_t_pushFrontElement(shinsei_deque_t*const restrict this,const void*const restrict val,const size_t cnt){
	return deq_pushFrontElement(this,val,cnt);
}

// Push an element to the back
bool shinsei_deque_t_pushBack(shinsei_deque_t*const restrict this,const void*const restrict val){
	return deq_pushBackElement(this,val,1);
}
bool shinsei_deque_t_pushBackArray(shinsei_deque_t*const restrict this,const void*const restrict arr,const size_t len){
	return deq_pushBackArray(this,arr,len);
}
bool shinsei_deque_t_pushBackElement(shinsei_deque_t*const restrict this,const void*const restrict val,const size_t cnt){
	return deq_pushBackElement(this,val,cnt);
}

// Swap 2 deques
void shinsei_deque_t_swap(shinsei_deque_t*const restrict this,shinsei_deque_t*const restrict src){
	shinsei_deque_t tmp;
	__builtin_memcpy(&tmp,src,sizeof(shinsei_deque_t));
	__builtin_memcpy(src,this,sizeof(shinsei_deque_t));
	__builtin_memcpy(this,&tmp,sizeof(shinsei_deque_t));
	return;
}

// Clear all elements
bool shinsei_deque_t_clear(shinsei_deque_t*const restrict this){
	this->head=0;
	this->tail=0;
	if(!deq_inlined(this)){
		register char*const new_ptr=(char*)realloc(this->data,(shinsei_deque_t_DEF_CAP+1)*this->element_size);
		if(__builtin_expect(new_ptr==nullptr,0)) return false;
		this->cap=shinsei_deque_t_DEF_CAP;
		this->data=new_ptr;
	}
	return true;
}

// Set deque size (effectively shifts tail forward)
bool shinsei_deque_t_setSize(shinsei_deque_t*const restrict this,const size_t size){
	if(size>this->cap){
		if(!shinsei_deque_t_reserve(this,size)) return false;
	}
	this->tail=(this->head+size)%(this->cap+1);
	return true;
}

// Assign the deque and all elements
bool shinsei_deque_t_assign(shinsei_deque_t*const restrict this,const shinsei_deque_t*const restrict src){
	deq_freeData(this);
	if(!deq_inlined(this)&&!deq_inlined(src)){
		if(this->cap!=src->cap){
			register char* ptr=(char*)realloc(this->data,(src->cap+1)*this->element_size);
			if(__builtin_expect(ptr==nullptr,0)) return false;
			this->data=ptr;
		}
	}
	else if(!deq_inlined(this)&&deq_inlined(src)){
		free(this->data);
	}
	else if(deq_inlined(this)&&!deq_inlined(src)){
		this->data=(char*)malloc((src->cap+1)*this->element_size);
		if(__builtin_expect(this->data==nullptr,0)) return false;
	}
	this->ctrl=src->ctrl;
	this->head=src->head;
	this->tail=src->tail;
	this->cap=src->cap;
	this->element_size=src->element_size;
	__builtin_memcpy(deq_data(this),deq_data(src),(this->cap+1)*this->element_size);
	return true;
}

// Move the ownership to another deque
void shinsei_deque_t_move(shinsei_deque_t*const restrict this,shinsei_deque_t*const restrict src){
	deq_freeData(this);
	deq_asMove(this,src);
	return;
}

// Attach the deque from another one
bool shinsei_deque_t_attach(shinsei_deque_t*const restrict this,const shinsei_deque_t*const restrict src){
	register const bool des_inlined=deq_inlined(this);
	if(!des_inlined){
		if(this->cap<src->cap){
			register char* ptr=(char*)realloc(this->data,(src->cap+1)*this->element_size);
			if(__builtin_expect(ptr==nullptr,0)) return false;
			this->data=ptr;
			this->cap=src->cap;
		}
	}
	this->ctrl=(src->ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->head=src->head;
	this->tail=src->tail;
	__builtin_memcpy(deq_data(this),deq_data(src),(this->cap+1)*this->element_size);
	return true;
}

// Attach the deque from values
bool shinsei_deque_t_attachValue(shinsei_deque_t*const restrict this,const int_fast32_t ctrl,const size_t head,const size_t tail,const size_t cap,void*const ptr,const size_t element_size){
	register const bool des_inlined=deq_inlined(this);
	this->element_size=element_size;
	if(!des_inlined){
		if(this->cap<cap){
			register char* new_ptr=(char*)realloc(this->data,(cap+1)*this->element_size);
			if(__builtin_expect(new_ptr==nullptr,0)) return false;
			this->data=new_ptr;
			this->cap=cap;
		}
	}
	this->ctrl=(ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->head=head;
	this->tail=tail;
	__builtin_memcpy(deq_data(this),ptr,(this->cap+1)*this->element_size);
	return true;
}

// Free all elements
void shinsei_deque_t_freeData(shinsei_deque_t*const restrict this){
	deq_freeData(this);
	return;
}

// Static default constructor
bool shinsei_deque_t_as(shinsei_deque_t*const restrict this,const size_t element_size){
	return deq_con(this,element_size);
}

// Static capacity constructor
bool shinsei_deque_t_asCapacity(shinsei_deque_t*const restrict this,const size_t cap,const size_t element_size){
	return deq_conCapacity(this,cap,element_size);
}

// Static copy constructor
bool shinsei_deque_t_asCopy(shinsei_deque_t*const restrict this,const shinsei_deque_t*const restrict src){
	return deq_asCopy(this,src);
}

// Static move constructor
void shinsei_deque_t_asMove(shinsei_deque_t*const restrict this,shinsei_deque_t*const restrict src){
	deq_asMove(this,src);
	return;
}

bool shinsei_deque_t_asElement(shinsei_deque_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size){
	return deq_asElement(this,val,cnt,element_size);
}

bool shinsei_deque_t_asArray(shinsei_deque_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size){
	return deq_asArray(this,arr,len,element_size);
}

// Inline default constructor
void shinsei_deque_t_inl(shinsei_deque_t*const restrict this,const size_t cap,const size_t element_size){
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->head=0;
	this->tail=0;
	this->cap=cap;
	this->element_size=element_size;
	return;
}

// Inline capacity constructor
void shinsei_deque_t_inlCapacity(shinsei_deque_t*const restrict this,const size_t cap,const size_t element_size){
	shinsei_deque_t_inl(this,cap,element_size);
	return;
}

// Inline copy constructor
bool shinsei_deque_t_inlCopy(shinsei_deque_t*const restrict this,const shinsei_deque_t*const restrict src){
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->head=src->head;
	this->tail=src->tail;
	this->cap=src->cap;
	this->element_size=src->element_size;
	__builtin_memcpy(deq_data(this),deq_data(src),(this->cap+1)*this->element_size);
	return true;
}

// Inline move constructor
void shinsei_deque_t_inlMove(shinsei_deque_t*const restrict this,shinsei_deque_t*const restrict src){
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->head=src->head;
	this->tail=src->tail;
	this->cap=src->cap;
	this->element_size=src->element_size;
	__builtin_memcpy(deq_data(this),deq_data(src),(this->cap+1)*this->element_size);
	if(!deq_inlined(src)) free(src->data);
	src->ctrl=0;
	src->head=0;
	src->tail=0;
	src->cap=0;
	src->data=nullptr;
	return;
}

void shinsei_deque_t_inlElement(shinsei_deque_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size){
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->head=0;
	this->tail=cnt;
	this->cap=cnt;
	this->element_size=element_size;
	register char*const dst=deq_data(this);
	for(register size_t i=0;i<cnt;++i) __builtin_memcpy(dst+i*element_size,val,element_size);
	return;
}

void shinsei_deque_t_inlArray(shinsei_deque_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size){
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->head=0;
	this->tail=len;
	this->cap=len;
	this->element_size=element_size;
	__builtin_memcpy(deq_data(this),arr,len*element_size);
	return;
}

// [Const] Check if elements are inlined
bool shinsei_deque_t_inlined(const shinsei_deque_t*const restrict this){
	return deq_inlined(this);
}

// [Const] Get the ctrl code
int_fast32_t shinsei_deque_t_getCtrl(const shinsei_deque_t*const restrict this){
	return this->ctrl;
}

// Set the ctrl code
void shinsei_deque_t_setCtrl(shinsei_deque_t*const restrict this,const int_fast32_t ctrl){
	this->ctrl=ctrl;
	return;
}

// vector_t

// [Internal, const] Check if elements are inlined
_SHINSEI_OS_INLINE static bool vec_inlined(const shinsei_vector_t*const restrict this){
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}

// [Internal, const] Get the element data
_SHINSEI_OS_INLINE static char* vec_data(const shinsei_vector_t*const restrict this){
	return (char*)((uintptr_t)&this->data*vec_inlined(this)+!vec_inlined(this)*(uintptr_t)this->data);
}

// [Internal] Expand capacity by more_cap
_SHINSEI_OS_INLINE static bool vec_expand(shinsei_vector_t*const restrict this,const size_t more_cap){
	if(vec_inlined(this)){
		this->cap+=more_cap;
		return true;
	}
	register char*const ptr=(char*)realloc(this->data,(this->cap+more_cap)*this->element_size);
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap+=more_cap;
	this->data=ptr;
	return true;
}

// [Internal] Shrink capacity by less_cap
_SHINSEI_OS_INLINE static bool vec_shrink(shinsei_vector_t*const restrict this,const size_t less_cap){
	if(vec_inlined(this)){
		this->cap-=less_cap;
		return true;
	}
	register char*const ptr=(char*)realloc(this->data,(this->cap-less_cap)*this->element_size);
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap-=less_cap;
	this->data=ptr;
	return true;
}

// [Internal] Default constructor
_SHINSEI_OS_INLINE static bool vec_con(shinsei_vector_t*const restrict this,const size_t element_size){
	this->ctrl=0;
	this->size=0;
	this->cap=shinsei_vector_t_DEF_CAP;
	this->element_size=element_size;
	this->data=(char*)malloc(this->cap*this->element_size);
	return this->data!=nullptr;
}

// [Internal] Static copy constructor
_SHINSEI_OS_INLINE static bool vec_asCopy(shinsei_vector_t*const restrict this,const shinsei_vector_t*const restrict src){
	this->ctrl=src->ctrl;
	this->size=src->size;
	this->cap=src->cap;
	this->element_size=src->element_size;
	if(!vec_inlined(this)){
		this->data=(char*)malloc(this->cap*this->element_size);
		if(__builtin_expect(this->data==nullptr,0)) return false;
	}
	__builtin_memcpy(vec_data(this),vec_data(src),this->size*this->element_size);
	return true;
}

// [Internal] Static move constructor
_SHINSEI_OS_INLINE static void vec_asMove(shinsei_vector_t*const restrict this,shinsei_vector_t*const restrict src){
	this->ctrl=src->ctrl;
	this->size=src->size;
	this->cap=src->cap;
	this->element_size=src->element_size;
	if(vec_inlined(src)){
		__builtin_memcpy(vec_data(this),vec_data(src),this->size*this->element_size);
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
_SHINSEI_OS_INLINE static void vec_freeData(shinsei_vector_t*const restrict this){
	free(this->data);
	return;
}

// [Internal] Batch Add
_SHINSEI_OS_INLINE static bool vec_pushBackArray(shinsei_vector_t*const restrict this,const void*const restrict arr,const size_t len){
	if(!len) return true;
	if(this->size+len>this->cap){
		register const size_t needed=this->size+len-this->cap;
		if(!vec_expand(this,(needed>shinsei_vector_t_DEF_CAP)*needed+(needed<=shinsei_vector_t_DEF_CAP)*shinsei_vector_t_DEF_CAP)) return false;
	}
	__builtin_memcpy(vec_data(this)+this->size*this->element_size,arr,len*this->element_size);
	this->size+=len;
	return true;
}
_SHINSEI_OS_INLINE static bool vec_pushBackElement(shinsei_vector_t*const restrict this,const void*const restrict val,const size_t cnt){
	if(!cnt) return true;
	if(this->size+cnt>this->cap){
		register const size_t needed=this->size+cnt-this->cap;
		if(!vec_expand(this,(needed>shinsei_vector_t_DEF_CAP)*needed+(needed<=shinsei_vector_t_DEF_CAP)*shinsei_vector_t_DEF_CAP)) return false;
	}
	register char*const dst=vec_data(this);
	for(register size_t i=0;i<cnt;++i) __builtin_memcpy(dst+(this->size+i)*this->element_size,val,this->element_size);
	this->size+=cnt;
	return true;
}

// [Internal] Batch Remove
_SHINSEI_OS_INLINE static void vec_popBackArray(shinsei_vector_t*const restrict this,const size_t cnt){
	register const size_t safe_cnt=(cnt>this->size)*this->size+(cnt<=this->size)*cnt;
	this->size-=safe_cnt;
	if(vec_inlined(this)) return;
	if(__builtin_expect(this->size>=this->cap>>2,1)) return;
	vec_shrink(this,this->cap>>1);
}

// [Internal] Insert & Erase Arrays
_SHINSEI_OS_INLINE static bool vec_insertArray(shinsei_vector_t*const restrict this,const size_t idx,const void*const restrict src,const size_t len){
	if(!len) return true;
	register const size_t safe_idx=(idx>this->size)*this->size+(idx<=this->size)*idx;
	if(this->size+len>this->cap){
		register const size_t needed=this->size+len-this->cap;
		if(!vec_expand(this,(needed>shinsei_vector_t_DEF_CAP)*needed+(needed<=shinsei_vector_t_DEF_CAP)*shinsei_vector_t_DEF_CAP)) return false;
	}
	if(__builtin_expect(safe_idx<this->size,1)){
		__builtin_memmove(vec_data(this)+(safe_idx+len)*this->element_size,vec_data(this)+safe_idx*this->element_size,(this->size-safe_idx)*this->element_size);
	}
	__builtin_memcpy(vec_data(this)+safe_idx*this->element_size,src,len*this->element_size);
	this->size+=len;
	return true;
}

_SHINSEI_OS_INLINE static bool vec_insertElement(shinsei_vector_t*const restrict this,const size_t idx,const void*const restrict val,const size_t cnt){
	if(!cnt) return true;
	register const size_t safe_idx=(idx>this->size)*this->size+(idx<=this->size)*idx;
	if(this->size+cnt>this->cap){
		register const size_t needed=this->size+cnt-this->cap;
		if(!vec_expand(this,(needed>shinsei_vector_t_DEF_CAP)*needed+(needed<=shinsei_vector_t_DEF_CAP)*shinsei_vector_t_DEF_CAP)) return false;
	}
	if(__builtin_expect(safe_idx<this->size,1)){
		__builtin_memmove(vec_data(this)+(safe_idx+cnt)*this->element_size,vec_data(this)+safe_idx*this->element_size,(this->size-safe_idx)*this->element_size);
	}
	register char*const dst=vec_data(this);
	for(register size_t i=0;i<cnt;++i) __builtin_memcpy(dst+(safe_idx+i)*this->element_size,val,this->element_size);
	this->size+=cnt;
	return true;
}

_SHINSEI_OS_INLINE static void vec_eraseArray(shinsei_vector_t*const restrict this,const size_t idx,const size_t len){
	if(__builtin_expect(idx>=this->size||!len,0)) return;
	register const size_t safe_len=(idx+len>this->size)*(this->size-idx)+(idx+len<=this->size)*len;
	if(__builtin_expect(idx+safe_len<this->size,1)){
		__builtin_memmove(vec_data(this)+idx*this->element_size,vec_data(this)+(idx+safe_len)*this->element_size,(this->size-idx-safe_len)*this->element_size);
	}
	this->size-=safe_len;
	if(vec_inlined(this)) return;
	if(__builtin_expect(this->size>=this->cap>>2,1)) return;
	vec_shrink(this,this->cap>>1);
}

// [Internal] Capacity constructor
_SHINSEI_OS_INLINE static bool vec_conCapacity(shinsei_vector_t*const restrict this,const size_t cap,const size_t element_size){
	this->ctrl=0;
	this->size=0;
	this->cap=cap;
	this->element_size=element_size;
	this->data=(char*)malloc(this->cap*this->element_size);
	return this->data!=nullptr;
}

// [Internal] Element constructor
_SHINSEI_OS_INLINE static bool vec_asElement(shinsei_vector_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size){
	this->ctrl=0;
	this->size=cnt;
	this->cap=cnt+!cnt*shinsei_vector_t_DEF_CAP;
	this->element_size=element_size;
	this->data=(char*)malloc(this->cap*this->element_size);
	if(__builtin_expect(this->data==nullptr,0)) return false;
	register char*const dst=vec_data(this);
	for(register size_t i=0;i<cnt;++i) __builtin_memcpy(dst+i*element_size,val,element_size);
	return true;
}

// [Internal] Array constructor
_SHINSEI_OS_INLINE static bool vec_asArray(shinsei_vector_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size){
	this->ctrl=0;
	this->size=len;
	this->cap=len+!len*shinsei_vector_t_DEF_CAP;
	this->element_size=element_size;
	this->data=(char*)malloc(this->cap*this->element_size);
	if(__builtin_expect(this->data==nullptr,0)) return false;
	__builtin_memcpy(vec_data(this),arr,len*element_size);
	return true;
}

// Default constructor
shinsei_vector_t* shinsei_vector_t_con(const size_t element_size){
	register shinsei_vector_t*const this=(shinsei_vector_t*const)malloc(sizeof(shinsei_vector_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!vec_con(this,element_size),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Capacity constructor
shinsei_vector_t* shinsei_vector_t_conCapacity(const size_t cap,const size_t element_size){
	register shinsei_vector_t*const this=(shinsei_vector_t*const)malloc(sizeof(shinsei_vector_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!vec_conCapacity(this,cap,element_size),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Copy constructor
shinsei_vector_t* shinsei_vector_t_conCopy(const shinsei_vector_t*const restrict src){
	register shinsei_vector_t*const this=(shinsei_vector_t*const)malloc(sizeof(shinsei_vector_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!vec_asCopy(this,src),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Move constructor
shinsei_vector_t* shinsei_vector_t_conMove(shinsei_vector_t*const restrict src){
	register shinsei_vector_t*const this=(shinsei_vector_t*const)malloc(sizeof(shinsei_vector_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	vec_asMove(this,src);
	return this;
}

// Element constructor
shinsei_vector_t* shinsei_vector_t_conElement(const void*const restrict val,const size_t cnt,const size_t element_size){
	register shinsei_vector_t*const this=(shinsei_vector_t*const)malloc(sizeof(shinsei_vector_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!vec_asElement(this,val,cnt,element_size),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Array constructor
shinsei_vector_t* shinsei_vector_t_conArray(const void*const restrict arr,const size_t len,const size_t element_size){
	register shinsei_vector_t*const this=(shinsei_vector_t*const)malloc(sizeof(shinsei_vector_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!vec_asArray(this,arr,len,element_size),0)){
		free(this);
		return nullptr;
	}
	return this;
}

// Destructor
void shinsei_vector_t_dec(shinsei_vector_t*const restrict this){
	if(!vec_inlined(this)) vec_freeData(this);
	free(this);
	return;
}

// Expand capacity by more_cap
bool shinsei_vector_t_expand(shinsei_vector_t*const restrict this,const size_t more_cap){
	return vec_expand(this,more_cap);
}

// Shrink capacity by less_cap
bool shinsei_vector_t_shrink(shinsei_vector_t*const restrict this,const size_t less_cap){
	return vec_shrink(this,less_cap);
}

// Reserve for the elements
bool shinsei_vector_t_reserve(shinsei_vector_t*const restrict this,const size_t cap){
	if(vec_inlined(this)){
		this->cap=cap;
		return true;
	}
	register char*const ptr=(char*)realloc(this->data,cap*this->element_size);
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap=cap;
	this->data=ptr;
	return true;
}

// Shrink capacity to fit
bool shinsei_vector_t_shrinkToFit(shinsei_vector_t*const restrict this){
	if(vec_inlined(this)){
		this->cap=this->size;
		return true;
	}
	register char*const ptr=(char*)realloc(this->data,this->size*this->element_size);
	if(__builtin_expect(ptr==nullptr,0)) return false;
	this->cap=this->size;
	this->data=ptr;
	return true;
}

// [Const] Check if vector is empty
bool shinsei_vector_t_empty(const shinsei_vector_t*const restrict this){
	return !this->size;
}

// [Const] Get vector size
size_t shinsei_vector_t_size(const shinsei_vector_t*const restrict this){
	return this->size;
}

// [Const] Get vector capacity
size_t shinsei_vector_t_capacity(const shinsei_vector_t*const restrict this){
	return this->cap;
}

// [Const] Get the element at idx
void* shinsei_vector_t_at(const shinsei_vector_t*const restrict this,const size_t idx){
	return vec_data(this)+idx*this->element_size;
}

// [Const] Get the element data
void* shinsei_vector_t_data(const shinsei_vector_t*const restrict this){
	return vec_data(this);
}

// Pop an element from the back
void shinsei_vector_t_popBack(shinsei_vector_t*const restrict this){
	vec_popBackArray(this,1);
	return;
}
void shinsei_vector_t_popBackArray(shinsei_vector_t*const restrict this,const size_t cnt){
	vec_popBackArray(this,cnt);
	return;
}

// Push an element to the back
bool shinsei_vector_t_pushBack(shinsei_vector_t*const restrict this,const void*const restrict val){
	return vec_pushBackElement(this,val,1);
}
bool shinsei_vector_t_pushBackArray(shinsei_vector_t*const restrict this,const void*const restrict arr,const size_t len){
	return vec_pushBackArray(this,arr,len);
}
bool shinsei_vector_t_pushBackElement(shinsei_vector_t*const restrict this,const void*const restrict val,const size_t cnt){
	return vec_pushBackElement(this,val,cnt);
}

// Insert an element at idx
bool shinsei_vector_t_insert(shinsei_vector_t*const restrict this,const size_t idx,const void*const restrict val){
	return vec_insertElement(this,idx,val,1);
}
bool shinsei_vector_t_insertArray(shinsei_vector_t*const restrict this,const size_t idx,const void*const restrict src,const size_t len){
	return vec_insertArray(this,idx,src,len);
}
bool shinsei_vector_t_insertElement(shinsei_vector_t*const restrict this,const size_t idx,const void*const restrict val,const size_t cnt){
	return vec_insertElement(this,idx,val,cnt);
}

// Erase an element at idx
void shinsei_vector_t_erase(shinsei_vector_t*const restrict this,const size_t idx){
	vec_eraseArray(this,idx,1);
	return;
}
void shinsei_vector_t_eraseArray(shinsei_vector_t*const restrict this,const size_t idx,const size_t len){
	vec_eraseArray(this,idx,len);
	return;
}

// Swap 2 vectors
void shinsei_vector_t_swap(shinsei_vector_t*const restrict this,shinsei_vector_t*const restrict src){
	shinsei_vector_t tmp;
	__builtin_memcpy(&tmp,src,sizeof(shinsei_vector_t));
	__builtin_memcpy(src,this,sizeof(shinsei_vector_t));
	__builtin_memcpy(this,&tmp,sizeof(shinsei_vector_t));
	return;
}

// Clear all elements
bool shinsei_vector_t_clear(shinsei_vector_t*const restrict this){
	this->size=0;
	if(!vec_inlined(this)){
		register char*const new_ptr=(char*)realloc(this->data,shinsei_vector_t_DEF_CAP*this->element_size);
		if(__builtin_expect(new_ptr==nullptr,0)) return false;
		this->cap=shinsei_vector_t_DEF_CAP;
		this->data=new_ptr;
	}
	return true;
}

// Set vector size
bool shinsei_vector_t_setSize(shinsei_vector_t*const restrict this,const size_t size){
	if(size>this->cap){
		if(!shinsei_vector_t_reserve(this,size)) return false;
	}
	this->size=size;
	return true;
}

// Assign the vector and all elements
bool shinsei_vector_t_assign(shinsei_vector_t*const restrict this,const shinsei_vector_t*const restrict src){
	vec_freeData(this);
	if(!vec_inlined(this)&&!vec_inlined(src)){
		if(this->cap!=src->cap){
			register char* ptr=(char*)realloc(this->data,src->cap*this->element_size);
			if(__builtin_expect(ptr==nullptr,0)) return false;
			this->data=ptr;
		}
	}
	else if(!vec_inlined(this)&&vec_inlined(src)){
		free(this->data);
	}
	else if(vec_inlined(this)&&!vec_inlined(src)){
		this->data=(char*)malloc(src->cap*this->element_size);
		if(__builtin_expect(this->data==nullptr,0)) return false;
	}
	this->ctrl=src->ctrl;
	this->size=src->size;
	this->cap=src->cap;
	this->element_size=src->element_size;
	__builtin_memcpy(vec_data(this),vec_data(src),this->size*this->element_size);
	return true;
}

// Move the ownership to another vector
void shinsei_vector_t_move(shinsei_vector_t*const restrict this,shinsei_vector_t*const restrict src){
	vec_freeData(this);
	vec_asMove(this,src);
	return;
}

// Attach the vector from another one
bool shinsei_vector_t_attach(shinsei_vector_t*const restrict this,const shinsei_vector_t*const restrict src){
	register const bool des_inlined=vec_inlined(this);
	if(!des_inlined){
		if(this->cap<src->size){
			register char* ptr=(char*)realloc(this->data,src->size*this->element_size);
			if(__builtin_expect(ptr==nullptr,0)) return false;
			this->data=ptr;
			this->cap=src->size;
		}
	}
	this->ctrl=(src->ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->size=src->size;
	__builtin_memcpy(vec_data(this),vec_data(src),this->size*this->element_size);
	return true;
}

// Attach the vector from values
bool shinsei_vector_t_attachValue(shinsei_vector_t*const restrict this,const int_fast32_t ctrl,const size_t size,const size_t cap,void*const ptr,const size_t element_size){
	(void)cap;
	register const bool des_inlined=vec_inlined(this);
	this->element_size=element_size;
	if(!des_inlined){
		if(this->cap<size){
			register char* new_ptr=(char*)realloc(this->data,size*this->element_size);
			if(__builtin_expect(new_ptr==nullptr,0)) return false;
			this->data=new_ptr;
			this->cap=size;
		}
	}
	this->ctrl=(ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->size=size;
	__builtin_memcpy(vec_data(this),ptr,this->size*this->element_size);
	return true;
}

// Free all elements
void shinsei_vector_t_freeData(shinsei_vector_t*const restrict this){
	vec_freeData(this);
	return;
}

// Static default constructor
bool shinsei_vector_t_as(shinsei_vector_t*const restrict this,const size_t element_size){
	return vec_con(this,element_size);
}
// Static capacity constructor
bool shinsei_vector_t_asCapacity(shinsei_vector_t*const restrict this,const size_t cap,const size_t element_size){
	return vec_conCapacity(this,cap,element_size);
}
// Static copy constructor
bool shinsei_vector_t_asCopy(shinsei_vector_t*const restrict this,const shinsei_vector_t*const restrict src){
	return vec_asCopy(this,src);
}
// Static move constructor
void shinsei_vector_t_asMove(shinsei_vector_t*const restrict this,shinsei_vector_t*const restrict src){
	vec_asMove(this,src);
	return;
}
bool shinsei_vector_t_asElement(shinsei_vector_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size){
	return vec_asElement(this,val,cnt,element_size);
}
bool shinsei_vector_t_asArray(shinsei_vector_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size){
	return vec_asArray(this,arr,len,element_size);
}

// Inline default constructor
void shinsei_vector_t_inl(shinsei_vector_t*const restrict this,const size_t cap,const size_t element_size){
	vec_inl(this,cap,element_size);
	return;
}
// Inline capacity constructor
void shinsei_vector_t_inlCapacity(shinsei_vector_t*const restrict this,const size_t cap,const size_t element_size){
	vec_inl(this,cap,element_size);
	return;
}
// Inline copy constructor
bool shinsei_vector_t_inlCopy(shinsei_vector_t*const restrict this,const shinsei_vector_t*const restrict src){
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->size=src->size;
	this->cap=src->cap;
	this->element_size=src->element_size;
	__builtin_memcpy(vec_data(this),vec_data(src),this->size*this->element_size);
	return true;
}
// Inline move constructor
void shinsei_vector_t_inlMove(shinsei_vector_t*const restrict this,shinsei_vector_t*const restrict src){
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->size=src->size;
	this->cap=src->cap;
	this->element_size=src->element_size;
	__builtin_memcpy(vec_data(this),vec_data(src),this->size*this->element_size);
	if(!vec_inlined(src)) free(src->data);
	src->ctrl=0;
	src->size=0;
	src->cap=0;
	src->data=nullptr;
	return;
}
void shinsei_vector_t_inlElement(shinsei_vector_t*const restrict this,const void*const restrict val,const size_t cnt,const size_t element_size){
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->size=cnt;
	this->cap=cnt;
	this->element_size=element_size;
	register char*const dst=vec_data(this);
	for(register size_t i=0;i<cnt;++i) __builtin_memcpy(dst+i*element_size,val,element_size);
	return;
}
void shinsei_vector_t_inlArray(shinsei_vector_t*const restrict this,const void*const restrict arr,const size_t len,const size_t element_size){
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->size=len;
	this->cap=len;
	this->element_size=element_size;
	__builtin_memcpy(vec_data(this),arr,len*element_size);
	return;
}

// [const] Check if elements are inlined
bool shinsei_vector_t_inlined(const shinsei_vector_t*const restrict this){
	return vec_inlined(this);
}

// [Const] Get the ctrl code
int_fast32_t shinsei_vector_t_getCtrl(const shinsei_vector_t*const restrict this){
	return this->ctrl;
}

// Set the ctrl code
void shinsei_vector_t_setCtrl(shinsei_vector_t*const restrict this,const int_fast32_t ctrl){
	this->ctrl=ctrl;
	return;
}
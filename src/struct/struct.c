#include"shinsei/minimal/struct.h"

shinsei_object_t* shinsei_object_t_con(const void *const val,shinsei_deallocator_t deallocator){
	shinsei_object_t* res=(shinsei_object_t*)malloc(sizeof(shinsei_object_t));
	if(res==nullptr) return nullptr;
	res->val=val;
	res->deallocator=deallocator;
	return res;
}


void shinsei_object_t_dec(shinsei_object_t *const obj){
	if(shinsei_object_t_isLegal(obj)) obj->deallocator((void*)obj->val);
	free(obj);
	return;
}

bool shinsei_object_t_isLegal(const shinsei_object_t *const obj){
	return obj->deallocator!=nullptr;
}

bool shinsei_object_t_isNullptr(const shinsei_object_t *const obj){
	return obj->val==nullptr;
}

const void* shinsei_object_t_value(const shinsei_object_t *const obj){
	return obj->val;
}

shinsei_deallocator_t shinsei_object_t_getDeallocator(const shinsei_object_t *const obj){
	return obj->deallocator;
}

void shinsei_object_t_alloc(shinsei_object_t *const obj,const void *const val){
	obj->val=val;
	return;
}

bool shinsei_object_t_free(shinsei_object_t *const obj){
	if(!shinsei_object_t_isLegal(obj)) return 0;
	obj->deallocator((void*)obj->val);
	obj->val=nullptr;
	return 1;
}

void shinsei_object_t_setDeallocator(shinsei_object_t *const obj,shinsei_deallocator_t deallocator){
	obj->deallocator=deallocator;
	return;
}
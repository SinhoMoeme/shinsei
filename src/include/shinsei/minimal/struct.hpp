#pragma once
#include"shinsei/minimal/struct.h"
#include"shinsei/.internal/tag.hpp"
#include<new>

namespace shinsei{
	class object_definition_t{
	private:
		::shinsei_object_definition_t obj;
	public:
		// Default constructor
		object_definition_t(allocate_copy_callback_t allocate_callback=nullptr,free_callback_t free_callback=nullptr){
			::shinsei_object_definition_t_as(&obj,allocate_callback,free_callback);
			return;
		}
		// Copy constructor
		object_definition_t(const object_definition_t& src){
			::shinsei_object_definition_t_asCopy(&obj,src.cObj());
			return;
		}
		object_definition_t(const ::shinsei_object_definition_t& src){
			::shinsei_object_definition_t_asCopy(&obj,&src);
			return;
		}
		// Move constructor
		object_definition_t(object_definition_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_asMove(&obj,src.cObj());
			return;
		}
		object_definition_t(::shinsei_object_definition_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_asMove(&obj,&src);
			return;
		}
		
		// In-place Constructors
		explicit object_definition_t(shinsei::in_place_t,allocate_copy_callback_t allocate_callback=nullptr,free_callback_t free_callback=nullptr){
			::shinsei_object_definition_t_as(&obj,allocate_callback,free_callback);
			return;
		}
		explicit object_definition_t(shinsei::in_place_t,const object_definition_t& src){
			::shinsei_object_definition_t_asCopy(&obj,src.cObj());
			return;
		}
		explicit object_definition_t(shinsei::in_place_t,const ::shinsei_object_definition_t& src){
			::shinsei_object_definition_t_asCopy(&obj,&src);
			return;
		}
		explicit object_definition_t(shinsei::in_place_t,object_definition_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_asMove(&obj,src.cObj());
			return;
		}
		explicit object_definition_t(shinsei::in_place_t,::shinsei_object_definition_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_asMove(&obj,&src);
			return;
		}
		
		// Inlined Constructors
		explicit object_definition_t(shinsei::inlined_t,allocate_copy_callback_t allocate_callback=nullptr,free_callback_t free_callback=nullptr)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_inl(&obj,allocate_callback,free_callback);
			return;
		}
		explicit object_definition_t(shinsei::inlined_t,const object_definition_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_inlCopy(&obj,src.cObj());
			return;
		}
		explicit object_definition_t(shinsei::inlined_t,const ::shinsei_object_definition_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_inlCopy(&obj,&src);
			return;
		}
		explicit object_definition_t(shinsei::inlined_t,object_definition_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_inlMove(&obj,src.cObj());
			return;
		}
		explicit object_definition_t(shinsei::inlined_t,::shinsei_object_definition_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_inlMove(&obj,&src);
			return;
		}
		
		// Destructor
		~object_definition_t()_SHINSEI_OS_NOEXCEPT{
			return;
		}
		
		// Info & Access
		bool hasAllocateCallback()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_object_definition_t_hasAllocateCallback(&obj);
		}
		bool hasFreeCallback()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_object_definition_t_hasFreeCallback(&obj);
		}
		
		// Modification
		void swap(object_definition_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_swap(&obj,src.cObj());
			return;
		}
		void swap(::shinsei_object_definition_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_swap(&obj,&src);
			return;
		}
		
		// Standard API Operations
		void assign(const object_definition_t& src){
			::shinsei_object_definition_t_assign(&obj,src.cObj());
			return;
		}
		void assign(const ::shinsei_object_definition_t& src){
			::shinsei_object_definition_t_assign(&obj,&src);
			return;
		}
		object_definition_t& operator=(const object_definition_t& src){
			if(this==&src) return *this;
			::shinsei_object_definition_t_assign(&obj,src.cObj());
			return *this;
		}
		object_definition_t& operator=(const ::shinsei_object_definition_t& src){
			::shinsei_object_definition_t_assign(&obj,&src);
			return *this;
		}
		
		void move(object_definition_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_move(&obj,src.cObj());
			return;
		}
		void move(::shinsei_object_definition_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_move(&obj,&src);
			return;
		}
		object_definition_t& operator=(object_definition_t&& src)_SHINSEI_OS_NOEXCEPT{
			if(this==&src) return *this;
			::shinsei_object_definition_t_move(&obj,src.cObj());
			return *this;
		}
		object_definition_t& operator=(::shinsei_object_definition_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_move(&obj,&src);
			return *this;
		}
		
		// Attach Operations
		void attach(const object_definition_t& src){
			::shinsei_object_definition_t_attach(&obj,src.cObj());
			return;
		}
		void attach(const ::shinsei_object_definition_t& src){
			::shinsei_object_definition_t_attach(&obj,&src);
			return;
		}
		void attach(const int_fast32_t ctrl,allocate_copy_callback_t allocate_callback,free_callback_t free_callback){
			::shinsei_object_definition_t_attachValue(&obj,ctrl,allocate_callback,free_callback);
			return;
		}
		
		// Static Helpers (for explicit C-struct manipulation in user code)
		static void as(object_definition_t*const restrict ptr,allocate_copy_callback_t allocate_callback=nullptr,free_callback_t free_callback=nullptr){
			::shinsei_object_definition_t_as(ptr->cObj(),allocate_callback,free_callback);
			return;
		}
		static void as(::shinsei_object_definition_t*const restrict ptr,allocate_copy_callback_t allocate_callback=nullptr,free_callback_t free_callback=nullptr){
			::shinsei_object_definition_t_as(ptr,allocate_callback,free_callback);
			return;
		}
		static void as(object_definition_t*const restrict ptr,const object_definition_t& src){
			::shinsei_object_definition_t_asCopy(ptr->cObj(),src.cObj());
			return;
		}
		static void as(object_definition_t*const restrict ptr,const ::shinsei_object_definition_t& src){
			::shinsei_object_definition_t_asCopy(ptr->cObj(),&src);
			return;
		}
		static void as(object_definition_t*const restrict ptr,object_definition_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_asMove(ptr->cObj(),src.cObj());
			return;
		}
		static void as(object_definition_t*const restrict ptr,::shinsei_object_definition_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_asMove(ptr->cObj(),&src);
			return;
		}
		
		static void inl(object_definition_t*const restrict ptr,allocate_copy_callback_t allocate_callback=nullptr,free_callback_t free_callback=nullptr)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_inl(ptr->cObj(),allocate_callback,free_callback);
			return;
		}
		static void inl(::shinsei_object_definition_t*const restrict ptr,allocate_copy_callback_t allocate_callback=nullptr,free_callback_t free_callback=nullptr)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_inl(ptr,allocate_callback,free_callback);
			return;
		}
		static void inl(object_definition_t*const restrict ptr,const object_definition_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_inlCopy(ptr->cObj(),src.cObj());
			return;
		}
		static void inl(object_definition_t*const restrict ptr,const ::shinsei_object_definition_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_inlCopy(ptr->cObj(),&src);
			return;
		}
		static void inl(object_definition_t*const restrict ptr,object_definition_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_inlMove(ptr->cObj(),src.cObj());
			return;
		}
		static void inl(object_definition_t*const restrict ptr,::shinsei_object_definition_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_inlMove(ptr->cObj(),&src);
			return;
		}
		
		// Core Identity Controls
		bool inlined()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_object_definition_t_inlined(&obj);
		}
		int_fast32_t getCtrl()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_object_definition_t_getCtrl(&obj);
		}
		void setCtrl(const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_definition_t_setCtrl(&obj,ctrl);
			return;
		}
		
		// Type Casting / Access
		::shinsei_object_definition_t* cObj()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		const ::shinsei_object_definition_t* cObj()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator ::shinsei_object_definition_t*()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator const ::shinsei_object_definition_t*()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
	};
	
	class object_t{
	private:
		::shinsei_object_t obj;
	public:
		// Default constructor
		object_t(const void*const val,const object_definition_t& definition){
			::shinsei_object_t_as(&obj,val,*definition.cObj());
			return;
		}
		object_t(const void*const val,const ::shinsei_object_definition_t& definition){
			::shinsei_object_t_as(&obj,val,definition);
			return;
		}
		// Copy constructor
		object_t(const object_t& src){
			::shinsei_object_t_asCopy(&obj,src.cObj());
			return;
		}
		object_t(const ::shinsei_object_t& src){
			::shinsei_object_t_asCopy(&obj,&src);
			return;
		}
		// Move constructor
		object_t(object_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_asMove(&obj,src.cObj());
			return;
		}
		object_t(::shinsei_object_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_asMove(&obj,&src);
			return;
		}
		
		// In-place Constructors
		explicit object_t(shinsei::in_place_t,const void*const val,const object_definition_t& definition){
			::shinsei_object_t_as(&obj,val,*definition.cObj());
			return;
		}
		explicit object_t(shinsei::in_place_t,const void*const val,const ::shinsei_object_definition_t& definition){
			::shinsei_object_t_as(&obj,val,definition);
			return;
		}
		explicit object_t(shinsei::in_place_t,const object_t& src){
			::shinsei_object_t_asCopy(&obj,src.cObj());
			return;
		}
		explicit object_t(shinsei::in_place_t,const ::shinsei_object_t& src){
			::shinsei_object_t_asCopy(&obj,&src);
			return;
		}
		explicit object_t(shinsei::in_place_t,object_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_asMove(&obj,src.cObj());
			return;
		}
		explicit object_t(shinsei::in_place_t,::shinsei_object_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_asMove(&obj,&src);
			return;
		}
		
		// Inlined Constructors
		explicit object_t(shinsei::inlined_t,const void*const val,const object_definition_t& definition)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_inl(&obj,val,*definition.cObj());
			return;
		}
		explicit object_t(shinsei::inlined_t,const void*const val,const ::shinsei_object_definition_t& definition)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_inl(&obj,val,definition);
			return;
		}
		explicit object_t(shinsei::inlined_t,const object_t& src){
			::shinsei_object_t_inlCopy(&obj,src.cObj());
			return;
		}
		explicit object_t(shinsei::inlined_t,const ::shinsei_object_t& src){
			::shinsei_object_t_inlCopy(&obj,&src);
			return;
		}
		explicit object_t(shinsei::inlined_t,object_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_inlMove(&obj,src.cObj());
			return;
		}
		explicit object_t(shinsei::inlined_t,::shinsei_object_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_inlMove(&obj,&src);
			return;
		}
		
		// Destructor
		~object_t(){
			if(!inlined()) ::shinsei_object_t_freeData(&obj);
			return;
		}
		
		// Info & Access
		bool hasAllocateCallback()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_object_t_hasAllocateCallback(&obj);
		}
		bool hasFreeCallback()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_object_t_hasFreeCallback(&obj);
		}
		bool isNullptr()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_object_t_isNullptr(&obj);
		}
		const void* value()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_object_t_value(&obj);
		}
		::shinsei_object_definition_t getDefinition()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_object_t_getDefinition(&obj);
		}
		
		// Modification
		void alloc(const void*const val){
			::shinsei_object_t_alloc(&obj,val);
			return;
		}
		void free(){
			::shinsei_object_t_free(&obj);
			return;
		}
		void setDefinition(const object_definition_t& definition){
			::shinsei_object_t_setDefinition(&obj,*definition.cObj());
			return;
		}
		void setDefinition(const ::shinsei_object_definition_t& definition){
			::shinsei_object_t_setDefinition(&obj,definition);
			return;
		}
		void swap(object_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_swap(&obj,src.cObj());
			return;
		}
		void swap(::shinsei_object_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_swap(&obj,&src);
			return;
		}
		
		// Standard API Operations
		void assign(const object_t& src){
			::shinsei_object_t_assign(&obj,src.cObj());
			return;
		}
		void assign(const ::shinsei_object_t& src){
			::shinsei_object_t_assign(&obj,&src);
			return;
		}
		object_t& operator=(const object_t& src){
			if(this==&src) return *this;
			::shinsei_object_t_assign(&obj,src.cObj());
			return *this;
		}
		object_t& operator=(const ::shinsei_object_t& src){
			::shinsei_object_t_assign(&obj,&src);
			return *this;
		}
		
		void move(object_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_move(&obj,src.cObj());
			return;
		}
		void move(::shinsei_object_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_move(&obj,&src);
			return;
		}
		object_t& operator=(object_t&& src)_SHINSEI_OS_NOEXCEPT{
			if(this==&src) return *this;
			::shinsei_object_t_move(&obj,src.cObj());
			return *this;
		}
		object_t& operator=(::shinsei_object_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_move(&obj,&src);
			return *this;
		}
		
		// Attach Operations
		void attach(const object_t& src){
			::shinsei_object_t_attach(&obj,src.cObj());
			return;
		}
		void attach(const ::shinsei_object_t& src){
			::shinsei_object_t_attach(&obj,&src);
			return;
		}
		void attach(const int_fast32_t ctrl,const void *const val,const object_definition_t& definition){
			::shinsei_object_t_attachValue(&obj,ctrl,val,*definition.cObj());
			return;
		}
		void attach(const int_fast32_t ctrl,const void *const val,const ::shinsei_object_definition_t& definition){
			::shinsei_object_t_attachValue(&obj,ctrl,val,definition);
			return;
		}
		
		// Free Data
		void freeData(){
			::shinsei_object_t_freeData(&obj);
			return;
		}
		
		// Static Helpers (for explicit C-struct manipulation in user code)
		static void as(object_t*const restrict ptr,const void *const val,const object_definition_t& definition){
			::shinsei_object_t_as(ptr->cObj(),val,*definition.cObj());
			return;
		}
		static void as(::shinsei_object_t*const restrict ptr,const void *const val,const ::shinsei_object_definition_t& definition){
			::shinsei_object_t_as(ptr,val,definition);
			return;
		}
		static void as(object_t*const restrict ptr,const object_t& src){
			::shinsei_object_t_asCopy(ptr->cObj(),src.cObj());
			return;
		}
		static void as(object_t*const restrict ptr,const ::shinsei_object_t& src){
			::shinsei_object_t_asCopy(ptr->cObj(),&src);
			return;
		}
		static void as(object_t*const restrict ptr,object_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_asMove(ptr->cObj(),src.cObj());
			return;
		}
		static void as(object_t*const restrict ptr,::shinsei_object_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_asMove(ptr->cObj(),&src);
			return;
		}
		
		static void inl(object_t*const restrict ptr,const void *const val,const object_definition_t& definition)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_inl(ptr->cObj(),val,*definition.cObj());
			return;
		}
		static void inl(::shinsei_object_t*const restrict ptr,const void *const val,const ::shinsei_object_definition_t& definition)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_inl(ptr,val,definition);
			return;
		}
		static void inl(object_t*const restrict ptr,const object_t& src){
			::shinsei_object_t_inlCopy(ptr->cObj(),src.cObj());
			return;
		}
		static void inl(object_t*const restrict ptr,const ::shinsei_object_t& src){
			::shinsei_object_t_inlCopy(ptr->cObj(),&src);
			return;
		}
		static void inl(object_t*const restrict ptr,object_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_inlMove(ptr->cObj(),src.cObj());
			return;
		}
		static void inl(object_t*const restrict ptr,::shinsei_object_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_inlMove(ptr->cObj(),&src);
			return;
		}
		
		// Core Identity Controls
		bool inlined()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_object_t_inlined(&obj);
		}
		int_fast32_t getCtrl()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_object_t_getCtrl(&obj);
		}
		void setCtrl(const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
			::shinsei_object_t_setCtrl(&obj,ctrl);
			return;
		}
		
		// Type Casting / Access
		::shinsei_object_t* cObj()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		const ::shinsei_object_t* cObj()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator ::shinsei_object_t*()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator const ::shinsei_object_t*()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
	};
	
	// stack_t
	template<typename T>
	class stack_t{
	private:
		::shinsei_stack_t obj;
	public:
		static _SHINSEI_OS_CONSTEXPR size_t DEF_CAP=::shinsei_stack_t_DEF_CAP;
		
		// Default constructor
		stack_t(){
			if(!::shinsei_stack_t_as(&obj,sizeof(T))) throw std::bad_alloc();
			return;
		}
		// Capacity constructor
		explicit stack_t(const size_t cap){
			if(!::shinsei_stack_t_asCapacity(&obj,cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		// Copy constructor
		stack_t(const stack_t& src){
			if(!::shinsei_stack_t_asCopy(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		stack_t(const ::shinsei_stack_t& src){
			if(!::shinsei_stack_t_asCopy(&obj,&src)) throw std::bad_alloc();
			return;
		}
		// Move constructor
		stack_t(stack_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_asMove(&obj,src.cObj());
			return;
		}
		stack_t(::shinsei_stack_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_asMove(&obj,&src);
			return;
		}
		// From Element/Array
		stack_t(const size_t repeat_cnt,const T& val){
			if(!::shinsei_stack_t_asElement(&obj,&val,repeat_cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		stack_t(const T*const restrict arr,const size_t len){
			if(!::shinsei_stack_t_asArray(&obj,arr,len,sizeof(T))) throw std::bad_alloc();
			return;
		}
		
		// In-place Constructors
		explicit stack_t(shinsei::in_place_t){
			if(!::shinsei_stack_t_as(&obj,sizeof(T))) throw std::bad_alloc();
			return;
		}
		explicit stack_t(shinsei::in_place_t,const size_t cap){
			if(!::shinsei_stack_t_asCapacity(&obj,cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		explicit stack_t(shinsei::in_place_t,const stack_t& src){
			if(!::shinsei_stack_t_asCopy(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		explicit stack_t(shinsei::in_place_t,const ::shinsei_stack_t& src){
			if(!::shinsei_stack_t_asCopy(&obj,&src)) throw std::bad_alloc();
			return;
		}
		explicit stack_t(shinsei::in_place_t,stack_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_asMove(&obj,src.cObj());
			return;
		}
		explicit stack_t(shinsei::in_place_t,::shinsei_stack_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_asMove(&obj,&src);
			return;
		}
		explicit stack_t(shinsei::in_place_t,const size_t repeat_cnt,const T& val){
			if(!::shinsei_stack_t_asElement(&obj,&val,repeat_cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		explicit stack_t(shinsei::in_place_t,const T*const restrict arr,const size_t len){
			if(!::shinsei_stack_t_asArray(&obj,arr,len,sizeof(T))) throw std::bad_alloc();
			return;
		}
		
		// Inlined Constructors
		explicit stack_t(shinsei::inlined_t,const size_t cap)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_inl(&obj,cap,sizeof(T));
			return;
		}
		explicit stack_t(shinsei::inlined_t,const stack_t& src){
			if(!::shinsei_stack_t_inlCopy(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		explicit stack_t(shinsei::inlined_t,const ::shinsei_stack_t& src){
			if(!::shinsei_stack_t_inlCopy(&obj,&src)) throw std::bad_alloc();
			return;
		}
		explicit stack_t(shinsei::inlined_t,stack_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_inlMove(&obj,src.cObj());
			return;
		}
		explicit stack_t(shinsei::inlined_t,::shinsei_stack_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_inlMove(&obj,&src);
			return;
		}
		explicit stack_t(shinsei::inlined_t,const size_t repeat_cnt,const T& val)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_inlElement(&obj,&val,repeat_cnt,sizeof(T));
			return;
		}
		explicit stack_t(shinsei::inlined_t,const T*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_inlArray(&obj,arr,len,sizeof(T));
			return;
		}
		
		// Destructor
		~stack_t(){
			if(!inlined()) ::shinsei_stack_t_freeData(&obj);
			return;
		}
		
		// Capacity
		void expand(const size_t more_cap){
			if(!::shinsei_stack_t_expand(&obj,more_cap)) throw std::bad_alloc();
			return;
		}
		void shrink(const size_t less_cap){
			if(!::shinsei_stack_t_shrink(&obj,less_cap)) throw std::bad_alloc();
			return;
		}
		void reserve(const size_t cap){
			if(!::shinsei_stack_t_reserve(&obj,cap)) throw std::bad_alloc();
			return;
		}
		void shrinkToFit(){
			if(!::shinsei_stack_t_shrinkToFit(&obj)) throw std::bad_alloc();
			return;
		}
		
		// Info & Access
		bool empty()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stack_t_empty(&obj);
		}
		size_t size()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stack_t_size(&obj);
		}
		size_t capacity()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stack_t_capacity(&obj);
		}
		T& top()const _SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_stack_t_top(&obj);
		}
		T& at(const size_t idx)_SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_stack_t_at(&obj,idx);
		}
		const T& at(const size_t idx)const _SHINSEI_OS_NOEXCEPT{
			return *(const T*)::shinsei_stack_t_at(&obj,idx);
		}
		T& operator[](const size_t idx)_SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_stack_t_at(&obj,idx);
		}
		const T& operator[](const size_t idx)const _SHINSEI_OS_NOEXCEPT{
			return *(const T*)::shinsei_stack_t_at(&obj,idx);
		}
		T* data()_SHINSEI_OS_NOEXCEPT{
			return (T*)::shinsei_stack_t_data(&obj);
		}
		const T* data()const _SHINSEI_OS_NOEXCEPT{
			return (const T*)::shinsei_stack_t_data(&obj);
		}
		
		// Modification
		void pop()_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_pop(&obj);
			return;
		}
		void pop(const size_t cnt)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_popArray(&obj,cnt);
			return;
		}
		void push(const T& val){
			if(!::shinsei_stack_t_pushElement(&obj,&val,1)) throw std::bad_alloc();
			return;
		}
		void push(const T*const restrict arr,const size_t len){
			if(!::shinsei_stack_t_pushArray(&obj,arr,len)) throw std::bad_alloc();
			return;
		}
		void push(const T& val,const size_t cnt){
			if(!::shinsei_stack_t_pushElement(&obj,&val,cnt)) throw std::bad_alloc();
			return;
		}
		void swap(stack_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_swap(&obj,src.cObj());
			return;
		}
		void swap(::shinsei_stack_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_swap(&obj,&src);
			return;
		}
		void clear(){
			if(!::shinsei_stack_t_clear(&obj)) throw std::bad_alloc();
			return;
		}
		void setSize(const size_t size){
			if(!::shinsei_stack_t_setSize(&obj,size)) throw std::bad_alloc();
			return;
		}
		
		// Standard API Operations
		void assign(const stack_t& src){
			if(!::shinsei_stack_t_assign(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		void assign(const ::shinsei_stack_t& src){
			if(!::shinsei_stack_t_assign(&obj,&src)) throw std::bad_alloc();
			return;
		}
		stack_t& operator=(const stack_t& src){
			if(this==&src) return *this;
			if(!::shinsei_stack_t_assign(&obj,src.cObj())) throw std::bad_alloc();
			return *this;
		}
		stack_t& operator=(const ::shinsei_stack_t& src){
			if(!::shinsei_stack_t_assign(&obj,&src)) throw std::bad_alloc();
			return *this;
		}
		
		void move(stack_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_move(&obj,src.cObj());
			return;
		}
		void move(::shinsei_stack_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_move(&obj,&src);
			return;
		}
		stack_t& operator=(stack_t&& src)_SHINSEI_OS_NOEXCEPT{
			if(this==&src) return *this;
			::shinsei_stack_t_move(&obj,src.cObj());
			return *this;
		}
		stack_t& operator=(::shinsei_stack_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_move(&obj,&src);
			return *this;
		}
		
		// Attach Operations
		void attach(const stack_t& src){
			if(!::shinsei_stack_t_attach(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		void attach(const ::shinsei_stack_t& src){
			if(!::shinsei_stack_t_attach(&obj,&src)) throw std::bad_alloc();
			return;
		}
		void attach(const int_fast32_t ctrl,const size_t size,const size_t cap,T*const ptr){
			if(!::shinsei_stack_t_attachValue(&obj,ctrl,size,cap,ptr,sizeof(T))) throw std::bad_alloc();
			return;
		}
		
		// Free Data
		void freeData(){
			::shinsei_stack_t_freeData(&obj);
			return;
		}
		
		// Static Helpers (for explicit C-struct manipulation in user code)
		static void as(stack_t*const restrict ptr){
			if(!::shinsei_stack_t_as(ptr->cObj(),sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_stack_t*const restrict ptr){
			if(!::shinsei_stack_t_as(ptr,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(stack_t*const restrict ptr,const size_t cap){
			if(!::shinsei_stack_t_asCapacity(ptr->cObj(),cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_stack_t*const restrict ptr,const size_t cap){
			if(!::shinsei_stack_t_asCapacity(ptr,cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(stack_t*const restrict ptr,const stack_t& src){
			if(!::shinsei_stack_t_asCopy(ptr->cObj(),src.cObj())) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_stack_t*const restrict ptr,const ::shinsei_stack_t& src){
			if(!::shinsei_stack_t_asCopy(ptr,&src)) throw std::bad_alloc();
			return;
		}
		static void as(stack_t*const restrict ptr,stack_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_asMove(ptr->cObj(),src.cObj());
			return;
		}
		static void as(::shinsei_stack_t*const restrict ptr,::shinsei_stack_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_asMove(ptr,&src);
			return;
		}
		static void as(stack_t*const restrict ptr,const T& val,const size_t cnt){
			if(!::shinsei_stack_t_asElement(ptr->cObj(),&val,cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_stack_t*const restrict ptr,const T& val,const size_t cnt){
			if(!::shinsei_stack_t_asElement(ptr,&val,cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(stack_t*const restrict ptr,const T*const restrict arr,const size_t len){
			if(!::shinsei_stack_t_asArray(ptr->cObj(),arr,len,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_stack_t*const restrict ptr,const T*const restrict arr,const size_t len){
			if(!::shinsei_stack_t_asArray(ptr,arr,len,sizeof(T))) throw std::bad_alloc();
			return;
		}
		
		static void inl(stack_t*const restrict ptr,const size_t cap)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_inl(ptr->cObj(),cap,sizeof(T));
			return;
		}
		static void inl(::shinsei_stack_t*const restrict ptr,const size_t cap)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_inl(ptr,cap,sizeof(T));
			return;
		}
		static void inl(stack_t*const restrict ptr,const stack_t& src){
			if(!::shinsei_stack_t_inlCopy(ptr->cObj(),src.cObj())) throw std::bad_alloc();
			return;
		}
		static void inl(::shinsei_stack_t*const restrict ptr,const ::shinsei_stack_t& src){
			if(!::shinsei_stack_t_inlCopy(ptr,&src)) throw std::bad_alloc();
			return;
		}
		static void inl(stack_t*const restrict ptr,stack_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_inlMove(ptr->cObj(),src.cObj());
			return;
		}
		static void inl(::shinsei_stack_t*const restrict ptr,::shinsei_stack_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_inlMove(ptr,&src);
			return;
		}
		static void inl(stack_t*const restrict ptr,const T& val,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_inlElement(ptr,&val,cnt,sizeof(T));
			return;
		}
		static void inl(::shinsei_stack_t*const restrict ptr,const T& val,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_inlElement(ptr,&val,cnt,sizeof(T));
			return;
		}
		static void inl(stack_t*const restrict ptr,const T*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_inlArray(ptr->cObj(),arr,len,sizeof(T));
			return;
		}
		static void inl(::shinsei_stack_t*const restrict ptr,const T*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_inlArray(ptr,arr,len,sizeof(T));
			return;
		}
		
		// Core Identity Controls
		bool inlined()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stack_t_inlined(&obj);
		}
		int_fast32_t getCtrl()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_stack_t_getCtrl(&obj);
		}
		void setCtrl(const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
			::shinsei_stack_t_setCtrl(&obj,ctrl);
			return;
		}
		
		// Type Casting / Access
		::shinsei_stack_t* cObj()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		const ::shinsei_stack_t* cObj()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator ::shinsei_stack_t*()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator const ::shinsei_stack_t*()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
	};
	
	// queue_t
	template<typename T>
	class queue_t{
	private:
		::shinsei_queue_t obj;
	public:
		static _SHINSEI_OS_CONSTEXPR size_t DEF_CAP=::shinsei_queue_t_DEF_CAP;
		
		// Default constructor
		queue_t(){
			if(!::shinsei_queue_t_as(&obj,sizeof(T))) throw std::bad_alloc();
			return;
		}
		// Capacity constructor
		explicit queue_t(const size_t cap){
			if(!::shinsei_queue_t_asCapacity(&obj,cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		// Copy constructor
		queue_t(const queue_t& src){
			if(!::shinsei_queue_t_asCopy(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		queue_t(const ::shinsei_queue_t& src){
			if(!::shinsei_queue_t_asCopy(&obj,&src)) throw std::bad_alloc();
			return;
		}
		// Move constructor
		queue_t(queue_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_asMove(&obj,src.cObj());
			return;
		}
		queue_t(::shinsei_queue_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_asMove(&obj,&src);
			return;
		}
		// From Element/Array
		queue_t(const size_t repeat_cnt,const T& val){
			if(!::shinsei_queue_t_asElement(&obj,&val,repeat_cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		queue_t(const T*const restrict arr,const size_t len){
			if(!::shinsei_queue_t_asArray(&obj,arr,len,sizeof(T))) throw std::bad_alloc();
			return;
		}
		
		// In-place Constructors
		explicit queue_t(shinsei::in_place_t){
			if(!::shinsei_queue_t_as(&obj,sizeof(T))) throw std::bad_alloc();
			return;
		}
		explicit queue_t(shinsei::in_place_t,const size_t cap){
			if(!::shinsei_queue_t_asCapacity(&obj,cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		explicit queue_t(shinsei::in_place_t,const queue_t& src){
			if(!::shinsei_queue_t_asCopy(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		explicit queue_t(shinsei::in_place_t,const ::shinsei_queue_t& src){
			if(!::shinsei_queue_t_asCopy(&obj,&src)) throw std::bad_alloc();
			return;
		}
		explicit queue_t(shinsei::in_place_t,queue_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_asMove(&obj,src.cObj());
			return;
		}
		explicit queue_t(shinsei::in_place_t,::shinsei_queue_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_asMove(&obj,&src);
			return;
		}
		explicit queue_t(shinsei::in_place_t,const size_t repeat_cnt,const T& val){
			if(!::shinsei_queue_t_asElement(&obj,&val,repeat_cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		explicit queue_t(shinsei::in_place_t,const T*const restrict arr,const size_t len){
			if(!::shinsei_queue_t_asArray(&obj,arr,len,sizeof(T))) throw std::bad_alloc();
			return;
		}
		
		// Inlined Constructors
		explicit queue_t(shinsei::inlined_t,const size_t cap)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_inl(&obj,cap,sizeof(T));
			return;
		}
		explicit queue_t(shinsei::inlined_t,const queue_t& src){
			if(!::shinsei_queue_t_inlCopy(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		explicit queue_t(shinsei::inlined_t,const ::shinsei_queue_t& src){
			if(!::shinsei_queue_t_inlCopy(&obj,&src)) throw std::bad_alloc();
			return;
		}
		explicit queue_t(shinsei::inlined_t,queue_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_inlMove(&obj,src.cObj());
			return;
		}
		explicit queue_t(shinsei::inlined_t,::shinsei_queue_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_inlMove(&obj,&src);
			return;
		}
		explicit queue_t(shinsei::inlined_t,const size_t repeat_cnt,const T& val)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_inlElement(&obj,&val,repeat_cnt,sizeof(T));
			return;
		}
		explicit queue_t(shinsei::inlined_t,const T*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_inlArray(&obj,arr,len,sizeof(T));
			return;
		}
		
		// Destructor
		~queue_t(){
			if(!inlined()) ::shinsei_queue_t_freeData(&obj);
			return;
		}
		
		// Capacity
		void expand(const size_t more_cap){
			if(!::shinsei_queue_t_expand(&obj,more_cap)) throw std::bad_alloc();
			return;
		}
		void shrink(const size_t less_cap){
			if(!::shinsei_queue_t_shrink(&obj,less_cap)) throw std::bad_alloc();
			return;
		}
		void reserve(const size_t cap){
			if(!::shinsei_queue_t_reserve(&obj,cap)) throw std::bad_alloc();
			return;
		}
		void shrinkToFit(){
			if(!::shinsei_queue_t_shrinkToFit(&obj)) throw std::bad_alloc();
			return;
		}
		
		// Info & Access
		bool empty()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_queue_t_empty(&obj);
		}
		size_t size()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_queue_t_size(&obj);
		}
		size_t capacity()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_queue_t_capacity(&obj);
		}
		T& front()const _SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_queue_t_front(&obj);
		}
		T& back()const _SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_queue_t_back(&obj);
		}
		T& at(const size_t idx)_SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_queue_t_at(&obj,idx);
		}
		const T& at(const size_t idx)const _SHINSEI_OS_NOEXCEPT{
			return *(const T*)::shinsei_queue_t_at(&obj,idx);
		}
		T& operator[](const size_t idx)_SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_queue_t_at(&obj,idx);
		}
		const T& operator[](const size_t idx)const _SHINSEI_OS_NOEXCEPT{
			return *(const T*)::shinsei_queue_t_at(&obj,idx);
		}
		T* data()_SHINSEI_OS_NOEXCEPT{
			return (T*)::shinsei_queue_t_data(&obj);
		}
		const T* data()const _SHINSEI_OS_NOEXCEPT{
			return (const T*)::shinsei_queue_t_data(&obj);
		}
		
		// Modification
		void pop()_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_pop(&obj);
			return;
		}
		void pop(const size_t cnt)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_popArray(&obj,cnt);
			return;
		}
		void push(const T& val){
			if(!::shinsei_queue_t_pushElement(&obj,&val,1)) throw std::bad_alloc();
			return;
		}
		void push(const T*const restrict arr,const size_t len){
			if(!::shinsei_queue_t_pushArray(&obj,arr,len)) throw std::bad_alloc();
			return;
		}
		void push(const T& val,const size_t cnt){
			if(!::shinsei_queue_t_pushElement(&obj,&val,cnt)) throw std::bad_alloc();
			return;
		}
		void swap(queue_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_swap(&obj,src.cObj());
			return;
		}
		void swap(::shinsei_queue_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_swap(&obj,&src);
			return;
		}
		void clear(){
			if(!::shinsei_queue_t_clear(&obj)) throw std::bad_alloc();
			return;
		}
		void setSize(const size_t size){
			if(!::shinsei_queue_t_setSize(&obj,size)) throw std::bad_alloc();
			return;
		}
		
		// Standard API Operations
		void assign(const queue_t& src){
			if(!::shinsei_queue_t_assign(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		void assign(const ::shinsei_queue_t& src){
			if(!::shinsei_queue_t_assign(&obj,&src)) throw std::bad_alloc();
			return;
		}
		queue_t& operator=(const queue_t& src){
			if(this==&src) return *this;
			if(!::shinsei_queue_t_assign(&obj,src.cObj())) throw std::bad_alloc();
			return *this;
		}
		queue_t& operator=(const ::shinsei_queue_t& src){
			if(!::shinsei_queue_t_assign(&obj,&src)) throw std::bad_alloc();
			return *this;
		}
		
		void move(queue_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_move(&obj,src.cObj());
			return;
		}
		void move(::shinsei_queue_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_move(&obj,&src);
			return;
		}
		queue_t& operator=(queue_t&& src)_SHINSEI_OS_NOEXCEPT{
			if(this==&src) return *this;
			::shinsei_queue_t_move(&obj,src.cObj());
			return *this;
		}
		queue_t& operator=(::shinsei_queue_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_move(&obj,&src);
			return *this;
		}
		
		// Attach Operations
		void attach(const queue_t& src){
			if(!::shinsei_queue_t_attach(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		void attach(const ::shinsei_queue_t& src){
			if(!::shinsei_queue_t_attach(&obj,&src)) throw std::bad_alloc();
			return;
		}
		void attach(const int_fast32_t ctrl,const size_t head,const size_t tail,const size_t cap,T*const ptr){
			if(!::shinsei_queue_t_attachValue(&obj,ctrl,head,tail,cap,ptr,sizeof(T))) throw std::bad_alloc();
			return;
		}
		
		// Free Data
		void freeData(){
			::shinsei_queue_t_freeData(&obj);
			return;
		}
		
		// Static Helpers (for explicit C-struct manipulation in user code)
		static void as(queue_t*const restrict ptr){
			if(!::shinsei_queue_t_as(ptr->cObj(),sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_queue_t*const restrict ptr){
			if(!::shinsei_queue_t_as(ptr,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(queue_t*const restrict ptr,const size_t cap){
			if(!::shinsei_queue_t_asCapacity(ptr->cObj(),cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_queue_t*const restrict ptr,const size_t cap){
			if(!::shinsei_queue_t_asCapacity(ptr,cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(queue_t*const restrict ptr,const queue_t& src){
			if(!::shinsei_queue_t_asCopy(ptr->cObj(),src.cObj())) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_queue_t*const restrict ptr,const ::shinsei_queue_t& src){
			if(!::shinsei_queue_t_asCopy(ptr,&src)) throw std::bad_alloc();
			return;
		}
		static void as(queue_t*const restrict ptr,queue_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_asMove(ptr->cObj(),src.cObj());
			return;
		}
		static void as(::shinsei_queue_t*const restrict ptr,::shinsei_queue_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_asMove(ptr,&src);
			return;
		}
		static void as(queue_t*const restrict ptr,const T& val,const size_t cnt){
			if(!::shinsei_queue_t_asElement(ptr->cObj(),&val,cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_queue_t*const restrict ptr,const T& val,const size_t cnt){
			if(!::shinsei_queue_t_asElement(ptr,&val,cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(queue_t*const restrict ptr,const T*const restrict arr,const size_t len){
			if(!::shinsei_queue_t_asArray(ptr->cObj(),arr,len,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_queue_t*const restrict ptr,const T*const restrict arr,const size_t len){
			if(!::shinsei_queue_t_asArray(ptr,arr,len,sizeof(T))) throw std::bad_alloc();
			return;
		}
		
		static void inl(queue_t*const restrict ptr,const size_t cap)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_inl(ptr->cObj(),cap,sizeof(T));
			return;
		}
		static void inl(::shinsei_queue_t*const restrict ptr,const size_t cap)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_inl(ptr,cap,sizeof(T));
			return;
		}
		static void inl(queue_t*const restrict ptr,const queue_t& src){
			if(!::shinsei_queue_t_inlCopy(ptr->cObj(),src.cObj())) throw std::bad_alloc();
			return;
		}
		static void inl(::shinsei_queue_t*const restrict ptr,const ::shinsei_queue_t& src){
			if(!::shinsei_queue_t_inlCopy(ptr,&src)) throw std::bad_alloc();
			return;
		}
		static void inl(queue_t*const restrict ptr,queue_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_inlMove(ptr->cObj(),src.cObj());
			return;
		}
		static void inl(::shinsei_queue_t*const restrict ptr,::shinsei_queue_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_inlMove(ptr,&src);
			return;
		}
		static void inl(queue_t*const restrict ptr,const T& val,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_inlElement(ptr->cObj(),&val,cnt,sizeof(T));
			return;
		}
		static void inl(::shinsei_queue_t*const restrict ptr,const T& val,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_inlElement(ptr,&val,cnt,sizeof(T));
			return;
		}
		static void inl(queue_t*const restrict ptr,const T*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_inlArray(ptr->cObj(),arr,len,sizeof(T));
			return;
		}
		static void inl(::shinsei_queue_t*const restrict ptr,const T*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_inlArray(ptr,arr,len,sizeof(T));
			return;
		}
		
		// Core Identity Controls
		bool inlined()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_queue_t_inlined(&obj);
		}
		int_fast32_t getCtrl()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_queue_t_getCtrl(&obj);
		}
		void setCtrl(const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
			::shinsei_queue_t_setCtrl(&obj,ctrl);
			return;
		}
		
		// Type Casting / Access
		::shinsei_queue_t* cObj()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		const ::shinsei_queue_t* cObj()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator ::shinsei_queue_t*()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator const ::shinsei_queue_t*()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
	};
	
	// deque_t
	template<typename T>
	class deque_t{
	private:
		::shinsei_deque_t obj;
	public:
		static _SHINSEI_OS_CONSTEXPR size_t DEF_CAP=::shinsei_deque_t_DEF_CAP;
		
		// Default constructor
		deque_t(){
			if(!::shinsei_deque_t_as(&obj,sizeof(T))) throw std::bad_alloc();
			return;
		}
		// Capacity constructor
		explicit deque_t(const size_t cap){
			if(!::shinsei_deque_t_asCapacity(&obj,cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		// Copy constructor
		deque_t(const deque_t& src){
			if(!::shinsei_deque_t_asCopy(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		deque_t(const ::shinsei_deque_t& src){
			if(!::shinsei_deque_t_asCopy(&obj,&src)) throw std::bad_alloc();
			return;
		}
		// Move constructor
		deque_t(deque_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_asMove(&obj,src.cObj());
			return;
		}
		deque_t(::shinsei_deque_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_asMove(&obj,&src);
			return;
		}
		// From Element/Array
		deque_t(const size_t repeat_cnt,const T& val){
			if(!::shinsei_deque_t_asElement(&obj,&val,repeat_cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		deque_t(const T*const restrict arr,const size_t len){
			if(!::shinsei_deque_t_asArray(&obj,arr,len,sizeof(T))) throw std::bad_alloc();
			return;
		}
		
		// In-place Constructors
		explicit deque_t(shinsei::in_place_t){
			if(!::shinsei_deque_t_as(&obj,sizeof(T))) throw std::bad_alloc();
			return;
		}
		explicit deque_t(shinsei::in_place_t,const size_t cap){
			if(!::shinsei_deque_t_asCapacity(&obj,cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		explicit deque_t(shinsei::in_place_t,const deque_t& src){
			if(!::shinsei_deque_t_asCopy(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		explicit deque_t(shinsei::in_place_t,const ::shinsei_deque_t& src){
			if(!::shinsei_deque_t_asCopy(&obj,&src)) throw std::bad_alloc();
			return;
		}
		explicit deque_t(shinsei::in_place_t,deque_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_asMove(&obj,src.cObj());
			return;
		}
		explicit deque_t(shinsei::in_place_t,::shinsei_deque_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_asMove(&obj,&src);
			return;
		}
		explicit deque_t(shinsei::in_place_t,const size_t repeat_cnt,const T& val){
			if(!::shinsei_deque_t_asElement(&obj,&val,repeat_cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		explicit deque_t(shinsei::in_place_t,const T*const restrict arr,const size_t len){
			if(!::shinsei_deque_t_asArray(&obj,arr,len,sizeof(T))) throw std::bad_alloc();
			return;
		}
		
		// Inlined Constructors
		explicit deque_t(shinsei::inlined_t,const size_t cap)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_inl(&obj,cap,sizeof(T));
			return;
		}
		explicit deque_t(shinsei::inlined_t,const deque_t& src){
			if(!::shinsei_deque_t_inlCopy(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		explicit deque_t(shinsei::inlined_t,const ::shinsei_deque_t& src){
			if(!::shinsei_deque_t_inlCopy(&obj,&src)) throw std::bad_alloc();
			return;
		}
		explicit deque_t(shinsei::inlined_t,deque_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_inlMove(&obj,src.cObj());
			return;
		}
		explicit deque_t(shinsei::inlined_t,::shinsei_deque_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_inlMove(&obj,&src);
			return;
		}
		explicit deque_t(shinsei::inlined_t,const size_t repeat_cnt,const T& val)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_inlElement(&obj,&val,repeat_cnt,sizeof(T));
			return;
		}
		explicit deque_t(shinsei::inlined_t,const T*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_inlArray(&obj,arr,len,sizeof(T));
			return;
		}
		
		// Destructor
		~deque_t(){
			if(!inlined()) ::shinsei_deque_t_freeData(&obj);
			return;
		}
		
		// Capacity
		void expand(const size_t more_cap){
			if(!::shinsei_deque_t_expand(&obj,more_cap)) throw std::bad_alloc();
			return;
		}
		void shrink(const size_t less_cap){
			if(!::shinsei_deque_t_shrink(&obj,less_cap)) throw std::bad_alloc();
			return;
		}
		void reserve(const size_t cap){
			if(!::shinsei_deque_t_reserve(&obj,cap)) throw std::bad_alloc();
			return;
		}
		void shrinkToFit(){
			if(!::shinsei_deque_t_shrinkToFit(&obj)) throw std::bad_alloc();
			return;
		}
		
		// Info & Access
		bool empty()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_deque_t_empty(&obj);
		}
		size_t size()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_deque_t_size(&obj);
		}
		size_t capacity()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_deque_t_capacity(&obj);
		}
		T& front()const _SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_deque_t_front(&obj);
		}
		T& back()const _SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_deque_t_back(&obj);
		}
		T& at(const size_t idx)_SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_deque_t_at(&obj,idx);
		}
		const T& at(const size_t idx)const _SHINSEI_OS_NOEXCEPT{
			return *(const T*)::shinsei_deque_t_at(&obj,idx);
		}
		T& operator[](const size_t idx)_SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_deque_t_at(&obj,idx);
		}
		const T& operator[](const size_t idx)const _SHINSEI_OS_NOEXCEPT{
			return *(const T*)::shinsei_deque_t_at(&obj,idx);
		}
		T* data()_SHINSEI_OS_NOEXCEPT{
			return (T*)::shinsei_deque_t_data(&obj);
		}
		const T* data()const _SHINSEI_OS_NOEXCEPT{
			return (const T*)::shinsei_deque_t_data(&obj);
		}
		
		// Modification
		void popFront()_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_popFront(&obj);
			return;
		}
		void popFront(const size_t cnt)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_popFrontArray(&obj,cnt);
			return;
		}
		void popBack()_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_popBack(&obj);
			return;
		}
		void popBack(const size_t cnt)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_popBackArray(&obj,cnt);
			return;
		}
		
		void pushFront(const T& val){
			if(!::shinsei_deque_t_pushFrontElement(&obj,&val,1)) throw std::bad_alloc();
			return;
		}
		void pushFront(const T*const restrict arr,const size_t len){
			if(!::shinsei_deque_t_pushFrontArray(&obj,arr,len)) throw std::bad_alloc();
			return;
		}
		void pushFront(const T& val,const size_t cnt){
			if(!::shinsei_deque_t_pushFrontElement(&obj,&val,cnt)) throw std::bad_alloc();
			return;
		}
		
		void pushBack(const T& val){
			if(!::shinsei_deque_t_pushBackElement(&obj,&val,1)) throw std::bad_alloc();
			return;
		}
		void pushBack(const T*const restrict arr,const size_t len){
			if(!::shinsei_deque_t_pushBackArray(&obj,arr,len)) throw std::bad_alloc();
			return;
		}
		void pushBack(const T& val,const size_t cnt){
			if(!::shinsei_deque_t_pushBackElement(&obj,&val,cnt)) throw std::bad_alloc();
			return;
		}
		
		void swap(deque_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_swap(&obj,src.cObj());
			return;
		}
		void swap(::shinsei_deque_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_swap(&obj,&src);
			return;
		}
		void clear(){
			if(!::shinsei_deque_t_clear(&obj)) throw std::bad_alloc();
			return;
		}
		void setSize(const size_t size){
			if(!::shinsei_deque_t_setSize(&obj,size)) throw std::bad_alloc();
			return;
		}
		
		// Standard API Operations
		void assign(const deque_t& src){
			if(!::shinsei_deque_t_assign(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		void assign(const ::shinsei_deque_t& src){
			if(!::shinsei_deque_t_assign(&obj,&src)) throw std::bad_alloc();
			return;
		}
		deque_t& operator=(const deque_t& src){
			if(this==&src) return *this;
			if(!::shinsei_deque_t_assign(&obj,src.cObj())) throw std::bad_alloc();
			return *this;
		}
		deque_t& operator=(const ::shinsei_deque_t& src){
			if(!::shinsei_deque_t_assign(&obj,&src)) throw std::bad_alloc();
			return *this;
		}
		
		void move(deque_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_move(&obj,src.cObj());
			return;
		}
		void move(::shinsei_deque_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_move(&obj,&src);
			return;
		}
		deque_t& operator=(deque_t&& src)_SHINSEI_OS_NOEXCEPT{
			if(this==&src) return *this;
			::shinsei_deque_t_move(&obj,src.cObj());
			return *this;
		}
		deque_t& operator=(::shinsei_deque_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_move(&obj,&src);
			return *this;
		}
		
		// Attach Operations
		void attach(const deque_t& src){
			if(!::shinsei_deque_t_attach(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		void attach(const ::shinsei_deque_t& src){
			if(!::shinsei_deque_t_attach(&obj,&src)) throw std::bad_alloc();
			return;
		}
		void attach(const int_fast32_t ctrl,const size_t head,const size_t tail,const size_t cap,T*const ptr){
			if(!::shinsei_deque_t_attachValue(&obj,ctrl,head,tail,cap,ptr,sizeof(T))) throw std::bad_alloc();
			return;
		}
		
		// Free Data
		void freeData(){
			::shinsei_deque_t_freeData(&obj);
			return;
		}
		
		// Static Helpers (for explicit C-struct manipulation in user code)
		static void as(deque_t*const restrict ptr){
			if(!::shinsei_deque_t_as(ptr->cObj(),sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_deque_t*const restrict ptr){
			if(!::shinsei_deque_t_as(ptr,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(deque_t*const restrict ptr,const size_t cap){
			if(!::shinsei_deque_t_asCapacity(ptr->cObj(),cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_deque_t*const restrict ptr,const size_t cap){
			if(!::shinsei_deque_t_asCapacity(ptr,cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(deque_t*const restrict ptr,const deque_t& src){
			if(!::shinsei_deque_t_asCopy(ptr->cObj(),src.cObj())) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_deque_t*const restrict ptr,const ::shinsei_deque_t& src){
			if(!::shinsei_deque_t_asCopy(ptr,&src)) throw std::bad_alloc();
			return;
		}
		static void as(deque_t*const restrict ptr,deque_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_asMove(ptr->cObj(),src.cObj());
			return;
		}
		static void as(::shinsei_deque_t*const restrict ptr,::shinsei_deque_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_asMove(ptr,&src);
			return;
		}
		static void as(deque_t*const restrict ptr,const T& val,const size_t cnt){
			if(!::shinsei_deque_t_asElement(ptr->cObj(),&val,cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_deque_t*const restrict ptr,const T& val,const size_t cnt){
			if(!::shinsei_deque_t_asElement(ptr,&val,cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(deque_t*const restrict ptr,const T*const restrict arr,const size_t len){
			if(!::shinsei_deque_t_asArray(ptr->cObj(),arr,len,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_deque_t*const restrict ptr,const T*const restrict arr,const size_t len){
			if(!::shinsei_deque_t_asArray(ptr,arr,len,sizeof(T))) throw std::bad_alloc();
			return;
		}
		
		static void inl(deque_t*const restrict ptr,const size_t cap)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_inl(ptr->cObj(),cap,sizeof(T));
			return;
		}
		static void inl(::shinsei_deque_t*const restrict ptr,const size_t cap)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_inl(ptr,cap,sizeof(T));
			return;
		}
		static void inl(deque_t*const restrict ptr,const deque_t& src){
			if(!::shinsei_deque_t_inlCopy(ptr->cObj(),src.cObj())) throw std::bad_alloc();
			return;
		}
		static void inl(::shinsei_deque_t*const restrict ptr,const ::shinsei_deque_t& src){
			if(!::shinsei_deque_t_inlCopy(ptr,&src)) throw std::bad_alloc();
			return;
		}
		static void inl(deque_t*const restrict ptr,deque_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_inlMove(ptr->cObj(),src.cObj());
			return;
		}
		static void inl(::shinsei_deque_t*const restrict ptr,::shinsei_deque_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_inlMove(ptr,&src);
			return;
		}
		static void inl(deque_t*const restrict ptr,const T& val,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_inlElement(ptr->cObj(),&val,cnt,sizeof(T));
			return;
		}
		static void inl(::shinsei_deque_t*const restrict ptr,const T& val,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_inlElement(ptr,&val,cnt,sizeof(T));
			return;
		}
		static void inl(deque_t*const restrict ptr,const T*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_inlArray(ptr->cObj(),arr,len,sizeof(T));
			return;
		}
		static void inl(::shinsei_deque_t*const restrict ptr,const T*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_inlArray(ptr,arr,len,sizeof(T));
			return;
		}
		
		// Core Identity Controls
		bool inlined()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_deque_t_inlined(&obj);
		}
		int_fast32_t getCtrl()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_deque_t_getCtrl(&obj);
		}
		void setCtrl(const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
			::shinsei_deque_t_setCtrl(&obj,ctrl);
			return;
		}
		
		// Type Casting / Access
		::shinsei_deque_t* cObj()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		const ::shinsei_deque_t* cObj()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator ::shinsei_deque_t*()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator const ::shinsei_deque_t*()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
	};
	
	// vector_t
	template<typename T>
	class vector_t{
	private:
		::shinsei_vector_t obj;
	public:
		static _SHINSEI_OS_CONSTEXPR size_t DEF_CAP=::shinsei_vector_t_DEF_CAP;
		
		// Default constructor
		vector_t(){
			if(!::shinsei_vector_t_as(&obj,sizeof(T))) throw std::bad_alloc();
			return;
		}
		// Capacity constructor
		explicit vector_t(const size_t cap){
			if(!::shinsei_vector_t_asCapacity(&obj,cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		// Copy constructor
		vector_t(const vector_t& src){
			if(!::shinsei_vector_t_asCopy(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		vector_t(const ::shinsei_vector_t& src){
			if(!::shinsei_vector_t_asCopy(&obj,&src)) throw std::bad_alloc();
			return;
		}
		// Move constructor
		vector_t(vector_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_asMove(&obj,src.cObj());
			return;
		}
		vector_t(::shinsei_vector_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_asMove(&obj,&src);
			return;
		}
		// From Element/Array
		vector_t(const size_t repeat_cnt,const T& val){
			if(!::shinsei_vector_t_asElement(&obj,&val,repeat_cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		vector_t(const T*const restrict arr,const size_t len){
			if(!::shinsei_vector_t_asArray(&obj,arr,len,sizeof(T))) throw std::bad_alloc();
			return;
		}
		
		// In-place Constructors
		explicit vector_t(shinsei::in_place_t){
			if(!::shinsei_vector_t_as(&obj,sizeof(T))) throw std::bad_alloc();
			return;
		}
		explicit vector_t(shinsei::in_place_t,const size_t cap){
			if(!::shinsei_vector_t_asCapacity(&obj,cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		explicit vector_t(shinsei::in_place_t,const vector_t& src){
			if(!::shinsei_vector_t_asCopy(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		explicit vector_t(shinsei::in_place_t,const ::shinsei_vector_t& src){
			if(!::shinsei_vector_t_asCopy(&obj,&src)) throw std::bad_alloc();
			return;
		}
		explicit vector_t(shinsei::in_place_t,vector_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_asMove(&obj,src.cObj());
			return;
		}
		explicit vector_t(shinsei::in_place_t,::shinsei_vector_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_asMove(&obj,&src);
			return;
		}
		explicit vector_t(shinsei::in_place_t,const size_t repeat_cnt,const T& val){
			if(!::shinsei_vector_t_asElement(&obj,&val,repeat_cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		explicit vector_t(shinsei::in_place_t,const T*const restrict arr,const size_t len){
			if(!::shinsei_vector_t_asArray(&obj,arr,len,sizeof(T))) throw std::bad_alloc();
			return;
		}
		
		// Inlined Constructors
		explicit vector_t(shinsei::inlined_t,const size_t cap)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_inl(&obj,cap,sizeof(T));
			return;
		}
		explicit vector_t(shinsei::inlined_t,const vector_t& src){
			if(!::shinsei_vector_t_inlAssign(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		explicit vector_t(shinsei::inlined_t,const ::shinsei_vector_t& src){
			if(!::shinsei_vector_t_inlAssign(&obj,&src)) throw std::bad_alloc();
			return;
		}
		explicit vector_t(shinsei::inlined_t,vector_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_inlMove(&obj,src.cObj());
			return;
		}
		explicit vector_t(shinsei::inlined_t,::shinsei_vector_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_inlMove(&obj,&src);
			return;
		}
		explicit vector_t(shinsei::inlined_t,const size_t repeat_cnt,const T& val)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_inlElement(&obj,&val,repeat_cnt,sizeof(T));
			return;
		}
		explicit vector_t(shinsei::inlined_t,const T*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_inlArray(&obj,arr,len,sizeof(T));
			return;
		}
		
		// Destructor
		~vector_t(){
			if(!inlined()) ::shinsei_vector_t_freeData(&obj);
			return;
		}
		
		// Capacity
		void expand(const size_t more_cap){
			if(!::shinsei_vector_t_expand(&obj,more_cap)) throw std::bad_alloc();
			return;
		}
		void shrink(const size_t less_cap){
			if(!::shinsei_vector_t_shrink(&obj,less_cap)) throw std::bad_alloc();
			return;
		}
		void reserve(const size_t cap){
			if(!::shinsei_vector_t_reserve(&obj,cap)) throw std::bad_alloc();
			return;
		}
		void shrinkToFit(){
			if(!::shinsei_vector_t_shrinkToFit(&obj)) throw std::bad_alloc();
			return;
		}
		
		// Info & Access
		bool empty()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_vector_t_empty(&obj);
		}
		size_t size()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_vector_t_size(&obj);
		}
		size_t capacity()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_vector_t_capacity(&obj);
		}
		T& front()const _SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_vector_t_at(&obj,0);
		}
		T& back()const _SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_vector_t_at(&obj,::shinsei_vector_t_size(&obj)-1);
		}
		T& at(const size_t idx)_SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_vector_t_at(&obj,idx);
		}
		const T& at(const size_t idx)const _SHINSEI_OS_NOEXCEPT{
			return *(const T*)::shinsei_vector_t_at(&obj,idx);
		}
		T& operator[](const size_t idx)_SHINSEI_OS_NOEXCEPT{
			return *(T*)::shinsei_vector_t_at(&obj,idx);
		}
		const T& operator[](const size_t idx)const _SHINSEI_OS_NOEXCEPT{
			return *(const T*)::shinsei_vector_t_at(&obj,idx);
		}
		T* data()_SHINSEI_OS_NOEXCEPT{
			return (T*)::shinsei_vector_t_data(&obj);
		}
		const T* data()const _SHINSEI_OS_NOEXCEPT{
			return (const T*)::shinsei_vector_t_data(&obj);
		}
		
		// Modification
		void popBack()_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_popBack(&obj);
			return;
		}
		void popBack(const size_t cnt)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_popBackArray(&obj,cnt);
			return;
		}
		
		void pushBack(const T& val){
			if(!::shinsei_vector_t_pushBackElement(&obj,&val,1)) throw std::bad_alloc();
			return;
		}
		void pushBack(const T*const restrict arr,const size_t len){
			if(!::shinsei_vector_t_pushBackArray(&obj,arr,len)) throw std::bad_alloc();
			return;
		}
		void pushBack(const T& val,const size_t cnt){
			if(!::shinsei_vector_t_pushBackElement(&obj,&val,cnt)) throw std::bad_alloc();
			return;
		}
		
		void insert(const size_t idx,const T& val){
			if(!::shinsei_vector_t_insertElement(&obj,idx,&val,1)) throw std::bad_alloc();
			return;
		}
		void insert(const size_t idx,const T*const restrict src,const size_t len){
			if(!::shinsei_vector_t_insertArray(&obj,idx,src,len)) throw std::bad_alloc();
			return;
		}
		void insert(const size_t idx,const T& val,const size_t cnt){
			if(!::shinsei_vector_t_insertElement(&obj,idx,&val,cnt)) throw std::bad_alloc();
			return;
		}
		
		void erase(const size_t idx)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_eraseArray(&obj,idx,1);
			return;
		}
		void erase(const size_t idx,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_eraseArray(&obj,idx,len);
			return;
		}
		
		void swap(vector_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_swap(&obj,src.cObj());
			return;
		}
		void swap(::shinsei_vector_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_swap(&obj,&src);
			return;
		}
		void clear(){
			if(!::shinsei_vector_t_clear(&obj)) throw std::bad_alloc();
			return;
		}
		void setSize(const size_t size){
			if(!::shinsei_vector_t_setSize(&obj,size)) throw std::bad_alloc();
			return;
		}
		
		// Standard API Operations
		void assign(const vector_t& src){
			if(!::shinsei_vector_t_assign(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		void assign(const ::shinsei_vector_t& src){
			if(!::shinsei_vector_t_assign(&obj,&src)) throw std::bad_alloc();
			return;
		}
		vector_t& operator=(const vector_t& src){
			if(this==&src) return *this;
			if(!::shinsei_vector_t_assign(&obj,src.cObj())) throw std::bad_alloc();
			return *this;
		}
		vector_t& operator=(const ::shinsei_vector_t& src){
			if(!::shinsei_vector_t_assign(&obj,&src)) throw std::bad_alloc();
			return *this;
		}
		
		void move(vector_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_move(&obj,src.cObj());
			return;
		}
		void move(::shinsei_vector_t& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_move(&obj,&src);
			return;
		}
		vector_t& operator=(vector_t&& src)_SHINSEI_OS_NOEXCEPT{
			if(this==&src) return *this;
			::shinsei_vector_t_move(&obj,src.cObj());
			return *this;
		}
		vector_t& operator=(::shinsei_vector_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_move(&obj,&src);
			return *this;
		}
		
		// Attach Operations
		void attach(const vector_t& src){
			if(!::shinsei_vector_t_attach(&obj,src.cObj())) throw std::bad_alloc();
			return;
		}
		void attach(const ::shinsei_vector_t& src){
			if(!::shinsei_vector_t_attach(&obj,&src)) throw std::bad_alloc();
			return;
		}
		void attach(const int_fast32_t ctrl,const size_t size,const size_t cap,T*const ptr){
			if(!::shinsei_vector_t_attachValue(&obj,ctrl,size,cap,ptr,sizeof(T))) throw std::bad_alloc();
			return;
		}
		
		// Free Data
		void freeData(){
			::shinsei_vector_t_freeData(&obj);
			return;
		}
		
		// Static Helpers (for explicit C-struct manipulation in user code)
		static void as(vector_t*const restrict ptr){
			if(!::shinsei_vector_t_as(ptr->cObj(),sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_vector_t*const restrict ptr){
			if(!::shinsei_vector_t_as(ptr,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(vector_t*const restrict ptr,const size_t cap){
			if(!::shinsei_vector_t_asCapacity(ptr->cObj(),cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_vector_t*const restrict ptr,const size_t cap){
			if(!::shinsei_vector_t_asCapacity(ptr,cap,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(vector_t*const restrict ptr,const vector_t& src){
			if(!::shinsei_vector_t_asCopy(ptr->cObj(),src.cObj())) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_vector_t*const restrict ptr,const ::shinsei_vector_t& src){
			if(!::shinsei_vector_t_asCopy(ptr,&src)) throw std::bad_alloc();
			return;
		}
		static void as(vector_t*const restrict ptr,vector_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_asMove(ptr->cObj(),src.cObj());
			return;
		}
		static void as(::shinsei_vector_t*const restrict ptr,::shinsei_vector_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_asMove(ptr,&src);
			return;
		}
		static void as(vector_t*const restrict ptr,const T& val,const size_t cnt){
			if(!::shinsei_vector_t_asElement(ptr->cObj(),&val,cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_vector_t*const restrict ptr,const T& val,const size_t cnt){
			if(!::shinsei_vector_t_asElement(ptr,&val,cnt,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(vector_t*const restrict ptr,const T*const restrict arr,const size_t len){
			if(!::shinsei_vector_t_asArray(ptr->cObj(),arr,len,sizeof(T))) throw std::bad_alloc();
			return;
		}
		static void as(::shinsei_vector_t*const restrict ptr,const T*const restrict arr,const size_t len){
			if(!::shinsei_vector_t_asArray(ptr,arr,len,sizeof(T))) throw std::bad_alloc();
			return;
		}
		
		static void inl(vector_t*const restrict ptr,const size_t cap)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_inl(ptr->cObj(),cap,sizeof(T));
			return;
		}
		static void inl(::shinsei_vector_t*const restrict ptr,const size_t cap)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_inl(ptr,cap,sizeof(T));
			return;
		}
		static void inl(vector_t*const restrict ptr,const vector_t& src){
			if(!::shinsei_vector_t_inlAssign(ptr->cObj(),src.cObj())) throw std::bad_alloc();
			return;
		}
		static void inl(::shinsei_vector_t*const restrict ptr,const ::shinsei_vector_t& src){
			if(!::shinsei_vector_t_inlAssign(ptr,&src)) throw std::bad_alloc();
			return;
		}
		static void inl(vector_t*const restrict ptr,vector_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_inlMove(ptr->cObj(),src.cObj());
			return;
		}
		static void inl(::shinsei_vector_t*const restrict ptr,::shinsei_vector_t&& src)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_inlMove(ptr,&src);
			return;
		}
		static void inl(vector_t*const restrict ptr,const T& val,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_inlElement(ptr->cObj(),&val,cnt,sizeof(T));
			return;
		}
		static void inl(::shinsei_vector_t*const restrict ptr,const T& val,const size_t cnt)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_inlElement(ptr,&val,cnt,sizeof(T));
			return;
		}
		static void inl(vector_t*const restrict ptr,const T*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_inlArray(ptr->cObj(),arr,len,sizeof(T));
			return;
		}
		static void inl(::shinsei_vector_t*const restrict ptr,const T*const restrict arr,const size_t len)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_inlArray(ptr,arr,len,sizeof(T));
			return;
		}
		
		// Core Identity Controls
		bool inlined()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_vector_t_inlined(&obj);
		}
		int_fast32_t getCtrl()const _SHINSEI_OS_NOEXCEPT{
			return ::shinsei_vector_t_getCtrl(&obj);
		}
		void setCtrl(const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
			::shinsei_vector_t_setCtrl(&obj,ctrl);
			return;
		}
		
		// Type Casting / Access
		::shinsei_vector_t* cObj()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		const ::shinsei_vector_t* cObj()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator ::shinsei_vector_t*()_SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
		operator const ::shinsei_vector_t*()const _SHINSEI_OS_NOEXCEPT{
			return &obj;
		}
	};
	
}
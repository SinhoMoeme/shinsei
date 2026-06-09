#pragma once
#include"shinsei/ex/python3/struct.h"
#include"shinsei/.internal/tag.hpp"
#include<new>

namespace shinsei{
	namespace ex{
		class pystack_t{
		private:
			::shinsei_ex_pystack_t obj;
		public:
			constexpr size_t DEF_CAP=8;
			
			// Default constructor
			pystack_t(){
				if(!::shinsei_ex_pystack_t_as(&obj)) throw std::bad_alloc();
				return;
			}
			// Capacity constructor
			explicit pystack_t(const size_t cap){
				if(!::shinsei_ex_pystack_t_asCapacity(&obj,cap)) throw std::bad_alloc();
				return;
			}
			// Copy constructor
			pystack_t(const pystack_t& src){
				if(!::shinsei_ex_pystack_t_asCopy(&obj,src.cObj())) throw std::bad_alloc();
				return;
			}
			pystack_t(const ::shinsei_ex_pystack_t& src){
				if(!::shinsei_ex_pystack_t_asCopy(&obj,&src)) throw std::bad_alloc();
				return;
			}
			explicit pystack_t(shinsei::unsafe_t,const pystack_t& src){
				if(!::shinsei_ex_pystack_t_asCopyUnsafe(&obj,src.cObj())) throw std::bad_alloc();
				return;
			}
			explicit pystack_t(shinsei::unsafe_t,const ::shinsei_ex_pystack_t& src){
				if(!::shinsei_ex_pystack_t_asCopyUnsafe(&obj,&src)) throw std::bad_alloc();
				return;
			}
			// Move constructor
			pystack_t(pystack_t&& src)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_asMove(&obj,src.cObj());
				return;
			}
			pystack_t(::shinsei_ex_pystack_t&& src)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_asMove(&obj,&src);
				return;
			}
			
			// In-place Constructors
			explicit pystack_t(shinsei::in_place_t){
				if(!::shinsei_ex_pystack_t_as(&obj)) throw std::bad_alloc();
				return;
			}
			explicit pystack_t(shinsei::in_place_t,const size_t cap){
				if(!::shinsei_ex_pystack_t_asCapacity(&obj,cap)) throw std::bad_alloc();
				return;
			}
			explicit pystack_t(shinsei::in_place_t,const pystack_t& src){
				if(!::shinsei_ex_pystack_t_asCopy(&obj,src.cObj())) throw std::bad_alloc();
				return;
			}
			explicit pystack_t(shinsei::in_place_t,const ::shinsei_ex_pystack_t& src){
				if(!::shinsei_ex_pystack_t_asCopy(&obj,&src)) throw std::bad_alloc();
				return;
			}
			explicit pystack_t(shinsei::unsafe_t,shinsei::in_place_t,const pystack_t& src){
				if(!::shinsei_ex_pystack_t_asCopyUnsafe(&obj,src.cObj())) throw std::bad_alloc();
				return;
			}
			explicit pystack_t(shinsei::unsafe_t,shinsei::in_place_t,const ::shinsei_ex_pystack_t& src){
				if(!::shinsei_ex_pystack_t_asCopyUnsafe(&obj,&src)) throw std::bad_alloc();
				return;
			}
			explicit pystack_t(shinsei::in_place_t,pystack_t&& src)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_asMove(&obj,src.cObj());
				return;
			}
			explicit pystack_t(shinsei::in_place_t,::shinsei_ex_pystack_t&& src)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_asMove(&obj,&src);
				return;
			}
			
			// Inlined Constructors
			explicit pystack_t(shinsei::inlined_t,const size_t cap)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_inl(&obj,cap);
				return;
			}
			explicit pystack_t(shinsei::inlined_t,const pystack_t& src){
				if(!::shinsei_ex_pystack_t_inlCopy(&obj,src.cObj())) throw std::bad_alloc();
				return;
			}
			explicit pystack_t(shinsei::inlined_t,const ::shinsei_ex_pystack_t& src){
				if(!::shinsei_ex_pystack_t_inlCopy(&obj,&src)) throw std::bad_alloc();
				return;
			}
			explicit pystack_t(shinsei::unsafe_t,shinsei::inlined_t,const pystack_t& src){
				if(!::shinsei_ex_pystack_t_inlCopyUnsafe(&obj,src.cObj())) throw std::bad_alloc();
				return;
			}
			explicit pystack_t(shinsei::unsafe_t,shinsei::inlined_t,const ::shinsei_ex_pystack_t& src){
				if(!::shinsei_ex_pystack_t_inlCopyUnsafe(&obj,&src)) throw std::bad_alloc();
				return;
			}
			explicit pystack_t(shinsei::inlined_t,pystack_t&& src)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_inlMove(&obj,src.cObj());
				return;
			}
			explicit pystack_t(shinsei::inlined_t,::shinsei_ex_pystack_t&& src)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_inlMove(&obj,&src);
				return;
			}
			
			// Destructor
			~pystack_t()_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_freeData(&obj);
				return;
			}
			
			// Capacity
			void expand(const size_t more_cap){
				if(!::shinsei_ex_pystack_t_expand(&obj,more_cap)) throw std::bad_alloc();
				return;
			}
			void shrink(const size_t less_cap){
				if(!::shinsei_ex_pystack_t_shrink(&obj,less_cap)) throw std::bad_alloc();
				return;
			}
			void reserve(const size_t cap){
				if(!::shinsei_ex_pystack_t_reserve(&obj,cap)) throw std::bad_alloc();
				return;
			}
			void shrinkToFit(){
				if(!::shinsei_ex_pystack_t_shrinkToFit(&obj)) throw std::bad_alloc();
				return;
			}
			
			// Info & Access
			bool empty()const _SHINSEI_OS_NOEXCEPT{
				return ::shinsei_ex_pystack_t_empty(&obj);
			}
			size_t size()const _SHINSEI_OS_NOEXCEPT{
				return ::shinsei_ex_pystack_t_size(&obj);
			}
			size_t capacity()const _SHINSEI_OS_NOEXCEPT{
				return ::shinsei_ex_pystack_t_capacity(&obj);
			}
			PyObject* top()const _SHINSEI_OS_NOEXCEPT{
				return ::shinsei_ex_pystack_t_top(&obj);
			}
			PyObject* topUnsafe()const _SHINSEI_OS_NOEXCEPT{
				return ::shinsei_ex_pystack_t_topUnsafe(&obj);
			}
			PyObject* at(const size_t idx)const _SHINSEI_OS_NOEXCEPT{
				return ::shinsei_ex_pystack_t_at(&obj,idx);
			}
			PyObject* atUnsafe(const size_t idx)const _SHINSEI_OS_NOEXCEPT{
				return ::shinsei_ex_pystack_t_atUnsafe(&obj,idx);
			}
			PyObject* operator[](const size_t idx)const _SHINSEI_OS_NOEXCEPT{
				return ::shinsei_ex_pystack_t_at(&obj,idx);
			}
			PyObject** data()_SHINSEI_OS_NOEXCEPT{
				return ::shinsei_ex_pystack_t_data(&obj);
			}
			PyObject*const* data()const _SHINSEI_OS_NOEXCEPT{
				return (PyObject*const*)::shinsei_ex_pystack_t_data(&obj);
			}
			
			// Modification
			void pop()_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_pop(&obj);
				return;
			}
			void popUnsafe()_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_popUnsafe(&obj);
				return;
			}
			void push(const PyObject*const restrict val){
				if(!::shinsei_ex_pystack_t_push(&obj,val)) throw std::bad_alloc();
				return;
			}
			void pushUnsafe(const PyObject*const restrict val){
				if(!::shinsei_ex_pystack_t_pushUnsafe(&obj,val)) throw std::bad_alloc();
				return;
			}
			void swap(pystack_t& src)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_swap(&obj,src.cObj());
				return;
			}
			void swap(::shinsei_ex_pystack_t& src)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_swap(&obj,&src);
				return;
			}
			void clear(){
				if(!::shinsei_ex_pystack_t_clear(&obj)) throw std::bad_alloc();
				return;
			}
			void clearUnsafe(){
				if(!::shinsei_ex_pystack_t_clearUnsafe(&obj)) throw std::bad_alloc();
				return;
			}
			void setSize(const size_t size){
				if(!::shinsei_ex_pystack_t_setSize(&obj,size)) throw std::bad_alloc();
				return;
			}
			
			// Standard API Operations
			void assign(const pystack_t& src){
				if(!::shinsei_ex_pystack_t_assign(&obj,src.cObj())) throw std::bad_alloc();
				return;
			}
			void assign(const ::shinsei_ex_pystack_t& src){
				if(!::shinsei_ex_pystack_t_assign(&obj,&src)) throw std::bad_alloc();
				return;
			}
			void assignUnsafe(const pystack_t& src){
				if(!::shinsei_ex_pystack_t_assignUnsafe(&obj,src.cObj())) throw std::bad_alloc();
				return;
			}
			void assignUnsafe(const ::shinsei_ex_pystack_t& src){
				if(!::shinsei_ex_pystack_t_assignUnsafe(&obj,&src)) throw std::bad_alloc();
				return;
			}
			pystack_t& operator=(const pystack_t& src){
				if(this==&src) return *this;
				if(!::shinsei_ex_pystack_t_assign(&obj,src.cObj())) throw std::bad_alloc();
				return *this;
			}
			pystack_t& operator=(const ::shinsei_ex_pystack_t& src){
				if(!::shinsei_ex_pystack_t_assign(&obj,&src)) throw std::bad_alloc();
				return *this;
			}
			
			void move(pystack_t& src)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_move(&obj,src.cObj());
				return;
			}
			void move(::shinsei_ex_pystack_t& src)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_move(&obj,&src);
				return;
			}
			void moveUnsafe(pystack_t& src)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_moveUnsafe(&obj,src.cObj());
				return;
			}
			void moveUnsafe(::shinsei_ex_pystack_t& src)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_moveUnsafe(&obj,&src);
				return;
			}
			pystack_t& operator=(pystack_t&& src)_SHINSEI_OS_NOEXCEPT{
				if(this==&src) return *this;
				::shinsei_ex_pystack_t_move(&obj,src.cObj());
				return *this;
			}
			pystack_t& operator=(::shinsei_ex_pystack_t&& src)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_move(&obj,&src);
				return *this;
			}
			
			// Attach Operations
			void attach(const pystack_t& src){
				if(!::shinsei_ex_pystack_t_attach(&obj,src.cObj())) throw std::bad_alloc();
				return;
			}
			void attach(const ::shinsei_ex_pystack_t& src){
				if(!::shinsei_ex_pystack_t_attach(&obj,&src)) throw std::bad_alloc();
				return;
			}
			void attachUnsafe(const pystack_t& src){
				if(!::shinsei_ex_pystack_t_attachUnsafe(&obj,src.cObj())) throw std::bad_alloc();
				return;
			}
			void attachUnsafe(const ::shinsei_ex_pystack_t& src){
				if(!::shinsei_ex_pystack_t_attachUnsafe(&obj,&src)) throw std::bad_alloc();
				return;
			}
			
			void attachValue(const int_fast32_t ctrl,const size_t size,const size_t cap,PyObject**const ptr){
				if(!::shinsei_ex_pystack_t_attachValue(&obj,ctrl,size,cap,ptr)) throw std::bad_alloc();
				return;
			}
			void attachValueUnsafe(const int_fast32_t ctrl,const size_t size,const size_t cap,PyObject**const ptr){
				if(!::shinsei_ex_pystack_t_attachValueUnsafe(&obj,ctrl,size,cap,ptr)) throw std::bad_alloc();
				return;
			}
			
			// Free Data
			void freeData()_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_freeData(&obj);
				return;
			}
			void freeDataUnsafe()_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_freeDataUnsafe(&obj);
				return;
			}
			
			// Static Helpers (for explicit C-struct manipulation in user code)
			static void as(pystack_t*const restrict ptr){
				if(!::shinsei_ex_pystack_t_as(ptr->cObj())) throw std::bad_alloc();
				return;
			}
			static void as(::shinsei_ex_pystack_t*const restrict ptr){
				if(!::shinsei_ex_pystack_t_as(ptr)) throw std::bad_alloc();
				return;
			}
			static void asCapacity(pystack_t*const restrict ptr,const size_t cap){
				if(!::shinsei_ex_pystack_t_asCapacity(ptr->cObj(),cap)) throw std::bad_alloc();
				return;
			}
			static void asCapacity(::shinsei_ex_pystack_t*const restrict ptr,const size_t cap){
				if(!::shinsei_ex_pystack_t_asCapacity(ptr,cap)) throw std::bad_alloc();
				return;
			}
			static void asCopy(pystack_t*const restrict ptr,const pystack_t& src){
				if(!::shinsei_ex_pystack_t_asCopy(ptr->cObj(),src.cObj())) throw std::bad_alloc();
				return;
			}
			static void asCopy(pystack_t*const restrict ptr,const ::shinsei_ex_pystack_t& src){
				if(!::shinsei_ex_pystack_t_asCopy(ptr->cObj(),&src)) throw std::bad_alloc();
				return;
			}
			static void asCopyUnsafe(pystack_t*const restrict ptr,const pystack_t& src){
				if(!::shinsei_ex_pystack_t_asCopyUnsafe(ptr->cObj(),src.cObj())) throw std::bad_alloc();
				return;
			}
			static void asCopyUnsafe(pystack_t*const restrict ptr,const ::shinsei_ex_pystack_t& src){
				if(!::shinsei_ex_pystack_t_asCopyUnsafe(ptr->cObj(),&src)) throw std::bad_alloc();
				return;
			}
			
			static void asMove(pystack_t*const restrict ptr,pystack_t& src)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_asMove(ptr->cObj(),src.cObj());
				return;
			}
			static void asMove(pystack_t*const restrict ptr,::shinsei_ex_pystack_t& src)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_asMove(ptr->cObj(),&src);
				return;
			}
			
			static void inl(pystack_t*const restrict ptr,const size_t cap)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_inl(ptr->cObj(),cap);
				return;
			}
			static void inl(::shinsei_ex_pystack_t*const restrict ptr,const size_t cap)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_inl(ptr,cap);
				return;
			}
			static void inlCapacity(pystack_t*const restrict ptr,const size_t cap)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_inlCapacity(ptr->cObj(),cap);
				return;
			}
			static void inlCapacity(::shinsei_ex_pystack_t*const restrict ptr,const size_t cap)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_inlCapacity(ptr,cap);
				return;
			}
			static void inlCopy(pystack_t*const restrict ptr,const pystack_t& src){
				if(!::shinsei_ex_pystack_t_inlCopy(ptr->cObj(),src.cObj())) throw std::bad_alloc();
				return;
			}
			static void inlCopy(pystack_t*const restrict ptr,const ::shinsei_ex_pystack_t& src){
				if(!::shinsei_ex_pystack_t_inlCopy(ptr->cObj(),&src)) throw std::bad_alloc();
				return;
			}
			static void inlCopyUnsafe(pystack_t*const restrict ptr,const pystack_t& src){
				if(!::shinsei_ex_pystack_t_inlCopyUnsafe(ptr->cObj(),src.cObj())) throw std::bad_alloc();
				return;
			}
			static void inlCopyUnsafe(pystack_t*const restrict ptr,const ::shinsei_ex_pystack_t& src){
				if(!::shinsei_ex_pystack_t_inlCopyUnsafe(ptr->cObj(),&src)) throw std::bad_alloc();
				return;
			}
			
			static void inlMove(pystack_t*const restrict ptr,pystack_t& src)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_inlMove(ptr->cObj(),src.cObj());
				return;
			}
			static void inlMove(pystack_t*const restrict ptr,::shinsei_ex_pystack_t& src)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_inlMove(ptr->cObj(),&src);
				return;
			}
			
			// Core Identity Controls
			bool inlined()const _SHINSEI_OS_NOEXCEPT{
				return ::shinsei_ex_pystack_t_inlined(&obj);
			}
			int_fast32_t getCtrl()const _SHINSEI_OS_NOEXCEPT{
				return ::shinsei_ex_pystack_t_getCtrl(&obj);
			}
			void setCtrl(const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_pystack_t_setCtrl(&obj,ctrl);
				return;
			}
			
			// Type Casting / Access
			::shinsei_ex_pystack_t* cObj()_SHINSEI_OS_NOEXCEPT{
				return &obj;
			}
			const ::shinsei_ex_pystack_t* cObj()const _SHINSEI_OS_NOEXCEPT{
				return &obj;
			}
			operator ::shinsei_ex_pystack_t*()_SHINSEI_OS_NOEXCEPT{
				return &obj;
			}
			operator const ::shinsei_ex_pystack_t*()const _SHINSEI_OS_NOEXCEPT{
				return &obj;
			}
		};
	}
}
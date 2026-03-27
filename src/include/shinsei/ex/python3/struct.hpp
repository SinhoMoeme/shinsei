#include"shinsei/ex/python3/struct.h"
#include"shinsei/ex/python3/gil.hpp"
#include<new>

namespace shinsei{
	namespace ex{
		class pystack_t{
		private:
			::shinsei_ex_pystack_t obj;
		public:
			// Default constructor
			pystack_t(){
				if(!::shinsei_ex_pystack_t_as(&obj)) throw std::bad_alloc();
				return;
			}
			// Copy constructor
			pystack_t(const pystack_t& src){
				if(!::shinsei_ex_pystack_t_asAssign(&obj,src.cObj())) throw std::bad_alloc();
				return;
			}
			pystack_t(const ::shinsei_ex_pystack_t& src){
				if(!::shinsei_ex_pystack_t_asAssign(&obj,&src)) throw std::bad_alloc();
				return;
			}
			// Move constructor
			pystack_t(pystack_t&& src)noexcept{
				::shinsei_ex_pystack_t_asMove(&obj,src.cObj());
				return;
			}
			pystack_t(::shinsei_ex_pystack_t&& src)noexcept{
				::shinsei_ex_pystack_t_asMove(&obj,&src);
				return;
			}
			
			// Destructor
			~pystack_t(){
				::shinsei_ex_pystack_t_freeData(&obj);
				return;
			}
			
			// Expand capacity by more_cap
			bool expand(const size_t more_cap){
				return ::shinsei_ex_pystack_t_expand(&obj,more_cap);
			}
			
			// Shrink capacity by less_cap
			bool shrink(const size_t less_cap){
				return ::shinsei_ex_pystack_t_shrink(&obj,less_cap);
			}
			
			// Reserve for the elements
			bool reserve(const size_t cap){
				return ::shinsei_ex_pystack_t_reserve(&obj,cap);
			}
			
			// Shrink capacity to fit
			bool shrinkToFit(){
				return ::shinsei_ex_pystack_t_shrinkToFit(&obj);
			}
			
			// [Const] Check if stack is empty
			bool empty()const{
				return ::shinsei_ex_pystack_t_empty(&obj);
			}
			
			// [Const] Get stack size
			size_t size()const{
				return ::shinsei_ex_pystack_t_size(&obj);
			}
			
			// [Const] Get stack capacity
			size_t capacity()const{
				return ::shinsei_ex_pystack_t_capacity(&obj);
			}
			
			// [Const] Get the top element
			PyObject* top()const{
				return ::shinsei_ex_pystack_t_top(&obj);
			}
			
			// [Const] Get the element at idx
			PyObject* at(const size_t idx)const{
				return ::shinsei_ex_pystack_t_at(&obj,idx);
			}
			
			// [Const] Get the element data
			PyObject** data()const{
				return ::shinsei_ex_pystack_t_data(&obj);
			}
			
			// Pop the top element
			void pop(){
				::shinsei_ex_pystack_t_pop(&obj);
				return;
				
			}
			
			// Push an element to the top
			void push(const PyObject*const restrict val){
				::shinsei_ex_pystack_t_push(&obj,val);
				return;
			}
			
			// Swap 2 stacks
			void swap(pystack_t& src){
				::shinsei_ex_pystack_t_swap(&obj,src.cObj());
				return;
			}
			void swap(::shinsei_ex_pystack_t& src){
				::shinsei_ex_pystack_t_swap(&obj,&src);
				return;
			}
			
			// Clear all elements
			void clear(){
				::shinsei_ex_pystack_t_clear(&obj);
				return;
			}
			
			// Set stack size
			void setSize(const size_t size){
				::shinsei_ex_pystack_t_setSize(&obj,size);
				return;
			}
			
			// Assign the stack and all elements
			bool assign(const pystack_t& src){
				return ::shinsei_ex_pystack_t_assign(&obj,src.cObj());
			}
			bool assign(const ::shinsei_ex_pystack_t& src){
				return ::shinsei_ex_pystack_t_assign(&obj,&src);
			}
			pystack_t& operator=(const pystack_t& src){
				if(this==&src) return *this;
				::shinsei_ex_pystack_t_assign(&obj,src.cObj());
				return *this;
			}
			pystack_t& operator=(const ::shinsei_ex_pystack_t& src){
				::shinsei_ex_pystack_t_assign(&obj,&src);
				return *this;
			}
			
			// Move the ownership to another stack
			void move(pystack_t& src)noexcept{
				::shinsei_ex_pystack_t_move(&obj,src.cObj());
				return;
			}
			void move(::shinsei_ex_pystack_t& src)noexcept{
				::shinsei_ex_pystack_t_move(&obj,&src);
				return;
			}
			pystack_t& operator=(pystack_t&& src)noexcept{
				if(this==&src) return *this;
				::shinsei_ex_pystack_t_move(&obj,src.cObj());
				return *this;
			}
			pystack_t& operator=(::shinsei_ex_pystack_t&& src)noexcept{
				::shinsei_ex_pystack_t_move(&obj,&src);
				return *this;
			}
			
			// Attach the stack from another one
			void attach(const pystack_t& src){
				::shinsei_ex_pystack_t_attach(&obj,src.cObj());
				return;
			}
			void attach(const ::shinsei_ex_pystack_t& src){
				::shinsei_ex_pystack_t_attach(&obj,&src);
				return;
			}
			void attachValue(const int_fast32_t ctrl,const size_t size,const size_t cap,PyObject**const data){
				::shinsei_ex_pystack_t_attachValue(&obj,ctrl,size,cap,data);
				return;
			}

			// Free all elements
			void freeData(){
				::shinsei_ex_pystack_t_freeData(&obj);
				return;
			}

			// Static default constructor
			static bool as(pystack_t*const restrict ptr){
				return ::shinsei_ex_pystack_t_as(ptr->cObj());
			}
			static bool as(::shinsei_ex_pystack_t*const restrict ptr){
				return ::shinsei_ex_pystack_t_as(ptr);
			}
			explicit pystack_t(shinsei::in_place_t){
				if(!::shinsei_ex_pystack_t_as(&obj)) throw std::bad_alloc();
			}
			// Static copy constructor
			static bool asAssign(pystack_t*const restrict ptr,const pystack_t& src){
				return ::shinsei_ex_pystack_t_asAssign(ptr->cObj(),src.cObj());
			}
			static bool asAssign(pystack_t*const restrict ptr,const ::shinsei_ex_pystack_t& src){
				return ::shinsei_ex_pystack_t_asAssign(ptr->cObj(),&src);
			}
			static bool asAssign(::shinsei_ex_pystack_t*const restrict ptr,const pystack_t& src){
				return ::shinsei_ex_pystack_t_asAssign(ptr,src.cObj());
			}
			static bool asAssign(::shinsei_ex_pystack_t*const restrict ptr,const ::shinsei_ex_pystack_t& src){
				return ::shinsei_ex_pystack_t_asAssign(ptr,&src);
			}
			explicit pystack_t(shinsei::in_place_t,const pystack_t& src){
				return ::shinsei_ex_pystack_t_asAssign(&obj,src.cObj());
			}
			explicit pystack_t(shinsei::in_place_t,const ::shinsei_ex_pystack_t& src){
				return ::shinsei_ex_pystack_t_asAssign(&obj,&src);
			}
			// Static move constructor
			static void asMove(pystack_t*const restrict ptr,pystack_t& src){
				return ::shinsei_ex_pystack_t_asMove(ptr->cObj(),src.cObj());
			}
			static void asMove(pystack_t*const restrict ptr,::shinsei_ex_pystack_t& src){
				return ::shinsei_ex_pystack_t_asMove(ptr->cObj(),&src);
			}
			static void asMove(::shinsei_ex_pystack_t*const restrict ptr,pystack_t& src){
				return ::shinsei_ex_pystack_t_asMove(ptr,src.cObj());
			}
			static void asMove(::shinsei_ex_pystack_t*const restrict ptr,::shinsei_ex_pystack_t& src){
				return ::shinsei_ex_pystack_t_asMove(ptr,&src);
			}
			explicit pystack_t(shinsei::in_place_t,pystack_t& src){
				return ::shinsei_ex_pystack_t_asMove(&obj,src.cObj());
			}
			explicit pystack_t(shinsei::in_place_t,::shinsei_ex_pystack_t& src){
				return ::shinsei_ex_pystack_t_asMove(&obj,&src);
			}
			
			// Inline default constructor
			static bool inl(pystack_t*const restrict ptr,const size_t cap){
				return ::shinsei_ex_pystack_t_inl(ptr->cObj(),cap);
			}
			static bool inl(::shinsei_ex_pystack_t*const restrict ptr,const size_t cap){
				return ::shinsei_ex_pystack_t_inl(ptr,cap);
			}
			explicit pystack_t(shinsei::inlined_t,const size_t cap){
				return ::shinsei_ex-pystack_t_inl(&obj,cap);
			}
			// Inline copy constructor
			static bool inlAssign(pystack_t*const restrict ptr,const pystack_t& src){
				return ::shinsei_ex_pystack_t_inlAssign(ptr->cObj(),src.cObj());
			}
			static bool inlAssign(pystack_t*const restrict ptr,const ::shinsei_ex_pystack_t& src){
				return ::shinsei_ex_pystack_t_inlAssign(ptr->cObj(),&src);
			}
			static bool inlAssign(::shinsei_ex_pystack_t*const restrict ptr,const pystack_t& src){
				return ::shinsei_ex_pystack_t_inlAssign(ptr,src.cObj());
			}
			static bool inlAssign(::shinsei_ex_pystack_t*const restrict ptr,const ::shinsei_ex_pystack_t& src){
				return ::shinsei_ex_pystack_t_inlAssign(ptr,&src);
			}
			explicit pystack_t(shinsei::inlined_t,const pystack_t& src){
				return ::shinsei_ex_pystack_t_inlAssign(&obj,src.cObj());
			}
			explicit pystack_t(shinsei::inlined_t,const ::shinsei_ex_pystack_t& src){
				return ::shinsei_ex_pystack_t_inlAssign(&obj,&src);
			}
			// Inline move constructor
			static void inlMove(pystack_t*const restrict ptr,pystack_t& src){
				return ::shinsei_ex_pystack_t_inlMove(ptr->cObj(),src.cObj());
			}
			static void inlMove(pystack_t*const restrict ptr,::shinsei_ex_pystack_t& src){
				return ::shinsei_ex_pystack_t_inlMove(ptr->cObj(),&src);
			}
			static void inlMove(::shinsei_ex_pystack_t*const restrict ptr,pystack_t& src){
				return ::shinsei_ex_pystack_t_inlMove(ptr,src.cObj());
			}
			static void inlMove(::shinsei_ex_pystack_t*const restrict ptr,::shinsei_ex_pystack_t& src){
				return ::shinsei_ex_pystack_t_inlMove(ptr,&src);
			}
			explicit pystack_t(shinsei::inlined_t,pystack_t& src){
				return ::shinsei_ex_pystack_t_inlMove(&obj,src.cObj());
			}
			explicit pystack_t(shinsei::inlined_t,::shinsei_ex_pystack_t& src){
				return ::shinsei_ex_pystack_t_inlMove(&obj,&src);
			}
			
			// [Const] C Object
			::shinsei_ex_pystack_t* cObj(){
				return &obj;
			}
			const ::shinsei_ex_pystack_t* cObj()const{
				return &obj;
			}
			
			// Type casting
			operator ::shinsei_ex_pystack_t*(){
				return &obj;
			}
			operator const ::shinsei_ex_pystack_t*()const{
				return &obj;
			}
		}
	}
}
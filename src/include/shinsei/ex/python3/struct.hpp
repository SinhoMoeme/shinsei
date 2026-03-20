#include"shinsei/ex/python3/struct.h"
#include<new>

namespace shinsei{
	namespace ex{
		class pystack_t{
		private:
			::shinsei_ex_pystack_t obj;
		public:
			// Default constructor
			pystack_t(){
				if(!::shinsei_ex_pystack_t_as(this)) throw std::bad_alloc();
				return;
			}
			// Copy constructor
			pystack_t(pystack_t& src){
				if(!::shinsei_ex_pystack_t_asAssign(this,&src)) throw std::bad_alloc();
				return;
			}
			pystack_t(::shinsei_ex_pystack_t& src){
				if(!::shinsei_ex_pystack_t_asAssign(this,&src)) throw std::bad_alloc();
				return;
			}
			// Move constructor
			pystack_t(pystack_t&& src)noexcept{
				::shinsei_ex_pystack_t_asMove(this,&src));
				return;
			}
			pystack_t(::shinsei_ex_pystack_t&& src)noexcept{
				::shinsei_ex_pystack_t_asMove(this,&src));
				return;
			}
			
			// Destructor
			~pystack_t(){
				::shinsei_ex_pystack_t_freeData(this);
				return;
			}
			
			// Expand capacity by more_cap
			bool expand(const size_t more_cap){
				return ::shinsei_ex_pystack_t_expand(this,more_cap);
			}
			
			// Shrink capacity by less_cap
			bool shrink(const size_t less_cap){
				return ::shinsei_ex_pystack_t_shrink(this,less_cap);
			}
			
			// Reserve for the elements
			bool reserve(const size_t cap){
				return ::shinsei_ex_pystack_t_reserve(this,cap);
			}
			
			// Shrink capacity to fit
			bool shrinkToFit(){
				return ::shinsei_ex_pystack_t_shrinkToFit(this);
			}
			
			// [Const] Check if stack is empty
			bool empty()const{
				return ::shinsei_ex_pystack_t_empty(this);
			}
			
			// [Const] Get stack size
			bool size()const{
				return ::shinsei_ex_pystack_t_size(this);
			}
			
			// [Const] Get stack capacity
			bool capacity()const{
				return ::shinsei_ex_pystack_t_capacity(this);
			}
			
			// [Const] Get the top element
			PyObject* top()const{
				return ::shinsei_ex_pystack_t_top(this);
			}
			
			// [Const] Get the element at idx
			PyObject* at(const size_t idx)const{
				return ::shinsei_ex_pystack_t_at(this,idx);
			}
			
			// [Const] Get the element data
			PyObject** data()const{
				return ::shinsei_ex_pystack_t_data(this);
			}
			
			// Pop the top element
			void pop(){
				::shinsei_ex_pystack_t_pop(this);
				return;
				
			}
			
			// Push an element to the top
			void push(const PyObject*const restrict val){
				::shinsei_ex_pystack_t_push(this,val);
				return;
			}
			
			// Swap 2 stacks
			void swap(pystack_t& src){
				::shinsei_ex_pystack_t_swap(this,&src);
				return;
			}
			void swap(::shinsei_ex_pystack_t& src){
				::shinsei_ex_pystack_t_swap(this,&src);
				return;
			}
			
			// Clear all elements
			void clear(){
				::shinsei_ex_pystack_t_clear(this);
				return;
			}
			
			// Set stack size
			void setSize(const size_t size){
				::shinsei_ex_pystack_t_setSize(this,size);
				return;
			}
			
			// Assign the stack and all elements
			bool assign(pystack_t& src){
				return ::shinsei_ex_pystack_t_assign(this,&src);
			}
			bool assign(::shinsei_ex_pystack_t& src){
				return ::shinsei_ex_pystack_t_assign(this,&src);
			}
			pystack_t& operator=(::shinsei_ex_pystack_t& src){
				::shinsei_ex_pystack_t_assign(this,&src);
				return *this;
			}
			
			// Move the ownership to another stack
			void move(pystack_t& src)noexcept{
				::shinsei_ex_pystack_t_move(this,&src);
				return;
			}
			void move(::shinsei_ex_pystack_t& src)noexcept{
				::shinsei_ex_pystack_t_move(this,&src);
				return;
			}
			pystack_t& operator=(::shinsei_ex_pystack_t&& src)noexcept{
				::shinsei_ex_pystack_t_move(this,&src);
				return *this;
			}
			
			// Attach the stack from another one
			void attach(pystack_t& src){
				::shinsei_ex_pystack_t_attach(this,&src);
				return;
			}
			void attach(::shinsei_ex_pystack_t& src){
				::shinsei_ex_pystack_t_attach(this,&src);
				return;
			}
			void attachValue(const int_fast32_t ctrl,const size_t size,const size_t cap,PyObject** data){
				::shinsei_ex_pystack_t_attchValue(this,ctrl,size,cap,data);
				return;
			}

			// Free all elements
			void freeData(){
				::shinsei_ex_pystack_t_freeData(this);
				return;
			}

			// Static default constructor
			bool as(){
				return ::shinsei_ex_pystack_t_as(this);
			}
			// Static copy constructor
			bool asAssign(const shinsei_ex_pystack_t*const restrict src){
				return ::shinsei_ex_pystack_t_asAssign(this,src);
			}
			// Static move constructor
			void asMove(shinsei_ex_pystack_t* const restrict src){
				return ::shinsei_ex_pystack_t_asMove(this,src);
			}
			
			// [Const] C Object
			::shinsei_ex_pystack_t* cObj()const{
				return obj;
			}
		}
	}
}
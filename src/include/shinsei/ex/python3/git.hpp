#include"shinsei/ex/python3/gil.h"
#include<new>

namespace shinsei{
    namespace ex{
        class gil_guard_t {
        private:
            ::shinsei_ex_gil_guard_t obj;
        public:
            // Default constructor
            explicit gil_guard_t(const bool instant_alloc=true){
                ::shinsei_ex_gil_guard_t_as(&obj,instant_alloc);
            }
			
            // Destructor
            ~gil_guard_t(){
                if(isUsing()) free(); 
				return;
            }
            
            // [Const] Check if the GIL is using
            bool isUsing()const{
                return ::shinsei_ex_gil_guard_t_isUsing(&obj);
            }
            
            // Allocate the GIL
            void alloc(){
                ::shinsei_ex_gil_guard_t_alloc(&obj);
            }
            
            // Free the GIL
            void free(){
                ::shinsei_ex_gil_guard_t_free(&obj);
            }
            
            // Static default constructor
            static void as(gil_guard_t*const restrict ptr,const bool instant_alloc=true){
                ::shinsei_ex_gil_guard_t_as(ptr->cObj(),instant_alloc);
            }
            static void as(::shinsei_ex_gil_guard_t*const restrict ptr,const bool instant_alloc=true){
                ::shinsei_ex_gil_guard_t_as(ptr,instant_alloc);
            }
            
            // Inline default constructor
            static void inl(gil_guard_t*const restrict ptr,const bool instant_alloc=true){
                ::shinsei_ex_gil_guard_t_inl(ptr->cObj(),instant_alloc);
            }
            static void inl(::shinsei_ex_gil_guard_t*const restrict ptr,const bool instant_alloc=true){
                ::shinsei_ex_gil_guard_t_inl(ptr,instant_alloc);
            }
            
            // [Const] C Object
            ::shinsei_ex_gil_guard_t* cObj(){
				return &obj;
			}
            const ::shinsei_ex_gil_guard_t* cObj()const{
				return &obj;
			}
            
            // Type casting
            operator ::shinsei_ex_gil_guard_t*(){
				return &obj;
			}
            operator const ::shinsei_ex_gil_guard_t*()const{
				return &obj;
			}
            
            // Disable copy and move
            gil_guard_t(const gil_guard_t&)=delete;
            gil_guard_t& operator=(const gil_guard_t&)=delete;
            gil_guard_t(gil_guard_t&&)=delete;
            gil_guard_t& operator=(gil_guard_t&&)=delete;
        };
    }
}
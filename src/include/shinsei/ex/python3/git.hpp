#pragma once
#include"shinsei/ex/python3/gil.h"
#include<new>

namespace shinsei{
	namespace ex{
		class gil_guard_t{
		private:
			::shinsei_ex_gil_guard_t obj;
		public:
			// Default constructor
			explicit gil_guard_t(const bool instant_alloc=true)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_gil_guard_t_as(&obj,instant_alloc);
				return;
			}
			
			// Destructor
			~gil_guard_t()_SHINSEI_OS_NOEXCEPT{
				if(isUsing()) free();
				return;
			}
			
			// [Const] Check if the GIL is using
			bool isUsing()const _SHINSEI_OS_NOEXCEPT{
				return ::shinsei_ex_gil_guard_t_isUsing(&obj);
			}
			
			// Allocate the GIL
			void alloc()_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_gil_guard_t_alloc(&obj);
				return;
			}
			
			// Free the GIL
			void free()_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_gil_guard_t_free(&obj);
				return;
			}
			
			// Static in-place constructor helpers
			static void as(gil_guard_t*const restrict ptr,const bool instant_alloc=true)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_gil_guard_t_as(ptr->cObj(),instant_alloc);
				return;
			}
			static void as(::shinsei_ex_gil_guard_t*const restrict ptr,const bool instant_alloc=true)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_gil_guard_t_as(ptr,instant_alloc);
				return;
			}
			
			// In-place tag dispatcher
			explicit gil_guard_t(shinsei::in_place_t,const bool instant_alloc=true)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_gil_guard_t_as(&obj,instant_alloc);
				return;
			}
			
			// Static inline constructor helpers
			static void inl(gil_guard_t*const restrict ptr,const bool instant_alloc=true)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_gil_guard_t_inl(ptr->cObj(),instant_alloc);
				return;
			}
			static void inl(::shinsei_ex_gil_guard_t*const restrict ptr,const bool instant_alloc=true)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_gil_guard_t_inl(ptr,instant_alloc);
				return;
			}
			
			// Inlined tag dispatcher
			explicit gil_guard_t(shinsei::inlined_t,const bool instant_alloc=true)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_gil_guard_t_inl(&obj,instant_alloc);
				return;
			}
			
			// [const] Check if elements are inlined
			bool inlined()const _SHINSEI_OS_NOEXCEPT{
				return ::shinsei_ex_gil_guard_t_inlined(&obj);
			}
			
			// [Const] Get the ctrl code
			int_fast32_t getCtrl()const _SHINSEI_OS_NOEXCEPT{
				return ::shinsei_ex_gil_guard_t_getCtrl(&obj);
			}
			
			// Set the ctrl code
			void setCtrl(const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
				::shinsei_ex_gil_guard_t_setCtrl(&obj,ctrl);
				return;
			}
			
			// [Const] C Object
			::shinsei_ex_gil_guard_t* cObj()_SHINSEI_OS_NOEXCEPT{
				return &obj;
			}
			const ::shinsei_ex_gil_guard_t* cObj()const _SHINSEI_OS_NOEXCEPT{
				return &obj;
			}
			
			// Type casting
			operator ::shinsei_ex_gil_guard_t*()_SHINSEI_OS_NOEXCEPT{
				return &obj;
			}
			operator const ::shinsei_ex_gil_guard_t*()const _SHINSEI_OS_NOEXCEPT{
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
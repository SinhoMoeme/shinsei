#pragma once

#include"shinsei/.internal/os.h"

// Windows
#if defined(_SHINSEI_OS_WINDOWS)
	#ifdef _SHINSEI_BUILD_LIB
		#define _SHINSEI_LIB_API __declspec(dllexport)
	#elif defined(_SHINSEI_USE_SHARED)
		#define _SHINSEI_LIB_API __declspec(dllimport)
	#else
		#define _SHINSEI_LIB_API
	#endif

// Linux / Unix
#elif defined(_SHINSEI_OS_UNIX)
	#if defined(_SHINSEI_BUILD_LIB)||defined(_SHINSEI_USE_SHARED)
		#if defined(_SHINSEI_OS_GNUC_4)||defined(_SHINSEI_OS_CLANG)
			#define _SHINSEI_LIB_API __attribute__((visibility("default")))
		#else
			#define _SHINSEI_LIB_API
		#endif
	#else
		#define _SHINSEI_LIB_API
	#endif

// Unknown
#else
	#define _SHINSEI_LIB_API
#endif

// Object control code
#define _SHINSEI_CTRL_INLINED 1
#define _SHINSEI_CTRL_CODE_PAGE 2
#define _SHINSEI_CTRL_RUNNING 2

// Generic type definitions
#include<stddef.h>
typedef void* (*shinsei_allocate_callback_t)(const size_t)_SHINSEI_OS_NOEXCEPT;
typedef void* (*shinsei_allocate_copy_callback_t)(const void*)_SHINSEI_OS_NOEXCEPT;
typedef void (*shinsei_free_callback_t)(void*)_SHINSEI_OS_NOEXCEPT;
#ifdef _SHINSEI_OS_CPP
	namespace shinsei{
		using allocate_callback_t=::shinsei_allocate_callback_t;
		using allocate_copy_callback_t=::shinsei_allocate_copy_callback_t;
		using free_callback_t=::shinsei_free_callback_t;
	}
#endif
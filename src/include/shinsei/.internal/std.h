#pragma once

// Windows
#if defined(_SHINSEI_OS_WINDOWS)
	#if !defined(WIN32_LEAN_AND_MEAN)
		#define WIN32_LEAN_AND_MEAN
	#endif
	#include<Windows.h>
	typedef wchar_t shinsei_nchar_t;

// Unistd
#elif defined(_SHINSEI_OS_UNISTD)
    #include<unistd.h>
	typedef char8_t shinsei_nchar_t;

// Unknown
#else
    #error "Unsupported platform for shinsei OS abstraction!"
#endif

// Apple (macOS, iOS, etc.)
#if defined(_SHINSEI_OS_MACOS)
    #include<TargetConditionals.h>
#endif

// C++
#if defined(_SHINSEI_OS_CPP)
	namespace shinsei{
		typedef ::shinsei_nchar_t nchar_t;
	}
#endif
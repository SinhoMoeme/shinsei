#pragma once

#include"shinsei/.internal/os.h"

// Windows
#if defined(_SHINSEI_OS_WINDOWS)
	#include<Windows.h>
	#include<shlobj.h>

// Unistd
#elif defined(_SHINSEI_OS_UNISTD)
    #include<unistd.h>

// Unknown
#else
    #error "Unsupported platform for shinsei OS abstraction!"
#endif

// Apple (macOS, iOS, etc.)
#if defined(_SHINSEI_OS_MACOS)
    #include<TargetConditionals.h>
#endif
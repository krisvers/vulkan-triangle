#ifndef KRISVERS_PLATFORM_H
#define KRISVERS_PLATFORM_H

#if defined(_WIN64) || defined(_WIN32) || defined(WIN32) || defined(__WIN32__)
	#define WINDOWS 1
#elif defined(__linux__) || defined(__gnu_linux__)
	#define LINUX 1
#elif defined(__unix__)
	#define UNIX 1
#elif __APPLE__
	#define APPLE 1
	#include <TargetConditionals.h>
	#ifdef TARGET_OS_MAC
		#define MACOS 1
	#else
		#error "Unsupported Apple target"
	#endif
#else
	#error "Unsupported platform"
#endif

#if defined(_MSC_VER)
	#define MSVC 1
#endif

#endif


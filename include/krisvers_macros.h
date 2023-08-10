#ifndef KRISVERS_MACROS_H
#define KRISVERS_MACROS_H

#include <krisvers_types.h>
#include <krisvers_platform.h>
#include <platerror.h>

#ifdef FLAG_DEBUGBREAK
	#ifdef MSVC
		#include <intrin.h>
		#define DEBUGBREAK() __debugbreak()
	#else
		#define DEBUGBREAK() __builtin_trap()
	#endif
#else
	#define DEBUGBREAK()
#endif

#ifdef FLAG_ABORT_ON_ASSERTION_FAILURE
	#define ASSERTION_FAILURE() abort()
#else
	#define ASSERTION_FAILURE()
#endif

#ifdef FLAG_ASSERTIONS
	#define ASSERT(cond)								\
	{													\
		if (cond) {} else {								\
			error_message("Error ("__FILE__":%llu)\n"	\
				"%s\n", (u64) __LINE__, #cond);			\
			DEBUGBREAK();								\
			ASSERTION_FAILURE();						\
		}												\
	}
#else
	#define ASSERT(cond)
#endif

#endif
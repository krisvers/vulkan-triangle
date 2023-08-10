#ifndef KRISVERS_PLATPLATFORM_H
#define KRISVERS_PLATPLATFORM_H

#include <krisvers_types.h>

typedef enum PlatReturnEnum {
	PLATRETURN_GENERIC_ERROR = -1,
	PLATRETURN_SUCCESS = 0,
	PLATRETURN_SHOULD_CLOSE = 1,
} platreturn_enum;

#endif
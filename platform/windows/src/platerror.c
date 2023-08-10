#include <windows.h>
#include <stdarg.h>
#include <stdio.h>
#include <krisvers_types.h>
#include <malloc.h>

void error_message(char * fmt, ...) {
	va_list list;
	va_start(list, fmt);

	u64 length = strlen(fmt) * 1.5f + 512;
	char * buffer = _malloca(length);
	if (buffer == NULL) {
		return;
	}
	vsnprintf(buffer, length, fmt, list);
	va_end(list);

	MessageBoxA(NULL, buffer, "Error", MB_OK | MB_ICONERROR);
}
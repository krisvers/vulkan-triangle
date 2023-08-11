#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <krisvers_types.h>
#include <alloca.h>

void error_message(char * fmt, ...) {
	va_list list;
	va_start(list, fmt);

	u64 length = strlen(fmt) * 1.5f + 512;
	char * buffer = alloca(length);
	if (buffer == NULL) {
		return;
	}
	vsnprintf(buffer, length, fmt, list);
	va_end(list);

	fprintf(stderr, "Error:\n%s\n", buffer);
}

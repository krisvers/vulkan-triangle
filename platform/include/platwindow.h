#ifndef KRISVERS_PLATWINDOW_H
#define KRISVERS_PLATWINDOW_H

#include <krisvers_types.h>
#include <platplatform.h>

typedef struct PlatWindow {
	internal_t _internal;
	u32 width;
	u32 height;
	b8 close;
} platwindow_t;

int platwindow_create(platwindow_t * window, u32 width, u32 height, char * title, b8 fullscreen);
int platwindow_update(platwindow_t * window);
int platwindow_destroy(platwindow_t * window);

#endif
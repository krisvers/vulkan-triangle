#include <platwindow.h>
#include <GLFW/glfw3.h>
#include <krisvers_macros.h>

int platwindow_create(platwindow_t * window, u32 width, u32 height, char * title) {
	ASSERT(window != NULL);
	window->_internal = glfwCreateWindow(width, height, title, NULL, NULL);
	ASSERT(window->_internal != NULL);
	window->width = width;
	window->height = height;

	return PLATRETURN_SUCCESS;
}

int platwindow_destroy(platwindow_t * window) {
	ASSERT(window != NULL);
	ASSERT(window->_internal != NULL);
	glfwDestroyWindow(window->_internal);

	return PLATRETURN_SUCCESS;
}
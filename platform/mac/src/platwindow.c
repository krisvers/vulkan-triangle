#include <platwindow.h>
#include <GLFW/glfw3.h>
#include <krisvers_macros.h>

int platwindow_create(platwindow_t * window, u32 width, u32 height, char * title, b8 fullscreen) {
	ASSERT(window != NULL);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	GLFWmonitor * monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode * mode = glfwGetVideoMode(monitor);
	if (width == 0) {
		width = mode->width;
	}
	if (height == 0) {
		height = mode->height;
	}
	window->_internal = glfwCreateWindow(width, height, title, (fullscreen == 1) ? glfwGetPrimaryMonitor() : NULL, NULL);
	if (fullscreen == 2) {
		glfwSetWindowMonitor(window->_internal, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
	}
	window->width = width;
	window->height = height;
	window->close = 0;

	return PLATRETURN_SUCCESS;
}

int platwindow_update(platwindow_t * window) {
	ASSERT(window != NULL);
	ASSERT(window->_internal != NULL);
	glfwSwapBuffers(window->_internal);

	if (glfwWindowShouldClose(window->_internal)) {
		window->close = 1;
		return PLATRETURN_SHOULD_CLOSE;
	}

	return PLATRETURN_SUCCESS;
}

int platwindow_destroy(platwindow_t * window) {
	ASSERT(window != NULL);
	ASSERT(window->_internal != NULL);
	glfwDestroyWindow(window->_internal);

	return PLATRETURN_SUCCESS;
}


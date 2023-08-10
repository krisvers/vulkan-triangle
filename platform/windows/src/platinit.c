#include <platinit.h>
#include <krisvers_macros.h>
#include <GLFW/glfw3.h>

int platinit_init(void) {
	int err = glfwInit();
	ASSERT(err != 0);

	return PLATRETURN_SUCCESS;
}

int platinit_deinit(void) {
	glfwTerminate();

	return PLATRETURN_SUCCESS;
}
#include <stdio.h>
#include <krisvers_types.h>
#include <platerror.h>
#include <platinit.h>
#include <platwindow.h>

int main(void) {
	printf("Hello, World\n");
	platinit_init();

	platwindow_t window;
	platwindow_create(&window, 800, 600, "hello", 0);

	while (!window.close) {
		platinit_update();
		platwindow_update(&window);
	}
	error_message("googus gaggus %lf\n", 3.14);

	platwindow_destroy(&window);

	platinit_deinit();
	printf("Goodbye, World\n");

	return 0;
}
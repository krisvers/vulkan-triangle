#include <stdio.h>
#include <krisvers_types.h>
#include <platinit.h>
#include <platwindow.h>

int main(void) {
	printf("Hello, World\n");
	platinit_init();

	platwindow_t window;
	platwindow_create(&window, 800, 600, "hello");

	while (1);

	platwindow_destroy(&window);

	platinit_deinit();
	printf("Goodbye, World\n");

	return 0;
}
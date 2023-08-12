CC = i686-w64-mingw32-gcc
CFLAGS = -std=c99
CWARNINGS = -Wall -Wextra -Wpedantic
CLIBS = -Llib/mingw -lglfw3 -lmingw32 -lgdi32 -luser32 -lkernel32
CDEFINES = -DGLFW_INCLUDE_NONE
CDEBUGDEFINES = -DGLFW_INCLUDE_NONE -DFLAG_DEBUGBREAK -DFLAG_ASSERTIONS -DFLAG_ABORT_ON_ASSERTION_FAILURE
CINCLUDES = -Iinclude -Iplatform/include -Iplatform/linux/include -Ilib/include -Ilib/linux/include
CSRCS = ./src ./platform/windows/src
CFILES = $(shell find $(CSRCS) -type f -name "*.c")
CBINARY = ./working/mingw

mingw:
	$(CC) $(CFLAGS) $(CINCLUDES) $(CDEFINES) $(CFILES) $(CLIBS) -o $(CBINARY)

mingw-debug:
	$(CC) $(CFLAGS) $(CINCLUDES) $(CDEBUGDEFINES) $(CFILES) $(CLIBS) -o $(CBINARY)-debug

mingw-run:
	cd ./working && ./mingw.exe

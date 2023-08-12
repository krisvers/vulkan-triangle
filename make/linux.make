CC = clang
CFLAGS = -std=c99
CWARNINGS = -Wall -Wextra -Wpedantic
CLIBS = -Llib/linux -lglfw
CDEFINES = -DGLFW_INCLUDE_NONE
CDEBUGDEFINES = -DGLFW_INCLUDE_NONE -DFLAG_DEBUGBREAK -DFLAG_ASSERTIONS -DFLAG_ABORT_ON_ASSERTION_FAILURE
CINCLUDES = -Iinclude -Iplatform/include -Iplatform/linux/include -Ilib/include -Ilib/linux/include
CSRCS = ./src ./platform/linux/src
CFILES = $(shell find $(CSRCS) -type f -name "*.c")
CBINARY = ./working/linux

linux:
	$(CC) $(CFLAGS) $(CLIBS) $(CINCLUDES) $(CDEFINES) $(CFILES) -o $(CBINARY)

linux-debug:
	$(CC) $(CFLAGS) $(CLIBS) $(CINCLUDES) $(CDEBUGDEFINES) $(CFILES) -o $(CBINARY)-debug

linux-run:
	cd ./working && ./linux

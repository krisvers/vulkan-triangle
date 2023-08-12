CC = clang
CFLAGS = -std=c99
CWARNINGS = -Wall -Wextra -Wpedantic
CLIBS = -Llib/mac -lglfw3 -framework Cocoa -framework IOKit
CDEFINES =
CDEBUGDEFINES = -DFLAG_DEBUGBREAK -DFLAG_ASSERTIONS -DFLAG_ABORT_ON_ASSERTION_FAILURE
CINCLUDES = -Iinclude -Iplatform/include -Iplatform/mac/include -Ilib/include -Ilib/mac/include
CSRCS = ./src ./platform/mac/src
CFILES = $(shell find $(CSRCS) -type f -name "*.c")
CBINARY = ./mac

linux:
	$(CC) $(CFLAGS) $(CLIBS) $(CINCLUDES) $(CDEFINES) $(CFILES) -o $(CBINARY)

linux-debug:
	$(CC) $(CFLAGS) $(CLIBS) $(CINCLUDES) $(CDEBUGDEFINES) $(CFILES) -o $(CBINARY)-debug
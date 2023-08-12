CC = clang
CFLAGS = -std=c99 -shared -fPIC
CWARNINGS = -Wall -Wextra -Wpedantic
CLIBS = -Llib/mac -lglfw3 -framework Cocoa -framework IOKit
CDEFINES = -DGLFW_INCLUDE_NONE
CDEBUGDEFINES = -DGLFW_INCLUDE_NONE -DFLAG_DEBUGBREAK -DFLAG_ASSERTIONS -DFLAG_ABORT_ON_ASSERTION_FAILURE
CINCLUDES = -Iinclude -Iplatform/include -Iplatform/mac/include -Ilib/include -Ilib/mac/include
CSRCS = ./src ./platform/mac/src
CFILES = $(shell find $(CSRCS) -type f -name "*.c")
CBINARY = ./working/mac

mac:
	$(CC) $(CFLAGS) $(CLIBS) $(CINCLUDES) $(CDEFINES) $(CFILES) -o $(CBINARY)

mac-debug:
	$(CC) $(CFLAGS) $(CLIBS) $(CINCLUDES) $(CDEBUGDEFINES) $(CFILES) -o $(CBINARY)-debug

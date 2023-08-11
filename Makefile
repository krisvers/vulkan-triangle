PLATFORM = linux

CC = clang
CFLAGS = -std=c99
CWARNINGS = -Wall -Wextra -Wpedantic
CLIBS = -Llib/$(PLATFORM) -lglfw
CDEFINES =
CDEBUGDEFINES = -DFLAG_DEBUGBREAK -DFLAG_ASSERTIONS -DFLAG_ABORT_ON_ASSERTION_FAILURE
CINCLUDES = -Iinclude -Iplatform/include -Iplatform/$(PLATFORM)/include -Ilib/include -Ilib/$(PLATFORM)/include
CSRCS = ./src ./platform/$(PLATFORM)/src
CFILES = $(shell find $(CSRCS) -type f -name "*.c")
CBINARY = ./program

all: $(PLATFORM)
debug: $(PLATFORM)-debug

linux:
	$(CC) $(CFLAGS) $(CLIBS) $(CINCLUDES) $(CDEFINES) $(CFILES) -o $(CBINARY)

linux-debug:
	$(CC) $(CFLAGS) $(CLIBS) $(CINCLUDES) $(CDEBUGDEFINES) $(CFILES) -o $(CBINARY)

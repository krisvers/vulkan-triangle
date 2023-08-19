PLATFORM = linux
MAKEDEFINESDIR = make

.PHONY: $(PLATFORM) $(PLATFORM)-debug $(PLATFORM)-run all debug run

include $(MAKEDEFINESDIR)/$(PLATFORM).make

all: $(PLATFORM)
debug: $(PLATFORM)-debug
run: $(PLATFORM)-run

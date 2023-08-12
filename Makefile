PLATFORM = mac
MAKEDEFINESDIR = make

include $(MAKEDEFINESDIR)/$(PLATFORM).make

all: $(PLATFORM)
debug: $(PLATFORM)-debug
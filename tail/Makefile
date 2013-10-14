sources := $(wildcard *.cpp)
objects := $(subst .cpp,.o,$(sources))
dependencies := $(subst .cpp,.d,$(sources))
programs := tail

CPPFLAGS += -I../
LDFLAGS += -L../utils/
LDLIBS += -lutils

.PHONY: all
all: $(programs)

tail: main.o getopt.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

.PHONY: clean
clean:
	rm -f *.d *.o *.a
	rm -f $(programs)

ifneq "$(MAKECMDGOALS)" "clean"
  -include $(dependencies)
endif

include ../common.mk
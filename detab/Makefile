sources := $(wildcard *.cpp)
objects := $(subst .cpp,.o,$(sources))
dependencies := $(subst .cpp,.d,$(sources))
programs := detab

.PHONY: all
all: $(programs)

detab: main.o getopt.o detab.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

.PHONY: clean
clean:
	rm -f *.d *.o *.a
	rm -f $(programs)

ifneq "$(MAKECMDGOALS)" "clean"
  -include $(dependencies)
endif

include ../common.mk
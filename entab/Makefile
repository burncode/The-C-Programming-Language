sources := $(wildcard *.cpp)
objects := $(subst .cpp,.o,$(sources))
dependencies := $(subst .cpp,.d,$(sources))
programs := entab

.PHONY: all
all: $(programs)

entab: main.o getopt.o entab.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

.PHONY: clean
clean:
	rm -f *.d *.o *.a
	rm -f $(programs)

ifneq "$(MAKECMDGOALS)" "clean"
  -include $(dependencies)
endif

include ../common.mk
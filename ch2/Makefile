sources := $(wildcard *.cpp)
objects := $(subst .cpp,.o,$(sources))
dependencies := $(subst .cpp,.d,$(sources))
programs := print-limit print-line htoi squeeze any setbits invert \
	rightrot bit-count lower

CPPFLAGS += -I../
LDFLAGS += -L../utils/
LDLIBS += -lutils

.PHONY: all
all: $(programs)

print-limit: 2-1.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

print-line: 2-2.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

htoi: 2-3.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

squeeze: 2-4.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

any: 2-5.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

setbits: 2-6.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

invert: 2-7.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

rightrot: 2-8.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

bit-count: 2-9.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

lower: 2-10.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

.PHONY: clean
clean:
	rm -f *.d *.o *.a
	rm -f $(programs)

ifneq "$(MAKECMDGOALS)" "clean"
  -include $(dependencies)
endif

include ../common.mk
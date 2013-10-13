sources := $(wildcard *.cpp)
objects := $(subst .cpp,.o,$(sources))
dependencies := $(subst .cpp,.d,$(sources))
libraries := libutils.a

.PHONY: all
all: $(libraries)

libutils.a: $(objects)
	$(AR) $(ARFLAGS) $@ $?

.PHONY: clean
clean:
	rm -f *.d *.o *.a
	rm -f $(libraries)

ifneq "$(MAKECMDGOALS)" "clean"
  -include $(dependencies)
endif

include ../common.mk
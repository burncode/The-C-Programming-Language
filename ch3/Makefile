sources := $(wildcard *.cpp)
objects := $(subst .cpp,.o,$(sources))
dependencies := $(subst .cpp,.d,$(sources))
programs := binary-search escape-unescape expand itoa itob format-itoa

CPPFLAGS += -I../
LDFLAGS += -L../utils/
LDLIBS += -lutils

.PHONY: all
all: $(programs)

binary-search: 3-1.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

escape-unescape: 3-2.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

expand: 3-3.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

itoa: 3-4.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

itob: 3-5.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

format-itoa: 3-6.o
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

.PHONY: clean
clean:
	rm -f *.d *.o *.a
	rm -f $(programs)

ifneq "$(MAKECMDGOALS)" "clean"
  -include $(dependencies)
endif

# $(call make-depend,source-file,object-file,depend-file)
define make-depend
  $(CXX) -MM 		\
         -MF $3		\
         -MP            \
         -MT $2		\
         $(CFLAGS)      \
         $(CPPFLAGS)	\
         $(TARGET_ARCH) \
         $1
endef

%.o: %.cpp
	$(call make-depend,$<,$@,$(subst .o,.d,$@))
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<
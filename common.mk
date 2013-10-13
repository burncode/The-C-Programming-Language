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
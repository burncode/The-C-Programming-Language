projects := ch1 ch2 ch3 ch4 calculator
libraries := utils

.PHONY: all $(projects) $(libraries)
all: $(projects)

$(projects) $(libraries):
	$(MAKE) --directory=$@

$(projects): $(libraries)

.PHONY: clean
clean:
	for d in $(projects) $(libraries); \
	do                                 \
	  $(MAKE) --directory=$$d clean;   \
	done

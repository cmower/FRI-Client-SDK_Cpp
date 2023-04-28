
all: lib examples

clean: clean_lib clean_examples

lib:
	@if [ -n "$(SOURCE_DIRS)" ] ; then  \
  	echo " "; \
	for i in $(SOURCE_DIRS); do  \
		$(MAKE) -C $$i all; \
	done; \
	fi;
	$(MKDIR) $(LIB_DIR)
	$(AR) cr $(LIB_DIR)/$(TARGETLIB) $(SOURCE_DIRS_OBJS)

clean_lib:
	@if [ -n "$(SOURCE_DIRS)" ] ; then  \
  	echo " "; \
	for i in $(SOURCE_DIRS); do  \
		$(MAKE) -C $$i clean; \
	done; \
	fi;
	$(RM) $(LIB_DIR)/$(TARGETLIB)

examples: lib
	@if [ -n "$(EXAMPLE_DIRS)" ] ; then  \
  	echo " "; \
	for i in $(EXAMPLE_DIRS); do  \
		$(MAKE) -C $$i all install; \
	done; \
	fi;

clean_examples:
	@if [ -n "$(EXAMPLE_DIRS)" ] ; then  \
  	echo " "; \
	for i in $(EXAMPLE_DIRS); do  \
		$(MAKE) -C $$i clean uninstall; \
	done; \
	fi;

doxygen:
	cd $(DOC_DIR); doxygen Doxyfile;

.PHONY: all lib examples clean clean_lib clean_examples doxygen
#SUBDIRS := $(wildcard */.)
SUBDIRS := ./progII

$(SUBDIRS):
	$(MAKE) -C $@ -s

.PHONY: $(SUBDIRS)

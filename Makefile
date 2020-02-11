#SUBDIRS := $(wildcard */.)
SUBDIRS := ./P0

$(SUBDIRS):
	$(MAKE) -C $@

.PHONY: $(SUBDIRS)

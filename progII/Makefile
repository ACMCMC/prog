SUBDIRS := $(wildcard */.)

all: $(SUBDIRS)

$(SUBDIRS):
	@echo Se va a compilar $@
	$(MAKE) -C $@

.PHONY: $(SUBDIRS)

SUBDIRS := $(wildcard */.)

all: $(SUBDIRS)

$(SUBDIRS):
	@echo Se va a compilar $@
	$(MAKE) -C $@
	@echo Compilado.

.PHONY: $(SUBDIRS)

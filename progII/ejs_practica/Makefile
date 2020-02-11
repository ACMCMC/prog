SUBDIRS := $(wildcard */.)

$(SUBDIRS):
#No hay problema si el make de los ejercicios de practica falla
	-$(MAKE) -C $@

.PHONY: $(SUBDIRS)

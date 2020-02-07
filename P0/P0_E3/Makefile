OUTPUT = made.exe

ARCHS = main.c factorial.c potencia.c

OBJS = $(ARCHS:.c=.o)

$(OUTPUT): $(OBJS)
	gcc -o $(OUTPUT) $(OBJS)

build_and_clean:
	$(MAKE) $(OUTPUT)
	$(MAKE) clean

%.o: %.c
	gcc -c $< -o $@

rebuild:
	-$(MAKE) cleanall
	$(MAKE) $(OUTPUT)

clean:
	-rm $(OBJS)

cleanall: clean
	rm $(OUTPUT)
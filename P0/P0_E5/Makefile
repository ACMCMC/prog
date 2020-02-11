OUTPUT = res

ARCHS = programa.c

OBJS = $(ARCHS:.c=.o)

$(OUTPUT): $(OBJS)
	gcc -o $(OUTPUT) $(OBJS)

%.o: %.c
	gcc -o $@ -c $<

clean:
	-rm $(OBJS)

cleanall: clean
	-rm $(OUTPUT)
OUTPUT = out

HEADERS_DIR = ./TAD/

LIBS_NAMES = cola.h listas.h pila.h

LIBS = $(addprefix $(HEADERS_DIR),$(LIBS_NAMES))

C_FILES = main.c $(LIBS:.h=.c)

OBJS = $(C_FILES:.c=.o)

$(OUTPUT): $(OBJS)
	gcc -o $(OUTPUT) $(OBJS)

%.o: %.c
	gcc -o $@ -c $< -I $(HEADERS_DIR)

clean:
	-rm $(OBJS)

cleanall:
	-rm $(OBJS) $(OUTPUT)
OUTPUT = out

C_FILES = asignarElemento.c crearMatriz.c destruirMatriz.c imprimirMatriz.c main.c obtenerElemento.c producto.c suma.c

OBJS = $(C_FILES:.c=.o)

HEADERS = .

$(OUTPUT): $(OBJS)
	gcc -o $(OUTPUT) $(OBJS) -I $(HEADERS)

%.o: %.c
	gcc -o $@ -c $< -I $(HEADERS)

clean:
	-rm $(OBJS)

cleanall:
	-rm $(OBJS) $(OUTPUT)
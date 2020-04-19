OUTPUT = out

C_FILES = main.c matrizdinamica.c

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
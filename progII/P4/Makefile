OUTPUT = out

#ARGS = -O0
ARGS = -lm

C_FILES = main.c matrizdinamica.c

OBJS = $(C_FILES:.c=.o)

HEADERS = .

$(OUTPUT): $(OBJS)
	gcc -o $(OUTPUT) $(OBJS) -I $(HEADERS) $(ARGS)

%.o: %.c
	gcc -o $@ -c $< -I $(HEADERS) $(ARGS)

clean:
	-rm $(OBJS)

cleanall:
	-rm $(OBJS) $(OUTPUT)
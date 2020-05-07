OUTPUT = out

#ARGS = -O0
ARGS = 

C_FILES = main.c matrizdinamica.c

OBJS = $(C_FILES:.c=.o)

HEADERS = .

$(OUTPUT): $(OBJS)
	gcc $(ARGS) -o $(OUTPUT) $(OBJS) -I $(HEADERS)

%.o: %.c
	gcc $(ARGS) -o $@ -c $< -I $(HEADERS)

clean:
	-rm $(OBJS)

cleanall:
	-rm $(OBJS) $(OUTPUT)
CC=gcc
CFLAGS=-Wall -g  # Enable warnings + debug info

OBJ=main.o ./stack/lib/node_stack.o ./tree/binary_tree.o

main: $(OBJ)
	$(CC) $(OBJ) -o main

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main

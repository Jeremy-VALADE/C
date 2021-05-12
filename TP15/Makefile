CC=gcc
CFLAGS=-Wall -ansi -pedantic -lreadline -lm
OBJ=main.o stack.o operation.o

calc : $(OBJ)
	$(CC) -o calc $(OBJ) $(CFLAGS)

stack.o: stack.c stack.h
	$(CC) -c stack.c -o stack.o $(CFLAGS)

operation.o: operation.c operation.h stack.h
	$(CC) -c operation.c -o operation.o $(CFLAGS)

main.o : main.c
	$(CC) -c main.c $(CFLAGS)

clean:
	rm *.o
	rm calc

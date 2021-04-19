# Makefile TP 7

CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJ=main.o interface.o operation.o dame.o
LDFLAGS=-lMLV

dame: $(OBJ)
	$(CC) -o dame $(OBJ) $(LDFLAGS)

interface.o: interface.c interface.h 
	$(CC) -c interface.c -o interface.o $(CFLAGS)

dame.o: dame.c dame.h operation.o operation.h 
	$(CC) -c dame.c -o dame.o $(CFLAGS)

operation.o: operation.c operation.h 
	$(CC) -c operation.c -o operation.o $(CFLAGS)

main.o: main.c interface.h operation.o
	$(CC) -c main.c -o main.o $(CFLAGS)

clean:
	rm -f *.o
	rm -f dame

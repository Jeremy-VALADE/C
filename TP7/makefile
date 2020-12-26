# Makefile TP 7

CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJ=interface.o main.o operation.o
LDFLAGS=-lMLV

calc: $(OBJ)
	$(CC) -o calc $(OBJ) $(LDFLAGS)

interface.o: interface.c interface.h objet.h
	$(CC) -c interface.c -o interface.o $(CFLAGS) -lMLV

operation.o: operation.h operation.c objet.h interface.h
	$(CC) -c operation.c -o operation.o $(CFLAGS) -lm

main.o: main.c objet.h interface.h operation.h
	$(CC) -c main.c -o main.o $(CFLAGS)

clean:
	rm -f *.o
	rm -f calc


# Makefile TP 7

CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJ=interface.o main.o objet.o
LDFLAGS=-lMLV

taquin: $(OBJ)
	$(CC) -o taquin $(OBJ) $(LDFLAGS)

interface.o: interface.c interface.h objet.h
	$(CC) -c interface.c -o interface.o $(CFLAGS)

objet.o: objet.c objet.h 
	$(CC) -c objet.c -o objet.o $(CFLAGS)

main.o: main.c objet.h interface.h
	$(CC) -c main.c -o main.o $(CFLAGS)

clean:
	rm -f *.o
	rm -f taquin

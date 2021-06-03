# Makefile TP 7

CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJ=main.o objet.o
LDFLAGS=

taquin: $(OBJ)
	$(CC) -o exe $(OBJ) $(LDFLAGS)

objet.o: objet.c objet.h 
	$(CC) -c objet.c -o objet.o $(CFLAGS)

main.o: main.c objet.h 
	$(CC) -c main.c -o main.o $(CFLAGS)

clean:
	rm -f *.o
	rm -f exe

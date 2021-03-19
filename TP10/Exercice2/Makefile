CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJ=personne.o main.o


exe: main.o personne.o
	$(CC) -o exe $(OBJ) $(CFLAGS)
main.o : main.c
	$(CC) -c main.c -o main.o $(CFLAGS)
personne.o : personne.h personne.c
	$(CC) -c personne.c -o personne.o $(CFLAGS)

clean:
	rm *.o
	rm exe?

CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJ=personne.o main.o


exe: main.o personne.o
	$(CC) -o exe $(OBJ) $(CFLAGS)
main.o : Sources/main.c
	$(CC) -c Sources/main.c -o main.o $(CFLAGS)
personne.o : Headers/personne.h Sources/personne.c
	$(CC) -c Sources/personne.c -o personne.o $(CFLAGS)

clean:
	rm *.o exe

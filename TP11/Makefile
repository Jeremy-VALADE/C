CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJ=interface.o main.o objet.o
LDFLAGS=-lMLV
sources=Sources/
headers=Headers/

taquin: $(OBJ)
	$(CC) -o taquin $(OBJ) $(LDFLAGS)

interface.o: $(sources)interface.c $(headers)interface.h $(headers)objet.h
	$(CC) -c $(sources)interface.c -o interface.o $(CFLAGS)

objet.o: $(sources)objet.c $(headers)objet.h 
	$(CC) -c $(sources)objet.c -o objet.o $(CFLAGS)

main.o: $(sources)main.c $(headers)objet.h $(headers)interface.h
	$(CC) -c $(sources)main.c -o main.o $(CFLAGS)

clean:
	rm -f *.o
	rm -f taquin

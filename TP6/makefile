CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJ=main.o fonctions.o 

exe : $(OBJ)
	$(CC) -o exe $(OBJ) $(CFLAGS)

main.o : main.c fonctions.h
	$(CC) -c main.c $(CFLAGS)

clean:
	rm *.o
	rm exe	

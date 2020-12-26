CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJ=main.o tableau.o 

exe : $(OBJ)
	$(CC) -o exe $(OBJ) $(CFLAGS)

main.o : main.c tableau.h
	$(CC) -c main.c $(CFLAGS)

clean:
	rm *.o
	rm exe	

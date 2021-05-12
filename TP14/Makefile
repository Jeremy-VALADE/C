CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJ=main.o

larger_file : $(OBJ)
	$(CC) -o larger_file $(OBJ) $(CFLAGS)

main.o : main.c
	$(CC) -c main.c $(CFLAGS)

clean:
	rm *.o
	rm larger_file

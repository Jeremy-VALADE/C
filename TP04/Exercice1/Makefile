CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJ=main.o stack.h

exe : $(OBJ)
	$(CC) -o exe $(OBJ) $(CFLAGS)

main.o : main.c stack.h
	$(CC) -c main.c $(CFLAGS)

clean:
	rm *.o
	rm exe

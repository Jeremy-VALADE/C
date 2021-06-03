CC=gcc
CFLAGS=-Wall -ansi
OBJ=main.o

exe : $(OBJ)
	$(CC) -o exe $(OBJ) $(CFLAGS)

main.o : main.c
	$(CC) -c main.c $(CFLAGS)

clean:
	rm *.o
	rm exe

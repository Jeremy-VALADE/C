CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJ=main.o interface.o operation.o dame.o
LDFLAGS=-lMLV
sources=Sources/
headers=Headers/

dame: $(OBJ)
	$(CC) -o dame $(OBJ) $(LDFLAGS)

interface.o: $(sources)interface.c $(headers)interface.h 
	$(CC) -c $(sources)interface.c -o interface.o $(CFLAGS)

dame.o: $(sources)dame.c $(headers)dame.h operation.o $(headers)operation.h 
	$(CC) -c $(sources)dame.c -o dame.o $(CFLAGS)

operation.o: $(sources)operation.c $(headers)operation.h 
	$(CC) -c $(sources)operation.c -o operation.o $(CFLAGS)

main.o: $(sources)main.c $(headers)interface.h operation.o
	$(CC) -c $(sources)main.c -o main.o $(CFLAGS)

clean:
	rm -f *.o
	rm -f dame

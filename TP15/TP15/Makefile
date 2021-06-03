CC=gcc
CFLAGS= -lreadline -lm -ldl -Wall -ansi
OBJ=main.o stack.o fonctions.o fonctionnalites.o
sources=Sources/
headers=Headers/
library=Plugin/

all: calc plugin 
	
calc : $(OBJ)
	$(CC) -o calc $(OBJ) $(CFLAGS)

stack.o: $(headers)stack.h
	$(CC) -c $(sources)stack.c -o stack.o $(CFLAGS)

fonctions.o: $(headers)fonctions.h
	$(CC) -c $(sources)fonctions.c -o fonctions.o $(CFLAGS)

fonctionnalites.o: $(headers)fonctionnalites.h
	$(CC) -c $(sources)fonctionnalites.c -o fonctionnalites.o $(CFLAGS)

main.o : $(sources)main.c
	$(CC) -c $(sources)main.c $(CFLAGS)

plugin:	
	./Plugin/cToSo.sh $(library)

clean:
	rm -f $(library)o/* $(library)so/* 
	rm -f *.o
	rm -f calc

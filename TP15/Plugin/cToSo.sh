# Méthode pour transfomer un fichier .c en fichier .so

gcc -fPIC -c $1.c 

gcc -shared -o lib$1.so $1.o

#gcc -shared -o libAdd.so add.o

#gcc Plugin/operation.c -ldl

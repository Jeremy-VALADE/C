# Méthode pour transfomer un fichier .c en fichier .so
database=$(find -name *.c)

for file in $database
do
	f=$(basename $file .${file##*.})
	echo $f.c
	gcc -fPIC -c c/$f.c 
	gcc -shared -o c/$f.so c/$f.o
done	


#gcc -fPIC -c $1.c 

#gcc -shared -o lib$1.so $1.o

#gcc -shared -o libAdd.so add.o

#gcc Plugin/operation.c -ldl

# Méthode pour transfomer un fichier .c en fichier .so
database=$(find $1 -name *.c)
for file in $database
do
	f=$(basename $file .${file##*.})
	gcc -fPIC -c $1c/$f.c -o $1o/$f.o
	gcc -shared -o $1so/$f.so $1o/$f.o
done	
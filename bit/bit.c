/*
 *Écrire une fonction C prenant en argument un entier n qui retourne 1 si l'entier n contient un nombre pair de bits à 1 dans son écriture binaire. Votre fonction devra retourner 0 sinon, c'est à dire quand n contient un nombre impair de bits à 1.
 */
 int bin_parity(int n){
  int size = sizeof(int)*8;
  int somme = 0;
  while (size--) {
    if ((n>>size & 1) == 1)
      somme++;
  }
  if (somme%2 == 0) 
    return 1;
  return 0;
}




/* Structure d'une opération du programme */
typedef struct operation {
	char symbole; /* Identificateur */
	int arite; /* Nombre d'opérandes */
	int (*eval)(int* args); /* Fonction de calcul */
} operation;



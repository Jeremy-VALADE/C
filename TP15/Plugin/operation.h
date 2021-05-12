
typedef struct operation {
	char symbole;
	int arite;
	int (*eval)(int* args);
} operation;

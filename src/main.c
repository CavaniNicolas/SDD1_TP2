
#include <stdio.h>
#include "pile.h"
#include "file.h"

void mainFile();
void mainPile();

int main() {
	mainFile();
	return 0;
}


void mainFile() {
	file_t * file = initFile(6);
	int i = 0;
	int val = 0;

	if (file != NULL) {
		for (i=0; i<10; i++) {
			enfiler(file, i+1);

			printf("AFFFFFFFFFFFFFFFF %d\n", file->capacite);
			afficherFile(file);
		}

		for (i=0; i<8; i++) {
			defiler(file, &val);

			printf("defil %d\n", file->base[file->indexSuppression]);
		}

		enfiler(file, 7);
		enfiler(file, 8);

		printf("\nAFFFFFFFFFFFFFFFF %d\n", file->capacite);
		afficherFile(file);
	}

	libererFile(file);
}


void mainPile() {
	pile_t * pile = initPile(10);
	int valeur = 0;

	if (pile != NULL) {

		int i = 0;
		while (i<30) {
			empiler(pile, i);
			printf("sommet : %d\n", pile->sommet);
			i++;
		}
puts("");
		printf("max %d\n", pile->capacite);
		afficherPile(pile);
		i=0;
		while (i<25) {
			depiler(pile, &valeur);
			printf("sommet : %d\n", pile->sommet);
			i++;
		}
puts("");
		printf("max %d\n", pile->capacite);
		afficherPile(pile);
	}

	libererPile(pile);
}

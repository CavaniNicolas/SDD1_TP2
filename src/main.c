
#include <stdio.h>
#include "pile.h"
#include "file.h"


void inverserPile();
void mainFile();
void mainPile();

void inverserPile(pile_t * pile) {
	int  i         = 0;
	type valeur    = 0;
	int  capacite  = pile->capacite;
	file_t * file = initFile(capacite);

	if (file != NULL) {
		for (i=0; i<=capacite; i++) {
			depiler(pile, &valeur);
			enfiler(file, valeur);
			puts("héhé");
		}
		for (i=0; i<=capacite; i++) {
			defiler(file, &valeur);
			empiler(pile, valeur);
			puts("haha");
		}
	}
}



int main() {
	int i = 1;
	pile_t * pile = initPile(10);

	while (i<=5) {
		empiler(pile, (type)i+70);
		printf("sommet : %d\n", pile->sommet);
		i++;
	}
	printf("capacite : %d\n", pile->capacite);
	afficherPile(pile);
	
	inverserPile(pile);

	afficherPile(pile);
	return 0;
}





void mainFile() {
	file_t * file = initFile(6);
	int i = 0;
	type val = 0;

	if (file != NULL) {
		for (i=0; i<10; i++) {
			enfiler(file, (type)i+1);

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
	type valeur = 0;

	if (pile != NULL) {

		int i = 0;
		while (i<30) {
			empiler(pile, (type)i);
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

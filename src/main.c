/* ---------------------------------------------------------------------------- */
/*  main.c                                                                      */
/*            Contient le programme principal d'inversion d'une pile            */
/* ---------------------------------------------------------------------------- */

#include <stdio.h>
#include "pile.h"
#include "file.h"


void inverserPile();
void mainFile();
void mainPile();

void inverserPile(pile_t * pile) {
	int  i        = 0;                 /*Compteur*/
	type valeur   = 0;                 /*Valeur d'entrée/sortie de la pile ou file*/
	int  nbElems  = pile->sommet;      /*Nombre d'elements dans la pile, à inverser*/
	file_t * file = initFile(nbElems+1); /*File temporaire permettant d'inverser la pile*/

	/* Inversion de la pile */
	if (file != NULL) {
		/* On vide la Pile, on rempli la File */
		for (i=0; i<=nbElems; i++) {
			depiler(pile, &valeur);
			enfiler(file, valeur);
		}

		/* On vide la File, on rempli la Pile */
		for (i=0; i<=nbElems; i++) {
			defiler(file, &valeur);
			empiler(pile, valeur);
		}

		/* La pile est alors inversée */
		printf("La pile est inversée\n");

		libererFile(file);
	}
}



int main() {
	int i = 1;
	pile_t * pile = initPile(10);

	while (i<=5) {
		empiler(pile, (type)i);
		printf("sommet : %d\n", pile->sommet);
		i++;
	}
	printf("capacite : %d\n", pile->capacite);
	afficherPile(pile);

	inverserPile(pile);

	afficherPile(pile);

	libererPile(pile);
	return 0;
}





/*void mainFile() {
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
*/
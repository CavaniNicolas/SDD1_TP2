
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"


int main() {
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
	return 0;
}


pile_t * initPile(int capacite) {
	pile_t * pile         = (pile_t *)malloc(sizeof(pile_t));

	if (pile != NULL) {
		pile->base = (int *)malloc(capacite * sizeof(int));
		
		if (pile->base == NULL) {
			free(pile);
			pile = NULL;

		} else {
			pile->capacite = capacite;
			pile->sommet = -1;
		}
	}

	return (pile);
}


char estVide(pile_t * pile) {
	char estVide = 1;
	if (pile->sommet != -1)
		estVide = 0;
	return estVide;
}


char empiler(pile_t * pile, int valeur) {
	char codeErreur = 1;

	if (pile->sommet < pile->capacite - 1) {
		empiler_valeur(pile, valeur);
		codeErreur = 0;

	} else {
		int * nouvBase   = NULL;
		int nouvCapacite = 1.5 * pile->capacite;

		nouvBase = realloc(pile->base, sizeof(int) * nouvCapacite);

		if (nouvBase != NULL) {
			pile->base = nouvBase;
			pile->capacite = nouvCapacite;
			empiler_valeur(pile, valeur);
			codeErreur = 0;
		}
	}

	return codeErreur;
}


void empiler_valeur(pile_t * pile, int valeur) {
	pile->sommet += 1;
	pile->base[pile->sommet] = valeur;
}


char depiler(pile_t * pile, int * valeur) {
	char codeErreur = 2;

	if (!estVide(pile)) {
		*valeur = pile->base[pile->sommet];
		pile->sommet -= 1;
		codeErreur = 0;

		if (pile->sommet < 0.25 * pile->capacite) {
			int * nouvBase = NULL;
			int   nouvCapacite = 0.5 * pile->capacite;

			nouvBase = realloc(pile->base, sizeof(int) * nouvCapacite);
puts("yolo");
			if (nouvBase != NULL) {
				pile->base = nouvBase;
				pile->capacite = nouvCapacite;
			}
		}
	}


	return codeErreur;
}


void afficherPile(pile_t * pile) {
	int i = 0;
	printf("SOMMMMMMMMET : %d\n", pile->sommet);
	for (i=0; i<=pile->sommet; i++) {
		printf("%d\n", pile->base[i]);
	}
}


void libererPile(pile_t * pile) {
	free(pile->base);
	free(pile);
	pile = NULL;
}
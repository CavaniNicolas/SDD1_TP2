
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"


pile_t * initPile(int capacite) {
	pile_t * pile         = (pile_t *)malloc(sizeof(pile_t));

	if (pile != NULL) {
		pile->base = (type *)malloc(capacite * sizeof(type));
		
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


char empiler(pile_t * pile, type valeur) {
	char codeErreur = 1;

	if (pile->sommet < pile->capacite - 1) {
		empiler_valeur(pile, valeur);
		codeErreur = 0;

	} else {
		type * nouvBase     = NULL;
		int    nouvCapacite = 1.5 * pile->capacite + 1;

		nouvBase = (type *)realloc(pile->base, sizeof (type) * nouvCapacite);

		if (nouvBase != NULL) {
			pile->base = nouvBase;
			pile->capacite = nouvCapacite;
			empiler_valeur(pile, valeur);
			codeErreur = 0;
		}
	}

	return codeErreur;
}


void empiler_valeur(pile_t * pile, type valeur) {
	pile->sommet += 1;
	pile->base[pile->sommet] = valeur;
}


char depiler(pile_t * pile, type * valeur) {
	char codeErreur = 2;

	if (!estVide(pile)) {
		*valeur = pile->base[pile->sommet];
		pile->sommet -= 1;
		codeErreur = 0;

		if (pile->sommet < 0.25 * pile->capacite) {
			type * nouvBase = NULL;
			int    nouvCapacite = 0.5 * pile->capacite + 1;

			nouvBase = (type *)realloc(pile->base, sizeof(type) * (nouvCapacite));

			if (nouvBase != NULL) {
				pile->base = nouvBase;
				pile->capacite = nouvCapacite;
			}
		}
	}


	return codeErreur;
}


void libererPile(pile_t * pile) {
	free(pile->base);
	free(pile);
	pile = NULL;
}



void afficherPile(pile_t * pile) {
	int sizeInt = sizeof(int);
	int sizeChar = sizeof(char);

	int sizeType = sizeof(type);

	if (sizeType == sizeInt)
		afficherPileInt(pile);
	else if (sizeType == sizeChar)
		afficherPileChar(pile);
	else
		printf("pas de fonction afficher pile");

}


void afficherPileInt(pile_t * pile) {
	int i = 0;
	for (i=0; i<=pile->sommet; i++) {
		printf("%d\n", pile->base[i]);
	}
}


void afficherPileChar(pile_t * pile) {
	int i = 0;
	for (i=0; i<=pile->sommet; i++) {
		printf("%c\n", pile->base[i]);
	}
}

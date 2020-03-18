/* ---------------------------------------------------------------------------- */
/*  pile.c                                                                      */
/*                  Contient les fonctions associées à la pile                  */
/* ---------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"


pile_t * initPile(int capacite) {
	pile_t * pile = (pile_t *)malloc(sizeof(pile_t)); /*Pile créée*/

	if (pile != NULL) {
		pile->base = (type *)malloc(capacite * sizeof(type));
		
		if (pile->base == NULL) {
			free(pile);
			pile = NULL;

		/* Initialisation de la pile */
		} else {
			pile->capacite = capacite;
			pile->sommet = -1;
		}
	}

	return (pile);
}


char estVidePile(pile_t * pile) {
	char estVide = 1;
	if (pile->sommet != -1)
		estVide = 0;
	return estVide;
}


char empiler(pile_t * pile, type valeur) {
	char codeErreur = 1; /*Code erreur*/

	/* Si la pile n'est pas déjà rempli, on empile la valeur */
	if (pile->sommet < pile->capacite - 1) {
		empiler_valeur(pile, valeur);
		codeErreur = 0;

	/* Sinon, il faut redimmensionner la pile */
	} else {
		int    nouvCapacite = 1.5 * pile->capacite + 1;                                  /*Nouvelle capacité*/
		type * nouvBase     = (type *)realloc(pile->base, sizeof (type) * nouvCapacite); /*Nouvelle base de la pile*/

		/* Si la redimmension est sans erreur, on actualise les données de la pile et on empile la valeur */
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
	/* Empile réellement la valeur au sommet de la pile */
	/* Cette fonction est appelée que si l'on est sur qu'il y a la place */
	pile->sommet += 1;
	pile->base[pile->sommet] = valeur;
}


char depiler(pile_t * pile, type * valeur) {
	char codeErreur = 2; /*Code erreur*/

	/* Si la pile n'est pas vide, on depile la valeur */
	if (!estVidePile(pile)) {
		*valeur = pile->base[pile->sommet];
		pile->sommet -= 1;
		codeErreur = 0;

		/* Apres depilement, si la pile est peu utilisée, on la redimmensionne */
		if (pile->sommet < 0.25 * pile->capacite) {
			int    nouvCapacite = 0.5 * pile->capacite + 1;                                   /*Nouvelle capacite*/
			type * nouvBase     = (type *)realloc(pile->base, sizeof(type) * (nouvCapacite)); /*Nouvelle base de la pile*/

			/* Si la redimmension est sans erreur, on actualise les données de la pile */
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
	int sizeInt  = sizeof(int);
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

	if (!estVidePile(pile)) {
		for (i=0; i<=pile->sommet; i++) {
			printf("%d\n", pile->base[i]);
		}

	} else {
		printf("Pile vide\n");
	}
}


void afficherPileChar(pile_t * pile) {
	int i = 0;

	if (!estVidePile(pile)) {
		for (i=0; i<=pile->sommet; i++) {
			printf("%c\n", pile->base[i]);
		}

	} else {
		printf("Pile vide\n");
	}
}

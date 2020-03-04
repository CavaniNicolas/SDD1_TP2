
#include <stdio.h>
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

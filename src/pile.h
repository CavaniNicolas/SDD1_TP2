#ifndef PILE_H
#define PILE_H


typedef struct pile {
	int capacite;
	int sommet;
	int * base;
}pile_t;


/* -------------------------------------------------------------- */
/* initPile     Initialise une pile de taille le paramètre taille */
/*                                                                */
/* En entrée :  taille : entier, taille de la pile                */
/*                                                                */
/* En sortie :  pile : pointeur sur la pile (pile_t)              */
/* -------------------------------------------------------------- */
pile_t * initPile(int);


/* --------------------------------------------------------------------- */
/* estVide      Indique si la pile passée en paramètre est vide ou non   */
/*                                                                       */
/* En entrée :  pile : pile_t * : pile à tester                          */
/*                                                                       */
/* En sortie :  estVide : (char) booléen, 1 si la pile est vide, 0 sinon */
/* --------------------------------------------------------------------- */
char estVide(pile_t *);


char empiler(pile_t * pile, int valeur);


void empiler_valeur(pile_t * pile, int valeur);


char depiler(pile_t * pile, int * valeur);


void afficherPile(pile_t * pile);


void libererPile(pile_t * pile);


#endif
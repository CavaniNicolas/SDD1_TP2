#ifndef PILE_H
#define PILE_H

typedef int type;


typedef struct pile {
	int  capacite;
	int  sommet;
	type * base;
}pile_t;


/* -------------------------------------------------------------- */
/* initPile     Initialise une pile de taille le paramètre taille */
/*                                                                */
/* En entrée :  taille (int) : taille de la pile                  */
/*                                                                */
/* En sortie :  pile : pointeur sur la pile (pile_t *)            */
/* -------------------------------------------------------------- */
pile_t * initPile(int);


/* --------------------------------------------------------------------- */
/* estVide      Indique si la pile passée en paramètre est vide ou non   */
/*                                                                       */
/* En entrée :  pile (pile_t *) : pile à tester                          */
/*                                                                       */
/* En sortie :  estVide (char) booléen : 1 si la pile est vide, 0 sinon  */
/* --------------------------------------------------------------------- */
char estVide(pile_t *);


/* ------------------------------------------------------------------ */
/* empiler      Empile une valeur au sommet de la pile,               */
/*                          et l'aggrandit si elle est trop petite    */
/*                                                                    */
/* En entrée :  pile (pile_t *) : pile à remplir                      */
/*              valeur (int)    : valeur à empiler                    */
/*                                                                    */
/* En sortie :  codeErreur (char) booléen : 1 si erreur, 0 sinon      */
/* ------------------------------------------------------------------ */
char empiler(pile_t * pile, type valeur);


/* ------------------------------------------------------------------ */
/* empiler_valeur    Ajoute réelement la valeur au sommet de la pile  */
/*                                                                    */
/* En entrée :  pile (pile_t *) : pile à remplir                      */
/*              valeur (int)    : valeur à emiler                     */
/*                                                                    */
/* En sortie :  void                                                  */
/* ------------------------------------------------------------------ */
void empiler_valeur(pile_t * pile, type valeur);


/* -------------------------------------------------------------- */
/* depiler      Dépile la valeur au sommet de la pile,            */
/*                          et la réduit si elle peu utilisée     */
/*                                                                */
/* En entrée :  pile (pile_t *) : pile à vider                    */
/*              valeur (int)    : valeur dépilée (par adresse)    */
/*                                                                */
/* En sortie :  codeErreur (char) booléen : 2 si erreur, 0 sinon  */
/* -------------------------------------------------------------- */
char depiler(pile_t * pile, type * valeur);


/* --------------------------------------------------------- */
/* afficherPile   Affiche la pile                            */
/*                                                           */
/* En entrée :  pile (pile_t *) : pile à afficher            */
/*                                                           */
/* En sortie :  void                                         */
/* --------------------------------------------------------- */
void afficherPile(pile_t * pile);

void afficherPileInt(pile_t * file);
void afficherPileChar(pile_t * file); 


/* --------------------------------------------------------- */
/* libererPile  Libère la mémoire utilisée par la pile       */
/*                                                           */
/* En entrée :  pile (pile_t *) : pile à libérer             */
/*                                                           */
/* En sortie :  void                                         */
/* --------------------------------------------------------- */
void libererPile(pile_t * pile);


#endif
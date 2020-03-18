/* ---------------------------------------------------------------------------- */
/*  file.c                                                                      */
/*                  Contient les fonctions associées à la file                  */
/* ---------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "file.h"


file_t * initFile(int capacite) {
	file_t * file = (file_t *)malloc(sizeof(file_t)); /*File créée*/

	if (file != NULL) {
		file->base = (type *)malloc(capacite * sizeof(capacite));

		/* Erreur de memoire */
		if (file->base == NULL) {
			free(file);
			file = NULL;

		/* Initialisation de la file */
		} else {
			file->capacite         = capacite;
			file->nbElements       = 0;
			file->indexSuppression = 0;
			file->indexInsertion   = 0;
		}
	}

	return file;
}


char estVideFile(file_t * file) {
	char estVide = 1;
	if (file->nbElements != 0) {
		estVide = 1;
	}
	return estVide;
}


char enfiler(file_t * file, type valeur) {
	char codeErreur = 1;                                           /*Code erreur*/
	int  suivInsere = (file->indexInsertion + 1) % file->capacite; /*Index d'insertion*/

	/* Si la file n'est pas déjà remplie, on enfile la valeur */
	if (file->nbElements != file->capacite) {
		file->base[file->indexInsertion] = valeur;
		file->indexInsertion = suivInsere;

		file->nbElements += 1;
		codeErreur = 0;

	/* Sinon, il faut redimmensionner la file */
	} else {
		int    nouvCapacite = 1.5 * file->capacite;
		type * nouvBase     = (type *)malloc(nouvCapacite * sizeof(type));

		/* Si l'allocation est sans erreur, on redimmensionne la file et on enfile la valeur */
		if (nouvBase != NULL) {
			redimensionnerFile(file, nouvBase, nouvCapacite);
			enfiler(file, valeur);

		} else {
			printf("Memoire insufisante\n");
		}
	}
	return codeErreur;
}


char defiler(file_t * file, type * valeur) {
	char codeErreur = 2; /*Code erreur*/

	/* Si la file n'est pas vide, on defile la valeur */
	if (!estVideFile(file)) {
		*valeur = file->base[file->indexSuppression];
		file->indexSuppression = (file->indexSuppression + 1) % file->capacite;
		file->nbElements -= 1;
		codeErreur = 0;

		/* Si la file est peu utilisée, on la redimmensionne */
		if (file->nbElements < 0.25 * file->capacite) {
			int    nouvCapacite = 0.5 * file->capacite + 1;
			type * nouvBase     = (type *)malloc(nouvCapacite * sizeof(type));

			/* Si l'allocation est sans erreur, on redimmensionne la file */
			if (nouvBase != NULL) {
				redimensionnerFile(file, nouvBase, nouvCapacite);
			}
		}

	} else {
		printf("File vide\n");
	}

	return codeErreur;
}


void redimensionnerFile(file_t * file, type * nouvBase, int nouvCapacite) {
	int i = 0; /*Compteur*/

	/* On copie l'ancienne file dans la nouvelle (redimmensionnée) */
	for (i=0; i<file->nbElements; i++) {
		nouvBase[i] = file->base[file->indexSuppression + i];
	}

	/* On libère l'ancienne file et on actualise les données de la nouvelle */
	free(file->base);
	file->base = nouvBase;

	file->indexSuppression = 0;
	file->indexInsertion   = file->nbElements;
	file->capacite = nouvCapacite;
}


void libererFile(file_t * file) {
	free(file->base);
	free(file);
	file = NULL;
}


void afficherFile(file_t * file) {
	int sizeInt = sizeof(int);
	int sizeChar = sizeof(char);

	int sizeType = sizeof(type);

	if (sizeType == sizeInt)
		afficherFileInt(file);
	else if (sizeType == sizeChar)
		afficherFileChar(file);
	else
		printf("pas de fonction afficher file");

}


void afficherFileInt(file_t * file) {
	int cour = file->indexSuppression;

	if (!estVideFile(file)) {
		while (cour != file->indexInsertion) {
			printf("%d\n", file->base[cour]);
			cour = (cour + 1) % file->capacite;
		}

	} else {
		printf("File vide\n");
	}
}


void afficherFileChar(file_t * file) {
	int cour = file->indexSuppression;

	if (!estVideFile(file)) {
		while (cour != file->indexInsertion) {
			printf("%c\n", file->base[cour]);
			cour = (cour + 1) % file->capacite;
		}

	} else {
		printf("File vide\n");
	}
}

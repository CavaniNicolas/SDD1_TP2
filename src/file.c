
#include <stdio.h>
#include <stdlib.h>
#include "file.h"


file_t * initFile(int capacite) {
	file_t * file = (file_t *)malloc(sizeof(file_t));

	if (file != NULL) {
		file->capacite         = capacite;
		file->nbElements       = 0;
		file->indexSuppression = 0;
		file->indexInsertion   = 0;

		file->base = (type *)malloc(capacite * sizeof(capacite));

		if (file->base == NULL) {
			free(file);
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
	char codeErreur = 1;
	int  suivInsere = (file->indexInsertion + 1) % file->capacite;

	if (file->nbElements != file->capacite) {
		file->base[file->indexInsertion] = valeur;
		file->indexInsertion = suivInsere;

		file->nbElements += 1;
		codeErreur = 0;

	} else {
		int    nouvCapacite = 1.5 * file->capacite;
		type * nouvBase     = (type *)malloc(nouvCapacite * sizeof(type));

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
	char codeErreur = 2;

	if (file->nbElements != 0) {
		*valeur = file->base[file->indexSuppression];
		file->indexSuppression = (file->indexSuppression + 1) % file->capacite;
		file->nbElements -= 1;
		codeErreur = 0;


		if (file->nbElements < 0.25 * file->capacite) {
			int    nouvCapacite = 0.5 * file->capacite + 1;
			type * nouvBase     = (type *)malloc(nouvCapacite * sizeof(type));

			if (nouvBase != NULL) {
				redimensionnerFile(file, nouvBase, nouvCapacite);
			}
		}

	} else {
		printf("file vide\n");
	}

	return codeErreur;
}


void redimensionnerFile(file_t * file, type * nouvBase, int nouvCapacite) {
	int i = 0;

	for (i=0; i<file->nbElements; i++) {
		nouvBase[i] = file->base[file->indexSuppression + i];
	}

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
	while (cour != file->indexInsertion) {
		printf("AAAAA %d\n", file->base[cour]);
		cour = (cour + 1) % file->capacite;
	}
}


void afficherFileChar(file_t * file) {
	int cour = file->indexSuppression;
	while (cour != file->indexInsertion) {
		printf("AAAAA %c\n", file->base[cour]);
		cour = (cour + 1) % file->capacite;
	}
}


#include <stdio.h>
#include <stdlib.h>
#include "file.h"


file_t * initFile(int capacite) {
	file_t * file = (file_t *)malloc(sizeof(file_t));

	if (file != NULL) {
		file->capacite         = capacite;
		file->nbElements       = 0;
		file->indexSuppression = 0;
		file->indexInsertion   = 1;

		file->base = (int *)malloc(capacite * sizeof(capacite));

		if (file->base == NULL) {
			free(file);
		}
	}

	return file;
}


char enfiler(file_t * file, int valeur) {
	char codeErreur = 1;

	if (file->indexInsertion != file->indexSuppression) {
		file->base[file->indexInsertion] = valeur;
		file->indexInsertion = (file->indexInsertion + 1) % file->capacite;
		codeErreur = 0;

	} else {
		printf("capacite de la file insufisante, en recreer une plus grande\n");
	}

	return codeErreur;
}


char defiler(file_t * file, int * valeur) {
	char codeErreur = 1;

	if (file->indexSuppression != file->indexInsertion) {
		*valeur = file->base[file->indexSuppression];
		file->indexSuppression = (file->indexSuppression + 1) % file->capacite;
		codeErreur = 0;

	} else {
		printf("file vide\n");
	}

	return codeErreur;
}


void libererFile(file_t * file) {
	free(file->base);
	free(file);
	file = NULL;
}
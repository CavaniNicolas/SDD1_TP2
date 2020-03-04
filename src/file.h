#ifndef FILE_H
#define FILE_H


typedef struct file {
	int   capacite;
	int   nbElements;
	int   indexInsertion;
	int   indexSuppression;
	int * base;
}file_t;


file_t * initFile(int);


char enfiler(file_t * file, int valeur);


char defiler(file_t * file, int * valeur);


void libererFile(file_t *);


#endif
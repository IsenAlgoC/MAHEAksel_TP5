#pragma once

#include <stdlib.h>
#include <stdio.h>
#define TAILLEINITIALE 100

typedef struct Tableau {
	int* elt;                               // le tableau d’entiers
	int size;                               // la taille de ce tableau d’entiers
	int eltsCount;                          // le nombre d’éléments dans le tableau
}TABLEAU;

int initTab(int* tab, int size) {			// fonction d'initialisation du tableau avec des 0

	if (tab == NULL || size < 0) { return -1; }
	else {
		for (int i = 0; i < size; i++) {
			*(tab + i) = 0;
		}
	}

}

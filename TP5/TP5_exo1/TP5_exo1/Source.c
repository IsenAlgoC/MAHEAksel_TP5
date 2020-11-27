// Aksel MAHE
// CSI3

#include <stdlib.h>                                     
#include <stdio.h>
#include "tab.h"                                        //On introduit notre fichier d'en-tête   
#define TAILLE 10                                        
#define TAB2SIZE 100
#define TAILLEAJOUT 50 


int initTab(int* tab, int size) {                       // Fonction d'initialisation du tableau
	if (tab == 'NULL' || size < 0)                      // Conditions d'erreurs
	{ 
		return -1;										//Affiche -1 car avec un return -1;, la console n'affiche rien.
	}
	else{
		for (int i = 0; i < size; i++) {				//Condition d'initialisation si le tableau contient des éléments
			tab[i] = 0;                               	//Initialisation du tableau avec la valeur 0
		}
		return size;
	}

	}

int afficheTab(int* tab, int size, int nbElts) {       //Fonction d'affichage du tableau
	if (tab == NULL || size < 0 || size < nbElts)      //Conditions d'erreurs
	{
		return -1;                                     
	}
	else {
		int i;
		for (i = 0; i < nbElts; i++)
		{
			printf("%i", tab[i]);                      //Affichage du tableau valeur par valeur
		}
	}
}


int remplirTab(int* tab, int size) {                   //Remplis les n premeirs termes du tableau de 1 à n

	if (tab == NULL || size < 0) {
		return -1;
	}
	else {
		for (int i = 0; i < 20; i++) {
			*(tab + i) = i + 1;
		}
	}
}

int ajouteElementDansTableau(int* tab, int* size, int* nbElts, int element)  
//On ajoute un élément au tableau en augmentant sa taille si nécessaire. renvoie NULL si l'agrandissement échoue
{

if (tab == NULL || size < 0 || nbElts < 0) 
{ 
	return NULL; 
}

else {
	if (*size == *nbElts)
	{
		*size += 1;
		int* tabSave = tab;
		tab = (int*)realloc(tab, *size * sizeof(int));
		if (tab == NULL)
		{
			tab = tabSave; return NULL; 
		}
		*(tab + *nbElts) = element;
		*nbElts += 1;
		return tab;
	}
	else 
	{
		*(tab + *nbElts) = element;
		*nbElts += 1;
		return tab;
	}
}

}

int main() {

	int myTab1[TAILLE];

	int* myTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbElts = 0;
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));

	if (myTab2 != NULL) {
		initTab(myTab2, tabSize);
		remplirTab(myTab2, tabSize, &nbElts, tabSize);						//On remplit le tableau entièrement (de 1 à 100)
		for (int i = 0; i < tabSize; i++) {
			printf("%d ", *(myTab2 + i));
		}
		printf("\n");

		ajouteElementDansTableau(myTab2, &tabSize, &nbElts, 125);				//On augmente la taille du tableau de 1 puis on ajoute 101
		for (int i = 0; i < tabSize; i++) {
			printf("%d ", *(myTab2 + i));
		}
		printf("\n");

		ajouteElementDansTableau(myTab2, &tabSize, &nbElts,150);				//On augmente la taille du tableau de 1 puis on ajoute 563
		for (int i = 0; i < tabSize; i++) {
			printf("%d ", *(myTab2 + i));
		}
	}
	else { printf("Memoire insuffisante"); }

	free(myTab2);
}
//Aksel MAHE
//CSI 3

#include <stdlib.h>
#include <stdio.h>
#include "tab.h"


TABLEAU newArray() {										//créé un tableau de taille TAILLEINITIALE qui renvoie NULL si allocation échouée

	TABLEAU tab;
	tab.size = TAILLEINITIALE;
	tab.eltsCount = 0;
	tab.elt = NULL;
	tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));
	initTab(tab.elt, tab.size);
	return tab;

}

int incrementArraySize(TABLEAU* tab, int incrementValue) {				//on augmente la taille du tableau de incrementValue

	if (tab->elt == NULL || tab->size < 0)                              //conditions d'erreurs
	{
		return -1; 
	}

	tab->size += incrementValue;
	return tab->size;

}

int setElement(TABLEAU* tab, int pos, int element) {

	if (tab->elt == NULL || tab->size < 0 || pos < 1)  
	{
		return 0;
	}

	if (pos - 1 < tab->size) 
	{
		*(tab->elt + pos - 1) = element;
		tab->eltsCount = max(pos, tab->eltsCount);
	}

	if (incrementArraySize(tab, pos - tab->size) != 1)
	{
		*(tab->elt + tab->size - 1) = element;
		tab->eltsCount = pos;
		return pos;												
		//renvoie la position telle que première valeur est position 1, sinon mettre return pos-1 pour avoir le vrai rang
	}

	return 0;

}

int displayElements(TABLEAU* tab, int startPos, int endPos)
{
	if (tab->elt == NULL || startPos < 0 || endPos < 0)
	{
		return 0; 
	}

	if (endPos < startPos)                           
	{
		int buffer = endPos;                          //On échange les valeurs
		endPos = startPos;
		startPos = buffer;
	}

	for (int i = startPos - 1; i <= endPos - 1; i++) //On reste sur l'hypothèse selon laquelle le 1er élément est à la position 1
	{				
		printf("%d ", *(tab->elt + i));
	}
	printf("\n");
	return 0;
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) 
{
	if (tab->elt == NULL || startPos < 1 || endPos < 1 || startPos > tab->size || endPos > tab->size) //Conditions d'erreurs
	{
		return -1; 
	}

	if (endPos < startPos)                    //On échange les valeurs
	{
		int buffer = endPos;
		endPos = startPos;
		startPos = buffer;
	}

	int nbValeurs = endPos - startPos + 1;

	if (nbValeurs == tab->size) 
	{
		free(tab->elt);
		tab->elt = NULL; 
		tab->size = 0; 
		tab->eltsCount = 0; 
		return tab->size; 
	}

	for (int i = startPos - 1; i < tab->size - endPos; i++) 
	{
		*(tab->elt + i) = *(tab->elt + i + nbValeurs);
	}

	int* memoire = tab->elt;

	tab->elt = (int*)realloc(tab->elt, ((size_t)tab->size - (size_t)nbValeurs * sizeof(int)));
	if (tab->elt == NULL) 
	{
		tab->elt = memoire;
		return -1;
	}
	tab->size -= nbValeurs;
	return tab->size;
}

int main() {

	TABLEAU tab = newArray();                                                                       //Initialise le tableau

	printf("Le tableau a une taille de %d\n", tab.size);                                            //Imprime la taille du tableau

	printf("\nApres agrandissement, le tableau a une taille de %d\n", incrementArraySize(&tab, 2)); //Imprime la taille du tableau après agrandissement de 2

	printf("\nOn ajoute %d au rang %d\n", 32, setElement(&tab, 56, 32)); 	                        //Va inclure 32 au rang 56 (en supposant que la première valeur est au rang 1)

	printf("\nLes elements du rang 54 au rang 58 sont :");                                          //va donner du rang 54 au rang 58 (où le premier élément est au rang 1)
	displayElements(&tab, 54, 58);

	printf("\n");

	/*supprime les éléments entre 2 positions puis libère leur espace
	 ici on cherchera à tout supprimer jusqu'au rang 56 (où on retrouve le 32 de la fonction précédente*/

	deleteElements(&tab, 1, 55);


	printf("Le tableau final est donc : "); 	//Imprime tout le tableau
	for (int i = 0; i < tab.size - 1; i++) {
		printf("%d ", *(tab.elt + i));
	}
	printf("\n\n");


}
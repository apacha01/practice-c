///////////////////////////////////////////////////////BIBLIOTECAS///////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "TablaHash.h"
/////////////////////////////////////////////////////////DEFINES/////////////////////////////////////////////////////////

////////////////////////////////////////////////////////VARIABLES////////////////////////////////////////////////////////

///////////////////////////////////////////////////////ESTRUCTURAS///////////////////////////////////////////////////////

/////////////////////////////////////////////////PROTOTIPOS DE FUNCIONES/////////////////////////////////////////////////

//////////////////////////////////////////////////////////Main///////////////////////////////////////////////////////////
int main(){
	HashTable h;
	initHashTable(&h,7);

	printTable(&h);

	addToTable(&h, "Jorge", 56);
	addToTable(&h, "Jose", 101);
	addToTable(&h, "María", 5);
	//"Maria" (sin tilde) colisiona con "Graciela"
	addToTable(&h, "Graciela", 6);

	printTable(&h);

	printf("%d\n", existsInTable(&h, "Jorge"));
	printf("%d\n", existsInTable(&h, "Pedro"));

	finishHashTable(&h);
	return 0;
}
////////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////
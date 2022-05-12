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
	addToTable(&h, "Pablo", 5);
	addToTable(&h, "Graciela", 6);
	addToTable(&h, "Maria", 60);
	addToTable(&h, "Pedro", 65);
	addToTable(&h, "Juan Martin", 76);
	addToTable(&h, "Moriello", 150);

	printTable(&h);

	printf("%d\n", existsInTable(&h, "Jorge"));
	printf("%d\n", existsInTable(&h, "Martin"));
	printf("%d\n", existsInTable(&h, "Pablo"));
	printf("%d\n", existsInTable(&h, "Maria"));
	printf("%d\n", existsInTable(&h, "Jose"));
	printf("%d\n", existsInTable(&h, "Pedro"));

	printf("\n\n");

	removeFromTable(&h, "Jorge");
	removeFromTable(&h, "Pablo");
	removeFromTable(&h, "Maria");

	printf("\n\n");

	printf("%d\n", existsInTable(&h, "Jorge"));
	printf("%d\n", existsInTable(&h, "Martin"));
	printf("%d\n", existsInTable(&h, "Pablo"));
	printf("%d\n", existsInTable(&h, "Graciela"));
	printf("%d\n", existsInTable(&h, "Jose"));
	printf("%d\n", existsInTable(&h, "Pedro"));
	addToTable(&h, "Maria", 60);

	printTable(&h);

	printf("%d\n", getFromTable(&h, "Jorge"));
	printf("%d\n", getFromTable(&h, "Martin"));
	printf("%d\n", getFromTable(&h, "Pablo"));
	printf("%d\n", getFromTable(&h, "Graciela"));
	printf("%d\n", getFromTable(&h, "Pedro"));
	printf("%d\n", getFromTable(&h, "Jose"));
	printf("%d\n", getFromTable(&h, "Jose Luis"));
	printf("%d\n", getFromTable(&h, "Maria"));

	addToTable(&h, "Graciela", 85);

	printTable(&h);

	finishHashTable(&h);
	return 0;
}
////////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "vectorDinamico.h"

int main(){
	struct Vector v1;
	struct Vector *v = &v1;

	for (int i = 0; i < 16; i++) {
		printf("hola mundo\n");
	}

	init(v);

	for (int i = 0; i < 16; i++) {
		printf("hola mundo\n");
	}

	//printf("%d\n", capacity(v));
	//int c = capacity(v);

	free(v->p);
	return 0;
}

/*
//PARA PRUEBAS SIN CICLOS

	printf("%d\n", at(v,0));
	printf("%d\n", size(v));
	printf("%d\n", capacity(v));

	push(v,178);
	push(v,178);
	push(v,178);
	push(v,65);

	printf("\n%d\n", at(v,0));
	printf("%d\n", size(v));
	printf("%d\n", capacity(v));

	insert(v,3,135);
	prepend(v,67);
	push(v,156);
	push(v,182);
	push(v,193);
	push(v,15);
	push(v,16);
	push(v,56);
	push(v,556);
	push(v,1);
	push(v,6);
	push(v,5);

	printf("\n%d\n", find(v,135));
	printf("%d\n", find(v,178));

	printf("\n%d\n", at(v,0));
	printf("%d\n", at(v,1));
	printf("%d\n", at(v,2));
	printf("%d\n", at(v,3));
	printf("%d\n", at(v,4));
	printf("%d\n", at(v,5));
	printf("%d\n", at(v,6));
	printf("%d\n", at(v,7));
	printf("%d\n", at(v,8));
	printf("%d\n", at(v,9));
	printf("%d\n", at(v,10));
	printf("%d\n", at(v,11));
	printf("%d\n", at(v,12));
	printf("%d\n", at(v,13));
	printf("%d\n", at(v,14));
	printf("%d\n", at(v,15));

	printf("\n%d\n", pop(v));

	printf("\n%d\n", size(v));
	printf("%d\n", capacity(v));
	printf("%d\n", isEmpty(v));

	printf("\n%d\n", pop(v));
	printf("%d\n", pop(v));
	printf("%d\n", pop(v));
	printf("%d\n", pop(v));
	printf("%d\n", pop(v));
	printf("%d\n", pop(v));
	printf("%d\n", pop(v));
	printf("%d\n", pop(v));
	printf("%d\n", pop(v));
	printf("%d\n", pop(v));

	printf("\n%d\n", size(v));
	printf("%d\n", capacity(v));
*/
#include <stdio.h>
#include <stdlib.h>
#include "vectorDinamico.h"

int main(){
	struct Vector v1;
	struct Vector *v = &v1;

	allocateMemory(v,16);

	printf("%d\n", at(v,0));
	printf("%d\n", size(v));
	printf("%d\n", capacity(v));

	push(v,178);
	push(v,12);
	push(v,18);
	push(v,78);

	printf("\n%d\n", at(v,0));
	printf("%d\n", size(v));
	printf("%d\n", capacity(v));

	insert(v,3,135);
	prepend(v,67);

	printf("\n%d\n", at(v,0));
	printf("%d\n", at(v,1));
	printf("%d\n", at(v,2));
	printf("%d\n", at(v,3));
	printf("%d\n", at(v,4));
	printf("%d\n", at(v,5));

	printf("%d\n", pop(v));

	printf("\n%d\n", size(v));
	printf("%d\n", isEmpty(v));

	free(v->p);
	return 0;
}
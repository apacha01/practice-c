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

	printf("%d\n", at(v,0));
	printf("%d\n", size(v));
	printf("%d\n", capacity(v));

	insert(v,0,135);

	printf("%d\n", at(v,0));
	printf("%d\n", isEmpty(v));

	free(v->p);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "vectorDinamico.h"

int main(){
	struct Vector v1;
	struct Vector *v = &v1;

	allocateMemory(v,16);

	for (int i = 0; i < capacity(v); ++i)
	{
		push(v,i+1);
		printf("%d\n", at(v,i));
	}

	free(v->p);
	return 0;
}
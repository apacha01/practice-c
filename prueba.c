#include <stdio.h>
#include <stdlib.h>
#include "vectorDinamico.h"

int main(){
	struct Vector v1;
	struct Vector *v = &v1;

	allocateMemory(v,16);

	printf("%d\n", *v1.p);
	printf("%d\n", size(v));
	printf("%d\n", capacity(v));

	push(v,178);

	printf("%d\n", *v->p);
	printf("%d\n", *v->_size);
	printf("%d\n", *v->_capacity);

	printf("%d\n",at(v,0));
	printf("%d\n", isEmpty(v));

	free(v->p);
	return 0;
}
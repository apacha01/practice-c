#include <stdio.h>
#include <stdlib.h>
#include "vectorDinamico.h"

int main(){
	struct Vector v1;
	struct Vector *v = &v1;

	init(v);

	for (int i = 0; i < capacity(v); ++i)
	{
		printf("hola mundo\n");
	}

	return 0;
}
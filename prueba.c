#include <stdio.h>
#include <stdlib.h>
#include "vectorDinamico.h"


int main(){
	struct Vector v1;
	allocateMemory(v1, 16);

	printf("%d\n", v1._size);
	printf("%d\n", v1._capacity);

	v1._size = 1;

	*v1.p = 12;
	push(v1,16);

	printf("%d\n", *v1.p);
	printf("%d\n", at(v1,1));

/*
	for (int i = 0; i < 10; ++i)
	{
		push(vector,i+1);
		printf("%d, ", at(vector,i));
	}
*/
	free(v1.p);
	return 0;
}
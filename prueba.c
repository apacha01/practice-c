#include <stdio.h>
#include <stdlib.h>
#include "vectorDinamico.h"


int main(){
	struct Vector v1;
	//allocateMemory(v1,16);

	printf("%d\n", *v1._size);
	printf("%d\n", *v1._capacity);

	free(v1.p);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "vectorDinamico.h"


int main(){
	int *vector;
	vector = allocateMemory(16);

	for (int i = 0; i < 10; ++i)
	{
		push(vector,i+1);
		printf("%d, ", at(vector,i));
	}
	printf("%d\n", _size);


	return 0;
}
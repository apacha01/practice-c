#include <stdio.h>
#include <stdlib.h>
#include "vectorDinamico.h"

int main(){
	struct Vector v1;
	struct Vector *v = &v1;
	init(v);

	for (int i = 0; i < 18; i++) {
		push(v,i+1);
		printf("%d - ", at(v,i));
	}

	erase(v,0);
	removeAll(v,5);
	insert(v,6,75);
	printf("\n%d\n", find(v,75));
	printf("%d\n", size(v));
	printf("%d\n", capacity(v));
	printf("%d\n", isEmpty(v));
	prepend(v,98);
	printf("%d\n", pop(v));


	for (int i = 0; i < capacity(v); i++) {
		printf("%d - ", at(v,i));
	}

	for (int i = 0; i < 10; i++) {
		erase(v,i);
	}

	printf("\n");

	for (int i = 0; i < size(v); i++) {
		printf("%d - ", at(v,i));
	}

	printf("\n%d\n", size(v));
	printf("%d\n", capacity(v));

	free(v->p);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "ListaSimple.h"

int main(){
	struct SLinkedList l;
	struct SLinkedList *lp = &l;

	init(lp);

	printf("%d\n", size(lp));
	printf("%d\n", empty(lp));

	pushFront(lp, 3);

	return 0;
}
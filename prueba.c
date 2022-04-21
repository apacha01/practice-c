#include <stdio.h>
#include <stdlib.h>
#include "ListaSimple.h"

int main(){
	struct SLinkedList l;
	struct SLinkedList *lp = &l;

	init(lp);

	printf("Size: %d - ", size(lp));
	printf("Empty: %d\n", empty(lp));
	printf("%d\n", lp->head);

	pushFront(lp, 3);
	pushFront(lp, 4);
	pushBack(lp,17);
	pushBack(lp,58);

	printf("%d\n", popFront(lp));
	printf("%d\n", lp->head->_value);
	printf("Size: %d - ", size(lp));
	printf("Empty: %d\n", empty(lp));

	for (int i = 0; i < size(lp); i++)
	{
		printf("%d\n", valueAt(lp,i));
	}

	return 0;
}
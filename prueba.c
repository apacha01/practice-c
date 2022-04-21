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

	for (int i = 0; i < 4; i++) {
		pushFront(lp, i+1);
		pushBack(lp,i+17);
	}

	printf("%d\n", popFront(lp));
	printf("%d\n", popBack(lp));
	printf("Size: %d - ", size(lp));
	printf("Empty: %d\n", empty(lp));

	for (int i = 0; i < size(lp); i++) {
		printf("%d\n", valueAt(lp,i));
	}

	printf("%d\n", front(lp));
	printf("%d\n", back(lp));

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "ListaSimple.h"

int main(){
	struct SLinkedList l;
	struct SLinkedList *lp = &l;

	init(lp);

	printf("%d\n", size(lp));
	printf("%d\n", empty(lp));
	printf("%d\n", lp->head);

	pushFront(lp, 3);

	printf("%d\n", valueAt(lp,0));
	printf("%d\n", lp->head);
	printf("%d\n", lp->head->_value);

	return 0;
}
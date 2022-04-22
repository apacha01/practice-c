#include <stdio.h>
#include <stdlib.h>
#include "ListaSimple.h"

void data(struct SLinkedList *);

int main(){
	struct SLinkedList l;
	struct SLinkedList *lp = &l;
	init(lp);

	data(lp);

	for (int i = 0; i < 4; i++) {
		pushFront(lp, i+1);
		pushBack(lp,i+17);
	}

	printf("%d\n", popFront(lp));
	printf("%d\n", popBack(lp));
	printf("Size: %d - ", size(lp));
	printf("Empty: %d\n", empty(lp));

	data(lp);

	printf("\n%d\n", front(lp));
	printf("%d\n\n", back(lp));

	insert(lp,0,0);
	insert(lp,2,135);
	insert(lp,1,400);
	insert(lp,6,567);
	insert(lp,5,1000);
	insert(lp,20,10);

	erase(lp,2);

	data(lp);

	printf("\n%d\n", valueNfromEnd(lp,0));
	printf("\n%d\n", valueNfromEnd(lp,2));
	printf("\n%d\n", valueNfromEnd(lp,5));



	return 0;
}

void data(struct SLinkedList *lp){
	for (int i = 0; i < size(lp); i++) {
		printf("%d\n", valueAt(lp,i));
	}
	printf("Size: %d - ", size(lp));
	printf("Empty: %d\n", empty(lp));
}
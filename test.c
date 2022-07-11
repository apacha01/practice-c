///////////////////////////////////////////////////////BIBLIOTECAS///////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"
//////////////////////////////////////////////////////////Main///////////////////////////////////////////////////////////
int main(){
	BST b;

	BSTinit(&b);
	insert(&b,17);
	insert(&b,18);
	insert(&b,19);
	insert(&b,1);
	insert(&b,8);
	insert(&b,28);
	insert(&b,27);
	insert(&b,-1);
	insert(&b,25);
	insert(&b,2);
	insert(&b,7);

	printValues(&b);

	printf("%d\n\n", getNodeCount(&b));

	printf("%d\n", isInTree(&b, 1));
	printf("%d\n", isInTree(&b, 18));
	printf("%d\n", isInTree(&b, 8));
	printf("%d\n", isInTree(&b, 19));
	printf("%d\n", isInTree(&b, 17));
	printf("%d\n", isInTree(&b, 15));
	printf("%d\n", isInTree(&b, 12));
	printf("%d\n\n", isInTree(&b, 22));
	

	printf("Height: %d\n", getHeight(&b));
	printf("Min: %d\n", getMin(&b));
	printf("Max: %d\n", getMax(&b));

	

	printf("\n\nFin\n\n");
	deleteTree(&b);
	printValues(&b);
	return 0;
}
////////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////
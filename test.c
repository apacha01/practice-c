///////////////////////////////////////////////////////BIBLIOTECAS///////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"
//////////////////////////////////////////////////////////Main///////////////////////////////////////////////////////////
int main(){
	BST b;

	BSTinit(&b);

/*
*					17
*				/		\
*			1				18
*		   / \					\
*		-1		8					19
*			  /					   /   \
*			2					 20		28
*			  \						  /
*				7					27
*								  /
*								25
*
*		Height = 5	-	Node Count = 12	-	smallest = -1	-	greatest = 28	-	isBST = true
*/

	insert(&b,17);
	insert(&b,18);
	insert(&b,19);
	insert(&b,20);
	insert(&b,1);
	insert(&b,8);
	insert(&b,28);
	insert(&b,27);
	insert(&b,-1);
	insert(&b,25);
	insert(&b,2);
	insert(&b,7);

	printValues(&b);

	printf("%d\n", getNodeCount(&b));

	printf("\n%d\n", isInTree(&b, 1));
	printf("%d\n", isInTree(&b, 18));
	printf("%d\n", isInTree(&b, 8));
	printf("%d\n", isInTree(&b, 19));
	printf("%d\n", isInTree(&b, 17));
	printf("%d\n", isInTree(&b, 15));
	printf("%d\n", isInTree(&b, 12));
	printf("%d\n", isInTree(&b, 22));
	

	printf("\nHeight: %d\n", getHeight(&b));
	printf("Min: %d\n", getMin(&b));
	printf("Max: %d\n", getMax(&b));
	printf("Es BST: %d\n", isBST(&b));

	printf("\n%d\n", getLeftmostNode(b.root)->_value);
	printf("%d\n", getRightmostNode(b.root)->_value);
	printf("%d\n", getRightmostNode(b.root->leftChild)->_value);
	printf("%d\n", getLeftmostNode(b.root->rightChild->rightChild->rightChild)->_value);

	printf("\n");
	printValues(&b);
	
	printf("\nDeleting number 7...\n");
	deleteValue(&b, 7);
	printValues(&b);

	printf("\nDeleting number 1...\n");
	deleteValue(&b, 1);

	printValues(&b);

	printf("\nDeleting number 8...\n");
	deleteValue(&b, 8);

	printValues(&b);

	printf("\nDeleting number 19...\n");
	deleteValue(&b, 19);

	printValues(&b);

	printf("\nDeleting number 28...\n");
	deleteValue(&b, 28);

	printValues(&b);


	printf("\nDeleting tree...\n");
	deleteTree(&b);
	printValues(&b);
	printf("\n\nFin");
	return 0;
}
////////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////
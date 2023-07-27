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
*			  /					       \
*			2					 		20
*			  \						  	   \
*				7							28
*									  	  /	   \
*										27		29
*								  	  /			  \
*									25				38
*
*		Height = 6	-	Node Count = 14	-	smallest = -1	-	greatest = 38	-	isBST = true
*		
*/

	insert(&b,17);
	insert(&b,18);
	insert(&b,19);
	insert(&b,20);
	insert(&b,1);
	insert(&b,8);
	insert(&b,28);
	insert(&b,27);
	insert(&b,-5);
	insert(&b,25);
	insert(&b,2);
	insert(&b,7);
	insert(&b,29);
	insert(&b,38);

	printValues(&b);
	printValuesAsTree(&b);

	printf("\nNode Count: %d\n", getNodeCount(&b));

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

	printf("\n%d\n", getLeftmostNode(b.root)->_value);	//min
	printf("%d\n", getRightmostNode(b.root)->_value);	//max
	printf("%d\n", getRightmostNode(b.root->leftChild)->_value);	//predecessor
	printf("%d\n", getLeftmostNode(b.root->rightChild->rightChild->rightChild)->_value);	//20 (no left subtree)


	printf("\nSuccessor of 17: %d\n", getSuccessor(&b,17));
	printf("Successor of 18: %d\n", getSuccessor(&b,18));
	printf("Successor of 19: %d\n", getSuccessor(&b,19));
	printf("Successor of 20: %d\n", getSuccessor(&b,20));
	printf("Successor of 25: %d\n", getSuccessor(&b,25));
	printf("Successor of 27: %d\n", getSuccessor(&b,27));
	printf("Successor of 28: %d\n", getSuccessor(&b,28));
	printf("Successor of 29: %d\n", getSuccessor(&b,29));
	printf("Successor of 38: %d\n", getSuccessor(&b,38));
	printf("Successor of 8: %d\n", getSuccessor(&b,8));
	printf("Successor of 7: %d\n", getSuccessor(&b,7));
	printf("Successor of 2: %d\n", getSuccessor(&b,2));
	printf("Successor of 1: %d\n", getSuccessor(&b,1));
	printf("Successor of -5: %d\n", getSuccessor(&b,-5));

	printf("\nPredecessor of 17: %d\n", getPredecessor(&b,17));
	printf("Predecessor of 18: %d\n", getPredecessor(&b,18));
	printf("Predecessor of 19: %d\n", getPredecessor(&b,19));
	printf("Predecessor of 20: %d\n", getPredecessor(&b,20));
	printf("Predecessor of 25: %d\n", getPredecessor(&b,25));
	printf("Predecessor of 27: %d\n", getPredecessor(&b,27));
	printf("Predecessor of 28: %d\n", getPredecessor(&b,28));
	printf("Predecessor of 29: %d\n", getPredecessor(&b,29));
	printf("Predecessor of 38: %d\n", getPredecessor(&b,38));
	printf("Predecessor of 8: %d\n", getPredecessor(&b,8));
	printf("Predecessor of 7: %d\n", getPredecessor(&b,7));
	printf("Predecessor of 2: %d\n", getPredecessor(&b,2));
	printf("Predecessor of 1: %d\n", getPredecessor(&b,1));
	printf("Predecessor of -5: %d\n", getPredecessor(&b,-5));

	printf("\nComplete tree:\n");
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

	printf("\n");
	printValuesAsTree(&b);
	printf("\nHeight: %d\n", getHeight(&b));
	printf("Min: %d\n", getMin(&b));
	printf("Max: %d\n", getMax(&b));
	printf("Es BST: %d\n", isBST(&b));


	printf("\nDeleting tree...\n");
	deleteTree(&b);
	printValues(&b);
	printf("\n\nEnd");
	return 0;
}
////////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////
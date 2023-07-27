/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Implement:
//  insert // insert value into tree
//  get_node_count // get count of values stored
//  print_values // prints the values in the tree, from min to max
//  delete_tree
//  is_in_tree // returns true if given value exists in the tree
//  get_height // returns the height in nodes (single node's height is 1)
//  get_min // returns the minimum value stored in the tree
//  get_max // returns the maximum value stored in the tree
//  is_binary_search_tree
//  delete_value
//  get_successor // returns next-higher value in tree after given value, -1 if none
///////////////////////////////////////////////////////BIBLIOTECAS///////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
/////////////////////////////////////////////////////////DEFINES/////////////////////////////////////////////////////////
#define max(x,y)	((x >= y) ? x : y)
#define MIN_IS_BST		-2147483648
#define MAX_IS_BST		2147483647
////////////////////////////////////////////////////////VARIABLES////////////////////////////////////////////////////////

///////////////////////////////////////////////////////ESTRUCTURAS///////////////////////////////////////////////////////
typedef struct BSTnode
{
	int _value;
	BSTnode *parent;
	BSTnode *leftChild;
	BSTnode *rightChild;
}BSTnode;

typedef struct BST
{
	BSTnode *root;
}BST;
/////////////////////////////////////////////////PROTOTIPOS DE FUNCIONES/////////////////////////////////////////////////
void insert(BST*/*tree*/, int/*value*/);			// insert value into tree
int getNodeCount(BST*/*tree*/);						// get count of values stored
void printValues(BST*/*tree*/);						// prints the values in the tree, from min to max
void deleteTree(BST*/*tree*/);						// delets all nodes and resets the root
bool isInTree(BST*/*tree*/, int/*value*/);			// returns true if given value exists in the tree
int getHeight(BST*/*tree*/);						// returns the height in nodes (single node's height is 1)
int getMin(BST*/*tree*/);							// returns the minimum value stored in the tree
int getMax(BST*/*tree*/);							// returns the maximum value stored in the tree
bool isBST(BST*/*tree*/);							// returns true if tree is BST, false otherwise
void deleteValue(BST*/*tree*/, int/*value*/);		// deletes node with value
int getSuccessor(BST*/*tree*/, int/*value*/);		// returns next-higher value in tree after given value, -1 if none

//AUXILIAR
void BSTinit(BST*/*tree*/);								// initialize the BST
BSTnode* createNode();									// creates a node and returns it
void preorder(BSTnode*/*root*/);						// prints values in preorder
void inorder(BSTnode*/*root*/);							// prints values in inorder
void postorder(BSTnode*/*root*/);						// prints values in postorder
void addNode(BSTnode**/*root*/, BSTnode*/*node*/);		// adds a node
void printValuesAsTree(BSTnode*/*root*/,int /*space*/);	// prints values as a tree leftshifted
void printValuesAsTree(BST*/*tree*/);					// prints values as a tree leftshifted
int getNodeCount(BSTnode*/*root*/);						// get count of values stored
void deleteTree(BSTnode*/*root*/);						// delets all nodes and resets the root
bool isInTree(BSTnode*/*root*/, int/*value*/);			// returns true if given value exists in the tree
int getHeight(BSTnode*/*root*/);						// returns the height in nodes (single node's height is 1)
int getMin(BSTnode*/*root*/);							// returns the minimum value stored in the tree
int getMax(BSTnode*/*root*/);							// returns the maximum value stored in the tree
bool isBST(BSTnode*/*root*/);							// returns true if tree is BST, false otherwise
BSTnode* searchValue(BSTnode*/*root*/, int/*value*/);	// returns pointer to node with value, NULL if not found
void deleteNode(BSTnode*/*root*/);						// delets a node in tree
BSTnode* deleteNode(BSTnode*/*root*/, int/*value*/);	// delets a node in tree
BSTnode* getLeftmostNode(BSTnode*/*root*/);				// returns pointer to leftmost node, root if leftChild = NULL
BSTnode* getRightmostNode(BSTnode*/*root*/);			// returns pointer to rightmost node, root if rightChild = NULL
int getPredecessor(BST*/*tree*/, int/*value*/);			// returns next-lower value in tree after given value,-1 if none
////////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////
//AUXILIAR
void BSTinit(BST *BSTree){
	BSTree->root = NULL;
}

BSTnode* createNode(int value){
	BSTnode *n = (struct BSTnode*)calloc(1,sizeof(BSTnode));
	n->_value = value;
	n->parent = NULL;
	n->leftChild = NULL;
	n->rightChild = NULL;
	return n;
}

void preorder(BSTnode *root){
	if (root == NULL) return;

	printf("%d ", root->_value);
	preorder(root->leftChild);
	preorder(root->rightChild);
}

void inorder(BSTnode *root){
	if (root == NULL) return;

	inorder(root->leftChild);
	//printf("This: %d - ", root);
	//printf("Value: %d - ", root->_value);
	//printf("Parent: %d - ", root->parent);
	//printf("Left Child:%d - ", root->leftChild);
	//printf("Right Child:%d\n", root->rightChild);
	printf("%d ", root->_value);
	inorder(root->rightChild);
}

void postorder(BSTnode *root){
	if (root == NULL) return;

	postorder(root->leftChild);
	postorder(root->rightChild);
	printf("%d ", root->_value);
}

void addNode(BSTnode **root, BSTnode *node){
	if (*root == NULL) {
		*root = node;
		return;
	}

	if (node->_value >= (*root)->_value) {
		addNode(&(*root)->rightChild, node);
		(*root)->rightChild->parent = *root;
	}
	else{
		addNode(&(*root)->leftChild, node);
		(*root)->leftChild->parent = *root;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////insert///////////////////////////////////////////////////
void insert(BST *BSTree, int value){
	addNode(&(BSTree->root), createNode(value));
}

//////////////////////////////////////////////printValues/////////////////////////////////////////////////
void printValues(BST *BSTree){
	if (BSTree->root == NULL) { printf("Empty tree.\n"); return;}
	//MIN to MAX
	inorder(BSTree->root);
	printf("\n");
}

void printValuesAsTree(BSTnode *root, int space){	//space should be amount of digits in the data of each node
	if (root == NULL) return;
	else{
		printValuesAsTree(root->rightChild, space+1);
		for (int i = 0; i < space; ++i){
			printf("  ");
		}
		printf("%d\n", root->_value);
		printValuesAsTree(root->leftChild,space+1);
	}
}

void printValuesAsTree(BST *BSTree){
	printValuesAsTree(BSTree->root, 0);
}
//////////////////////////////////////////////getNodeCount////////////////////////////////////////////////
int getNodeCount(BSTnode *root){
	if (root == NULL) return 0;
	return 1 + getNodeCount(root->leftChild) + getNodeCount(root->rightChild);
}

int getNodeCount(BST *BSTree){
	return getNodeCount(BSTree->root);
}

//////////////////////////////////////////////deleteTree//////////////////////////////////////////////////
void deleteTree(BSTnode *root){
	if (root == NULL) return;

	deleteTree(root->leftChild);
	deleteTree(root->rightChild);

	free(root);
}

void deleteTree(BST *BSTree){
	deleteTree(BSTree->root);
	BSTinit(BSTree);
}

////////////////////////////////////////////////isInTree//////////////////////////////////////////////////
bool isInTree(BSTnode *root, int value){
	if (root == NULL) return false;
	if (root->_value == value) return true;
	else if (root->_value > value) return isInTree(root->leftChild, value);
	else return isInTree(root->rightChild, value);
}

bool isInTree(BST *BSTree, int value){
	// NON RECURSIVE (1st IDEA)
	// BSTnode *aux = BSTree->root;
	
	// while(aux){
	// 	if (aux->_value == value) return true;
	// 	if (aux->leftChild == NULL && aux->rightChild == NULL) return false;
	// 	if (aux->_value > value) aux = aux->leftChild;
	// 	if (aux->_value < value) aux = aux->rightChild;
	// }

	// return false;

	return isInTree(BSTree->root, value);
}

////////////////////////////////////////////////getHeight/////////////////////////////////////////////////
int getHeight(BSTnode *root){
	if (root == NULL) return -1;

	int leftHeight = getHeight(root->leftChild);
	int rightHeight = getHeight(root->rightChild);

	return 1 + max(leftHeight,rightHeight);
}

int getHeight(BST *BSTree){
	return getHeight(BSTree->root);
}

/////////////////////////////////////////////////getMin///////////////////////////////////////////////////
int getMin(BSTnode *root){
	if (root->leftChild == NULL) return root->_value;
	return getMin(root->leftChild);
}

int getMin(BST *BSTree){
	//NON RECURSIVE (1ST IDEA)
	// BSTnode *aux = BSTree->root;

	// while(aux->leftChild != NULL){
	// 	aux = aux->leftChild;
	// }

	// return aux->_value;

	return getMin(BSTree->root);
}

/////////////////////////////////////////////////getMax///////////////////////////////////////////////////
int getMax(BSTnode *root){
	if (root->rightChild == NULL) return root->_value;
	return getMax(root->rightChild);
}

int getMax(BST *BSTree){
	//NON RECURSIVE (1ST IDEA)
	// BSTnode *aux = BSTree->root;

	// while(aux->rightChild != NULL){
	// 	aux = aux->rightChild;
	// }

	// return aux->_value;

	return getMax(BSTree->root);
}

/////////////////////////////////////////////////isBST////////////////////////////////////////////////////
bool isBST(BSTnode *root, int max, int min){
	if (root == NULL) return true;
	if (root->_value > min && root->_value < max
		&& isBST(root->leftChild, root->_value, min)
		&& isBST(root->rightChild, max, root->_value))
		return true;
	else return false;
}

bool isBST(BST *BSTree){
	return isBST(BSTree->root, MAX_IS_BST, MIN_IS_BST);
}

///////////////////////////////////////////////deleteValue////////////////////////////////////////////////
BSTnode* searchValue(BSTnode *root, int value){

	while (root != NULL){
		if (root->_value == value) return root;
		if (root->_value > value) root = root->leftChild;
		else root = root->rightChild;
	}

	return root;
}

BSTnode* getLeftmostNode(BSTnode *root){
	if (root->leftChild == NULL) return root;
	return getLeftmostNode(root->leftChild);
}

BSTnode* getRightmostNode(BSTnode *root){
	if (root->rightChild == NULL) return root;
	return getRightmostNode(root->rightChild);
}

void deleteNode(BSTnode *root){
	if (root == NULL) return;

	BSTnode *aux;
	//LEAF
	if (root->leftChild == NULL && root->rightChild == NULL){

		//Find if leaf is right or left child to erase pointer in parent
		if (root->parent->leftChild == root) root->parent->leftChild = NULL;	// If its left child 	
		else root->parent->rightChild = NULL;									// If its right child
		
		free(root);
		root = NULL;
	}

	//ONE CHILD
	else if (root->leftChild != NULL && root->rightChild == NULL){		// If it has left child
		//1st IDEA (Non recursive, constant time)
		aux = root->leftChild;											// Save adress to delete copy
		root->leftChild->parent = root->parent;							// Change child's parent pointer

		// Change parent's child pointer
		if (root->parent->leftChild == root) root->parent->leftChild = aux;	
		else root->parent->rightChild = aux;
		
		root = root->leftChild;											// Overwrite root as its child

		free(aux);														// Free the original child (now copied in parent)
		root = NULL;
		// 2nd IDEA (Recursive until leaf node, O(n) -> n = number of leftChildren in each node)
		//root->_value = root->leftChild->_value;
		//deleteNode(root->leftChild);
	}

	else if (root->rightChild != NULL && root->leftChild == NULL){		// If it has right child
		
		aux = root->rightChild;											// Save adress to delete copy
		root->rightChild->parent = root->parent;						// Change child's parent pointer

		// Change parent's child pointer
		if (root->parent->leftChild == root) root->parent->leftChild = aux;	
		else root->parent->rightChild = aux;

		root = root->rightChild;										// Overwrite root as its child

		free(aux);														// Free the original child (now copied in parent)
		aux = NULL;
	}
	
	//TWO CHILDREN
	else if(root->leftChild != NULL && root->rightChild != NULL){
		aux = getLeftmostNode(root->rightChild);						// Gets leftmost child of its rightChild
		root->_value = aux->_value;										// Replace current node value with the leftmost
		deleteNode(aux);												// delete the node that got copied
	}
}

// Recursive version after internet research
BSTnode* deleteNode(BSTnode *root, int value){
	if (root == NULL) return root;
	else if (value < root->_value) root->leftChild = deleteNode(root->leftChild, value);
	else if (value > root->_value) root->rightChild = deleteNode(root->rightChild, value);
	else {
		//Leaf node
		if (root->leftChild == NULL && root->rightChild == NULL){
			free(root);
			root = NULL;
		}
		//1 child
		else if (root->leftChild == NULL){
			BSTnode *aux = root;
			root->rightChild->parent = root->parent;
			root = root->rightChild;
			free(aux);
		}
		else if (root->rightChild == NULL){
			BSTnode *aux = root;
			root->leftChild->parent = root->parent;
			root = root->leftChild;
			free(aux);
		}
		//2 children
		else{
			BSTnode *aux = getLeftmostNode(root->rightChild);
			root->_value = aux->_value;
			root->rightChild = deleteNode(root->rightChild, aux->_value);
		}

	}
	return root;
}

void deleteValue(BST *BSTree, int value){
	deleteNode(BSTree->root, value);
	//deleteNode(searchValue(BSTree->root, value));
}

//////////////////////////////////////////////getSuccessor////////////////////////////////////////////////
int getSuccessor(BST* BSTree, int value){
	//If it's the max number there's no successor
	if (getMax(BSTree->root) == value) return -1;

	BSTnode *aux = searchValue(BSTree->root,value);

	//If it doesn't exist there's no successor
	if (aux == NULL) return -1;

	//Has right subtree
	if (aux->rightChild != NULL) return getLeftmostNode(aux->rightChild)->_value;

	//Doesn't have right subtree
	else if (aux->rightChild == NULL){
		BSTnode *temp = aux;
		
		while(temp->_value <= value){
			temp = temp->parent;
		}

		return temp->_value;

		//NO PARENT POINTER VERSION (from internet)
		/*
		BSTnode *succesor = NULL;
		BSTnode *ancestor = root;
		while(ancestor != aux){
			if (aux->_value < ancestor->_value){
				succesor = ancestor;
				ancestor = ancestor->leftChild;
			}
			else{
				ancestor = ancestor->rightChild;
			}
		}

		if (succesor == NULL) return -1;
		else return succesor;
		*/
	}
}

/////////////////////////////////////////////getPredecessor///////////////////////////////////////////////
int getPredecessor(BST* BSTree, int value){
	//If it's the min number there's no predecessor
	if (getMin(BSTree->root) == value) return -1;

	BSTnode *aux = searchValue(BSTree->root,value);

	//If it doesn't exist there's no predecessor
	if (aux == NULL) return -1;

	//Has left child
	if (aux->leftChild != NULL) return getRightmostNode(aux->leftChild)->_value;

	//Doesn't have left child
	else if (aux->leftChild == NULL){
		BSTnode *temp = aux;
		
		while(temp->_value >= value){
			temp = temp->parent;
		}

		return temp->_value;
	}
}
///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////
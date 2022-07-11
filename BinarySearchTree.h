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
//  get_successor // returns next-highest value in tree after given value, -1 if none
///////////////////////////////////////////////////////BIBLIOTECAS///////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
/////////////////////////////////////////////////////////DEFINES/////////////////////////////////////////////////////////
#define max(x,y)	((x > y) ? x : y)
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
BSTnode* getSuccessor(BST*/*tree*/, int/*value*/);	// returns next-highest value in tree after given value, -1 if none

//AUXILIAR
void BSTinit(BST*/*tree*/);							// initialize the BST
BSTnode *createNode();								// creates a node and returns it
void preorder(BSTnode*/*root*/);					// prints values in preorder
void inorder(BSTnode*/*root*/);						// prints values in inorder
void postorder(BSTnode*/*root*/);					// prints values in postorder
void addNode(BSTnode**/*root*/, BSTnode*/*node*/);	// adds a node
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

	printf("%d - ", root->_value);
	preorder(root->leftChild);
	preorder(root->rightChild);
}

void inorder(BSTnode *root){
	if (root == NULL) return;

	inorder(root->leftChild);
	printf("%d ", root->_value);
	inorder(root->rightChild);
}

void postorder(BSTnode *root){
	if (root == NULL) return;

	postorder(root->leftChild);
	postorder(root->rightChild);
	printf("%d - ", root->_value);
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

//////////////////////////////////////////////////////////
void insert(BST *BSTree, int value){
	addNode(&(BSTree->root), createNode(value));
}

void printValues(BST *BSTree){
	if (BSTree->root == NULL) { printf("Empty tree.\n"); return;}
	//MIN to MAX
	inorder(BSTree->root);
	printf("\n");
}

int getNodeCount(BSTnode *root){
	if (root == NULL) return 0;
	return 1 + getNodeCount(root->leftChild) + getNodeCount(root->rightChild);
}

int getNodeCount(BST *BSTree){
	return getNodeCount(BSTree->root);
}

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

bool isInTree(BSTnode *root, int value){
	if (root == NULL) return false;
	if (root->_value == value) return true;
	else if (root->leftChild == NULL && root->rightChild == NULL) return false;
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

int getHeight(BSTnode *root){
	if (root == NULL) return -1;

	int leftHeight = getHeight(root->leftChild);
	int rightHeight = getHeight(root->rightChild);

	return 1 + max(leftHeight,rightHeight);
}

int getHeight(BST *BSTree){
	return getHeight(BSTree->root);
}

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
///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////
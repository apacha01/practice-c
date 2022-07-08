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
void deleteTree(BST*/*tree*/);
bool isInTree(BST*/*tree*/, int/*value*/);			// returns true if given value exists in the tree
int getHeight(BST*/*tree*/);						// returns the height in nodes (single node's height is 1)
int getMin(BST*/*tree*/);							// returns the minimum value stored in the tree
int getMax(BST*/*tree*/);							// returns the maximum value stored in the tree
bool isBST(BST*/*tree*/);
void deleteValue(BST*/*tree*/, int/*value*/);
BSTnode* getSuccessor(BST*/*tree*/, int/*value*/);	// returns next-highest value in tree after given value, -1 if none

//AUXILIAR
void BSTinit(BST*/*tree*/);							// initialize the BST
BSTnode *createNode();								// creates a node and returns it
void preorder(BSTnode*/*root*/);					// prints values in preorder
void inorder(BSTnode*/*root*/);						// prints values in inorder
void postorder(BSTnode*/*root*/);					// prints values in postorder
void addNode(BSTnode**/*root*/, BSTnode*/*node*/);	// adds a node
int countNodes(BST*/*root*/);						// returns count of nodes
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
	printf("This: %x - ", root);
	printf("Value: %d - ", root->_value);
	printf("Parent: %x - ", root->parent);
	printf("Left Child: %x - ", root->leftChild);
	printf("Right Child: %x\n", root->rightChild);
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

int countNodes(BSTnode *root){
	if (root == NULL) return 0;
	return 1 + countNodes(root->leftChild) + countNodes(root->rightChild);
}

//////////////////////////////////////////////////////////
void insert(BST *BSTree, int value){
	addNode(&(BSTree->root), createNode(value));
}

void printValues(BST *BSTree){
	//MIN to MAX
	inorder(BSTree->root);
}

int getNodeCount(BST *BSTree){
	return countNodes(BSTree->root);
}
///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////
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
	if (root->rightChild != NULL) printf("%d - ", root->_value);
	else { printf("%d\n", root->_value); }
	inorder(root->rightChild);
}

void postorder(BSTnode *root){
	if (root == NULL) return;

	postorder(root->leftChild);
	postorder(root->rightChild);
	printf("%d - ", root->_value);
}
//////////////////////////////////////////////////////////
void insert(BST *BSTree, int value){
	if (BSTree->root == NULL) {
		BSTree->root = createNode(value);
	}
	else {
		if (value >= BSTree->root->_value) {	//TO THE RIGHT
			printf("added to right subtree\n");
		}
		else { //TO THE LEFT
			printf("added to left subtree\n");
		}
	}
}

void printValues(BST *BSTree){
	//MIN to MAX
	inorder(BSTree->root);
}



///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////
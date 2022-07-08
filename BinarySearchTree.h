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
void insert(BST*/*root*/, int/*value*/);			// insert value into tree
int get_node_count(BST*/*root*/);					// get count of values stored
void print_values(BST*/*root*/);					// prints the values in the tree, from min to max
void delete_tree(BST*/*root*/);
bool is_in_tree(BST*/*root*/, int/*value*/);		// returns true if given value exists in the tree
int get_height(BST*/*root*/);						// returns the height in nodes (single node's height is 1)
int get_min(BST*/*root*/);							// returns the minimum value stored in the tree
int get_max(BST*/*root*/);							// returns the maximum value stored in the tree
bool is_binary_search_tree(BST*/*root*/);
void delete_value(BST*/*root*/, int/*value*/);
BSTnode* get_successor(BST*/*root*/, int/*value*/);	// returns next-highest value in tree after given value, -1 if none

//AUXILIAR
void BSTinit(BST*/*root*/);							// initialize the BST
BSTnode *createNode();								// creates a node and returns it
////////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////
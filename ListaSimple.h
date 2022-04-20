/*
Implement (I did with tail pointer & without):
	size() - returns number of data elements in list
	empty() - bool returns true if empty
	value_at(index) - returns the value of the nth item (starting at 0 for first)
	push_front(value) - adds an item to the front of the list
	pop_front() - remove front item and return its value
	push_back(value) - adds an item at the end
	pop_back() - removes end item and returns its value
	front() - get value of front item
	back() - get value of end item
	insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
	erase(index) - removes node at given index
	value_n_from_end(n) - returns the value of the node at nth position from the end of the list
	reverse() - reverses the list
	remove_value(value) - removes the first item in the list with this value
*/
///////////////////////////////////////////////////////BIBLIOTECAS///////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
/////////////////////////////////////////////////////////DEFINES/////////////////////////////////////////////////////////

///////////////////////////////////////////////////////ESTRUCTURAS///////////////////////////////////////////////////////
struct SLinkedList
{
	int size;
	int *head;
};

struct SListNode
{
	int value;
	SListNode *next;
};
/////////////////////////////////////////////////PROTOTIPOS DE FUNCIONES/////////////////////////////////////////////////
int	size();									// Devuelve el numero de elementos en la lista.
bool empty();								// Devuelve true si esta vacía la lista, caso contrario false.
int	valueAt(int/*n*/);						// Devuelve el valor del nodo numero n, contando desde 0.
void pushFront(int/*valor*/);				// Agrega un nodo al principio de la lista.
int popFront();								// Elimina nodo del inicio y devuelve el valor.
void pushBack(int/*valor*/);				// Agrega un nodo al final de la lista.
int popBack();								// Elimina nodo del final y devuelve el valor.
int front();								// Devuelve el valor del primer nodo.
int back();									// Devuelve el valor del último nodo.
void insert(int/*índice*/, int/*valor*/);	// Inserta valor en índice, por lo que el nodo actual es apuntado por el nodo nuevo.
void erase(int/*índice*/);					// Remueve el nodo en índice.
int valueNfromEnd(int/*n*/);				// Devuelve el valor del nodo numero n, contando desde el último nodo.
void reverse();								// Invierte la lista.
void removeValue(int/*valor*/);				// Elimina el primer nodo con el valor.
////////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////

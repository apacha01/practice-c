////////////////////////////////////////////////////////CONSIGNAS////////////////////////////////////////////////////////
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
	int _size;
	struct SListNode *head;
};

struct SListNode
{
	int _value;
	SListNode *next;
};
/////////////////////////////////////////////////PROTOTIPOS DE FUNCIONES/////////////////////////////////////////////////
//CONSIGNAS
int	size(struct SLinkedList*);									// Devuelve el numero de elementos en la lista.
bool empty(struct SLinkedList*);								// Devuelve true si esta vacía la lista, caso contrario false.
int	valueAt(struct SLinkedList*, int/*índice*/);				// Devuelve el valor del nodo en índice, contando desde 0.
void pushFront(struct SLinkedList*, int/*valor*/);				// Agrega un nodo al principio de la lista.
int popFront(struct SLinkedList*);								// Elimina nodo del inicio y devuelve el valor.
void pushBack(struct SLinkedList*, int/*valor*/);				// Agrega un nodo al final de la lista.
int popBack(struct SLinkedList*);								// Elimina nodo del final y devuelve el valor.
int front(struct SLinkedList*);									// Devuelve el valor del primer nodo.
int back(struct SLinkedList*);									// Devuelve el valor del último nodo.
void insert(struct SLinkedList*, int/*índice*/, int/*valor*/);	// Inserta valor en índice, por lo que el nodo actual es apuntado por el nodo nuevo.
void erase(struct SLinkedList*, int/*índice*/);					// Remueve el nodo en índice.
int valueNfromEnd(struct SLinkedList*, int/*índice*/);			// Devuelve el valor del nodo en índice, contando desde el último nodo.
void reverse(struct SLinkedList*);								// Invierte la lista.
void removeValue(struct SLinkedList*, int/*valor*/);			// Elimina el primer nodo con el valor.

//AUXILIARES
void init(struct SLinkedList*);
void incrementSize(struct SLinkedList*);
void decrementSize(struct SLinkedList*);

////////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////
//AUXILIARES
void init(struct SLinkedList *l){
	l->head = NULL;
	l->_size = 0;
}

void incrementSize(struct SLinkedList *l){
	l->_size++;
}

void decrementSize(struct SLinkedList *l){
	l->_size--;
}

//CONSIGNAS
int size(struct SLinkedList *l){
	return l->_size;
}

bool empty(struct SLinkedList *l){
	return l->_size <= 0;
}

int valueAt(struct SLinkedList *l, int index){
	struct SListNode *aux;
	struct SListNode *aux2;
	aux = l->head;

	for (int i = 0; i < index; i++) {
		l->head = l->head->next;
	}

	aux2 = l->head;
	l->head = aux;

	return aux2->_value;
}

void pushFront(struct SLinkedList *l, int value){
	struct SListNode *n = (struct SListNode*)calloc(1,sizeof(SListNode));
	if (empty(l)) {
		n->_value = value;
		n->next = NULL;
	}
	else{
		n->next = l->head;
		n->_value = value;
	}
	l->head = n;
	incrementSize(l);
}

int popFront(struct SLinkedList *l){
	int aux;
	struct SListNode *aux2;
	
	aux2 = l->head;
	aux = l->head->_value;
	l->head = l->head->next;

	free(aux2);			//Libero el respacio reservado en pushFront;
	decrementSize(l);
	return aux;
}

void pushBack(struct SLinkedList *l, int value){
	struct SListNode *aux;
	struct SListNode *n = (struct SListNode*)calloc(1,sizeof(SListNode));
	
	aux = l->head;

	while(l->head != NULL){
		l->head = l->head->next;
	}

	l->head = n;
	n->next = NULL;
	n->_value = value;

	l->head = aux;
}

int popBack(struct SLinkedList *l){

}

///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////

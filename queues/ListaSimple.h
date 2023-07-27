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
	struct SListNode *tail;
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
	l->tail = NULL;
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
	
	if (index < 0 || index >= size(l)) {
		printf("\nNOP\n");
		return -1;
	}
	
	struct SListNode *aux;
	
	aux = l->head;

	for (int i = 0; i < index; i++) {
		aux = aux->next;
	}

	return aux->_value;
}

void pushFront(struct SLinkedList *l, int value){
	struct SListNode *n = (struct SListNode*)calloc(1,sizeof(SListNode));
	if (empty(l)) {
		n->next = NULL;
		l->tail = n;
	}
	else{
		n->next = l->head;
	}

	n->_value = value;
	l->head = n;
	incrementSize(l);
}

int popFront(struct SLinkedList *l){
	
	if (empty(l)) {
		printf("\nNOP\n");
		return 0;
	}

	int aux;
	struct SListNode *aux2;
	
	aux2 = l->head;
	aux = l->head->_value;
	l->head = l->head->next;
	if (size(l) == 2){
		l->tail = l->head;
	}

	free(aux2);
	decrementSize(l);
	return aux;
}

void pushBack(struct SLinkedList *l, int value){
	struct SListNode *n = (struct SListNode*)calloc(1,sizeof(SListNode));

	if (empty(l)) {
		l->head = n;
		l->tail = n;
	}
	else {
		l->tail->next = n;
		l->tail = l->tail->next;
	}

	n->next = NULL;
	n->_value = value;
	incrementSize(l);
}

int popBack(struct SLinkedList *l){
	if (empty(l)) {
		printf("\nNOP\n");
		return 0;
	}

	struct SListNode *aux;
	int aux2;
	aux = l->head;
	aux2 = l->tail->_value;

	if(size(l) >= 1){
		for (int i = 0; i < size(l)-2; i++) {
			aux = aux->next;
		}
		l->tail = aux;
		aux = aux->next;
	}

	free(aux);
	decrementSize(l);
	return aux2;
}

int front(struct SLinkedList *l){
	return l->head->_value;
}

int back(struct SLinkedList *l){
	return l->tail->_value;
}

void insert(struct SLinkedList *l, int index, int value){
	struct SListNode *aux;
	aux = l->head;

	if (index < 0 || index >= size(l)) {
		printf("\nNOP\n");
	}
	else if (index == 0) {
		pushFront(l,value);
	}
	else if(index == size(l)-1){
		pushBack(l,value);
	}
	else {
		for (int i = 0; i < index-1; i++) {
			aux = aux->next;
		}
		struct SListNode *n = (struct SListNode*)calloc(1,sizeof(SListNode));
		n->_value = value;
		n->next = aux->next;
		aux->next = n;
		incrementSize(l);
	}
}

void erase(struct SLinkedList *l, int index){
	struct SListNode *aux;
	struct SListNode *aux2;
	aux = l->head;

	if (index < 0 || index >= size(l)) {
		printf("\nNOP\n");
	}
	else if (index == 0) {
		popFront(l);
	}
	else if(index == size(l)-1){
		popBack(l);
	}
	else {
		for (int i = 0; i < index-1; i++) {
			aux = aux->next;
		}
		aux2 = aux->next;
		aux->next = aux->next->next;

		free(aux2);
		decrementSize(l);
	}
}

int valueNfromEnd(struct SLinkedList *l, int index){
	int valueNfromHead;
	valueNfromHead = size(l) - index - 1;

	if (index < 0 || index >= size(l)) {
		printf("\nNOP\n");
	}
	else if (index == 0){
		return l->tail->_value;
	}
	else {
		return valueAt(l,valueNfromHead);
	}

	return -1;
}

void reverse(struct SLinkedList *l){
	for (int i = 0; i < size(l)-1; i++) {
		pushFront(l,valueAt(l,i+1));
		erase(l,i+2);
	}
}

void removeValue(struct SLinkedList *l, int value){
	struct SListNode *aux;
	aux = l->head;

	for (int i = 0; i < size(l)-1; i++) {
		if (aux->_value == value) {
			erase(l,i);
			break;
		}
		aux = aux->next;
	}
}
///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////

/*
Implement using linked-list, with tail pointer:
	enqueue(value) - adds value at position at tail
	dequeue() - returns value and removes least recently added element (front)
	empty()
Implement using fixed-sized array:
	enqueue(value) - adds item at end of available storage
	dequeue() - returns value and removes least recently added element
	empty()
	full()
Cost:
	a bad implementation using linked list where you enqueue at head and dequeue at tail would be O(n) because you'd need the next to last element, causing a full traversal each dequeue
	enqueue: O(1) (amortized, linked list and array [probing])
	dequeue: O(1) (linked list and array)
	empty: O(1) (linked list and array)
*/
///////////////////////////////////////////////////////BIBLIOTECAS///////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "ListaSimple.h"
/////////////////////////////////////////////////////////DEFINES/////////////////////////////////////////////////////////

////////////////////////////////////////////////////////VARIABLES////////////////////////////////////////////////////////

///////////////////////////////////////////////////////ESTRUCTURAS///////////////////////////////////////////////////////
typedef struct
{
	struct SLinkedList sl;
} Queue;
/////////////////////////////////////////////////PROTOTIPOS DE FUNCIONES/////////////////////////////////////////////////
//CONSIGNA
void enqueue(Queue*, int value);	//Agrega valor al final de la lista. 
int dequeue(Queue*);				//Elimina y devuelve el valor primer valor agregado.
bool emptyQueue(Queue*);			//Devuelve true si esta vacía la fila.

//AUXILIARES
void initQueue(Queue*);				//Inicializo.

////////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////
//AUXILIARES
void initQueue(Queue *q){
	init(&q->sl);
}

void enqueue(Queue *q, int value){
	pushBack(&q->sl, value);
}

int dequeue(Queue *q){
	return popFront(&q->sl);
}

bool emptyQueue(Queue *q){
	return empty(&q->sl);
}
///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////
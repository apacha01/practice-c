/*
 Implement a vector (mutable array with automatic resizing):
 	Practice coding using arrays and pointers, and pointer math to jump to an index instead of using indexing.
 	New raw data array with allocated memory can allocate int array under the hood, just not use its features start with 
 	16,	or if starting number is greater, use power of 2 - 16, 32, 64, 128
		size() - number of items
		capacity() - number of items it can hold
		is_empty()
		at(index) - returns item at given index, blows up if index out of bounds
		push(item)
		insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
		prepend(item) - can use insert above at index 0
		pop() - remove from end, return value
		delete(index) - delete item at index, shifting all trailing elements left
		remove(item) - looks for value and removes index holding it (even if in multiple places)
		find(item) - looks for value and returns first index with that value, -1 if not found
		resize(new_capacity) // private function
			when you reach capacity, resize to double the size
			when popping an item, if size is 1/4 of capacity, resize to half
 Time
	O(1) to add/remove at end (amortized for allocations for more space), index, or update
	O(n) to insert/remove elsewhere
 Space
	contiguous in memory, so proximity helps performance
	space needed = (array capacity, which is >= n) * size of item, but even if 2n, still O(n)
*/
//////////////////////////////////////////////////BIBLIOTECAS////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
//////////////////////////////////////////////////DEFINES////////////////////////////////////////////////////////////////
#define resizeFactor 2
//////////////////////////////////////////////////VARIABLES GLOBALES/////////////////////////////////////////////////////
struct Vector
{
	int *p;
	int *_size;
	int *_capacity;
};
//////////////////////////////////////////////////PROTOTIPOS DE FUNCIONES////////////////////////////////////////////////
//DE LAS CONSIGNAS
int size(struct Vector *);									//Devuelve size
int capacity(struct Vector *);								//Devuelve capacity
bool isEmpty(struct Vector*);								//true si esta vacio, false si no.
int at(struct Vector*, int/*índice*/);						//Devuelve el valor en índice.
void push(struct Vector*, int */*vector*/, int/*valor*/);	//Inserta valor al final del array.
void insert(int/*indice*/, int/*valor*/);	//Inserta valor en índice y mueve los valores que le sigan a la derecha.
void prepend(int/*valor*/);					//Inserta valor al inicio del array.
int pop();									//Elimina el último valor y lo devuelve.
void erase(int/*índice*/);					//Elimina valor en índice y mueve los valores siguientes a la izquierda.
void removeAll(int/*valor*/);				//Elimina todas las coincidencias de valor.
int find(int/*valor*/);						//Busca valor y devuelve el primer índice que coincida. -1 si no encuentra.
void resize(int/*nueva capacidad*/);		//Cambia el tamaño del array.

//AUXILIARES
void allocateMemory(struct Vector*, int/*capacidad*/);		//Reserva el espacio en memoria para el array.
void incrementSize(struct Vector*);
/////////////////////////////////////////////////FUNCIONES///////////////////////////////////////////////////////////////
//AUXILIARES
void allocateMemory(struct Vector *v, int capacity){
	v->p = (int *)malloc(capacity);
	v->_size = (v->p)-1;
	v->_size = (v->p)-2;

	*v->_size = 0;
	*v->_capacity = (int)capacity;
}

void incrementSize(struct Vector *v){
	*v->_size += 1;
}

//DE LAS CONSIGNAS
int size(struct Vector *v){
	return *v->_size;
}

int capacity(struct Vector *v){
	return *v->_capacity;
}

bool isEmpty(struct Vector *v){
	return *v->_size == 0;
}

int at(struct Vector *v, int index){
	return *((v->p)+index);
}

void push(struct Vector *v, int item){
	*((v->p)+*v->_size) = item;
	incrementSize(v);
}
/////////////////////////////////////////////////FIN PROGRAMA////////////////////////////////////////////////////////////















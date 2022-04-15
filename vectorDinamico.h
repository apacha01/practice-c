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
#define initalLengthArr 16
#define resizeFactor 2
//////////////////////////////////////////////////VARIABLES GLOBALES/////////////////////////////////////////////////////
int _size = 0, _capacity = 0;
//////////////////////////////////////////////////PROTOTIPOS DE FUNCIONES////////////////////////////////////////////////
int	size();									//Devuelve el tamaño del array.
int capacity();								//Devuelve la máxima capacidad del array.
bool isEmpty();								//true si esta vacio, false si no.
int at(int /*índice*/);						//Devuelve el valor en índice.
void push(int/*valor*/);					//Inserta valor al final del array.
void insert(int/*indice*/, int/*valor*/);	//Inserta valor en índice y mueve los valores que le sigan a la derecha.
void prepend(int/*valor*/);					//Inserta valor al inicio del array.
int pop();									//Elimina el último valor y lo devuelve.
void erase(int/*índice*/);					//Elimina valor en índice y mueve los valores siguientes a la izquierda.
void removeAll(int/*valor*/);				//Elimina todas las coincidencias de valor.
int find(int/*valor*/);						//Busca valor y devuelve el primer índice que coincida. -1 si no encuentra.
void resize(int/*nueva capacidad*/);		//Crea nuevo array con nueva capacidad y devuelve el puntero al nuevo array.
/////////////////////////////////////////////////FUNCIONES///////////////////////////////////////////////////////////////

/////////////////////////////////////////////////FIN PROGRAMA////////////////////////////////////////////////////////////















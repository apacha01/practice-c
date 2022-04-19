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
#define initialLength 16
//////////////////////////////////////////////////VARIABLES GLOBALES/////////////////////////////////////////////////////
struct Vector
{
	int *p;
	int *_size;
	int *_capacity;
};
//////////////////////////////////////////////////PROTOTIPOS DE FUNCIONES////////////////////////////////////////////////
//DE LAS CONSIGNAS
int size(struct Vector*);									//Devuelve size
int capacity(struct Vector*);								//Devuelve capacity
bool isEmpty(struct Vector*);								//true si esta vacio, false si no.
int at(struct Vector*, int/*índice*/);						//Devuelve el valor en índice.
void push(struct Vector*, int*/*vector*/, int/*valor*/);	//Inserta valor al final del array.
void insert(struct Vector*, int/*indice*/, int/*valor*/);	//Inserta valor en índice y mueve los valores que le sigan a la derecha.
void prepend(struct Vector*, int/*valor*/);					//Inserta valor al inicio del array.
int pop(struct Vector*);									//Elimina el último valor y lo devuelve.
void erase(struct Vector*, int/*índice*/);					//Elimina valor en índice y mueve los valores siguientes a la izquierda.
void removeAll(struct Vector*, int/*valor*/);				//Elimina todas las coincidencias de valor.
int find(struct Vector*, int/*valor*/);						//Busca valor y devuelve el primer índice que coincida. -1 si no encuentra.
void resize(struct Vector*, int/*nueva capacidad*/);		//Cambia el tamaño del array.
void init(struct Vector*);									//Inicializa el vector dinámico (reserva el espacio en memoria).

//AUXILIARES
void incrementSize(struct Vector*);							//Incrementa size y resize si es necesario.
void decrementSize(struct Vector*);							//Decrementa size y resize si es necesario.
void moveTo(struct Vector*, int, char);						//Mueve hacia izq o der (para insert y delete).
void ownRealloc(struct Vector*, int /*nueva capacidad*/);	//Mismo objetivo que realloc pero propia.
/////////////////////////////////////////////////FUNCIONES///////////////////////////////////////////////////////////////
//AUXILIARES
void init(struct Vector *v){
	v->p = (int *)calloc(initialLength,sizeof(int));
	v->_size = (v->p)-1;
	v->_capacity = (v->p)-2;

	*v->_size = 0;
	*v->_capacity = initialLength;
}

void incrementSize(struct Vector *v){
	*v->_size += 1;
	if (size(v) == capacity(v)) {
		resize(v,(capacity(v)*resizeFactor));
	}
}

void decrementSize(struct Vector *v){
	*v->_size -= 1;
	if (size(v) == (capacity(v)/4)) {
		resize(v,(capacity(v)/resizeFactor));
	}
}

void moveTo(struct Vector *v, int index, char c){
	if (c == 'r') {
		for (int i = size(v); i > index; i--) {
			*(v->p + i) = *(v->p + i-1);
		}
	}
	if (c == 'l') {
		for (int i = index; i < size(v) - 1; i++) {
			*(v->p + i) = *(v->p + i + 1);
		}
	}
}

void ownRealloc(struct Vector *v, int newCapacity){
	struct Vector vCpy = *v;
	v->p = (int *)calloc(newCapacity, sizeof(int));
	for (int i = 0; i < size(&vCpy); i++) {
		*(v->p+i) = *(vCpy.p+i);
	}
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
	*((v->p)+size(v)) = item;
	incrementSize(v);
}

void insert(struct Vector *v, int index, int item){
	moveTo(v,index,'r');
	*(v->p + index) = item;
	incrementSize(v);
}

void prepend(struct Vector *v, int item){
	insert(v,0,item);
}

int pop(struct Vector *v){
	int a = *(v->p+size(v)-1);
	*(v->p + size(v) - 1) = 0;
	decrementSize(v);
	return a;
}

void erase(struct Vector *v, int index){
	moveTo(v,index,'l');
	decrementSize(v);
}

void removeAll(struct Vector *v, int item){
	for (int i = 0; i < size(v); i++)
	{
		if (*(v->p+i) == item)
		{
			erase(v,i);
			if (i > 0) {
				i -= 2;
			}
		}
	}
}

int find(struct Vector *v, int item){
	for (int i = 0; i < size(v); i++) {
		if (*(v->p + i) == item)
		{
			return i;
		}
	}
	return -1;
}

void resize(struct Vector *v, int newCapacity){
	*v->_capacity = newCapacity;
	ownRealloc(v,newCapacity);
}
/////////////////////////////////////////////////FIN PROGRAMA////////////////////////////////////////////////////////////















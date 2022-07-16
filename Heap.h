/*
*Implement a max-heap:
* insert
* sift_up // needed for insert
* get_max // returns the max item, without removing it
* get_size() // return number of elements stored
* is_empty() // returns true if heap contains no elements
* extract_max // returns the max item, removing it
* sift_down // needed for extract_max
* remove(x) // removes item at index x
* heapify // create a heap from an array of elements, needed for heap_sort
* heap_sort() // take an unsorted array and turn it into a sorted array in-place using a max heap or min heap
*/
///////////////////////////////////////////////////////BIBLIOTECAS///////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"
/////////////////////////////////////////////////////////DEFINES/////////////////////////////////////////////////////////
#define max(x,y)	((x >= y) ? x : y)

////////////////////////////////////////////////////////VARIABLES////////////////////////////////////////////////////////

///////////////////////////////////////////////////////ESTRUCTURAS///////////////////////////////////////////////////////
typedef struct Heap
{
	Vector arr;
}Heap;

/////////////////////////////////////////////////PROTOTIPOS DE FUNCIONES/////////////////////////////////////////////////
void insert(Heap*, int/*value*/);
void siftUp(Heap*, int/*index*/);		// needed for insert
void getMax(Heap*);						// returns the max item, without removing it
int getSize(Heap*);						// return number of elements stored
bool isEmpty(Heap*);					// returns true if heap contains no elements
int extractMax(Heap*);					// returns the max item, removing it
void siftDown(Heap*, int/*index*/);		// needed for extract_max
void remove(Heap*, int/*index*/);		// removes item at index
void heapify(Heap*);					// create a heap from an array of elements, needed for heap_sort
void heapsort(Heap*);					// take unsorted array and sort it in-place using max or min heap
void heapsort(int*);					// take unsorted array and sort it in-place using max or min heap
//////////////////////////////////////////////////////////Main///////////////////////////////////////////////////////////

////////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////
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
typedef struct MaxHeap
{
	Vector arr;
}MaxHeap;

/////////////////////////////////////////////////PROTOTIPOS DE FUNCIONES/////////////////////////////////////////////////
void insert(MaxHeap*, int/*value*/);
void siftUp(MaxHeap*, int/*index*/);		// needed for insert
void getMax(MaxHeap*);						// returns the max item, without removing it
int getSize(MaxHeap*);						// return number of elements stored
bool isEmpty(MaxHeap*);						// returns true if heap contains no elements
int extractMax(MaxHeap*);					// returns the max item, removing it
void siftDown(MaxHeap*, int/*index*/);		// needed for extract_max
void remove(MaxHeap*, int/*index*/);		// removes item at index
void heapify(MaxHeap*);						// create a heap from an array of elements, needed for heap_sort
void heapsort(MaxHeap*);					// take unsorted array and sort it in-place using max or min heap
void heapsort(int*);						// take unsorted array and sort it in-place using max or min heap

//AUXILIAR
int parent(int/*index*/);					// returns index of parent of i
int leftChild(int/*index*/);				// returns index of left child of i
int rightChils(int/*index*/);				// reutnrs index of right child of i
//////////////////////////////////////////////////////////Main///////////////////////////////////////////////////////////

////////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////
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
void heapsort(MaxHeap*);					// takes a maxheap and sorts it in-place using max or min heap
void heapsort(int*);						// takes unsorted array and sorts it in-place using max or min heap

//AUXILIAR
void maxHeapInit(MaxHeap*);					// initialize the heap
int parent(int/*index*/);					// returns index of parent of i
int leftChild(int/*index*/);				// returns index of left child of i
int rightChild(int/*index*/);				// returns index of right child of i
void printHeap(MaxHeap*);					// prints heap
////////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////
void maxHeapInit(MaxHeap* heap){
	init(&heap->arr);
}

int parent(int i){
	// Using index 0
	return (i%2 == 0) ? (i/2)-1 : i/2;
}

int leftChild(int i){
	// Using index 0
	return (2*i)+1;
}

int rightChild(int i){
	// Using index 0
	return (2*i)+2;
}

void printHeap(MaxHeap* h){
	for (int i = 0; i < getSize(&h->arr); ++i){
		printf("Posicion [%d]: %d\n", i, valueAt(&h->arr, i));
	}
}
/////////////////////////////////////insert/////////////////////////////////////
void insert(MaxHeap* heap, int value){
	push(&heap->arr, value);

	siftUp(heap, getSize(&heap->arr)-1);	// siftUp if necessary
}

/////////////////////////////////////siftUp/////////////////////////////////////
void siftUp(MaxHeap* heap, int index){
	int parentIndex = parent(index);
	int parentValue = valueAt(&heap->arr, parentIndex);
	int actualValue = valueAt(&heap->arr, index);

	//			get value at parents index					compare with value
	if (parentValue < actualValue && parentIndex >= 0 && parentIndex < index){
		changeValue(&heap->arr, index, parentValue);
		changeValue(&heap->arr, parentIndex, actualValue);
		siftUp(heap, parentIndex);
	}
}
/////////////////////////////////////getMax/////////////////////////////////////

////////////////////////////////////getSize/////////////////////////////////////

////////////////////////////////////isEmpty/////////////////////////////////////

///////////////////////////////////extractMax///////////////////////////////////

////////////////////////////////////siftDown////////////////////////////////////

/////////////////////////////////////remove/////////////////////////////////////

////////////////////////////////////heapify/////////////////////////////////////

////////////////////////////////////heapsort////////////////////////////////////


///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////
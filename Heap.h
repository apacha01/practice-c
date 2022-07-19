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
int getMax(MaxHeap*);						// returns the max item, without removing it
int getSize(MaxHeap*);						// return number of elements stored
bool isEmpty(MaxHeap*);						// returns true if heap contains no elements
int extractMax(MaxHeap*);					// returns the max item, removing it
void siftDown(MaxHeap*, int/*index*/);		// needed for extract_max
void remove(MaxHeap*, int/*index*/);		// removes item at index
void heapify(int*);							// create a heap from an array of elements, needed for heap_sort
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
	return (i-1)/2;
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
	// insert at last index
	push(&heap->arr, value);

	// siftUp if necessary
	siftUp(heap, getSize(&heap->arr)-1);
}

/////////////////////////////////////siftUp/////////////////////////////////////
void siftUp(MaxHeap* heap, int index){
	int parentIndex = parent(index);
	int parentValue = valueAt(&heap->arr, parentIndex);
	int actualValue = valueAt(&heap->arr, index);

	// base case
	if (parentValue > actualValue) return;

	//  compare parent with child	check index to avoid index out of bounds errors
	if (parentValue < actualValue && parentIndex >= 0 && parentIndex < index){
		changeValue(&heap->arr, index, parentValue);
		changeValue(&heap->arr, parentIndex, actualValue);
		siftUp(heap, parentIndex);
	}
}

/////////////////////////////////////getMax/////////////////////////////////////
int getMax(MaxHeap *h){
	return valueAt(&h->arr, 0);
}

////////////////////////////////////getSize/////////////////////////////////////
int getSize(MaxHeap *h){
	return getSize(&h->arr);
}

////////////////////////////////////isEmpty/////////////////////////////////////
bool isEmpty(MaxHeap *h){
	return isEmpty(&h->arr);
}

///////////////////////////////////extractMax///////////////////////////////////
int extractMax(MaxHeap *h){
	int aux = getMax(h);

	// put last value at index 0
	changeValue(&h->arr, 0, valueAt(&h->arr, getSize(h)-1));
	
	// delete last value
	pop(&h->arr);

	// siftDown if necessary
	siftDown(h, 0);

	return aux;
}

////////////////////////////////////siftDown////////////////////////////////////
void siftDown(MaxHeap *h, int index){
	int actual = valueAt(&h->arr, index);
	int leftChildIndex = leftChild(index);
	int rightChildIndex = rightChild(index);
	int leftChildValue = valueAt(&h->arr, leftChildIndex);
	int rightChildValue = valueAt(&h->arr, rightChildIndex);
	
	// get child with greater value
	int maxChild = max(leftChildValue, rightChildValue);

	// base case, return when it has no children
	if (leftChildIndex < 0 && leftChildIndex >= getSize(h) &&
		rightChildIndex < 0 && rightChildIndex >= getSize(h)) return;

	// when its greater than its children stop going down
	if (actual > leftChildValue && actual > rightChildValue) return;

	// if left child is bigger or equal change with it and siftDown again
	if (maxChild == leftChildValue){
		changeValue(&h->arr, index, leftChildValue);
		changeValue(&h->arr, leftChildIndex, actual);
		siftDown(h, leftChildIndex);
	}
	// if right child is bigger change with it and siftDown again
	else if(maxChild == rightChildValue){
		changeValue(&h->arr, index, rightChildValue);
		changeValue(&h->arr, rightChildIndex, actual);
		siftDown(h, rightChildIndex);
	}
	// error (one has to be bigger or equal than the other)
	else printf("ERROR.\n");
}

/////////////////////////////////////remove/////////////////////////////////////
void remove(MaxHeap *h, int index){

	// put last value at index
	changeValue(&h->arr, index, valueAt(&h->arr, getSize(h)-1));

	// delete last value
	pop(&h->arr);

	// siftDown if necessary

	// -1 cause i poped the last item before, so if it wants to remove last
	//	item then index is out of bounds
	if (index == getSize(h)) siftDown(h, index-1);
	else siftDown(h, index);

}

////////////////////////////////////heapify/////////////////////////////////////
void heapify(int *arr, int size, int index){
	int leftChildIndex = leftChild(index);
	int rightChildIndex = rightChild(index);
	int largest = index;

	//	if index is within arr 		if left child is greater tha parent
	if (leftChildIndex < size && *(arr+leftChildIndex) > *(arr+largest))
		largest = leftChildIndex;

	//	if index is within arr 		if right child is greater tha parent
	if (rightChildIndex < size && *(arr+rightChildIndex) > *(arr+largest))
		largest = rightChildIndex;

	if (largest != index){
		int aux = *(arr+index);
		*(arr+index) = *(arr+largest);
		*(arr+largest) = aux;
		heapify(arr, size, largest);
	}
}

////////////////////////////////////heapsort////////////////////////////////////
void heapsort(int *arr, int size){
	int aux;

	for (int i = (size/2) - 1; i >= 0; i--){
		heapify(arr, size, i);
	}

	for (int i = size-1; i >= 0; i--){
		aux = *arr;
		*arr = *(arr + i);
		*(arr + i) = aux;
		heapify(arr, i, 0);
	}

}

///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////
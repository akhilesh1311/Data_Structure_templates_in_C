#include<stdio.h>

enum heapType{
	MIN_HEAP,MAX_HEAP
};

//typedef int (*compare)(void *,void *);

struct heap{
	int capacity;
	int count;
	void **array;
	enum heapType type;
	size_t size;							//size of each element
	int (*compare)(void *,void *);	//note: return a-b only, not b-a
};

/*
example of compare function:

int fun (void *a, void *b){
	return (((struct element*)a)->data - ((struct element*)b)->data);
}
*/

struct heap* createHeap(size_t size, enum heapType type, int (*compare)(void *,void *));
int getParent(struct heap* h, int i);
int getLeftChild(struct heap* h,int i);
int getRightChild(struct heap* h,int i);
void * getMaximum(struct heap *h);
void * getMinimum(struct heap *h);
void maxHeapify(struct heap *h,int i);
void minHeapify(struct heap *h,int i);
void resizeHeap(struct heap *h);
int searchHeap(struct heap *h,void* key, int (*equal)(void *, void*));
void buildHeap(struct heap *h,void **A,int n);
void heapSort(struct heap *h,void **A,int n);
void* heapExtractMax(struct heap *h);
void* heapExtractMin(struct heap *h);
void heapIncreaseKey(struct heap *h,int i,void* key);
void heapDecreaseKey(struct heap *h,int i,void* key);
void heapInsert(struct heap *h,void* key, void* min, void* max);
void destroyHeap(struct heap *h);

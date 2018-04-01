#include<stdio.h>
#include<stdlib.h>
#define INT_MIN -32767
#define INT_MAX 32767

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

struct heap* createHeap(size_t size, enum heapType type, int (*compare)(void *,void *)){
	struct heap *h=(struct heap *)malloc(sizeof(struct heap));
	if(h==NULL){
		printf("not enough memory to allocate heap\n");
		return;
	}
	h->type=type;
	h->compare=compare;
	h->count=0;
	h->size=size;
	h->capacity=1;
	h->array=(void **)malloc(h->size*h->capacity);
	if(h->array==NULL){
		printf("not enough memory to allocate array of heap\n");
		return;
	}
	return h;
}

int getParent(struct heap* h, int i){				//same for minHeap and maxHeap
	if(i<=0 || i>h->count){
		return -1;
	}
	return (i-1)/2;
}

int getLeftChild(struct heap* h,int i){			//same for minHeap and maxHeap
	int left=2*i+1;
	if(left>=h->count){
		return -1;
	}
	return left;
}

int getRightChild(struct heap* h,int i){			//same for minHeap and maxHeap
	int right=2*i+2;
	if(right>=h->count){
		return -1;
	}
	return right;
}

void * getMaximum(struct heap *h){						//only for maxHeap
	if(h->count==0){
		printf("array is already empty\n");
		return NULL;
	}
	if(h->type != MAX_HEAP){
		printf("sorry this operation is valid only for maxHeap\n");
		return NULL;
	}
	return h->array[0];
}

void * getMinimum(struct heap *h){						//only for minHeap
	if(h->count==0){
		printf("array is already empty\n");
		return NULL;
	}
	if(h->type != MIN_HEAP){
		printf("sorry this operation is valid only for minHeap\n");
		return NULL;
	}
	return h->array[0];
}

void maxHeapify(struct heap *h,int i){
	if(h==NULL){
		printf("please care to create heap before calling heapify\n");
		return;
	}
	if(h->type != MAX_HEAP){
		printf("doing maxHeapify on a minHeap..God help you\n");
		return;
	}

	int l=getLeftChild(h,i);
	int r=getRightChild(h,i);
	int largest;
	void *temp;
//	if(l<=h->count && l>=0 && h->array[l]>h->array[i]){
	if(l<=h->count && l>=0 && (h->compare(h->array[l], h->array[i]) > 0)){
		largest=l;
	}else{
		largest=i;
	}
//	if(r<=h->count && r>=0 && h->array[r]>h->array[largest]){
	if(r<=h->count && r>=0 && (h->compare(h->array[r],h->array[largest]) > 0)){
		largest=r;
	}
	if(largest!=i){
		temp=h->array[i];
		h->array[i]=h->array[largest];
		h->array[largest]=temp;
		maxHeapify(h,largest);
	}
}

void minHeapify(struct heap *h,int i){
	if(h==NULL){
		printf("please care to create heap before calling heapify\n");
		return;
	}
	if(h->type != MIN_HEAP){
		printf("doing minHeapify on a maxHeap..God help you\n");
		return;
	}

	int l=getLeftChild(h,i);
	int r=getRightChild(h,i);
	int smallest;
	void *temp;
//	if(l<=h->count && l>=0 && h->array[l]<h->array[i]){
	if(l<=h->count && l>=0 && (h->compare(h->array[l],h->array[i]) < 0)){
		smallest=l;
	}else{
		smallest=i;
	}
//	if(r<=h->count && r>=0 && h->array[r]<h->array[smallest]){
	if(r<=h->count && r>=0 && (h->compare(h->array[r],h->array[smallest]) < 0)){
		smallest=r;
	}
	if(smallest!=i){
		temp=h->array[i];
		h->array[i]=h->array[smallest];
		h->array[smallest]=temp;
		minHeapify(h,smallest);
	}
}


void resizeHeap(struct heap *h){
	void **array_old=h->array;
	int i;
	h->array=(void **)malloc(2*h->capacity*h->size);
	if(h->array==NULL){
		printf("sorry,can't increase the size of array\n");
		return;
	}
	for(i=0;i<h->capacity;i++){
		h->array[i]=array_old[i];
	}
	h->capacity=h->capacity*2;
	free(array_old);
}

/*
equal function can be:
int equal (void *, void *){
	return (((struct element*)a)->data == ((struct element*)b)->data);
}
*/

int searchHeap(struct heap *h,void* key, int (*equal)(void *, void*)){				//This search is a linear time search of O(n)
	int i=0,flag=0;																				//TODO make a heapSearch with tighter upper bound, and return all the 
	while(i<h->count){																			//elements instead of one, with the matching key value	
//		if(h->array[i]==key){
		if(equal(h->array[i],key)){
			flag=1;
			return i;
		}
		i++;
	}
	return -1;
}

void buildHeap(struct heap *h,void **A,int n){
	int i;
	if (h->type == MAX_HEAP) {
		if(!h){
			printf("create a heap first before passing it blindly\n");
			return;
		}
		while(n>h->capacity){
			resizeHeap(h);
		}
		for(i=0;i<n;i++){
			h->array[i]=A[i];
		}
		h->count=n;
		for(i=(h->count/2)-1;i>=0;i--){
			maxHeapify(h,i);
		}		
	} else if (h->type == MIN_HEAP) {
		if(!h){
			printf("create a heap first before passing it blindly\n");
			return;
		}
		while(n>h->capacity){
			resizeHeap(h);
		}
		for(i=0;i<n;i++){
			h->array[i]=A[i];
		}
		h->count=n;
		for(i=(h->count/2)-1;i>=0;i--){
			minHeapify(h,i);
		}		
	}
}

void heapSort(struct heap *h,void **A,int n){		//After building the heap, heapsort for MAX_HEAP places the largest element in the 
	int i;															//end so sorts in ascending order sorted data in h->array
	void *temp;
	if(h->type == MAX_HEAP){
		buildHeap(h,A,n);
		for(i=h->count-1;i>0;i--){
			temp=h->array[0];
			h->array[0]=h->array[i];
			h->array[i]=temp;
			h->count--;
			maxHeapify(h,0);
		}
	} else if (h->type == MIN_HEAP) {		//heapsort for MIN_HEAP places the smallest data in the end
		buildHeap(h,A,n);						//so sorts in descending order in h->array
		for(i=h->count-1;i>0;i--){
			temp=h->array[0];
			h->array[0]=h->array[i];
			h->array[i]=temp;
			h->count--;
			minHeapify(h,0);
		}	
	}
}

void* heapExtractMax(struct heap *h){
	void *max;
	if(h->count<1){
		printf("somethings wrong---heap underflow\n");
		return NULL;
	}
	if(h->type != MAX_HEAP){
		printf("sorry this operation is valid only for maxHeap\n");
		return NULL;
	}
	max=h->array[0];
	h->array[0]=h->array[h->count-1];
	h->count--;
	maxHeapify(h,0);
	return max;
}

void* heapExtractMin(struct heap *h){
	void* min;
	if(h->count<1){
		printf("somethings wrong---heap underflow\n");
		return NULL;
	}
	if(h->type != MIN_HEAP){
		printf("sorry this operation is valid only for minHeap\n");
		return NULL;
	}		
	min=h->array[0];
	h->array[0]=h->array[h->count-1];
	h->count--;
	minHeapify(h,0);
	return min;
}

void heapIncreaseKey(struct heap *h,int i,void* key){
	void* temp;
	if(h->type == MAX_HEAP){
		if((h->compare(h->array[i], key)) > 0){
			printf("LOLOLOL---the new key is lesser than the current key---can't increase\n");
			return;
		}
		h->array[i]=key;
		while(i>0 && (h->compare(h->array[getParent(h,i)], h->array[i]) < 0)){
			temp=h->array[getParent(h,i)];
			h->array[getParent(h,i)]=h->array[i];
			h->array[i]=temp;
			i=getParent(h,i);
		}		
	} else if (h->type == MIN_HEAP) {
		if(h->compare(h->array[i], key) > 0){
			printf("LOLOLOL---the new key is less than the current key---can't increase\n");
			return;
		}
		h->array[i]=key;
		minHeapify(h,i);		
	}
}

void heapDecreaseKey(struct heap *h,int i,void* key){
	void* temp;
	if (h->type == MIN_HEAP) {
		if(h->compare(h->array[i], key) < 0){
			printf("LOLOLOL---the new key is more than the current key---can't decrease\n");
			return;
		}
		h->array[i]=key;
		while(i>0 && (h->compare(h->array[getParent(h,i)], h->array[i]) > 0)){
			temp=h->array[getParent(h,i)];
			h->array[getParent(h,i)]=h->array[i];
			h->array[i]=temp;
			i=getParent(h,i);
		}		
	} else if (h->type == MAX_HEAP) {
		if(h->compare(h->array[i], key) < 0){
			printf("LOLOLOL---the new key is more than the current key---can't decrease\n");
			return;
		}
		h->array[i]=key;
		maxHeapify(h,i);		
	}
}

void heapInsert(struct heap *h,void* key, void* min, void* max){
	if(h->type == MAX_HEAP){
		if(h->count==h->capacity){
			resizeHeap(h);
		}
		h->count++;
		h->array[h->count-1]=min;
		heapIncreaseKey(h,h->count-1,key);
	} else if (h->type == MIN_HEAP) {
		if(h->count==h->capacity){
			resizeHeap(h);
		}
		h->count++;
		h->array[h->count-1]=min;
		heapDecreaseKey(h,h->count-1,key);		
	}
}

void destroyHeap(struct heap *h){
	if(h!=NULL){
		if(h->array!=NULL){
			free(h->array);
			if(h->array==NULL){
				printf("hehehaha---heap array destroyed successfully\n");
			}
//			h->array=NULL;
		}
		free(h);
		if(h==NULL){
			printf("hohohuhu---heap destroyed successfully\n");
		}
//		h=NULL;
	}
}

/*
int cmp (void *a, void *b) {
	return ((((struct element*)a)->a) - (((struct element*)b)->a));
}

int equal (void *a, void *b) {
//	return ((((struct element*)a)->b) == (((struct element*)b)->b));
	return ((((struct element*)a)->b) == *(char*)b);
}

int main(){

}
*/

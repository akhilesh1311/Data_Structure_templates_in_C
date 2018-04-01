#include<stdio.h>
#include<stdlib.h>
#define INT_MIN -32767
#define INT_MAX 32767

enum heapType{
	MIN_HEAP,MAX_HEAP
};

struct heap{
	int capacity;
	int count;
	int *array;
	enum heapType type;
};

int heapExtractMax(struct heap *h);

struct heap* createHeap(int capacity,enum heapType type){
	struct heap *h=(struct heap *)malloc(sizeof(struct heap));
	if(h==NULL){
		printf("not enough memory to allocate heap\n");
		return;
	}
	h->type=type;
	h->count=0;
	h->capacity=capacity;
	h->array=(int *)malloc(sizeof(int)*capacity);
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

int getMaximum(struct heap *h){						//only for maxHeap
	if(h->count==0){
		return -1;
	}
	if(h->type != MAX_HEAP){
		printf("sorry this operation is valid only for maxHeap\n");
		return -1;
	}
	return h->array[0];
}

int getMinimum(struct heap *h){						//only for minHeap
	if(h->count==0){
		return -1;
	}
	if(h->type != MIN_HEAP){
		printf("sorry this operation is valid only for minHeap\n");
		return -1;
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
	int largest,temp;
	if(l<=h->count && l>=0 && h->array[l]>h->array[i]){
		largest=l;
	}else{
		largest=i;
	}
	if(r<=h->count && r>=0 && h->array[r]>h->array[largest]){
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
	int smallest,temp;
	if(l<=h->count && l>=0 && h->array[l]<h->array[i]){
		smallest=l;
	}else{
		smallest=i;
	}
	if(r<=h->count && r>=0 && h->array[r]<h->array[smallest]){
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
	int *array_old=h->array;
	int i;
	h->array=(int *)malloc(2*h->capacity*sizeof(int));
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

int searchHeap(struct heap *h,int key){				//This search is a linear time search of O(n)
	int i=0,flag=0;												//TODO make a heapSearch with tighter upper bound
	while(i<h->count){
		if(h->array[i]==key){
			flag=1;
			return i;
		}
		i++;
	}
	return -1;
}

void buildHeap(struct heap *h,int *A,int n){
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

void heapSort(struct heap *h,int *A,int n){		//After building the heap, heapsort for MAX_HEAP places the largest element in the 
	int i,temp;												//end so sorts in ascending order sorted data in h->array
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

int heapExtractMax(struct heap *h){
	int max;
	if(h->count<1){
		printf("somethings wrong---heap underflow\n");
		return INT_MIN;
	}
	if(h->type != MAX_HEAP){
		printf("sorry this operation is valid only for maxHeap\n");
		return INT_MIN;
	}
	max=h->array[0];
	h->array[0]=h->array[h->count-1];
	h->count--;
	maxHeapify(h,0);
	return max;
}

int heapExtractMin(struct heap *h){
	int min;
	if(h->count<1){
		printf("somethings wrong---heap underflow\n");
		return INT_MIN;
	}
	if(h->type != MIN_HEAP){
		printf("sorry this operation is valid only for minHeap\n");
		return INT_MIN;
	}		
	min=h->array[0];
	h->array[0]=h->array[h->count-1];
	h->count--;
	minHeapify(h,0);
	return min;
}

void heapIncreaseKey(struct heap *h,int i,int key){
	int temp;
	if(h->type == MAX_HEAP){
		if(key<h->array[i]){
			printf("LOLOLOL---the new key is lesser than the current key---can't increase\n");
			return;
		}
		h->array[i]=key;
		while(i>0 && h->array[getParent(h,i)]<h->array[i]){
			temp=h->array[getParent(h,i)];
			h->array[getParent(h,i)]=h->array[i];
			h->array[i]=temp;
			i=getParent(h,i);
		}		
	} else if (h->type == MIN_HEAP) {
		if(key<h->array[i]){
			printf("LOLOLOL---the new key is less than the current key---can't increase\n");
			return;
		}
		h->array[i]=key;
		minHeapify(h,i);		
	}
}

void heapDecreaseKey(struct heap *h,int i,int key){
	int temp;
	if (h->type == MIN_HEAP) {
		if(key>h->array[i]){
			printf("LOLOLOL---the new key is more than the current key---can't decrease\n");
			return;
		}
		h->array[i]=key;
		while(i>0 && h->array[getParent(h,i)]>h->array[i]){
			temp=h->array[getParent(h,i)];
			h->array[getParent(h,i)]=h->array[i];
			h->array[i]=temp;
			i=getParent(h,i);
		}		
	} else if (h->type == MAX_HEAP) {
		if(key>h->array[i]){
			printf("LOLOLOL---the new key is more than the current key---can't decrease\n");
			return;
		}
		h->array[i]=key;
		maxHeapify(h,i);		
	}
}

void heapInsert(struct heap *h,int key){
	if(h->type == MAX_HEAP){
		if(h->count==h->capacity){
			resizeHeap(h);
		}
		h->count++;
		h->array[h->count-1]=INT_MIN;
		heapIncreaseKey(h,h->count-1,key);
	} else if (h->type == MIN_HEAP) {
		if(h->count==h->capacity){
			resizeHeap(h);
		}
		h->count++;
		h->array[h->count-1]=INT_MAX;
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

int main(){
	enum heapType type = MIN_HEAP;
	struct heap *h1 = createHeap(1,type); 
	int a[]={203,1,10,55,45,99,105};
	buildHeap(h1,a,7);
	heapInsert(h1,700);
	heapInsert(h1,9);
	heapIncreaseKey(h1,2,102);
	int b[]={439,12,432,96,420,52,4};
	destroyHeap(h1);
	h1 = createHeap(1,type); 
	heapSort(h1,b,7);
	printf("%d ",h1->array[0]);
	printf("%d ",h1->array[1]);
	printf("%d ",h1->array[2]);
	printf("%d ",h1->array[3]);
	printf("%d ",h1->array[4]);
	printf("%d ",h1->array[5]);
	printf("%d ",h1->array[6]);
	printf("%d ",h1->array[7]);
	printf("%d ",h1->array[8]);
	printf("%d ",searchHeap(h1,2));
	
}

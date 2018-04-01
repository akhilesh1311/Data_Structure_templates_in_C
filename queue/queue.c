#include<stdio.h>
#include<stdlib.h>
#define INT_MIN -5000

struct arrayQueue{
	int front,rear;
	int capacity;
	int *array;
};

struct arrayQueue* createQueue(){
	struct arrayQueue *q=(struct arrayQueue*)malloc(sizeof(struct arrayQueue));
	if(q==NULL){
		printf("not enough memory for queue\n");
		return NULL;
	}
	q->capacity=2;
	q->front=-1;
	q->rear=0;
	q->array=(int *)malloc(sizeof(int)*q->capacity);
	if(q->array==NULL){
		printf("not enough memory for array\n");
		return NULL;
	}
	return q;
}

int isQueueEmpty(struct arrayQueue *q){
	if(q->front==-1){
		return 1;
	}else{
		return 0;
	}
}

int isQueueFull(struct arrayQueue *q){
	if(q->front == (q->rear + 1)%q->capacity){
		return 1;
	}else{
		return 0;
	}
}

void resizeQueue(struct arrayQueue *q){
	int size;
	size_t s;
	size=q->capacity;
	q->capacity=q->capacity*2;
	s = sizeof(int)*q->capacity;
	printf("jai %d\n",q->capacity);
	q->array=(int *)realloc(q->array,s);
	if(q->front>=q->rear){
		int i;
		for(i=0;i<q->rear;i++){
			q->array[i+size]=q->array[i];
		}
		q->rear=q->rear + size;
	}
}

int queueSize(struct arrayQueue *q){
	if(q->front == -1){
		return 0;
	}else if(q->rear>q->front){
		return (q->rear-q->front);
	}else{
		return (q->capacity-(q->front-q->rear));
	}
}

void enQueue(struct arrayQueue *q, int data){
	if(isQueueFull(q)){
		printf("Queue overflow\n");
		resizeQueue(q);
	}
	q->array[q->rear]=data;
	q->rear=(q->rear+1)%q->capacity;
	if(q->front==-1){
		q->front=0;
	}
}

int deQueue(struct arrayQueue *q){
	if(isQueueEmpty(q)){
		printf("already queue is empty\n");
		return INT_MIN;
	}else{
		int data;
		data=q->array[q->front];
		q->front=(q->front+1)%q->capacity;
		if(q->front==q->rear){
			q->front = -1;
			q->rear = 0;
		}
		return data;
	}
}

void deleteQueue(struct arrayQueue *q){
	if(q!=NULL){
		if(q->array!=NULL){
			free(q->array);
		}
		free(q);
	}
}

int main(){
	int i;
	struct arrayQueue *q;
	q=createQueue();
	printf("shiv %d %d\n",q->front,q->rear);
	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,0);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,1);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,2);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,3);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,4);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	
	printf("shiv top %d %d %d\n",q->front,q->rear,deQueue(q));

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}

	printf("shiv top %d %d %d\n",q->front,q->rear,deQueue(q));

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}

	printf("shiv top %d %d %d\n",q->front,q->rear,deQueue(q));

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}

	printf("shiv top %d %d %d\n",q->front,q->rear,deQueue(q));

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}

	printf("shiv top %d %d %d\n",q->front,q->rear,deQueue(q));

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}

	printf("shiv top %d %d %d\n",q->front,q->rear,deQueue(q));

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}

	printf("shiv top %d %d %d\n",q->front,q->rear,deQueue(q));

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}

	
	enQueue(q,5);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,6);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,7);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,8);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,9);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,10);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,11);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,12);
	printf("shiv %d %d\n",q->front,q->rear);
	
	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,13);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,14);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,15);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,16);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,17);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,18);
	printf("shiv %d %d\n",q->front,q->rear);

	printf("shiv top %d %d %d\n",q->front,q->rear,deQueue(q));

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}

	printf("shiv top %d %d %d\n",q->front,q->rear,deQueue(q));

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}

	printf("shiv top %d %d %d\n",q->front,q->rear,deQueue(q));

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}

	printf("shiv top %d %d %d\n",q->front,q->rear,deQueue(q));

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}

	printf("shiv top %d %d %d\n",q->front,q->rear,deQueue(q));

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,18);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,19);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,20);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,21);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,22);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,23);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,24);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,25);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,26);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,27);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,28);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,29);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,30);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,31);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,32);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,33);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,34);
	printf("shiv %d %d\n",q->front,q->rear);

	for(i=0;i<q->capacity;i++){
		printf("himalaya %d\n",q->array[i]);
	}
	enQueue(q,35);
	printf("shiv %d %d\n",q->front,q->rear);

}

#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
/*
struct arrayQueue{
	int front,rear;
	int capacity;
	void **array;
	size_t size;		//size of each element
};*/

struct arrayQueue* createQueue(size_t size){
	struct arrayQueue *q=(struct arrayQueue*)malloc(sizeof(struct arrayQueue));
	if(q==NULL){
		printf("not enough memory for queue\n");
		return NULL;
	}
	q->capacity=2;
	q->front=-1;
	q->rear=0;
	q->size=size;
	q->array=(void **)malloc(size*q->capacity);
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
	s = q->size*q->capacity;
	q->array=(void **)realloc(q->array,s);
	if(q->front>=q->rear){
		int i;
		for(i=0;i<q->rear;i++){
			q->array[(i+size)*q->size]=q->array[i*q->size];
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

void enQueue(struct arrayQueue *q, void *data){
	if(isQueueFull(q)){
//		printf("Queue overflow\n");
		resizeQueue(q);
	}
	q->array[q->rear*q->size]=data;
	q->rear=(q->rear+1)%q->capacity;
	if(q->front==-1){
		q->front=0;
	}
}

void* deQueue(struct arrayQueue *q){
	if(isQueueEmpty(q)){
		printf("already queue is empty\n");
		return NULL;
	}else{
		void* data;
		data=q->array[q->front*q->size];
		q->front=(q->front+1)%q->capacity;
		if(q->front==q->rear){
			q->front = -1;
			q->rear = 0;
		}
		return data;
	}
}

void* peep(struct arrayQueue *q){
	if(isQueueEmpty(q)){
		printf("already queue is empty\n");
		return NULL;
	} else {
		void* data;
		data = q->array[q->front*q->size];
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
/*
struct element{
	int a;
	char b;
	struct element *next;
};


int main(){
	struct arrayQueue *q = createQueue(sizeof(struct element));
	struct element *e1 = (struct element *)malloc(sizeof(struct element));
	e1->a=1;
	e1->b='a';
	e1->next = NULL;
	struct element *e2 = (struct element *)malloc(sizeof(struct element));
	e2->a=2;
	e2->b='b';
	e2->next = NULL;
	struct element *e3 = (struct element *)malloc(sizeof(struct element));
	e3->a=3;
	e3->b='c';
	e3->next = NULL;
	struct element *e4 = (struct element *)malloc(sizeof(struct element));
	e4->a=4;
	e4->b='d';
	e4->next = NULL;
	enQueue(q,e1);
	enQueue(q,e2);
	enQueue(q,e3);
	enQueue(q,e1);
	struct element *temp = (struct element *)malloc(sizeof(struct element));
	temp = (struct element *)deQueue(q);
	printf("%d ",temp->a);
	temp = (struct element *)deQueue(q);
	printf("%d ",temp->a);
	temp = (struct element *)deQueue(q);
	printf("%d ",temp->a);
	temp = (struct element *)deQueue(q);
	printf("%d ",temp->a);

}
*/

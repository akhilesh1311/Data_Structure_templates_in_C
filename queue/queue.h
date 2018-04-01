#include<stdio.h>

struct arrayQueue{
	int front,rear;
	int capacity;
	void **array;
	size_t size;		//size of each element
};

struct arrayQueue* createQueue(size_t size);
int isQueueEmpty(struct arrayQueue *q);
int isQueueFull(struct arrayQueue *q);
void resizeQueue(struct arrayQueue *q);
int queueSize(struct arrayQueue *q);
void enQueue(struct arrayQueue *q, void *data);
void* deQueue(struct arrayQueue *q);
void* peep(struct arrayQueue *q);
void deleteQueue(struct arrayQueue *q);

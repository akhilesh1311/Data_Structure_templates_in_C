/** THIS ARRAY BASED STACK DOUBLES EVERYTIME ITS CAPACITY IS REACHED
*	When empty---top=-1
*	when full---top=capacity-1
*	initially theres only 1 element in array
*	top=topmost occupied element
*	APIs:
*	
*/

#include<stdio.h>
#include<stdlib.h>
#define INT_MIN -3200

struct Dynamic_generic_stack{
	int capacity;
	int top;
	void **array;			//an array of void pointers
	size_t size;			//size of each element
};

struct Dynamic_generic_stack *createStack(size_t size){
	struct Dynamic_generic_stack *new=(struct Dynamic_generic_stack *)malloc(sizeof(struct Dynamic_generic_stack));
	
	if(new==NULL){
		printf("can't create stack...memory full\n");
		return NULL;
	}
	new->capacity=1;
	new->top=-1;
	new->array=(void **)malloc(size*1);
	new->size=size;
	
	if(new->array==NULL){
		printf("can't create stack...memory full\n");
		return NULL;
	}
	return new;
}


int isStackFull(struct Dynamic_generic_stack * S){
	if(S->capacity-1==S->top){
		return 1;
	}else{
		return 0;
	}
}

int isStackEmpty(struct Dynamic_generic_stack *S){
	if(S->top==-1){
		return 1;
	}else{
		return 0;
	}
}

void doubleStack(struct Dynamic_generic_stack *S){
	S->capacity=S->capacity*2;
	S->array=(void **)realloc(S->array,S->capacity * S->size);	//notice this realloc function has eased a lot of things, which i don't really use much
	if(S->array==NULL){
		printf("stack doubling failed\n");
	}
}

void push(struct Dynamic_generic_stack *S,void* x){
	if(isStackFull(S)){
		doubleStack(S);
	}
	S->top++;
	S->array[S->top*S->size]=x;
}

void* top(struct Dynamic_generic_stack *S){
	if(isStackEmpty(S)){
		printf("oops stack empty...can't print top\n");
		return NULL;
	}
	return S->array[S->top*S->size];
}

void* pop(struct Dynamic_generic_stack *S){
	if(isStackEmpty(S)){
		printf("oops stack empty...can't pop top\n");
		return NULL;
	}
	void* temp;
	temp=S->array[S->top*S->size];
	S->top--;
	return temp;
}

void deleteStack(struct Dynamic_generic_stack *S){
	if(S!=NULL){
		if(S->array!=NULL){
			free(S->array);
		}
		free(S);
	}
}

/*
int main(){
	return 0;
}
*/

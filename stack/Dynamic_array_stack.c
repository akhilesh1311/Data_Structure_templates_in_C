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

struct Dynamic_array_stack{
	int capacity;
	int top;
	int *array;
};

struct Dynamic_array_stack *createStack();
int isStackFull(struct Dynamic_array_stack * S);
int isStackEmpty(struct Dynamic_array_stack *S);
void doubleStack(struct Dynamic_array_stack *S);
void push(struct Dynamic_array_stack *S,int x);
int top(struct Dynamic_array_stack *S);
int pop(struct Dynamic_array_stack *S);
void deleteStack(struct Dynamic_array_stack *S);

struct Dynamic_array_stack *createStack(){
	struct Dynamic_array_stack *new=(struct Dynamic_array_stack *)malloc(sizeof(struct Dynamic_array_stack));
	
	if(new==NULL){
		printf("can't create stack...memory full\n");
		return NULL;
	}
	new->capacity=1;
	new->top=-1;
	new->array=(int *)malloc(sizeof(int));
	
	if(new->array==NULL){
		printf("can't create stack...memory full\n");
		return NULL;
	}
	return new;
}

int isStackFull(struct Dynamic_array_stack * S){
	if(S->capacity-1==S->top){
		return 1;
	}else{
		return 0;
	}
}

int isStackEmpty(struct Dynamic_array_stack *S){
	if(S->top==-1){
		return 1;
	}else{
		return 0;
	}
}

void doubleStack(struct Dynamic_array_stack *S){
	S->capacity=S->capacity*2;
	S->array=(int *)realloc(S->array,S->capacity);				//notice this realloc function has eased a lot of things, which i don't really use much
	if(S->array==NULL){
		printf("stack doubling failed\n");
	}
}

void push(struct Dynamic_array_stack *S,int x){
	if(isStackFull(S)){
		doubleStack(S);
	}
	S->top++;
	S->array[S->top]=x;
}

int top(struct Dynamic_array_stack *S){
	if(isStackEmpty(S)){
		printf("oops stack empty...can't print top\n");
		return INT_MIN;
	}
	return S->array[S->top];
}

int pop(struct Dynamic_array_stack *S){
	if(isStackEmpty(S)){
		printf("oops stack empty...can't pop top\n");
		printf("here i am\n");
		return INT_MIN;
	}
	int temp;
	temp=S->array[S->top];
	S->top--;
	return temp;
}

void deleteStack(struct Dynamic_array_stack *S){
	if(S!=NULL){
		if(S->array!=NULL){
			free(S->array);
		}
		free(S);
	}
}

int main(){
	struct Dynamic_array_stack* s=createStack();
	printf("pon pon---%d\n",isStackFull(s));
	printf("pon pon---%d\n",isStackEmpty(s));
	push(s,3);
	push(s,5);
	push(s,7);
	push(s,9);
	printf("ass ass---%d\n",pop(s));
	printf("ass ass---%d\n",pop(s));
	printf("ass ass---%d\n",pop(s));
	printf("ass ass---%d\n",pop(s));
	printf("ass ass---%d\n",pop(s));
	printf("ass ass---%d\n",pop(s));
	printf("ass ass---%d\n",pop(s));
	printf("ass ass---%d\n",pop(s));
	printf("boob boob---%d\n",top(s));
	printf("pon pon---%d\n",isStackEmpty(s));
	deleteStack(s);
	push(s,8);
	push(s,100);
	printf("vagina vagina---%d\n",pop(s));
	printf("vagina vagina---%d\n",pop(s));
	push(s,1000);
	deleteStack(s);
	printf("chut %d %d %d\n",pop(s),s->capacity,s->top);
	push(s,20);
	push(s,30);
	printf("chut %d %d %d\n",pop(s),s->capacity,s->top);
	return 0;
}

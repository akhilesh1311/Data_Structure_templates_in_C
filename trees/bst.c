#include<stdio.h>
#include<stdlib.h>
//#include "../queue/circular_queue_generic.c"
#include "../queue/queue.h"
#include "../stack/stack.h"

struct BinaryTreeNode{
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
};

struct BinaryTreeNode* createBST(){
	struct BinaryTreeNode *temp;
	temp=(struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
	temp->data=0;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void insertBST(struct BinaryTreeNode *b,int n){				//The root element will always have the data value as 0, for convenience
	 if(n>b->data){
		if (b->right != NULL) {
			insertBST(b->right,n);
		} else {
			b->right = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
			b->right->data = n;
			b->right->left = NULL;
			b->right->right = NULL;
		}
	}else if(n<b->data){
		if (b->left != NULL) {
			insertBST(b->left,n);
		} else {
			b->left = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
			b->left->data = n;
			b->left->left = NULL;
			b->left->right = NULL;
		}
	} else if(n == b->data){
		if (b->right == NULL) {
			b->right = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
			b->right->data = n;
			b->right->left = NULL;
			b->right->right = NULL;			
		} else {
			struct BinaryTreeNode *b1 = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
			b1->data = n;
			b1->right = b->right;
			b->right = b1;
		}
	}
}

void preOrderTraversal(struct BinaryTreeNode *b){
	printf("%d ",b->data);
	if (b->left != NULL) {
		preOrderTraversal(b->left);
	}
	if (b->right != NULL) {
		preOrderTraversal(b->right);
	}
}

void inOrderTraversal(struct BinaryTreeNode *b){
	if (b->left != NULL) {
		inOrderTraversal(b->left);
	}
	printf("%d ",b->data);
	if (b->right != NULL) {
		inOrderTraversal(b->right);
	}
}

void postOrderTraversal(struct BinaryTreeNode *b){
	if (b->left != NULL) {
		postOrderTraversal(b->left);
	}
	if (b->right != NULL) {
		postOrderTraversal(b->right);
	}
	printf("%d ",b->data);
}

void levelOrderTraversal(struct BinaryTreeNode *b){
	struct arrayQueue *q;
	q = createQueue(sizeof(struct BinaryTreeNode));
	struct BinaryTreeNode *temp = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
	enQueue(q,b);
	while (!isQueueEmpty(q)) {
		temp = deQueue(q);
		printf("%d ",temp->data);
		if (temp->left != NULL) {
			enQueue(q,temp->left);
		}
		if (temp->right != NULL) {
			enQueue(q,temp->right);
		}
	}
}

void preOrderTraversalNoRecursion(struct BinaryTreeNode *b){
	struct Dynamic_generic_stack *s = createStack(sizeof(struct BinaryTreeNode));
	struct BinaryTreeNode *temp = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
//	printf("%d ",b->data);
	push(s,b);
	temp = b;
	int i = 10;
	while(!isStackEmpty(s)){
		printf("%d ",temp->data);
		if(temp->left != NULL){
			temp = temp->left;
			push(s,temp);
		} else {
			temp = pop(s);
			if(temp->right != NULL){
				temp = temp->right;
				if(temp->left != NULL){
					push(s,temp);
				}
			}
		}
	}
}

void inOrderTraversalNoRecursion(struct BinaryTreeNode *b){
	struct Dynamic_generic_stack *s = createStack(sizeof(struct BinaryTreeNode));
	struct BinaryTreeNode *temp = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
	struct BinaryTreeNode *temp2 = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
	push(s,b);
	temp = b;
	printf("tanu\n");
	while(!isStackEmpty(s)) {
		temp2 = top(s);
		printf("belly %d\n",temp2->data);
		printf("shakira %d \n",temp->data);
		while(temp->left != NULL) {
			printf("booty %d \n",temp->data);
			temp = temp->left;
			push(s,temp);
		}
		printf("Hello Brother\n");
		if(!isStackEmpty(s)) {
			temp = pop(s);
		}
		printf("%d \n",temp->data);
		printf("Hello Bhai\n");
		if(temp->right != NULL) {
			printf("ass %d\n",temp->right->data);
			temp = temp->right;
			push(s,temp);
		}
		if(temp->right == NULL) {
			printf("Hello Sister\n");
		}
	}
}

int main(){
	struct BinaryTreeNode *b = createBST();
	insertBST(b,19);
	insertBST(b,7);
	insertBST(b,43);
	insertBST(b,3);
	insertBST(b,11);
	insertBST(b,23);
	insertBST(b,47);
	insertBST(b,2);
	insertBST(b,5);
	insertBST(b,17);
	insertBST(b,37);
	insertBST(b,53);
	insertBST(b,13);
	insertBST(b,29);
	insertBST(b,41);
	insertBST(b,31);
	preOrderTraversal(b);
	printf("\n");
	inOrderTraversal(b);
	printf("\n");
	postOrderTraversal(b);
	printf("\n");
	levelOrderTraversal(b);
	printf("\n");
//	preOrderTraversalNoRecursion(b);
//	printf("\n");
	inOrderTraversalNoRecursion(b);
	printf("\n");
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../queue/queue.h"
#include "../stack/stack.h"

struct graph {
	int vertex;
	int edge;
	struct listNode **adj;
};

struct listNode {
	int vertexNumber;
	struct listNode *next;
};

struct graph* adjListOfGraph (int vertex) {
	int i,x,y;
	struct graph *g = (struct graph *)malloc(sizeof(struct graph));
	if (g == NULL) {
		printf("memory error\n");
		return;
	}
	g->vertex = vertex;
	g->edge = 0;
	g->adj = (struct listNode **)malloc((vertex+1) * sizeof(struct listNode *));		// vertex 1 can be stored in adj[1] or adj[0], as the user wants
	for(i=0;i <= g->vertex;i++) {																			//one extra vertex
		g->adj[i] = (struct listNode *)malloc(sizeof(struct listNode));
		g->adj[i]->vertexNumber = i;																		//again
		g->adj[i]->next = g->adj[i];
	}
	return g;
}

void addGraphEdgeUndirected(struct graph *g, int vertex1, int vertex2) {
	int i;
	struct listNode *temp,*temp2;

	temp = (struct listNode *)malloc(sizeof(struct listNode));
	temp->vertexNumber = vertex2;
	temp->next = g->adj[vertex1];
	temp2 = g->adj[vertex1];
	while(temp2->next != g->adj[vertex1]) {
		temp2 = temp2->next;
	}
	temp2->next = temp;

	temp = (struct listNode *)malloc(sizeof(struct listNode));								//this is an undirected graph
	temp->vertexNumber = vertex1;
	temp->next = g->adj[vertex2];
	temp2 = g->adj[vertex2];
	while(temp2->next != g->adj[vertex2]) {
		temp2 = temp2->next;
	}
	temp2->next = temp;
	
	g->edge = g->edge + 1;
}

void addGraphEdgeDirected(struct graph *g, int vertex1, int vertex2) {
	struct listNode *temp,*temp2;

	temp = (struct listNode *)malloc(sizeof(struct listNode));
	temp->vertexNumber = vertex2;
	temp->next = g->adj[vertex1];
	temp2 = g->adj[vertex1];
	while(temp2->next != g->adj[vertex1]) {
		temp2 = temp2->next;
	}
	temp2->next = temp;
	
	g->edge = g->edge + 1;
}

void deleteGraphEdgeUndirected(struct graph *g, int vertex1, int vertex2) {	//will delete only one edge at a time, if the graph contains
	struct listNode *temp,*temp2;																//many edges between vertex1 and vertex2.

	temp = g->adj[vertex1];
	temp2 = g->adj[vertex1]->next;
	while(temp2->next != g->adj[vertex1] & temp2->vertexNumber != vertex2) {
		temp = temp2;
		temp2 = temp2->next;
	}
	if(temp2->vertexNumber == vertex2) {
		temp->next = temp2->next;
		free(temp2);
	} else {
		printf("don't try to delete a non existant edge\n");
	}

	temp = g->adj[vertex2];
	temp2 = g->adj[vertex2]->next;
	while(temp2->next != g->adj[vertex2] & temp2->vertexNumber != vertex1) {
		temp = temp2;
		temp2 = temp2->next;
	}
	if(temp2->vertexNumber == vertex1) {
		temp->next = temp2->next;
		free(temp2);
	} else {
		printf("don't try to delete a non existant edge\n");
	}
	g->edge = g->edge - 1;
}

void deleteGraphEdgeDirected(struct graph *g, int vertex1, int vertex2) {	//will delete only one edge at a time, if the graph contains
	struct listNode *temp,*temp2;															//many edges between vertex1 and vertex2.

	temp = g->adj[vertex1];
	temp2 = g->adj[vertex1]->next;
	while(temp2->next != g->adj[vertex1] & temp2->vertexNumber != vertex2) {
		temp = temp2;
		temp2 = temp2->next;
	}
	if(temp2->vertexNumber == vertex2) {
		temp->next = temp2->next;
		free(temp2);
	} else {
		printf("don't try to delete a non existant edge\n");
	}
}

void deleteGraphVertex(struct graph *g, int vertex) {
	int i,j;
	struct listNode *temp,*temp2;
	for(i=0;i<=g->vertex;i++) {
		temp = g->adj[i]->next;
		temp2 = g->adj[i];
		if(i == vertex) {
			while(temp != g->adj[i]) {
				temp2->next = temp->next;
				free(temp);
				temp = temp2->next;
				g->edge = g->edge - 1;
			}
			continue;
		}
		while(temp != g->adj[i]) {
			if (temp->vertexNumber == vertex) {
				temp2->next = temp->next;
				free(temp);
				temp = temp2->next;
				g->edge = g->edge - 1;
			}
			temp2 = temp;
			temp = temp->next;
		}
	}
}

void printList(struct listNode *adj){
	struct listNode *temp;
	temp = adj->next;
	while(temp != adj){
		printf("%d ",temp->vertexNumber);
		temp=temp->next;
	}
}

void printGraph(struct graph *g){
	int i;
	for(i=0;i<=g->vertex;i++){
		printf("\nhere is %d::\n",i);
		printList(g->adj[i]);
	}
}

struct integer {
	int a;
};

void bfs(struct graph *g,int start){
	int visited[g->vertex+1],i,*level,*vertex,*temp3,*level2,*level3;
	struct listNode *temp;
	for(i=0;i<=g->vertex;i++) {
		visited[i] = 0;
	}
	visited[start]=1;
	struct arrayQueue* q = createQueue(sizeof(struct integer));
	level = (int *)malloc(sizeof(int));
	level2 = (int *)malloc(sizeof(int));
	level3 = (int *)malloc(sizeof(int));
	struct integer *in1 = (struct integer *)malloc(sizeof(struct integer));
	in1->a = 1;
	struct integer *in2 = (struct integer *)malloc(sizeof(struct integer));
	in1->a = 2;
	struct integer *in3 = (struct integer *)malloc(sizeof(struct integer));
	struct integer *in4 = (struct integer *)malloc(sizeof(struct integer));
	in1->a = 5;
	vertex = (int *)malloc(sizeof(int));
	*level = start;
	enQueue(q,in1);
	*level = 2;
	enQueue(q,in2);
	*level = 9;
	enQueue(q,in3);
	in4 = (struct integer *)deQueue(q);
	printf("hips %d\n",in4->a);
	in4 = (struct integer *)deQueue(q);
	printf("hips %d\n",in4->a);
	in4 = (struct integer *)deQueue(q);
	printf("hips %d\n",in4->a);


	while(!isQueueEmpty(q)) {
		level = deQueue(q);
		printf("shakira %d \n",*level);
		temp = g->adj[*level]->next;
		printf("dance %d\n",queueSize(q));
		while (temp != g->adj[*level]) {
//			printf("shakira\n");
			if (visited[temp->vertexNumber] == 0) {
				*vertex = temp->vertexNumber;
//				printf("\n%d\n ",*vertex);
//				enQueue(q,vertex);
				visited[*vertex] = 1;
			}
			printf("belly %d  ",queueSize(q));
			temp = temp->next;
		}
	}
}

int main() {
	struct graph *g = adjListOfGraph(4);

	addGraphEdgeDirected(g,1,2);
	addGraphEdgeDirected(g,2,3);
	addGraphEdgeDirected(g,3,4);
	addGraphEdgeDirected(g,4,1);
	addGraphEdgeDirected(g,4,2);
	addGraphEdgeDirected(g,4,1);
//	printGraph(g);
//	deleteGraphEdgeDirected(g,2,3);
//	printGraph(g);
//	deleteGraphVertex(g,2);
//	printGraph(g);
	bfs(g,4);
}

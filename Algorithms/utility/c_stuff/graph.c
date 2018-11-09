#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node* next;
};

struct List{
	struct node* head;
};

struct Graph{
	int v;
	struct List* neighbours;
};

struct Graph* Graph_init(int vertices){
	struct Graph* gt = malloc(sizeof(struct Graph));
	gt->v=vertices;
	gt->neighbours = malloc(sizeof(struct List)*vertices);
	for(int k=0; k<vertices; k++){
		gt->neighbours[k].head=NULL;
	}
	return gt;
}

void add_edge(struct Graph* gt, int i, int j){
	struct node* dest = malloc(sizeof(struct node));	
	dest->val=j;
	dest->next=NULL;
	dest->next=gt->neighbours[i].head;
	gt->neighbours[i].head=dest;
}

void print_graph(struct Graph *gt){
	for(int k=0; k<gt->v; k++){
		printf("########## %d ##########\n",k);
		struct node* tp = gt->neighbours[k].head;
		while(tp!=NULL){
			printf("%d\n", tp->val);
			tp=tp->next;
		}
	}
}

int main(){
	struct Graph* testGraph = Graph_init(4);
	add_edge(testGraph,0,1);
	add_edge(testGraph,1,2);
	add_edge(testGraph,2,3);
	add_edge(testGraph,0,3);
	print_graph(testGraph);
	return 0;
}
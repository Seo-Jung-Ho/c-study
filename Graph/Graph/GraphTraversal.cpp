#include "GraphTraversal.h"

//³ÐÀÌ ¿ì¼± Å½»ö
void BFS(Vertex* v, LinkedQueue* queue) {
	Edge* e = NULL;
	
	printf("%c ", v->data);
	v->visited = Visited;

	enQueue(queue, createNode(v));

	while (!isEmpty(queue)) {
		Node* poped = deQueue(queue);
		v = poped->data;
		e = v->adjacencyList;
		while (e != NULL) {
			v = e->target;
			if (v != NULL&& v->visited == No) {
				printf("%c  ", v->data);
				v->visited = Visited;
				enQueue(queue, createNode(v));
			}
			e = e->next;
		}
	}
};

//±íÀÌ ¿ì¼± Å½»ö
void DFS(Vertex* v) {
	Edge* e = NULL;
	printf("%c ",v->data);

	v->visited = Visited;

	e = v->adjacencyList;
	while (e != NULL) {
		if (e->target != NULL && e->target->visited == No) {
			DFS(e->target);
		}
		e = e->next;
	}
};
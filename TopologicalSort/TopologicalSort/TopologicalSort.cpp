#include "TopologicalSort.h"

void topologicalSort(Vertex* v, Node** list) {
	while (v != NULL && v->visited == No) {
		ts_dfs(v, list);
		v = v->next;
	}
};
void ts_dfs(Vertex* v, Node** list) {
	Node* newHead = NULL;
	Edge* e = NULL;

	v->visited = Visited;

	e = v->adjacencyList;

	while (e != NULL) {
		if (e->target != NULL && e->target->visited == No) {
			ts_dfs(e->target, list);
		}
			e = e->next;
	}
	printf("%c\n", v->data);
	
	newHead = createNode(v);
	insertNewHead(list, newHead );
};


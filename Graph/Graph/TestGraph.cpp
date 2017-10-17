#include "GraphTraversal.h"

void main() {
	Graph* g = createGraph();

	Vertex* v1 = createVertex('1');
	Vertex* v2 = createVertex('2');
	Vertex* v3 = createVertex('3');
	Vertex* v4 = createVertex('4');
	Vertex* v5 = createVertex('5');
	Vertex* v6 = createVertex('6');
	Vertex* v7 = createVertex('7');

	addVertex(g, v1);
	addVertex(g, v2);
	addVertex(g, v3);
	addVertex(g, v4);
	addVertex(g, v5);
	addVertex(g, v6);
	addVertex(g, v7);

	addEdge(v1, createEdge(v1, v2, 0));
	addEdge(v1, createEdge(v1, v3, 0));

	addEdge(v2, createEdge(v2, v4, 0));
	addEdge(v2, createEdge(v2, v5, 0));

	addEdge(v3, createEdge(v3, v4, 0));
	addEdge(v3, createEdge(v3, v6, 0));

	addEdge(v4, createEdge(v4, v5, 0));
	addEdge(v4, createEdge(v4, v7, 0));

	addEdge(v5, createEdge(v5, v7, 0));

	addEdge(v6, createEdge(v6, v7, 0));

	printGraph(g);

	printf("DFS \n");
	//DFS(g->vertices);
	printf("\n");

	printf("BFS \n");
	LinkedQueue* queue;
	createQueue(&queue);
	BFS(g->vertices, queue);
	destroyQueue(queue);
	printf("\n");

	destroyGraph(g);
}
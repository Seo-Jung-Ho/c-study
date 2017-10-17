#include "TopologicalSort.h"

void main() {
	Node* sortedList = NULL;
	Node* currentNode = NULL;

	Graph* graph = createGraph();

	Vertex* a = createVertex('A');
	Vertex* b = createVertex('B');
	Vertex* c = createVertex('C');
	Vertex* d = createVertex('D');
	Vertex* e = createVertex('E');
	Vertex* f = createVertex('F');
	Vertex* g = createVertex('G');
	Vertex* h = createVertex('H');

	addVertex(graph, a);
	addVertex(graph, b);
	addVertex(graph, c);
	addVertex(graph, d);
	addVertex(graph, e);
	addVertex(graph, f);
	addVertex(graph, g);
	addVertex(graph, h);

	addEdge(a, createEdge(a, c, 0));
	addEdge(a, createEdge(a,d,0));

	addEdge(b, createEdge(b, c, 0));
	addEdge(b, createEdge(b, e, 0));

	addEdge(c, createEdge(c, f, 0));
	
	addEdge(d, createEdge(d, f, 0));
	addEdge(d, createEdge(d, g, 0));

	addEdge(e, createEdge(e, g, 0));

	addEdge(f, createEdge(f, h, 0));

	addEdge(g, createEdge(g, h, 0));

	topologicalSort(graph->vertices, &sortedList);

	printf("result ~~!~!\n");

	currentNode = sortedList;
	while (currentNode != NULL) {
		printf("%C", currentNode->data->data);
		currentNode = currentNode->nextNode;
	}

	printf("\n");
	destroyGraph(graph);
}
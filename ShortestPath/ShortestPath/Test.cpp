#include "ShortestPath.h"

void main() {

	Graph* graph = createGraph();
	Graph* shortesGr = createGraph();

	Vertex* a = createVertex('A');
	Vertex* b = createVertex('B');
	Vertex* c = createVertex('C');
	Vertex* d = createVertex('D');
	Vertex* e = createVertex('E');
	Vertex* f = createVertex('F');
	Vertex* g = createVertex('G');
	Vertex* h = createVertex('H');
	Vertex* i = createVertex('I');

	addVertex(graph, a);
	addVertex(graph, b);
	addVertex(graph, c);
	addVertex(graph, d);
	addVertex(graph, e);
	addVertex(graph, f);
	addVertex(graph, g);
	addVertex(graph, h);
	addVertex(graph, i);

	addEdge(a, createEdge(a, e, 247));

	addEdge(b, createEdge(b, a, 35));
	addEdge(b, createEdge(b, c, 126));
	addEdge(b, createEdge(b, f, 150));

	addEdge(c, createEdge(c, d, 117));
	addEdge(c, createEdge(c, f, 162));
	addEdge(c, createEdge(c, g, 220));

	//addEdge(d, createEdge(d, g, 2));

	addEdge(e, createEdge(e, h, 98));

	addEdge(f, createEdge(f, e, 82));
	addEdge(f, createEdge(f, g, 154));
	addEdge(f, createEdge(f, h, 120));

	addEdge(g, createEdge(g, i, 106));

	Dijkstra(graph, b, shortesGr);

	printGraph(shortesGr);

	destroyGraph(graph);
	destroyGraph(shortesGr);
}
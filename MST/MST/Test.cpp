#include "MST.h"

void main() {

	Graph* graph = createGraph();
	Graph* primMST = createGraph();
	Graph* kruskalMST = createGraph();

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

	addEdge(a, createEdge(a, b, 35));
	addEdge(a, createEdge(a, e, 247));

	addEdge(b, createEdge(b, a, 35));
	addEdge(b, createEdge(b, c, 126));
	addEdge(b, createEdge(b, f, 150));

	addEdge(c, createEdge(c, b, 126));
	addEdge(c, createEdge(c, d, 117));
	addEdge(c, createEdge(c, f, 162));
	addEdge(c, createEdge(c, g, 220));

	addEdge(d, createEdge(d, c, 117));

	addEdge(e, createEdge(e, a, 247));
	addEdge(e, createEdge(e, f, 82));
	addEdge(e, createEdge(e, h, 98));

	addEdge(f, createEdge(f, b, 150));
	addEdge(f, createEdge(f, c, 162));
	addEdge(f, createEdge(f, e, 82));
	addEdge(f, createEdge(f, g, 154));
	addEdge(f, createEdge(f, h, 120));

	addEdge(g, createEdge(g, c, 220));
	addEdge(g, createEdge(g, f, 154));
	addEdge(g, createEdge(g, i, 106));

	addEdge(h, createEdge(h, e, 98));
	addEdge(h, createEdge(h, f, 120));

	addEdge(i, createEdge(i, g, 106));

	prim(graph, b, primMST);
	printGraph(primMST);

	kruskal(graph, kruskalMST);
	printGraph(kruskalMST);

	destroyGraph(kruskalMST);
	destroyGraph(primMST);
	destroyGraph(graph);
}
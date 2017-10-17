#include "Graph.h"


Graph* createGraph() {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->vertices = NULL;
	graph->vertexCount = 0;
	return graph;
};

void destroyGraph(Graph* graph) {
	while (graph->vertices != NULL) {
		//temp
		Vertex* temp = graph->vertices->next;
		destroyVertex(graph->vertices);
		graph->vertices = temp;
	}
	free(graph);
};

Vertex* createVertex(ElementType data) {
	Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
	vertex->data = data;
	vertex->next = NULL;
	vertex->adjacencyList = NULL;
	vertex->visited = No;
	vertex->index = -1;
	return vertex;
};
void destroyVertex(Vertex* vertex) {
	while (vertex->adjacencyList != NULL) {
		Edge* temp = vertex->adjacencyList->next;
		destroyEdge(vertex->adjacencyList);
		vertex->adjacencyList = temp;
	}
	free(vertex);
};

Edge* createEdge(Vertex* from, Vertex* target, int weight) {
	Edge* e = (Edge*)malloc(sizeof(Edge));
	e->from = from;
	e->target = target;
	e->weight = weight;
	e->next = NULL;
	return e;
};

void destroyEdge(Edge* edge) {
	free(edge);
};

void addVertex(Graph* graph, Vertex* vertex) {
	Vertex* vertexList = graph->vertices;
	if (vertexList == NULL) {
		graph->vertices = vertex;
	}
	else {
		while (vertexList->next != NULL) {
			vertexList = vertexList->next;
		}
		vertexList->next = vertex;
	}

	vertex->index = graph->vertexCount++;
};
void addEdge(Vertex* vertex, Edge* edge) {
	if (vertex->adjacencyList == NULL) {
		vertex->adjacencyList = edge;
	}
	else {
		Edge* adList = vertex->adjacencyList;
		while (adList->next != NULL) {
			adList = adList->next;
		}
		adList->next = edge;
	}
};
void printGraph(Graph* graph) {
	Vertex* vertex = NULL;
	Edge* edge = NULL;
	//if( (vertex))
	vertex = graph->vertices;
	if (vertex == NULL) return;

	while (vertex != NULL) {

		printf("%c   ", vertex->data);
		edge = vertex->adjacencyList;

		if (edge == NULL) {
			printf("\n");
			vertex = vertex->next;
			continue;
		}

		while (edge != NULL) {
			printf("%c[%d] ", edge->target->data, edge->weight);
			edge = edge->next;
		}
		printf("\n");
		vertex = vertex->next;
	}
	printf("\n");
};

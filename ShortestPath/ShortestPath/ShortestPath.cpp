#include "ShortestPath.h"

void Dijkstra(Graph* g, Vertex* startVertex, Graph* shortestPath) {
	int i = 0;

	PQNode startNode = { 0, startVertex };
	PriorityQueue* pq = create(10);

	Vertex* currentVertex = NULL;
	Edge* currentEdge = NULL;
	int* weightList = (int*)malloc(sizeof(int) * g->vertexCount);
	Vertex** shortestPathVertexList = (Vertex**)malloc(sizeof(Vertex*) * g->vertexCount);
	Vertex** fringeList = (Vertex**)malloc(sizeof(Vertex*) * g->vertexCount);
	Vertex** precedenceList = (Vertex**)malloc(sizeof(Vertex*) * g->vertexCount);

	currentVertex = g->vertices;
	while (currentVertex != NULL) {
		Vertex* newVertex = createVertex(currentVertex->data);
		addVertex(shortestPath, newVertex);
		fringeList[i] = NULL;
		precedenceList[i] = NULL;
		shortestPathVertexList[i] = newVertex;
		weightList[i] = MAX_WEIGHT;
		currentVertex = currentVertex->next;
		i++;
	}

	enqueue(pq, startNode);
	weightList[startVertex->index] = 0; //시작 정점의 거리를 0으로

	while (!isEmpty(pq)) {
		PQNode poped;
		dequeue(pq, &poped);
		currentVertex = (Vertex*)poped.data;

		fringeList[currentVertex->index] = currentVertex;
		currentEdge = currentVertex->adjacencyList;

		while (currentEdge != NULL) {
			Vertex* targetVertex = currentEdge->target;

			if (fringeList[targetVertex->index] == NULL
				&&
				weightList[currentVertex->index] + currentEdge->weight < weightList[targetVertex->index]) {
				PQNode newNode = { currentEdge->weight,targetVertex };
				enqueue(pq, newNode);
				precedenceList[targetVertex->index] = currentEdge->from;
				weightList[targetVertex->index] = weightList[currentVertex->index] + currentEdge->weight;
			}
			currentEdge = currentEdge->next;
		}
	}

	for (int i = 0; i < g->vertexCount; i++) {
		int fromIndex, toIndex;

		if (precedenceList[i] == NULL)
			continue;
		
		fromIndex = precedenceList[i]->index;
		toIndex = i;

		addEdge(shortestPathVertexList[fromIndex],
			createEdge(shortestPathVertexList[fromIndex], shortestPathVertexList[toIndex], weightList[i]));
	}

	free(fringeList);
	free(precedenceList);
	free(shortestPathVertexList);
	free(weightList);

	destroy(pq);

}
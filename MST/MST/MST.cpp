#include "MST.h"

void prim(Graph* g, Vertex* startVertex, Graph* MST) {

	int i = 0;

	PQNode startNode = { 0, startVertex };
	PriorityQueue* pq = create(10);

	Vertex* currentVertex = NULL;
	Edge* currentEdge = NULL;

	int* weights = (int*)malloc(sizeof(int)*g->vertexCount);//??

	Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * g->vertexCount);
	Vertex** fringes = (Vertex**)malloc(sizeof(Vertex*) * g->vertexCount);
	Vertex** precedences = (Vertex**)malloc(sizeof(Vertex*) * g->vertexCount);

	currentVertex = g->vertices;
	while (currentVertex != NULL) { //초기화 하는 부분
		Vertex* newVertex = createVertex(currentVertex->data);
		addVertex(MST, newVertex);

		fringes[i] = NULL;
		precedences[i] = NULL;
		MSTVertices[i] = newVertex;
		weights[i] = MAX_WEIGHT;
		currentVertex = currentVertex->next;
		i++;
	}

	enqueue(pq, startNode);
	weights[startVertex->index] = 0;

	while (!isEmpty(pq)) {
		PQNode poped;

		dequeue(pq, &poped);
		currentVertex = (Vertex*)poped.data;

		fringes[currentVertex->index] = currentVertex;

		currentEdge = currentVertex->adjacencyList;
		while (currentEdge != NULL) {
			Vertex* targetVertex = currentEdge->target;
			if (fringes[targetVertex->index] == NULL
				&& currentEdge->weight < weights[targetVertex->index]) {
				PQNode newNode = {currentEdge->weight, targetVertex };
				enqueue(pq, newNode);

				precedences[targetVertex->index] = currentEdge->from;
				weights[targetVertex->index] = currentEdge->weight;
			}

			currentEdge = currentEdge->next;
		}
	}

	for (int i = 0; i < g->vertexCount; i++) {
		int fromIndex, toIndex;
		if (precedences[i] == NULL)
			continue;

		fromIndex = precedences[i]->index;
		toIndex = i;

		addEdge(MSTVertices[fromIndex],
				createEdge(MSTVertices[fromIndex], 
					MSTVertices[toIndex],
					weights[i]));
		addEdge(MSTVertices[toIndex],
			createEdge(MSTVertices[toIndex],
				MSTVertices[fromIndex],
				weights[i]));
	}

	free(fringes);
	free(precedences);
	free(MSTVertices);

	free(weights);

	destroy(pq);
};
void kruskal(Graph* g, Graph* mst) {
	//그래프 내의 모든 간선을 가중치의 오름차순으로 목록을 만듬
	//1에서 만든 간선의 목록을 차례대로 순회하면서 간선을 최소 신장트리에 추가합니다, 단 이떄 추가된 간선으로인해 최소 신장트리 내에 사이클이 형성되면 안됨

	int i;
	Vertex* currentVertex = NULL;
	Vertex** MSTVertecies = (Vertex**)malloc(sizeof(Vertex*) * g->vertexCount);//얘는 결과과 될 놈

	DisjointSet** vertexSet = (DisjointSet**)malloc(sizeof(DisjointSet*) * g->vertexCount);// 얘는 집합을 변수

	PriorityQueue* pq = create(10);

	i = 0;
	currentVertex = g->vertices;
	while (currentVertex != NULL) {
		Edge* currentEdge;

		vertexSet[i] = makeSet(currentVertex);
		MSTVertecies[i] = createVertex(currentVertex->data);
		addVertex(mst, MSTVertecies[i]);

		currentEdge = currentVertex->adjacencyList;
		while (currentEdge != NULL) {
			PQNode newNode = { currentEdge->weight, currentEdge };
			enqueue(pq, newNode);
			currentEdge = currentEdge->next;
		}
		currentVertex = currentVertex->next;
		i++;
	}
	for (int j = 0; j < pq->usedSize; j++) {
		//printNode(&pq->nodes[j]);
	}

	while (!isEmpty(pq)) {
		Edge* currentEdge;
		int fromIndex;
		int toIndex;
		PQNode poped;

		dequeue(pq, &poped);
		printNode(&poped);
		currentEdge = (Edge*)poped.data;

		fromIndex = currentEdge->from->index;
		toIndex = currentEdge->target->index;

		if (findSet(vertexSet[fromIndex]) != findSet(vertexSet[toIndex])) {
			addEdge(MSTVertecies[fromIndex],
				createEdge(MSTVertecies[fromIndex],
					MSTVertecies[toIndex],
					currentEdge->weight));
			addEdge(MSTVertecies[toIndex],
				createEdge(MSTVertecies[toIndex],
					MSTVertecies[fromIndex],
					currentEdge->weight));

			unionSet(vertexSet[fromIndex], vertexSet[toIndex]);
		}
	}

	for (int i = 0; i < g->vertexCount; i++) {
		destroySet(vertexSet[i]);
	}

	free(vertexSet);
	free(MSTVertecies);
};
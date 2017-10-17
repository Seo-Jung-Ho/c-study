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
	while (currentVertex != NULL) { //�ʱ�ȭ �ϴ� �κ�
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
	//�׷��� ���� ��� ������ ����ġ�� ������������ ����� ����
	//1���� ���� ������ ����� ���ʴ�� ��ȸ�ϸ鼭 ������ �ּ� ����Ʈ���� �߰��մϴ�, �� �̋� �߰��� ������������ �ּ� ����Ʈ�� ���� ����Ŭ�� �����Ǹ� �ȵ�

	int i;
	Vertex* currentVertex = NULL;
	Vertex** MSTVertecies = (Vertex**)malloc(sizeof(Vertex*) * g->vertexCount);//��� ����� �� ��

	DisjointSet** vertexSet = (DisjointSet**)malloc(sizeof(DisjointSet*) * g->vertexCount);// ��� ������ ����

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
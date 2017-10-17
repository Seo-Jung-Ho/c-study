#include <stdio.h>
#include <stdlib.h>

enum VisitMode {
	Visited,
	No
};

typedef int ElementType;

//정점
typedef struct tagVertex {
	ElementType data;
	int visited; //순회 알고리즘을 위해서
	int index; //정점의 인덱스

	struct tagVertex* next; //다음 정점
	struct tagEdge* adjacencyList; //인접 간선 목록에 대한 포인터
}Vertex;

//간선
typedef struct tagEdge {
	int weight; //가중치
	struct tagEdge* next; //다음간선?
	Vertex* from; //시작
	Vertex* target; //끝
}Edge;

typedef struct tagGraph {
	Vertex* vertices; //정점들
	int vertexCount; //
}Graph;

Graph* createGraph();
void destroyGraph(Graph* graph);

Vertex* createVertex(ElementType data);
void destroyVertex(Vertex* vertex);

Edge* createEdge(Vertex* from, Vertex* target, int weight);
void destroyEdge(Edge* edge);

void addVertex(Graph* graph, Vertex* vertex);
void addEdge(Vertex* vertex, Edge* edge);
void printGraph(Graph* graph);
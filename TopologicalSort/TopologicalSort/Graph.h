#include <stdio.h>
#include <stdlib.h>

enum VisitMode {
	Visited,
	No
};

typedef int ElementType;

//����
typedef struct tagVertex {
	ElementType data;
	int visited; //��ȸ �˰����� ���ؼ�
	int index; //������ �ε���

	struct tagVertex* next; //���� ����
	struct tagEdge* adjacencyList; //���� ���� ��Ͽ� ���� ������
}Vertex;

//����
typedef struct tagEdge {
	int weight; //����ġ
	struct tagEdge* next; //��������?
	Vertex* from; //����
	Vertex* target; //��
}Edge;

typedef struct tagGraph {
	Vertex* vertices; //������
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
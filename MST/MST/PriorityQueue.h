#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int PriorityType;

typedef struct tagePQNode {
	PriorityType  priority;
	void* data;
}PQNode;

typedef struct tagPriorityQueue {
	PQNode* nodes;
	int capacity;
	int usedSize;
}PriorityQueue;

PriorityQueue* create(int initialSize);
void destroy(PriorityQueue* pq);
void enqueue(PriorityQueue* pq, PQNode newData);
void dequeue(PriorityQueue* pq, PQNode* root);
int getPerent(int index);
int getLeftChilde(int index);
void swapNodes(PriorityQueue* pq, int index1, int index2);
int isEmpty(PriorityQueue* pq);

void printNode(PQNode* node);
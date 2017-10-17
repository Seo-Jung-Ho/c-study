#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

typedef Vertex* MyEle;

typedef struct tagNode {
	MyEle data;
	struct tagNode* nextNode;
}Node;

typedef struct tagLinkedQueue {
	Node* front;
	Node* rear;
	int count;
}LinkedQueue;

Node* createNode(Vertex* data);

void createQueue(LinkedQueue** createQueue);
void destroyQueue(LinkedQueue* queue);

void enQueue(LinkedQueue* queue, Node* data);
Node* deQueue(LinkedQueue* queue);

int isEmpty(LinkedQueue* queue);
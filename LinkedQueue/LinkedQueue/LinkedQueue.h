#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
	int data;
	struct tagNode* nextNode;
}Node;

typedef struct tagLinkedQueue{
	Node* front;
	Node* rear;
	int count;
}LinkedQueue;

Node* createNode(int data);

void createQueue(LinkedQueue** createQueue);
void destroyQueue(LinkedQueue* queue);
//
void enQueue(LinkedQueue* queue, int data);
Node* deQueue(LinkedQueue* queue);
//
//int getSize(CircularQueue* queue);
//int isEmpty(CircularQueue* queue);
//int isFull(CircularQueue* queue);
//
//
//

#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
	ElementType data;
}Node;

typedef struct tagCircularQueue {
	int capacity; // 실제 용량은 이것보다 하나 작다 왜? -> 공백값 하나 때문에
	int front;
	int rear; // 후단 인덱스
	Node* nodes; // 노드 배열
}CircularQueue;

void createQueue(CircularQueue** createQueue, int capacity);
void destroyQueue(CircularQueue* queue);

void enQueue(CircularQueue* queue, ElementType data);
ElementType deQueue(CircularQueue* queue);

int getSize(CircularQueue* queue);
int isEmpty(CircularQueue* queue);
int isFull(CircularQueue* queue);




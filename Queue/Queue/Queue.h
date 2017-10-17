#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
	ElementType data;
}Node;

typedef struct tagCircularQueue {
	int capacity; // ���� �뷮�� �̰ͺ��� �ϳ� �۴� ��? -> ���鰪 �ϳ� ������
	int front;
	int rear; // �Ĵ� �ε���
	Node* nodes; // ��� �迭
}CircularQueue;

void createQueue(CircularQueue** createQueue, int capacity);
void destroyQueue(CircularQueue* queue);

void enQueue(CircularQueue* queue, ElementType data);
ElementType deQueue(CircularQueue* queue);

int getSize(CircularQueue* queue);
int isEmpty(CircularQueue* queue);
int isFull(CircularQueue* queue);




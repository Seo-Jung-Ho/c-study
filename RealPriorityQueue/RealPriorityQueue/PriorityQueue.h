#pragma once
#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include<math.h>

typedef int PriorityType;

typedef struct tagNode {
	PriorityType priority;
	void* data;
}Node;

typedef struct tagPriorityQueue {
	Node* nodes;
	int capacity;
	int usedSize;
}PriorityQueue;

PriorityQueue* create(int initSize);
void destroy(PriorityQueue* pq);
void enqueue(PriorityQueue* pq, Node* newData);
void dequeue(PriorityQueue* pq, Node* root);
int getParentIdx(int index);
int getLeftChildIdx(int index);
void swap(PriorityQueue* pq, int idx1, int idx2);
int isEmpty(PriorityQueue* pq);


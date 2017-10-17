#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
typedef int ElementType;

typedef struct tagHeapNode {
	ElementType data;
}HeapNode;

typedef struct tagHeap {
	HeapNode* nodes;
	int capacity;
	int usedSize;
}Heap;

Heap* createHeap(int initSize);
void destroyHeap(Heap* h);
void insertHeap(Heap* h, ElementType newData);
void deleteMin(Heap* h, HeapNode* root);
int getParent(int index);
int getLeftChild(int index);
void swapNodes(Heap* h, int index1, int index2);
void showAll(Heap* h);


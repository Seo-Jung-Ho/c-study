#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagLCRSNode {
	struct tagLCRSNode* leftChild;
	struct tagLCRSNode* rightSibling;

	ElementType data;
}Node;

Node* createNode(ElementType newData);
void destroyNode(Node* node);
void addChild(Node* parent, Node* child);
void printTree(Node* node, int depth);
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode{
	struct tagNode* left;
	struct tagNode* right;
	ElementType data;
} Node;

Node* createNode(ElementType newData);
void destroyTree(Node* root);
Node* searchNode(Node* root, ElementType target);
Node* searchMinNode(Node* tree);
void insertNode(Node* root, Node* child);
Node* removeNode(Node* tree, Node* parent, ElementType target);
void inorderPrintTree(Node* root, int depth);
#pragma once
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

typedef struct tagNode {
	Vertex* data;
	struct tagNode* nextNode;
} Node;


Node* createNode(Vertex* data);
void deleteWithIndex(Node* head, Vertex* index);
void destroyList(Node* head);
void showAll();
int getCount(Node* head);
Node* prepend(Node* head, int data);
void append(Node** head, Vertex* data);
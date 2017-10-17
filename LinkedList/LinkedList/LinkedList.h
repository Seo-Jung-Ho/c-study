#pragma once
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
	int data;
	struct tagNode* nextNode;
} Node;


Node* createNode(int data);
void deleteWithIndex(Node* head, int index);
void destroyList(Node* head);
void showAll();
int getCount(Node* head);
Node* prepend(Node* head, int data);
void append(Node** head, int data);
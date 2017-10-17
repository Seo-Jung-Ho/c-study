#pragma once
#define STACK
#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
	double data;
	struct tagNode* nextNode;
}Node;

typedef struct tagLinkedStack {
	Node* head;
	Node* top;
}LinkedListStack;

Node* createNode(double data);
void destroyNode(Node* node);

void createStack(LinkedListStack** stack);
void destroyStack(LinkedListStack* stack);

void push(LinkedListStack* stack, Node* node);
Node* pop(LinkedListStack* stack);

int getCount(LinkedListStack* stack);
void showAll(LinkedListStack* stack);
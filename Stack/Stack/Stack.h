#ifndef  LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tagNode
{
	char* data;
	struct tagNode* nextNode;
} Node;

typedef struct tagLinkedListStack
{
	Node* head;
	Node* top;

} LinkedListStack;


Node* createNode(char* data);
void destroyNode(Node* node);
void createStack(LinkedListStack** stack);
void destroyStack(LinkedListStack* stack);
void push(LinkedListStack* stack, Node* node);
Node* pop(LinkedListStack* stack);
int getCount(LinkedListStack* stack);
void showAll(LinkedListStack* stack);

#endif // ! LINKEDLIST_STACK_H
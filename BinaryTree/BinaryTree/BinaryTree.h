#pragma onnce
#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagNode {
	struct tagNode* left;
	struct tagNode* right;
	ElementType data;
}Node;

Node* createNode(ElementType newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = newData;
	return newNode;
}

void preorderPrintTree(Node* node) {
	if (node == NULL) {
		return;
	};

	printf("%c", node->data);
	preorderPrintTree(node->left);
	preorderPrintTree(node->right);
}

void inorderPrintTree(Node* node) {
	if (node == NULL) {
		return;
	}
	inorderPrintTree(node->left);
	printf("%c", node->data);
	inorderPrintTree(node->right);
}

void postorderPrintTree(Node* node) {
	if (node == NULL) {
		return;
	}
	postorderPrintTree(node->left);
	postorderPrintTree(node->right);
	printf("%c", node->data);
}

void destroyTree(Node* node) {
	if (node == NULL)
		return;

	destroyTree(node->left);
	destroyTree(node->right);
	free(node);
}
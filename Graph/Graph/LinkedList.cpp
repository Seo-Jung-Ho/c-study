#include "LinkedList.h"

Node* createNode(Vertex* data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->nextNode = NULL;
	return newNode;
};
void deleteWithIndex(Node* head, int index) {
};
void destroyList(Node* head) {
	int cnt = getCount(head);
	for (int i = 0; i < cnt; i++) {
		Node* currentNode = head;
		if (currentNode->nextNode == NULL) {
			free(head);
		}
		else {
			while (currentNode->nextNode->nextNode != NULL) {
				currentNode = currentNode->nextNode;
			}
			free(currentNode->nextNode);
			currentNode->nextNode = NULL;
		}
		printf("?");
	}
};
void showAll() {
};
int getCount(Node* head) {
	int cnt = 1;
	Node* currentNode = head;
	while (currentNode->nextNode != NULL) {
		currentNode = currentNode->nextNode;
		cnt++;
	}
	return cnt;
};
//Node* prepend(Node* head, int data) {
//};
void append(Node** head, Vertex* data) {

	Node* newNode = createNode(data);
	Node* currentNode = (*head);
	while (currentNode->nextNode != NULL) {
		currentNode = currentNode->nextNode;
	}
	currentNode->nextNode = newNode;

};


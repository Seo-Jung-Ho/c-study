#include "LinkedList.h"

Node* createNode(int data) {
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
		} else {
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
void append(Node** head, int data) {

	Node* newNode = createNode(data);
	Node* currentNode = (*head);
	while (currentNode->nextNode != NULL) {
		currentNode = currentNode->nextNode;
	}
	currentNode->nextNode = newNode;

};

void main() {

	Node* head = createNode(100);
	append(&head, 200);
	append(&head, 300);

	printf("%d°³\n", getCount(head));

	destroyList(head);

}
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct tagNode{
//	int data;
//	struct tagNode* nextNode;
//} Node;
//
//Node* createNode(int data) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = data;
//	newNode->nextNode = NULL;
//	return newNode;
//};
//
//void deleteWithIndex(Node* head, int index) {
//	Node* current = head;
//	while		(index > 1) { //지워야할 노드를 찾는게아니라 그전에서 멈춰야 한다
//		current = current->nextNode;
//		index--;
//	}
//	Node* remove = current->nextNode;
//	//현재 노드와 현재 다음 다음 노드를 연결
//	current->nextNode = current->nextNode->nextNode;
//	//현재 다음 노드를 제거
//	free(remove);
//	
//}
//
//void appendNode(Node** head, Node* newNode) {
//	if ((*head) == NULL) {
//		*head = newNode;
//	}
//	else {
//		Node* tail = (*head);
//		while (tail->nextNode != NULL) {
//			tail = tail->nextNode;
//		}
//		tail->nextNode = newNode;
//	}
//}
//
//void destroy(Node* head, int count) {
//	for (int i = 0; i < count; i++) {
//		Node* current = head;
//		if (current->nextNode == NULL) {
//			free(head);
//		}
//		else {
//			while			(current->nextNode->nextNode != NULL) {
//				current = current->nextNode;
//			}
//			free(current->nextNode);
//			current->nextNode = NULL;
//		}
//	}
//
//}
//
//void showAll(Node* head) {
//	Node* current = head;
//	printf("data is : %d\n", current->data);
//	while (current->nextNode != NULL) {
//		current = current->nextNode;
//		printf("data is : %d\n", current->data);
//	}
//}
//
//Node* prepend(Node* head, int data) {
//
//	Node* newHead = createNode(data);
//	newHead->nextNode = head;
//
//	return newHead;
//}
//
//Node* getNodeAt(Node* head, int loc) {
//	Node* current = head;
//	while ( loc > 0) {
//		loc--;
//		current = current->nextNode;
//	}
//	return current;
//}
//
//int getCount(Node* head) {
//	Node* current = head;
//	if (current == NULL) return 0;
//	int count = 1;
//	while (current->nextNode != NULL) {
//		count++;
//		current = current->nextNode;
//	}
//	return count;
//}
//
//void main() {
//
//	Node* head = NULL;
//	Node* newNode1 = NULL;
//	newNode1 = createNode(1);
//	appendNode(&head, newNode1);
//
//	newNode1 = createNode(2);
//	appendNode(&head, newNode1);
//	
//	newNode1 = createNode(3);
//	appendNode(&head, newNode1);
//
//	newNode1 = createNode(12312);
//	appendNode(&head, newNode1);
//
//	head = prepend(head, 100);
//	head = prepend(head, 200);
//
//	//showAll(list);
//	//Node* third = getNodeAt(list, 2);
//
//	printf("삭제 하기 전 : \n");
//	showAll(head);
//
//	printf("삭제 \n");
//	deleteWithIndex(head, 2);
//	showAll(head);
//	destroy(head, getCount(head));
//
//	printf("%d\n",sizeof(head));
//	
//	printf("끝");
//
//}
//#include "LinkedQueue.h"
//
//Node* createNode(Vertex* data) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = data;
//	newNode->nextNode = NULL;
//	return newNode;
//};
//
//void createQueue(LinkedQueue** queue) {
//	(*queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
//	(*queue)->count = 0;
//	(*queue)->front = NULL;
//	(*queue)->rear = NULL;
//};
//
//void destroyQueue(LinkedQueue* queue) {
//	Node* pop = deQueue(queue);
//	while (pop != NULL) {
//		free(pop);
//		pop = deQueue(queue);
//	}
//	free(queue);
//};
//
//void enQueue(LinkedQueue* queue, Node* data) {
//	if (queue->front == NULL) {
//		queue->front = data;
//		queue->rear = data;
//		queue->count++;
//	}
//	else {
//		queue->rear->nextNode = data;
//		queue->rear = data;
//		queue->count++;
//	}
//};
//
//int isEmpty(LinkedQueue* queue) {
//	return (queue->front == NULL);
//}
//
//Node* deQueue(LinkedQueue* queue) {
//	if (queue->front == NULL) {
//		return NULL;
//	}
//	Node* pop = queue->front;
//	if (queue->front->nextNode == NULL) {//한개인경우
//		queue->front = NULL;
//		queue->rear = NULL;
//	}
//	else {
//		queue->front = queue->front->nextNode;
//	}
//	queue->count--;
//	return pop;
//};
//
////void showAll(LinkedQueue* queue) {
////	Node* current = queue->front;
////	printf("%d\n", current->data);
////	while (current->nextNode != NULL) {
////		current = current->nextNode;
////		printf("%d\n", current->data);
////	}
////};

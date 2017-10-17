#include "Queue.h"

void createQueue(CircularQueue** queue, int capacity) {

	(*queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
	
	//입력된 capacity + 1 만큼의 노드를 자유 저장소에 생성
	(*queue)->nodes = (Node*)malloc(sizeof(Node)*(capacity + 1));

	// 큐가 실제 수용할 용랑을 저장
	(*queue)->capacity = capacity;

	//시작과 끝의 인덱스를 0으로 설정
	(*queue)->front = 0;
	(*queue)->rear = 0;
};

void destroyQueue(CircularQueue* queue) {
	free(queue->nodes);
	free(queue);
}

void enQueue(CircularQueue* queue, ElementType data) {
	int pos = 0;

	if (queue->rear == queue->capacity) {// 후단과 수용량이 같을때? 있을수가 있나?
		//아무튼 후단이 끝에 도달했으므로 후단을 다시 시작점으로 옴겨준다
		pos = queue->rear;
		queue->rear = 0;
	}
	else {
		pos = queue->rear++;
	}
	queue->nodes[pos].data = data;
};
ElementType deQueue(CircularQueue* queue) {
	//전단에서 하나제거
	int pos = queue->front;
	if (queue->front == queue->capacity)
		queue->front = 0;
	else
		queue->front++;
	return queue->nodes[pos].data;
}

int isEmpty(CircularQueue* queue) {
	return (queue->front == queue->rear);
}

int isFull(CircularQueue* queue) {
	if (queue->front < queue->rear) {
		return(queue->front) - (queue->rear) == queue->capacity;
	}
	else {
		return (queue->rear + 1) == queue->front;
	}
}

int getSize(CircularQueue* queue) {
	if (queue->front < queue->rear) {
		return queue->rear - queue->front;
	}else{
		return queue->rear + (queue->capacity - queue->front) + 1;
	}
}

void showAll(CircularQueue* queue) {
	for (int i = 0; i < queue->capacity; i++) {
		printf("%d\n", queue->nodes[i].data);
	}
};
void main() {

	CircularQueue* queue;
	createQueue(&queue,10);
	for (int i = 0; i < 8; i++) {
		enQueue(queue, i);
	}
	deQueue(queue);
	deQueue(queue);
	deQueue(queue);

	showAll(queue);

	printf("사이즈는 %d\n", getSize(queue));

	destroyQueue(queue);

}
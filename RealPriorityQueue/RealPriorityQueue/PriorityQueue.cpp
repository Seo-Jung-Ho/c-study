#include "PriorityQueue.h"


PriorityQueue* create(int initSize) {
	PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	pq->capacity = initSize;
	pq->usedSize = 0;
	pq->nodes = (Node*)malloc(sizeof(Node) * initSize);
	return pq;
};
void destroy(PriorityQueue* pq) {
	free(pq->nodes);
	free(pq);
};
void enqueue(PriorityQueue* pq, Node newData) {
	int currentPos = pq->usedSize;
	int parrentPos = getParentIdx(pq->usedSize);
	if (pq->usedSize == pq->capacity) {
		pq->capacity *= 2;
		pq->nodes = (Node*)realloc(pq->nodes, ( sizeof(Node) * pq->capacity ));
	}

	pq->nodes[currentPos] = newData;

	while (currentPos >0 && pq->nodes[currentPos].priority < pq->nodes[parrentPos].priority) {
		swap(pq, currentPos, parrentPos);
		currentPos = parrentPos;
		parrentPos = getParentIdx(parrentPos);
	}
	pq->usedSize++;
};
void dequeue(PriorityQueue* pq, Node* root) {
	int parrentPos = 0;
	int leftPos = 0;
	int rightPos = 0;

	memcpy(root, &pq->nodes[0], sizeof Node);
	memset(&pq->nodes[0], 0, sizeof Node);
	pq->usedSize--;
	swap(pq, 0, pq->usedSize);

	leftPos = getLeftChildIdx(0);
	rightPos = leftPos + 1;
	
	while (1) {
		int selectedOne = 0;
		if (leftPos >= pq->usedSize)
			break;

		if (rightPos >= pq->usedSize) {
			selectedOne = leftPos;
		}
		else {
			if (pq->nodes[leftPos].priority > pq->nodes[rightPos].priority) {
				selectedOne = rightPos;
			}
			else {
				selectedOne = leftPos;
			}
		}

		if (pq->nodes[selectedOne].priority < pq->nodes[parrentPos].priority) {
			swap(pq, selectedOne, parrentPos);
			parrentPos = selectedOne;
		}
		else
			break;
		leftPos = getLeftChildIdx(parrentPos);
		rightPos = leftPos + 1;
	};

};
int getParentIdx(int index) {
	return (index - 1) / 2;
};
int getLeftChildIdx(int index) {
	return index * 2 + 1;
};
void swap(PriorityQueue* pq, int idx1, int idx2) {
	int size = sizeof Node;
	Node* temp = (Node*)malloc(size);
	memcpy(temp, &pq->nodes[idx1], size);
	memcpy(&pq->nodes[idx1], &pq->nodes[idx2], size);
	memcpy(&pq->nodes[idx2], temp, size);
	free(temp);
};
int isEmpty(PriorityQueue* pq) {
	return (pq->usedSize == 0);
};

void showAll(PriorityQueue* pq) {
	Node poped;
	for (int i = 0; i < 10; i++) {
		dequeue(pq, &poped);
		printf("%s : 이름, %d : priority\n",poped.data,poped.priority);
	}
};

void main() {

	PriorityQueue* pq = create(10);
	Node nodes[10] = {
		{ 5,(void*)"5번할일" },
		{ 10,(void*)"10번할일" },
		{ 9,(void*)"9번할일" },
		{ 8,(void*)"8번할일" },
		{ 7,(void*)"7번할일" },
		{ 6,(void*)"6번할일" },
		{ 4,(void*)"4번할일" },
		{3,(void*)"3번할일"},
		{ 1,(void*)"1번할일" },
		{ 2,(void*)"2번할일" }
	};
	for (int i = 0; i < (sizeof(nodes) / sizeof(nodes[0])); i++) {
		enqueue(pq, nodes[i]);
	}
	showAll(pq);
	destroy(pq);

}
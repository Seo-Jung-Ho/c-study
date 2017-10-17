#include "PriorityQueue.h"

PriorityQueue* create(int initialSize) {
	PriorityQueue* newPQ = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	newPQ->capacity = initialSize;
	newPQ->usedSize = 0;
	newPQ->nodes = (PQNode*)malloc(sizeof(PQNode) * initialSize);
	return newPQ;
}

void destroy(PriorityQueue* pq) {
	free(pq->nodes);
	free(pq);
};

void enqueue(PriorityQueue* pq, PQNode newData) {
	int currentPos = pq->usedSize;
	int parrentPos = getPerent(currentPos);

	if (pq->usedSize == pq->capacity) {
		if (pq->capacity == 0)
			pq->capacity = 1;

		pq->capacity *= 2;
		pq->nodes = (PQNode*)realloc(pq->nodes, sizeof(PQNode)*pq->capacity);
	}

	pq->nodes[currentPos] = newData;

	while (currentPos > 0
		&& pq->nodes[currentPos].priority < pq->nodes[parrentPos].priority) {
		swapNodes(pq, currentPos, parrentPos);
		currentPos = parrentPos;
		parrentPos = getPerent(currentPos);
	}
	pq->usedSize++;
};

void swapNodes(PriorityQueue* pq, int index1, int index2) {
	int copySize = sizeof(PQNode);
	PQNode* temp = (PQNode*)malloc((copySize));

	memcpy(temp, &pq->nodes[index1], copySize); // temp¿¡ º¹»ç
	memcpy(&pq->nodes[index1], &pq->nodes[index2], copySize);
	memcpy(&pq->nodes[index2], temp, copySize);

	free(temp);
};

void dequeue(PriorityQueue* pq, PQNode* root) {
	int parentPos = 0, leftPos = 0, rightPos = 0;
	memcpy(root, &pq->nodes[0], sizeof(PQNode));
	memset(&pq->nodes[0], 0, sizeof(PQNode));

	pq->usedSize--;
	swapNodes(pq, 0, pq->usedSize);
	leftPos = getLeftChilde(0);
	rightPos = leftPos + 1;

	while (1) {
		int selectedChilde = 0;
		if (leftPos >= pq->usedSize)
			break;

		if (rightPos >= pq->usedSize) {
			selectedChilde = leftPos;
		}
		else {
			if (pq->nodes[leftPos].priority >
				pq->nodes[rightPos].priority)
				selectedChilde = rightPos;
			else
				selectedChilde = leftPos;
		}

		if (pq->nodes[selectedChilde].priority < pq->nodes[parentPos].priority) {
			swapNodes(pq, parentPos, selectedChilde);
			parentPos = selectedChilde;
		}
		else
			break;

		leftPos = getLeftChilde(parentPos);
		rightPos = leftPos + 1;
	}

	if (pq->usedSize < (pq->capacity / 2)) {
		pq->capacity /= 2;
		pq->nodes = (PQNode*)realloc(pq->nodes, sizeof(PQNode) * pq->capacity);
	}
}

int getPerent(int index) {
	return (int)((index - 1) / 2);
};

int getLeftChilde(int index) {
	return (2 * index) + 1;
};

int isEmpty(PriorityQueue* pq) {
	return(pq->usedSize == 0);
};

void printNode(PQNode* node) {
	printf("task name : %s (priority : %d)\n", node->data, node->priority);
}

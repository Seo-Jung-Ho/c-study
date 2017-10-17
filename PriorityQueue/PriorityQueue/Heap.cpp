#include "Heap.h"

Heap* createHeap(int initSize) {
	Heap* newHeap = (Heap*)malloc(sizeof(Heap));
	newHeap->usedSize = 0;
	newHeap->capacity = initSize;
	newHeap->nodes = (HeapNode*)malloc((sizeof(HeapNode)) * initSize);
	return newHeap;
};
void destroyHeap(Heap* h) {
	free(h->nodes);
	free(h);
};
void insertHeap(Heap* h, ElementType newData) {
	int currentPos = h->usedSize;
	int parentPos = getParent(h->usedSize);

	if (h->usedSize == h->capacity) {
		h->capacity *= 2;
		h->nodes = (HeapNode*)realloc(h->nodes, sizeof(HeapNode) * h->capacity);
	}
	
	//삽입처리
	h->nodes[currentPos].data = newData;

	while (currentPos > 0 && h->nodes[currentPos].data < h->nodes[parentPos].data) {
		swapNodes(h, currentPos, parentPos);
		currentPos = parentPos;
		parentPos = getParent(currentPos);
	}
	h->usedSize++;
};
void deleteMin(Heap* h, HeapNode* root) {
	int parentPos = 0;
	int leftPos = 0;
	int rightPos = 0;

	memcpy(root, &h->nodes[0], sizeof HeapNode);
	memset(&h->nodes[0], 0, sizeof HeapNode);
	h->usedSize--;
	swapNodes(h, 0, h->usedSize);
	leftPos = getLeftChild(0);
	rightPos = leftPos + 1;

	while (true) {
		int selectedChild = 0;

		if (leftPos >= h->usedSize)
			break;

		if (rightPos >= h->usedSize) {
			selectedChild = leftPos;
		}
		else {
			if (h->nodes[leftPos].data > h->nodes[rightPos].data) {
				selectedChild = rightPos;
			}else{
				selectedChild = leftPos;
			}
		}

		if (h->nodes[selectedChild].data < h->nodes[parentPos].data) {
			swapNodes(h, parentPos, selectedChild);
			parentPos = selectedChild;
		}
		else
			break;


		leftPos = getLeftChild(parentPos);
		rightPos = leftPos + 1;
	}

};
int getParent(int index) {
	return (index - 1) / 2;
};
int getLeftChild(int index) {
	return (index * 2) + 1;
};
void swapNodes(Heap* h, int index1, int index2) {
	//temp를 만들어서 둘의 주소를 교환 하고 탬프 해제
	int copySize = sizeof HeapNode;
	HeapNode* temp = (HeapNode*)malloc(copySize);
	
	memcpy(temp, &h->nodes[index1], copySize);
	memcpy(&h->nodes[index1], &h->nodes[index2], copySize);
	memcpy(&h->nodes[index2], temp, copySize);
	free(temp);
};
void showAll(Heap* h) {
	int depth = 0;
	for (int i = 0; i < h->usedSize  ; i++) {
		depth = log2(i + 1);
		for (int j = 0; j < depth; j++) {
			printf("  ");
		}
		printf("%d\n", h->nodes[i].data);
	}
};

void main() {
	Heap* h = createHeap(30);
	HeapNode minNode;
	for (int i = 10; i < 100; i += 10) {
		insertHeap(h, i);
	}
	deleteMin(h, &minNode);
	deleteMin(h, &minNode);
	deleteMin(h, &minNode);
	showAll(h);
	destroyHeap(h);
}

// 0 -> 0
// 1 -> 1
// 2-> 3;
//3 ->7
// 4 15
#include <stdio.h>
#include <stdlib.h>

void Merge(int dataset[], int startIndex, int middleIndex, int endIndex) {
	int i = 0;
	int leftIndex = startIndex;
	int rightIndex = endIndex + 1;
	int destIndex = 0;

	int* destination = (int*)malloc(sizeof(int) * (endIndex - startIndex + 1));

	while (leftIndex <= middleIndex && rightIndex <= endIndex) {
		if (dataset[leftIndex] < dataset[rightIndex]);
	}
};
void MergeSort(int dataset[], int startIndex, int endIndex) {
	if (endIndex - startIndex < 1)
		return;

	int middleIndex = (startIndex + endIndex) / 2;

	MergeSort(dataset, startIndex, middleIndex);
	MergeSort(dataset, middleIndex + 1, endIndex);

	Merge(dataset, startIndex, middleIndex, endIndex);
};
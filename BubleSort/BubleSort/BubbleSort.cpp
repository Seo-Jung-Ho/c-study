#include<stdio.h>

void bubbleSort(int dataSet[], int length) {
	int temp = 0;
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - (i+1); j ++) {
			if (dataSet[j] > dataSet[j + 1]) {
				temp = dataSet[j];
				dataSet[j] = dataSet[j + 1];
				dataSet[j + 1] = temp;
			}
		}
	}

}

void main() {
	int dataSet[] = { 6,4,2,3,0,9,8,5 };
	int length = sizeof dataSet / sizeof dataSet[0];
	bubbleSort(dataSet, length);
	for (int i = 0; i < length; i++) {
		printf("%d", dataSet[i]);
	};

	printf("\n");
}
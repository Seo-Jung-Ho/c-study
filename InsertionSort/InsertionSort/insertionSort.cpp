#include <stdio.h>
#include <string.h>

void insertionSort(int dataSet[], int lenght) {
	int value = 0;

	for (int i = 1; i < lenght; i++) {
		if (dataSet[i - 1] <= dataSet[i])
			continue;

			value = dataSet[i];
			for (int j = 0; j < i; j++) {
				if (dataSet[j] > value) {
					memmove(&dataSet[j + 1], &dataSet[j], sizeof(dataSet[0])*(i - j));
					dataSet[j] = value;
					break;
				}
			}
			for (int i = 0; i < lenght; i++) {
				printf("%d  ", dataSet[i]);
			}
			printf("\n");
	};
};

void printData(int dataSet[], int length) {

}

void main() {

	int dataSet[] = { 9,8,7,5,4,3 };
	int length = sizeof dataSet / sizeof dataSet[0];

	insertionSort(dataSet, length);
	
	

}
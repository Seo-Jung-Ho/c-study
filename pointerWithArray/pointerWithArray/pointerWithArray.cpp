#include <stdio.h>
#include <stdlib.h>

void main() {

	int width = 0;
	int height = 0;
	scanf_s("%d", &width);
	scanf_s("%d", &height);

	int **numPtr = (int**)malloc(sizeof(int) * height);

	for (int i = 0; i < height; i++) {
		numPtr[i] = (int*)malloc(sizeof(int) * width);
		for (int i2 = 0; i2 < width; i2++) {
			numPtr[i][i2] = i == i2 ? 1 : 0;
		}
	}

	for (int i = 0; i < height; i++) {
		for (int i2 = 0; i2 < width; i2++) {
			printf("%d", numPtr[i][i2]);
		}
		printf("\n");
	}

	// d b

	for (int i = 0; i < height; i++) {
		free(numPtr[i]);
	}
	free(numPtr);

}
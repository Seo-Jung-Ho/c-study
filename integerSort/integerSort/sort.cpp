#include <stdio.h>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void main() {
	int num[10] = {10,9,8,7,6,5,4,3,2,1 };

	for (int i = 0; i < sizeof(num) / sizeof(int) - 1; i++) {
		for (int j = 0; j < sizeof(num) / sizeof(int) - 1; j++) {
			if (num[j]  > num[j + 1]) {
				swap(num[j], num[j + 1]);
			}
		}
		for (int i2 = 0; i2 < sizeof(num) / sizeof(int); i2++) {
			printf("%d,", num[i2]);
			if ((i2 + 1) == sizeof(num) / sizeof(int)) {
				printf("\n");
			}
		}
	}

	

}
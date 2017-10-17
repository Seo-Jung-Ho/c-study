#include <stdio.h>
#include <time.h>
#include <iostream>

typedef unsigned long long ULONG;
typedef struct tagMatrix2x2 {
	ULONG data[2][2];
}Matrix;

ULONG fibonacci(int n) {
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;

	return fibonacci(n - 1) + fibonacci(n - 2);
}

Matrix matrixMultiply(Matrix m1, Matrix m2) {
	Matrix result;

	result.data[0][0] = m1.data[0][0] * m2.data[0][0] + m1.data[0][1] * m2.data[1][0];
	result.data[0][1] = m1.data[0][0] * m2.data[1][0] + m1.data[0][1] * m2.data[1][1];
	result.data[1][0] = m1.data[1][0] * m2.data[0][0] + m1.data[1][1] * m2.data[1][0];
	result.data[1][1] = m1.data[1][0] * m2.data[1][0] + m1.data[1][1] * m2.data[1][1];

	return result;
}

Matrix MPower(Matrix a, int n) {
	if (n > 1) {
		a = MPower(a, n / 2);
		a = matrixMultiply(a, a);

		if (n & 1) {
			Matrix b;
			b.data[0][0] = 1; b.data[0][1] = 1;
			b.data[1][0] = 1; b.data[1][1] = 0;

			a = matrixMultiply(a, b);
		}
	}
	return a;
}

ULONG fibonacci2(int n) {
	Matrix a;
	a.data[0][0] = 1; a.data[0][1] = 1;
	a.data[1][0] = 1; a.data[1][1] = 0;
	a = MPower(a, n);
	return a.data[0][1];
}

void main() {

	clock_t begin, end;
	begin = clock();        // 시간설정
	printf("%lld\n", fibonacci(40));
	end = clock();          // 시간설정
	printf("수행시간 : %d ms\n", end - begin / CLOCKS_PER_SEC);

	clock_t begin2, end2;

	begin2 = clock();        // 시간설정
	printf("%lld\n", fibonacci2(40));
	end2 = clock();          // 시간설정
	printf("수행시간 : %d ms\n", end2 - begin2 / CLOCKS_PER_SEC);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {

	//malloc == memory allocation
	// variable �� stack ������ ����ǰ�
	// malloc function�� heap ������ ����ȴ�
	// �ݵ�� ���� ó���� ����ߵȴ�

	//int num = 20;
	//int *numPtr;

	//numPtr = &num;

	//int *numPtr2;
	//numPtr2 = (int*) malloc(sizeof(int)); // int�� ũ�� 4byte ��ŭ�� ���� �޸� �Ҵ�
	//*numPtr2 = 123;
	//printf("%p\n", numPtr);
	//printf("%p\n", numPtr2);
	//printf("%d\n", *numPtr2);

	//memset(numPtr2, 1, 3); // numptr �� ����Ű�� �޸𸮸� 3���� �Ķ���� ����Ʈ��ŭ 2��° �Ķ���� �� ����
	//printf("%d\n", *numPtr2);

	//free(numPtr2); // ���� �޸� ����

	int num1;
	int num2;

	scanf_s("%d %d", &num1, &num2);

	int *numPtr1 = (int*)malloc(sizeof(int));
	int *numPtr2 = (int*)malloc(sizeof(int));

	*numPtr1 = num1;
	*numPtr2 = num2;

	printf("%d\n",*numPtr1 + *numPtr2);

	free(numPtr1);
	free(numPtr2);
}
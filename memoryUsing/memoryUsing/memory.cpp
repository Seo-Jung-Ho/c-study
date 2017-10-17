#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {

	//malloc == memory allocation
	// variable 은 stack 영역에 저장되고
	// malloc function은 heap 영역에 저장된다
	// 반드시 해제 처리를 해줘야된다

	//int num = 20;
	//int *numPtr;

	//numPtr = &num;

	//int *numPtr2;
	//numPtr2 = (int*) malloc(sizeof(int)); // int의 크기 4byte 만큼의 동적 메모리 할당
	//*numPtr2 = 123;
	//printf("%p\n", numPtr);
	//printf("%p\n", numPtr2);
	//printf("%d\n", *numPtr2);

	//memset(numPtr2, 1, 3); // numptr 이 가르키는 메모리를 3번쨰 파라미터 바이트만큼 2번째 파라미터 로 설정
	//printf("%d\n", *numPtr2);

	//free(numPtr2); // 동적 메모리 해제

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
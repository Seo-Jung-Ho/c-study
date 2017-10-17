#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	//char *string = "Hello World!!";
	//printf("%s \n",string);

	//char string2[] = "I am \n a boy";
	//string2[1] = 's';
	//printf("%s", string2);

	char *s = (char*)malloc(sizeof(char) * 1000);
	char *s2 = (char*)malloc(sizeof(char) * 1000);

	scanf("%s %s", s,s2);
	printf("%s \n", s);
	printf("%s \n", s2);
	//printf("%d \n", strlen(s2));

	strcat(s2, s);

	printf("%s\n", s2);
	//if (strcmp(s, s2) == 0) {
	//	printf("문자열이 같습니다");
	//}
	//else {
	//	printf("문자열이 다름니다");
	//}


	free(s);
	free(s2);
}
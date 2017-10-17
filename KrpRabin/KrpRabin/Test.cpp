#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include "KarpRabin.h"

#define MAX_BUFFER 512

int main(int argc, char** argv) {
	char* filePath;
	FILE* fp;

	char text[MAX_BUFFER];
	char* pattern;
	int patternSize = 0;
	int line = 0;

	if (argc < 3) {
		printf("usage : %s <filepath> <pattern>\n", argv[0]);
		return 1;
	}

	filePath = argv[1];
	pattern = argv[2];

	patternSize = strlen(pattern);

	if ((fp = fopen(filePath, "r")) == NULL) {
		printf("cannot open file : %s\n", filePath);
		return 1;
	}

	while (fgets(text,MAX_BUFFER,fp) != NULL) { // 파일을 처음부터 끝까지 한줄씩 읽으며 함수를 호출
		int position = KarpRabin(text, strlen(text), 0, pattern, patternSize);
		line++;
		if (position >= 0) {
			printf("line : %d, column : %d : %s", line, position, text);
		}
	}
	fclose(fp);

	return 0;
}
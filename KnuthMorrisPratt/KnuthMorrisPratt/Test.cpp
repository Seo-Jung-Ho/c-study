#define _CRT_SECURE_NO_WARNINGS
#include "KruthMorrisPratt.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER 512

void main(int argc, char** argv) {

	char* filePath;
	FILE* fp;

	char text[MAX_BUFFER];
	char* pattern;
	int patternSize = 0;
	int line = 0;

	if (argc < 3) {
		printf("argv is incorrect\n");
		return;
	}
	filePath = argv[1];
	pattern = argv[2];

	patternSize = strlen(pattern);

	if ( (fp = fopen(filePath, "r")) == NULL) {
		printf("cannot read file : %s\n", filePath);
		return;
	}

	while (fgets(text, MAX_BUFFER, fp) != NULL) {
		int position = KnuthMorrisPratt(text, strlen(text), 0, pattern, patternSize);
		line++;
		if (position >= 0) {
			printf("line : %d, column : %d  : %s\n", line, position + 1, text);
		}
	}
	fclose(fp);
}
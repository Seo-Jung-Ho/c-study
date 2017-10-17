#include "KruthMorrisPratt.h"
#include <stdlib.h>

int KnuthMorrisPratt(char* text, int textSize, int start, char* pattern, int patternSize) {

	int i = start;
	int j = 0;
	int position = -1;

	//calloc �迭�� ���� �Ҵ��Ҷ� ������ָ� ����
	int* border = (int*)calloc(patternSize + 1, sizeof(int));

	Preprocess(pattern, patternSize, border);

	/*printf("pre processed table \n");
	for (int k = 0; k < sizeof(border) / sizeof(int*); k++) {
		printf("%d\n", border[k]);
	}*/

	while (i < textSize) {
		//printf("1\n");
		while (j >= 0 && text[i] != pattern[j]) {
			//printf("2\n");
			j = border[j];
		}

		i++;
		j++;

		if (j == patternSize) {
			position = i - j;
			break;
		}
	}

	free(border);
	return position;
};

/**
	���Ͽ� ���� �˻����ϱ����� ���ڿ� ��ü�� �м��س��°�
*/
void Preprocess(char* pattern, int patternSize, int* border) {
	//border = ��ġ���θ� ���� �ϴ� table
	int i = 0; 
	int j = -1;

	border[0] = -1;

	while (i < patternSize) {
		//printf("3\n");
		while (j > -1 && pattern[i] != pattern[j]) {
			//printf("4\n");
			j = border[j];
		}
		i++;
		j++;
		border[i] = j;
	}
};
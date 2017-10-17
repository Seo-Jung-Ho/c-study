#include "BoyerMoore.h"
#include <stdlib.h>

int BoyerMoore(char* text, int textSize, int start, char* pattern, int patternSize) {
	int bct[128];
	int* suffix = (int*)calloc(patternSize + 1, sizeof(int));
	int* gst = (int*)calloc(patternSize + 1, sizeof(int));
	int i = start;
	int j = 0; 

	int pos = -1;

	BadCharacter(pattern, patternSize, bct);
	GoodSuffix(pattern, patternSize, suffix, gst);

	while (i <= textSize - patternSize) {

		j = patternSize - 1;

		while (j >= 0 && pattern[j] == text[i + j])
			j--;

		//printf("j is : %d\n", j);

		if (j < 0) {
			pos = i;
			break;
		}
		else {
			i += Max(gst[j + 1], j - bct[text[i + j]]);
		}
	}

	/*printf("gst is \n");
	for (int k = 0; k < sizeof(gst) / sizeof(int*); k++) {
		printf("k : %d\n", k);
	}*/

	free(suffix);
	free(gst);

	return pos;
};

void BadCharacter(char* pattern, int patternSize, int* bct) {
	//128인 이유? asc code 값이기때문에??
	int i;
	int j;
	for (i = 0; i < 128; i++)
		bct[i] = -1; //배열을 기본값 -1(매칭되지 않음) 으로 초기화
	for (j = 0; j < patternSize; j++)
		bct[pattern[j]] = j; // 테이블에 asc코드값의 index를 넣어둬 
};
void GoodSuffix(char* pattern, int patternSize, int* suffix, int* gst) {
	
	/* case 1 */
	int i = patternSize;
	int j = patternSize + 1;

	suffix[i] = j; //패턴의 마지막은 패턴 사이즈 + 1?

	while (i > 0) { //pattern 전체 루프
		
		while (j <= patternSize && pattern[i - 1] != pattern[j - 1]) {

			if (gst[i] == 0)
				gst[j] = j - 1;

			j = suffix[j];
		}
		i--;
		j--;

		suffix[i] = j;
	}

	/* case 2 */
	j = suffix[0];
	for (i = 0; i <= patternSize; i++) {
		if (gst[i] == 0)
			gst[i] = j;

		if (i == j)
			j = suffix[j];
	}
};

int Max(int a, int b) {
	if (a > b) 
		return a;
	else
		return b;
};
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
	//128�� ����? asc code ���̱⶧����??
	int i;
	int j;
	for (i = 0; i < 128; i++)
		bct[i] = -1; //�迭�� �⺻�� -1(��Ī���� ����) ���� �ʱ�ȭ
	for (j = 0; j < patternSize; j++)
		bct[pattern[j]] = j; // ���̺� asc�ڵ尪�� index�� �־�� 
};
void GoodSuffix(char* pattern, int patternSize, int* suffix, int* gst) {
	
	/* case 1 */
	int i = patternSize;
	int j = patternSize + 1;

	suffix[i] = j; //������ �������� ���� ������ + 1?

	while (i > 0) { //pattern ��ü ����
		
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
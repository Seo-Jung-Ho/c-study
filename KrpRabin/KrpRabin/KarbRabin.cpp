#include "KarpRabin.h"
#include <stdio.h>
#include <math.h>

int KarpRabin(char* text, int textSize, int start, char* pattern, int patternSize) {
	int i = 0;
	int j = 0;
	int coefficent = pow(2.0, patternSize - 1); //2의 m-1 승

	int hashText = Hash(text, patternSize);
	int hashPattern = Hash(pattern, patternSize);

	for (i = start; i < textSize - patternSize; i++) {
		hashText = Rehash(text, i, patternSize, hashText, coefficent);

		if (hashPattern == hashText) {
			printf("hash값 일치 확인 \n");
			for (j = 0; j < patternSize; j++) {
				if (text[i + j] != pattern[j])
					break;
			}
			if (j >= patternSize)
				return i;
		}
	}
	return -1;
}
int Hash(char* string, int size) {
	int i = 0;
	int hashValue = 0;
	
	for (i = 0; i < size; i++) {
		hashValue += (string[i] * pow(2.0, size - (1 + i)));
	}
	return hashValue;
};
int Rehash(char* string, int start, int size, int hashPrev, int coefficient) {
	if (start == 0)
		return hashPrev;

	return string[start + size - 1] + ((hashPrev - coefficient * string[start - 1]) * 2);
};
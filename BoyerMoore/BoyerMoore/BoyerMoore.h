#include <stdio.h>

int BoyerMoore(char* text, int textSize, int start, char* pattern, int patternSize);

void GoodSuffix(char* pattern, int patternSize, int* suffix, int* gst);
void BadCharacter(char* pattern, int patternSize, int* bst);

int Max(int a, int b);
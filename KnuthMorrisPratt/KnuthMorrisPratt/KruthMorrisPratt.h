#include <stdio.h>

int KnuthMorrisPratt(char* text, int textSize, int start, char* pattern, int patternSize);
void Preprocess(char* pattern, int patternSize, int* border);
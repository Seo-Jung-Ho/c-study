#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* KeyType;
typedef char* ValueType;

enum ElementStatus {
	EMPTY = 0,
	OCCUPIED = 1
};

typedef struct tagElementType {
	KeyType key;
	ValueType value;
	enum ElementStatus status;
} ElementType;

typedef struct tagHashTable {
	int occupiedCnt;
	int tableSize;
	ElementType* table; //테이블의 배열
}HashTable;

HashTable* createHashTable(int tableSize);
void destoryhashTable(HashTable* ht);
void clearElement(ElementType* ele);

void set(HashTable** ht, KeyType key, ValueType value);
ValueType get(HashTable* ht, KeyType key);
int hash(KeyType key, int keyLength, int tableSize);
int hash2(KeyType key, int keyLength, int tableSize);

void rehash(HashTable** ht);



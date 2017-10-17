#ifndef SIMPLE_HASHTABLE_H
#define SIMPLE_HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>

typedef int keyType;
typedef int valueType;

typedef struct tagNode {
	keyType key;
	valueType value;
}node;

typedef struct tagHashTable {
	int tableSize;
	node* table;
} hashTable;

hashTable* createHashTable(int tableSize);
void set(hashTable* ht, keyType key, valueType val);
valueType get(hashTable* ht, keyType key);
void destroy(hashTable* ht);
int hash(keyType key, int tableSize);


#endif

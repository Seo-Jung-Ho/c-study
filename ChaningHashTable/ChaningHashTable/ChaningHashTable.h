#pragma once

#include <stdio.h>
#include <stdlib.h>
#include<string.h>


typedef char* KeyType;
typedef char* ValueType;

typedef struct tagNode {
	KeyType key;
	ValueType val;
	struct tagNode* next;
}Node;

typedef Node* List;

typedef struct tagHashTable {
	int tableSize;
	List* table;
} HashTable;


HashTable* create(int tableSize);
void set(HashTable* ht, KeyType key, ValueType val);
ValueType get(HashTable* ht, KeyType key);
int hash(KeyType key, int keyLength, int tableSize);
Node* createNode(KeyType key, ValueType val);
void destroyNode(Node* node);
void destroyList(List list);
void destroy(HashTable* ht);


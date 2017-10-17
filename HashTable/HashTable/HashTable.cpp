#include "SimpleHashTable.h"

hashTable* createHashTable(int tableSize) {
	hashTable* ht = (hashTable*)malloc(sizeof(hashTable));
	ht->table = (node*)malloc(sizeof(node)*tableSize);
	ht->tableSize = tableSize;
	return ht;
};
void set(hashTable* ht, keyType key, valueType val) {
	int address = hash(key, ht->tableSize);
	ht->table[address].key = key;
	ht->table[address].value = val;
};

valueType get(hashTable* ht, keyType key) {
	int address = hash(key, ht->tableSize);
	return ht->table[address].value;
};

void destroy(hashTable* ht) {
	free(ht->table);
	free(ht);
};
int hash(keyType key, int tableSize) {
	return key % tableSize;
};

void main() {
	hashTable* ht = createHashTable(193);
	set(ht, 100, 100);
	set(ht, 200, 200);
	set(ht, 300, 300);
	set(ht, 400, 400);
	
	printf("key : %d, value :%d\n", 100, get(ht, 100));
	printf("key : %d, value :%d\n", 200, get(ht, 200));
	printf("key : %d, value :%d\n", 300, get(ht, 300));
	printf("key : %d, value :%d\n", 400, get(ht, 400));

	destroy(ht);
}
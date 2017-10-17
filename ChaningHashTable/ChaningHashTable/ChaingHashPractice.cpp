#define _CRT_SECURE_NO_WARNINGS
#include "ChaningHashTable.h"

HashTable* create(int tableSize) {
	HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
	ht->table = (List*)malloc(sizeof(List)*tableSize);
	memset(ht->table, 0, sizeof(List)*tableSize);
	ht->tableSize = tableSize;
	return ht;
};
void set(HashTable* ht, KeyType key, ValueType val) {
	int address = hash(key, strlen(key), ht->tableSize);
	Node* newNode = createNode(key, val);
	if (ht->table[address] == NULL) {
		ht->table[address] = newNode;
	}else{
		List list = ht->table[address];
		newNode->next = list;
		ht->table[address] = newNode;
		printf("collision occured : key %s, address %d \n", key, address);
	}
};
ValueType get(HashTable* ht, KeyType key) {
	int address = hash(key, strlen(key), ht->tableSize);
	List list = ht->table[address];
	List target = NULL;
	if (list == NULL)
		return NULL;
	while (1) {
		if (strcmp(key, list->key) == 0) {
			target = list;
			break;
		}

		if (list->next == NULL) {
			return NULL;
		}
		else {
			list = list->next;
		}

	}
	return target->val;
};
Node* createNode(KeyType key, ValueType val) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = (char*)malloc(sizeof(char) * (strlen(key) + 1));
	strcpy(newNode->key, key);
	newNode->val = (char*)malloc(sizeof(char) * (strlen(val) + 1));
	strcpy(newNode->val, val);
	newNode->next = NULL;
	return newNode;
};
void destroyNode(Node* node) {

	free(node->key);
	free(node->val);
	free(node);

};

void destroyList(List list) {
	if (list == NULL)
		return;
	if (list->next != NULL) {
		destroyList(list->next);
		printf("?");
	}

	destroyNode(list);
};
void destroy(HashTable* ht) {
	int i = 0;
	for (i = 0; i < ht->tableSize; i++) {
		destroyList(ht->table[i]);
	}
	free(ht->table);
	free(ht);
};

int hash(KeyType key, int keyLength, int tableSize) {
	int i = 0;
	int hashValue = 0;
	for (i = 0; i < keyLength; i++) {
		hashValue = (hashValue << 3) + key[i];
	}
	hashValue = hashValue % tableSize;
	return hashValue;
};

void main() {

	HashTable* ht = create(12289);
	set(ht, "MSFT", "microsoft");
	set(ht, "APAC", "apppppca");
	set(ht, "ZYMZZ", "what is this");
	set(ht, "JAVA", "this is java~");

	printf("key %s, val %s \n", "MSFT", get(ht, "MSFT"));
	printf("key %s, val %s \n", "APAC", get(ht, "APAC"));
	printf("key %s, val %s \n", "ZYMZZ", get(ht, "ZYMZZ"));
	printf("key %s, val %s \n", "JAVA", get(ht, "JAVA"));

	destroy(ht);
}
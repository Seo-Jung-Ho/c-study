//#define _CRT_SECURE_NO_WARNINGS
//#include "ChaningHashTable.h"
//
//HashTable* create(int tableSize) {
//	HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
//	ht->table = (List*)malloc(sizeof(List*) * tableSize);
//	ht->tableSize = tableSize;
//	memset(ht->table, 0, sizeof(List)*tableSize); //?이게 왜 필요하지?
//	return ht;
//};
//Node* createNode(KeyType key, ValueType val) {
//	Node* node = (Node*)malloc(sizeof(Node));
//	node->key = (char*)malloc(sizeof(char) * (strlen(key) + 1) );
//	strcpy(node->key, key);
//	node->val = (char*)malloc(sizeof(char) * (strlen(val) + 1) );
//	strcpy(node->val, val);
//
//	node->next = NULL;
//	return node;
//};
//void set(HashTable* ht, KeyType key, ValueType val) {
//	int address = hash(key, strlen(key), ht->tableSize);
//	Node* newNode = createNode(key, val);
//	if (ht->table[address] == NULL) {//안충돌
//		//ht->table[address] 
//		ht->table[address] = newNode;
//	}
//	else {//충돌
//		List list = ht->table[address];
//		newNode->next = list;
//		ht->table[address] = newNode;
//		printf("collision occured : key %s, address %d \n", key, address);
//	}
//};
//ValueType get(HashTable* ht, KeyType key) {
//	int address = hash(key, strlen(key), ht->tableSize);
//	List list = ht->table[address];
//	Node* head = list;
//	while (1) {
//		if (strcmp(head->key, key) == 0) {
//			return head->val;
//		}
//		if (head->next == NULL) {
//			return NULL;
//		}
//		else {
//			head = head->next;
//		}
//	}
//};
//int hash(KeyType key, int keyLength, int tableSize) {
//	int i = 0;
//	int hashValue = 0;
//	for (i = 0; i < keyLength; i++) {
//		hashValue = (hashValue << 3) + key[i];
//	}
//	hashValue = hashValue % tableSize;
//	return hashValue;
//};
//void destroyNode(Node* node) {
//	free(node->key);
//	free(node->val);
//	free(node->next);
//}
//void destroyList(List list) {
//	if (list == NULL)
//		return;
//	if (list->next != NULL)
//		destroyList(list->next);
//
//	destroyNode(list);
//};
//void destroy(HashTable* ht) {
//	int i = 0;
//	for (i = 0; i < ht->tableSize; i++) {
//		List list = ht->table[i];
//		destroyList(list);
//	}
//};
//

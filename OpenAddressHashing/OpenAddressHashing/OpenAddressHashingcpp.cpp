//#define _CRT_SECURE_NO_WARNINGS
//#include "OpenAddressHashing.h"
//
//HashTable* createHashTable(int tableSize) {
//	HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
//	ht->tableSize = tableSize;
//	ht->occupiedCnt = 0;
//	ht->table = (ElementType*)malloc(sizeof(ElementType) * tableSize);
//	//���̺� ������ �ʱ�ȭ
//	memset(ht->table, 0, sizeof(ElementType)*tableSize);
//	return ht;
//};
//void destoryhashTable(HashTable* ht) {
//
//	//�� ��ũ�� ����Ʈ�� ���� ����ҿ��� ����
//	for (int i = 0; i < ht->tableSize; i++) {
//		clearElement(&(ht->table[i]));
//	}
//
//	//�ؽ� ���̺��� �޸𸮿��� ����
//	free(ht->table);
//	free(ht);
//};
//
//void clearElement(ElementType* ele) {
//	if (ele->status == EMPTY)
//		return;
//	free(ele->key);
//	free(ele->value);
//};
//
//void set(HashTable** ht, KeyType key, ValueType value) {
//
//	//�������� ����
//	int keyLen, address, stepSize;
//	double usage;
//	usage = (double)(*ht)->occupiedCnt / (*ht)->tableSize;
//
//	//��뷮 Ȯ���� rehash���� Ȯ��
//	if (usage > 0.5) {
//		rehash(ht);
//	}
//
//	//�ּҰ� ���
//	//�浹�� �� ��쿡�� ��� ���ǻ����ŭ �̵�
//	keyLen = strlen(key);
//	address = hash(key, keyLen, (*ht)->tableSize);
//	stepSize = hash2(key, keyLen, (*ht)->tableSize);
//
//	//printf("address : %d \n", address);
//	while ((*ht)->table[address].status != EMPTY && strcmp((*ht)->table[address].key, key) != 0) {
//		printf("Collision occured!! : key (%s), address(%d)", key, address);
//		address = (address + stepSize) % (*ht)->tableSize;
//	}
//
//	//set key,value
//	(*ht)->table[address].key = (char*)malloc(sizeof(char) * keyLen + 1);
//	strcpy((*ht)->table[address].key, key);
//	(*ht)->table[address].value = (char*)malloc(sizeof(char) * strlen(value) + 1);
//	strcpy((*ht)->table[address].value, value);
//
//	//table status , occupied cnt ++
//	(*ht)->table[address].status = OCCUPIED;
//	(*ht)->occupiedCnt++;
//
//	printf("key %s, entered at address %d \n", key, address);
//};
//
//ValueType get(HashTable* ht, KeyType key) {
//	int keyLen = strlen(key);
//
//	int address = hash(key, keyLen, (ht)->tableSize);
//	int stepSize = hash2(key, keyLen, (ht)->tableSize);
//
//	while ((ht)->table[address].status != EMPTY && strcmp( (ht)->table[address].key, key) != 0 ){
//		address = (address + stepSize) % (ht)->tableSize;
//	}
//
//	//printf("address : %d\n", address);
//
//	return ht->table[address].value;
//};
//
//int hash(KeyType key, int keyLength, int tableSize) {
//	int hashValue = 0;
//	for (int i = 0; i < keyLength; i++) {
//		hashValue = (hashValue << 3) + key[i];
//	}
//	hashValue = hashValue % tableSize;
//	return hashValue;
//};
//int hash2(KeyType key, int keyLength, int tableSize) {
//	int hashValue = 0;
//
//	for (int i = 0; i < keyLength; i++) {
//		hashValue = (hashValue << 2) + key[i];
//	}
//	hashValue = hashValue % (tableSize-3);
//	return hashValue + 1;
//
//};
//
//void rehash(HashTable** ht) {
//	
//	printf("\n");
//	printf("Starting rehash...\n");
//
//	//�������� ����
//	ElementType* oldTable = (*ht)->table;
//
//	//�� �ؽ� ���̺� ���� ( ������� 2�� )
//	HashTable* newTable = createHashTable((*ht)->tableSize * 2);
//
//	printf("new table size is %d\n", (*ht)->tableSize * 2);
//	printf("\n");
//	//���� �ؽ� ���̺� �����͸� ���� ���� ( ���̺� ����� �ٲ���⶧���� �ּҰ��� �ٲ� )
//	for (int i = 0; i < (*ht)->tableSize; i++) {
//		if (oldTable[i].status == OCCUPIED) {
//			set((&newTable), oldTable[i].key, oldTable[i].value);
//		}
//	}
//
//	//���� �ؽ� ���̺� �Ҹ�
//	destoryhashTable((*ht));
//
//	//���� �ؽ� ���̺��� ������ ������ �� �ؽ� ���̺��� ����
//	*ht = newTable;
//};
//
////void main() {
////	HashTable* ht = createHashTable(11);
////
////	set(&ht, "MSFT", "microsoft");
////	set(&ht, "APAC", "apache org");
////	set(&ht, "ZYMZZ", "what is this!!?");
////	set(&ht, "GOOG", "hello google!!");
////	set(&ht, "JAVA", "My first language");
////	set(&ht, "IBM", "lenovo");
////	set(&ht, "EVER", "eversong~");
////	
////	printf("\n");
////	printf("key: %s, value:%s \n", "MSFT", get(ht, "MSFT"));
////	printf("key: %s, value:%s \n", "APAC", get(ht, "APAC"));
////	printf("key: %s, value:%s \n", "ZYMZZ", get(ht, "ZYMZZ"));
////	printf("key: %s, value:%s \n", "GOOG", get(ht, "GOOG"));
////	printf("key: %s, value:%s \n", "JAVA", get(ht, "JAVA"));
////	printf("key: %s, value:%s \n", "IBM", get(ht, "IBM"));
////	printf("key: %s, value:%s \n", "EVER", get(ht, "EVER"));
////	printf("\n");
////	destoryhashTable(ht);
////}
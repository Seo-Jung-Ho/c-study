//#define _CRT_SECURE_NO_WARNINGS
//#include "OpenAddressHashing.h"
//
//HashTable* createHashTable(int tableSize) {
//	HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
//	ht->tableSize = tableSize;
//	ht->occupiedCnt = 0;
//	ht->table = (ElementType*)malloc(sizeof(ElementType) * tableSize);
//	//테이블 데이터 초기화
//	memset(ht->table, 0, sizeof(ElementType)*tableSize);
//	return ht;
//};
//void destoryhashTable(HashTable* ht) {
//
//	//각 링크드 리스트를 자유 저장소에서 제거
//	for (int i = 0; i < ht->tableSize; i++) {
//		clearElement(&(ht->table[i]));
//	}
//
//	//해시 테이블을 메모리에서 제거
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
//	//지역변수 설정
//	int keyLen, address, stepSize;
//	double usage;
//	usage = (double)(*ht)->occupiedCnt / (*ht)->tableSize;
//
//	//사용량 확인후 rehash여부 확인
//	if (usage > 0.5) {
//		rehash(ht);
//	}
//
//	//주소값 계산
//	//충돌이 날 경우에는 계속 스탭사이즈만큼 이동
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
//	//지역변수 설정
//	ElementType* oldTable = (*ht)->table;
//
//	//새 해시 테이블 생성 ( 사이즈는 2배 )
//	HashTable* newTable = createHashTable((*ht)->tableSize * 2);
//
//	printf("new table size is %d\n", (*ht)->tableSize * 2);
//	printf("\n");
//	//이전 해시 테이블 데이터를 새로 이전 ( 테이블 사이즈가 바뀌었기때문에 주소값도 바뀜 )
//	for (int i = 0; i < (*ht)->tableSize; i++) {
//		if (oldTable[i].status == OCCUPIED) {
//			set((&newTable), oldTable[i].key, oldTable[i].value);
//		}
//	}
//
//	//이전 해시 테이블 소멸
//	destoryhashTable((*ht));
//
//	//이전 해시 테이블의 포인터 변수에 새 해시 테이블을 대입
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
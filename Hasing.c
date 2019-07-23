#include <stdio.h>
#include <malloc.h>

#define LOAD_FACTOR 20

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct HashNode {
	int key;
	int count;
	struct Node* list;
}HashNode;

typedef struct HashTable {
	int size;
	int numofData;
	struct HashNode** table;
}HashTable;

HashTable *createHashTable(int tableSize) {

	HashTable* htable;
	htable = (HashTable*)malloc(sizeof(HashTable));
	if (!htable) {
		printf("Memory allocation Fail\n");
		return NULL;
	}

	htable->size = tableSize;
	htable->numofData = 0;
	htable->table = (HashNode **)malloc(sizeof(HashNode)*tableSize);

	if (!htable->table) {
		printf("Memory allocation Fail\n");
		return NULL;
	}

	for (int i = 0; i < tableSize; i++) {
		htable->table[i] = (HashNode*)malloc(sizeof(HashNode));
		if (!htable->table[i]) {
			printf("Memory allocation Fail\n");
			return NULL;
		}
		htable->table[i]->key = i;
		htable->table[i]->count = 0;
		htable->table[i]->list = NULL;
	}

	printf("Create Hash Table\n");
	return htable;
}

int GetKey(int data, int tableSize) {
	return data % tableSize;
}

int HashSearch(HashTable* hTable, int data) {
	Node* temp;
}

int main() {
	
	int tableSize;
	printf("Table Size 입력 : ");
	scanf("%d", &tableSize);

	HashTable *hTable = CreateHashTable(tableSize);
	printf("Insert Data\n");
	for (int i = 0; i < 100; i++) {
		HashInsert(hTable, i);
	}

	printHashTalbe(hTable);

	printf("delete data\n");
	for (int i = 0; i < 100; i++) {
		HashDelete(hTable, i);
	}

	printHashTalbe(hTable);
	
	DeleteHashTable(hTable);

	return 0;
}

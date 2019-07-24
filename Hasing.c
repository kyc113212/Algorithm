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

HashTable* CreateHashTable(int tableSize);
int GetKey(int data, int tableSize);
int HashSearch(HashTable* hTable, int data);
void HashInsert(HashTable* hTable, int data);
void HashDelete(HashTable* hTable, int data);
void DeleteHashTable(HashTable* hTable);
void PrintHashTable(HashTable* hTable);
HashTable* ReHash(HashTable* hTable);

int main() {

	int tableSize;
	printf("Table Size 입력 : ");
	scanf("%d", &tableSize);

	HashTable* hTable = CreateHashTable(tableSize);
	printf("Insert Data\n");
	for (int i = 0; i < 100; i++) {
		HashInsert(hTable, i);
	}

	PrintHashTable(hTable);

	printf("delete data\n");
	for (int i = 0; i < 100; i++) {
		HashDelete(hTable, i);
	}

	PrintHashTable(hTable);

	DeleteHashTable(hTable);

	return 0;
}

HashTable* CreateHashTable(int tableSize) {

	HashTable* htable;
	htable = (HashTable*)malloc(sizeof(HashTable));
	if (!htable) {
		printf("Memory allocation Fail\n");
		return NULL;
	}

	htable->size = tableSize;
	htable->numofData = 0;
	htable->table = (HashNode * *)malloc(sizeof(HashNode) * tableSize);

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
	Node* temp = NULL;
	temp = hTable->table[GetKey(data, hTable->size)]->list;

	if (!temp)
		return 0;
	while (temp) {
		if (temp->data == data)
			return 1;
		temp = temp->next;
	}

	return 0;
}

void HashInsert(HashTable* hTable, int data) {
	HashNode* first;
	first = hTable->table[GetKey(data, hTable->table)];

	Node* temp;
	temp = first->list;

	Node* node = (Node*)malloc(sizeof(Node));
	if (!node) {
		printf("Memory allocation Fail\n");
		return;
	}

	node->data = data;
	node->next = NULL;

	if (!temp)
		first->list = node;
	else {
		Node* temp2;
		temp2 = first->list;
		first->list = node;
		node->next = temp2;
	}

	first->count++;

	if ((first->count / hTable->size) > LOAD_FACTOR)
		hTable = ReHash(hTable);

}

void HashDelete(HashTable* hTable, int data) {
	HashNode* first;
	first = hTable->table[GetKey(data, hTable->size)];

	Node* temp;
	temp = first->list;

	Node* before = temp;
	if (!temp)
		return;
	while (temp) {
		if (temp->data == data) {
			if (before == temp) {
				first->list = temp->next;
			}
			else {
				before->next = temp->next;
			}
			free(temp);
			break;
		}
		before = temp;
		temp = temp->next;
	}
	first->count--;
}

void DeleteHashTable(HashTable* hTable) {
	for (int i = 0; i < hTable->size; i++) {
		Node* temp = NULL;
		Node* before = NULL;
		temp = hTable->table[i]->list;
		before = temp;
		while (temp) {
			before = temp;
			temp = temp->next;
			free(before);
		}
	}

	for (int i = 0; i < hTable->size; i++) {
		free(hTable->table[i]);
	}
	free(hTable);

	printf("HashTable Delete\n");
}

void PrintHashTable(HashTable* hTable) {
	printf("All print Hash Table Data\n");

	for (int i = 0; i < hTable->size; i++) {
		HashNode* first = hTable->table[i];
		Node* temp = first->list;

		printf("Key %d : ",i);
		while (temp) {
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

HashTable* ReHash(HashTable* hTable) {
	HashTable* oldTable = hTable;
	hTable = CreateHashTable(hTable->size * 2);
	if (!hTable) {
		printf("Memory allocation Fail\n");
		return NULL;
	}

	for (int i = 0; i < oldTable->size; i++) {
		HashNode* first = oldTable->table[i];
		Node* temp = first->list;

		while (temp) {
			HashInsert(hTable, temp->data);
			temp = temp->next;
		}
	}

	DeleteHashTable(oldTable);
	printf("Load Factor에 따른 ReHash로 data 분산 완료\n");
	return hTable;
}


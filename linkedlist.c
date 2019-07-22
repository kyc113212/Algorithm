#include <stdio.h>
#include <malloc.h>
//Linked List Node Add, Delete, Search, InitNode, CreateNode, IsEmpty, Print, Find(위치)
typedef struct Node {
	int data;
	struct Node* next;
}Node;
typedef struct LinkedList {
	Node* head, * tail;
	int l_size;
}LinkedList;

int isEmpty(LinkedList* linkedlist) {
	if (linkedlist->l_size == 0)
		return 1;
	else
		return 0;
}

void initNode(LinkedList* linkedlist) {
	linkedlist->head = linkedlist->tail = NULL;
	linkedlist->l_size = 0;
}

void addNode(LinkedList* linkedlist, int value, int pos, int ver) { //version 1: 뒤에 삽입, 2: 앞에 삽입, 3, 지정 Pos에 삽입
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	linkedlist->l_size++;
	if (linkedlist->head == NULL && linkedlist->tail == NULL) {
		linkedlist->head = newNode;
		linkedlist->tail = newNode;
		return;
	}
	if (ver == 1) {
		linkedlist->tail->next = newNode;
		linkedlist->tail = newNode;
		return;
	}
	else if (ver == 2) {
		newNode->next = linkedlist->head;
		linkedlist->head = newNode;
		return;
	}
	else if (ver == 3) {
		if (pos == 0) {
			newNode->next = linkedlist->head->next;
			linkedlist->head = newNode;
			return;
		}
		else {
			Node* temp = linkedlist->head;
			for (int i = 0; i < pos - 1; i++) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
			return;
		}
	}
	return;
}
 
void printNode(LinkedList* linkedlist) {
	Node* temp = linkedlist->head;
	for (int i = 0; i < linkedlist->l_size; i++) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
 
	printf("\n");
 
	return;
 
}
 
int main() {
	LinkedList linkedlist;
	initNode(&linkedlist);
 
	addNode(&linkedlist, 1, 0, 1);//첫번째 노드
	addNode(&linkedlist, 2, 0, 1);
	addNode(&linkedlist, 3, 0, 1);
	addNode(&linkedlist, 4, 1, 3);
 
	printNode(&linkedlist);
 
	return 0;
}


#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int data;
	struct Node *next, *before;
}Node;

typedef struct LinkedList {
	Node *front, *tail;
	int size;
}LinkedList;

void initList(LinkedList *ll) {

	ll->size = 0;
	ll->front = NULL;
	ll->tail = NULL;

	return;
}

void insertNode(LinkedList *ll, int pos, int value) {

	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = value;
	if (ll->size == 0) {
		printf("push empty list\n");
		newNode->before = NULL;
		newNode->next = NULL;
		ll->front = newNode;
		ll->tail = newNode;
		ll->size++;
		//return;
	}
	else if (pos > ll->size) {
		//newNode->before = NULL;
		printf("out of size! push tail!\n");
		ll->tail->next = newNode;
		newNode->before = ll->tail;
		ll->tail = newNode;
		ll->size++;
		//return;		
	}
	else if (pos == 1) {
		printf("push front!\n");
		newNode->before = NULL;
		ll->front->before = newNode;
		newNode->next = ll->front;
		ll->front = newNode;
		ll->size++;

	}
	else {
		Node *tmpNode = ll->front;
		Node *nextTmpNode = tmpNode->next;
		for (int i = 1; i < pos - 1; i++) {
			tmpNode = tmpNode->next;
			nextTmpNode = tmpNode->next;
		}
		newNode->next = tmpNode->next;
		newNode->before = tmpNode;
		tmpNode->next = newNode;
		nextTmpNode->before = newNode;
		ll->size++;
	}


	return;
}

void deleteList(LinkedList *ll, int pos) {
	if (ll->size == 0) {
		printf("list empty!!\n");
		return;
	}
	if(pos > ll->size) {
		printf("out of size\n");
		return;
	}
	if(pos == 1) {
		Node *tmp = ll->front;
		int tmpdata = ll->front->data;
		ll->front = tmp->next;
		ll->front->before = NULL;
		ll->size--;
		printf("delete data : %d\n",tmpdata);
		free(tmp);
	}
	else if(pos == ll->size) {
		Node *tmp = ll->tail;
		int tmpdata = ll->tail->data;
		ll->tail = tmp->before;
		ll->tail->next = NULL;
		ll->size--;
		printf("delete data : %d\n",tmpdata);
		free(tmp);
	}
	else {
		Node *targetNode = ll->front;
		Node *nexttargetNode = ll->front->next;
		for (int i = 1; i < pos; i++) {
			targetNode = targetNode->next;
			nexttargetNode = targetNode->next;
		}
		int tmpdata = targetNode->data;
		targetNode->before->next = nexttargetNode;
		nexttargetNode->before = targetNode->before->next;
		free(targetNode);
		ll->size--;
		printf("delete data : %d\n",tmpdata);
	}


	return;
}


void print_list(LinkedList *ll) {
	Node *tmpNode = ll->front;
	printf("print list\n");
	for (int i = 0; i < ll->size; i++) {
		printf("%d ", tmpNode->data);
		tmpNode = tmpNode->next;
	}

	printf("\n");

	return;
}



int main(void) {

	LinkedList *ll = (LinkedList *)malloc(sizeof(LinkedList));
	initList(ll);
	insertNode(ll,1,10);
	insertNode(ll,5,50);
	insertNode(ll,1,30);
	insertNode(ll,2,20);
	print_list(ll);
	deleteList(ll,1);
	deleteList(ll,3);
	print_list(ll);
	insertNode(ll,3,100);
	insertNode(ll,1,70);
	insertNode(ll,2,50);
	print_list(ll);	
	deleteList(ll,4);	
	print_list(ll);	
	insertNode(ll,2,80);
	print_list(ll);	

	return 0;
}

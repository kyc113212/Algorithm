#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct Queue {
	Node* front, * tail;
	int q_size;
}Queue;

void InitQueue(Queue* queue) {
	queue->front = NULL;
	queue->tail = NULL;
	queue->q_size = 0;
}

int EmptyQueue(Queue* queue) {
	if (queue->q_size == 0) {
		return 1;
	}
	else
		return 0;
}

void PushQueue(Queue* queue, int data) {
	Node* now = (Node*)malloc(sizeof(Node));
	now->data = data;
	now->next = NULL;

	if (EmptyQueue(queue)) {
		queue->front = now;
	}
	else {
		queue->tail->next = now;
	}
	queue->tail = now;
	queue->q_size++;
}

int PopQueue(Queue* queue) {
	Node* temp;
	int re_d;

	if (EmptyQueue(queue)) {
		return -1;
	}
	else {
		re_d = queue->front->data;
		temp = queue->front;
		queue->front = temp->next;
		free(temp);
		queue->q_size--;
		return re_d;
	}

}

int SizeQueue(Queue* queue) {
	return queue->q_size;
}
int FrontQueue(Queue* queue) {
	if (queue->q_size == 0) {
		return -1;
	}
	else {
		return queue->front->data;
	}
}

int BackQueue(Queue* queue) {
	if (queue->q_size == 0) {
		return -1;
	}
	else
		return queue->tail->data;
}

int strcmp(char* a, char* b, int s_size) {
	for (int i = 0; i < s_size; i++) {
		if (a[i] != b[i])
			return 0;
	}

	return 1;
}

int main() {

	int N;
	Queue queue;
	InitQueue(&queue);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {

		char cmd[10] = { '\0', };
		int num = 0;
		int string_size = 0;
		scanf("%s", cmd);
		for (int j = 0; j < 10; j++) {
			if (cmd[j] == '\0') {
				string_size = j;
				break;
			}
		}
		if (strcmp(cmd, "push", string_size) == 1) {
			scanf("%d", &num);
			PushQueue(&queue,num);
		}
		if (strcmp(cmd, "pop", string_size) == 1) {
			printf("%d\n", PopQueue(&queue));
		}
		if (strcmp(cmd, "size", string_size) == 1) {
			printf("%d\n", SizeQueue(&queue));
		}
		if (strcmp(cmd, "empty", string_size) == 1) {
			printf("%d\n", EmptyQueue(&queue));
		}
		if (strcmp(cmd, "front", string_size) == 1) {
			printf("%d\n", FrontQueue(&queue));
		}
		if (strcmp(cmd, "back", string_size) == 1) {
			printf("%d\n", BackQueue(&queue));
		}

	}
	return 0;
}

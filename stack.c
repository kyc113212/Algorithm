#include <stdio.h>
#include <malloc.h>

int s_size = 0;

typedef struct Node {
	int data;
	struct Node *next;
}Node;

typedef struct Stack {
	Node *top;
}Stack;

void InitStack(Stack* stack) {
	stack->top = NULL;
}
int isEmpty(Stack* stack) {
	if (stack->top == NULL) {
		return 1;
	}
	else
		return 0;
}

int Top(Stack* stack) {
	if (stack->top == NULL) {
		return -1;
	}
	else {
		Node* now;
		now = stack->top;
		return now->data;
	}
}


void Push(Stack* stack, int data) {
	Node* now = (Node*)malloc(sizeof(Node));//새 Node 생성
	now->data = data;
	now->next = stack->top;
	stack->top = now;	//stack 맨 앞은 now로 설정
	s_size++;
}
int Pop(Stack* stack) {
	Node* now;
	int re;
	s_size--;
	if (s_size < 0)
		s_size = 0;
	if (isEmpty(stack)) {
		return -1;
	}
	now = stack->top;
	re = now->data;	//꺼낼값
	stack->top = now->next;//top을 now의 next로 설정
	free(now);
	return re;
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
	Stack stack;
	InitStack(&stack);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char cmd[10] = {'\0',};
		int num = 0;
		int string_size = 0;
		scanf("%s", cmd);
		for (int j = 0; j < N; j++) {
			if (cmd[j] == '\0') {
				string_size = j;
				break;
			}
		}
		if (strcmp(cmd, "push", string_size) == 1) {
			scanf("%d", &num);
			Push(&stack, num);
		}
		if (strcmp(cmd, "pop", string_size) == 1) {
			printf("%d\n",Pop(&stack));
		}
		if (strcmp(cmd, "size", string_size) == 1) {
			printf("%d\n", s_size);
		}
		if (strcmp(cmd, "empty", string_size) == 1) {
			printf("%d\n", isEmpty(&stack));
		}
		if (strcmp(cmd, "top", string_size) == 1) {
			printf("%d\n", Top(&stack));
		}
		
	}
	return 0;
}

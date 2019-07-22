#include <stdio.h>
#include <malloc.h>

void Qsort(int left, int right, int *arr) {
	int L = left;
	int R = right;
	int temp;
	int pivot = arr[(left + right) / 2];

	while (L <= R) {
		while (arr[L] < pivot) L++;
		while (arr[R] > pivot) R--;
		if (L <= R) {
			if (L != R) {
				temp = arr[L];
				arr[L] = arr[R];
				arr[R] = temp;
			}
			L++, R--;
		}
	}

	if (left < R) {
		Qsort(left, R, arr);
	}
	if (right > L) {
		Qsort(L, right, arr);
	}

}


int main(void) {
	int N;
	scanf("%d", &N);
	int i;
	int* data = malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &data[i]);
	}

	printf(" --정렬 전 순서--\n"); //정렬하기 전 상태 출력.
	for (int i = 0; i < N; i++) {
		printf("%d ", data[i]);
	}
	printf("\n\n");

	Qsort(0, N-1, data);

	printf(" --정렬 후 순서--\n"); //정렬한 후 상태 출력.
	for (int i = 0; i < N; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
	return 0;
}

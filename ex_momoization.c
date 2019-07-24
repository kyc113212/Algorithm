#include <stdio.h>

int data[100];

int fibo_memoization(unsigned int n) {

	if (n <= 2) {
		return 1;
	}
	if (data[n] != 0)
		return data[n];
	else {
		data[n] = fibo_memoization(n-1) + fibo_memoization(n-2);
		return data[n];
	}

	
}

int fibo_nonmemoization(int n) {
	if (n <= 2) {
		return 1;
	}
	else {
		return fibo_nonmemoization(n - 1) + fibo_nonmemoization(n - 2);
	}
}

int main() {

	printf("피보나치 : ");
	int n;
	scanf("%d", &n);
	unsigned int rst = 0;
	rst = fibo_memoization(n);
	printf("memo-fibo : %d\n", rst);

	return 0;
}

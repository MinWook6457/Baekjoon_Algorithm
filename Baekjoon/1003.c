#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void fibonacci(int n, int* a, int* b) {
	int t;
	if (n == 0) {
		(*a)++;
	}
	else if (n == 1) {
		(*b)++;
	}
	else {
		*a = 1;
		*b = 1;
		for (int i = 2;i < n;i++) {
			t = *a + *b;
			*a = *b;
			*b = t;
		}
	}
}
int main() {
	int x, n;
	scanf("%d", &x);
	
	for (int i = 0;i < x;i++) {
		scanf("%d", &n);
		int a = 0, b = 0;
		fibonacci(n, &a, &b);
		printf("%d %d\n", a, b);
	}


	return 0;
}

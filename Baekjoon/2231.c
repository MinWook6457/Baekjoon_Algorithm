#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int find(int n) {
	int f = n;
	while (n > 0) {
		f = f + (n % 10);
		n = n / 10;
	}
	return f;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		if (find(i) == n) {
			printf("%d\n", i);
			break;
		}
		if (i == n)
			printf("0");
	}

	return 0;
}
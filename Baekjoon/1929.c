#include <stdio.h>
#pragma warning(disable:4996)
int arr[1000001] = { 0, };
int main() {
	int m,n;
	scanf("%d %d", &m, &n);

	arr[1] = 1; 

	for (int i = 2; i <= n;i++) {
		for (int j = 2; j * i <= n; j++)
			arr[i * j] = 1;
	}

	for (int i = m; i <= n; i++) {
		if (arr[i] == 0)
			printf("%d\n", i);
	}

	return 0;
}
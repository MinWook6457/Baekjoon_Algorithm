#include <stdio.h>
#pragma warning(disable:4996)
#define SIZE 100003

int arr[100003];
int sum[100003];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int t = 0; // ±¸°£ ÇÕ

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		t += arr[i];
		sum[i] = t;
	}

	for (int i = 1; i <= m; i++) {
		int s, e;
		scanf("%d%d", &s, &e);

		printf("%d\n", sum[e] - sum[s - 1]);
	}


	return 0;
}
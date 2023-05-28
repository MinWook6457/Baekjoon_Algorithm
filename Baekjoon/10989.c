#include <stdio.h>
#pragma warning(disable:4996)
#define max 10001

int main() {
	int n;

	scanf("%d", &n);

	int count[max] = { 0, }; // 배열 모든 원소 0으로 초기화

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		count[x] = count[x] + 1;
	}

	for (int i = 1; i < max; i++) {
		for (int j = 1; j <= count[i]; j++) {
			printf("%d\n", i);
		}
	}

	return 0;
}
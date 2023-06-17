#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	int cards[10001] = { 0, };

	for (int i = 0; i < n; i++) {
		scanf("%d", &cards[i]);
	}

	int bj = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = cards[i] + cards[j] + cards[k];
				if (sum > bj && sum <= m)
					bj = sum;
			}
		}
	}

	printf("%d", bj);
	return 0;
}
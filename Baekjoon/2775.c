#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int count;
	int k, n;;
	int arr[15][15] = { 0 };
	for (int i = 0; i < 15; i++) {
		arr[0][i] = i;
	}

	for (int i = 0; i < 15; i++) {
		arr[i][1] = 1;
	}

	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf("%d", &k);
		scanf("%d", &n);

		for (int x = 1; x <= k; x++) {
			for (int y = 1; y <= n; y++) {
				arr[x][y] = arr[x][y - 1] + arr[x - 1][y];
			}
		}
		printf("%d \n", arr[k][n]);

	}

	return 0;
}
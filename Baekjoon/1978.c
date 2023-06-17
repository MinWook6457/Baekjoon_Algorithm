#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int n;
	int arr[1000] = { 0, };
	int count = 0;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		int k = arr[i];

		for (int j = 2; j < k; j++) {
			if (k % j == 0)
				break;
			if (j == k - 1) {
				count++;
			}
		}
		if (k == 2)
			count++;
	}

	printf("%d", count);
	

	return 0;
}
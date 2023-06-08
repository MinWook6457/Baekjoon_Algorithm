#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int arr[5];

	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
	}

	int result[5] = { 0, };
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		result[i] = arr[i] * arr[i];
		sum += result[i];
	}

	printf("%d", sum % 10);

	return 0;
}
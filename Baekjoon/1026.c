#include <stdio.h>
#pragma warning(disable:4996)
int a[100];
int b[100];
int compare1(const void* a, const void* b) { // 오름차순
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2)
		return -1;

	if (num1 > num2)
		return 1;

	return 0;
}
int compare2(const void* a, const void* b) { // 내림차순
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2)
		return -1;

	if (num1 < num2)
		return 1;

	return 0;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}

	qsort(a, n, sizeof(int), compare1);
	qsort(b, n, sizeof(int), compare2);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (a[i] * b[i]);
	}

	printf("%d", sum);

	return 0;
}
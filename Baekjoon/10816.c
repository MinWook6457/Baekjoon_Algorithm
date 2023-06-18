/*
lower_bound / Upper_bound�� �̺�Ž���� ������ �˰�������,

* �̺�Ž���� ���ĵ� ���� �����Ͽ� ã���� �ϴ� k���� index�� ã�� �˰��� �̶�� �ϸ�,

1) lower_bound�� ���ĵ� ���� �� ã���� �ϴ� k �̻��� ���ʰ� index�� ã�� �˰����̰�,

2) Upper_bound�� ���ĵ� ���� �� ã���� �ϴ� k�� �ʰ��� ���ʰ��� index�� ã�� �˰����̴�.
*/
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int arrX[500000];
int arrY[500000];

int lower_bound(int* have, int key, int size) {
	int mid;
	int start = 0, end = size - 1;

	while (start < end) {
		mid = (start + end) / 2;
		if (key <= have[mid])
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}

int Upper_bound(int* have, int key, int size) {
	int mid;
	int start = 0, end = size - 1;

	while (start < end) {
		mid = (start + end) / 2;
		if (key < have[mid])
			end = mid;
		else
			start = mid + 1;
	}
	if (have[end] == key) {
		return end + 1;
	}
	return end;
}

int cmp(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) {
		return 1;
	}
	else {
		return -1;
	}
}

int main() {
	int n, m;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arrX[i]);

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
		scanf("%d", &arrY[i]);

	qsort(arrX, n, sizeof(int), cmp);

	int lower = 0;
	int upper = 0;

	for (int i = 0; i < m; i++) {
		lower = lower_bound(arrX, arrY[i], n);
		upper = Upper_bound(arrX, arrY[i], n);
		printf("%d ", upper - lower);
	}

	return 0;
}
/*
lower_bound / Upper_bound는 이분탐색을 응용한 알고리즘으로,

* 이분탐색은 정렬된 수를 분할하여 찾고자 하는 k값의 index를 찾는 알고리즘 이라고 하면,

1) lower_bound는 정렬된 수들 중 찾고자 하는 k 이상의 최초값 index를 찾는 알고리즘이고,

2) Upper_bound는 정렬된 수들 중 찾고자 하는 k를 초과한 최초값의 index를 찾는 알고리즘이다.
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
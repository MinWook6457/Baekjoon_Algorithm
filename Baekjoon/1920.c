#include <stdio.h>
#pragma warning(disable:4996)
int arr_N[100001];
int arr_M[100001];

int binary_search_tree(int* arr, int key, int size) {
	int f, r, p;
	f = 0;
	r = size - 1;

	while (1) {
		p = (f + r) / 2;
		// (arr[p] == key || arr[f] == key || arr[r] == key) 로 return 문 작성시 시간초과 발생
		// 이유는 모르겠음
 		if (arr[p] == key) 
			return 1;
		if (arr[f] == key)
			return 1;
		if (arr[r] == key)
			return 1;
		if (arr[p] < key)
			f = p + 1;
		else
			r = p - 1;

		if (f >= r)
			return 0;
	}
}

int compare(const void* a, const void* b) {
	return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &arr_N[i]);
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &arr_M[i]);
	}

	qsort(arr_N, n, sizeof(int), compare);

	for (int i = 0; i < m; i++) {
		printf("%d\n", binary_search_tree(arr_N, arr_M[i], n));
	}

	return 0;
}
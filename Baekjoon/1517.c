#include <stdio.h>
#pragma warning(disable:4996)
typedef long long int ll;

ll sorted[500001];
ll arr[500001];
ll answer = 0;

void merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			answer += j - k; // swap ±¸°£
			j++;
		}
		k++;
	}

	if (i > mid) {
		for (int a = j; a <= right;a++) {
			sorted[k++] = arr[a];
		}
	}
	else {
		for (int a = i; a <= mid; a++) {
			sorted[k++] = arr[a];
		}
	}

	for (int a = left; a <= right;a++) {
		arr[a] = sorted[a];
	}
}

void merge_sort(int left, int right) {
	if (left >= right) return;
	int mid = (left + right) / 2;
	merge_sort(left, mid);
	merge_sort(mid + 1, right);
	merge(left, mid, right);
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n;i++)
		scanf("%lld", &arr[i]);

	merge_sort(0, n - 1);
	printf("%lld", answer);

	return 0;
}
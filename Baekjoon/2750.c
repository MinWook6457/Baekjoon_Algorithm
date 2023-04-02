#include <stdio.h>
#pragma warning(disable:4996)
#define SWAP(x,y,t) ( (t)=(x) , (x) = (y) , (y) =(t) )
void BubbleSort(int list[], int n) {
	int i, j, temp;

	for (i = n - 1;i > 0;i--) {
		for (j = 0;j < i;j++) {
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int a[1000];

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	BubbleSort(a, n);
	for (int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
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

	int* people = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &people[i]);
	}

	BubbleSort(people, n);

	int sum = 0;
	int total = 0;
	for (int i = 0; i < n; i++) {
		sum += people[i];
		total += sum;
	}
	printf("%d", total);
}
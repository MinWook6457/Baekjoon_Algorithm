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
	int s[3];
	int temp;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &s[i]);
	}
	
	BubbleSort(s, 3);

	printf("%d", s[1]);
}
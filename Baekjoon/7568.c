#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct SIZE {
	int height;
	int weight;
}SIZE;

int main() {
	int n;
	scanf("%d", &n);

	SIZE* s = (SIZE*)malloc(sizeof(SIZE) * n);

	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		s[i].height = x;
		s[i].weight = y;
	}

	int count;
	for (int i = 0; i < n; i++) {
		count = 0;
		for (int j = 0; j < n; j++) {
			if (s[i].height < s[j].height && s[i].weight < s[j].weight) {
				count++;
			}
		}
		printf("%d ", count + 1);
	}


	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct coord {
	int x, y;
}coord;

int cmp(const void* first, const void* second)
{
	coord* a = (coord*)first;
	coord* b = (coord*)second;

	if (a->y < b->y)
		return -1;
	else if (a->y > b->y)
		return 1;
	else
	{
		if (a->x < b->x)
			return -1;
		else
			return 1;
	}
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);

	coord* cd = (coord*)malloc(sizeof(coord) * n);

	for (int i = 0; i < n; i++) {
		scanf(" %d %d", &cd[i].x, &cd[i].y);
	}

	qsort(cd, n, sizeof(cd[0]), cmp);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", cd[i].x, cd[i].y);
	}

	free(cd);
	return 0;
}
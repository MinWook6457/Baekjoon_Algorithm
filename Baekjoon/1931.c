#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/*
	시작 시간을 기준으로 정렬해야하나 
	종료 시점이 같은 경우엔 시작 시간이 빠른 것 시점 부터 
	회의를 시작해야 함.
*/
typedef struct Dis { // 회의시간 
	int start, end;
}Dis;

int cmp(const void* a, const void* b) {
	const Dis* d1 = (const Dis*)a;
	const Dis* d2 = (const Dis*)b;

	if (d1->end != d2->end) {
		if (d1->end < d2->end)
			return -1;
		else if (d1->end == d2->end)
			return 0;
		else
			return 1;
	}
	else {
		if (d1->start < d2->start)
			return -1;
		else if (d1->start == d2->start)
			return 0;
		else
			return 1;
	}
}

int main() {
	int n;
	int count = 0;
	int last = 0;
	scanf("%d", &n);

	Dis* d = (Dis*)malloc(sizeof(Dis) * n);

	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		d[i].start = x;
		d[i].end = y;
	}

	qsort(d, n, sizeof(Dis), cmp);

	for (int i = 0; i < n; i++) {
		if (d[i].start >= last) {
			count++;
			last = d[i].end;
		}
	}
	printf("%d\n", count);

	free(d);
	return 0;
}
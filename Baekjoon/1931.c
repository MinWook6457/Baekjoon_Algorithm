#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/*
	���� �ð��� �������� �����ؾ��ϳ� 
	���� ������ ���� ��쿣 ���� �ð��� ���� �� ���� ���� 
	ȸ�Ǹ� �����ؾ� ��.
*/
typedef struct Dis { // ȸ�ǽð� 
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
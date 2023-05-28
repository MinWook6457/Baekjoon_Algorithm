#include <stdio.h>
#include <stdlib.h>
#define MAX 100001
#pragma warning(disable:4996)

typedef struct edge { // 그래프 간선 정의
	int start, end, weight;
}edge;

int compare(const  void* a, const void* b) { // 퀵 정렬 비교 함수 재정의
	struct edge* x = (struct edge*)a;
	struct edge* y = (struct edge*)b;
	return x->weight - y->weight;
}

/* 전역 변수 선언 */
int parent[MAX];
edge E[MAX];

int find(int x) { 
	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = find(parent[x]);
	}
}

void union_find(int a, int b) {
	a = parent[a];
	b = parent[b];
	parent[a] = b;
}

int main() {
	int v, e;

	scanf("%d%d", &v, &e);

	for (int i = 0; i < e; i++) { // 간선 삽입
		int temp1, temp2, temp3;
		scanf("%d%d%d", &temp1, &temp2, &temp3);
		E[i].start = temp1;
		E[i].end = temp2;
		E[i].weight = temp3;
	}

	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	qsort(E, e, sizeof(struct edge), compare); // 가중치를 기준으로 정렬

	int j = 0;
	int accepted = 0; // 정점 접근
	int a, b;
	int result = 0;
	while (accepted != v - 1) { // 크루스칼 알고리즘 적용
		a = E[j].start;
		b = E[j].end;
		if (find(a) != find(b)) {
			union_find(a, b);
			accepted++;
			result += E[j].weight;
		}
		j++;
	}
	printf("%d", result);
	return 0;

}
/*
문제 : 
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 
정점 번호는 1번부터 N번까지이다.
*/

/*
입력 : 
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 
다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 
어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.
*/

/*
출력 : 
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.
*/
#include <stdio.h>
#pragma warning(disable:4996)
#define MAXV 1001

int DFS_V[MAXV + 10];
int BFS_V[MAXV + 10];

int map[MAXV + 10][MAXV + 10];

int N, M, V;

int queue[MAXV + 10];
int wp, rp;

void enQ(int v) {
	queue[wp] = v;
	wp++;
}

int deQ(void) {
	return queue[rp++];
}

int empty(void) {
	return wp == rp;
}

void DFS(int v, int n) {
	int w;
	DFS_V[v] = 1;
	printf("%d ", v);

	for (w = 1; w <= n; w++) {
		if ((map[v][w] == 1) && (DFS_V[w] == 0)) {
			DFS(w, n);
		}
	}
}

void BFS(int v, int n) {
	int w;
	printf("%d ", v);
	BFS_V[v] = 1;
	enQ(v);

	while (!empty()) {
		int cur = deQ();
		for (w = 1; w <= n; w++) {
			if ((map[cur][w] == 1) && (BFS_V[w] == 0)) {
				printf("%d ", w);
				enQ(w);
				BFS_V[w] = 1;
			}
		}
	}
}

void InputData() {
	int x, y;

	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
		map[y][x] = 1;
	}
}

int main() {

	InputData();

	DFS(V, N);
	printf("\n");
	BFS(V, N);

	return 0;
}
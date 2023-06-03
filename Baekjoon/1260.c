#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable:4996)

int visited[1001] = { 0, }; // 방문 표시 초기화
int graph[1001][1001] = { 0, }; // 그래프 초기화
int queue[1001]; 

void dfs(int v,int n) { // 깊이 우선 탐색
	visited[v] = true;
	printf("%d ", v);
	for (int i = 1; i <= n; i++) {
		if (graph[v][i] && !visited[i]) // 그래프에 방문하지 않았고 간선 존재
			dfs(i, n);
	}
}

void bfs(int v, int n) { // 너비 우선 탐색
	/* 큐 변수 선언 */
	int front = 0;
	int rear = 1;
	int pop;

	visited[v] = true;
	printf("%d ", v);
	queue[0] = v;
	while (front < rear) { // 큐가 비어있으면 반복 종료 
		pop = queue[front++]; // dequeue 연산
		for (int i = 1; i <= n; i++){
			if (graph[pop][i] && !visited[i]) {
				visited[i] = true;
				printf("%d ", i);
				queue[rear++] = i; // enqueue 연산
			}
		}
	}
}

int main() {
	int n,m, v;

	scanf("%d%d%d", &n, &m, &v);

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		graph[x][y] = 1; // 양방향 그래프
		graph[y][x] = 1;
	}

	visited[v] = true;
	dfs(v,n);

	for (int i = 1; i <= n; i++) // 방문 노드 초기화
			visited[i] = false;
	visited[v] = true;
	printf("\n");
	bfs(v, n);

	return 0;
}
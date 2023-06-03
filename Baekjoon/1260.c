#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable:4996)

int visited[1001] = { 0, }; // �湮 ǥ�� �ʱ�ȭ
int graph[1001][1001] = { 0, }; // �׷��� �ʱ�ȭ
int queue[1001]; 

void dfs(int v,int n) { // ���� �켱 Ž��
	visited[v] = true;
	printf("%d ", v);
	for (int i = 1; i <= n; i++) {
		if (graph[v][i] && !visited[i]) // �׷����� �湮���� �ʾҰ� ���� ����
			dfs(i, n);
	}
}

void bfs(int v, int n) { // �ʺ� �켱 Ž��
	/* ť ���� ���� */
	int front = 0;
	int rear = 1;
	int pop;

	visited[v] = true;
	printf("%d ", v);
	queue[0] = v;
	while (front < rear) { // ť�� ��������� �ݺ� ���� 
		pop = queue[front++]; // dequeue ����
		for (int i = 1; i <= n; i++){
			if (graph[pop][i] && !visited[i]) {
				visited[i] = true;
				printf("%d ", i);
				queue[rear++] = i; // enqueue ����
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
		graph[x][y] = 1; // ����� �׷���
		graph[y][x] = 1;
	}

	visited[v] = true;
	dfs(v,n);

	for (int i = 1; i <= n; i++) // �湮 ��� �ʱ�ȭ
			visited[i] = false;
	visited[v] = true;
	printf("\n");
	bfs(v, n);

	return 0;
}
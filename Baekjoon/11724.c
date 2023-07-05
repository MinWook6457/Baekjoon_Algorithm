#include <stdio.h>
#pragma warning(disable:4996)
int node[1001][1001] , visited[1001];

void dfs(int next,int n)
{
	// 방문 체크 후 1부터  n까지 dfs 순회
	if (!visited[next] && ++visited[next])
		for (int i = 1; i <= n; i++)
			if (node[next][i])
				dfs(i,n);
}

int main()
{
	int n, m, t1, t2;
	int	result = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &t1, &t2);
		node[t1][t2] = 1;
		node[t2][t1] = 1;
	}
	for (int i = 1; i <= n; i++)
		if (!visited[i]) {
			result += 1;
			dfs(i,n);
		}
	printf("%d\n", result);
	return (0);
}
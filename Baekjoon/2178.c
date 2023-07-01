#include<stdio.h>
#pragma warning(disable:4996)
#define map_size 105
#define max_queue_size 10005
int map[map_size][map_size] = { 0, }, visit[map_size][map_size] = { 0, }, dist[map_size][map_size],
queueX[max_queue_size] = { 0, }, queueY[max_queue_size] = { 0, };
void BFS(int x, int y) {
    int front = 0, rear = 1, popX, popY;
    visit[x][y] = 1;
    queueX[0] = x;
    queueY[0] = y;
    while (front < rear) {
        popX = queueX[front], popY = queueY[front++];
        if (map[popX + 1][popY] && !visit[popX + 1][popY]) {
            visit[popX + 1][popY] = 1;
            dist[popX + 1][popY] = dist[popX][popY] + 1;
            queueX[rear] = popX + 1;
            queueY[rear++] = popY;
        }
        if (map[popX - 1][popY] && !visit[popX - 1][popY]) {
            visit[popX - 1][popY] = 1;
            dist[popX - 1][popY] = dist[popX][popY] + 1;
            queueX[rear] = popX - 1;
            queueY[rear++] = popY;
        }
        if (map[popX][popY + 1] && !visit[popX][popY + 1]) {
            visit[popX][popY + 1] = 1;
            dist[popX][popY + 1] = dist[popX][popY] + 1;
            queueX[rear] = popX;
            queueY[rear++] = popY + 1;
        }
        if (map[popX][popY - 1] && !visit[popX][popY - 1]) {
            visit[popX][popY - 1] = 1;
            dist[popX][popY - 1] = dist[popX][popY] + 1;
            queueX[rear] = popX;
            queueY[rear++] = popY - 1;
        }
    }
}

int main() {
    int x, y;
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    dist[1][1] = 1;
    BFS(1, 1);
    printf("%d", dist[n][m]);
}
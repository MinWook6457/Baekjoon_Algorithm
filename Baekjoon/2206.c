#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 1000000

typedef struct
{
	int x, y, breakingWall, distance;
} Wall;

typedef struct
{
	int front, rear;
	Wall w[MAX_QUEUE];
} QueueType;

void init_queue(QueueType *q)
{
	q->front = 0;
	q->rear = 0;
}

int is_empty(QueueType *q)
{
	return q->front == q->rear;
}

int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE == q->front);
}

void enqueue(QueueType *q, Wall item)
{
	if (is_full(q))
		return;
	q->w[q->rear] = item;
	q->rear = (q->rear + 1) % MAX_QUEUE;
}

Wall dequeue(QueueType *q)
{
	Wall temp = q->w[q->front];
	q->front = (q->front + 1) % MAX_QUEUE;
	return temp;
}

int arr[1001][1001], visited[2][1001][1001];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs()
{
	QueueType q;
	init_queue(&q);

	enqueue(&q, (Wall){0, 0, 0, 1});
	visited[0][0][0] = 1;

	while (!is_empty(&q))
	{
		Wall current = dequeue(&q);
		int x = current.x, y = current.y, wall = current.breakingWall, dist = current.distance;

		// 목표 위치 도달 시 반환
		if (x == n - 1 && y == m - 1)
		{
			return dist;
		}

		// 상하좌우 이동
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				// 벽이 없는 경우
				if (arr[nx][ny] == 0 && visited[wall][nx][ny] == 0)
				{
					visited[wall][nx][ny] = 1;
					enqueue(&q, (Wall){nx, ny, wall, dist + 1});
				}
				// 벽이 있고, 벽을 부순 적이 없을 경우
				else if (arr[nx][ny] == 1 && wall == 0 && visited[1][nx][ny] == 0)
				{
					visited[1][nx][ny] = 1;
					enqueue(&q, (Wall){nx, ny, 1, dist + 1});
				}
			}
		}
	}
	return -1;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	printf("%d\n", bfs());
	return 0;
}

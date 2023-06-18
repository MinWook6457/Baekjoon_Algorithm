/* 벽 부수고 이동하기 BFS 사용 */
// 가중치가 없는 최댄 경로는 무조건 BFS
// 모든 칸을 전부 0으로 바꾸어 BFS를 하는것은 통과될 수 없음 => 시간 복잡도 O(NM^2)
// 칸마다 방문 체크 하나씩만으로 해결 불가능 => 벽을 부술 수 있는 상태와 벽을 부술 수 없는 상태 2가지임
// 좌표를 큐에 넣는것 뿐만 아니라 현재 상태를 큐에 넣어야함 : 각각을 별개의 방문 체크

#include <stdio.h>
#pragma warning(disable:4996)
#define MAX_QUEUE 100
#define ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int visited[2][1001][1001];

typedef struct wall {
	int x, y;
	int breakingWall; // 0 : 벽 부숨 1 : 벽 안 부숨
}wall;

typedef struct QueueType {
	int rear;
	int front;
	wall w[1001];
}QueueType;

void init_queue(QueueType* q) {
	q->front = 0;
	q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->rear == q->front);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE == q->front);
}

void enqueue(QueueType* q, wall item) {
	if (is_full(q)) {
		fprintf(stderr, "큐가 포화상태 입니다.\n");
		return;
	}

	q->rear = (q->rear + 1) % MAX_QUEUE;
	q->w[q->rear] = item;
}


wall dequeue(QueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 공백상태입니다\n");
		return;
	}

	q->front = (q->front + 1) % MAX_QUEUE;
	return q->w[q->front];
}
int arr[1001][1001];

int bfs(int x, int y) {
	QueueType* q;
	init_queue(q);

	wall w;
	w.x = x;
	w.y = y;

	enqueue(q, w);

	visited[1][x][y] = 1;

	while (is_empty(q)) {
		wall current;
		enqueue(q, current);

		current = dequeue(q);


	}
}

int main() {
	QueueType q[1001];

	int n, m;

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	return 0;
}
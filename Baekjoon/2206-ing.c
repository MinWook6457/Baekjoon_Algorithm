/* �� �μ��� �̵��ϱ� BFS ��� */
// ����ġ�� ���� �ִ� ��δ� ������ BFS
// ��� ĭ�� ���� 0���� �ٲپ� BFS�� �ϴ°��� ����� �� ���� => �ð� ���⵵ O(NM^2)
// ĭ���� �湮 üũ �ϳ��������� �ذ� �Ұ��� => ���� �μ� �� �ִ� ���¿� ���� �μ� �� ���� ���� 2������
// ��ǥ�� ť�� �ִ°� �Ӹ� �ƴ϶� ���� ���¸� ť�� �־���� : ������ ������ �湮 üũ

#include <stdio.h>
#pragma warning(disable:4996)
#define MAX_QUEUE 100
#define ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int visited[2][1001][1001];

typedef struct wall {
	int x, y;
	int breakingWall; // 0 : �� �μ� 1 : �� �� �μ�
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
		fprintf(stderr, "ť�� ��ȭ���� �Դϴ�.\n");
		return;
	}

	q->rear = (q->rear + 1) % MAX_QUEUE;
	q->w[q->rear] = item;
}


wall dequeue(QueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "ť�� ��������Դϴ�\n");
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
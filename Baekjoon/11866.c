#include <stdio.h>
#pragma warning(disable:4996)
#define SIZE 1001

typedef struct QueueType{
	int queue[SIZE];
	int front, rear;
}QueueType;

void init(QueueType* q) {
	q->front = q->rear = 0;
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % SIZE == q->front);
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

void enqueue(QueueType* q,int data) {
	if (is_full(q))
		return;

	q->rear = (q->rear + 1) % SIZE;
	q->queue[q->rear] = data;
}

int dequeue(QueueType* q) {
	if (is_empty(q))
		return -1;

	q->front = (q->front + 1) % SIZE;
	return q->queue[q->front];
}

int q_size(QueueType* q) {
	if (q->front < q->rear)
		return q->rear - q->front;
	else
		return SIZE - q->front + q->rear;
}

int main() {
	QueueType q;
	init(&q);

	int n, k;
	int tmp = 0;
	scanf("%d %d",&n, &k);

	for (int i = 0; i < n; i++) {
		enqueue(&q, i + 1);
	}

	printf("<");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k - 1; j++) {
			tmp = dequeue(&q);
			enqueue(&q, tmp);
		}
		if (q_size(&q) == 1)
			break;
		tmp = dequeue(&q);
		printf("%d, ", tmp);
	}

	printf("%d>", dequeue(&q));

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct QueueNode {
	int data;
	struct QueueNode* link;
}QueueNode;

typedef struct {
	QueueNode* front, * rear;
}LinkedQueueType;

void init(LinkedQueueType* q) {
	q->front = q->rear = NULL;
}

int is_empty(LinkedQueueType* q) {
	if (q->front == NULL)
		return 1;
	else
		return 0;
}

void enqueue(LinkedQueueType *q,int data) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;
	if (is_empty(q) == 1) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp;
		q->rear = temp;
	}
}

int dequeue(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	int data;
	if (is_empty(q)) {
		exit(1);
	}
	else {
		data = temp->data;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
		return data;
	}
}

int existedOne(LinkedQueueType* q) {
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}


int main() {
	LinkedQueueType q;
	init(&q);
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		enqueue(&q, i);
	int data = 0;
	while (1) {
		if (n == 1)
			break;
		data = dequeue(&q);
		if (existedOne(&q) == 1)
			break;
		data = dequeue(&q);
		enqueue(&q, data);
	}

	printf("%d", dequeue(&q));

	return 0;
}
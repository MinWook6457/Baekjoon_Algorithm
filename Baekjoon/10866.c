#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAX_QUEUE 100
typedef struct {
	int data[MAX_QUEUE];
	int front, rear;
}DequeType;

void init_queue(DequeType* q) {
	q->front = q->rear = 0;
}

int is_empty(DequeType* q) {
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

int front(DequeType* q) {
	return q->data[q->front];
}

int back(DequeType* q) {
	return q->data[q->rear];
}

int size(DequeType* q) {
	return (q->front - q->rear);
}

int is_full(DequeType* q) {
	if (q->front == (q->rear + 1) % MAX_QUEUE)
		return 1;
	else
		return 0;
}

/* push_back X: ���� X�� ���� �ڿ� �ִ´�. */
void push_back(DequeType* q, int item) {
	if (is_full(q)) {
		printf("ť�� ��ȭ���� �Դϴ�.");
	}

	q->rear = (q->rear + 1) % MAX_QUEUE;
	q->data[q->rear] = item;
}

/* pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�. */
int pop_front(DequeType* q) {
	int item;

	if (is_empty(q)) {
		return -1;
	}

	q->front = (q->front + 1) % MAX_QUEUE;
	item = q->data[q->front];
	return item;
}

/* push_front X: ���� X�� ���� �տ� �ִ´�. */
void push_front(DequeType* q, int value) {
	if (is_full(q)) {
		printf("ť�� ��ȭ���� �Դϴ�.\n");
	}
	q->data[q->front] = value;
	q->front = (q->front - 1 + MAX_QUEUE) % MAX_QUEUE;
}



int pop_back(DequeType* q) {
	int del = q->rear; // �ε��� ����
	if (is_empty(q)) {
		return -1;
	}
	q->rear = (q->rear - 1 + MAX_QUEUE) % MAX_QUEUE; // �ε��� ����
	return q->data[del];
}

int main() {
	int n;
	scanf("%d", &n);
	DequeType q;
	int k;
	init_queue(&q);

	for (int i = 0; i < n; i++) {
		char s[11];
		scanf("%s", s);
		if (strcmp(s, "push_front") == 0) {
			scanf("%d", &k);
			push_front(&q,k);
		}
		else if (strcmp(s, "push_back") == 0) {
			scanf("%d", &k);
			push_back(&q,k);
		}
		else if (strcmp(s, "pop_front") == 0) printf("%d\n", pop_front(&q));
		else if (strcmp(s, "pop_back") == 0) printf("%d\n", pop_back(&q));
		else if (strcmp(s, "size") == 0) printf("%d\n", size(&q));
		else if (strcmp(s, "empty") == 0) printf("%d\n", is_empty(&q));
		else if (strcmp(s, "front") == 0) printf("%d\n", front(&q));
		else if (strcmp(s, "back") == 0) printf("%d\n", back(&q));
	}
	return 0;
}
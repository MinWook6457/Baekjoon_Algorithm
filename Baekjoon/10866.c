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

/* push_back X: 정수 X를 덱의 뒤에 넣는다. */
void push_back(DequeType* q, int item) {
	if (is_full(q)) {
		printf("큐가 포화상태 입니다.");
	}

	q->rear = (q->rear + 1) % MAX_QUEUE;
	q->data[q->rear] = item;
}

/* pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다. */
int pop_front(DequeType* q) {
	int item;

	if (is_empty(q)) {
		return -1;
	}

	q->front = (q->front + 1) % MAX_QUEUE;
	item = q->data[q->front];
	return item;
}

/* push_front X: 정수 X를 덱의 앞에 넣는다. */
void push_front(DequeType* q, int value) {
	if (is_full(q)) {
		printf("큐가 포화상태 입니다.\n");
	}
	q->data[q->front] = value;
	q->front = (q->front - 1 + MAX_QUEUE) % MAX_QUEUE;
}



int pop_back(DequeType* q) {
	int del = q->rear; // 인덱스 저장
	if (is_empty(q)) {
		return -1;
	}
	q->rear = (q->rear - 1 + MAX_QUEUE) % MAX_QUEUE; // 인덱스 감소
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
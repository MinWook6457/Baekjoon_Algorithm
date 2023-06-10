#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct Queue {
	int queue[10001];
	int q_size;
}Queue;


// push : 정수를 큐에 넣는 연산
void push(Queue* q, int data) {
	q->queue[q->q_size++] = data;
}

// 큐에서 가장 앞에 있는 정수를 반환(큐가 비어있는 경우에 -1 반환)
int pop(Queue* q) {
	if (q->q_size) {
		int result = q->queue[0];
		for (int i = 0; i < q->q_size - 1;i++) {
			q->queue[i] = q->queue[i + 1];
		}
		q->q_size--;
		return result;
	}
	else {
		return -1;
	}
}

// 큐의 크기 반환
int size(Queue* q) {
	return q->q_size;
}

// 큐의 공백 검사
int empty(Queue* q) {
	return q->q_size == 0;
}

// 큐의 맨앞 정수 반환
int front(Queue* q) {
	if (q->q_size)
		return q->queue[0];
	else
		return -1;
}

// 큐의 맨뒤 정수 반환
int back(Queue* q) {
	if (q->q_size)
		return q->queue[q->q_size - 1];
	else
		return -1;
}

int main() {
	Queue q = { {0}, 0 }; // 큐 초기화

	int n;
	int data;
	char arr[255];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr);
		if (strcmp(arr, "push") == 0) {
			scanf("%d", &data);
			// printf("%d\n", data);
			push(&q, data);
		}
		else if (strcmp(arr, "pop") == 0) {
			printf("%d\n", pop(&q));
		}
		else if (strcmp(arr, "size") == 0) {
			printf("%d\n", size(&q));
		}
		else if (strcmp(arr, "empty") == 0) {
			printf("%d\n", empty(&q));
		}
		else if (strcmp(arr, "front") == 0) {
			printf("%d\n", front(&q));
		}
		else if (strcmp(arr, "back") == 0) {
			printf("%d\n", back(&q));
		}
	}

	return 0;
}
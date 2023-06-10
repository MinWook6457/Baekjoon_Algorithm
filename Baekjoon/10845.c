#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct Queue {
	int queue[10001];
	int q_size;
}Queue;


// push : ������ ť�� �ִ� ����
void push(Queue* q, int data) {
	q->queue[q->q_size++] = data;
}

// ť���� ���� �տ� �ִ� ������ ��ȯ(ť�� ����ִ� ��쿡 -1 ��ȯ)
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

// ť�� ũ�� ��ȯ
int size(Queue* q) {
	return q->q_size;
}

// ť�� ���� �˻�
int empty(Queue* q) {
	return q->q_size == 0;
}

// ť�� �Ǿ� ���� ��ȯ
int front(Queue* q) {
	if (q->q_size)
		return q->queue[0];
	else
		return -1;
}

// ť�� �ǵ� ���� ��ȯ
int back(Queue* q) {
	if (q->q_size)
		return q->queue[q->q_size - 1];
	else
		return -1;
}

int main() {
	Queue q = { {0}, 0 }; // ť �ʱ�ȭ

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
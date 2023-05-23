#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int stack[10001];
int count = 0; // ���� ũ��

// push X: ���� X�� ���ÿ� �ִ� �����̴�.
void push(int n) {
	stack[count] = n; // ���ÿ� ����
	count++; // ���� ũ�� ����
}

// pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
void pop() {
	// count == 0 -> ������ �����
	if (count != 0) {
		count--;
		printf("%d\n", stack[count]);
		stack[count] = 0; // ���ÿ��� �������Ƿ� �ش� �ε����� 0���� �ʱ�ȭ, �ʱ�ȭ ���� ������ �����Ⱚ
	}
	else {
		printf("-1\n");
	}
}

// top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
void top() {
	if (count != 0) {
		printf("%d\n", stack[count - 1]);
	}
	else {
		printf("-1\n");
	}
}

// empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
void empty() {
	if (count != 0) { // ������ ������� ������
		printf("0\n");
	}
	else {
		printf("1\n");
	}
}

// size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
void size() {
	printf("%d\n", count);
}

int main() {
	int n;
	char s[10];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		if (strcmp(s, "push") == 0) {
			int x;
			scanf("%d", &x);
			push(x);
		}
		else if (strcmp(s, "pop")==0) {
			pop();
		}
		else if (strcmp(s, "top") == 0) {
			top();
		}
		else if (strcmp(s, "empty") == 0) {
			empty();
		}
		else if (strcmp(s, "size") == 0) {
			size();
		}
	}

	return 0;
}
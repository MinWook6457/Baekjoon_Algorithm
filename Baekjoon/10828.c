#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int stack[10001];
int count = 0; // 스택 크기

// push X: 정수 X를 스택에 넣는 연산이다.
void push(int n) {
	stack[count] = n; // 스택에 삽입
	count++; // 스택 크기 증가
}

// pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void pop() {
	// count == 0 -> 스택이 비었음
	if (count != 0) {
		count--;
		printf("%d\n", stack[count]);
		stack[count] = 0; // 스택에서 지웠으므로 해당 인덱스는 0으로 초기화, 초기화 하지 않으면 쓰레기값
	}
	else {
		printf("-1\n");
	}
}

// top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void top() {
	if (count != 0) {
		printf("%d\n", stack[count - 1]);
	}
	else {
		printf("-1\n");
	}
}

// empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
void empty() {
	if (count != 0) { // 스택이 비어있지 않으면
		printf("0\n");
	}
	else {
		printf("1\n");
	}
}

// size: 스택에 들어있는 정수의 개수를 출력한다.
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
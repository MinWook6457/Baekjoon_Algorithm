#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100000
#pragma warning(disable:4996)
int stack[SIZE]; // 스택
char c[SIZE * 2]; // +,- 저장할 char형 배열
int top = -1; // 스택 상단 표시
int arr[SIZE];
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int arr_index = 0; // 할당한 배열 인덱스
	int c_index = 0; // + , - 표현 인덱스
	int temp = 1;

	while (1) {
		// 스택의 상단 수가 해당 배열 인덱스 수 보다 낮은 경우 push
		if ((top == -1) || (stack[top] < arr[arr_index])) {
			stack[++top] = temp++;
			c[c_index++] = '+'; // push = '+'
		}
		/* 스택의 상단 수가 해당 배열 인덱스 수와 같은 경우 pop */
		else if (stack[top] == arr[arr_index]) {
			top--;
			c[c_index++] = '-';
			arr_index++;
		}
		else { /* 스택의 상단 수가 해당 배열 인덱스 수보다 큰 경우*/
			printf("NO\n");
			return 0;
		}
		if (c_index == n * 2) // 무한 루프 탈출
			break;
	}
	
	
	for (int i = 0; i < c_index ;i++)
		printf("%c\n", c[i]);

	return 0;
}
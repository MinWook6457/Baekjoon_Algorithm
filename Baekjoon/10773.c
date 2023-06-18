#include <stdio.h>
#pragma warning(disable:4996)
int stack[100001];
int top = -1;
void push(int data) {
	stack[++top] = data;
}
void pop() {
	top--;
}

int main() {
	int n;
	int sum = 0;
	scanf("%d", &n);
	int arr[100001] = { 0, };

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0) // 0�� �ƴ� �� �Է�
			push(arr[i]); // ���ÿ� push.
		if (arr[i] == 0) // �Է°� == 0
			pop(); // ���ÿ��� pop
	}
	for (int i = 0; i <= top;i++) {
		sum += stack[i];
	}
	printf("%d\n", sum);

	return 0;
}
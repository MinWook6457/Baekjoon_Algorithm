#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100000
#pragma warning(disable:4996)
int stack[SIZE]; // ����
char c[SIZE * 2]; // +,- ������ char�� �迭
int top = -1; // ���� ��� ǥ��
int arr[SIZE];
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int arr_index = 0; // �Ҵ��� �迭 �ε���
	int c_index = 0; // + , - ǥ�� �ε���
	int temp = 1;

	while (1) {
		// ������ ��� ���� �ش� �迭 �ε��� �� ���� ���� ��� push
		if ((top == -1) || (stack[top] < arr[arr_index])) {
			stack[++top] = temp++;
			c[c_index++] = '+'; // push = '+'
		}
		/* ������ ��� ���� �ش� �迭 �ε��� ���� ���� ��� pop */
		else if (stack[top] == arr[arr_index]) {
			top--;
			c[c_index++] = '-';
			arr_index++;
		}
		else { /* ������ ��� ���� �ش� �迭 �ε��� ������ ū ���*/
			printf("NO\n");
			return 0;
		}
		if (c_index == n * 2) // ���� ���� Ż��
			break;
	}
	
	
	for (int i = 0; i < c_index ;i++)
		printf("%c\n", c[i]);

	return 0;
}
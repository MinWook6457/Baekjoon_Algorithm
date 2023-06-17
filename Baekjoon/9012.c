#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TERMS 100
#pragma warning(disable:4996)
typedef struct { // ����ü ����
	char name[MAX_TERMS]; // ��ȣ�� �޾� ���ÿ� �Ҵ��ϴ� ����
	int top; // ������ ��ġ�� ǥ���ϴ� ����
}StackType;
void init(StackType* s) { // ���� �ʱ�ȭ
	s->top = -1;
	for (int i = 0; i < strlen(s->name); i++)
		s->name[i] = NULL;
}
int is_empty(StackType* s) { // ���� ���� ���� �˻�
	if (s->top == -1) {
		return 1;
	}
	else
		return 0;
}
int is_full(StackType* s) { // ���� ��ȭ ���� �˻�
	if (s->top > MAX_TERMS - 1) {
		return 1;
	}
	else
		return 0;
}
void push(StackType* s, char ch) { // ���� ���� �Լ�
	if (is_full(s)) {
		fprintf(stderr, "Push Error\n");
		exit(1);
	}
	else {
		s->top++;
		s->name[s->top] = ch;
	}
}
int pop(StackType* s) { // ���� ���� �Լ� 
	if (is_empty(s)) {
		fprintf(stderr, "pop Error\n");
		exit(1);
	}

	return s->top--;
}
int check_matching(const char* in) { // ��ȣ �˻� �Լ�
	StackType s;
	char ch, open_ch; // ch�� ���ÿ� ���� ���� , open_ch�� ���ÿ��� ���� ����(���� ��ȣ)
	init(&s);

	int n = strlen(in); // ���ڿ� ����

	for (int i = 0; i < n; i++) { // ���ڿ��� �ִ� ��ȣ�� ������ȣ���� ������ȣ���� �˻�
		ch = in[i];
		switch (ch)
		{
		case '(': case '[': case '{': // ������ȣ��� ���ÿ� �߰�
			push(&s, ch);
			break;
	    // �ݴ� ��ȣ��� ���ÿ��� ������ ������ȣ�� �˻�
		case ')':  case ']': case '}': 
			if (is_empty(&s)) // ������ ����ִٸ� ����
				return  0;
			else {
				open_ch = pop(&s);
				if (ch != '(' && open_ch == ')' || ch != '[' && open_ch == ']' || ch != '{' && open_ch == '}') // ��ȣ�� ���� �̷��� �ʴ´ٸ�
					return 0;
			}
			break;
		}
	}
	if (!is_empty(&s)) // ������ ������� �ʴٸ� ����
		return 0;
	return 1;
}
int main() {
	int n;
	char arr[255] = { 0, };
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", arr);
		if (check_matching(arr) == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
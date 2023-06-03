#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable:4996)
#define MAX_TERM 100
typedef struct {
	int data[MAX_TERM];
	int top;
}StackType;
void init_stack(StackType* s) {
	s->top = -1;
}
int is_full(StackType* s) {
	if (s->top > MAX_TERM) {
		return 1;
	}
	else
		return 0;
}

int is_empty(StackType* s) {
	if (s->top == -1) {
		return 1;
	}
	else
		return 0;
}

void push(StackType* s, int value) {
	if (is_full(s)) {
		fprintf(stderr, "Push Error\n");
		exit(1);
	}
	else {
		s->top++;
		s->data[s->top] = value;
	}
}

int pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Pop Error\n");
		exit(1);
	}
	return s->data[(s->top)--];
}

int peek(StackType* s) { // �����Ͱ� �������� ������ �ִ����� Ȯ���Ѵ�.
	if (is_empty(s)) {
		fprintf(stderr, "Peek Error\n");
		exit(1);
	}
	return s->data[(s->top)];
}
int prec(char op) { // ������ �켱���� ��ȯ
	// �켱���� 0�� ���� ���� 2�� ���� ����.
	switch (op)
	{
	case '(':
	case ')':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	}
	return -1;
}

void infix_to_postfix(char exp[]) {
	StackType s;
	char ch, top_op;
	int len = strlen(exp);
	init_stack(&s); // ���� �ʱ�ȭ ����� ����!
	for (int i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
			while (!is_empty(&s) && prec(ch) <= prec(peek(&s))){ // ������ ������� �ʰ� ���� �����ں���
				printf("%c", pop(&s));
			}
			push(&s, ch);
			break;
		case '(':
			push(&s, ch);
			break;
		case ')': // ���� ��ȣ
			top_op = pop(&s); // ��ȣ �ȿ��ִ� ������ pop
			while (top_op != '(') { // ���� ��ȣ�� ������ ����
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default: // �ǿ�����

			printf("%c", ch);

			break;

		} // end of switch

	} // end of for
	// ���ÿ� ���� ������ ó��
	while (!is_empty(&s))
		printf("%c", pop(&s));
}

int main() {
	char buf[1024] = { 0 , };
	
	gets(buf);

	infix_to_postfix(buf);

	return 0;
}
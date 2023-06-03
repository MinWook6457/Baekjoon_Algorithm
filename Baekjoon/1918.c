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

int peek(StackType* s) { // 데이터가 무슨값을 가지고 있는지만 확인한다.
	if (is_empty(s)) {
		fprintf(stderr, "Peek Error\n");
		exit(1);
	}
	return s->data[(s->top)];
}
int prec(char op) { // 연산자 우선순위 반환
	// 우선순위 0이 가장 낮고 2가 가장 높다.
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
	init_stack(&s); // 스택 초기화 까먹지 말것!
	for (int i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
			while (!is_empty(&s) && prec(ch) <= prec(peek(&s))){ // 스택이 비어있지 않고 낮은 연산자부터
				printf("%c", pop(&s));
			}
			push(&s, ch);
			break;
		case '(':
			push(&s, ch);
			break;
		case ')': // 닫힘 괄호
			top_op = pop(&s); // 괄호 안에있는 연산자 pop
			while (top_op != '(') { // 열린 괄호를 만나면 종료
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default: // 피연산자

			printf("%c", ch);

			break;

		} // end of switch

	} // end of for
	// 스택에 남은 연산자 처리
	while (!is_empty(&s))
		printf("%c", pop(&s));
}

int main() {
	char buf[1024] = { 0 , };
	
	gets(buf);

	infix_to_postfix(buf);

	return 0;
}
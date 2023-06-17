#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TERMS 100
#pragma warning(disable:4996)
typedef struct { // 구조체 선언
	char name[MAX_TERMS]; // 괄호를 받아 스택에 할당하는 변수
	int top; // 스택의 위치를 표시하는 변수
}StackType;
void init(StackType* s) { // 스택 초기화
	s->top = -1;
	for (int i = 0; i < strlen(s->name); i++)
		s->name[i] = NULL;
}
int is_empty(StackType* s) { // 스택 공백 상태 검사
	if (s->top == -1) {
		return 1;
	}
	else
		return 0;
}
int is_full(StackType* s) { // 스택 포화 상태 검사
	if (s->top > MAX_TERMS - 1) {
		return 1;
	}
	else
		return 0;
}
void push(StackType* s, char ch) { // 스택 삽입 함수
	if (is_full(s)) {
		fprintf(stderr, "Push Error\n");
		exit(1);
	}
	else {
		s->top++;
		s->name[s->top] = ch;
	}
}
int pop(StackType* s) { // 스택 제거 함수 
	if (is_empty(s)) {
		fprintf(stderr, "pop Error\n");
		exit(1);
	}

	return s->top--;
}
int check_matching(const char* in) { // 괄호 검사 함수
	StackType s;
	char ch, open_ch; // ch는 스택에 넣을 변수 , open_ch는 스택에서 꺼낼 변수(열린 괄호)
	init(&s);

	int n = strlen(in); // 문자열 길이

	for (int i = 0; i < n; i++) { // 문자열에 있는 괄호가 열린괄호인지 닫힌괄호인지 검사
		ch = in[i];
		switch (ch)
		{
		case '(': case '[': case '{': // 열린괄호라면 스택에 추가
			push(&s, ch);
			break;
	    // 닫는 괄호라면 스택에서 꺼내어 열린괄호와 검사
		case ')':  case ']': case '}': 
			if (is_empty(&s)) // 스택이 비어있다면 오류
				return  0;
			else {
				open_ch = pop(&s);
				if (ch != '(' && open_ch == ')' || ch != '[' && open_ch == ']' || ch != '{' && open_ch == '}') // 괄호가 쌍을 이루지 않는다면
					return 0;
			}
			break;
		}
	}
	if (!is_empty(&s)) // 스택이 비어있지 않다면 오류
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
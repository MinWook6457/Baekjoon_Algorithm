#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#define SIZE 100

char stack[SIZE];
int top = -1;

int push(char op) {
	if (top >= SIZE) {
		return -1;
	}

	return stack[++top] = op;
}

int pop() {
	if (top < 0)
		return -1;
	else
		return stack[top--] = '\0'; // ³Î ¹®ÀÚ »ðÀÔ
}

char peek() {
	return stack[top];
}

void balance(char* s, int size) {
	for (int i = 0; i < size; i++) {
		if (s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']') {
			if (top == -1)
				push(s[i]);
			else {
				if (peek() == '(' && s[i] == ')') {
					pop();
				}
				else if (peek() == '[' && s[i] == ']') {
					pop();
				}
				else {
					push(s[i]);
				}
			}
		}
	}

	if (top == -1)
		printf("yes\n");
	else
		printf("no\n");
}

int main() {
	char s[SIZE];

	while (1) {
		top = -1;
		gets(s);
		if (strcmp(s, ".") == 0)
			break;
		balance(s, strlen(s));
	}

	return 0;
}
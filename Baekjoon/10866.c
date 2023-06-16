#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int deq[10001];
int count = 0;

void push_front(int data) {
	for (int i = count;i >= 0;i--) {
		deq[i + 1] = deq[i];
	}
	deq[0] = data;
	count++;
}

void push_back(int data) {
	deq[count] = data;
	count++;
}

void pop_front() {
	if (deq[0] == 0 && count == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", deq[0]);
		for (int i = 0; i < count; i++) {
			deq[i] = deq[i + 1];
		}
		deq[count] = 0;
		count--;
	}
}

void pop_back() {
	if (deq[0] == 0 && count == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", deq[count - 1]);
		deq[count - 1] = 0;
		count--;
	}
}

void empty() {
	if (deq[0] == 0 && count == 0) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
}

void size() {
	printf("%d\n", count);
}

void front() {
	if (deq[0] == 0 && count == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", deq[0]);
	}
}

void back() {
	if (deq[0] == 0 && count == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", deq[count - 1]);
	}
}

int main() {
	int n;
	scanf("%d", &n);

	char s[20];
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		if (strcmp(s, "push_front") == 0) {
			int x;
			scanf("%d", &x);
			push_front(x);
		}
		else if (strcmp(s, "push_back") == 0) {
			int y;
			scanf("%d", &y);
			push_back(y);
		}
		else if (strcmp(s, "pop_front") == 0) {
			pop_front();
		}
		else if (strcmp(s, "pop_back") == 0) {
			pop_back();
		}
		else if (strcmp(s, "empty") == 0) {
			empty();
		}
		else if (strcmp(s, "size")==0) {
			size();
		}
		else if (strcmp(s, "front") == 0) {
			front();
		}
		else if (strcmp(s, "back") == 0) {
			back();
		}
	}
	
	return 0;
}
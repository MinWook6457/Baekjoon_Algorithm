/*
A+: 4.3, A0: 4.0, A-: 3.7

B+: 3.3, B0: 3.0, B-: 2.7

C+: 2.3, C0: 2.0, C-: 1.7

D+: 1.3, D0: 1.0, D-: 0.7

F: 0.0
*/
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main() {
	char s[5];
	scanf("%s", s);
	if (strcmp(s, "A+") == 0) {
		printf("4.3\n");
	}
	else if (strcmp(s, "A0") == 0) {
		printf("4.0\n");
	}
	else if (strcmp(s, "A-") == 0) {
		printf("3.7\n");
	}
	else if (strcmp(s, "B+") == 0) {
		printf("3.3\n");
	}
	else if (strcmp(s, "B0") == 0) {
		printf("3.0\n");
	}
	else if (strcmp(s, "B-") == 0) {
		printf("2.7\n");
	}
	else if (strcmp(s, "C+") == 0) {
		printf("2.3\n");
	}
	else if (strcmp(s, "C0") == 0) {
		printf("2.0\n");
	}
	else if (strcmp(s, "C-") == 0) {
		printf("1.7\n");
	}
	else if (strcmp(s, "D+") == 0) {
		printf("1.3\n");
	}
	else if (strcmp(s, "D0") == 0) {
		printf("1.0\n");
	}
	else if (strcmp(s, "D-") == 0) {
		printf("0.7\n");
	}
	else if (strcmp(s, "F") == 0) {
		printf("0.0\n");
	}
	return 0;
}
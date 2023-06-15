#include <stdio.h>
#pragma warning(disable:4996)
int isPalin(char* s) {
	int left = 0;
	int right = strlen(s) - 1;
	while (left < right) {
		if (s[left++] != s[right--])
			return -1;
	}
	return 1;
}
int main() {
	char s[100001] = { 0, };
	int i = 0;
	while (1) {
		gets(s);

		if (s[0] == '0')
			return 0;
		if (isPalin(s) == 1)
			printf("yes\n");
		if (isPalin(s) == -1) {
			printf("no\n");
		}
			
	}


	return 0;
}
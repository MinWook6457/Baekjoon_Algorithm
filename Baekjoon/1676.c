#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
	int n;
	scanf("%d", &n);
	int answer = 0;
	if (n < 5) {
		answer = 0;
	}
	else {
		for (int i = 5; i <= n; i *= 5) {
			answer += n / i;
		}
	}

	printf("%d", answer);

	return 0;
}
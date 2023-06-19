#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int a, b, v;

	scanf("%d%d%d", &a, &b, &v);
	int result = 0;
	if ((v - a) % (a - b) == 0) {
		result = (v - a) / (a - b) + 1;
	}
	else if ((v - a) % (a - b) != 0) {
		result = (v - a) / (a - b) + 2;
	}
	if (a >= v) {
		result = 1;
	}

	printf("%d", result);
	return 0;
}
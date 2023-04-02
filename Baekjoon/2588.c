#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int x, y;

	scanf("%d%d", &x, &y);

	int a = 0, b = 0, c = 0;

	a = y % 100;
	int a1 = a / 10;
	b = y % 10;
	c = y / 100;

	printf("%d\n%d\n%d\n%d", b * x, a1 * x, c * x, x * y);

	return 0;
}
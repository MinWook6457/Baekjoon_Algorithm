#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		int x, y;
		x = c % a;
		if (x == 0)
			x = a;
		y = c / a + 1;
		if (c % a == 0)
			y -= 1;
		printf("%d%02d\n", x, y);
	}

	return 0;
}
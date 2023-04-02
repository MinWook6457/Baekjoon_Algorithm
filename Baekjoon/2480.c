#include <stdio.h>
#pragma warning(disable:4996)
int main() {
	int x, y, z;
	int r = 0;
	scanf("%d%d%d", &x, &y, &z);

	if (x == y && y == z) {
		r = 10000 + x * 1000;
		printf("%d", r);
	}
	else if (x == y) {
		r = 1000 + x * 100;
		printf("%d", r);
	}
	else if (y == z) {
		r = 1000 + y * 100;
		printf("%d", r);
	}
	else if (x == z) {
		r = 1000 + z * 100;
		printf("%d", r);
	}
	else {
		if (x > y && x > z) {
			r = x * 100;
			printf("%d", r);
		}
		if (y > x && y > z) {
			r = y * 100;
			printf("%d", r);
		}
		if (z > x && z > y) {
			r = z * 100;
			printf("%d", r);
		}
	}
	return 0;
}
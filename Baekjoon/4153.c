#include <stdio.h>
#pragma warning(disable:4996)

int is_triangle(int a, int b, int c) {
	int max;
	int n1, n2;
	if (a >= b && a >= c) {
		max = a;
		n1 = b;
		n2 = c;
	}

	if (b >= a && b >= c) {
		max = b;
		n1 = a;
		n2 = c;
	}

	if (c >= a && c >= b) {
		max = c;
		n1 = a;
		n2 = b;
	}

	if (max * max == n1 * n1 + n2 * n2)
		return 1;
	else
		return 0;
}

int main() {
	int x, y, z;
	while (1) {
		scanf("%d%d%d", &x, &y, &z);
		if (x == 0 && y == 0 && z == 0)
			break;

		if (is_triangle(x,y,z) == 1)
			printf("right\n");
		else
			printf("wrong\n");
	}

	return 0;
}
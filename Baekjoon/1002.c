#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		double d = sqrt((double)(x1 - x2) * (x1 - x2) + (y2 - y1) * (y2 - y1));
		int r_sum = r1 + r2;
		int r_big, r_small;

		if (r1 > r2) {
			r_big = r1;
			r_small = r2;
		}
		else {
			r_big = r2;
			r_small = r1;
		}

		if (d == 0) {
			if (r1 == r2)
				printf("-1\n");
			else
				printf("0\n");
		}
		else {
			if (r_sum < d)
				printf("0\n");
			else if (d == r_sum)
				printf("1\n");
			else if (r_big - r_small < d && d < r_sum)
				printf("2\n");
			else if (d == r_big - r_small)
				printf("1\n");
			else
				printf("0\n");
		}
	}


	return 0;
}
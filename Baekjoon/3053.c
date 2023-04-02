#include <stdio.h>
#define PI 3.1415926535897932
#pragma warning(disable:4996)
int main() {
	int r;
	scanf("%d", &r);
	double u, t;

	u = r * r * PI;
	t = 2 * r * r;

	printf("%lf\n%lf", u, t);
	return 0;
}
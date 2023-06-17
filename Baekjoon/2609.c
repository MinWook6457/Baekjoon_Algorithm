#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int a, b;
	int temp;
	int result = 1;
	scanf("%d%d", &a, &b);
	
	if (a > b) {
		temp = a;
		a = b;
		b = temp;
	}
	for (int i = 2; i <= a; i++) {
		if (a % i == 0 && b % i == 0)
			result = i;
	}
	int k = (a * b) / result;
	printf("%d\n%d", result, k);

	return 0;
}
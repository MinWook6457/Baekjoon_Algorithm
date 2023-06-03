#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int n, first_n;
	scanf("%d", &first_n);
	n = first_n;

	int count = 0;
	while (1) {
		int sum = (n / 10) + (n % 10);
		n = (n % 10) * 10 + (sum % 10);
		count++;
	
		if (first_n == n)
			break;
	}
	printf("%d", count);

	return 0;
}
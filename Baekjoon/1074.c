#include <stdio.h>
#include <math.h> // pow �Լ� ���
#pragma warning(disable:4996)
/*
	1 ��и� : ���� ��
	2 ��и� : ������ ��
	3 ��и� : ���� �Ʒ�
	4 ��и� : ������ �Ʒ�
*/

int solve(int n, int r, int c) {
	if (n < 1)
		return 0;

	int m = (int)pow(2, n - 1); // 2^n

	if (r < m && c < m) { // 1��и�
		return solve(n - 1, r, c);
	}
	else if (r < m && c >= m) { // 2��и�
		return m * m + solve(n - 1, r, c - m);
	}
	else if (r >= m && c < m) { // 3��и�
		return m * m * 2 + solve(n - 1, r - m, c);
	}
	else { // 4��и�
		return m * m * 3 + solve(n - 1, r - m, c - m);
	}
}

int main() {
	int n, r, c;
	scanf("%d%d%d", &n, &r, &c);

	printf("%d\n", solve(n, r, c));
	return 0;
}
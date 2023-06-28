#include <stdio.h>
#include <math.h> // pow 함수 사용
#pragma warning(disable:4996)
/*
	1 사분면 : 왼쪽 위
	2 사분면 : 오른쪽 위
	3 사분면 : 왼쪽 아래
	4 사분면 : 오른쪽 아래
*/

int solve(int n, int r, int c) {
	if (n < 1)
		return 0;

	int m = (int)pow(2, n - 1); // 2^n

	if (r < m && c < m) { // 1사분면
		return solve(n - 1, r, c);
	}
	else if (r < m && c >= m) { // 2사분면
		return m * m + solve(n - 1, r, c - m);
	}
	else if (r >= m && c < m) { // 3사분면
		return m * m * 2 + solve(n - 1, r - m, c);
	}
	else { // 4사분면
		return m * m * 3 + solve(n - 1, r - m, c - m);
	}
}

int main() {
	int n, r, c;
	scanf("%d%d%d", &n, &r, &c);

	printf("%d\n", solve(n, r, c));
	return 0;
}
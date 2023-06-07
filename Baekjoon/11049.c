#include <stdio.h>
#define min(a,b) (a) < (b) ? (a) : (b)
#pragma	warning(disable:4996)
#define INF 1000000000
/*
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) 
			C_matrix[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				C_matrix[i][j] = C_matrix[i][j] + (A_matrix[i][k] * B_matrix[k][j]);
			}
		}
	}
*/

// dp[x][y] : x번째 행렬부터 y번째 행렬까지 곱했을 때 최소의 곱셈 연산 횟수
int matrix[501][2] = {0,}, dp[501][501] = {0,};

int main() {
	int n, r, c;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &r, &c);
		matrix[i][0] = r;
		matrix[i][1] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; i + j <= n; j++) {
			dp[j][i + j] = INF;
			for (int k = j; k <= i + j;k++) {
				/*
					matrix[j][0] : 구간 시작 부분의 행렬의 행 (n 역할)

					matrix[k][1] : 구간을 둘로 나누는 기준점 행렬의 열 (m 역할)

					matrix[i+j][1] : 구간 마지막 부분의 행렬의 열 (k 역할)
				*/
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + (matrix[j][0] * matrix[k][1] * matrix[i + j][1]));
			}
		}
	}

	printf("%d", dp[1][n]); // (1~N번째의 행렬을 곱했을 때 연산의 최솟값)

	return 0;
}
#include <stdio.h>
#pragma warning(disable:4996)
/*
	9 2 3
	8 1 4
	7 6 5
*/
// 방향 : 하 -> 우 -> 상 -> 좌 
int d[4][2] = { {1,0}, {0, 1}, {-1, 0}, {0, -1} };
int snail[1000][1000];

int main() {
	int x, y;
	int a = 0, b = 0; // 하 우 상 좌 순으로 배열을 채울 변수
	int c = 0; 
	int p, q; // 위치 찾기에 사용될 변수
	scanf("%d", &x); // x : x*x 행렬
	scanf("%d", &y); // 행렬에서 어느 위치에 있는지 찾을 수

	for (int i = x * x; i > 0; i--) {
		snail[a][b] = i;
		if (i == y) { // 위치 찾기
			p = a + 1; 
			q = b + 1;
		}
		int dx = a + d[c][0]; 
		int dy = b + d[c][1];
		if (dx < 0 || dx >= x || dy < 0 || dy >= x || snail[dx][dy] != 0) { // 범위에서 벗어나거나 값이 들어간 경우 방향 전환
			c = (c + 1) % 4; // 방향 전환
		}
		a += d[c][0];
		b += d[c][1];
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			printf("%d ", snail[i][j]);
		}
		printf("\n");
	}

	printf("%d %d\n", p, q);


	return 0;
}
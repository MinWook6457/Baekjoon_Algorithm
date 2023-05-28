#include <stdio.h>
#pragma warning(disable:4996)
/*
	9 2 3
	8 1 4
	7 6 5
*/
// ���� : �� -> �� -> �� -> �� 
int d[4][2] = { {1,0}, {0, 1}, {-1, 0}, {0, -1} };
int snail[1000][1000];

int main() {
	int x, y;
	int a = 0, b = 0; // �� �� �� �� ������ �迭�� ä�� ����
	int c = 0; 
	int p, q; // ��ġ ã�⿡ ���� ����
	scanf("%d", &x); // x : x*x ���
	scanf("%d", &y); // ��Ŀ��� ��� ��ġ�� �ִ��� ã�� ��

	for (int i = x * x; i > 0; i--) {
		snail[a][b] = i;
		if (i == y) { // ��ġ ã��
			p = a + 1; 
			q = b + 1;
		}
		int dx = a + d[c][0]; 
		int dy = b + d[c][1];
		if (dx < 0 || dx >= x || dy < 0 || dy >= x || snail[dx][dy] != 0) { // �������� ����ų� ���� �� ��� ���� ��ȯ
			c = (c + 1) % 4; // ���� ��ȯ
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
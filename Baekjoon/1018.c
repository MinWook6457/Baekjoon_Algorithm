#include <stdio.h>
#pragma warning(disable:4996)
#define board_size 8

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	char board[50][50] = { 0, };

	for (int i = 0; i < n; i++) {
		scanf("%s", &board[i]);
	}

	// Black Whith 보드 저장

	char black[board_size][board_size];
	char white[board_size][board_size];
	int check = 1;
	for (int i = 0; i < board_size;i++) {
		for (int j = 0; j < board_size; j++) {
			if (check == 1) {
				black[i][j] = 'B';
				white[i][j] = 'W';
			}
			else {
				black[i][j] = 'W';
				white[i][j] = 'B';
			}
			check *= -1;
		}
		check *= -1;
	}

	int min = n * m;
	for (int i = 0; i < n - 7;i++) {
		for (int j = 0; j < m - 7;j++) {
			int count_black = 0, count_white = 0;
			for (int k1 = 0; k1 < 8; k1++) {
				for (int k2 = 0; k2 < 8; k2++) {
					if (black[k1][k2] != board[i + k1][j + k2])
						count_black++;
					if (white[k1][k2] != board[i + k1][j + k2])
						count_white++;
				}
			}

			if (count_black < min)
				min = count_black;
			if (count_white < min)
				min = count_white;
		}
	}

	printf("%d", min);

	return 0;
}
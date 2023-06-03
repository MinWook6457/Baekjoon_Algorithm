#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

char star[2200][2200];
void func(int size, char(*star)[2200], int m, int n) {
	if (size == 1)
		star[m][n] = '*';
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1) {
					for (int a = (m + 1) - (size / 3) * 2; a < size / 3; a++) { 
						for (int b = (n + 1) - (size) / 3 * 2; b < size / 3; b++) {
							star[a][b] = '\0';
						}
					}
				}
				else {
					func(size / 3, star, (m + 1) - (size / 3) * i - 1, (n + 1) - (size / 3) * j - 1);
				}
			}
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);

	func(n, star, n - 1, n - 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (star[i][j] == '*')
				printf("%c", star[i][j]);
			else
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
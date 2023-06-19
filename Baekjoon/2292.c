#include <stdio.h>
#pragma warning(disable:4996)

/*
	벌집 이웃 중 가장 큰 수 f(x) = 6x + 1
*/
int main() {
	int n;
	scanf("%d", &n);

	int x = 0, y = 0, room;

	while (1) {
		if (n <= 6 * x + 1) {
			room = y + 1;
			break;
		}
		y++;
		x += y;
	}
	printf("%d", room);


	return 0;
}
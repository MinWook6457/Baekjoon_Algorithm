#include <stdio.h>
#pragma warning(disable:4996)

int broken[11]; // 0 1 2 3 4 5 6 7 8 9 + -
int min = 1000000;


int check(int n) {
	int length = 0;
	if (n == 0) {
		return broken[0] ? 0 : 1;
	}
	while (n) {
		length++;
		if (broken[n % 10])
			return 0;

		n /= 10;
	}
	return length;
}

int main() {
	int goal,n;
	int x, y, length, l;
	
	scanf("%d %d", &goal, &n);

	x = goal - 100; // + , - 로만 이동하는 횟수

	if (x < 0)
		x = -1 * x; // 음수면 양수 치환

	for (int i = 0; i < n; i++) { // 고장 버튼 입력
		int brk;
		scanf("%d", &brk);
		broken[brk] = 1; // 고장 표시
	}

	for (int i = 0; i < 1000001; i++) {
		length = check(i); // 이동 가능하다면
		if (length) {
			int data = goal - i;
			if (data < 0) {
				data = data * -1;
			}
			
			if (data < min) {
				min = data;
				l = length;
			}
		}
	}

	y = min + l;

	printf("%d", x < y ? x : y);


	return 0;
}
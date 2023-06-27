#include <stdio.h>
#pragma warning(disable:4996)
int map[100001] = {0};
int q[200002];

int main() {
	int n, m;
	int last = 0, cur = 0, pos = -1;
	scanf("%d%d", &n, &m);

	if (n == m) {
		printf("0\n");
		return 0;
	}

	q[last++] = n;
	while (cur < last && map[m] == 0) { // 큐가 비지 않고 서로 맞닿지 않을 때 까지 반복
		pos = q[cur++];
		if (pos - 1 >= 0 && map[pos - 1] == 0) { // 이전 위치에 방문한 적이 없다면
			q[last++] = pos - 1;
			map[pos - 1] = map[pos] + 1;
		}

		if (pos + 1 <= 100000 && map[pos + 1] == 0) { // + 1 위치에 방문한 적이 없다면
			q[last++] = pos + 1;
			map[pos + 1] = map[pos] + 1;
		}

		if (pos * 2 <= 100000 && map[pos * 2] == 0) { // * 2 위치에 방문한 적이 없다면
			q[last++] = pos * 2;
			map[pos * 2] = map[pos] + 1;
		}
	}
	printf("%d\n", map[m]);

	return 0;
}
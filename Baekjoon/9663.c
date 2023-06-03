#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable:4996)

int board[16] = { 0, };
int n;

int N_Queen(int num) {
    if (num == n)
        return 1;
    else {
        //  count: 경우의 수
        int count = 0;
        // num 번째 줄에 queen 위치
        for (int i = 0; i < n; i++) {
            //0~ num-1 번째 줄에 겹치는 queen 있는가 확인
            int overlap = 0;
            for (int j = 0; j < num; j++) {
                int column = board[j];  //queen의 위치: (j, column)
                if (column == i || abs(num - j) == abs(i - column)) { // 대각선에 존재하는 경우
                    overlap = 1;
                    break;
                }
            }
            if (!overlap) {   //겹치지 않을 경우
                board[num] = i;
                count = count + N_Queen(num + 1);
            }
        }
        return count;
    }
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		board[i] = 0;
	}
    printf("%d", N_Queen(0));


	return 0;
}
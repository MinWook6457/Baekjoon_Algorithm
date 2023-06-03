#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable:4996)

int board[16] = { 0, };
int n;

int N_Queen(int num) {
    if (num == n)
        return 1;
    else {
        //  count: ����� ��
        int count = 0;
        // num ��° �ٿ� queen ��ġ
        for (int i = 0; i < n; i++) {
            //0~ num-1 ��° �ٿ� ��ġ�� queen �ִ°� Ȯ��
            int overlap = 0;
            for (int j = 0; j < num; j++) {
                int column = board[j];  //queen�� ��ġ: (j, column)
                if (column == i || abs(num - j) == abs(i - column)) { // �밢���� �����ϴ� ���
                    overlap = 1;
                    break;
                }
            }
            if (!overlap) {   //��ġ�� ���� ���
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
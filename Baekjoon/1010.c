#include <stdio.h>
#include <stdlib.h>
// 조합 함수 정의
int c[31][31];
int main() {
    int x; // 다리 개수
    scanf("%d", &x);

    for (int i = 0; i < 31; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }

    for (int i = 0; i < x; i++) {
        int n, m;
        scanf("%d%d", &n, &m);
        printf("%d\n", c[m][n]);
    }

    return 0;
}
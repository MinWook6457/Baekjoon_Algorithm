#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int field[50][50], m, n;

int dfs(int x, int y) {
    field[x][y] = 0; // 방문 표시
    //상하좌우로 탐색
    if (x + 1 < m && field[x + 1][y] == 1) dfs(x + 1, y);
    if (x - 1 >= 0 && field[x - 1][y] == 1) dfs(x - 1, y);
    if (y + 1 < n && field[x][y + 1] == 1) dfs(x, y + 1);
    if (y - 1 >= 0 && field[x][y - 1] == 1) dfs(x, y - 1);
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);

    int k, x, y, cnt;
    for (int test_case = 0; test_case < t; test_case++) {
        //배열 초기화
        memset(field, 0, sizeof(field));
        scanf("%d %d %d", &m, &n, &k);

        //배추위치
        while (k--) {
            scanf("%d %d", &x, &y);
            field[x][y] = 1;
        }
        cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //배추가 있는 곳만 dfs 실행
                if (field[i][j] == 1) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        //결과 출력
        printf("%d\n", cnt);
    }
    return 0;
}

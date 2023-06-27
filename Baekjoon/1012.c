#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int field[50][50], m, n;

int dfs(int x, int y) {
    field[x][y] = 0; // �湮 ǥ��
    //�����¿�� Ž��
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
        //�迭 �ʱ�ȭ
        memset(field, 0, sizeof(field));
        scanf("%d %d %d", &m, &n, &k);

        //������ġ
        while (k--) {
            scanf("%d %d", &x, &y);
            field[x][y] = 1;
        }
        cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //���߰� �ִ� ���� dfs ����
                if (field[i][j] == 1) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        //��� ���
        printf("%d\n", cnt);
    }
    return 0;
}

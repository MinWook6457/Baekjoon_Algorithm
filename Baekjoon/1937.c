#include <stdio.h>
#define max(X,Y) ((X) > (Y) ? (X) : (Y)) // max ����
#pragma warning(disable:4996)

int n;
int bamboo[1001][1001]; // �볪�� ��ǥ
int sum[1001][1001]; // �Ǵ� ���� �ϼ�

int dx[] = { -1,1,0,0 }; // x ��ǥ
int dy[] = { 0,0,1,-1 }; // y ��ǥ

int dfs(int x, int y) { // dfs �� ���� ��ȹ�� ���
    if (sum[x][y] != 0) 
        return sum[x][y];

    sum[x][y] = 1; // �ʱ갪 ����
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i]; 
        int ny = y + dy[i];
        

        if (ny < 0 || nx < 0 || nx >= n || ny >= n) // ������ ��� ���
            continue;
        if (bamboo[nx][ny] > bamboo[x][y]) { // �Ǵٰ� ������ �� �ִ� �� �� ���� 
            sum[x][y] = max(sum[x][y], dfs(nx, ny) + 1 );
        }
    }
    return sum[x][y];
}


int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &bamboo[i][j]);

		}
	}

	int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result = max(result, dfs(j, i)); // �ִ� ����
        }
    }

    printf("%d", result);

	return 0;
}
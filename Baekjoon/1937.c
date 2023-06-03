#include <stdio.h>
#define max(X,Y) ((X) > (Y) ? (X) : (Y)) // max 정의
#pragma warning(disable:4996)

int n;
int bamboo[1001][1001]; // 대나무 좌표
int sum[1001][1001]; // 판다 생존 일수

int dx[] = { -1,1,0,0 }; // x 좌표
int dy[] = { 0,0,1,-1 }; // y 좌표

int dfs(int x, int y) { // dfs 와 동적 계획법 사용
    if (sum[x][y] != 0) 
        return sum[x][y];

    sum[x][y] = 1; // 초깃값 설정
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i]; 
        int ny = y + dy[i];
        

        if (ny < 0 || nx < 0 || nx >= n || ny >= n) // 범위를 벗어난 경우
            continue;
        if (bamboo[nx][ny] > bamboo[x][y]) { // 판다가 생존할 수 있는 일 수 갱신 
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
            result = max(result, dfs(j, i)); // 최댓값 갱신
        }
    }

    printf("%d", result);

	return 0;
}
#include <stdio.h>
#define min(x, y) (x) < (y) ? (x) : (y)
int s[1000][3];
int main() {
    int n;
    int c[3];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &c[0], &c[1], &c[2]);
        s[i][0] = min(s[i - 1][1] + c[0], s[i - 1][2] + c[0]);
        s[i][1] = min(s[i - 1][0] + c[1], s[i - 1][2] + c[1]);
        s[i][2] = min(s[i - 1][0] + c[2], s[i - 1][1] + c[2]);
    }

    int result = min(s[n][0], min(s[n][1], s[n][2]));
    printf("%d", result);
    return 0;
}
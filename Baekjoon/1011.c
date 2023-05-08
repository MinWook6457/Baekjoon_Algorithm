#include <stdio.h>
int main(void) {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        int d = y - x; // y > x �̹Ƿ� d > 1
        int n = (int)sqrt((double)d); // n = ��Ʈd 
        // ��Ģ�� ã�ƺ���
        // n^2 <= d < (n+1)^2
        // 1. d = n^2 => n+(n-1)ȸ(2n-1)
        // 2. n^2 < d <= n*(n+1) => 2nȸ
        // 3. n*(n+1) < d < (n+1)^2 => (n+1)+nȸ(2n+1) 
        /*
        y-x    �̵�    �̵�Ƚ��
        1        1        1    => 2n-1
        2        11       2    => 2n
        3        111      3    => 2n+1
        4        121      3    => 2n-1
        5        1211     4    => 2n
        6        1221     4    => 2n
        7        12211    5    => 2n+1
        8        12221    5    => 2n+1
        9        13221    5    => 2n-1
        10       132211   6
        11       133211   6
        */
        int result;
        if (d == n * n) {
            result = n + (n - 1);
        }
        else if (d <= n * (n + 1))
            result = 2 * n;
        else
            result = (n + 1) + n;
        printf("%d\n", result);
    }
}
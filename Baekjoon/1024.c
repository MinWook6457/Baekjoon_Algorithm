#include <stdio.h>
int main() {
    int n, l;
    scanf("%d%d", &n, &l);

    int d = (l - 1) * l / 2; // n(n-1)/2 공식
    int f;

    while ((n - d) % l != 0) { // 리스트 찾기
        if (n < d) {
            printf("-1");
            return 0;
        }

        d += l;
        l++;
        if (l > 100) { // l 길이 100보다 커지면 오류
            printf("-1");
            return 0;
        }
    }

    f = (n - d) / l;
    if (f < 0) {
        printf("-1");
        return 0;
    }

    for (int i = 0; i < l; i++) {
        printf("%d ", f + i);
    }

    return 0;
}
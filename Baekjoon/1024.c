#include <stdio.h>
int main() {
    int n, l;
    scanf("%d%d", &n, &l);

    int d = (l - 1) * l / 2; // n(n-1)/2 ����
    int f;

    while ((n - d) % l != 0) { // ����Ʈ ã��
        if (n < d) {
            printf("-1");
            return 0;
        }

        d += l;
        l++;
        if (l > 100) { // l ���� 100���� Ŀ���� ����
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
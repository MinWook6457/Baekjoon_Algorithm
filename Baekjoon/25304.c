#include <stdio.h>
int main() {
    int x; // 총 금액
    int n; // 물건 수
    scanf("%d", &x);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        x -= a * b;
    }

    if (x == 0)
        printf("Yes");
    else
        printf("No");

    return 0;
}
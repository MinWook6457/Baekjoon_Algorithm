#include <stdio.h>
int main() {
    int x, y, count = 0;

    int s[10];

    scanf("%d%d", &x, &y);
    for (int i = 0; i < x; i++) {
        scanf("%d", &s[i]);
    }

    for (int i = x - 1; i >= 0; i--) {
        if (s[i] <= y) {
            count += y / s[i];
            y %= s[i];
        }
    }
    printf("%d", count);

    return 0;
}
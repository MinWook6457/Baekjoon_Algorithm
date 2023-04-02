#include <stdio.h>
int main() {
    int s[100001];
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        s[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (s[i] > s[i - j * j] + 1)
                s[i] = s[i - j * j] + 1;
        }
    }

    printf("%d", s[n]);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int main() {
    char a[100];
    char b[100];
    int x, y;
    scanf("%s %s", a, b);
    int n = strlen(a);
    int m = strlen(b);
    char tmp1, tmp2;

    for (int i = 0; i < n / 2; i++) {
        tmp1 = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = tmp1;
    }
    for (int i = 0; i < m / 2; i++) {
        tmp2 = b[i];
        b[i] = b[m - i - 1];
        b[m - i - 1] = tmp2;
    }
    x = atoi(a);
    y = atoi(b);
    if (x > y)
        printf("%d", x);
    else
        printf("%d", y);
    return 0;
}
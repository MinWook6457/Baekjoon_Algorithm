#include <stdio.h>
#pragma warning(disable:4996)
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n - i; ++j) {
            printf(" ");
        }
        for (int j = 1; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
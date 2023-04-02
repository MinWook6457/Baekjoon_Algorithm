#include <stdio.h>
#pragma warning(disable:4996)
int main() {
    int s[9][9];
    int a = 0, b = 0, max = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &s[i][j]);
            if (max < s[i][j]) {
                max = s[i][j];
                a = i + 1;
                b = j + 1;
            }
        }
    }
    if (a == 0 && b == 0) {
        a = 1, b = 1;
    }
    printf("%d\n", max);
    printf("%d %d", a, b);

    return 0;
}
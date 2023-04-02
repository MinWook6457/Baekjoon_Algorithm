#include <stdio.h>
#pragma warning(disable:4996)
int i;
int main() {
    int s[9];

    for (i = 0; i < 9; i++) {
        scanf("%d", &s[i]);
    }
    int max = s[0];
    int count = 0;
    for (i = 1; i < 9; i++) {
        if (s[i] > max) {
            max = s[i];
            count = i;
        }
    }
    printf("%d\n%d", max, count + 1);

    return 0;
}
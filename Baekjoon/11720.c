#include <stdio.h>
#pragma warning(disable:4996)
int main() {
    char s[1000];

    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int l = strlen(s);
    int sum = 0;
    for (int i = 0; i < l; i++) {
        sum += (s[i] - '0');
    }

    printf("%d", sum);
    return 0;
}
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main() {
    char s[80];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int sum = 0, count = 1;
        scanf("%s", s);
        int l = strlen(s);
        for (int j = 0; j < l; j++) {
            if (s[j] == 'O') {
                sum += count;
                count++;
            }
            else
                count = 1;
        }
        printf("%d\n", sum);
    }

    return 0;
}
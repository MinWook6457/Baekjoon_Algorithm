#include <stdio.h>
#include <string.h>
int main() {
    char s[1000];
    scanf("%s", s);
    int x;
    scanf("%d", &x);
    printf("%c", s[x - 1]);

    return 0;
}
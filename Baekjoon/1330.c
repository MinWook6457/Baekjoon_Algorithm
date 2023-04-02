#include <stdio.h>
int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    if (x > y)
        printf(">");
    else if (x < y)
        printf("<");
    else
        printf("==");

    return 0;
}
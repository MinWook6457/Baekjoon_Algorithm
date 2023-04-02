#include <stdio.h>
#pragma warning(disable:4996)
int main() {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    printf("%d\n", (x + y) % z);
    printf("%d\n", ((x % z) + (y % z)) % z);
    printf("%d\n", (x * y) % z);
    printf("%d\n", ((x % z) * (y % z)) % z);
    return 0;
}
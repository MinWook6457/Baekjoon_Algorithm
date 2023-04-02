#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    int l = n / 4;
    for (int i = 0; i < l; i++) {
        printf("long ");
    }
    printf("int");

    return 0;
}
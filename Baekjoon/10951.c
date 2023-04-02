#include <stdio.h>
int main() {
    int a, b;
    while (1) {
        if (scanf("%d %d", &a, &b) == EOF) // EOF 입력 종료
            return 0;
        else
            printf("%d\n", a + b);
    }
    return 0;
}
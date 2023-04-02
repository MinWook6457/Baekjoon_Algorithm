#include <stdio.h>
#include <stdlib.h>
int main() {
    int x;
    scanf("%d", &x);
    int* s = (int*)malloc(sizeof(int) * x);

    for (int i = 0; i < x; i++) {
        scanf("%d", &s[i]);
    }

    int a = 0, b = 0, c = 0; // a : 찬성수 b : 반대수 c : 기권수

    for (int i = 0; i < x; i++) {
        if (s[i] == 1)
            a++;
        else if (s[i] == -1)
            b++;
        else if (s[i] == 0)
            c++;
    }
    if (x % 2 == 0)
        x = x / 2;
    else
        x = x / 2 + 1;

    if (c >= x)
        printf("INVALID");
    else if (a > b)
        printf("APPROVED");
    else if (b > a || b == a)
        printf("REJECTED");

    free(s);
    return 0;
}
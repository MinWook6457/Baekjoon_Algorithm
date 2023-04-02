#include <stdio.h>
#pragma warning(disable:4996)
int s[30];
int main() {

    int temp;
    for (int i = 0; i < 28; i++) {
        scanf("%d", &temp);
        s[temp - 1]++;
    }

    for (int i = 0; i < 30; i++) {
        if (s[i] == 0)
            printf("%d\n", i + 1);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    int count = 0;
    int find;
    scanf("%d", &n);

    int* s = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d ", &s[i]);
    }
    scanf("%d", &find);
    for (int i = 0; i < n; i++) {
        if (find == s[i]) {
            count++;
        }
    }
    printf("%d", count);
    free(s);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int main() {
    char s[1000001];
    gets(s);
    //getchar();
    char* ptr = strtok(s, " ");
    int count = 0;
    while (ptr != NULL) {
        count++;
        ptr = strtok(NULL, " ");
    }
    printf("%d", count);

    return 0;
}
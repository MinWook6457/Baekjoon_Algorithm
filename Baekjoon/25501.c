#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int count = 0;
int recursion(const char* s, int l, int r) {
    count++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else {
        return recursion(s, l + 1, r - 1);
    }
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    char s[1001];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        count = 0;
        scanf("%s", s);
        int pal = isPalindrome(s);
        printf("%d %d\n", pal, count);
    }

    return 0;
}
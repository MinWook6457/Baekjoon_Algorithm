#include <stdio.h>
int main() {
    int s[10];
    int count = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &s[i]);
        s[i] %= 42;
    }

    for (int i = 0; i < 10; i++) {
        int cnt = 0;
        for (int j = 0; j < i; j++) {
            if (s[i] == s[j])
                cnt++;
        }
        if (cnt == 0) {
            count++;
        }
    }
    printf("%d", count);

    return 0;
}
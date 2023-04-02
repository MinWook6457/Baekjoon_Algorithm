#include <stdio.h>
int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    y = y - 45;
    if (y < 0) {
        x = x - 1;
        if (x < 0)
            x = x + 24;
        y = y + 60;
        printf("%d %d", x, y);
    }
    else {
        printf("%d %d", x, y);
    }
    return 0;
}
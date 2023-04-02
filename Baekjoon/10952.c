#include <stdio.h>
int main() {
    for (;;) {
        int x, y;
        scanf("%d%d", &x, &y);

        if (x == 0 && y == 0)
            return 0;

        printf("%d\n", x + y);
    }

    return 0;
}
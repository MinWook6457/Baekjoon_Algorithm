#include <stdio.h>
#pragma warning(disable:4996)
int main() {
	int n;
	scanf("%d", &n);

	int num = -1;
	int max = n / 5;

	for (int i = max; i >= 0; i--) {
        if ((n - i * 5) % 3 == 0) {
            num = i + (n - i * 5) / 3;
            break;
        }
        else {
            if (i == 0)
                break;
            else
                continue;
        }
	}

    printf("%d", num);
	return 0;
}
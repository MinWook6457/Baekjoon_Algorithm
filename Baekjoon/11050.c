#include <stdio.h>
#pragma warning(disable:4996)

int factorial(int num)
{
    if (num <= 1) 
        return 1;

    return num * factorial(num - 1);
}

int func(int n, int k) {
    if (k > n)
        return 0;
    else if (k < 0)
        return 0;
    else
        return factorial(n) / (factorial(k) * (factorial(n - k)));
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int result = func(a, b);

    printf("%d", result);
	return 0;
}
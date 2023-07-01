#include <stdio.h>
#pragma warning(disable:4996)
int main() {
    long long s1, s2;
    long long diff;

    scanf("%lld %lld", &s1, &s2);

    diff = s1 >= s2 ? s1 - s2 : s2 - s1;

    printf("%lld\n", diff);

    return 0;
}
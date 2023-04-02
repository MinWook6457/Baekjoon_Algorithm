#include <stdio.h>
int main() {
    double x, y;
    scanf("%lf %lf", &x, &y);
    printf("%.13lf", x / y);
    return 0;
}
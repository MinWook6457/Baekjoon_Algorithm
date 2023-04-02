#include <stdio.h>
int main() {
    int x, y, z; // x : 시 y : 분 z : 오븐 시간
    scanf("%d %d %d", &x, &y, &z);

    int min = x * 60 + y;
    min += z;// 요리하는데 걸린 시간 더하기

    int hour = (min / 60) % 24;
    int minute = min % 60;
    printf("%d %d", hour, minute);

    return 0;
}
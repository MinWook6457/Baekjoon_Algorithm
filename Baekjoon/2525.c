#include <stdio.h>
int main() {
    int x, y, z; // x : �� y : �� z : ���� �ð�
    scanf("%d %d %d", &x, &y, &z);

    int min = x * 60 + y;
    min += z;// �丮�ϴµ� �ɸ� �ð� ���ϱ�

    int hour = (min / 60) % 24;
    int minute = min % 60;
    printf("%d %d", hour, minute);

    return 0;
}
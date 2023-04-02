#include <stdio.h>
#define Module 9901
int main() {
    int fense[1000001][3]; // ����� �� 3���� (0 : ���� ����x 1: ���� ���ʿ� ���� 2: ���� �����ʿ� ����)
    fense[1][0] = 1, fense[1][1] = 1, fense[1][2] = 1;

    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        fense[i][0] = (fense[i - 1][0] + fense[i - 1][1] + fense[i - 1][2]) % Module;
        fense[i][1] = (fense[i - 1][0] + fense[i - 1][2]) % Module;
        fense[i][2] = (fense[i - 1][0] + fense[i - 1][1]) % Module;
    }
    int result = (fense[n][0] + fense[n][1] + fense[n][2]) % Module;
    printf("%d", result);
    return 0;
}
#include <stdio.h>
#pragma warning(disable:4996)
int main() {
    int n;
    scanf("%d", &n);

    int count = 0; // ������ ���� ����
    int num = 666; // ���� ���� 
    while (1) {
        // num�� 666�� ���Եȴٸ� count++
        int consecutive_6 = 0;
        int cur = num;
        while (cur > 0) {
            int digit = cur % 10;
            if (digit == 6)
                consecutive_6++;
            else
                consecutive_6 = 0; //�ٽ� 0���� �ʱ�ȭ

            if (consecutive_6 == 3) { // 666
                count++;
                break;
            }
            cur = cur / 10;
        }
        if (count == n)
            break;
        num++;
    }
    printf("%d\n", num);
}
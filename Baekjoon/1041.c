#include <stdio.h>
#pragma warning(disable:4996)
#define max(x,y) ((x) > (y) ? (x) : (y)) 
#define min(x,y) ((x) < (y) ? (x) : (y)) 
// 3���� ���̴� �ֻ��� ����, 2���� ���̴� �ֻ��� ����, 1���� ���̴� �ֻ��� ������ ���� ���ϴ� �����̴�.
// ���ֺ��� ���� ���ԵǼ� �ȵȴ�.
// A-F�� 0-5 ������ �Է��Ѵٰ� �������� ��,
// A,F�� 0��5, E,B�� 1��4, C,D�� 2��3�� ���ֺ���.
int n;
int dice[6];
int three = 5000, two = 5000, one = 5000, large = 0;
long long result = 0;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 6; i++) {
        scanf("%d", &dice[i]);
        result += dice[i];
        large = max(large, dice[i]); 
    }

    if (n == 1) { // �ֻ����� 1���� ���
        printf("%lld", result - large);
        return 0;
    }

    // ���ֺ��� ��� ���ֱ�
    for (int i = 0; i < 6; i++) {
        one = min(one, dice[i]); // 1�� ��
        for (int j = i + 1; j < 6; j++) {
            if (i + j == 5) // ���ֺ��� ���
                continue;
            two = min(dice[i] + dice[j], two); // 2����
            for (int k = j + 1; k < 6; k++) {
                if (i + k == 5 || j + k == 5) // ���ֺ��� ���
                    continue;
                three = min(three, dice[i] + dice[j] + dice[k]); // 3����
            }
        }
    }

    // 3�� : 4, 2�� : 8n-12, 1�� : (5n-6)(n-2)
    result = 0;
    result += (5 * (long long)n * n - 16 * n + 12) * one;
    result += 4 * three;
    result += (8 * n - 12) * two;
    printf("%lld", result);

    return 0;
}
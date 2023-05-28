#include <stdio.h>
#pragma warning(disable:4996)
#define max(x,y) ((x) > (y) ? (x) : (y)) 
#define min(x,y) ((x) < (y) ? (x) : (y)) 
// 3면이 보이는 주사위 갯수, 2면이 보이는 주사위 갯수, 1면이 보이는 주사위 갯수의 합을 구하는 문제이다.
// 마주보는 면은 포함되선 안된다.
// A-F를 0-5 순서로 입력한다고 가정했을 때,
// A,F는 0과5, E,B는 1과4, C,D는 2와3이 마주본다.
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

    if (n == 1) { // 주사위가 1개인 경우
        printf("%lld", result - large);
        return 0;
    }

    // 마주보는 경우 없애기
    for (int i = 0; i < 6; i++) {
        one = min(one, dice[i]); // 1면 합
        for (int j = i + 1; j < 6; j++) {
            if (i + j == 5) // 마주보는 경우
                continue;
            two = min(dice[i] + dice[j], two); // 2면합
            for (int k = j + 1; k < 6; k++) {
                if (i + k == 5 || j + k == 5) // 마주보는 경우
                    continue;
                three = min(three, dice[i] + dice[j] + dice[k]); // 3면합
            }
        }
    }

    // 3면 : 4, 2면 : 8n-12, 1면 : (5n-6)(n-2)
    result = 0;
    result += (5 * (long long)n * n - 16 * n + 12) * one;
    result += 4 * three;
    result += (8 * n - 12) * two;
    printf("%lld", result);

    return 0;
}
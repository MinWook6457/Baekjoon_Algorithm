#include <stdio.h>
#pragma warning(disable:4996)
int main() {
    int people[11];
    int answer[11] = { 0 };

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &people[i]);
    }

    for (int i = 0; i < n; i++) {
        int count = 0; // 줄 선 번호를 세기위한 변수
        for (int j = 0; j < n; j++) {
            if (people[i] == count) {
                if (!answer[j]) {
                    answer[j] = i + 1;
                    break;
                }
            }
            else {
                if (!answer[j])
                    count++;
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", answer[i]);

    return 0;
}
#include <stdio.h>
#include <stdlib.h> // 퀵 정렬 
#include <math.h> // abs 
#define max(X,Y) ((X) > (Y) ? (X) : (Y)) // max 정의
#pragma warning(disable:4996)
int book[10000];
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int count = 0;
    int result = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &book[i]);
        if (book[i] < 0)
            count++;
    }
    qsort(book, n, sizeof(int), compare); // 정렬
    // 가장 끝에 있는 인덱스가 가장 먼 거리임

    // 음수 거리 처리
    for (int i = 0; i < count; i += m) {
        result += abs(book[i] * 2);
    }

    for (int i = n - 1; i >= count; i -= m) {
        result += book[i] * 2;
    }

    // 극한값 빼기
    result -= max(abs(book[0]), abs(book[n - 1])); // 어느 쪽이 음수인지 모르기 때문에 양쪽 모두 절대값 처리

    printf("%d ", result);

    return 0;
}
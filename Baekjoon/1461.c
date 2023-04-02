#include <stdio.h>
#include <stdlib.h> // �� ���� 
#include <math.h> // abs 
#define max(X,Y) ((X) > (Y) ? (X) : (Y)) // max ����
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
    qsort(book, n, sizeof(int), compare); // ����
    // ���� ���� �ִ� �ε����� ���� �� �Ÿ���

    // ���� �Ÿ� ó��
    for (int i = 0; i < count; i += m) {
        result += abs(book[i] * 2);
    }

    for (int i = n - 1; i >= count; i -= m) {
        result += book[i] * 2;
    }

    // ���Ѱ� ����
    result -= max(abs(book[0]), abs(book[n - 1])); // ��� ���� �������� �𸣱� ������ ���� ��� ���밪 ó��

    printf("%d ", result);

    return 0;
}
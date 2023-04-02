#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct
{
    int x;
    int y;
} point; // ����ü ����
int compare(const void* a, const void* b) // qsort ���� �Լ� compare ������
{
    point A = *(point*)a; // ĳ����
    point B = *(point*)b; // ĳ����
    if (A.x > B.x) // �������� ����
        return 1;
    else if (A.x == B.x)
    {
        if (A.y > B.y)
            return 1;
        else
            return -1;
    }
    return -1;
}

int main()
{
    int n, i;
    scanf("%d", &n);

    point* arr = (point*)malloc(sizeof(point) * n);// ����ü �����Ҵ�

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }

    qsort(arr, n, sizeof(point), compare); // ������ ���
    i = 0;
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i].x, arr[i].y); // ���ĵ� �迭 ���
    }


    return 0;
}
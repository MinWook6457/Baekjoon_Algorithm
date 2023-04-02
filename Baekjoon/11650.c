#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct
{
    int x;
    int y;
} point; // 구조체 선언
int compare(const void* a, const void* b) // qsort 내장 함수 compare 재정의
{
    point A = *(point*)a; // 캐스팅
    point B = *(point*)b; // 캐스팅
    if (A.x > B.x) // 오름차순 정렬
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

    point* arr = (point*)malloc(sizeof(point) * n);// 구조체 동적할당

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }

    qsort(arr, n, sizeof(point), compare); // 퀵정렬 사용
    i = 0;
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i].x, arr[i].y); // 정렬된 배열 출력
    }


    return 0;
}
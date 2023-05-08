/*
	|Ai + T - Bi| 식을 y = 꼴 식으로 표현해보면
	y = |x-a| 와 같다. 
	i가 증가함에 따라 y = |x| + |x-a| + |x-b| 형식으로 바뀔 수 있다.
	기본적인 함수형은 y = |x-a| 를 따른다. 일차적으로 V 형태 함수
	식이 홀수 개 일경우 최소가 되는 꼭지점 개수가 1개 이므로 최소 개수는 1임
	식이 짝수 개 일경우 차식을 오름차순 했을 경우 중앙 두 값을 포함한 사이값들이 최소 값이 되므로
	a와 b 사이라면 [a,b] 의 개수가 최소 개수임
*/
/*
    홀수 짝수 알고리즘을 이용하여 문제 해결을 하려고 했으나 
    최소값이 겹치는 경우에 문제가 발생하여 문제에서 주어진 수식을 활용하여
    알고리즘을 해결하였으나 틀렸습니다 출력
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
int arr[10000];
#pragma warning(disable:4996)
int compare(const void* a, const void* b) // 오름차순 비교 함수 구현
{
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2)
        return -1;

    if (num1 > num2)
        return 1;

    return 0;
}
int main() {
    int n;
    scanf("%d", &n);
    int x, y;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        arr[i] = y - x;
    }
    qsort(arr, n, sizeof(int), compare);
    // 홀수일 경우 답은 1
    if (n % 2 == 1)
    {
        printf("1");
        return 0;
    }
    // 짝수일 경우 arr[n/2] arr[n/2-1] 사이의 모든 수들의 합을 최소로 만드는 값
    else
    {  
        printf("%d", abs(arr[n/2] - arr[(n / 2) - 1]) + 1);
    }
    return 0;
}
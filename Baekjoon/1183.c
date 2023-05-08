/*
	|Ai + T - Bi| ���� y = �� ������ ǥ���غ���
	y = |x-a| �� ����. 
	i�� �����Կ� ���� y = |x| + |x-a| + |x-b| �������� �ٲ� �� �ִ�.
	�⺻���� �Լ����� y = |x-a| �� ������. ���������� V ���� �Լ�
	���� Ȧ�� �� �ϰ�� �ּҰ� �Ǵ� ������ ������ 1�� �̹Ƿ� �ּ� ������ 1��
	���� ¦�� �� �ϰ�� ������ �������� ���� ��� �߾� �� ���� ������ ���̰����� �ּ� ���� �ǹǷ�
	a�� b ���̶�� [a,b] �� ������ �ּ� ������
*/
/*
    Ȧ�� ¦�� �˰����� �̿��Ͽ� ���� �ذ��� �Ϸ��� ������ 
    �ּҰ��� ��ġ�� ��쿡 ������ �߻��Ͽ� �������� �־��� ������ Ȱ���Ͽ�
    �˰����� �ذ��Ͽ����� Ʋ�Ƚ��ϴ� ���
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
int arr[10000];
#pragma warning(disable:4996)
int compare(const void* a, const void* b) // �������� �� �Լ� ����
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
    // Ȧ���� ��� ���� 1
    if (n % 2 == 1)
    {
        printf("1");
        return 0;
    }
    // ¦���� ��� arr[n/2] arr[n/2-1] ������ ��� ������ ���� �ּҷ� ����� ��
    else
    {  
        printf("%d", abs(arr[n/2] - arr[(n / 2) - 1]) + 1);
    }
    return 0;
}
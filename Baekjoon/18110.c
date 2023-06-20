#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

int cmp(const void* a, const void* b) {
	int num1 = *(int*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	int num2 = *(int*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (num1 < num2)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ

	if (num1 > num2)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
}

int main() {
	int n;
	float res = 0;
	scanf("%d", &n);

	if (n == 0) {
		printf("0");
		return 0;
	}


	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);	
	}

	float tmp = n * 0.15;    // 30%�� ��������� ����

	tmp = round(tmp);    // �ݿø�

	qsort(arr, n, sizeof(arr[0]), cmp);


	for (int i = tmp; i < n - tmp; i++) {    // �ݿø��� ���������
		res += (float)arr[i];                // �Ʒ�15%, �� 15%���� �����ϰ� ����
	}
	
	res /= (n - tmp * 2);
	res = round(res);

	printf("%.f", res);

	free(arr);
	return 0;
}
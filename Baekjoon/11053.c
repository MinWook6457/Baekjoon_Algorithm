#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int arr[1001];
	int dp[1001] = {0,}; // Dynamic Programming Array

	int max = 0;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++) { // ���� ��ȹ�� ���
		int min = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) // �ּڰ��� ������ �ε��� ã��
				if (min < dp[j])
					min = dp[j];
		}

		dp[i] = min + 1; // dp �迭�� �ε��� ����
		if (max < dp[i]) // �ִ� = ������ ����
			max = dp[i];
	}

	printf("%d", max);
	return 0;
}
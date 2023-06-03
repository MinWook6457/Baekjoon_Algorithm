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

	for (int i = 0; i < n; i++) { // 동적 계획법 사용
		int min = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) // 최솟값을 가지는 인덱스 찾기
				if (min < dp[j])
					min = dp[j];
		}

		dp[i] = min + 1; // dp 배열에 인덱스 저장
		if (max < dp[i]) // 최댓값 = 수열의 길이
			max = dp[i];
	}

	printf("%d", max);
	return 0;
}
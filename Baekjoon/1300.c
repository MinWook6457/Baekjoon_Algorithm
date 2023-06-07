/*
	low=1, high=n*n으로 설정
		low <= high 일 동안 while문 루프
			mid값 구하기
		mid값보다 작거나 같은 수들 구하기 => cnt
		
		cnt값이 목표 인덱스(K) 보다 크거나 같을 경우
		mid를 좀 더 왼쪽으로 옮겨야 한다.
		high = mid - 1
	
		cnt값이 목표 인덱스(K) 보다 작을 경우
		mid를 좀 더 오른쪽으로 옮겨야 한다.
		low = mid + 1
	루프 탈출 후 low값 출력
*/
#include <stdio.h>
#define min(a,b) (a) < (b) ? (a) : (b)
#pragma warning(disable:4996)
#define INF 1000000000
typedef long long int ll;
ll n, k;
ll low, high, mid;
ll cnt;

ll func(ll x) { // mid보다 작은 수들의 개수를 시간 초과 없이 시간 복잡도 O(n) 으로 구현
	ll sum = 0;

	for (int i = 1; i <= n; i++){ 
		sum += min(x / i, n);
	}
	return sum;
}

int main() {
	scanf("%lld%lld", &n, &k);

	low = 1;
	high = n * n;

	k = min((long long)INF, k);

	while (low <= high) { // 이진 탐색
		mid = (low + high) / 2;

		cnt = func(mid); 

		if (cnt >= k) { // cnt값이 목표 인덱스(K) 보다 크거나 같을 경우
			high = mid - 1; // high 값 업데이트
		}
		else { // cnt값이 목표 인덱스(K) 보다 작을 경우 
			low = mid + 1; // low 값 업데이트
		}
	}
	
	printf("%d", low); // 

	return 0;
}
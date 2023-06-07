/*
	low=1, high=n*n���� ����
		low <= high �� ���� while�� ����
			mid�� ���ϱ�
		mid������ �۰ų� ���� ���� ���ϱ� => cnt
		
		cnt���� ��ǥ �ε���(K) ���� ũ�ų� ���� ���
		mid�� �� �� �������� �Űܾ� �Ѵ�.
		high = mid - 1
	
		cnt���� ��ǥ �ε���(K) ���� ���� ���
		mid�� �� �� ���������� �Űܾ� �Ѵ�.
		low = mid + 1
	���� Ż�� �� low�� ���
*/
#include <stdio.h>
#define min(a,b) (a) < (b) ? (a) : (b)
#pragma warning(disable:4996)
#define INF 1000000000
typedef long long int ll;
ll n, k;
ll low, high, mid;
ll cnt;

ll func(ll x) { // mid���� ���� ������ ������ �ð� �ʰ� ���� �ð� ���⵵ O(n) ���� ����
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

	while (low <= high) { // ���� Ž��
		mid = (low + high) / 2;

		cnt = func(mid); 

		if (cnt >= k) { // cnt���� ��ǥ �ε���(K) ���� ũ�ų� ���� ���
			high = mid - 1; // high �� ������Ʈ
		}
		else { // cnt���� ��ǥ �ε���(K) ���� ���� ��� 
			low = mid + 1; // low �� ������Ʈ
		}
	}
	
	printf("%d", low); // 

	return 0;
}
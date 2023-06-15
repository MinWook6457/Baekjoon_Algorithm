#include <stdio.h>
#pragma warning(disable:4996)
typedef long long int ll;

int main() {
	ll k, n;
	ll low = 1;
	ll high = -1;
	ll mid;

	ll line[10001] = { 0, };
	ll result = 0;
	ll sum = 0;

	scanf("%lld%lld", &k, &n);

	for (int i = 0; i < k; i++) {
		scanf("%lld", &line[i]);
		high = high < line[i] ? line[i] : high;
	}

	while (low <= high) {
		mid = (low + high) / 2;
		sum = 0;
		for (int j = 0; j < k; j++) {
			sum += (line[j] / mid);
		}

		if (sum < n)
			high = mid - 1;
		else if (sum >= n) {
			low = mid + 1;
			result = result < mid ? mid : result;
		}
	}

	printf("%lld", result);
	return 0;
}	
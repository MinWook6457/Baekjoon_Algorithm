#include <stdio.h>
#pragma warning(disable:4996)
typedef long long ll;
#define M 1234567891

int main() {
	char s[51];
	int n;

	ll hash_value = 0;
	ll r = 1;

	scanf("%d %s", &n, s);

	for (int i = 0; i < n; i++) {
		hash_value = (hash_value + (s[i] - 'a' + 1) * r) % M;
		r = (r * 31) % M;
	}

	printf("%lld", hash_value);

	return 0;
}
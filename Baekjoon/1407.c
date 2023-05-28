#include <stdio.h>
#pragma warning(disable:4996)
/*
	문제 해석 :
	i) 홀수인 경우 무조건 1
	ii) 짝수인 경우
	f(2) = 2
	f(4) = 4
	f(6) = 2 * f(3)
	S(n) = f(1) + f(2) + ... + f(n-1) + f(n)

	점화식 : S(n) = s(b) - s(a-1)

	if n % 2 == 0
		s(n/2) = 1 // 짝수를 나누면 홀수
	else
		s(n/2) + 1 = 1

	((n/2) - 1) % 2 == 0

	f(2n)= 2f(n)

	짝수들의 합 2S(n)

	==> 재귀함수로 표현 가능
		if(n % 2 ==0)
			S(n) = n / 2 + S(n/2)
		else
			S(n) = n / 2 + S(n/2) + 1
*/
long long int func(long long int n) {
	if (n == 0) // 재귀 종료 시점
		return 0;
	else if (n == 1)
		return 1;
	else if (n % 2 == 0)
		return (n / 2) + 2 * func(n / 2);
	else if (n % 2 == 1)
		return (n / 2) + 2 * func(n / 2) + 1;
}
int main() {
	long long int a, b;

	scanf("%lld%lld", &a, &b);

	long long int result = func(b) - func(a - 1);

	printf("%lld", result);

	return 0;
}
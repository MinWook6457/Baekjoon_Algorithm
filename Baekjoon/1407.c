#include <stdio.h>
#pragma warning(disable:4996)
/*
	���� �ؼ� :
	i) Ȧ���� ��� ������ 1
	ii) ¦���� ���
	f(2) = 2
	f(4) = 4
	f(6) = 2 * f(3)
	S(n) = f(1) + f(2) + ... + f(n-1) + f(n)

	��ȭ�� : S(n) = s(b) - s(a-1)

	if n % 2 == 0
		s(n/2) = 1 // ¦���� ������ Ȧ��
	else
		s(n/2) + 1 = 1

	((n/2) - 1) % 2 == 0

	f(2n)= 2f(n)

	¦������ �� 2S(n)

	==> ����Լ��� ǥ�� ����
		if(n % 2 ==0)
			S(n) = n / 2 + S(n/2)
		else
			S(n) = n / 2 + S(n/2) + 1
*/
long long int func(long long int n) {
	if (n == 0) // ��� ���� ����
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
#include <stdio.h>
#pragma warning(disable:4996)
int main() {
	char c;
	scanf("%c", &c);
	if (c == 'n' || c == 'N')
		printf("Naver D2\n");
	else
		printf("Naver Whale");

	return 0;

}
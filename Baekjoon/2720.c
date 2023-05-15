#include <stdio.h>
#pragma warning(disable:4996)
int main() {
	int n;
	int money[4] = { 25,10,5,1 };
	
	int cent;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &cent);
		int count[4] = { 0, };
		for (int j = 0; j < 4; j++) {

			while (cent >= money[j]) {
				cent -= money[j];
				count[j]++;
			}
			if (cent == 0)
				break;
		}
		for (int i = 0; i < 4; i++) {
			printf("%d ", count[i]);
		}
		printf("\n");
	}
	
	return 0;
}
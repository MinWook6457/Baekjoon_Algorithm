#include <stdio.h>
#pragma warning(disable:4996)
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int r;
		char str[101];
		scanf("%d", &r);
		scanf("%s", str);
		int length = strlen(str);
		for (int j = 0; j < length; j++) {
			for (int k = 0; k < r; k++) {
				printf("%c", str[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
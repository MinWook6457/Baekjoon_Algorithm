#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	int a, b, c;
	char arr[1000001] = { 0, };
	scanf("%d%d%d", &a, &b, &c);

	char number[] = "0123456789";
	int count[10] = { 0, };

	int result = a * b * c;
	
	sprintf(arr, "%d", result);


	for (int i = 0; i < strlen(arr); i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i] == number[j])
				count[j] += 1;
		}
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", count[i]);
	}

	return 0;
}
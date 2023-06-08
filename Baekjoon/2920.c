#include <stdio.h>
#include <string.h>
#define size 8
#pragma warning(disable:4996)

int main() {
	int arr[size];
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	int num = arr[0];
	if (num == 1) {
		for (int i = 1; i < size; i++) {
			num++;
			if (arr[i] != num)
				break;
			if (i == 7) {
				printf("ascending\n");
				return 0;
			}
		}
	}
	else if (num == 8) {
		for (int i = 1; i < size; i++) {
			num--;
			if (arr[i] != num) {
				break;
			}
			if (i == 7) {
				printf("descending\n");
				return 0;
			}
		}
	}
	printf("mixed\n");

	return 0;
}
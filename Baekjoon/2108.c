#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)


int arithmetic_mean(int* arr, int n) { // »ê¼úÆò±Õ
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (double)arr[i];
	}
	return (int)round(sum / n);
}

int median(int* arr, int n) { // Áß¾Ó°ª
	int num = 0;
	for (int i = 0; i < 8001; i++) {
		num += arr[i];	
		if (num >= (n + 1) / 2) {
			return i - 4000;
		}
	}
	return 0;
}

int mode(int* arr, int n) { // ÃÖºó°ª
	int max = 0;
	int num = 0;
	int mode = 0;
	for (int i = 0; i < 8001; i++) {
		if (arr[i] > max) {
			max = arr[i];
			num = 1;
			mode = i - 4000;
		}
		else if (arr[i] == max) {
			if (num == 1) {
				num++;
				mode = i - 4000;
			}
			else {
				num++;
			}
		}
	}
	return mode;
}

int range(int* arr, int n) {
	int max = 0;
	int min = 0;
	for (int i = 8000; i >= 0; i--) {
		if (arr[i] != 0) {
			max = i;
			break;
		}
	}
	for (int i = 0; i < 8001; i++) {
		if (arr[i] != 0) {
			min = i;
			break;
		}
	}
	return max - min;
}

int main() {
	int n;
	scanf("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int counting[8001];
	for (int i = 0; i < 8001; i++) {
		counting[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		counting[arr[i] + 4000]++;    //0~8000 -> -4000~4000
	}

	printf("%d\n", arithmetic_mean(arr, n));
	printf("%d\n", median(counting, n));
	printf("%d\n", mode(counting, n));
	printf("%d\n", range(counting, n));


	free(arr);
	return 0;
}
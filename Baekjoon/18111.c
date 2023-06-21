#include <stdio.h>
#pragma warning(disable:4996)
int arr[500][500];
int num[257];

int main() {
	int n, m, b;

	scanf("%d%d%d", &n, &m, &b);	

	int gap[2] = { 0 };
	int f = 0;

	int min = 192000000;
	int min_num = 0;
	int max = 0;
	int btemp = b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (max < arr[i][j])
				max = arr[i][j];
		}
	}

	for (int i = 0; i <= 256; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arr[j][k] > i) {
					gap[0] += arr[j][k] - i;
					b += arr[j][k] - i;
				}
			}
		}
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arr[j][k] <= i) {
					gap[1] += i - arr[j][k];
					b -= i - arr[j][k];
				}
				if (b < 0) {
					gap[1] = 64000000; 
					gap[0] = 64000000; 
					f = 1; 
					break; 
				}
			}
			if (f == 1) { 
				f = 0; 
				break; 
			}
		}
		num[i] = (gap[0] * 2) + (gap[1]);
		if (num[i] <= min) {
			min = num[i]; 
			min_num = i; 
		}
		gap[0] = 0; 
		gap[1] = 0;
		b = btemp;
	}

	printf("%d %d", min, min_num);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

int cmp(const void* a, const void* b) {
	int num1 = *(int*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1 < num2)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (num1 > num2)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}

int main() {
	int n;
	float res = 0;
	scanf("%d", &n);

	if (n == 0) {
		printf("0");
		return 0;
	}


	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);	
	}

	float tmp = n * 0.15;    // 30%의 절사평균을 구함

	tmp = round(tmp);    // 반올림

	qsort(arr, n, sizeof(arr[0]), cmp);


	for (int i = tmp; i < n - tmp; i++) {    // 반올림한 절사평균을
		res += (float)arr[i];                // 아래15%, 위 15%명을 제외하고 더함
	}
	
	res /= (n - tmp * 2);
	res = round(res);

	printf("%.f", res);

	free(arr);
	return 0;
}
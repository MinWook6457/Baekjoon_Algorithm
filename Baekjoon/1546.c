#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    double result = ((double)sum / (double)max) * 100 / (double)n;
    printf("%lf", result);
    free(arr);
    return 0;
}
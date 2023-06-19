#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct{
	int age;
	char name[101];
}student;

int compare(const void* a, const void* b) {
	student* a1 = (student*)a;
	student* b1 = (student*)b;

	if (a1->age > b1->age)
		return 1;
	else if (a1->age < b1->age)
		return -1;
	else
		return 0;
}

int main() {
	int n;
	scanf("%d", &n);

	student* st = (student *)malloc(sizeof(student) * n);
	for (int i = 0; i < n; i++) {	//ют╥б
		scanf("%d%*c%s", &st[i].age,st[i].name);
	}

	qsort(st, n, sizeof(student), compare);

	for (int i = 0; i < n; i++) {
		printf("%d %s\n", st[i].age, st[i].name);
	}

	free(st);

	return 0;
}
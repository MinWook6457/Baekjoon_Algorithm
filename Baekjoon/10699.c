#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)
int main(void)
{
	struct tm* t;
	time_t base = time(NULL);

	t = localtime(&base);

	printf("%d-%02d-%02d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);

	return 0;
}
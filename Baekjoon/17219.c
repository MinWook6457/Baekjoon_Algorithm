#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
typedef struct _dict
{
    char url[21];
    char pw[21];
} Dict;
Dict dicts[100000] = { 0, };

int cmp(const void* a, const void* b)
{
    Dict dict1 = *(Dict*)a;
    Dict dict2 = *(Dict*)b;
    return (strcmp(dict1.url, dict2.url));
}

char* binsearch(Dict* dicts, int len, char* target)
{
    int start = 0;
    int end = len - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (!strcmp(dicts[mid].url, target))
            return dicts[mid].pw;
        if (strcmp(dicts[mid].url, target) < 0)
            start = mid + 1;
        if (strcmp(dicts[mid].url, target) > 0)
            end = mid - 1;
    }
    return ("");
}
int main()
{
    int n, m;

    scanf("%d %d", &n, &m);
   

    for (int i = 0; i < n; ++i)
    {
        char url[21] = { 0, };
        char pw[21] = { 0, };
        scanf("%s %s", url, pw);

        strncpy(dicts[i].url, url, strlen(url));
        strncpy(dicts[i].pw, pw, strlen(pw));
    }
    qsort(dicts, n, sizeof(Dict), cmp);
    for (int i = 0; i < m; ++i)
    {
        char url[21] = { 0, };
        scanf("%s", url);
        printf("%s", binsearch(dicts, n, url));
        if (i < m - 1)
            printf("\n");
    }
    return 0;
}

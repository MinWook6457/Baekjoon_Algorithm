#include <stdio.h>
#pragma warning(disable:4996)
int main() {
    char s[101];
    char a[26];
    int arr[26];
    for (int i = 0; i < 26; i++) {
        a[i] = 'a' + i;
        arr[i] = -1;
    }
    scanf("%s", s);

    int n = strlen(s);
    for (int i = 'a'; i <= 'z'; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == s[j])
            {
                arr[s[j] - 'a'] = j;
                break;
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%d", arr[i]);
        if (i < 25)
            printf(" ");
    }
    return 0;
}
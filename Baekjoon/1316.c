#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

#define MAX_LENGTH 101
#define ALPHABET_COUNT 26

int is_group_word(const char *word)
{
    int visited[ALPHABET_COUNT] = {0};
    char prev_char = '\0';

    while (*word)
    {
        char current = *word;
        if (current != prev_char)
        {
            if (visited[current - 'a'])
            {
                return 0;
            }
            visited[current - 'a'] = 1;
        }
        prev_char = current;
        word++;
    }

    return 1;
}

int main()
{
    int n, count = 0;
    char word[MAX_LENGTH];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", word);
        if (is_group_word(word))
        {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}

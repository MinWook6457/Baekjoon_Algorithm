#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define max_n 50

int compare(const void* a, const void* b) {
    char* word1 = *(char**)a;
    char* word2 = *(char**)b;

    if (strlen(word1) != strlen(word2))
        return strlen(word1) - strlen(word2);

    return strcmp(word1, word2);
}

int main() {
    char** words;
    int n;
    scanf("%d", &n);

    words = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        words[i] = (char*)malloc(sizeof(char) * (max_n + 1));
        scanf("%s", words[i]);
    }

    qsort(words, n, sizeof(words[0]), compare);

    for (int i = 0; i < n; i++) {
        if (i > 0 && strcmp(words[i], words[i - 1]) == 0)
            continue;
        printf("%s\n", words[i]);
    }

    // 동적 메모리 해제
    for (int i = 0; i < n; i++)
        free(words[i]);
    free(words);
    return 0;
}
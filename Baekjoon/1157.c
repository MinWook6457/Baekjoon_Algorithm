#include <stdio.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

int main() {
	char input[1000001];
	char s[26] = { 0, };
	int count[26] = { 0, };
	int arr[255];
	
	scanf("%s", input);

	int n = strlen(input);

	for (int i = 0; i < n; i++) {
		char cur = toupper(input[i]);
		count[cur - 'A']++;
	}

	int max = 0, num = 0, max_alphabet = 0; 
	for (int k = 0; k < 26; k++) {
		if (count[k] > max) {
			max = count[k];
			num = 1;
			max_alphabet = 'A' + k;
		}
		else if (max != 0 && count[k] == max) {
			num++;
		}
		else {
			continue;
		}
	}


	if (num == 1) {
		printf("%c", max_alphabet);
	}
	else {
		printf("?");
	}

	return 0;
}
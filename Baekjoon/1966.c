#include <stdio.h>
#pragma warning(disable:4996)
int queue[100];

int main() {
	int n;
	int p, q;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p, &q);
		int cnt = 1;
		int front = 0;
		int max = 0;
		
		for (int j = 0; j < p; j++) {
			scanf("%d", &queue[j]);
		}
		while (1) {
			//ÃÖ´ñ°ª Ã£±â
			for (int k = 0; k < p; k++) {
				if (queue[k] > max) {
					max = queue[k];
				}
			}
			while (queue[front] != max) {
				front = (front + 1) % p;
			}
			if (front == q) {
				break;
			}
			queue[front] = 0;
			front = (front + 1) % p;
			max = 0;
			cnt++;
		}
		printf("%d\n", cnt);
	}
}
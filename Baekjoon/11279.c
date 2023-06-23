#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define swap(a, b) {int tmp=a; a=b; b=tmp;}

typedef struct HeapType {
	int heap[100001];
	int heap_size;
}HeapType;

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, int data) { // 최대 힙 삽입 연산
	int i; // heap index for new node
	i = ++(h->heap_size); // heap_size increment

	// i가 루트가 아니고 i번째 노드가 부모 노드보다 크면
	while ((i != 1) && data > h->heap[i / 2]) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = data;
}

int delete_max_heap(HeapType* h) { // 최대 힙 삭제 연산
	if (h->heap_size == 0)
		return 0;
	int temp = h->heap[1];
	h->heap[1] = h->heap[h->heap_size--];
	int parent = 1;
	int child;
	
	while (1) {
		child = parent * 2;
		if (child + 1 <= h->heap_size && h->heap[child] < h->heap[child + 1]) {
			child++;
		}

		if (child > h->heap_size || h->heap[child] < h->heap[parent]) {
			break;
		}
		swap(h->heap[parent], h->heap[child]);
		parent = child;
	}
	return temp;;
}

int main() {
	int n;
	HeapType h;
	init(&h);

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int data;
		scanf("%d", &data);

		if (data == 0) {
			int x = delete_max_heap(&h);
			printf("%d\n", x);
		}
		else {
			insert_max_heap(&h,data);
		}

	}
	return 0;
}
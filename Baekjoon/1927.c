#include <stdio.h>
#pragma warning(disable:4996)
#define swap(type,x,y) do{type t = x ; x = y; y = t;} while(0)
#define SIZE 100001
typedef struct heap {
	int size;
	int heap[SIZE];
}heap;

void init(heap* h) {
	h->size = 0;
}

int insert_heap(heap* h, int data) {
	if (h->size + 1 > SIZE) {
		return 0;
	}

	h->heap[h->size] = data;
	int current = h->size;
	int parent = (h->size - 1) / 2;

	while (current > 0 && h->heap[current] < h->heap[parent]) {
		swap(int, h->heap[current], h->heap[parent]);
		current = parent;
		parent = (parent - 1) / 2;
	}

	h->size++;

	return 1;
}

int delete_heap(heap* h) {
	if (h->size <= 0) {
		return 0;
	}

	int cut = h->heap[0];

	h->size--;
	h->heap[0] = h->heap[h->size];

	int current = 0;
	int minNode = 0;
	int left_child = current * 2 + 1;
	int right_child = current * 2 + 2;

	while (left_child < h->size) {
		if (h->heap[left_child] < h->heap[minNode]) {
			minNode = left_child;
		}

		if (right_child < h->size && h->heap[right_child] < h->heap[minNode]) {
			minNode = right_child;
		}

		if (current == minNode)
			break;
		else {
			swap(int, h->heap[current], h->heap[minNode]);
			current = minNode;
			left_child = current * 2 + 1;
			right_child = current * 2 + 2;
		}
	}

	return cut;
}

int main() {
	int n;

	scanf("%d", &n);
	heap h;

	init(&h);

	for (int i = 0; i < n; i++) {
		int data;
		scanf("%d", &data);
		if (data == 0) {
			printf("%d\n", delete_heap(&h));
		}
		else {
			insert_heap(&h, data);
		}
	}

	return 0;
}
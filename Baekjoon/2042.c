// �θ����ȣ x 2 = �����ڽĳ���ȣ, �θ����ȣ x 2 + 1 = �������ڽĳ���ȣ
// ���׸�Ʈ Ʈ�� �̿��Ͽ� ���� �ذ�
//      10		
//   3       7
//  1 2    3  4

/*
	ũ�Ⱑ N�� �迭�� ������ ��

	1. Ʈ���� ���� = ceil(log2(N))

	2. ���׸�Ʈ Ʈ���� ũ�� = (1 << (Ʈ���� ���� + 1) )

*/

// { ���� ��� ��ȣ , ���� ���� , ������ ���� }
// �ε��� 1���� ���

/*
1. �־��� ������ ������ ������.

2. ������ 2���� ������ ���ؼ� '���ʹ���'�� ���� ���ȣ���� �Ѵ�.

3. ������ 2���� ������ ���ؼ� '�����ʹ���'�� ���� ���ȣ���� �Ѵ�.

4. ���� ������ �ݺ��Ѵ�.
*/

#include <stdio.h>
#pragma warning(disable:4996)
typedef long long int ll; // long long Ÿ�� ����
ll arr[1000000];
ll tree[4000000];

ll MakeSegmentTree(int start, int end, int node) { // Ʈ�� ����
	if (start == end) // ��� ���� ����
		return tree[node]=arr[start];

	int mid = (start + end) / 2; // �߰��� ����
	tree[node] =  MakeSegmentTree(start, mid, node * 2) + MakeSegmentTree(mid + 1, end, node * 2 + 1); 
	// ���� Ʈ�� ��ȯ �� + ������ Ʈ�� ��ȯ �� ����
	return tree[node]; // ���׸�Ʈ Ʈ�� ��ȯ
}

ll sum(int start, int end, int node, int left, int right) { // ������ �Լ�
	if (start > right || end < left) // Ž�� ������ ������ ��� ���
		return 0;
	if (left <= start && end <= right) // Ž�� ������ ������ ���� ���
		return tree[node];

	/* Ž�� ������ �� �� ��츦 �����ϰ� �Ϻθ� ��ġ�� ��� */
	int mid = (start + end) / 2;
	 
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

ll UpdateSegmentTree(int start, int end, int node, int index, ll diff) {
	if (index < start || index > end) // ������ ��� ���
		return;

	tree[node] += diff; // Ʈ�� ��� ������Ʈ
	
	if (start == end) // ��� ���� ����
		return;

	int mid = (start + end) / 2;
	UpdateSegmentTree(start, mid, node * 2, index, diff);
	UpdateSegmentTree(mid + 1, end, node * 2 + 1, index, diff);
}

int main() {
	int n, x, y;
	scanf("%d %d %d", &n,&x,&y);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	MakeSegmentTree(0, n - 1, 1);
	int cnt = x + y;
	for (int i = 0; i < cnt; i++) {
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {
			UpdateSegmentTree(0, n - 1, 1, b - 1, c - arr[b - 1]);
			arr[b - 1] = c; // �迭 ��� ������Ʈ 
		}
		else {
			printf("%lld\n", sum(0, n - 1, 1, b - 1, c - 1)); // ������ ���
		}
	}

	return 0;
}
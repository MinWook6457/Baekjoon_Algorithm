// 부모노드번호 x 2 = 왼쪽자식노드번호, 부모노드번호 x 2 + 1 = 오른쪽자식노드번호
// 세그먼트 트리 이용하여 문제 해결
//      10		
//   3       7
//  1 2    3  4

/*
	크기가 N인 배열이 존재할 때

	1. 트리의 높이 = ceil(log2(N))

	2. 세그먼트 트리의 크기 = (1 << (트리의 높이 + 1) )

*/

// { 현재 노드 번호 , 시작 범위 , 마지막 범위 }
// 인덱스 1부터 사용

/*
1. 주어진 범위를 반으로 나눈다.

2. 나눠진 2개의 범위에 대해서 '왼쪽범위'에 대한 재귀호출을 한다.

3. 나눠진 2개의 범위에 대해서 '오른쪽범위'에 대한 재귀호출을 한다.

4. 위의 과정을 반복한다.
*/

#include <stdio.h>
#pragma warning(disable:4996)
typedef long long int ll; // long long 타입 정의
ll arr[1000000];
ll tree[4000000];

ll MakeSegmentTree(int start, int end, int node) { // 트리 생성
	if (start == end) // 재귀 종료 조건
		return tree[node]=arr[start];

	int mid = (start + end) / 2; // 중간값 설정
	tree[node] =  MakeSegmentTree(start, mid, node * 2) + MakeSegmentTree(mid + 1, end, node * 2 + 1); 
	// 왼쪽 트리 반환 값 + 오른쪽 트리 반환 값 저장
	return tree[node]; // 세그먼트 트리 반환
}

ll sum(int start, int end, int node, int left, int right) { // 구간합 함수
	if (start > right || end < left) // 탐색 범위가 완전히 벗어난 경우
		return 0;
	if (left <= start && end <= right) // 탐색 범위가 완전히 속한 경우
		return tree[node];

	/* 탐색 범위가 위 두 경우를 제외하고 일부만 걸치는 경우 */
	int mid = (start + end) / 2;
	 
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

ll UpdateSegmentTree(int start, int end, int node, int index, ll diff) {
	if (index < start || index > end) // 범위를 벗어난 경우
		return;

	tree[node] += diff; // 트리 노드 업데이트
	
	if (start == end) // 재귀 종료 조건
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
			arr[b - 1] = c; // 배열 요소 업데이트 
		}
		else {
			printf("%lld\n", sum(0, n - 1, 1, b - 1, c - 1)); // 구간합 출력
		}
	}

	return 0;
}
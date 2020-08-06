/*
트리 구조 : 그래프의 일종
1. 여러 노드가 하나의 노드를 가리킬 수 없는 구조
2. 회로가 없고, 서로 다른 두 노드를 잇는 길이 하나뿐인 그래프

<구성된 트리를 전위순회하고 방문한 노드의 번호 출력>
1. 첫 줄에는 전체 테스트 케이스의 수, 두 번째 줄에는 노드의 총 수, 간선의 총 수가 주어짐
2. 최대 노드의 개수는 10000개
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_NODE_NUM 10000
#define MAX_CHILD_NUM 2

typedef struct {
	int parent; // 부모 노드
	int child[MAX_CHILD_NUM]; // 자식 노드
}TreeNode;

TreeNode tree[MAX_NODE_NUM];

int nodeNum; // 노드 수
int edgeNum; // 간선 개수
int root; // 루트

// 구조체 배열 초기화
void initTree(void) {
	int i, j;
	for (i = 0; i <= nodeNum; i++) {
		tree[i].parent = -1; // 부모 노드 초기화
		for (j = 0; j < MAX_CHILD_NUM; j++) {
			tree[i].child[j] = -1; // 자식노드 초기화
		}
	}
}

// 트리에 값 대입
void addChild(int parent, int child) {
	int i;
	for (i = 0; i < MAX_CHILD_NUM; i++) {
		// 자식 노드가 존재하지 않는다면
		if (tree[parent].child[i] == -1) {
			break; // for문 탈출
		}
	}

	// 인자로 전달된 자식노드 번호는 tree 배열의 인덱스
	// 자식노드 번호에 해당하는 인덱스에 parent에 자식노드의 부모노드 번호를 기입
	// 부모노드 번호에 해당하는 인덱스에는 자식 노드의 번호들이 child[] 배열에 삽입된다.

	// 부모 노드를 인덱스로 자식노드 삽입
	tree[parent].child[i] = child;
	// 자식 노드를 인덱스로 부모노드 삽입
	tree[child].parent = parent;
}

int getRoot(void) {
	int i, j;

	for (i = 1; i <= nodeNum; i++) {
		if (tree[i].parent == -1) { // parent에 -1이 들어간 배열은 자식 노드의 정보만 담고있음
			return i; // 해당하는 인덱스 자체가 부모노드다.
		}
	}
	return -1;
}

void preOrder(int root) {
	int i;
	int child;

	printf("%d", root);

	for (i = 0; i < MAX_CHILD_NUM; i++) {
		child = tree[root].child[i]; // 부모 노드 번호인 root에 해당하는 자식 노드 번호 가져옴
		if (child != -1) { // 부모 노드 밑에 자식노드가 계속 존재한다면 깊이 탐색
			preOrder(child);
		}
	}
}

int main(void) {
	int test_case;
	int T;
	int i;
	int parent;
	int child;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case) {
		scanf("%d %d", &nodeNum, &edgeNum); // 노드 수, 간선 개수

		initTree(); // tree 배열 초기화

		for (i = 0; i < edgeNum; i++) {
			scanf("%d %d", &parent, &child);
			addChild(parent, child);
		}

		root = getRoot();

		printf("%d ", test_case);
		preOrder(root);
		printf("\n");
	}
	return 0;
}
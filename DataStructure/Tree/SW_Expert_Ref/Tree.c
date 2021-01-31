#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NODE 10000 // 노드 개수 지정
#define MAX_CHILD 2 // 하나의 노드가 가질 수 있는 자식 개수 지정, 이진 트리

// 노드 구조체 선언
typedef struct {
	int parent; // 현재 노드 기준, 부모 노드 번호를 저장하는 변수
	int child[MAX_CHILD]; // 현재 노드 기준, 자식 노드 번호를 저장하는 배열
}TreeNode;

TreeNode tree[MAX_NODE]; // 트리 노드 개수만큼 구조체 배열 선언
int nodeNum; // 전체 노드 개수
int edgeNum; // 전체 간선 개수
int root; // 루트 노드의 번호를 저장할 변수 

// 트리 초기화
void initTree() {
	printf("init tree\n");

	// 사용자가 입력한 노드 개수만큼 순회
	for (int i = 1; i <= nodeNum; i++) {
		tree[i].parent = -1; // 부모 노드가 없음을 -1로 표현
		for (int j = 0; j < MAX_CHILD; j++) {
			tree[i].child[j] = -1; // 자식 노드가 없음을 -1로 표현
		}
	}
}

// child를 parent 번호를 가진 노드에 삽입
void addChild(int parent, int child) {
	for (int i = 0; i < MAX_CHILD; i++) {
		// parent 번호를 가진 노드에 자식 노드 2개중 하나가 빈 공간이면
		if (tree[parent].child[i] == -1) {
			tree[parent].child[i] = child; // 부모 노드의 자식 지정
			tree[child].parent = parent; // 자식의 부모 노드 지정
			break;
		}
	}
}

// 루트 노드를 반환한다.
// 최상위 노드를 제외하고 모든 노드는 부모 노드 정보를 가지고 있다.
int getRoot() {
	for (int i = 1; i <= nodeNum; i++) {
		// 노드가 가진 자신의 부모에 대한 정보가 -1이라면 해당 노드는 최상위 노드다.
		if (tree[i].parent == -1)
			return i; // 자신의 인덱스를 반환 후 함수 종료
	}
	return -1; // 루트 노드가 없다면 -1 반환 후 함수 종료
}

// 전위 순회
// 자식 노드보다 루트 노드를 먼저 방문한다.
void preOrder(int root) {
	int child = 0;
	printf("%d ", root); // 루트 출력

	for (int i = 0; i < MAX_CHILD; i++) {
		// 루트의 자식 노드 2개를 순차적으로 child 변수에 삽입한다.
		child = tree[root].child[i]; 
		
		// 자식 노드가 존재하면
		if (child != -1) {
			// 자식 노드 번호를 통해 재귀 탐색
			preOrder(child);
		}
	}
}

// 중위 순회
void inOrder(int root) {
	int child = 0;

	child = tree[root].child[0];

	if (child != -1)
		inOrder(child);
	printf("%d ", root);

	child = tree[root].child[1];
	if (child != -1)
		inOrder(child);
}

// 후위 순회
void postOrder(int root) {
	int child = 0;

	for (int i = 0; i < MAX_CHILD; i++) {
		child = tree[root].child[i]; // 왼쪽 자식, 오른쪽 자식 노드 탐색

		// 자식 노드 존재 시
		if (child != -1) {
			postOrder(child); // 최하단 까지 내려감 
		}
	}
	printf("%d ", root);
}

int main() {
	int T = 0;
	int parent = 0, child = 0; // 사용자에게 입력 받을 부모, 자식 노드 변수

	for (scanf("%d", &T); T--;) {
		// 전체 노드 개수, 간선의 수를 입력 받는다.
		// 간선의 수 = 전체 노드 개수 - 1
		scanf("%d %d", &nodeNum, &edgeNum); 

		initTree();

		for (int i = 0; i < edgeNum; i++) {
			scanf("%d %d", &parent, &child); // 부모, 자식 노드 번호를 입력 받는다.
			addChild(parent, child); // 트리에 삽입
		}

		root = getRoot(); // 루트 노드의 번호를 반환받는다.
		preOrder(root); // 전위 순회
		printf("\n");

		root = getRoot();
		inOrder(root); // 중위 순회
		printf("\n");

		root = getRoot();
		postOrder(root); // 후위 순회
		printf("\n");
	}

	return 0;
}
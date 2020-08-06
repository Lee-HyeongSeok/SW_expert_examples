/*
Ʈ�� ���� : �׷����� ����
1. ���� ��尡 �ϳ��� ��带 ����ų �� ���� ����
2. ȸ�ΰ� ����, ���� �ٸ� �� ��带 �մ� ���� �ϳ����� �׷���

<������ Ʈ���� ������ȸ�ϰ� �湮�� ����� ��ȣ ���>
1. ù �ٿ��� ��ü �׽�Ʈ ���̽��� ��, �� ��° �ٿ��� ����� �� ��, ������ �� ���� �־���
2. �ִ� ����� ������ 10000��
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_NODE_NUM 10000
#define MAX_CHILD_NUM 2

typedef struct {
	int parent; // �θ� ���
	int child[MAX_CHILD_NUM]; // �ڽ� ���
}TreeNode;

TreeNode tree[MAX_NODE_NUM];

int nodeNum; // ��� ��
int edgeNum; // ���� ����
int root; // ��Ʈ

// ����ü �迭 �ʱ�ȭ
void initTree(void) {
	int i, j;
	for (i = 0; i <= nodeNum; i++) {
		tree[i].parent = -1; // �θ� ��� �ʱ�ȭ
		for (j = 0; j < MAX_CHILD_NUM; j++) {
			tree[i].child[j] = -1; // �ڽĳ�� �ʱ�ȭ
		}
	}
}

// Ʈ���� �� ����
void addChild(int parent, int child) {
	int i;
	for (i = 0; i < MAX_CHILD_NUM; i++) {
		// �ڽ� ��尡 �������� �ʴ´ٸ�
		if (tree[parent].child[i] == -1) {
			break; // for�� Ż��
		}
	}

	// ���ڷ� ���޵� �ڽĳ�� ��ȣ�� tree �迭�� �ε���
	// �ڽĳ�� ��ȣ�� �ش��ϴ� �ε����� parent�� �ڽĳ���� �θ��� ��ȣ�� ����
	// �θ��� ��ȣ�� �ش��ϴ� �ε������� �ڽ� ����� ��ȣ���� child[] �迭�� ���Եȴ�.

	// �θ� ��带 �ε����� �ڽĳ�� ����
	tree[parent].child[i] = child;
	// �ڽ� ��带 �ε����� �θ��� ����
	tree[child].parent = parent;
}

int getRoot(void) {
	int i, j;

	for (i = 1; i <= nodeNum; i++) {
		if (tree[i].parent == -1) { // parent�� -1�� �� �迭�� �ڽ� ����� ������ �������
			return i; // �ش��ϴ� �ε��� ��ü�� �θ����.
		}
	}
	return -1;
}

void preOrder(int root) {
	int i;
	int child;

	printf("%d", root);

	for (i = 0; i < MAX_CHILD_NUM; i++) {
		child = tree[root].child[i]; // �θ� ��� ��ȣ�� root�� �ش��ϴ� �ڽ� ��� ��ȣ ������
		if (child != -1) { // �θ� ��� �ؿ� �ڽĳ�尡 ��� �����Ѵٸ� ���� Ž��
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
		scanf("%d %d", &nodeNum, &edgeNum); // ��� ��, ���� ����

		initTree(); // tree �迭 �ʱ�ȭ

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
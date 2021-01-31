#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NODE 10000 // ��� ���� ����
#define MAX_CHILD 2 // �ϳ��� ��尡 ���� �� �ִ� �ڽ� ���� ����, ���� Ʈ��

// ��� ����ü ����
typedef struct {
	int parent; // ���� ��� ����, �θ� ��� ��ȣ�� �����ϴ� ����
	int child[MAX_CHILD]; // ���� ��� ����, �ڽ� ��� ��ȣ�� �����ϴ� �迭
}TreeNode;

TreeNode tree[MAX_NODE]; // Ʈ�� ��� ������ŭ ����ü �迭 ����
int nodeNum; // ��ü ��� ����
int edgeNum; // ��ü ���� ����
int root; // ��Ʈ ����� ��ȣ�� ������ ���� 

// Ʈ�� �ʱ�ȭ
void initTree() {
	printf("init tree\n");

	// ����ڰ� �Է��� ��� ������ŭ ��ȸ
	for (int i = 1; i <= nodeNum; i++) {
		tree[i].parent = -1; // �θ� ��尡 ������ -1�� ǥ��
		for (int j = 0; j < MAX_CHILD; j++) {
			tree[i].child[j] = -1; // �ڽ� ��尡 ������ -1�� ǥ��
		}
	}
}

// child�� parent ��ȣ�� ���� ��忡 ����
void addChild(int parent, int child) {
	for (int i = 0; i < MAX_CHILD; i++) {
		// parent ��ȣ�� ���� ��忡 �ڽ� ��� 2���� �ϳ��� �� �����̸�
		if (tree[parent].child[i] == -1) {
			tree[parent].child[i] = child; // �θ� ����� �ڽ� ����
			tree[child].parent = parent; // �ڽ��� �θ� ��� ����
			break;
		}
	}
}

// ��Ʈ ��带 ��ȯ�Ѵ�.
// �ֻ��� ��带 �����ϰ� ��� ���� �θ� ��� ������ ������ �ִ�.
int getRoot() {
	for (int i = 1; i <= nodeNum; i++) {
		// ��尡 ���� �ڽ��� �θ� ���� ������ -1�̶�� �ش� ���� �ֻ��� ����.
		if (tree[i].parent == -1)
			return i; // �ڽ��� �ε����� ��ȯ �� �Լ� ����
	}
	return -1; // ��Ʈ ��尡 ���ٸ� -1 ��ȯ �� �Լ� ����
}

// ���� ��ȸ
// �ڽ� ��庸�� ��Ʈ ��带 ���� �湮�Ѵ�.
void preOrder(int root) {
	int child = 0;
	printf("%d ", root); // ��Ʈ ���

	for (int i = 0; i < MAX_CHILD; i++) {
		// ��Ʈ�� �ڽ� ��� 2���� ���������� child ������ �����Ѵ�.
		child = tree[root].child[i]; 
		
		// �ڽ� ��尡 �����ϸ�
		if (child != -1) {
			// �ڽ� ��� ��ȣ�� ���� ��� Ž��
			preOrder(child);
		}
	}
}

// ���� ��ȸ
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

// ���� ��ȸ
void postOrder(int root) {
	int child = 0;

	for (int i = 0; i < MAX_CHILD; i++) {
		child = tree[root].child[i]; // ���� �ڽ�, ������ �ڽ� ��� Ž��

		// �ڽ� ��� ���� ��
		if (child != -1) {
			postOrder(child); // ���ϴ� ���� ������ 
		}
	}
	printf("%d ", root);
}

int main() {
	int T = 0;
	int parent = 0, child = 0; // ����ڿ��� �Է� ���� �θ�, �ڽ� ��� ����

	for (scanf("%d", &T); T--;) {
		// ��ü ��� ����, ������ ���� �Է� �޴´�.
		// ������ �� = ��ü ��� ���� - 1
		scanf("%d %d", &nodeNum, &edgeNum); 

		initTree();

		for (int i = 0; i < edgeNum; i++) {
			scanf("%d %d", &parent, &child); // �θ�, �ڽ� ��� ��ȣ�� �Է� �޴´�.
			addChild(parent, child); // Ʈ���� ����
		}

		root = getRoot(); // ��Ʈ ����� ��ȣ�� ��ȯ�޴´�.
		preOrder(root); // ���� ��ȸ
		printf("\n");

		root = getRoot();
		inOrder(root); // ���� ��ȸ
		printf("\n");

		root = getRoot();
		postOrder(root); // ���� ��ȸ
		printf("\n");
	}

	return 0;
}
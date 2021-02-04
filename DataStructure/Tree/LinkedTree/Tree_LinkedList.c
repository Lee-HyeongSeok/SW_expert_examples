#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

TreeNode * insertNode(TreeNode * root, int element) {
	TreeNode * cur = root;
	TreeNode * newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->data = element;
	newNode->left = NULL;
	newNode->right = NULL;

	while (1) {
		// ���ʿ� ����
		if (cur->data > element) {
			if (cur->left == NULL) {
				cur->left = newNode;
				printf("%d		", newNode->data);
				break;
			}
			else if (cur->left != NULL) {
				cur = cur->left;
			}
		}
		// �����ʿ� ���� 
		else if (cur->data < element) {
			if (cur->right == NULL) {
				cur->right = newNode;
				printf("		%d", newNode->data);
				break;
			}
			else if (cur->right != NULL) {
				cur = cur->right;
			}
		}
	}
	return root;
}

// Ʈ�� �� ���� ���� �˰���
void DeleteTree(TreeNode * root, int element) {
	// Ʈ���� �������� ���� ��� 
	if (!root) {
		printf("Ʈ���� �������� �ʴ´�.\n");
		return;
	}

	// Ʈ�� �� ���� ���� ��
	// �ش� ���Ҹ� ������ ��尡 �ܸ� ���, �ϳ��� ����Ʈ��, �ΰ��� ����Ʈ���� ��������
	// �Ǻ��ؾ� �Ѵ�.
	while (1) {
		// ���� ����� ��ġ�� �ش� �����Ͱ� ������ ���
		if (root->data == element) {

		}
		// ���� ����� ��ġ�� �ش� �����Ͱ� �������� ���� ���
		else {
			
		}
	}
}

void SearchNode(TreeNode * root, int data) {
	if (root == NULL) {
		printf("�ش� �����Ͱ� Ʈ���� �������� �ʴ´�.\n");
		return;
	}

	while (1) {
		if (root->data == data) {
			printf("current node value : %d\n", root->data); // ���� ����� �� ���
			if (root->left->data)
				printf("left child node value : %d\n", root->left->data); // ���� ����� ���� �ڽ� �� ���
			else
				printf("NULL\n");
			if (root->right->data)
				printf("right child node value : %d\n", root->right->data); // ���� ����� ������ �ڽ� �� ���
			else
				printf("NULL\n");
			break;
		}
		else {
			if (root->data > data) {// �θ� Ű������ ã������ ���� ���� ��� 
				SearchNode(root->left, data); // ���� �ڽ����� �̵�
			}
			else if (root->data < data) { // �θ� Ű������ ã������ ���� Ŭ ���
				SearchNode(root->right, data); // ������ �ڽ����� �̵�
			}
		}
		break;
	}
}

int main() {
	TreeNode * root = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = 5;
	root->left = NULL;
	root->right = NULL;
	printf("	%d		\n", root->data);

	root = insertNode(root, 2);
	root = insertNode(root, 6);
	printf("\n");
	root = insertNode(root, 1);
	printf("\n");
	root = insertNode(root, 3);
	printf("\n");

	printf("\n");

	SearchNode(root, 2);
}
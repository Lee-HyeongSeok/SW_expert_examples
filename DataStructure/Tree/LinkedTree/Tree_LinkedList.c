#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

TreeNode * maxNode(TreeNode * root) {
	for (TreeNode * cur = root; cur != NULL; cur = cur->right) {
		if (cur->right == NULL)
			return cur;
	}
	return root;
}

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
	TreeNode * cur = root; // Ž���� ���� ���
	TreeNode * removed; // ������ ���� �ӽ� ���
	TreeNode * temp;

	// Ʈ���� �������� ���� ��� 
	if (!root) {
		printf("Ʈ���� �������� �ʴ´�.\n");
		return;
	}

	// Ʈ�� �� ���� ���� ��
	// �ش� ���Ҹ� ������ ��尡 �ܸ� ���, �ϳ��� ����Ʈ��, �ΰ��� ����Ʈ���� ��������
	// �Ǻ��ؾ� �Ѵ�.
	while (1) {
		// ���� ��� ����, ���� ��� ���� ���� ��� ������ ������ ���� Ž��
		if (cur->data > element) {

			// ���� ��� ����
			// �� ��尡 ����Ű�� ���� �ڽ� ���� ���� ��� ���� ��ġ �ϴ� ���
			if (cur->left->data == element) {
				removed = cur->left;//���� ��� ���� �̵� 

				// ���� ��� ���(cur->left)�� ����, ������ �ڽ� �������� Ȯ��
				// ���� ��� ��尡 �ܸ� �����
				// ���� ��� ��带 ����
				if (cur->left->left == NULL && cur->left->right == NULL) {
					free(removed); // ���� ��� ����� removed�� �޸� ����
					cur->left = NULL; // �� ��� ����, ���� ����̿��� ���� �ڽ��� NULL�� ��ü
					break;
				}
				// ���� ��� ���(cur->left)�� ����, ������ ����Ʈ�� ���� Ȯ��
				// ���� ��� ��尡 ���� ����Ʈ���� ������ ���� ���
				else if (cur->left->left && cur->left->right == NULL) {
					temp = maxNode(cur->left->left);

				}
				// ���� ��� ���(cur->left)�� ����, ������ ����Ʈ�� ���� Ȯ��
				// ���� ��� ��尡 ������ ����Ʈ���� ������ ���� ���
				else if (cur->left->left == NULL && cur->left->right) {

				}
				// ���� ��� ��尡 ����, ������ �ΰ��� ����Ʈ���� ������ ���� ���
				else if (cur->left->left && cur->left->right) {

				}
			}
			// ���� ��� ����
			// �� ��尡 ����Ű�� ���� �ڽ� ���� ���� ��� ���� ����ġ �ϴ� ���
			// ������ ���� ��� ���� �� ��� ������ �����Ƿ�
			else if (cur->left->data != element) {
				cur = cur->left; // ����忡�� ���� �ڽ����� �̵� 
			}
		}
		// ���� ��� ����, ���� ��� ���� ���� ��� ������ ũ�� ������ Ž�� 
		else if (cur->data < element) {
			// ���� ��� ����
			// ���� ��尡 ����Ű�� ������ �ڽ� ���� ���� ��� ���� ��ġ �ϴ� ���
			if (cur->right->data == element) {
				removed = cur->right;//���� ��� ���� �̵� 

				// ���� ��� ���(cur->left)�� ����, ������ �ڽ� �������� Ȯ��
				// ���� ��� ��尡 �ܸ� �����
				// ���� ��� ��带 ����
				if (cur->right->left == NULL && cur->right->right == NULL) {
					free(removed); // ���� ��� ����� removed�� �޸� ����
					cur->left = NULL; // �� ��� ����, ���� ����̿��� ���� �ڽ��� NULL�� ��ü
					break;
				}
			}
			else if (cur->right->data != element) {
				cur = cur->right;
			}
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
			if (root->left != NULL)
				printf("left child node value : %d\n", root->left->data); // ���� ����� ���� �ڽ� �� ���
			else
				printf("NULL\n");
			if (root->right != NULL)
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

void preOrder(TreeNode * root) {
	printf("%d -> ", root->data);

	while (1) {
		if (root->left != NULL) {
			preOrder(root->left);
		}
		if (root->right != NULL) {
			preOrder(root->right);
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
	preOrder(root);

	SearchNode(root, 6);
	DeleteTree(root, 1); // 1���� 
	preOrder(root);

	
}
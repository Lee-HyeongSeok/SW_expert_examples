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
		// ¿ÞÂÊ¿¡ »ðÀÔ
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
		// ¿À¸¥ÂÊ¿¡ »ðÀÔ 
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

void preOrder(TreeNode * root) {
	TreeNode * cur;
	cur = root;
	printf("%d", cur->data);

	while (1) {
		cur = cur->left;

		if (cur != NULL) {
			preOrder(cur);
		}
		else {
			break;
		}

		cur = cur->right;

		if (cur != NULL) {
			preOrder(cur);
		}
		else {
			break;
		}
	}
}

int main() {
	TreeNode * root = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = 3;
	root->left = NULL;
	root->right = NULL;
	printf("	%d	\n", root->data);

	root = insertNode(root, 2);
	root = insertNode(root, 4);
	printf("\n");
	root = insertNode(root, 1);

	printf("\n");
	printf("\n");
	printf("\n");

	preOrder(root);
}
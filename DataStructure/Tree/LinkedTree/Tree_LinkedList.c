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
		// 왼쪽에 삽입
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
		// 오른쪽에 삽입 
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

// 트리 내 원소 삭제 알고리즘
void DeleteTree(TreeNode * root, int element) {
	// 트리가 존재하지 않을 경우 
	if (!root) {
		printf("트리가 존재하지 않는다.\n");
		return;
	}

	// 트리 내 원소 삭제 전
	// 해당 원소를 가지는 노드가 단말 노드, 하나의 서브트리, 두개의 서브트리를 가지는지
	// 판별해야 한다.
	while (1) {
		// 현재 노드의 위치에 해당 데이터가 존재할 경우
		if (root->data == element) {

		}
		// 현재 노드의 위치에 해당 데이터가 존재하지 않을 경우
		else {
			
		}
	}
}

void SearchNode(TreeNode * root, int data) {
	if (root == NULL) {
		printf("해당 데이터가 트리에 존재하지 않는다.\n");
		return;
	}

	while (1) {
		if (root->data == data) {
			printf("current node value : %d\n", root->data); // 현재 노드의 값 출력
			if (root->left->data)
				printf("left child node value : %d\n", root->left->data); // 현재 노드의 왼쪽 자식 값 출력
			else
				printf("NULL\n");
			if (root->right->data)
				printf("right child node value : %d\n", root->right->data); // 현재 노드의 오른쪽 자식 값 출력
			else
				printf("NULL\n");
			break;
		}
		else {
			if (root->data > data) {// 부모 키값보다 찾으려는 값이 작을 경우 
				SearchNode(root->left, data); // 왼쪽 자식으로 이동
			}
			else if (root->data < data) { // 부모 키값보다 찾으려는 값이 클 경우
				SearchNode(root->right, data); // 오른쪽 자식으로 이동
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
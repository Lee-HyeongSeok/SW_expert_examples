#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

// 가장 오른쪽 노드를 탐색해서 반환하는 함수
TreeNode * maxRightSearchingNode(TreeNode * root) {
	for (TreeNode * cur = root; cur != NULL; cur = cur->right) {
		if (cur->right == NULL && cur->left) // 최하위 단말노드일 때 반환
			return cur;
	}
	return root;
}
// 가장 왼쪽 노드를 탐색해서 반환하는 함수 
TreeNode * maxLeftSearchingNode(TreeNode * root) {
	for (TreeNode * cur = root; cur != NULL; cur = cur->left) {
		if (cur->left == NULL && cur->right) // 최하위 단말노드일 때 반환 
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
	TreeNode * cur = root; // 탐색을 위한 노드
	TreeNode * removed; // 삭제를 위한 임시 노드
	TreeNode * temp;

	// 트리가 존재하지 않을 경우 
	if (!root) {
		printf("트리가 존재하지 않는다.\n");
		return;
	}

	// 트리 내 원소 삭제 전
	// 해당 원소를 가지는 노드가 단말 노드, 하나의 서브트리, 두개의 서브트리를 가지는지
	// 판별해야 한다.
	while (1) {
		// 현재 노드 기준, 삭제 대상 값이 현재 노드 값보다 작으면 왼쪽 탐색
		if (cur->data > element) {

			// 현재 노드 기준
			// 현 노드가 가리키는 왼쪽 자식 값이 삭제 대상 값과 일치 하는 경우
			if (cur->left->data == element) {
				removed = cur->left;//삭제 대상 노드로 이동 

				// 삭제 대상 노드(cur->left)의 왼쪽, 오른쪽 자식 존재유무 확인
				// 삭제 대상 노드가 단말 노드라면
				// 삭제 대상 노드를 삭제
				if (cur->left->left == NULL && cur->left->right == NULL) {
					free(removed); // 삭제 대상 노드인 removed를 메모리 해제
					cur->left = NULL; // 현 노드 기준, 삭제 대상이였던 왼쪽 자식을 NULL로 교체
					break;
				}
				// 삭제 대상 노드(cur->left)의 왼쪽, 오른쪽 서브트리 유무 확인
				// 삭제 대상 노드가 왼쪽 서브트리만 가지고 있을 경우
				// 왼쪽 서브트리에서는 가장 오른쪽 최하단의 값으로 교체해야 함
				else if (cur->left->left && cur->left->right == NULL) {
					temp = maxRightSearchingNode(cur->left->left); // 왼쪽 서브트리에서 가장 큰 값을 가진 노드를 반환받는다.
					cur->left = temp; // 가장 큰 값을 가진 노드를 현재 노드에 왼쪽 자식으로 가리킨다.
					temp->left = removed->left; // 큰 값을 가진 노드의 왼쪽 자식을 삭제 대상 노드의 왼쪽 서브트리를 가리킨다.
					temp->right = removed->right; // 큰 값을 가진 노드의 오른쪽 자식을 삭제 대상 노드의 오른쪽 서브트리를 가리킨다.
					free(removed); // 삭제 대상 노드 메모리 해제
					free(temp);	// 큰 값을 가진 임시 노드 메모리 해제
					break;
				}
				// 삭제 대상 노드(cur->left)의 왼쪽, 오른쪽 서브트리 유무 확인
				// 삭제 대상 노드가 오른쪽 서브트리만 가지고 있을 경우
				// 오른쪽 서브트리에서는 가장 왼쪽 최하단의 값으로 교체해야 함
				else if (cur->left->left == NULL && cur->left->right) {
					temp = maxRightSearchingNode(cur->left->right); // 왼쪽 서브트리에서 가장 큰 값을 가진 노드를 반환받는다.
					cur->left = temp; // 가장 큰 값을 가진 노드를 현재 노드에 왼쪽 자식으로 가리킨다.
					temp->left = removed->left; // 큰 값을 가진 노드의 왼쪽 자식을 삭제 대상 노드의 왼쪽 서브트리를 가리킨다.
					temp->right = removed->right; // 큰 값을 가진 노드의 오른쪽 자식을 삭제 대상 노드의 오른쪽 서브트리를 가리킨다.
					free(removed); // 삭제 대상 노드 메모리 해제
					free(temp);	// 큰 값을 가진 임시 노드 메모리 해제
					break;
				}
				// 삭제 대상 노드가 왼쪽, 오른쪽 두개의 서브트리를 가지고 있을 경우
				else if (cur->left->left && cur->left->right) {
					temp = maxRightSearchingNode(cur->left->left); // 왼쪽 서브트리에서 가장 큰 값을 가진 노드를 반환받는다.
					cur->left = temp; // 가장 큰 값을 가진 노드를 현재 노드에 왼쪽 자식으로 가리킨다.
					temp->left = removed->left; // 큰 값을 가진 노드의 왼쪽 자식을 삭제 대상 노드의 왼쪽 서브트리를 가리킨다.
					temp->right = removed->right; // 큰 값을 가진 노드의 오른쪽 자식을 삭제 대상 노드의 오른쪽 서브트리를 가리킨다.
					free(removed); // 삭제 대상 노드 메모리 해제
					free(temp);	// 큰 값을 가진 임시 노드 메모리 해제
					break;
				}
			}
			// 현재 노드 기준
			// 현 노드가 가리키는 왼쪽 자식 값이 삭제 대상 값과 불일치 하는 경우
			// 위에서 삭제 대상 값이 현 노드 값보다 작으므로
			else if (cur->left->data != element) {
				cur = cur->left; // 현노드에서 왼쪽 자식으로 이동 
			}
		}
		// 현재 노드 기준, 삭제 대상 값이 현재 노드 값보다 크면 오른쪽 탐색 
		else if (cur->data < element) {
			// 현재 노드 기준
			// 현재 노드가 가리키는 오른쪽 자식 값이 삭제 대상 값과 일치 하는 경우
			if (cur->right->data == element) {
				removed = cur->right;//삭제 대상 노드로 이동 

				// 삭제 대상 노드(cur->left)의 왼쪽, 오른쪽 자식 존재유무 확인
				// 삭제 대상 노드가 단말 노드라면
				// 삭제 대상 노드를 삭제
				if (cur->right->left == NULL && cur->right->right == NULL) {
					free(removed); // 삭제 대상 노드인 removed를 메모리 해제
					cur->left = NULL; // 현 노드 기준, 삭제 대상이였던 왼쪽 자식을 NULL로 교체
					break;
				}
				// 삭제 대상 노드(cur->left)의 왼쪽, 오른쪽 서브트리 유무 확인
				// 삭제 대상 노드가 왼쪽 서브트리만 가지고 있을 경우
				// 왼쪽 서브트리에서는 가장 오른쪽 최하단의 값을 교체해야 함
				else if (cur->right->left && cur->right->right == NULL) {
					temp = maxLeftSearchingNode(cur->right->left); // 왼쪽 서브트리에서 가장 큰 값을 가진 노드를 반환받는다.
					cur->right = temp; // 가장 큰 값을 가진 노드를 현재 노드에 왼쪽 자식으로 가리킨다.
					temp->left = removed->left; // 큰 값을 가진 노드의 왼쪽 자식을 삭제 대상 노드의 왼쪽 서브트리를 가리킨다.
					temp->right = removed->right; // 큰 값을 가진 노드의 오른쪽 자식을 삭제 대상 노드의 오른쪽 서브트리를 가리킨다.
					free(removed); // 삭제 대상 노드 메모리 해제
					free(temp);	// 큰 값을 가진 임시 노드 메모리 해제
					break;
				}
				// 삭제 대상 노드(cur->left)의 왼쪽, 오른쪽 서브트리 유무 확인
				// 삭제 대상 노드가 오른쪽 서브트리만 가지고 있을 경우
				else if (cur->right->left == NULL && cur->right->right) {
					temp = maxLeftSearchingNode(cur->right->right); // 왼쪽 서브트리에서 가장 큰 값을 가진 노드를 반환받는다.
					cur->right = temp; // 가장 큰 값을 가진 노드를 현재 노드에 왼쪽 자식으로 가리킨다.
					temp->left = removed->left; // 큰 값을 가진 노드의 왼쪽 자식을 삭제 대상 노드의 왼쪽 서브트리를 가리킨다.
					temp->right = removed->right; // 큰 값을 가진 노드의 오른쪽 자식을 삭제 대상 노드의 오른쪽 서브트리를 가리킨다.
					free(removed); // 삭제 대상 노드 메모리 해제
					free(temp);	// 큰 값을 가진 임시 노드 메모리 해제
					break;
				}
				// 삭제 대상 노드가 왼쪽, 오른쪽 두개의 서브트리를 가지고 있을 경우
				else if (cur->right->left && cur->right->right) {
					temp = maxLeftSearchingNode(cur->right->right); // 왼쪽 서브트리에서 가장 큰 값을 가진 노드를 반환받는다.
					cur->right = temp; // 가장 큰 값을 가진 노드를 현재 노드에 왼쪽 자식으로 가리킨다.
					temp->left = removed->left; // 큰 값을 가진 노드의 왼쪽 자식을 삭제 대상 노드의 왼쪽 서브트리를 가리킨다.
					temp->right = removed->right; // 큰 값을 가진 노드의 오른쪽 자식을 삭제 대상 노드의 오른쪽 서브트리를 가리킨다.
					free(removed); // 삭제 대상 노드 메모리 해제
					free(temp);	// 큰 값을 가진 임시 노드 메모리 해제
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
		printf("해당 데이터가 트리에 존재하지 않는다.\n");
		return;
	}

	while (1) {
		if (root->data == data) {
			printf("current node value : %d\n", root->data); // 현재 노드의 값 출력
			if (root->left != NULL)
				printf("left child node value : %d\n", root->left->data); // 현재 노드의 왼쪽 자식 값 출력
			else
				printf("NULL\n");
			if (root->right != NULL)
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
	DeleteTree(root, 1); // 1삭제 
	preOrder(root);

	
}
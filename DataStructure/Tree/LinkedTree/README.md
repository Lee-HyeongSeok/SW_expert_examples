## **연결 리스트 완전 이진 탐색 트리**

***

### **⚙ 이진 탐색 트리(Binary Search Tree)**

- 이진 트리 탐색을 위한 자료구조
- 직접 구현한 코드에서는 5->2->6->1->3 순서로 삽입을 진행한다.

   ![1](https://user-images.githubusercontent.com/55940552/106847961-50959b00-66f3-11eb-9e02-0280710e0c09.png)

```c
int main() {
    // root 노드 동적 할당 시작
	TreeNode * root = (TreeNode*)malloc(sizeof(TreeNode));
    // root 노드의 데이터, 왼쪽/오른쪽 자식을 초기화 시켜준다.
	root->data = 5;
	root->left = NULL;
	root->right = NULL;
	printf("	%d		\n", root->data); // root 노드를 출력 후 삽입 시작 

    // root 노드를 기준으로 값을 삽입한다.
	root = insertNode(root, 2);
	root = insertNode(root, 6);
	printf("\n");
	root = insertNode(root, 1);
	printf("\n");
	root = insertNode(root, 3);
	printf("\n");

	printf("\n");

    // root 노드를 기준으로 2를 트리 내에서 찾는다.
    // 이진 탐색 트리의 탐색 알고리즘을 따른다.
	SearchNode(root, 2);
}
```







### **⚙ 이진 탐색 트리 특성**

1. 모든 노드의 키는 유일하다(중복 데이터 불허)
2. 전체 왼쪽 서브 트리의 키 값은 각 부모의 키 값보다 작아야 한다.
3. 전체 오른쪽 서브 트리의 키 값은 각 부모의 키 값보다 커야 한다.
4. 트리 내 모든 서브 트리는 이진 탐색 트리로 구성되어야 한다.



### **⚙ 이진 탐색 트리 삽입 알고리즘**

- 이진 탐색 트리를 탐색할 root 노드를 가리키는 cur 노드를 생성한다.
- element가 위치할 자리를 탐색 후 삽입할 새로운 노드인 newNode를 생성한다.
- newNode의 왼쪽, 오른쪽 자식을 가리키는 포인터를 NULL로 초기화 하고 데이터를 미리 삽입한다.
- 삽입하려는 데이터가 cur이 현재 가리키는 노드의 데이터보다 작은 경우
  - cur이 가리키는 왼쪽 자식이 **NULL인 경우**에 해당 위치에 새로운 노드 삽입
  - cur이 가리키는 왼쪽 자식이 **NULL이 아닌 경우**에 왼쪽 자식으로 탐색
- 삽입하려는 데이터가 cur이 현재 가리키는 노드의데이터보다 큰 경우
  - cur이 가리키는 오른쪽 자식이 **NULL인 경우**에 해당 위치에 새로운 노드 삽입
  - cur이 가리키는 오른쪽 자식이 **NULL이 아닌 경우**에 오른쪽 자식으로 탐색 

```c
TreeNode * insertNode(TreeNode * root, int element) {
	TreeNode * cur = root;
	TreeNode * newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->data = element;
	newNode->left = NULL;
	newNode->right = NULL;

	while (1) {
		// 왼쪽에 삽입
        // 이진 탐색 트리의 특성을 만족시키기 위한 조건문
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
        // 이진 탐색 트리의 특성을 만족시키기 위한 조건문
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
```



### **⚙ 이진 탐색 트리 탐색 알고리즘**

- 탐색하려는 **트리가 NULL인 경우** 트리 내 값이 존재하지 않음을 의미, 프로그램 종료
- 현재 노드의 데이터가 인자로 전달된 찾고자 하는 **데이터와 일치하는 경우**
  - 현재 노드의 값 출력
  - 현재 노드가 가리키는 왼쪽 자식의 값 출력
  - 현재 노드가 가리키는 오른쪽 자식의 값 출력 
- 현재 노드의 데이터가 인자로 전달된 찾고자 하는 **데이터와 일치하지 않는 경우**
  - 현재 노드의 데이터보다 찾고자 하는 **데이터가 작은 경우**
    - 왼쪽 노드로 이동 후 재귀 탐색
  - 현재 노드의 데이터보다 찾고자 하는 **데이터가 큰 경우**
    - 오른쪽 노드로 이동 후 재귀 탐색 

```c
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
```





### **⚙ 이진 탐색 트리 구현**

- **이진 탐색 트리 연산 알고리즘**
  - 삽입
  - 삭제
  - 탐색 -> 연산에 해당 안됨
- **이진 탐색 트리 삽입 알고리즘**
- **이진 탐색 트리 삭제 알고리즘**

![코드설명](https://user-images.githubusercontent.com/55940552/106874319-cb24e180-6718-11eb-919d-c450d45effc9.png)   



### **⚙ 이진 탐색 트리 연산 알고리즘**

- **삽입 연산**
  - root노드에서부터 시작
  - 모든 노드에 대해 키 값 비교가 이루어 지다가 NULL을 가리키는 단말 노드에 삽입된다.
  - 부모 노드의 키 값보다 삽입 데이터가 작으면 왼쪽 자식으로 삽입
  - 부모 노드의 키 값보다 삽입 데이터가 크면 오른쪽 자식으로 삽입
- **삭제 연산**
  - root 노드에서부터 시작
  - 모든 노드에 대한 키 값 비교를 통해 삭제 데이터의 위치를 알아낸다.
  - 삭제 시 고려 사항
    - **삭제하려는 대상 노드가 단말 노드(자식 노드가 없는 경우)를 확인한다.**
      - 삭제하려는 대상 노드를 삭제한다.
      - 삭제 대상 노드를 가리키던 부모 노드는 NULL을 가리킨다.
    - **삭제하려는 대상 노드가 왼쪽 서브 트리만 가지고 있는 경우**
      - 삭제하려는 대상 노드를 삭제한다.
      - 삭제 대상 노드를 가리키던 부모 노드는 NULL을 가리키게 한다.
    - **삭제하려는 대상 노드가 오른쪽 서브 트리만 가지고 있는 경우**
      - 삭제 대상 노드의 오른쪽 서브트리의 가장 왼쪽에 존재하는 노드를 삭제 대상 노드 자리로 옮긴다.
    - **삭제하려는 대상 노드가 왼쪽, 오른쪽 둘 다 가지고 있는 경우**
      - 삭제 대상 노드의 왼쪽 서브트리의 가장 오른쪽에 존재하는 노드를 삭제 대상 노드 자리로 옮긴다.
- **탐색 연산**
  - root 노드부터 시작
  - 탐색 시작 노드부터 출력
  - 탐색 노드에 왼쪽 자식이 존재하면 왼쪽 자식으로 재귀탐색
  - 탐색 노드에 오른쪽 자식이 존재하면 오른쪽 자식으로 재귀탐색
  - 탐색 노드와 해당 노드가 가진 왼쪽, 오른쪽 자식의 값을 출력해준다.
  - **PreOrder(전위 순회)** 방식으로 값을 탐색한다.



### **⚙ 이진 탐색 트리 삽입 알고리즘**

![삽입](https://user-images.githubusercontent.com/55940552/106896041-61b2cc00-6734-11eb-9d03-2244161368f2.png)      



```c
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
```





###  **⚙ 이진 탐색 트리 삭제 알고리즘**

![삭제연산](https://user-images.githubusercontent.com/55940552/106893627-2bc01880-6731-11eb-97c4-b05f84b33b48.png)   

![2](https://user-images.githubusercontent.com/55940552/106893632-2cf14580-6731-11eb-8495-659d02cea2d5.png)   



```c
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
```



### **이진 탐색 트리 탐색 알고리즘**

```c
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
```



***

**[출처]**

[황인띠기 티스토리](https://his130.tistory.com/369)

[wisecow 티스토리](https://mattlee.tistory.com/30)

[한국산업기술대학교](http://www.kpu.ac.kr/index.do?sso=ok)


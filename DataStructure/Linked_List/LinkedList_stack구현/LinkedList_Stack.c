#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

// 실직적인 스택 데이터를 가지는 노드
typedef struct ListNode {
	element data;
	struct ListNode * link;
}ListNode;

// 스택 데이터를 가지는 노드를 가리킬 구조체
typedef struct ListType {
	int size; // 현재 스택의 노드 개수를 가짐
	ListNode * head;
	ListNode * tail;
}ListType;

// 오류 처리 함수
void error(char * msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

ListType * create() {
	ListType * plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void Push(ListType * plist, element data) {
	ListNode * newNode = (ListNode*)malloc(sizeof(ListNode));

	if (newNode == NULL)
		error("메모리 할당 오류");

	newNode->data = data;
	newNode->link = NULL;

	// 초기에 실행되는 부분
	// 꼬리 포인터가 NULL일 경우 현재 스택에는 어떠한 데이터도 없음을 의미
	if (plist->tail == NULL) {
		plist->head = plist->tail = newNode; // 헤더와 꼬리가 새 노드를 가리킴
	}
	else {
		plist->tail->link = newNode;
		plist->tail = newNode;
	}
	plist->size++;
}

element Pop(ListType * plist) {
	plist->size--;
	element data = plist->tail->data;

	ListNode * cur = plist->head; // 순회 노드
	ListNode * removed = plist->tail; // 삭제 노드

	while (1) {
		// 현재 cur이 가리키는 다음 노드의 데이터가 삭제할 노드라면
		if (cur->link->data == data) {
			cur->link = NULL; // 현재 cur이 NULL을 가리키게 한다(현재 cur을 마지막 노드로)
			plist->tail = cur; // tail이 현재 cur을 가리키게 한다.
			free(removed); // 삭제 대상 노드 메모리를 해제한다.
			break;
		}
		// 현재 cur이 가리키는 다음 노드의 데이터가 삭제할 노드가 아니라면
		cur = cur->link; // 다음 노드로 이동
	}
	// 삭제한 데이터를 반환한다.
	return data;
}

void printStack(ListType * plist) {
	ListNode * cur = plist->head;

	for (; cur; cur = cur->link) {
		printf("%d ", cur->data);
	}
	printf("\n");
}

int main() {
	int T = 0;
	element data = 0;
	ListType * stack;

	stack = create();

	for (scanf("%d", &T); T--;) {
		// 사용자에게 스택에 삽입될 원소를 입력 받는다.
		while (1) {
			scanf("%d", &data);

			if (data == -1)
				break;
			Push(stack, data); // 데이터 삽입 
		}
		printStack(stack);
		printf("current stack size : %d\n", stack->size); 

		// 데이터 삭제
		data = Pop(stack);
		printf("\npop stack element : %d\n", data);
		printStack(stack);
		printf("current stack size : %d\n", stack->size);
	}
}
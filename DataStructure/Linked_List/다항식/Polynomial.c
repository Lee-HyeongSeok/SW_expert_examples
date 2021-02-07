#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef; // 계수 
	int expon; // 지수 
	struct ListNode * link; // 연결 링크 
}ListNode;

typedef struct ListType {
	int size;
	ListNode * head;
	ListNode * tail;
}ListType;

void error(char * msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

ListType * create(){
	ListType *plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

// 헤더를 가리키는 포인터, 계수, 지수
void insertNode(ListType * plist, int coef, int expon) {
	ListNode * newNode = (ListNode*)malloc(sizeof(ListNode));

	if (newNode == NULL)
		error("메모리 할당 에러");

	newNode->coef = coef;
	newNode->expon = expon;
	newNode->link = NULL;

	// 초기에 헤더 가리키는 포인터에 꼬리 부분이 NULL일 경우
	if (plist->tail == NULL) {
		plist->head = plist->tail = newNode;// 헤드와 테일이 새 노드를 가리키게 함
	}
	else {
		// plist가 가리키던 꼬리쪽 노드가 새 노드를 가리키게 한다.
		// 즉, 새로운 노드는 항상 뒷단에 위치시킨다.
		plist->tail->link = newNode;

		// 다음 새로운 노드를 위해 꼬리 헤더를 방금 들어온 노드로 옮긴다.
		plist->tail = newNode; 
	}
	plist->size++; // 노드 추가 시 사이즈 증가
}

void poly_add(ListType * plist1, ListType *plist2, ListType * plist3) {

}
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

// list3 = list1 + list2
void poly_add(ListType * plist1, ListType *plist2, ListType * plist3) {
	ListNode * a = plist1->head;
	ListNode * b = plist2->head;
	int sum = 0;
	
	while (a && b) {
		// a와 b의 지수가 같을 경우
		// 덧셈 수행
		if (a->expon == b->expon) {
			sum = a->coef + b->coef; // 각 계수를 더한다
			if (sum != 0) // 각 계수를 더한 값이 0이 아니라면
				insertNode(plist3, sum, a->expon); // plist3에 결과 삽입
			a = a->link;
			b = b->link;
		}
		// a의 지수가 b의 지수보다 클 경우
		else if (a->expon > b->expon) {
			// a의 정보만 plist3에 삽입된다.
			insertNode(plist3, a->coef, a->expon);
			a = a->link;
		}
		// a의 지수가 b의 지수보다 작을 경우
		else {
			// b의 정보만 plist3에 삽입된다.
			insertNode(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	// 나머지 남은 값들을 plist3에 삽입한다.
	for (; a != NULL; a = a->link)
		insertNode(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insertNode(plist3, b->coef, b->expon);
}

void printPolynomial(ListType * plist) {
	ListNode * cur = plist->head;

	for (; cur; cur = cur->link) {
		printf("%d^%d + ", cur->coef, cur->expon);
	}
	printf("\n");
}

int main() {
	ListType *list1, *list2, *list3;
	list1 = create();
	list2 = create();
	list3 = create();

	int T = 0;
	int coef, expon;

	// 테스트 케이스 만큼 다항식 하나를 입력 받는다.
	// plist1을 입력 받는다.
	for (scanf("%d", &T); T--;) {
		scanf("%d %d", &coef, &expon);

		insertNode(list1, coef, expon);
	}

	// 테스트 케이스 만큼 다항식 하나를 입력 받는다.
	// plist2를 입력 받는다.
	for (scanf("%d", &T); T--;) {
		scanf("%d %d", &coef, &expon);

		insertNode(list2, coef, expon);
	}

	printPolynomial(list1); // list1 출력
	printPolynomial(list2); // list2 출력

	poly_add(list1, list2, list3);// list3 = list1 + list2
	printPolynomial(list3); // 더한 결과 출력

	// 메모리 해제
	free(list1);
	free(list2);
	free(list3);
}
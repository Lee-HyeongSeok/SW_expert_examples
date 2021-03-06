/*
Linked List : 각 노드가 데이터와 포인터를 가지고 한 줄로 연결되어 있는 방식으로 데이터를 저장하는 자료구조

주어진 N(2 <= N <= 100) 개의 수를 순서대로 Linked List에 넣은 후 
2개의 간격으로 하나씩 데이터를 뺄 때 마지막에 남아 있는 데이터를 출력

Ex) 1 2 3 4 5 -> 2 3 4 5 -> 2 3 5 -> 2 5 -> 2

입력
2 // 테스트 케이스 수

5 // 입력 수
1 2 3 4 5 // 입력 데이터
6 // 입력 수
1 2 3 4 5 6
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_NODE 100

// 이중 연결 리스트 
typedef struct listNode {
	int data;
	struct listNode* prev; // listNode 구조체를 가리킬 수 있는 포인터, 이전 노드를 가리킴
	struct listNode* next; // listNode 구조체를 가리킬 수 있는 포인터, 다음 노드를 가리킴
}ListNode;

typedef struct {
	int use;
	ListNode node; // ListNode형 구조체를 저장하는 변수
}ListNodeHeap;

ListNodeHeap heap[MAX_NODE]; // 노드를 저장하는 힙 배열

void initHeap(void) {
	int i;
	for (i = 0; i < MAX_NODE; i++) {
		heap[i].use = 0; // ListNodeHeap 구조체의 use 변수를 초기화
	}
}

void initListNode(ListNode* node) {
	node->data = 0;
	// 이전, 다음 노드 포인터가 자신을 가리킴 
	node->prev = node; 
	node->next = node;
}

ListNode * getListNode(void) {
	int i;
	for (i = 0; i < MAX_NODE; i++) {
		if (!heap[i].use) { // heap[i].use가 0이라면
			heap[i].use = 1; // 1로 바꿔줌
			initListNode(&heap[i].node); // 노드 초기화
			return &heap[i].node; // 현재 노드 출력 
		}
	}
	return NULL; // 저장된 노드가 없다면 NULL 리턴
}

void destroyListNode(ListNode * node) {
	ListNodeHeap* heap_node = (ListNodeHeap*)((int*)node - 1); // 현재 노드의 이전 주소를 저장
	heap_node->use = 0;
}

// 노드의 뒤에 삽입
ListNode* appendListNode(ListNode* list, int data) {
	ListNode* node = getListNode(); // 헤더 노드를 저장
	node->data = data;

	if (list == NULL) {
		return node;
	}
	else {
		ListNode* last = list->prev; // list가 가리키는 이전노드를 가리킴
		last->next = node; // last의 다음 노드를 가리키는 포인터는 헤더 노드를 가리킴
		list->prev = node; // list의 이전 노드를 가리키는 포인터는 헤더 노드를 가리킴 
		node->prev = last; // 헤더 노드의 이전 노드를 가리키는 포인터는 last를 가리킴
		node->next = list; // 헤더 노드의 다음 노드를 가리키는 포인터는 list를 가리킴
		return list;
	}
}

ListNode* removeListNode(ListNode* list, ListNode* node) {
	if (list == list->next) { // list가 list가 가리키는 다음노드와 같을 때(마지막 노드일 때)
		destroyListNode(node);
		return NULL;
	}
	else {
		ListNode * prev = node->prev; // node가 가리키는 이전 노드를 가리킴
		ListNode * next = node->next; // node가 가리키는 다음 노드를 가리킴
		destroyListNode(node);
		return (list == node) ? next : list;
	}
}

int main(int argc, char * argv[]) {
	int T, N;
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case) {
		ListNode* list = NULL;
		ListNode* node;
		int i;

		initHeap();
		scanf("%d", &N);
		for (i = 0; i < N; i++) {
			int data;
			scanf("%d", &data);
			list = appendListNode(list, data); // 입력한 데이터를 리스트에 저장 
		}
		node = list;
		while (list != list->next) { // 리스트가 2개 이상일 때
			ListNode* nextNode = node->next; // 다음 노드를 가리킴 
			list = removeListNode(list, node); // 리스트 삭제
			node = nextNode->next->next; // 2개 간격으로 이동
		}
		printf("#%d %d\n", test_case, list->data);
	}
	return 0;
}
/*
Linked List : �� ��尡 �����Ϳ� �����͸� ������ �� �ٷ� ����Ǿ� �ִ� ������� �����͸� �����ϴ� �ڷᱸ��

�־��� N(2 <= N <= 100) ���� ���� ������� Linked List�� ���� �� 
2���� �������� �ϳ��� �����͸� �� �� �������� ���� �ִ� �����͸� ���

Ex) 1 2 3 4 5 -> 2 3 4 5 -> 2 3 5 -> 2 5 -> 2

�Է�
2 // �׽�Ʈ ���̽� ��

5 // �Է� ��
1 2 3 4 5 // �Է� ������
6 // �Է� ��
1 2 3 4 5 6
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_NODE 100

// ���� ���� ����Ʈ 
typedef struct listNode {
	int data;
	struct listNode* prev; // listNode ����ü�� ����ų �� �ִ� ������, ���� ��带 ����Ŵ
	struct listNode* next; // listNode ����ü�� ����ų �� �ִ� ������, ���� ��带 ����Ŵ
}ListNode;

typedef struct {
	int use;
	ListNode node; // ListNode�� ����ü�� �����ϴ� ����
}ListNodeHeap;

ListNodeHeap heap[MAX_NODE]; // ��带 �����ϴ� �� �迭

void initHeap(void) {
	int i;
	for (i = 0; i < MAX_NODE; i++) {
		heap[i].use = 0; // ListNodeHeap ����ü�� use ������ �ʱ�ȭ
	}
}

void initListNode(ListNode* node) {
	node->data = 0;
	// ����, ���� ��� �����Ͱ� �ڽ��� ����Ŵ 
	node->prev = node; 
	node->next = node;
}

ListNode * getListNode(void) {
	int i;
	for (i = 0; i < MAX_NODE; i++) {
		if (!heap[i].use) { // heap[i].use�� 0�̶��
			heap[i].use = 1; // 1�� �ٲ���
			initListNode(&heap[i].node); // ��� �ʱ�ȭ
			return &heap[i].node; // ���� ��� ��� 
		}
	}
	return NULL; // ����� ��尡 ���ٸ� NULL ����
}

void destroyListNode(ListNode * node) {
	ListNodeHeap* heap_node = (ListNodeHeap*)((int*)node - 1); // ���� ����� ���� �ּҸ� ����
	heap_node->use = 0;
}

// ����� �ڿ� ����
ListNode* appendListNode(ListNode* list, int data) {
	ListNode* node = getListNode(); // ��� ��带 ����
	node->data = data;

	if (list == NULL) {
		return node;
	}
	else {
		ListNode* last = list->prev; // list�� ����Ű�� ������带 ����Ŵ
		last->next = node; // last�� ���� ��带 ����Ű�� �����ʹ� ��� ��带 ����Ŵ
		list->prev = node; // list�� ���� ��带 ����Ű�� �����ʹ� ��� ��带 ����Ŵ 
		node->prev = last; // ��� ����� ���� ��带 ����Ű�� �����ʹ� last�� ����Ŵ
		node->next = list; // ��� ����� ���� ��带 ����Ű�� �����ʹ� list�� ����Ŵ
		return list;
	}
}

ListNode* removeListNode(ListNode* list, ListNode* node) {
	if (list == list->next) { // list�� list�� ����Ű�� �������� ���� ��(������ ����� ��)
		destroyListNode(node);
		return NULL;
	}
	else {
		ListNode * prev = node->prev; // node�� ����Ű�� ���� ��带 ����Ŵ
		ListNode * next = node->next; // node�� ����Ű�� ���� ��带 ����Ŵ
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
			list = appendListNode(list, data); // �Է��� �����͸� ����Ʈ�� ���� 
		}
		node = list;
		while (list != list->next) { // ����Ʈ�� 2�� �̻��� ��
			ListNode* nextNode = node->next; // ���� ��带 ����Ŵ 
			list = removeListNode(list, node); // ����Ʈ ����
			node = nextNode->next->next; // 2�� �������� �̵�
		}
		printf("#%d %d\n", test_case, list->data);
	}
	return 0;
}
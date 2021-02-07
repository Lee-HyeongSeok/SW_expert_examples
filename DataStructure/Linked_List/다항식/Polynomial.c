#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef; // ��� 
	int expon; // ���� 
	struct ListNode * link; // ���� ��ũ 
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

// ����� ����Ű�� ������, ���, ����
void insertNode(ListType * plist, int coef, int expon) {
	ListNode * newNode = (ListNode*)malloc(sizeof(ListNode));

	if (newNode == NULL)
		error("�޸� �Ҵ� ����");

	newNode->coef = coef;
	newNode->expon = expon;
	newNode->link = NULL;

	// �ʱ⿡ ��� ����Ű�� �����Ϳ� ���� �κ��� NULL�� ���
	if (plist->tail == NULL) {
		plist->head = plist->tail = newNode;// ���� ������ �� ��带 ����Ű�� ��
	}
	else {
		// plist�� ����Ű�� ������ ��尡 �� ��带 ����Ű�� �Ѵ�.
		// ��, ���ο� ���� �׻� �޴ܿ� ��ġ��Ų��.
		plist->tail->link = newNode;

		// ���� ���ο� ��带 ���� ���� ����� ��� ���� ���� �ű��.
		plist->tail = newNode; 
	}
	plist->size++; // ��� �߰� �� ������ ����
}

void poly_add(ListType * plist1, ListType *plist2, ListType * plist3) {

}
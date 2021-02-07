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

// list3 = list1 + list2
void poly_add(ListType * plist1, ListType *plist2, ListType * plist3) {
	ListNode * a = plist1->head;
	ListNode * b = plist2->head;
	int sum = 0;
	
	while (a && b) {
		// a�� b�� ������ ���� ���
		// ���� ����
		if (a->expon == b->expon) {
			sum = a->coef + b->coef; // �� ����� ���Ѵ�
			if (sum != 0) // �� ����� ���� ���� 0�� �ƴ϶��
				insertNode(plist3, sum, a->expon); // plist3�� ��� ����
			a = a->link;
			b = b->link;
		}
		// a�� ������ b�� �������� Ŭ ���
		else if (a->expon > b->expon) {
			// a�� ������ plist3�� ���Եȴ�.
			insertNode(plist3, a->coef, a->expon);
			a = a->link;
		}
		// a�� ������ b�� �������� ���� ���
		else {
			// b�� ������ plist3�� ���Եȴ�.
			insertNode(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	// ������ ���� ������ plist3�� �����Ѵ�.
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

	// �׽�Ʈ ���̽� ��ŭ ���׽� �ϳ��� �Է� �޴´�.
	// plist1�� �Է� �޴´�.
	for (scanf("%d", &T); T--;) {
		scanf("%d %d", &coef, &expon);

		insertNode(list1, coef, expon);
	}

	// �׽�Ʈ ���̽� ��ŭ ���׽� �ϳ��� �Է� �޴´�.
	// plist2�� �Է� �޴´�.
	for (scanf("%d", &T); T--;) {
		scanf("%d %d", &coef, &expon);

		insertNode(list2, coef, expon);
	}

	printPolynomial(list1); // list1 ���
	printPolynomial(list2); // list2 ���

	poly_add(list1, list2, list3);// list3 = list1 + list2
	printPolynomial(list3); // ���� ��� ���

	// �޸� ����
	free(list1);
	free(list2);
	free(list3);
}
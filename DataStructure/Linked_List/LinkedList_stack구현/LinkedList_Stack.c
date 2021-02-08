#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

// �������� ���� �����͸� ������ ���
typedef struct ListNode {
	element data;
	struct ListNode * link;
}ListNode;

// ���� �����͸� ������ ��带 ����ų ����ü
typedef struct ListType {
	int size; // ���� ������ ��� ������ ����
	ListNode * head;
	ListNode * tail;
}ListType;

// ���� ó�� �Լ�
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
		error("�޸� �Ҵ� ����");

	newNode->data = data;
	newNode->link = NULL;

	// �ʱ⿡ ����Ǵ� �κ�
	// ���� �����Ͱ� NULL�� ��� ���� ���ÿ��� ��� �����͵� ������ �ǹ�
	if (plist->tail == NULL) {
		plist->head = plist->tail = newNode; // ����� ������ �� ��带 ����Ŵ
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

	ListNode * cur = plist->head; // ��ȸ ���
	ListNode * removed = plist->tail; // ���� ���

	while (1) {
		// ���� cur�� ����Ű�� ���� ����� �����Ͱ� ������ �����
		if (cur->link->data == data) {
			cur->link = NULL; // ���� cur�� NULL�� ����Ű�� �Ѵ�(���� cur�� ������ ����)
			plist->tail = cur; // tail�� ���� cur�� ����Ű�� �Ѵ�.
			free(removed); // ���� ��� ��� �޸𸮸� �����Ѵ�.
			break;
		}
		// ���� cur�� ����Ű�� ���� ����� �����Ͱ� ������ ��尡 �ƴ϶��
		cur = cur->link; // ���� ���� �̵�
	}
	// ������ �����͸� ��ȯ�Ѵ�.
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
		// ����ڿ��� ���ÿ� ���Ե� ���Ҹ� �Է� �޴´�.
		while (1) {
			scanf("%d", &data);

			if (data == -1)
				break;
			Push(stack, data); // ������ ���� 
		}
		printStack(stack);
		printf("current stack size : %d\n", stack->size); 

		// ������ ����
		data = Pop(stack);
		printf("\npop stack element : %d\n", data);
		printStack(stack);
		printf("current stack size : %d\n", stack->size);
	}
}
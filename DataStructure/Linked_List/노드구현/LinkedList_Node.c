#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct {
	element data; // �����͸� ������ ����
	struct ListNode * link; // ���� ��带 ������ ������
}ListNode;

// ��带 �����԰� ���ÿ� head�� ���� �����ִ� �Լ�
ListNode * insertNode(ListNode * head, element value) {
	ListNode * newNode = (ListNode*)malloc(sizeof(ListNode)); // ���ο� ��� ����
	newNode->data = value; // ���ο� ��忡 ������ ����

	newNode->link = head; // ���� ������ ��尡 ���ڷ� ���޵� head�� ����Ű�� ��
	head = newNode; // head�� ���� ������ ��带 ������
	return head;
}

// pre ��尡 ����Ű�� ���� ��带 ����
ListNode * deleteNode(ListNode * head, ListNode *pre) {
	ListNode * removed;
	removed = pre->link; // pre�� ����Ű�� ���� ��带 �ӽ� ����
	pre->link = removed->link; // removed�� ����Ű�� ���� ��带 �ӽ� ����
	free(removed); // ������ ��� �޸� ����
	return head;
}

void printList(ListNode * head) {
	for (ListNode * cur = head; cur != NULL; cur = cur->link) {
		printf("%d -> ", cur->data);
	}
	printf("NULL \n");
}

int main() {
	ListNode * head = NULL; // ���ο� ��� ����
	int T = 0;
	element item = 0; // ����ڿ��� �Է� ���� ������ ����
	int cnt = 0;

	for (scanf("%d", &T); T--;) {
		while (1) {
			scanf("%d", &item);

			if (item == -1)
				break;

			head = insertNode(head, item); // ������ ����
			cnt++;
		}
		printList(head); // ���� ����Ʈ ��� ��� 

		while (cnt) {
			head = deleteNode(head); // �����ߴ� ������ ��� ����
			cnt--;
		}
	}
	return 0;
}

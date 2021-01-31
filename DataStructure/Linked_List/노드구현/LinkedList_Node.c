#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct {
	element data; // 데이터를 저장할 변수
	struct ListNode * link; // 다음 노드를 저장할 포인터
}ListNode;

// 노드를 생성함과 동시에 head와 연결 시켜주는 함수
ListNode * insertNode(ListNode * head, element value) {
	ListNode * newNode = (ListNode*)malloc(sizeof(ListNode)); // 새로운 노드 생성
	newNode->data = value; // 새로운 노드에 데이터 삽입

	newNode->link = head; // 새로 생성한 노드가 인자로 전달된 head를 가리키게 함
	head = newNode; // head에 새로 생성한 노드를 복사함
	return head;
}

// pre 노드가 가리키는 다음 노드를 삭제
ListNode * deleteNode(ListNode * head, ListNode *pre) {
	ListNode * removed;
	removed = pre->link; // pre가 가리키는 다음 노드를 임시 저장
	pre->link = removed->link; // removed가 가리키는 다음 노드를 임시 저장
	free(removed); // 삭제할 노드 메모리 해제
	return head;
}

void printList(ListNode * head) {
	for (ListNode * cur = head; cur != NULL; cur = cur->link) {
		printf("%d -> ", cur->data);
	}
	printf("NULL \n");
}

int main() {
	ListNode * head = NULL; // 새로운 노드 생성
	int T = 0;
	element item = 0; // 사용자에게 입력 받을 데이터 변수
	int cnt = 0;

	for (scanf("%d", &T); T--;) {
		while (1) {
			scanf("%d", &item);

			if (item == -1)
				break;

			head = insertNode(head, item); // 데이터 삽입
			cnt++;
		}
		printList(head); // 현재 리스트 모두 출력 

		while (cnt) {
			head = deleteNode(head); // 삽입했던 데이터 모두 삭제
			cnt--;
		}
	}
	return 0;
}

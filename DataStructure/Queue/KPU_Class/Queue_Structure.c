#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 // 최대 큐 사이즈

typedef int element;

// front, rear, 1차원 배열을 갖는 구조체 선언
typedef struct {
	int front;
	int rear;
	element data[MAX];
}QueueType;

void error(char *msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

// 큐를 초기화 하는 함수
void init_queue(QueueType * q) {
	q->rear = -1;
	q->front = -1;
}

void printQueueElement(QueueType * q) {
	for (int i = 0; i < MAX; i++) {
		// i가 큐 원소가 존재하는 범위 내에 없을 경우
		if (i <= q->front || i >= q->rear) {
			printf(" | "); // 공백 출력
		}
		// i가 큐 원소가 존재하는 범위 내에 있을 경우
		else {
			printf("%d | ", q->data[i]); // 원소 출력
		}
	}
	printf("\n");
}

// 큐의 포화 상태 검출 
bool is_full(QueueType * q) {
	// 큐 뒷단의 인덱스를 나타내는 변수가 원소의 최대 개수와 같을 경우
	// 포화 상태임을 나타낸다.
	if (q->rear == MAX - 1)
		return true;
	

	return false;
}

// 큐의 공백 상태 검출 
bool is_empty(QueueType * q) {
	// 큐 앞단과 뒷단의 원소를 가리키는 변수가 서로 같을 때
	// 큐에 어떠한 원소도 존재하지 않는다는 의미
	if (q->front == q->rear)
		return true;
	return false;
}

void Enqueue(QueueType * q, int item) {
	// 큐가 포화 상태일 경우 함수 종료
	if (is_full(q)) {
		error("큐가 포화상태 입니다.");
		return;
	}

	// 포화 상태가 아닐 경우 데이터 삽입 
	q->data[++(q->rear)] = item;
}

element Dequeue(QueueType * q) {
	if (is_empty(q)) {
		error("큐가 공백 상태입니다.");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}

int main() {
	int T = 0; // 테스트 케이스를 입력 받기 위함
	element data = 0; // 큐에 삽입될 데이터를 입력 받기 위한 변수
	QueueType q;
	int N = 0; // 몇 개의 데이터를 입력할 것인지

	// 입력 받은 테스트 케이스 만큼 순회
	for (scanf("%d", &T); T--;) {
		init_queue(&q); // 큐 초기화

		scanf("%d", &N); // 입력 받을 데이터 개수 

		while (N--) {
			scanf("%d", &data);

			Enqueue(&q, data);
		}
		printQueueElement(&q); // 전체 큐 출력 

		// 큐의 최대 원소 개수만큼 순회
		for (int i = 0; i < MAX; i++) {
			data = Dequeue(&q); // 원소를 하나씩 삭제
			printQueueElement(&q); // 삭제된 큐의 상태를 확인
		}
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 // 큐의 최대 사이즈 지정

typedef int element;
typedef struct {
	element data[MAX];
	int front, rear;
}QueueType;

// 오류 처리 함수
void error(char *msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

// 큐 초기화 함수
void init_queue(QueueType * q) {
	q->front = q->rear = 0; // 0으로 초기화
}

// 공백 상태 검출 함수
bool is_empty(QueueType * q) {
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
bool is_full(QueueType * q) {
	// 가장 뒷단의 인덱스 + 1은 MAX 값을 나타낸다.
	// rear+1을 MAX로 나눴을 때 0으로 떨어진다면 포화 상태임을 의미
	// front와 바로 붙어있다는 뜻
	return ((q->rear + 1) % MAX == q->front);
}

// 원형 큐 출력 함수
void printQueueElement(QueueType * q) {
	printf("Queue(front=%d, rear=%d)", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			// i가 rear에 도달하지 않을 때
			i = (i + 1) % (MAX);
			printf("%d ", q->data[i]);

			// i가 rear에 도달하면
			if (i == q->rear)
				break; // 반복문 정지
		} while (i != q->front); // i가 front가 아닐 경우 반복
	}
	printf("\n");
}

void Enqueue(QueueType * q, element item) {
	if (is_full(q))
		error("큐가 포화 상태 입니다.");
	q->rear = (q->rear + 1) % MAX; // 한 사이클 순회 시 다시 기본 값인 0으로 돌아간다.
	q->data[q->rear] = item;
}

element Dequeue(QueueType * q) {
	if (is_empty(q))
		error("큐가 공백 상태 입니다.");
	q->front = (q->front + 1) % MAX; // 한 사이클 순회 시 다시 기본 값인 0으로 돌아간다.
	return q->data[q->front]; // 가장 앞에 있는 데이터를 반환 
}

int main() {
	int T = 0;
	element data = 0;
	QueueType q;

	for (scanf("%d", &T); T--;) {
		init_queue(&q); // 초기화

		// 큐가 포화 상태가 될때 까지 입력 받는다.
		while (!is_full(&q)) {
			scanf("%d", &data);
			Enqueue(&q, data);
			printQueueElement(&q);
		}

		// 큐가 공백 상태가 될때 까지 삭제 한다.
		while (!is_empty(&q)) {
			data = Dequeue(&q);
			printf("삭제된 원소 : %d", data);
			printQueueElement(&q);
		}
	}

	return 0;
}
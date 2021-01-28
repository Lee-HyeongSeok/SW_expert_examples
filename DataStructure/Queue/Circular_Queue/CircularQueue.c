#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 // ť�� �ִ� ������ ����

typedef int element;
typedef struct {
	element data[MAX];
	int front, rear;
}QueueType;

// ���� ó�� �Լ�
void error(char *msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

// ť �ʱ�ȭ �Լ�
void init_queue(QueueType * q) {
	q->front = q->rear = 0; // 0���� �ʱ�ȭ
}

// ���� ���� ���� �Լ�
bool is_empty(QueueType * q) {
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
bool is_full(QueueType * q) {
	// ���� �޴��� �ε��� + 1�� MAX ���� ��Ÿ����.
	// rear+1�� MAX�� ������ �� 0���� �������ٸ� ��ȭ �������� �ǹ�
	// front�� �ٷ� �پ��ִٴ� ��
	return ((q->rear + 1) % MAX == q->front);
}

// ���� ť ��� �Լ�
void printQueueElement(QueueType * q) {
	printf("Queue(front=%d, rear=%d)", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			// i�� rear�� �������� ���� ��
			i = (i + 1) % (MAX);
			printf("%d ", q->data[i]);

			// i�� rear�� �����ϸ�
			if (i == q->rear)
				break; // �ݺ��� ����
		} while (i != q->front); // i�� front�� �ƴ� ��� �ݺ�
	}
	printf("\n");
}

void Enqueue(QueueType * q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ ���� �Դϴ�.");
	q->rear = (q->rear + 1) % MAX; // �� ����Ŭ ��ȸ �� �ٽ� �⺻ ���� 0���� ���ư���.
	q->data[q->rear] = item;
}

element Dequeue(QueueType * q) {
	if (is_empty(q))
		error("ť�� ���� ���� �Դϴ�.");
	q->front = (q->front + 1) % MAX; // �� ����Ŭ ��ȸ �� �ٽ� �⺻ ���� 0���� ���ư���.
	return q->data[q->front]; // ���� �տ� �ִ� �����͸� ��ȯ 
}

int main() {
	int T = 0;
	element data = 0;
	QueueType q;

	for (scanf("%d", &T); T--;) {
		init_queue(&q); // �ʱ�ȭ

		// ť�� ��ȭ ���°� �ɶ� ���� �Է� �޴´�.
		while (!is_full(&q)) {
			scanf("%d", &data);
			Enqueue(&q, data);
			printQueueElement(&q);
		}

		// ť�� ���� ���°� �ɶ� ���� ���� �Ѵ�.
		while (!is_empty(&q)) {
			data = Dequeue(&q);
			printf("������ ���� : %d", data);
			printQueueElement(&q);
		}
	}

	return 0;
}
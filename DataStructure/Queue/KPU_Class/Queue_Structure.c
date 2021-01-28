#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 // �ִ� ť ������

typedef int element;

// front, rear, 1���� �迭�� ���� ����ü ����
typedef struct {
	int front;
	int rear;
	element data[MAX];
}QueueType;

void error(char *msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

// ť�� �ʱ�ȭ �ϴ� �Լ�
void init_queue(QueueType * q) {
	q->rear = -1;
	q->front = -1;
}

void printQueueElement(QueueType * q) {
	for (int i = 0; i < MAX; i++) {
		// i�� ť ���Ұ� �����ϴ� ���� ���� ���� ���
		if (i <= q->front || i >= q->rear) {
			printf(" | "); // ���� ���
		}
		// i�� ť ���Ұ� �����ϴ� ���� ���� ���� ���
		else {
			printf("%d | ", q->data[i]); // ���� ���
		}
	}
	printf("\n");
}

// ť�� ��ȭ ���� ���� 
bool is_full(QueueType * q) {
	// ť �޴��� �ε����� ��Ÿ���� ������ ������ �ִ� ������ ���� ���
	// ��ȭ �������� ��Ÿ����.
	if (q->rear == MAX - 1)
		return true;
	

	return false;
}

// ť�� ���� ���� ���� 
bool is_empty(QueueType * q) {
	// ť �մܰ� �޴��� ���Ҹ� ����Ű�� ������ ���� ���� ��
	// ť�� ��� ���ҵ� �������� �ʴ´ٴ� �ǹ�
	if (q->front == q->rear)
		return true;
	return false;
}

void Enqueue(QueueType * q, int item) {
	// ť�� ��ȭ ������ ��� �Լ� ����
	if (is_full(q)) {
		error("ť�� ��ȭ���� �Դϴ�.");
		return;
	}

	// ��ȭ ���°� �ƴ� ��� ������ ���� 
	q->data[++(q->rear)] = item;
}

element Dequeue(QueueType * q) {
	if (is_empty(q)) {
		error("ť�� ���� �����Դϴ�.");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}

int main() {
	int T = 0; // �׽�Ʈ ���̽��� �Է� �ޱ� ����
	element data = 0; // ť�� ���Ե� �����͸� �Է� �ޱ� ���� ����
	QueueType q;
	int N = 0; // �� ���� �����͸� �Է��� ������

	// �Է� ���� �׽�Ʈ ���̽� ��ŭ ��ȸ
	for (scanf("%d", &T); T--;) {
		init_queue(&q); // ť �ʱ�ȭ

		scanf("%d", &N); // �Է� ���� ������ ���� 

		while (N--) {
			scanf("%d", &data);

			Enqueue(&q, data);
		}
		printQueueElement(&q); // ��ü ť ��� 

		// ť�� �ִ� ���� ������ŭ ��ȸ
		for (int i = 0; i < MAX; i++) {
			data = Dequeue(&q); // ���Ҹ� �ϳ��� ����
			printQueueElement(&q); // ������ ť�� ���¸� Ȯ��
		}
	}
	return 0;
}
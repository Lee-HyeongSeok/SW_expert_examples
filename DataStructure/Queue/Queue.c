#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 100 // ť �ִ� ũ�� ����

int front; // ť�� ���� ���� �ε����� ����Ű�� ����
int rear; // ť�� ���� ������ �ε����� ����Ű�� ����
int queue[MAX]; // �ڷḦ ������ ť, 1���� �迭 ����

void QueueInit() {
	front = 0;
	rear = 0;
}

// ť�� ���� ���� ���� �Լ�
int QueueEmpty() {
	// �մ��� �ε����� �޴��� �ε����� ������ ť�� ���Ե� �ڷᰡ ���ٴ� �ǹ�
	return (front == rear);
}

// ť�� ��ȭ ���¸� �����ϴ� �Լ�
int QueueFull() {
	// �޴��� �ε��� + 1�� MAX�� �������� �� �������� ���� �մ��� �ε������
	// ť�� ��ȭ �������� �ǹ�
	if ((rear + 1) % MAX == front) {
		return 1;
	}
	return 0;
}

// ť�� �����͸� �����ϴ� �Լ�
int QueueEnQueue(int value) {
	// ť�� ��ȭ���¶��
	if (QueueFull()) {
		printf("Queue is full!");
		return 0; // 0 ���� �� �Լ� ����
	}

	// ��ȭ ���°� �ƴ϶��
	// ť�� �޴ܿ� ���� �����ϰ�
	queue[rear] = value;
	rear++; // �޴��� �ε����� ��Ÿ���� ������ ���� �����ش�.

	// ������ �޴� �ε����� �ǹ��ϴ� ������ ť�� �ִ���ҿ� ������
	if (rear == MAX)
		rear = 0; // �޴��� �ε��� ������ 0���� �ʱ�ȭ(���� ť)

	return 1; // ������ �Ϸ�� ���¶�� 1�� ���� 
}

// ť�� �����͸� �����ϴ� �Լ�
int queueDequeue(int *value) {
	// ť�� ���� ���¶��
	if (QueueEmpty()) {
		printf("Queue is Empty!");
		return 0;
	}

	// ť�� ���� �մܿ� �ִ� �����͸� value�� ����
	*value = queue[front];
	front++; // front ����

	// ������ ���� �� : 0, 1, 2... �ε����� ����
	// ������ ���� �� : 3, 4, 5... �ε����� �����͵��� ����
	// FIFO ������� ���� �������� �����Ͱ� ���� ���� �����ٴ� ���

	// ���� �������� �����͸� ��Ÿ���� front�� �ִ� ���� ������ �������ٸ�
	if (front == MAX) {
		front = 0; // 0���� �ʱ�ȭ
	}
	return 1;
}

int main() {
	int T = 0; // �׽�Ʈ ���̽� ����
	int N = 0; // �Է¹��� ������ ����
	int data = 0; // ť�� ������ ������

	for (scanf("%d", &T); T--;) {
		scanf("%d", &N); // �Է� ���� ������ ������ �Է� �޴´�.

		QueueInit();
		for (int i = 0; i < N; i++) {
			scanf("%d", &data); // ����ڿ��� �����͸� �Է� �޴´�.
			QueueEnQueue(data); // ť�� ������ ����
		}

		// ť�� ��������� �� ���� ��ȸ
		while (!QueueEmpty()) {
			int value;
			if (queueDequeue(&value) == 1) {
				printf("%d ", value);
			}
		}
		printf("\n");
	}
	return 0;
}

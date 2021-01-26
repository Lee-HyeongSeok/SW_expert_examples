#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // ������ �ִ� ũ�� ����

typedef int element; // ������ �ڷ��� ����
element stack[MAX]; // 1���� �迭
int top = -1;

// ���� �ʱ�ȭ �Լ�
void init() {
	for (int i = 0; i < MAX; i++) {
		stack[i] = 0;
	}
	top = -1;
}

// ���� ������� ���� �Լ�
int is_Empty() {
	return (top == -1);
}

// ���� ��ȭ���� ���� �Լ�
int is_full() {
	// ���� �ֱٿ� ���� ���� �ε����� �����ϴ� top�� �ִ�ũ��-1�� ������
	// ���ÿ� �ִ� ũ�⸸ŭ �ε����� �����ߴٴ� �ǹ�
	return (top == (MAX - 1)); 
}

// ���ÿ� �����͸� �����ϴ� �Լ�
void push(element item) {
	// ������ ��ȭ���¶��
	if (is_full()) {
		printf("���� ��ȭ ����\n");
		return; // �Լ� ����
	}
	else
		stack[++top] = item; // top�� -1�� �����ϹǷ� �������� �� ������ ����
}

// ���ÿ� �����͸� �����ϴ� �Լ�
element pop() {
	// ������ ������¶��
	if (is_Empty()) {
		printf("���� ���� ����\n");
		exit(1); // ���α׷� ����
	}
	else
		return stack[top--]; // �ֻ��� ���� ���� �� top ������ ��������
}

void printStackElement() {
	for (int i = top; i >= 0; i--) {
		printf("%d ", stack[i]);
	}
	printf("\n");
}

int main() {
	int T = 0;
	element data = 0; // ���ÿ� ������ ������

	// �׽�Ʈ ���̽� �Է�
	for (scanf("%d", &T); T--;) {
		init();
		while (1) {
			scanf("%d", &data);

			// -1 �Է� �� ������ �Է� ����
			if (data == -1)
				break;

			push(data);
		}
		printStackElement(); // ������ ��� ��� ���, LIFO ���
	}
}

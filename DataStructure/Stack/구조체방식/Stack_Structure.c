#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 100 // ������ �ִ� ũ�� ����

typedef int element; // ������ ���� ����

// 1���� �迭�� ����ü�� ǥ��
typedef struct {
	element data[MAX];
	int top;
}StackType;


void init(StackType *s) {
	s->top = -1;
}

// ���� ���� ���� ���� �Լ�
// ���ڷ� ���޵� ����ü�� top ������ -1�̸� ���� �������� �ǹ�
int is_empty(StackType * s) {
	return (s->top == -1);
}

// ���� ��ȭ ���� ���� �Լ� 
int is_full(StackType * s) {
	return (s->top == (MAX - 1));
}

// ���ÿ� �����͸� �����ϴ� �Լ�
void push(StackType * s, element data) {
	// ���ڷ� ���޹��� ������ ��ȭ ���¶��
	if (is_full(s)) {
		printf("���� ��ȭ ����\n");
		return; // �Լ� ����
	}
	// ��ȭ ���°� �ƴ϶�� ������ ����
	s->data[++(s->top)] = data;
}

// ���ÿ��� �����͸� �����ϴ� �Լ�
element pop(StackType * s) {
	if (is_empty(s)) {
		printf("���� ���� ����\n");
		exit(1);
	}
	return s->data[(s->top)--]; // �����͸� ��ȯ�ϸ鼭 top������ ���� 
}

void printStackElement(StackType * s) {
	for (int i = s->top; i >= 0; i--) {
		printf("%d ", s->data[i]);
	}
	printf("\n");
}
int main() {
	StackType s; // ���� ����
	element data = 0;
	int T = 0;

	for (scanf("%d", &T); T--;) {
		init(&s); // ���� �ʱ�ȭ

		while (1) {
			scanf("%d", &data);

			// -1 �Է� �� ������ �Է� ����
			if (data == -1)
				break;

			push(&s, data);
		}
		printStackElement(&s);
	}
}
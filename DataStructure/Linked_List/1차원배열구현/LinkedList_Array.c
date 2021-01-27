#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // ����Ʈ �ִ� ũ�� ����

typedef int element; // �ڷ��� ����
typedef struct {
	element Arr[MAX]; // ����Ʈ ����
	int size; // ���� ����Ʈ�� ����� �׸���� ����
}ArrayList;

// ���� ó�� �Լ�
void error(char *msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

// ����Ʈ �ʱ�ȭ �Լ�
void init(ArrayList * L) {
	L->size = 0;
}

// ����Ʈ ���� ���� ���� �Լ�
element is_empty(ArrayList * L) {
	// ����Ʈ�� ��������� 1, �׷��� ������ 0 ��ȯ
	return (L->size == 0);
}

// ����Ʈ ��ȭ ���� ���� �Լ�
element is_full(ArrayList * L) {
	// size�� ���� �ε��� ��ġ�� ��Ÿ��
	// size�� 99��� ��� �ε����� ���ٵ� ���̹Ƿ� ��ȭ �������� �ǹ�
	// ��ȭ ������ �� 1, �׷��� ������ 0 ��ȯ
	return (L->size == MAX - 1);
}

// ���ڷ� ������ pos �ε��� ��ġ�� ���� ��ȯ�Ѵ�.
element get_entry(ArrayList * L, int pos) {
	// pos�� ArrayList�� �ε��� ��ġ
	// 0���� �۰ų� ����� ���� �ε������� ũ�ٸ� ����
	if (pos < 0 || pos >= L->size) {
		error("��ġ ����");
	}
	return L->Arr[pos];
}

// �ڷḦ ���� �ϴ� �Լ�
void insert(ArrayList * L, int pos, element item) {
	// ����Ʈ�� ��ȭ ���°� �ƴϰ� ���� ��ġ�� 0���� ũ�ų� ���� ������ ���� �۰ų� ���� ��
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		// �ڿ������� ����
		for (int i = (L->size - 1); i >= pos; i--) {
			L->Arr[i + 1] = L->Arr[i]; // ���� ��ġ ���� ��ҵ��� ��ĭ�� �о��.
		}
		L->Arr[pos] = item; // ���� ��ġ�� ������ ����
		L->size++; // ������ ���� �� ���� �׸� ���� ����
	}
}

// pos ��ġ�� �����͸� �����ϴ� �Լ�
element Delete(ArrayList * L, int pos) {
	element item;

	// �����Ϸ��� �������� ��ġ�� �ǹٸ��� ���� ��
	if (pos < 0 || pos >= L->size)
		error("��ġ ����");

	item = L->Arr[pos]; // �����Ϸ��� ������ �ӽ� ����

	// �����Ϸ��� ��ġ�� �������� �迭�� ������ �׸���� ��ȸ
	for (int i = pos; i < (L->size - 1); i++) {
		L->Arr[i] = L->Arr[i + 1]; // ������ �� ĭ�� ����.
	}
	L->size--; // �׸� ���� ����

	return item; // ������ ������ ��ȯ
}

// ����Ʈ ��� �Լ�
void printArrayList(ArrayList * L) {
	for (int i = 0; i < L->size; i++) {
		printf("%d -> ", L->Arr[i]);
	}
	printf("\n");
}

int main() {
	ArrayList list;
	int T = 0;
	element pos = 0; // ����ڿ��� �Է¹��� ������ ���� ������
	element item = 0; // ����ڿ��� �Է¹��� ������

	// �׽�Ʈ ���̽� �Է� ������ ���ÿ� ������ŭ ��ȸ
	for (scanf("%d", &T); T--;) {
		init(&list);

		while (1) {
			scanf("%d %d", &pos, &item); // ������ ���� �����ǰ� ������ �Է� ����

			// �����, -1�Է� �� �Է� ����
			if (item == -1)
				break;

			insert(&list, pos, item);
		}
		printArrayList(&list);
	}
	return 0;
}
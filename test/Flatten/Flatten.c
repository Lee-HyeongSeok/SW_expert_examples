#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define MAX 100 // ������ ����, ���� ���� ����

int height[MAX]; // ������ ���̸� �����ִ� �迭 
int maxIdx, minIdx;

void init() {
	for (int i = 0; i < MAX; i++) {
		height[i] = 0;
		maxIdx = minIdx = 0;
	}
}

// ������ ���̸� �Է� �޴� �Լ� 
void inputMap() {
	int val = 0;
	
	// ���� ���� 100�� ��ŭ ������ ���̸� �Է� �޴´�.
	// ���̸� ���η� �����.
	for (int i = 0; i < MAX; i++) {
		scanf("%d", &val);
		height[i] = val; // ������ ���̸� ����, ���߿� �ְ�/������ ã�� ����
		
	}
}

// ���� ������ ���̰� ��ź���� �˻��ϴ� �Լ�
bool isFlatten() {
	for (int i = 0; i < MAX; i = i + 2) {
		if (height[i] - height[i + 1] > 0)
			return false;
	}
	return true;
}

void maxIndex() {
	int maxVal = 0;

	for (int i = 0; i < MAX; i++) {
		// maxVal���� ū ���� �ִٸ�
		if (maxVal < height[i]) {
			maxVal = height[i]; // maxVal�� �� ū������ ��ü
			maxIdx = i; // �ش� �ε��� ����(��������)
		}
	}
}

void minIndex() {
	int minVal = height[0];
	minIdx = 0;

	for (int i = 1; i < MAX; i++) {
		if (minVal > height[i]) {
			minVal = height[i];
			minIdx = i;
		}
	}
}


void dumpBoxes(int dump) {
	// ���� Ƚ����ŭ ��ȸ
	while (dump--) {
		// ��ź���� �ʴٸ� ���� �۾� ����
		if (!isFlatten()) {
			maxIndex(); // maxIdx�� ���� ū ���� �ε����� �����Ѵ�.
			minIndex(); // minIdx�� ���� ���� ���� �ε����� �����Ѵ�.

			// ���� ���� ���ڸ� ���� ���� ���ڷ� ������.
			height[minIdx] += 1;
			height[maxIdx] -= 1;
		}
		// ��ź������ Ż��
		else if (isFlatten())
			break;
	}
}

void Score() {
	int result = 0;
	// max, min ���� Ž��
	maxIndex();
	minIndex();

	// �ְ����� �������� ����
	result = height[maxIdx] - height[minIdx];
	printf(" %d", result);
}


int main() {
	int dump = 0; // ���� Ƚ���� �Է� �޴´�.

	for (int test_case = 1; test_case <= 10; test_case++) {
		init(); // �迭 �ʱ�ȭ 
		scanf("%d", &dump);

		inputMap(); // ���� ���̸� �Է� �޴´�.
		dumpBoxes(dump); // ����
		printf("#%d", test_case);
		Score(); // ���� ���
		printf("\n");
	}

	return 0;
}
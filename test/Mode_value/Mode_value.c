#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 0�� �̻� 100�� ������ �� 
#define MAX 101

int score[MAX];

void input_Data() {
	int score_Data = 0;
	// 1000���� �����͸� �Է� ����
	for (int i = 0; i < 10; i++) {
		scanf("%d", &score_Data);
		if (score_Data >= 0 && score_Data <= MAX-1) {
			// ������ ������ ���� �κ�
			score[score_Data] += 1; // �л��� ������ �ε����� �Ͽ� 1�� ����
		}
	}
}

void Print() {
	for (int i = 0; i < MAX; i++) {
		printf("index : %d, value : %d\n", i, score[i]);
	}
}

void Max_Value() {
	int max = 0;
	int index_score = 0;

	// 0���� 100���� ��ȸ
	for (int i = 0; i < MAX; i++) {
		// �ֺ��� ������ max�� ����� ������ ũ�ٸ�
		// ���� ū �ֺ��� ã�� ����
		if (score[i] >= max && index_score < i) {
			index_score = i; // ������ index_score�� ����
			max = score[i]; // �ֺ��� max�� ����, �� ū �ֺ��� ã�� ����
		}
	}
	printf("�ֺ� : %d", index_score);
}

int main() {
	int T = 0;
	scanf("%d", &T);
	input_Data();
	Max_Value();
}
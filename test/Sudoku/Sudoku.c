#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define n 9 // 9 by 9 matrix 

int Map[n][n]; 
int mask[3][3];
int Row[n];
int Col[n];

// ���� �Է� �Լ�
void inputData() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &Map[i][j]);
		}
	}
}

void RowCol_init() {
	for (int i = 0; i < n; i++) {
		Row[i] = 0;
		Col[i] = 0;
	}
}
// ���� ��ǥ�� ���� �޾Ƽ� ��� ���� �˻�
/*  ������ ��Ȯ���� �˾ƺ��� ���� ���� �ε����� 1�� ǥ��,
	Row, Col �迭���� 2
*/ 

// �ϳ��� ��ǥ�� ���� ����, ���� Ž��
bool Find(int i, int j) {
	// �� ���� = i, �� ���� = j
	for (int z = 0; z < n; z++) {
		Row[Map[i][z]] += 1; // �� ����
		Col[Map[z][j]] += 1; // �� ���� 
	}
	for (int z = 0; z < n; z++) {
		if (Row[z] + Col[z] > 2) {
			return false;
		}
	}
	return true;
}

// �� Ž��, ������ ���� 
// ���� ��� ��ǥ�� ��ȸ
bool Finding_Map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// ���� ��ǥ�� ����
			// ��ġ�� ���ڰ� �ִٸ�
			if (!Find(i, j))
				return false;
			RowCol_init();
		}
	}
	return true;
}

int mask_op(int i, int j) {
	int total = 0;

	for (int c = i - 1; c <= i + 1; c++) {
		for (int r = j - 1; r <= j + 1; r++) {
			total += Map[c][r];
		}
	}
	return total;
}

bool masking(int i) {
	int result = 0;

	for (int j = 0; j < n; j++) {
		if (j == 1) {
			result = mask_op(i, j);
			if (result != (n * (n + 1)) / 2)
				return false;
		}
		else if (j == 4) {
			result = mask_op(i, j);
			if (result != (n * (n + 1)) / 2)
				return false;
		}
		else if (j == 7) {
			result = mask_op(i, j);
			if (result != (n * (n + 1)) / 2)
				return false;
		}
		result = 0;
	}
	return true;
}

// �ڽ� ���� 3 by 3 ��� �� ������ ���� 
bool Finding_local() {
	for (int i = 0; i < n; i++) {
		if (i == 1) {
			if (!masking(i))
				return false;
		}
		else if (i == 4) {
			if (!masking(i))
				return false;

		}
		else if (i == 7) {
			if (!masking(i))
				return false;
		}
	}
	return true;
}

int main() {
	int T = 0;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		inputData(); // ����� �Է¹��� 
		if (Finding_Map() && Finding_local())
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 12

int wall[MAX][MAX];
int N;
int value = 1;

// ���ڰ� �� �ڸ��� 0���� �ʱ�ȭ
void init() {
	// �����ڸ� ���� ��� 0���� �ʱ�ȭ 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			wall[i][j] = 0; // ���� ������ ������ ������ 0���� ����, ���ڰ� �� ���� 
		}
	}
}

// ��(�����ڸ�)�� -1�� �ʱ�ȭ 
void makeWall() {
	for (int i = 0; i <= N + 1; ++i) {
		wall[0][i] = -1;
		wall[i][N + 1] = -1;
		wall[N + 1][i] = -1;
		wall[i][0] = -1;
	}
}

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", wall[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int T = 0;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &N);
		init();
		makeWall();

		int i = 1;
		int j = 1;
		int value = 1;

		while (value <= (N*N)) {
			wall[i][j] = value;
			value++;

			// (i-1, j)��ǥ(��)�� ���̰�, �������� ��ĭ�̸�
			if ((wall[i - 1][j] != 0) && (wall[i][j + 1] == 0)) {
				j++;
			}
			// (i, j+1)��ǥ(������)�� ���̰�, �Ʒ��� ��ĭ�̸�
			else if ((wall[i][j + 1] != 0) && (wall[i + 1][j]) == 0) {
				i++;
			}
			// (i+1, j)��ǥ(�Ʒ�)�� ���̰�, ������ ��ĭ�̸�
			else if ((wall[i + 1][j] != 0) && (wall[i][j - 1] == 0)) {
				j--;
			}
			// (i, j-1)��ǥ(����)�� ���̰�, ������ ��ĭ�̸�
			else if ((wall[i][j - 1] != 0) && (wall[i - 1][j] == 0)) {
				i--;
			}
		}

		i = 1, j = 1, value = 1;
		printf("#%d \n", test_case);
		print();
	}

	return 0;
}
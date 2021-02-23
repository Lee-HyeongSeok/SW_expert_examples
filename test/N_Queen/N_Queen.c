#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXN 15
int Chess[MAXN]; // N by N ����
int N; // N ���� ��
int NumberOfCase; // ����� ��

void init() {
	for (int i = 0; i < N; i++) {
		Chess[i] = 0;
	}
}

bool CrossCheck(int r, int c) {
	for (int i = 1; i < r; i++) {
		if (Chess[i] == c)
			return false;
		if (abs(r-i) == abs(Chess[i] - c))
			return false;
	}
	return true;
}

void backTracking(int r, int c) {
	Chess[r] = c; // r�� c��

	if (r == N)
		NumberOfCase++;
	else {
		for (int i = 1; i <= N; i++) {
			if (CrossCheck(r + 1, i)) {
				backTracking(r + 1, i);
			}
		}
	}
	Chess[r] = 0;
}
/*
void dfs(int n_count) {
	// n_count�� ��� ���忡 N���� ���� ������ �� �ϳ��� �����Ѵ�.
	// n_count�� �����ϴٰ� N�� �������� �� ����� ���� ������Ų��.
	
	if (n_count == N) {
		NumberOfCase++;
		return;
	}
	
	else {
		// dfs ���Ž���ϴ� �κ�
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// ���� ��ġ�� ���� ��ġ�ص� �Ǵ� ���
				if (CrossCheck(i, j)) {
					Chess[i][j] = 1; // ���� ��ġ�� ���� ��ġ
					dfs(n_count + 1);
				}
			}
		}
	}
	Chess[i][j] = 0;
}
*/

int main() {
	int T = 0; // �׽�Ʈ ���̽�
	scanf("%d", &T); // �׽�Ʈ ���̽� �Է�

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N); // N���� ���� �Է¹޴´�.

		for (int i = 1; i <= N; i++) {
			backTracking(1, i);
		}
		
		printf("#%d %d\n", tc, NumberOfCase);

		init(); // N by N���� �Ҵ���� �迭 �ʱ�ȭ
		NumberOfCase = 0;
	}
}
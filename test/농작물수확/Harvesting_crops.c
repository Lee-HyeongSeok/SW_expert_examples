#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXN 50

int N;
int Map[MAXN][MAXN];

void process() {
	int half = N / 2;
	int SW = 0;
	int sum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// half�� 0�� �ƴ� ���� ��Ģ�� ���� ���� ���Ѵ�.
			if (half != 0) {
				if (j < half || j >= N - half)
					continue;
				else
					sum += Map[i][j];
					//printf("%d", Map[i][j]);
			}
			// half�� 0�� ���� �ش� ���ο� ��� ������ �������� �Ѵ�.
			// � ��Ģ�� �������� �ʰ� loop�� ���� 
			else {
				sum += Map[i][j];
				//printf("%d", Map[i][j]);
			}
		}
		// �߰� ���� ������ SW�� 1�� �ٲ㼭 half�� ��� ������Ų��.
		// �߰� ������� �ǹ̴� half�� ó������ 0�� �Ǿ��� ���� ���Ѵ�.
		if (half == 0)
			SW = 1;

		// switch ������ �̿��ؼ� half�� �������� ���������� ����
		if (SW) {
			half++;
		}
		else if (!SW) {
			half--;
		}
	}
	printf(" %d", sum);
}

int main() {
	int T = 0;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &Map[i][j]);
			}
		}
		printf("#%d", tc);
		process();
	}
}
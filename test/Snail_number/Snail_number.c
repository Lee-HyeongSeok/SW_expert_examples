#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 12

int wall[MAX][MAX];
int N;
int value = 1;

// 숫자가 들어갈 자리를 0으로 초기화
void init() {
	// 가장자리 빼고 모두 0으로 초기화 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			wall[i][j] = 0; // 벽을 제외한 나머지 공간을 0으로 만듬, 숫자가 들어갈 공간 
		}
	}
}

// 벽(가장자리)를 -1로 초기화 
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

			// (i-1, j)좌표(위)가 벽이고, 오른쪽이 빈칸이면
			if ((wall[i - 1][j] != 0) && (wall[i][j + 1] == 0)) {
				j++;
			}
			// (i, j+1)좌표(오른쪽)가 벽이고, 아래가 빈칸이면
			else if ((wall[i][j + 1] != 0) && (wall[i + 1][j]) == 0) {
				i++;
			}
			// (i+1, j)좌표(아래)가 벽이고, 왼쪽이 빈칸이면
			else if ((wall[i + 1][j] != 0) && (wall[i][j - 1] == 0)) {
				j--;
			}
			// (i, j-1)좌표(왼쪽)가 벽이고, 위쪽이 빈칸이면
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
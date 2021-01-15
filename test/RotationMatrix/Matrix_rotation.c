#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 7 // N은 3이상 7이하

int N;
int Map[MAX][MAX];
int temp[MAX][MAX];
int ResultMatrix[MAX*MAX];
int index;

void InputData() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &Map[i][j]);
		}
	}
}

void init_temp() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = 0;
		}
	}
}
void init_Map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Map[i][j] = 0;
		}
	}
}

void init_Resultmatrix() {
	for (int i = 0; i < N*N; i++) {
		ResultMatrix[i] = 0;
	}
}

void merge() {
	int merge_Row = 0;
	int num = 1;

	for (int i = 0; i < N; i++) {
		for (int j = N-1; j >= 0; j--) {
			merge_Row += (num * temp[i][j]);
			num *= 10;
		}
		num = 1;
		ResultMatrix[index++] = merge_Row;
		merge_Row = 0;
	}
}

void Rotation_90() {
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = Map[(N - 1) - j][i];
		}
	}

	// temp 배열의 각 행을 하나의 숫자로 통합
	merge();

	// 다시 temp 배열을 초기화
	init_temp();
}

void Rotation_180() {
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = Map[(N - 1) - i][(N - 1) - j];
		}
	}

	// 각 행을 하나의 숫자로 통합
	merge();

	// 다시 temp 배열을 초기화
	init_temp();
}

void Rotation_270() {
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = Map[j][(N - 1) - i];
		}
	}

	// 각 행을 하나의 숫자로 통합
	merge();

	// 다시 temp 배열을 초기화
	init_temp();
}

void printMatrix() {
	init_temp();
	int idx = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[j][i] = ResultMatrix[idx++];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", temp[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int T = 0;
	scanf("%d", &T); // 테스트 케이스 입력 받음 
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &N);
		InputData();

		Rotation_90();
		Rotation_180();
		Rotation_270();

		printf("#%d\n", test_case);
		printMatrix();

		// 결과 출력 후 초기화 
		init_Map();
		index = 0;
		init_Resultmatrix();
	}
	return 0;
}

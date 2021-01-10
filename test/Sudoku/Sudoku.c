#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define n 9 // 9 by 9 matrix 

int Map[n][n]; 
int mask[3][3];
int Row[n];
int Col[n];

// 퍼즐 입력 함수
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
// 현재 좌표를 전송 받아서 행과 열을 검사
/*  순서의 정확성을 알아보기 위해 값을 인덱스로 1을 표기,
	Row, Col 배열에서 2
*/ 

// 하나의 좌표에 대한 가로, 세로 탐색
bool Find(int i, int j) {
	// 행 기준 = i, 열 기준 = j
	for (int z = 0; z < n; z++) {
		Row[Map[i][z]] += 1; // 행 기준
		Col[Map[z][j]] += 1; // 열 기준 
	}
	for (int z = 0; z < n; z++) {
		if (Row[z] + Col[z] > 2) {
			return false;
		}
	}
	return true;
}

// 행 탐색, 수도쿠 검증 
// 맵의 모든 좌표를 순회
bool Finding_Map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 현재 좌표를 전송
			// 겹치는 숫자가 있다면
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

// 자신 기준 3 by 3 행렬 내 수도쿠 검증 
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
		inputData(); // 행렬을 입력받음 
		if (Finding_Map() && Finding_local())
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}

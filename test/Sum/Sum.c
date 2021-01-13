#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define T 10 // 주어진 테스트 케이스 10개
#define MAX 100 // 주어진 2차원 배열의 크기

int Arr[MAX][MAX];
int max_value;

void FindRow(){
	int sum = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			sum += Arr[i][j];
		}
		if (max_value < sum)
			max_value = sum;
		sum = 0;
	}
}

void FindCol() {
	int sum = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			sum += Arr[j][i];
		}
		if (max_value < sum)
			max_value = sum;
		sum = 0;
	}
}

void CrossLeftDown() {
	int sum = 0;
	// 왼쪽 상단부터 오른쪽 하단 대각선의 합
	for (int i = 0; i < MAX; i++) {
		sum += Arr[i][i];
	}
	if (max_value < sum)
		max_value = sum;
}

void CrossLeftUp() {
	int sum = 0;
	// 왼쪽 하단부터 오른쪽 상단 대각선의 합 
	// 전치 행렬
	for (int i = MAX - 1; i >= 0; i--) {	
		sum += Arr[MAX - (i + 1)][i];
		
	}
	if (max_value < sum)
		max_value = sum;
}

void InputMatrix() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			scanf("%d", &Arr[i][j]);
		}
	}
}
int main() {

	for (int test_case = 1; test_case <= T; test_case) {
		InputMatrix();
		FindRow();
		FindCol();
		CrossLeftDown();
		CrossLeftUp();
		printf("#%d %d\n", test_case, max_value);
		max_value = 0;
	}
	return 0;
}

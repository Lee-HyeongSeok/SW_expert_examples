#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXN 15
int Chess[MAXN]; // N by N 보드
int N; // N 개의 퀸
int NumberOfCase; // 경우의 수

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
	Chess[r] = c; // r행 c열

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
	// n_count는 모든 보드에 N개의 퀸이 놓였을 때 하나씩 증가한다.
	// n_count가 증가하다가 N과 같아졌을 때 경우의 수를 증가시킨다.
	
	if (n_count == N) {
		NumberOfCase++;
		return;
	}
	
	else {
		// dfs 재귀탐색하는 부분
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// 현재 위치에 퀸을 배치해도 되는 경우
				if (CrossCheck(i, j)) {
					Chess[i][j] = 1; // 현재 위치에 퀸을 배치
					dfs(n_count + 1);
				}
			}
		}
	}
	Chess[i][j] = 0;
}
*/

int main() {
	int T = 0; // 테스트 케이스
	scanf("%d", &T); // 테스트 케이스 입력

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N); // N개의 퀸을 입력받는다.

		for (int i = 1; i <= N; i++) {
			backTracking(1, i);
		}
		
		printf("#%d %d\n", tc, NumberOfCase);

		init(); // N by N으로 할당받은 배열 초기화
		NumberOfCase = 0;
	}
}
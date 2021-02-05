#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>

using namespace std;

#define MAX 4 // 격자판 크기 지정

int map[MAX][MAX];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
set<int> s; // 이어붙여진 숫자들을 저장할 변수


void dfs(int y, int x, int val, int dept) {
	if (dept == 7) { // 탐색 깊이가 7이면 이어붙인 값 저장, 함수 종료
		s.insert(val);
	}
	else {
		val *= 10;
		val += map[y][x];

		// 4 방향 탐색
		for (int i = 0; i < MAX; i++) {

			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x >= 0 && new_x < MAX && new_y >= 0 && new_y < MAX)
				dfs(new_y, new_x, val, dept + 1);
		}
	}
}

// 2차원 배열 값 추가 함수 
void inputData() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> map[i][j];
		}
	}
}

void printMap() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << " " << map[i][j];
		}
		cout << endl;
	}
}

int main() {
	int T = 0;
	int tc = 0;

	// 테스트 케이스 입력
	// 입력과 동시에 테스트 케이스만큼 순회 
	for (scanf("%d", &T); T--;) {
		++tc;
		inputData(); // 격자판을 입력받는다.
		printMap();

		// 모든 격자판 전사 탐색 
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				dfs(i, j, 0, 0); // 깊이는 1부터 시작 
			}
		}
		printf("#%d %d", tc, s.size());
	}
}
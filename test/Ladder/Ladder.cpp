#include <iostream>

using namespace std;

#define MAX 10

int Map[MAX][MAX];
int visit[MAX][MAX];

bool findLoad(int x, int y);

void inputLadder() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> Map[i][j];
		}
	}
}

void print() {
	cout << "===============================" << endl;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << Map[i][j] << " ";
		}
		cout << endl;
	}
}

void startVertex() {
	for (int i = 0; i < MAX; i++) {
		if (Map[0][i] == 1) {
			// 시작 정점을 찾아낸다.
			visit[0][i] = 1;
			// 0, i를 함수에 넘겨줌
			if (findLoad(0, i)) {
				printf("%d 라인에 2 있음", i);
			}
		}
	}
}

bool findLoad(int x, int y) {
	while (1) {
		// x가 MAX-1이면 바닥에 도착했다는 것
		// 도착하는 이전에 2를 찾지 못하면 해당 라인에는 2가 없음
		if (x == MAX - 1)
			break;

		// 오른쪽에 길이 있는지 검사
		if (Map[x][y + 1] == 1 && !visit[x][y+1]) {
			y++;
			visit[x][y] = 1;
			// 오른쪽으로 완전히 현재위치 이동 후 2가 있는지 검사
			if (Map[MAX-1][y] == 2) {
				return true;
			}
		}
		// 항상 세 방향 탐색
		// 아래 방향에 길이 있는지 검사 
		else if (Map[x + 1][y] == 1 && !visit[x+1][y]) {

			// 아래 방향에 길이 있으면서도 오른쪽 방향에도 길이 있는지 검사
			if (Map[x][y + 1] == 1 && !visit[x][y + 1]) {
				y++;
				visit[x][y] = 1;
			}
			// 아래 방향에 길이 있으면서도 왼쪽 방향에도 길이 있는지 검사
			else if (Map[x][y - 1] == 1 && !visit[x][y - 1]) {
				y--;
				visit[x][y] = 1;
			}
			// 아래 방향에 길이 있으며 좌우에 길이 없으면 아래 방향으로 진행
			else {
				x++;
				visit[x][y] = 1;
			}

			// 진행 이후 현재위치에서 2를 발견하면 true를 리턴하고 함수를 빠져나감
			if (Map[MAX-1][y] == 2) {
				return true;
			}
		}
		// 현재 위치 기준, 왼쪽 방향에 길이 있는지 검사 
		else if (Map[x][y - 1] == 1 && !visit[x][y - 1]) {
			y--;
			visit[x][y] = 1;

			// 완전히 이동 후 2가 있는지 검사
			if (Map[MAX-1][y] == 2) {
				return true;
			}
		}
	}
	return false; // 해당 라인에 2가 없을 때 
}

int main() {
	int T = 0;

	for (int test_case = 1; test_case <= 10; test_case++) {
		cin >> T;

		inputLadder();
		print();
		startVertex();
	}
	return 0;
}
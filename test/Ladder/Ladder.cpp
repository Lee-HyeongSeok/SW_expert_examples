#include <iostream>

using namespace std;

#define MAX 10

int Map[MAX][MAX];
int visit[MAX][MAX];
bool status = false;

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
		if (x == MAX - 1)
			break;
		if (Map[x][y + 1] == 1 && !visit[x][y+1]) {
			y++;
			visit[x][y] = 1;
			if (Map[MAX-1][y] == 2) {
				return true;
			}
		}
		// 항상 세 방향 탐색
		else if (Map[x + 1][y] == 1 && !visit[x+1][y]) {
			if (Map[x][y + 1] == 1 && !visit[x][y + 1]) {
				y++;
				visit[x][y] = 1;
			}
			else if (Map[x][y - 1] == 1 && !visit[x][y - 1]) {
				y--;
				visit[x][y] = 1;
			}
			else {
				x++;
				visit[x][y] = 1;
			}

			if (Map[MAX-1][y] == 2) {
				return true;
			}
		}
		else if (Map[x][y - 1] == 1 && !visit[x][y - 1]) {
			y--;
			visit[x][y] = 1;

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
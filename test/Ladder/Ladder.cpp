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
			// ���� ������ ã�Ƴ���.
			visit[0][i] = 1;
			// 0, i�� �Լ��� �Ѱ���
			if (findLoad(0, i)) {
				printf("%d ���ο� 2 ����", i);
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
		// �׻� �� ���� Ž��
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
	return false; // �ش� ���ο� 2�� ���� �� 
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
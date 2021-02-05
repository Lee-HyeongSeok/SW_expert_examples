#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>

using namespace std;

#define MAX 4 // ������ ũ�� ����

int map[MAX][MAX];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
set<int> s; // �̾�ٿ��� ���ڵ��� ������ ����


void dfs(int y, int x, int val, int dept) {
	if (dept == 7) { // Ž�� ���̰� 7�̸� �̾���� �� ����, �Լ� ����
		s.insert(val);
	}
	else {
		val *= 10;
		val += map[y][x];

		// 4 ���� Ž��
		for (int i = 0; i < MAX; i++) {

			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x >= 0 && new_x < MAX && new_y >= 0 && new_y < MAX)
				dfs(new_y, new_x, val, dept + 1);
		}
	}
}

// 2���� �迭 �� �߰� �Լ� 
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

	// �׽�Ʈ ���̽� �Է�
	// �Է°� ���ÿ� �׽�Ʈ ���̽���ŭ ��ȸ 
	for (scanf("%d", &T); T--;) {
		++tc;
		inputData(); // �������� �Է¹޴´�.
		printMap();

		// ��� ������ ���� Ž�� 
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				dfs(i, j, 0, 0); // ���̴� 1���� ���� 
			}
		}
		printf("#%d %d", tc, s.size());
	}
}
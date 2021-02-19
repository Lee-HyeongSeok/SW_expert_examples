#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAXM 11
#define MAXT ((MAXM * 2) + (MAXM * MAXM))

class Position {
	int r, c;

public :
	Position() {

	}

	Position(int r, int c) : r(r), c(c) {

	}

	int getRow() {
		return r;
	}

	int getCol() {
		return c;
	}
};

Position man[MAXM], stair[2];

int N, M, S;
int map[MAXM][MAXM];

// match[x] = y : x��° ����� y ��° ��� �Ա��� ��ġ���� �ǹ�
int match[MAXM];
int answer;

int dist(int man_index, int stair_index) {
	int dx = abs(man[man_index].getRow() - stair[stair_index].getRow());
	int dy = abs(man[man_index].getCol() - stair[stair_index].getCol());
	return dx + dy;
}

void update() {
	int total_min_time = 0;


	for (int stair_index = 0; stair_index < 2; stair_index++) {
		// ���� ��ü ����
		Position &now_stair = stair[stair_index];

		// arrival_time[t] : �ð� t�� �� ��� �Ա��� �����ϴ� ��� ��
		int arrival_time[MAXM * 2] = { 0, };

		// current_stair[t] : �ð� t �� �� ����� �������� �ִ� ��� ��
		int current_stair[MAXT] = { 0, };

		for (int man_index = 0; man_index < M; man_index++) {
			if (match[man_index] == stair_index) {
				arrival_time[dist(man_index, stair_index) + 1]++;
			}
		}

		// stair_index ����� �������� ����� ��� �۾��� ��ġ�� ���� �ʿ��� �ּҽð�
		int now_min_time = 0;

		for (int time = 1; time <= 20; time++) {
			while (arrival_time[time] > 0) {
				arrival_time[time]--;

				// �ش� ����� �������µ� �ʿ��� �ð�
				int remain_time = map[now_stair.getRow()][now_stair.getCol()];

				// 3���̻� ���ÿ� �������� ���� ���� �� 1ĭ�� ���� ������.
				for (int walk_time = time; walk_time < MAXT; walk_time++) {
					if (current_stair[walk_time] < 3) {
						current_stair[walk_time]++;
						remain_time--;

						// now_min_time : ��� �������� ����� ��� �۾��� ��ġ�� ���� �ּҽð�
						// walk_time+1 : ����� �������µ� �ɸ� �ð�
						// ����� ��� ���������� now_min_time ���� �� ����
						if (remain_time == 0) {
							now_min_time = max(now_min_time, walk_time + 1);
							break;
						}
					}
				}
			}
		}
		// ��ü ����� �������µ� �ʿ��� �ּ� �ð�
		total_min_time = max(total_min_time, now_min_time);
	}
	// ���� match ������ ���� total_min_time �� �������� ����
	answer = min(answer, total_min_time);
}

void dfs(int man_index) {
	// ��� �ο��� ����� ����� �� ���ߴٸ�
	if (man_index == M) {
		// �� ���¿��� �ʿ��� �ð��� ���, ����
		update();
		return;
	}

	for (int stair_index = 0; stair_index < 2; stair_index++) {
		// man_index ��° ����� stair_index ��° ����� ����
		match[man_index] = stair_index; 
		dfs(man_index + 1);
	}
}
int main() {
	int T = 0;
	cin >> T; // �׽�Ʈ ���̽� �Է¹ޱ�

	for (int tc = 1; tc <= T; tc++) {
		cin >> N; // N by N �迭 ����
		M = S = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];

				// �ԷµǴ� ������ 1 �̸� ����̹Ƿ�
				// ���� ����� ��ġ�� Position ��ü�� ����
				if (map[i][j] == 1)
					man[M++] = Position(i, j);

				// �ԷµǴ� ������ 2 �̻��̸� ����̹Ƿ�
				// ���� ����� ��ġ�� Position ��ü�� ����
				if (map[i][j] >= 2)
					stair[S++] = Position(i, j);
			}
		}
		// ���� ���Ѵ�� �ʱ�ȭ
		answer = 1e9;

		dfs(0);
		cout << "#" << tc << " " << answer << endl;
	}
}
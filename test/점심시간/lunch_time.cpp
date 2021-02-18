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

		}
	}
}

int main() {

}
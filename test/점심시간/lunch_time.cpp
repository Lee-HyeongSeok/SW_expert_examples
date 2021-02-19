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

// match[x] = y : x번째 사람이 y 번째 계단 입구에 위치함을 의미
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
		// 참조 객체 선언
		Position &now_stair = stair[stair_index];

		// arrival_time[t] : 시간 t일 때 계단 입구에 존재하는 사람 수
		int arrival_time[MAXM * 2] = { 0, };

		// current_stair[t] : 시간 t 일 때 계단을 내려가고 있는 사람 수
		int current_stair[MAXT] = { 0, };

		for (int man_index = 0; man_index < M; man_index++) {
			if (match[man_index] == stair_index) {
				arrival_time[dist(man_index, stair_index) + 1]++;
			}
		}

		// stair_index 계단을 내려가는 사람이 모두 작업을 마치기 위해 필요한 최소시간
		int now_min_time = 0;

		for (int time = 1; time <= 20; time++) {
			while (arrival_time[time] > 0) {
				arrival_time[time]--;

				// 해당 계단을 내려가는데 필요한 시간
				int remain_time = map[now_stair.getRow()][now_stair.getCol()];

				// 3명이상 동시에 내려가고 있지 않을 때 1칸씩 내려 보낸다.
				for (int walk_time = time; walk_time < MAXT; walk_time++) {
					if (current_stair[walk_time] < 3) {
						current_stair[walk_time]++;
						remain_time--;

						// now_min_time : 계단 내려가는 사람이 모두 작업을 마치기 위한 최소시간
						// walk_time+1 : 계단을 내려가는데 걸린 시간
						// 계단을 모두 내려갔으면 now_min_time 갱신 후 종료
						if (remain_time == 0) {
							now_min_time = max(now_min_time, walk_time + 1);
							break;
						}
					}
				}
			}
		}
		// 전체 계단을 내려가는데 필요한 최소 시간
		total_min_time = max(total_min_time, now_min_time);
	}
	// 현재 match 상태일 때의 total_min_time 을 정답으로 갱신
	answer = min(answer, total_min_time);
}

void dfs(int man_index) {
	// 모든 인원이 사용할 계단을 다 정했다면
	if (man_index == M) {
		// 현 상태에서 필요한 시간을 계산, 갱신
		update();
		return;
	}

	for (int stair_index = 0; stair_index < 2; stair_index++) {
		// man_index 번째 사람이 stair_index 번째 계단을 선택
		match[man_index] = stair_index; 
		dfs(man_index + 1);
	}
}
int main() {
	int T = 0;
	cin >> T; // 테스트 케이스 입력받기

	for (int tc = 1; tc <= T; tc++) {
		cin >> N; // N by N 배열 지정
		M = S = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];

				// 입력되는 정수가 1 이면 사람이므로
				// 현재 사람의 위치를 Position 객체에 저장
				if (map[i][j] == 1)
					man[M++] = Position(i, j);

				// 입력되는 정수가 2 이상이면 계단이므로
				// 현재 계단의 위치를 Position 객체에 저장
				if (map[i][j] >= 2)
					stair[S++] = Position(i, j);
			}
		}
		// 답을 무한대로 초기화
		answer = 1e9;

		dfs(0);
		cout << "#" << tc << " " << answer << endl;
	}
}
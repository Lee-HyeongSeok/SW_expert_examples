#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_SIZE 12 // 1 <= 코어의 최대수 <= 12
vector <pair<int, int>> v;
int vector_size; // 사용자가 입력한 최대 쌍의 수
int T, N; // 테스트 케이스, 정방행렬 사이즈
int core_cnt, line_len = 0; // 코어 개수, 전선 길이
int map[MAX_SIZE][MAX_SIZE]; // 코어와 셀을 마킹하기 위한 배열
int visited[MAX_SIZE][MAX_SIZE]; // 방문했음을 마킹하기 위한 배열

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 시작 인덱스, 전선 수, 코어 수, 탐색 횟수
void Processing(int index, int line, int core, int ex) {

	// 더 탐색해도 저장된 코어의 개수만큼 연결할 수 없을 때
	if (core_cnt > vector_size - ex + core)
		return;

	// 코어를 모두 탐색했을 때
	if (ex == vector_size) { 

		// 저장된 코어의 개수 보다 많은 코어를 연결했을 때 갱신해준다.
		if (core_cnt < core) {
			core_cnt = core;
			line_len = line;
		}
		// 저장된 코어의 개수가 같고, 전선의 길이가 짧은 경우 갱신한다.
		else if (core_cnt == core) {
			if (line_len > line)
				line_len = line;
		}
		return;
	}

	int temp[12][12] = { 0 };

	// visited[][]는 전역변수 선언으로 내부 값이 0을 setting
	// temp 2차원 배열에 자신의 값 삽입
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = visited[i][j];
		}
	}

	// vector pair 변수 v는 겉면을 제외한 좌표가 존재함
	// index = 시작 인덱스, 0부터 시작
	for (int i = 0; i < 4; i++) {
		bool flag = true;
		int ix = 0;
		int iy = 0;
		int cnt = 0;

		// 탐색할 쌍
		int x = v[index].first; // 인자로 전달된 index에 해당하는 쌍의 첫 번째 값
		int y = v[index].second; // 인자로 전달된 index에 해당하는 쌍의 두 번째 값

		while (1) {
			ix = x + dx[i];
			iy = y + dy[i];

			if (ix < 0 || ix >= N || iy < 0 || iy >= N) break;

			// 탐색할 위치에 코어가 존재하는지, 이미 방문했었는지 조사
			// 코어가 존재하고 이미 방문했으면 flag를 false로 세팅, while문 탈출
			if (map[ix][iy] == 1 || visited[ix][iy] == 1) {
				flag = false;
				break;
			}
			// 위의 if문이 아니라면
			// 방문했었음을 마킹
			visited[ix][iy] = 1;  
			cnt++; // 증가
			
			// 탐색할 쌍의 인덱스를 현재 검사한 위치로 세팅
			x = ix; 
			y = iy;
		}
		// 탐색할 위치에 코어가 존재하고 이미 방문했을 때
		// flag가 참이라면 길이 막힌것으로 간주(겉면이거나 코어가 존재할 때)
		// 다른 방향 탐색
		if (flag) {
			// 다른 방향을 위해 index를 1증가 시킨다.
			// cnt 증가하는 이유 : 막힌 곳이 없는 경우에는 연결된 선의 길이를 의미한다. -> 선의 길이를 넘겨줌
			// 코어의 수 증가
			Processing(index + 1, line + cnt, core + 1, ex + 1);
		}
		// 연결된 선의 길이가 존재할 경우
		if (cnt != 0) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					// 위에서 통과된 코어의 위치를 방문했음을 표시하는 배열에 삽입
					visited[i][j] = temp[i][j]; 
				}
			}
		}
	}
	Processing(index + 1, line, core, ex + 1);
	return;
}

int main() {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		core_cnt = 0;
		line_len = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// 0은 빈 셀, 1은 코어를 의미
				// 정방행렬의 크기만큼 셀과 코어를 설정한다.
				cin >> map[i][j];

				// 겉에있는 코어는 전선에 연결된 코어로 간주하고 제외시킨다.
				// 겉면에 있는 코어는 전선이 필요 없기 때문이다.
				if (j != 0 && i != 0 && j != N - 1 && i != N - 1) {
					// 겉면에 있는 코어가 아닌 좌표들을 vector의 pair에 넣어준다.
					// 이 부분만 전선의 수가 몇개인지 검사하면 되기 때문
					if (map[i][j] == 1) {
						v.push_back(make_pair(i, j));
					}
				}
			}
		}
		vector_size = (int)v.size(); // 입력한 쌍의 크기를 저장한다.
		Processing(0, 0, 0, 0); // 인덱스, 전선의 수, 코어, 탐색 횟수 0부터 시작
		cout << '#' << t << ' ' << line_len << '\n';

		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		v.clear();
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

/*
초기상태 생명력 수치 2인 줄기세포가 있음
1. 만들어진 시간 = 0초, 활성화 시간은 2초
2. 이 줄기세포가 번식한 줄기세포들의 활성화 시간 = 5초, 
	처음-활성화까지 2초 소요, 3초에 번식된 세포 만들어짐

활성화 시간 = 만들어진 시간 + 생명력
죽는시간 = 활성화 시간 + 생명력, 
죽는 줄기세포는 번식이 이루어지지 않기 때문에 세포의 상태가 결정됨
*/
using namespace std;

#define MAX 350
#define SIZE 150

typedef struct {
	int x; // x좌표
	int y; // y좌표
	int Alive_time; // 만들어진 시간
	int Life_value; // 생명력
	int Die_time; // 죽는시간
	int Active_Time; // 활성화 시간
	bool state; // 세포가 죽었는지 상태를 나타내기 위함 
}Cell;

int N, M, K;
int Answer;
int Map[MAX][MAX];
vector<Cell> V;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void init() {
	memset(Map, 0, sizeof(Map));
	V.clear();
	Answer = 0;
}

bool Standard(Cell A, Cell B) {
	if (A.Life_value > B.Life_value)
		return true;
	return false;
}

void Input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
			if (a == 0)
				continue;
			Map[i + SIZE][j + SIZE] = a;

			Cell Temp;
			Temp.x = i + SIZE;
			Temp.y = j + SIZE;
			Temp.state = true; // 살아있는 상태
			Temp.Alive_time = 0; // 살아있는 시간은 0으로 초기화
			Temp.Active_Time = Temp.Alive_time + Temp.Life_value; // 활동시간 = 비활동 시간 + 세포 생명
			Temp.Die_time = Temp.Active_Time * 2; // 죽는 시간 = 활동시간 * 2
			// 생명력이 2라면, 초기부터 활동시간 까지 2초가 걸리고 활동시간부터 죽는시간까지 2초가 더 걸리므로
			// 생명력이 2인 세포는 4초 동안 살아있는다.
			V.push_back(Temp);
		}
	}
}

void Print() {
	bool Visit[MAX][MAX];
	memset(Visit, true, sizeof(Visit));
	for (int i = 0; i < V.size(); i++) {
		int x = V[i].x;
		int y = V[i].y;
		// 활동을 끝낸 세포가 있다면
		if (V[i].state == false)
			Visit[x][y] = false;
	}
	cout << "################################################" << endl;
	for (int i = 140; i < 165; i++) {
		for (int j = 140; j < 165; j++) {
			if (Visit[i][j] == false)
				cout << "_ ";
			else
				cout << Map[i][j] << " ";
		}
		cout << endl;
	}
	cout << "################################################" << endl;
}

void Die(int T) {
	for (int i = 0; i < V.size(); i++) {
		// 현재 진행 시간과 세포의 사망 시간이 같으면
		if (V[i].Die_time == T) {
			V[i].state = false; // 죽은 세포로 취급
		}
	}
}

void Active(int T) {
	vector<Cell> V_Temp;

	for (int i = 0; i < V.size(); i++) {
		// 활동 후 죽어있는 세포면
		if (V[i].state == false)
			continue; // 해당 cell 스킵
		// 현재 진행 중인 시간과 해당 세포가 활동해야 할 시간이 일치하면 
		if (V[i].Active_Time == T) {
			// 해당 세포의 좌표
			int x = V[i].x;
			int y = V[i].y;
			// 해당 세포의 살아있는 시간
			int Lv = V[i].Life_value;

			for (int j = 0; j < 4; j++) {
				// 4방향 검사
				int nx = x + dx[j];
				int ny = y + dy[j];

				// 4방향 중에 다른 cell이 차지하고 있으면 continue
				if (Map[nx][ny] != 0)
					continue;

				// 4방향 중에 다른 cell이 자리를 차지하고 있지 않으면
				Cell Temp;
				// 활동 시간이므로 번식하므로 자라난 방향의 좌표를 가진 셀을 설정
				Temp.x = nx;
				Temp.y = ny;
				Temp.Life_value = Lv; // 복제된 셀의 살아있는 시간을 물려 받음
				Temp.state = true; // 살아있음
				Temp.Alive_time = T + 1; // 1초 후 생성하는 것이므로 현재 시간에 1초를 더함
				Temp.Active_Time = Temp.Alive_time + Temp.Life_value; // 활동 시간 = 살아있는 시간 + 생명 시간
				Temp.Die_time = Temp.Active_Time + Temp.Life_value; // 죽는 시간 = 활동시간 + 생명 시간

				V_Temp.push_back(Temp);
			}
		}
	}

	if (V_Temp.size() == 0)
		return;
	// cell들의 생명 시간에 따라 정렬
	sort(V_Temp.begin(), V_Temp.end(), Standard);


	for (int i = 0; i < V_Temp.size(); i++) {
		int x = V_Temp[i].x;
		int y = V_Temp[i].y;
		int Lv = V_Temp[i].Life_value;

		if (Map[x][y] != 0)
			continue;
		// 맵에 cell의 생명시간을 표시
		Map[x][y] = Lv;
		V.push_back(V_Temp[i]);
	}
}

void Solution() {
	int Time = 0;
	while (1) {
		// K시간 후 배양 용기에 살아 있는 줄기 세포가 문제이므로
		// Time이 증가하다가 지정한 K시간이 된다면
		if (Time == K) 
			break; // while 탈출

		Die(Time); // 죽은 세포인지 확인
		Active(Time); // 활동하는 세포인지 확인
		Time++;
	}
	int Count = 0;
	for (int i = 0; i < V.size(); i++) {
		if (V[i].state == false) // 죽어있는 세포일 때
			Count++;
		if (V[i].Die_time == K) // 죽은 시간과 지정한 시간이 일치할 때
			Count++;
		if (V[i].Alive_time == K + 1) // 살아있는 시간이 지정한 시간보다 1시간 더 지나쳤을 때
			Count++;
	}
	// 총 세포에서 세지 말아야 할 세포의 개수를 빼준다.
	Answer = V.size() - Count;
}
void Solve() {
	int Test_Case;
	cin >> Test_Case;

	for (int T = 1; T <= Test_Case; T++) {
		init();
		Input();
		Solution();

		cout << "#" << T << " " << Answer << endl;
	}
}

int main() {
	/* 
	c++ 표준 스트림들이 c 표준 스트림들과 각각의 입출력 연산 후
	동기화 할지 여부를 설정함

	 */
	ios::sync_with_stdio(false);
	// 프로그램이 사용자에게 입력을 요구하기 전에 output이 flush된다.
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();
	return 0;
}
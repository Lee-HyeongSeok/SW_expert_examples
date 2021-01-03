#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

/*
�ʱ���� ����� ��ġ 2�� �ٱ⼼���� ����
1. ������� �ð� = 0��, Ȱ��ȭ �ð��� 2��
2. �� �ٱ⼼���� ������ �ٱ⼼������ Ȱ��ȭ �ð� = 5��, 
	ó��-Ȱ��ȭ���� 2�� �ҿ�, 3�ʿ� ���ĵ� ���� �������

Ȱ��ȭ �ð� = ������� �ð� + �����
�״½ð� = Ȱ��ȭ �ð� + �����, 
�״� �ٱ⼼���� ������ �̷������ �ʱ� ������ ������ ���°� ������
*/
using namespace std;

#define MAX 350
#define SIZE 150

typedef struct {
	int x; // x��ǥ
	int y; // y��ǥ
	int Alive_time; // ������� �ð�
	int Life_value; // �����
	int Die_time; // �״½ð�
	int Active_Time; // Ȱ��ȭ �ð�
	bool state; // ������ �׾����� ���¸� ��Ÿ���� ���� 
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
			Temp.state = true; // ����ִ� ����
			Temp.Alive_time = 0; // ����ִ� �ð��� 0���� �ʱ�ȭ
			Temp.Active_Time = Temp.Alive_time + Temp.Life_value; // Ȱ���ð� = ��Ȱ�� �ð� + ���� ����
			Temp.Die_time = Temp.Active_Time * 2; // �״� �ð� = Ȱ���ð� * 2
			// ������� 2���, �ʱ���� Ȱ���ð� ���� 2�ʰ� �ɸ��� Ȱ���ð����� �״½ð����� 2�ʰ� �� �ɸ��Ƿ�
			// ������� 2�� ������ 4�� ���� ����ִ´�.
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
		// Ȱ���� ���� ������ �ִٸ�
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
		// ���� ���� �ð��� ������ ��� �ð��� ������
		if (V[i].Die_time == T) {
			V[i].state = false; // ���� ������ ���
		}
	}
}

void Active(int T) {
	vector<Cell> V_Temp;

	for (int i = 0; i < V.size(); i++) {
		// Ȱ�� �� �׾��ִ� ������
		if (V[i].state == false)
			continue; // �ش� cell ��ŵ
		// ���� ���� ���� �ð��� �ش� ������ Ȱ���ؾ� �� �ð��� ��ġ�ϸ� 
		if (V[i].Active_Time == T) {
			// �ش� ������ ��ǥ
			int x = V[i].x;
			int y = V[i].y;
			// �ش� ������ ����ִ� �ð�
			int Lv = V[i].Life_value;

			for (int j = 0; j < 4; j++) {
				// 4���� �˻�
				int nx = x + dx[j];
				int ny = y + dy[j];

				// 4���� �߿� �ٸ� cell�� �����ϰ� ������ continue
				if (Map[nx][ny] != 0)
					continue;

				// 4���� �߿� �ٸ� cell�� �ڸ��� �����ϰ� ���� ������
				Cell Temp;
				// Ȱ�� �ð��̹Ƿ� �����ϹǷ� �ڶ� ������ ��ǥ�� ���� ���� ����
				Temp.x = nx;
				Temp.y = ny;
				Temp.Life_value = Lv; // ������ ���� ����ִ� �ð��� ���� ����
				Temp.state = true; // �������
				Temp.Alive_time = T + 1; // 1�� �� �����ϴ� ���̹Ƿ� ���� �ð��� 1�ʸ� ����
				Temp.Active_Time = Temp.Alive_time + Temp.Life_value; // Ȱ�� �ð� = ����ִ� �ð� + ���� �ð�
				Temp.Die_time = Temp.Active_Time + Temp.Life_value; // �״� �ð� = Ȱ���ð� + ���� �ð�

				V_Temp.push_back(Temp);
			}
		}
	}

	if (V_Temp.size() == 0)
		return;
	// cell���� ���� �ð��� ���� ����
	sort(V_Temp.begin(), V_Temp.end(), Standard);


	for (int i = 0; i < V_Temp.size(); i++) {
		int x = V_Temp[i].x;
		int y = V_Temp[i].y;
		int Lv = V_Temp[i].Life_value;

		if (Map[x][y] != 0)
			continue;
		// �ʿ� cell�� ����ð��� ǥ��
		Map[x][y] = Lv;
		V.push_back(V_Temp[i]);
	}
}

void Solution() {
	int Time = 0;
	while (1) {
		// K�ð� �� ��� ��⿡ ��� �ִ� �ٱ� ������ �����̹Ƿ�
		// Time�� �����ϴٰ� ������ K�ð��� �ȴٸ�
		if (Time == K) 
			break; // while Ż��

		Die(Time); // ���� �������� Ȯ��
		Active(Time); // Ȱ���ϴ� �������� Ȯ��
		Time++;
	}
	int Count = 0;
	for (int i = 0; i < V.size(); i++) {
		if (V[i].state == false) // �׾��ִ� ������ ��
			Count++;
		if (V[i].Die_time == K) // ���� �ð��� ������ �ð��� ��ġ�� ��
			Count++;
		if (V[i].Alive_time == K + 1) // ����ִ� �ð��� ������ �ð����� 1�ð� �� �������� ��
			Count++;
	}
	// �� �������� ���� ���ƾ� �� ������ ������ ���ش�.
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
	c++ ǥ�� ��Ʈ������ c ǥ�� ��Ʈ����� ������ ����� ���� ��
	����ȭ ���� ���θ� ������

	 */
	ios::sync_with_stdio(false);
	// ���α׷��� ����ڿ��� �Է��� �䱸�ϱ� ���� output�� flush�ȴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();
	return 0;
}
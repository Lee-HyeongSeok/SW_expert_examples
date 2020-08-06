#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_SIZE 12 // 1 <= �ھ��� �ִ�� <= 12
vector <pair<int, int>> v;
int vector_size; // ����ڰ� �Է��� �ִ� ���� ��
int T, N; // �׽�Ʈ ���̽�, ������� ������
int core_cnt, line_len = 0; // �ھ� ����, ���� ����
int map[MAX_SIZE][MAX_SIZE]; // �ھ�� ���� ��ŷ�ϱ� ���� �迭
int visited[MAX_SIZE][MAX_SIZE]; // �湮������ ��ŷ�ϱ� ���� �迭

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// ���� �ε���, ���� ��, �ھ� ��, Ž�� Ƚ��
void Processing(int index, int line, int core, int ex) {

	// �� Ž���ص� ����� �ھ��� ������ŭ ������ �� ���� ��
	if (core_cnt > vector_size - ex + core)
		return;

	// �ھ ��� Ž������ ��
	if (ex == vector_size) { 

		// ����� �ھ��� ���� ���� ���� �ھ �������� �� �������ش�.
		if (core_cnt < core) {
			core_cnt = core;
			line_len = line;
		}
		// ����� �ھ��� ������ ����, ������ ���̰� ª�� ��� �����Ѵ�.
		else if (core_cnt == core) {
			if (line_len > line)
				line_len = line;
		}
		return;
	}

	int temp[12][12] = { 0 };

	// visited[][]�� �������� �������� ���� ���� 0�� setting
	// temp 2���� �迭�� �ڽ��� �� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = visited[i][j];
		}
	}

	// vector pair ���� v�� �Ѹ��� ������ ��ǥ�� ������
	// index = ���� �ε���, 0���� ����
	for (int i = 0; i < 4; i++) {
		bool flag = true;
		int ix = 0;
		int iy = 0;
		int cnt = 0;

		// Ž���� ��
		int x = v[index].first; // ���ڷ� ���޵� index�� �ش��ϴ� ���� ù ��° ��
		int y = v[index].second; // ���ڷ� ���޵� index�� �ش��ϴ� ���� �� ��° ��

		while (1) {
			ix = x + dx[i];
			iy = y + dy[i];

			if (ix < 0 || ix >= N || iy < 0 || iy >= N) break;

			// Ž���� ��ġ�� �ھ �����ϴ���, �̹� �湮�߾����� ����
			// �ھ �����ϰ� �̹� �湮������ flag�� false�� ����, while�� Ż��
			if (map[ix][iy] == 1 || visited[ix][iy] == 1) {
				flag = false;
				break;
			}
			// ���� if���� �ƴ϶��
			// �湮�߾����� ��ŷ
			visited[ix][iy] = 1;  
			cnt++; // ����
			
			// Ž���� ���� �ε����� ���� �˻��� ��ġ�� ����
			x = ix; 
			y = iy;
		}
		// Ž���� ��ġ�� �ھ �����ϰ� �̹� �湮���� ��
		// flag�� ���̶�� ���� ���������� ����(�Ѹ��̰ų� �ھ ������ ��)
		// �ٸ� ���� Ž��
		if (flag) {
			// �ٸ� ������ ���� index�� 1���� ��Ų��.
			// cnt �����ϴ� ���� : ���� ���� ���� ��쿡�� ����� ���� ���̸� �ǹ��Ѵ�. -> ���� ���̸� �Ѱ���
			// �ھ��� �� ����
			Processing(index + 1, line + cnt, core + 1, ex + 1);
		}
		// ����� ���� ���̰� ������ ���
		if (cnt != 0) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					// ������ ����� �ھ��� ��ġ�� �湮������ ǥ���ϴ� �迭�� ����
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
				// 0�� �� ��, 1�� �ھ �ǹ�
				// ��������� ũ�⸸ŭ ���� �ھ �����Ѵ�.
				cin >> map[i][j];

				// �ѿ��ִ� �ھ�� ������ ����� �ھ�� �����ϰ� ���ܽ�Ų��.
				// �Ѹ鿡 �ִ� �ھ�� ������ �ʿ� ���� �����̴�.
				if (j != 0 && i != 0 && j != N - 1 && i != N - 1) {
					// �Ѹ鿡 �ִ� �ھ �ƴ� ��ǥ���� vector�� pair�� �־��ش�.
					// �� �κи� ������ ���� ����� �˻��ϸ� �Ǳ� ����
					if (map[i][j] == 1) {
						v.push_back(make_pair(i, j));
					}
				}
			}
		}
		vector_size = (int)v.size(); // �Է��� ���� ũ�⸦ �����Ѵ�.
		Processing(0, 0, 0, 0); // �ε���, ������ ��, �ھ�, Ž�� Ƚ�� 0���� ����
		cout << '#' << t << ' ' << line_len << '\n';

		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		v.clear();
	}
	return 0;
}
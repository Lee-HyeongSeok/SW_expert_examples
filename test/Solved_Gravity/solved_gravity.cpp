#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<int> input_vector;
int N, M; // ���� ���� : N, ���� ���� : M

void init(int N, int M) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			input_vector.push_back(0);
		}
		map.push_back(input_vector);
	}
}

int Result() {
	int index = 0;
	// ���� ���ʿ� ���ڰ� �����ϴ� �ε����� ã�� ����
	// ���� ������ ���ڰ� �ִ� ���� ���� ������ ����
	while (1) {
		if (map[M - 1][index])
			break;
		else
			index += 1;
	}

	int cnt = 0;
	int max = 0;

	for (int i = M - 1; i >= 0; i--) {
		for (int j = index + 1; j < N; j++) {
			if (!map[i][j])
				cnt++;
		}
		if (max < cnt)
			max = cnt - 1; // �ϳ��� �� ���� ������ 1����
		cnt = 0;
	}
	return max;
}
int main() {
	int Test_case = 0; // �׽�Ʈ ���̽�
	int box_num = 0; // ������ ������ �Է¹ޱ� ���� ���� ����
	vector<int> box; // ������ ������ �����ϴ� ����
	int result = 0; // �ִ� ���� ���� �����ϱ� ���� ����

	cin >> Test_case;
	cin >> N >> M;

	init(N, M); // N by M ��� 0���� �ʱ�ȭ(���� ����� ����)
	
	for (int i = 0; i < Test_case; i++) {
		for (int j = 0; j < N; j++) { // ���� ���� ���̸�ŭ ������ ������ �Է� �޴´�.
			cin >> box_num;
			box.push_back(box_num); // ���Ϳ� ����
			box_num = 0; // �ʱ�ȭ
		}
		// �ʿ� ������ ������ �ش��ϴ� ��ŭ 1�� ǥ��, 0�� ������ ����ϱ� ���� ��
		for (int k = 0; k < N; k++) {
			for (int j = M - 1; j >= 0; j--) {
				if (box[k] >= 1) {
					map[j][k] = 1;
				}
				else {
					map[j][k] = 0;
				}
				box[k]--;
			}
		}
		result = Result();
		cout << result << endl;
	}
	
	for (int i = 0; i < M; i++) { // 8
		for (int j = 0; j < N; j++) { // 9
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	
	/*
	vector<vector<int>> vec;
	vector<int> input_vec;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			input_vec.push_back(j + 1);
		}
		vec.push_back(input_vec);
	}

	for (int i = 0; i < 10; i++) {
		cout << i + 1 << ": ";
		for (int j = 0; j < 10; j++) {
			cout << vec[i][j] << ' ';
		}
		cout << endl;
	}
	*/
}
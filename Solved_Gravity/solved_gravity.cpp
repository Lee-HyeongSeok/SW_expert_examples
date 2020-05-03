#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<int> input_vector;
int N, M; // 방의 가로 : N, 방의 세로 : M

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
	// 가장 왼쪽에 상자가 존재하는 인덱스를 찾는 동작
	// 가장 왼쪽의 상자가 최대 낙차 값을 가지기 때문
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
			max = cnt - 1; // 하나를 더 세기 때문에 1감소
		cnt = 0;
	}
	return max;
}
int main() {
	int Test_case = 0; // 테스트 케이스
	int box_num = 0; // 상자의 개수를 입력받기 위한 변수 선언
	vector<int> box; // 상자의 개수를 저장하는 벡터
	int result = 0; // 최대 낙차 수를 저장하기 위한 변수

	cin >> Test_case;
	cin >> N >> M;

	init(N, M); // N by M 행렬 0으로 초기화(낙차 계산을 위함)
	
	for (int i = 0; i < Test_case; i++) {
		for (int j = 0; j < N; j++) { // 방의 가로 길이만큼 상자의 개수를 입력 받는다.
			cin >> box_num;
			box.push_back(box_num); // 벡터에 삽입
			box_num = 0; // 초기화
		}
		// 맵에 상자의 개수에 해당하는 만큼 1로 표시, 0은 낙차를 계산하기 위한 것
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
## * S/W expert 문제해결 Self Study Book 1   
#### * 대표 문제. Gravity 해결하기   
#### * 사용 환경 : visual studio 2015   


#### * 문제   

		* 상자들이 쌓여있는 방이 있다.   
		* 방이 오른쪽으로 90도 회전하여 상자들이 중력의 영향을 받아 낙하한다고 할 때   
		* 낙차가 가장 큰 상자를 구하여 그 낙차를 출력하라   
#### * 입력   
		* 첫 번째 줄에 test case의 수 T(1 <= T <= 100)가 주어진다.   
		* 각 케이스의 첫째 줄에 방의 가로 길이 N(2 <= N <= 100)과 세로 길이 M(2 <= M <= 100)이 주어진다.   
		* 다음 줄에는 N개의 상자 들이 쌓여 있는 높이 H(0 <= H <= M)가 주어진다.   
#### * 출력   
		* 낙차가 가장 큰 값을 출력 한다.   

#### * 입력 예시   
1	테스트 케이스 T의 개수   
9 8	방의 가로 길이 N, 방의 세로 길이 M   
7 4 2 0 0 6 0 7 0	상자들이 쌓여 있는 높이   

#### * 출력 예시   
7   

#### * 문제 힌트   
		* 2차원 배열 선언   
		* 벡터 클래스를 사용하여 100-입력개수 만큼의 메모리 활용   
		* 상자가 있는 곳은 1로 표시, 벡터 클래스는 0을 NULL로 인식하기 때문에 조건문에서 조심해야 한다.   
				* if(map[][]) 형식으로 true and false로 검사해야한다.   
		* 가장 위에 있는 상자만이 최대 낙차를 가질 수 있다는 특징을 이용한다.    

#### * 전체 코드   

```cpp
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
}
```
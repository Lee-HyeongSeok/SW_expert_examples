#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
첫 줄에는 총 테스트 케이스 T가 주어짐
지도의 한 변크기인 N, N은 최대 20
경사로 길이 X가 주어짐
다음 N개의 줄에는 N by B 크기의 지형 정보가 주어짐 

*/

#define MAX 20

int Map[MAX][MAX]; // 전역 배열은 전부 0으로 기본 초기화
int height[MAX]; // 활주로 높이를 계산할 때 사용 
bool state = true; // 각 활주로에 대한 사용 여부를 bool 대수로 나타냄 
int N, x; // 전체 맵 크기, 활주로 길이(높이는 1로 가정)

// 절대 값 계산 함수 
int abs(int a) {
	return a > 0 ? a : -a;
}

// height 배열에서 index s부터 e까지 지역이 평평한지 확인
bool isFlatBetween(int s, int e) {
	// 경계값을 넘는 경우
	if (s < 0 || N <= e)
		return false;
	// 높이가 다른것이 하나라도 있으면 평평하지 않은 것
	for (int i = s; i < e; i++) {
		if (height[i] != height[i + 1])
			return false;
	}
	return true;
}

bool canRunway() {
	// 높이 차이가 2이상인 경우 활주로 성립 안됨
	for (int i = 0; i < N - 1; i++) {
		if (abs(height[i] - height[i + 1]) >= 2) {
			return false;
		}
	}
	// 경사로와 평지가 겹치는 경우를 조사하기 위함 
	// 오른쪽으로 올라가는 경사로 배치 여부 확인
	bool * upSlope = (bool*)malloc(N);
	// 오른쪽으로 내려가는 경사로 배치 여부 확인
	bool * downSlope = (bool*)malloc(N);

	// 모든 경사로를 초기화
	for (int i = 0; i < N; i++) {
		upSlope[i] = downSlope[i] = false;
	}
	// 높이 차이가 1인데 경사로를 설치할 수 없는 경우 활주로 성립 안됨 
	for (int i = 0; i < N - 1; i++) {
		if (height[i] + 1 == height[i + 1]) {
			// i번째 지형이 낮은경우 UpSlope 경사로는 i번째부터 왼쪽으로 x개 설치
			// ex) 1 1 2 2 2 2 이고, 경사로 길이가 2라면 3번째 이전에 1, 2번째에 경사로 설치됨
			int s = i - x + 1;
			int e = i;

			// s부터 e까지 영역이 평평한지 확인
			if (isFlatBetween(s, e)) {
				// s부터 e까지 순회하면서
				for (int j = s; j <= e; j++) {
					upSlope[j] = true;
				}
			}
			else
				return false; // upSlope인데 경사로를 설치할 수 없다면
		}
		else if (height[i] - 1 == height[i + 1]) {
			// i번째 지형이 높은경우 DownSlope 경사로는 i+1번째부터 오른쪽으로 x개 설치
			// ex) 2 2 1 1 1 1 이고, 경사로 길이가 2라면 3번째부터 4번째까지 경사로 설치됨
			int s = i + 1; // 높이차이 나는 곳+1번째부터
			int e = i + x; // 경사로를 설치했을 때 길이까지

			// 경사로를 설치할 수 있는지 s에서 e까지 평평한지 확인
			if (isFlatBetween(s, e)) {
				for (int j = s; j <= e; j++) {
					downSlope[j] = true;
				}
			}
			else
				return false;
		}
	}

	// 경사로가 설치되는 위치가 겹치는지 확인
	for (int i = 0; i < N; i++) {
		if (upSlope[i] && downSlope[i])
			return false; // 경사로 겹치면 활주로 성립 안됨
	}
	return true; // 모두 평평한 경우 활주로 성립 
}
void input_Runway() {
	
	// n by n 행렬
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &Map[i][j]); // 지형 높이를 입력 받음
		}
	}
}

int Counting_Runway() {
	// 가로 탐색, 세로 탐색
	// 가로에 활주로 설치 가능 도로 카운팅 변수
	// 세로에 활주로 설치 가능 도로 카운팅 변수 
	int rowCnt, colCnt;
	rowCnt = colCnt = 0;

	// 가로 탐색
	// 활주로 설치 가능 높이를 탐색하기 위해 맵의 각 행을 height 배열에 삽입 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			height[j] = Map[i][j];
		}
		if (canRunway()) {
			rowCnt++;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			height[j] = Map[j][i];
		}
		if (canRunway()) {
			colCnt++;
		}
	}
	return rowCnt + colCnt;
}

/*
이전에 작성했던 코드


// 절대 값 계산 함수 
int abs(int a) {
	return a > 0 ? a : -a;
}

void distance() {
	
	for (int i = 0; i < N-1; i++) {
		if (abs(height[i] - height[i + 1]) >= 2) {
			printf("높이가 2차이 나는 구간이 있어서 활주로 건설 불가\n");
			return;
		}

	}
	
	state = true;

	int i = 0, j = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (arr[i] != arr[j]) {
				// 높이가 차이나는 구간에 활주로를 설치해도 되는가?
				// 현재위치에서부터 높이가 차이가는 구간이 활주로를 놓을수있는가, 차이나는 인덱스-현재위치가 활주로 길이보다 안된다면 활주로건설 불가
				if ((j + x < N - 1) && (j-i) >= x) {
					i = j; // 높이 차가 나는 곳으로 건너뜀
					state = true;
				}
				else {
					state = false;
				}
			}
		}
	}
	if (state == true)
		printf("활주로 건설 가능\n");
	else if(state == false)
		printf("활주로 건설 불가능\n");
}

void Solve() {

	// 가로 탐색
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			height[j] = Map[i][j]; // 각 가로의 지형 높이를 저장 
		}
		distance();
	}

	// 세로 탐색
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			height[j] = Map[j][i];
		}
		distance();
	}
}
*/

int main() {
	int T = 0;
	scanf("%d", &T); // 테스트 케이스 입력받음
	
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d", &N, &x); // 총 맵 길이와 활주로 길이 x를 입력받음(x는 2이상 4이하)
		input_Runway(); // 맵을 입력 받음 

		int totalRunway = Counting_Runway();
		printf("#%d %d\n", test_case, totalRunway);
	}
}
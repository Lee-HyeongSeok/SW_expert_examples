#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

/*
1. 가로 길이는 항상 1000이하
2. 각 빌딩 높이는 최대 255
3. 맨 왼쪽, 맨 오른쪽 두칸은 건물이 지어지지 않음 00으로 시작해서 00으로 끝나야 함 
*/

#define MAX 1000 // 가로 길이

int N; // 각 테스트 케이스 마다의 입력 데이터 개수
int Map[MAX]; // 맵

void init() {
	for (int i = 0; i < MAX; i++) {
		Map[i] = 0;
	}
}
void InputData() {
	for (int i = 0; i < N; i++) {
		scanf("%d", &Map[i]); // N개(세대 수)만큼 높이를 입력 받음
	}
}

// 현재 건물이 조망권을 가질 수 있는지 없는지 판단 
bool Checking_View(int location) {
	// (현 위치 - 2)부터 시작하여 현위치를 제외한 (현위치 + 2) 인덱스까지 검사
	// 현 위치 건물 높이보다 더 큰 건물이 존재하면 현 위치에 건물 모든 세대는 조망권을 가지지 못함
	for (int i = (location - 2); i <= (location + 2); i++) {
		// 현재 위치 기준 -2에서 +2 인덱스 사이 건물들 중에 현재 건물 높이보다 하나라도 큰 건물이 있다면
		// 자기 자신 제외 i != location
		if (Map[location] < Map[i] && i != location)
			return false; // 현재 건물은 조망권을 가질 수 없음
	}
	// 현재 위치 기준 -2에서 +2 인덱스 사이 건물들 중에 현재 건물 높이가 인접 건물들 보다 가장 크다면
	return true; // 조망권을 가질 수 있음
}

int Counting_View(int location) {
	int max = 0; 

	// (현위치-2) ~ (현위치+2) 까지 높이를 순회
	// 높이를 순회하면서 현위치의 높이를 제외한 나머지 위치들의 높이 중 가장 큰 값을 찾아냄
	for (int i = (location - 2); i <= (location + 2); i++) {
		if (i != location) // 자기 자신을 제외한 순회
			if (Map[i] > max) // 가장 큰 값을 찾음
				max = Map[i];
	}
	return Map[location] - max;
}

// 각 건물들의 높이가 저장된 배열을 순회하는 함수
void Finding_View() {
	int view = 0; // 조망권이 확보된 세대 수

	// 맨 왼쪽 두 칸과 맨 오른쪽 두 칸에는 건물이 지어지지 않는다는 전제로
	// 인덱스 2부터 검사하여 N-3 인덱스 까지만 검사하면 된다.
	for (int i = 2; i < N - 2; i++) {
		if (Checking_View(i)) { // 각 건물 순회하면서 조망권을 가질 수 있는 건물인지 확인
			// 조망권을 가질 수 있는 건물이라면 몇개의 세대가 가질 수 있는지 확인 
			view += Counting_View(i); // 조망권이 확보된 세대 수를 더한다.
		}
	}
	printf("%d\n", view);
}

int main() {
	int T = 10; // 총 10개의 테스트 케이스가 주어짐 
	
	for (int test_case = 1; test_case <= T; test_case++) {
		init();
		scanf("%d", &N); // 각 테스트 케이스별로 세대 수 입력받음

		// 세대 수만큼 건물의 높이를 입력받는 함수
		InputData();
		printf("#%d ", test_case);
		Finding_View();
	}
	
}
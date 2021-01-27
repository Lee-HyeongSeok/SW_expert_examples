#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define MAX 100 // 상자의 가로, 세로 길이 지정

int height[MAX]; // 상자의 높이를 갖고있는 배열 
int maxIdx, minIdx;

void init() {
	for (int i = 0; i < MAX; i++) {
		height[i] = 0;
		maxIdx = minIdx = 0;
	}
}

// 상자의 높이를 입력 받는 함수 
void inputMap() {
	int val = 0;
	
	// 가로 길이 100개 만큼 상자의 높이를 입력 받는다.
	// 높이를 가로로 세운다.
	for (int i = 0; i < MAX; i++) {
		scanf("%d", &val);
		height[i] = val; // 상자의 높이를 삽입, 나중에 최고/최저값 찾기 유용
		
	}
}

// 현재 상자의 높이가 평탄한지 검사하는 함수
bool isFlatten() {
	for (int i = 0; i < MAX; i = i + 2) {
		if (height[i] - height[i + 1] > 0)
			return false;
	}
	return true;
}

void maxIndex() {
	int maxVal = 0;

	for (int i = 0; i < MAX; i++) {
		// maxVal보다 큰 값이 있다면
		if (maxVal < height[i]) {
			maxVal = height[i]; // maxVal을 더 큰값으로 교체
			maxIdx = i; // 해당 인덱스 저장(전역변수)
		}
	}
}

void minIndex() {
	int minVal = height[0];
	minIdx = 0;

	for (int i = 1; i < MAX; i++) {
		if (minVal > height[i]) {
			minVal = height[i];
			minIdx = i;
		}
	}
}


void dumpBoxes(int dump) {
	// 덤프 횟수만큼 순회
	while (dump--) {
		// 평탄하지 않다면 덤프 작업 수행
		if (!isFlatten()) {
			maxIndex(); // maxIdx에 가장 큰 값의 인덱스를 저장한다.
			minIndex(); // minIdx에 가장 작은 값의 인덱스를 저장한다.

			// 가장 높은 상자를 가장 작은 상자로 보낸다.
			height[minIdx] += 1;
			height[maxIdx] -= 1;
		}
		// 평탄해지면 탈출
		else if (isFlatten())
			break;
	}
}

void Score() {
	int result = 0;
	// max, min 값을 탐색
	maxIndex();
	minIndex();

	// 최고점과 최저점의 차이
	result = height[maxIdx] - height[minIdx];
	printf(" %d", result);
}


int main() {
	int dump = 0; // 덤프 횟수를 입력 받는다.

	for (int test_case = 1; test_case <= 10; test_case++) {
		init(); // 배열 초기화 
		scanf("%d", &dump);

		inputMap(); // 상자 높이를 입력 받는다.
		dumpBoxes(dump); // 덤프
		printf("#%d", test_case);
		Score(); // 점수 출력
		printf("\n");
	}

	return 0;
}
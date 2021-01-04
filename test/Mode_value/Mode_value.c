#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 0점 이상 100점 이하의 값 
#define MAX 101

int score[MAX];

void input_Data() {
	int score_Data = 0;
	// 1000명의 데이터를 입력 받음
	for (int i = 0; i < 10; i++) {
		scanf("%d", &score_Data);
		if (score_Data >= 0 && score_Data <= MAX-1) {
			// 점수의 개수를 세는 부분
			score[score_Data] += 1; // 학생의 점수를 인덱스로 하여 1씩 증가
		}
	}
}

void Print() {
	for (int i = 0; i < MAX; i++) {
		printf("index : %d, value : %d\n", i, score[i]);
	}
}

void Max_Value() {
	int max = 0;
	int index_score = 0;

	// 0에서 100까지 순회
	for (int i = 0; i < MAX; i++) {
		// 최빈값이 이전에 max에 저장된 값보다 크다면
		// 제일 큰 최빈값을 찾는 동작
		if (score[i] >= max && index_score < i) {
			index_score = i; // 점수를 index_score에 저장
			max = score[i]; // 최빈값을 max에 저장, 더 큰 최빈값을 찾기 위함
		}
	}
	printf("최빈값 : %d", index_score);
}

int main() {
	int T = 0;
	scanf("%d", &T);
	input_Data();
	Max_Value();
}
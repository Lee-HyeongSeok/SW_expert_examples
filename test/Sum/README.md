## Sum, 2차원 배열 다루기   

***

#### 1. 문제 

100 by 100 2차원 배열이 주어질 때, 

> * 각 행의 합   
>
> * 각 열의 합
>
> * 각 대각선의 합

-> 이 중 최댓값을 구하는 프로그램 작성  



**[제약 사항]**

총 10개의 테스트 케이스가 주어진다.

배열의 크기는 100X100으로 동일하다.

각 행의 합은 integer 범위를 넘어가지 않는다.

동일한 최댓값이 있을 경우, 하나의 값만 출력한다.
 
**[입력]**

각 테스트 케이스의 첫 줄에는 테스트 케이스 번호가 주어지고 그 다음 줄부터는 2차원 배열의 각 행 값이 주어진다.

**[출력]**

\#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 테스트 케이스의 답을 출력한다.

#### 2. 코드

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define T 10 // 주어진 테스트 케이스 10개
#define MAX 100 // 주어진 2차원 배열의 크기

int Arr[MAX][MAX];
int max_value;

// 행 탐색
void FindRow(){
	int sum = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			sum += Arr[i][j]; // 행 탐색
		}
        // 각 행의 합마다 최대값 조사
		if (max_value < sum)
			max_value = sum;
		sum = 0;
	}
}
// 열 탐색
void FindCol() {
	int sum = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			sum += Arr[j][i]; // 열 탐색
		}
        // 각 열의 합마다 최대값 조사
		if (max_value < sum)
			max_value = sum;
		sum = 0;
	}
}

void CrossLeftDown() {
	int sum = 0;
	// 왼쪽 상단부터 오른쪽 하단 대각선의 합
	for (int i = 0; i < MAX; i++) {
		sum += Arr[i][i];
	}
	if (max_value < sum)
		max_value = sum;
}

void CrossLeftUp() {
	int sum = 0;
	// 왼쪽 하단부터 오른쪽 상단 대각선의 합 
	// 전치 행렬
	for (int i = MAX - 1; i >= 0; i--) {	
		sum += Arr[MAX - (i + 1)][i];
	}
	if (max_value < sum)
		max_value = sum;
}

void InputMatrix() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			scanf("%d", &Arr[i][j]);
		}
	}
}
int main() {

	for (int test_case = 1; test_case <= T; test_case) {
		InputMatrix();
		FindRow();
		FindCol();
		CrossLeftDown();
		CrossLeftUp();
		printf("#%d %d\n", test_case, max_value);
		max_value = 0;
	}
	return 0;
}

```



출처 : SW Expert Academy

 




#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 28 // N의 개수는 8이상 28이하 정수, N은 4의 배수
#define MAX_DEC 100 // 10진수 저장 배열 크기 지정
#define DIV 4 // 4개의 면을 의미, 하나의 면에 들어갈 숫자들은 DIV로 나눈 몫이 됨

// A~F를 10부터 15까지 정의
enum Hex {
	A=10, B, C, D, E, F
};

// A ~ F(10 ~ 15)
int Value[MAX]; // 0이상 F 이하의 16진수가 주어진다.
int Binary[DIV*DIV]; // 4자리수, 4비트이므로 총 16개의 비트가 산출된다.
int N, K; // 숫자의 개수 N, 크기 K가 주어진다.

// 16진수 배열에 사용자 입력값을 입력받는 함수
void inputValue() {
	char data; // 사용자에게 입력 받을 변수

	// N개 만큼 숫자를 입력 받는다.
	for (int i = 0; i < N; i++) {
		scanf(" %c", &data);

		switch (data) {
		case 'A':
			Value[i] = A;
			break;
		case 'B':
			Value[i] = B;
			break;
		case 'C':
			Value[i] = C;
			break;
		case 'D':
			Value[i] = D;
		case 'E':
			Value[i] = E;
			break;
		case 'F':
			Value[i] = F;
			break;
		default:
			Value[i] = data - '0';
			break;
		}
	}
}

// 마지막 자리 인덱스를 받아서 m개씩 16진수를 10진수로 변환하는 함수
void FixedBinary(int index) {
	int temp = 0;
	int idx = N - 1;

	// index-2 부터 index까지 순회
	for (int i = index; i >= (index-2); i--) {
		temp = Value[i];
		
		// 2진수로 변환
		for(int j=0; j<4; j++){
			if (temp) {
				Binary[idx--] = temp % 2;
				temp /= 2;
			}
			else {
				Binary[idx--] = 0;
			}
		}
	}
	printf("\n");
	for (int i = 0; i < N; i++) {
		printf("%d", Binary[i]);
	}
	printf("\n");
}

void PickedHEX() {
	for (int i = 0; i < N; i++) {
		// 4개의 면 중에 1개의 면에 들어갈 숫자의 개수만큼 끊어낸다.
		// N이 12개라면, 3개씩 끊어낸다.
		if ((i + 1) % (N / DIV) == 0) {
			FixedBinary(i);
		}
	}
}

void printValue() {
	printf("\n");
	for (int i = 0; i < N; i++) {
		printf("%d ", Value[i]);
	}
}

int main() {
	int T = 0;

	scanf("%d", &T); // 테스트 케이스 입력 받는다.

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d", &N, &K); // N과 K를 입력 받는다.

		// 배열에 사용자 입력값을 입력받는다.
		inputValue();
		printValue();
		printf("\n");

		// 회전하기 전 4개의 면에 대해 HEX 값을 나누어 선택하는 동작
		PickedHEX();

		// 
	}
}
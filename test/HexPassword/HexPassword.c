#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 28 // N의 개수는 8이상 28이하 정수, N은 4의 배수
#define MAX_DEC 100 // 10진수 저장 배열 크기 지정
#define DIV 4 // 4개의 면을 의미, 하나의 면에 들어갈 숫자들은 DIV로 나눈 몫이 됨

// A~F를 10부터 15까지 정의
enum Hex {
	A=10, B=11, C=12, D=13, E=14, F=15
};

// A ~ F(10 ~ 15)
int Value[MAX]; // 0이상 F 이하의 16진수가 주어진다.
int Binary[DIV*DIV]; // 4자리수, 4비트이므로 총 16개의 비트가 산출된다.
int Dec[MAX_DEC]; // 16진수 -> 10진수로 변환한 각 면의 수를 저장하는 배열
int N, K; // 숫자의 개수 N, 크기 K가 주어진다.


void init() {
	for (int i = 0; i < DIV*DIV; i++) {
		Binary[i] = 0;
	}
}

void initDec() {
	for (int i = 0; i < MAX_DEC; i++) {
		Dec[i] = 0;
	}
}

void initValue() {
	for (int i = 0; i < N; i++) {
		Value[i] = 0;
	}
}

void RotationArray() {
	int temp = 0;

	temp = Value[N - 1];
	// 0부터 N개의 숫자 까지만 회전시킨다.
	for (int i = N - 1; i > 0; i--) {
		Value[i] = Value[i - 1];
	}

	Value[0] = temp;
}

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
			break;
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

// FixedBinary() 함수로부터 변환된 10진수를 인자로 전달받는다.
// 전달받은 10진수를 중복없이 Dec 배열에 삽입한다.
// 중복제거, 정렬을 한번에 수행
void InsertDec(int data) {
	// 10진수를 저장하는 배열을 순회
	for (int i = 0; i < MAX_DEC; i++) {
		// 인자로 전달받은 10진수가 배열에 이미 존재한다면
		if (data == Dec[i]) {
			return; // 중복 발생 시 함수 종료
		}
	}

	// 인자로 전달받은 10진수가 배열에 존재하지 않아 함수가 종료되지 않는 경우 동작하는 코드
	for (int i = 0; i < MAX_DEC; i++) {
		if (data > Dec[i]) {
			for (int j = MAX_DEC; j > i; j--) {
				Dec[j] = Dec[j - 1];
			}
			Dec[i] = data;
			break;
		}
	}
}

// 마지막 자리 인덱스를 받아서 m개씩 16진수를 10진수로 변환하는 함수
void FixedBinary(int index) {
	int temp = 0;
	int idx = 15; // 16비트 자리수, 맨 뒤에부터 채우기 위함 

	// 정해진 구간 순회
	for (int i = index; i >= (index-(N/DIV-1)); i--) {
		temp = Value[i]; // F535
		
		// 2진수로 변환
		for(int j=0; j<4; j++){
			if (temp) {
				Binary[idx--] = temp % 2;
				temp /= 2;
			}
			else if(temp == 0){
				Binary[idx--] = 0;
			}
		}
	}
	
	int dec = 0;
	int mult = 1;

	// 2진수를 10진수로 바꾸는 부분
	for (int i = 15; i >= 0; i--) {
		dec += (Binary[i] * mult);
		mult *= 2;
	}

	// 변환한 10진수를 배열에 삽입한다.
	InsertDec(dec);
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
	for (int i = 0; i < MAX_DEC; i++) {
		if(Dec[i])
			printf("%d\n", Dec[i]);
	}
}

int main() {
	int T = 0;

	scanf("%d", &T); // 테스트 케이스 입력 받는다.

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d", &N, &K); // N과 K를 입력 받는다.

		// 배열에 사용자 입력값을 입력받는다.
		inputValue();

		// 회전하기 전 4개의 면에 대해 HEX 값을 나누어 선택하는 동작
		// 내부에 16진수를 10진수로 변환하여 Dec 배열에 저장하는 함수 내장 
		// 한 면에 들어가는 숫자들 개수 -1만큼 회전하면 초기 숫자들로 돌아온다.
		for (int rotation = 0; rotation < (N / DIV); rotation++) {
			PickedHEX();

			// 배열 회전 코드
			RotationArray();

			// Binary배열 초기화
			init();

			// 입력 받은 16진수를 숫자로 나타낸 배열 Value를 출력 
			printf("------%d 회전------\n", rotation);
			printValue();
			printf("\n");
		}

		// K번째로 큰 수 출력
		printf("#%d %d\n", tc, Dec[K-1]); // 테스트 케이스 출력 

		initDec();
		initValue(); // Value 배열 초기화
	}
}
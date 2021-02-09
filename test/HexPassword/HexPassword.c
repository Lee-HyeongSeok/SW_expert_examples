#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 28 // N�� ������ 8�̻� 28���� ����, N�� 4�� ���
#define MAX_DEC 100 // 10���� ���� �迭 ũ�� ����
#define DIV 4 // 4���� ���� �ǹ�, �ϳ��� �鿡 �� ���ڵ��� DIV�� ���� ���� ��

// A~F�� 10���� 15���� ����
enum Hex {
	A=10, B, C, D, E, F
};

// A ~ F(10 ~ 15)
int Value[MAX]; // 0�̻� F ������ 16������ �־�����.
int initialValue[MAX]; // ��� ȸ���� ���ƴ��� Ȯ�� 
int Binary[DIV*DIV]; // 4�ڸ���, 4��Ʈ�̹Ƿ� �� 16���� ��Ʈ�� ����ȴ�.
int Dec[MAX_DEC]; // 10������ ��ȯ�� �� ���� 16�������� �����ϴ� �迭
int N, K; // ������ ���� N, ũ�� K�� �־�����.


void init() {
	// ó�� ���� ���� ���� ũ���� �迭�� �����Ѵ�.
	// ��� ȸ�� ���Ŀ� ó���� ���� ���� �������� Ȯ���Ͽ� ���α׷� ���Ḧ ����
	for (int i = 0; i < N; i++) {
		initialValue[i] = Value[i]; 
	}
}

// 16���� �迭�� ����� �Է°��� �Է¹޴� �Լ�
void inputValue() {
	char data; // ����ڿ��� �Է� ���� ����

	// N�� ��ŭ ���ڸ� �Է� �޴´�.
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

// FixedBinary() �Լ��κ��� ��ȯ�� 10������ ���ڷ� ���޹޴´�.
// ���޹��� 10������ �ߺ����� Dec �迭�� �����Ѵ�.
// �ߺ�����, ������ �ѹ��� ����
void InsertDec(int Value) {
	for (int i = 0; i < MAX_DEC; i++) {
		if (Dec[i] > 0) {
			
		}
	}
}

// ������ �ڸ� �ε����� �޾Ƽ� m���� 16������ 10������ ��ȯ�ϴ� �Լ�
void FixedBinary(int index) {
	int temp = 0;
	int idx = N - 1;

	// index-2 ���� index���� ��ȸ
	for (int i = index; i >= (index-2); i--) {
		temp = Value[i];
		
		// 2������ ��ȯ
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
	
	int dec = 0;
	int mult = 1;

	// 2������ 10������ �ٲٴ� �κ�
	for (int i = N - 1; i >= 0; i--) {
		dec += Binary[i] * mult;
		mult *= 2;
	}

	// ��ȯ�� 10������ �迭�� �����Ѵ�.
	InsertDec(dec);
}

void PickedHEX() {
	for (int i = 0; i < N; i++) {
		// 4���� �� �߿� 1���� �鿡 �� ������ ������ŭ �����.
		// N�� 12�����, 3���� �����.
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

	scanf("%d", &T); // �׽�Ʈ ���̽� �Է� �޴´�.

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d", &N, &K); // N�� K�� �Է� �޴´�.

		// �迭�� ����� �Է°��� �Է¹޴´�.
		inputValue();

		// �Է� ���� �ʱ� ���� �� �ٸ� �迭�� �����Ѵ�.
		init();

		// �Է� ���� 16������ ���ڷ� ��Ÿ�� �迭 Value�� ��� 
		printValue();
		printf("\n");

		// ȸ���ϱ� �� 4���� �鿡 ���� HEX ���� ������ �����ϴ� ����
		// ���ο� 16������ 10������ ��ȯ�Ͽ� Dec �迭�� �����ϴ� �Լ� ���� 
		PickedHEX();

		// 
	}
}
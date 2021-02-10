#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 28 // N�� ������ 8�̻� 28���� ����, N�� 4�� ���
#define MAX_DEC 100 // 10���� ���� �迭 ũ�� ����
#define DIV 4 // 4���� ���� �ǹ�, �ϳ��� �鿡 �� ���ڵ��� DIV�� ���� ���� ��

// A~F�� 10���� 15���� ����
enum Hex {
	A=10, B=11, C=12, D=13, E=14, F=15
};

// A ~ F(10 ~ 15)
int Value[MAX]; // 0�̻� F ������ 16������ �־�����.
int Binary[DIV*DIV]; // 4�ڸ���, 4��Ʈ�̹Ƿ� �� 16���� ��Ʈ�� ����ȴ�.
int Dec[MAX_DEC]; // 16���� -> 10������ ��ȯ�� �� ���� ���� �����ϴ� �迭
int N, K; // ������ ���� N, ũ�� K�� �־�����.


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
	// 0���� N���� ���� ������ ȸ����Ų��.
	for (int i = N - 1; i > 0; i--) {
		Value[i] = Value[i - 1];
	}

	Value[0] = temp;
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

// FixedBinary() �Լ��κ��� ��ȯ�� 10������ ���ڷ� ���޹޴´�.
// ���޹��� 10������ �ߺ����� Dec �迭�� �����Ѵ�.
// �ߺ�����, ������ �ѹ��� ����
void InsertDec(int data) {
	// 10������ �����ϴ� �迭�� ��ȸ
	for (int i = 0; i < MAX_DEC; i++) {
		// ���ڷ� ���޹��� 10������ �迭�� �̹� �����Ѵٸ�
		if (data == Dec[i]) {
			return; // �ߺ� �߻� �� �Լ� ����
		}
	}

	// ���ڷ� ���޹��� 10������ �迭�� �������� �ʾ� �Լ��� ������� �ʴ� ��� �����ϴ� �ڵ�
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

// ������ �ڸ� �ε����� �޾Ƽ� m���� 16������ 10������ ��ȯ�ϴ� �Լ�
void FixedBinary(int index) {
	int temp = 0;
	int idx = 15; // 16��Ʈ �ڸ���, �� �ڿ����� ä��� ���� 

	// ������ ���� ��ȸ
	for (int i = index; i >= (index-(N/DIV-1)); i--) {
		temp = Value[i]; // F535
		
		// 2������ ��ȯ
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

	// 2������ 10������ �ٲٴ� �κ�
	for (int i = 15; i >= 0; i--) {
		dec += (Binary[i] * mult);
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
	for (int i = 0; i < MAX_DEC; i++) {
		if(Dec[i])
			printf("%d\n", Dec[i]);
	}
}

int main() {
	int T = 0;

	scanf("%d", &T); // �׽�Ʈ ���̽� �Է� �޴´�.

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d", &N, &K); // N�� K�� �Է� �޴´�.

		// �迭�� ����� �Է°��� �Է¹޴´�.
		inputValue();

		// ȸ���ϱ� �� 4���� �鿡 ���� HEX ���� ������ �����ϴ� ����
		// ���ο� 16������ 10������ ��ȯ�Ͽ� Dec �迭�� �����ϴ� �Լ� ���� 
		// �� �鿡 ���� ���ڵ� ���� -1��ŭ ȸ���ϸ� �ʱ� ���ڵ�� ���ƿ´�.
		for (int rotation = 0; rotation < (N / DIV); rotation++) {
			PickedHEX();

			// �迭 ȸ�� �ڵ�
			RotationArray();

			// Binary�迭 �ʱ�ȭ
			init();

			// �Է� ���� 16������ ���ڷ� ��Ÿ�� �迭 Value�� ��� 
			printf("------%d ȸ��------\n", rotation);
			printValue();
			printf("\n");
		}

		// K��°�� ū �� ���
		printf("#%d %d\n", tc, Dec[K-1]); // �׽�Ʈ ���̽� ��� 

		initDec();
		initValue(); // Value �迭 �ʱ�ȭ
	}
}
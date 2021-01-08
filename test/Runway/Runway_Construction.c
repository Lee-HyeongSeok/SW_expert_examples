#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
ù �ٿ��� �� �׽�Ʈ ���̽� T�� �־���
������ �� ��ũ���� N, N�� �ִ� 20
���� ���� X�� �־���
���� N���� �ٿ��� N by B ũ���� ���� ������ �־��� 

*/

#define MAX 20

int Map[MAX][MAX]; // ���� �迭�� ���� 0���� �⺻ �ʱ�ȭ
int height[MAX]; // Ȱ�ַ� ���̸� ����� �� ��� 
bool state = true; // �� Ȱ�ַο� ���� ��� ���θ� bool ����� ��Ÿ�� 
int N, x; // ��ü �� ũ��, Ȱ�ַ� ����(���̴� 1�� ����)

// ���� �� ��� �Լ� 
int abs(int a) {
	return a > 0 ? a : -a;
}

// height �迭���� index s���� e���� ������ �������� Ȯ��
bool isFlatBetween(int s, int e) {
	// ��谪�� �Ѵ� ���
	if (s < 0 || N <= e)
		return false;
	// ���̰� �ٸ����� �ϳ��� ������ �������� ���� ��
	for (int i = s; i < e; i++) {
		if (height[i] != height[i + 1])
			return false;
	}
	return true;
}

bool canRunway() {
	// ���� ���̰� 2�̻��� ��� Ȱ�ַ� ���� �ȵ�
	for (int i = 0; i < N - 1; i++) {
		if (abs(height[i] - height[i + 1]) >= 2) {
			return false;
		}
	}
	// ���ο� ������ ��ġ�� ��츦 �����ϱ� ���� 
	// ���������� �ö󰡴� ���� ��ġ ���� Ȯ��
	bool * upSlope = (bool*)malloc(N);
	// ���������� �������� ���� ��ġ ���� Ȯ��
	bool * downSlope = (bool*)malloc(N);

	// ��� ���θ� �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		upSlope[i] = downSlope[i] = false;
	}
	// ���� ���̰� 1�ε� ���θ� ��ġ�� �� ���� ��� Ȱ�ַ� ���� �ȵ� 
	for (int i = 0; i < N - 1; i++) {
		if (height[i] + 1 == height[i + 1]) {
			// i��° ������ ������� UpSlope ���δ� i��°���� �������� x�� ��ġ
			// ex) 1 1 2 2 2 2 �̰�, ���� ���̰� 2��� 3��° ������ 1, 2��°�� ���� ��ġ��
			int s = i - x + 1;
			int e = i;

			// s���� e���� ������ �������� Ȯ��
			if (isFlatBetween(s, e)) {
				// s���� e���� ��ȸ�ϸ鼭
				for (int j = s; j <= e; j++) {
					upSlope[j] = true;
				}
			}
			else
				return false; // upSlope�ε� ���θ� ��ġ�� �� ���ٸ�
		}
		else if (height[i] - 1 == height[i + 1]) {
			// i��° ������ ������� DownSlope ���δ� i+1��°���� ���������� x�� ��ġ
			// ex) 2 2 1 1 1 1 �̰�, ���� ���̰� 2��� 3��°���� 4��°���� ���� ��ġ��
			int s = i + 1; // �������� ���� ��+1��°����
			int e = i + x; // ���θ� ��ġ���� �� ���̱���

			// ���θ� ��ġ�� �� �ִ��� s���� e���� �������� Ȯ��
			if (isFlatBetween(s, e)) {
				for (int j = s; j <= e; j++) {
					downSlope[j] = true;
				}
			}
			else
				return false;
		}
	}

	// ���ΰ� ��ġ�Ǵ� ��ġ�� ��ġ���� Ȯ��
	for (int i = 0; i < N; i++) {
		if (upSlope[i] && downSlope[i])
			return false; // ���� ��ġ�� Ȱ�ַ� ���� �ȵ�
	}
	return true; // ��� ������ ��� Ȱ�ַ� ���� 
}
void input_Runway() {
	
	// n by n ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &Map[i][j]); // ���� ���̸� �Է� ����
		}
	}
}

int Counting_Runway() {
	// ���� Ž��, ���� Ž��
	// ���ο� Ȱ�ַ� ��ġ ���� ���� ī���� ����
	// ���ο� Ȱ�ַ� ��ġ ���� ���� ī���� ���� 
	int rowCnt, colCnt;
	rowCnt = colCnt = 0;

	// ���� Ž��
	// Ȱ�ַ� ��ġ ���� ���̸� Ž���ϱ� ���� ���� �� ���� height �迭�� ���� 
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
������ �ۼ��ߴ� �ڵ�


// ���� �� ��� �Լ� 
int abs(int a) {
	return a > 0 ? a : -a;
}

void distance() {
	
	for (int i = 0; i < N-1; i++) {
		if (abs(height[i] - height[i + 1]) >= 2) {
			printf("���̰� 2���� ���� ������ �־ Ȱ�ַ� �Ǽ� �Ұ�\n");
			return;
		}

	}
	
	state = true;

	int i = 0, j = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (arr[i] != arr[j]) {
				// ���̰� ���̳��� ������ Ȱ�ַθ� ��ġ�ص� �Ǵ°�?
				// ������ġ�������� ���̰� ���̰��� ������ Ȱ�ַθ� �������ִ°�, ���̳��� �ε���-������ġ�� Ȱ�ַ� ���̺��� �ȵȴٸ� Ȱ�ַΰǼ� �Ұ�
				if ((j + x < N - 1) && (j-i) >= x) {
					i = j; // ���� ���� ���� ������ �ǳʶ�
					state = true;
				}
				else {
					state = false;
				}
			}
		}
	}
	if (state == true)
		printf("Ȱ�ַ� �Ǽ� ����\n");
	else if(state == false)
		printf("Ȱ�ַ� �Ǽ� �Ұ���\n");
}

void Solve() {

	// ���� Ž��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			height[j] = Map[i][j]; // �� ������ ���� ���̸� ���� 
		}
		distance();
	}

	// ���� Ž��
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
	scanf("%d", &T); // �׽�Ʈ ���̽� �Է¹���
	
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d", &N, &x); // �� �� ���̿� Ȱ�ַ� ���� x�� �Է¹���(x�� 2�̻� 4����)
		input_Runway(); // ���� �Է� ���� 

		int totalRunway = Counting_Runway();
		printf("#%d %d\n", test_case, totalRunway);
	}
}
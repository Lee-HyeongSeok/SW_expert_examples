#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define T 10 // �־��� �׽�Ʈ ���̽� 10��
#define MAX 100 // �־��� 2���� �迭�� ũ��

int Arr[MAX][MAX];
int max_value;

void FindRow(){
	int sum = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			sum += Arr[i][j];
		}
		if (max_value < sum)
			max_value = sum;
		sum = 0;
	}
}

void FindCol() {
	int sum = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			sum += Arr[j][i];
		}
		if (max_value < sum)
			max_value = sum;
		sum = 0;
	}
}

void CrossLeftDown() {
	int sum = 0;
	// ���� ��ܺ��� ������ �ϴ� �밢���� ��
	for (int i = 0; i < MAX; i++) {
		sum += Arr[i][i];
	}
	if (max_value < sum)
		max_value = sum;
}

void CrossLeftUp() {
	int sum = 0;
	// ���� �ϴܺ��� ������ ��� �밢���� �� 
	// ��ġ ���
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

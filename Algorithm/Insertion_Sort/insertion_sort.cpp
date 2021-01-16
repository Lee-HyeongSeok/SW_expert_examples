#include <iostream>

using namespace std;

#define MAX 100

class InsertionSort {
private:
	int input[MAX]; // ���ĵ� �����͸� �����ϱ� ���� �迭, �ִ� 100�� 
	int N; // �迭�� ũ�⸦ �Է¹ޱ� ���� ����

public : 
	// InsertionSort�� �⺻ ������, ��ü ����� ���ÿ� ���� ������ �ʱ�ȭ 
	InsertionSort() {
		
	}
	void init() {
		N = 0;
		for (int i = 0; i < MAX; i++) {
			input[i] = 0;
		}
	}
	// �������� ����
	void Sort() {
		int temp = 0;
		int i = 0;
		int j = 0;

		for (i = 1; i < N; i++) {
			temp = input[i];
			j = i - 1;

			// �ε��� ������ 0�̻��̰� temp�� ���� �ռ� �����ͺ��� ���� ��
			// ���� temp�� ���� �ڱ⺸�� ū ������ �� �κп� ��ġ���Ѿ� ��
			while ((j >= 0) && (temp < input[j])) {
				input[j + 1] = input[j];
				j = j - 1;
			}
			input[j + 1] = temp;
		}
	}
	// �迭�� ũ�⸦ ������ N�� �Է¹޴� �Լ�
	void setN() {
		cin >> N;
	}
	// �迭 �����͸� �Է¹ޱ� ���� �Լ�
	void InputData() {
		for (int i = 0; i < N; i++) {
			cin >> input[i];
		}
	}
	// ���ĵ� �迭�� ����ϱ� ���� �Լ� 
	void printResult() {
		for (int i = 0; i < N; ++i) {
			cout << input[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	int T = 0;
	cin >> T; // �׽�Ʈ ���̽� ������ �Է¹޴´�.
	InsertionSort obj; // �迭�� ó���� ��ü ���� 

	for (int test_case = 1; test_case <= T; test_case++) {
		obj.init();
		obj.setN(); // ���� ������ �������� ũ�⸦ �Է¹޴´�.
		obj.InputData(); // �迭 �����͸� �Է¹޴´�.
		obj.Sort(); // �迭 �����͸� �����Ѵ�.
		cout << "#" << test_case << " ";
		obj.printResult(); // ���ĵ� �迭 �����͸� ����Ѵ�.
	}
	return 0;
}
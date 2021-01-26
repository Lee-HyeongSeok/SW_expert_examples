#include <iostream>

using namespace std;

#define MAX 100

typedef int element;

class Stack {
private:
	element data[MAX];
	element top;

public:
	Stack() {
		top = -1;
	}
	void init() {
		for (int i = 0; i <= top; i++) {
			data[i] = 0;
		}
		top = -1;
	}
	int is_empty() {
		return (top == -1);
	}
	int is_full() {
		return (top == MAX - 1);
	}
	void push(element item) {
		if (is_full()) {
			cout << "���� ��ȭ ����" << endl;
			return;
		}
		data[++top] = item;
	}
	element pop() {
		if (is_full()) {
			cout << "���� ���� ����" << endl;
			exit(1);
		}
		return data[top--];
	}
	void printStackElement() {
		for (int i = top; i >= 0; i--) {
			cout << data[i] << " ";
		}
	}
};

int main() {
	Stack s; // ���� ��ü ����
	int T = 0;
	element data = 0;

	for (cin >> T; T--;) {
		s.init(); // ���� �ʱ�ȭ

		while (1) {
			cin >> data; // ����ڿ��� ������ �Է� ����

			// -1 �Է� �� while�� Ż��
			if (data == -1)
				break;

			s.push(data); // ������ ����
		}
		s.printStackElement();
	}
}
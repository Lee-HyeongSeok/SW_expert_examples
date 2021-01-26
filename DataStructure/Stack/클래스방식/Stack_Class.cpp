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
			cout << "스택 포화 에러" << endl;
			return;
		}
		data[++top] = item;
	}
	element pop() {
		if (is_full()) {
			cout << "스택 공백 에러" << endl;
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
	Stack s; // 스택 객체 생성
	int T = 0;
	element data = 0;

	for (cin >> T; T--;) {
		s.init(); // 스택 초기화

		while (1) {
			cin >> data; // 사용자에게 데이터 입력 받음

			// -1 입력 시 while문 탈출
			if (data == -1)
				break;

			s.push(data); // 데이터 삽입
		}
		s.printStackElement();
	}
}
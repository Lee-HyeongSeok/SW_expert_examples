#include <iostream>

using namespace std;

#define MAX 5 // 큐의 최대 사이즈 지정

typedef int element;

class QueueType {
private:
	int front;
	int rear;
	element data[MAX];

public:
	QueueType() {
		front = rear = 0;
	}
	void init() {
		front = rear = 0;
	}
	bool is_empty() {
		return front == rear;
	}
	bool is_full() {
		return ((rear + 1) % MAX == front);
	}
	void printQueueElement() {
		cout << "Queue(front = " << front << ", rear = " << rear << ")" << endl;
		if (!is_empty()) {
			int i = front;
			do {
				i = (i + 1) % MAX;
				cout <<" "<< data[i];

				if (i == rear)
					break;
			} while (i != front);
		}
		cout << endl;
	}

	void Enqueue(element value) {
		if (is_full()) {
			cout << "큐 포화 상태" << endl;
			exit(1);
		}
		rear = (rear + 1) % MAX;
		data[rear] = value;
	}

	element Dequeue() {
		if (is_empty()) {
			cout << "큐 공백 상태" << endl;
			exit(1);
		}
		front = (front + 1) % MAX;
		return data[front];
	}
};

int main() {
	int T = 0;
	element data = 0;
	QueueType q; // 큐 타입 객체 선언

	for (cin >> T; T--;) {
		q.init();

		while (!q.is_full()) {
			cin >> data;
			q.Enqueue(data);
			q.printQueueElement();
		}

		while (!q.is_empty()) {
			data = q.Dequeue();
			cout << "삭제된 원소 : " << data << endl;
			q.printQueueElement(); // 남은 원소 출력 
		}
	}
	return 0;
}


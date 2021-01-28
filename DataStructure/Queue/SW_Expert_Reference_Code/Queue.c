#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 100 // 큐 최대 크기 지정

int front; // 큐의 가장 앞쪽 인덱스를 가리키는 변수
int rear; // 큐의 가장 오른쪽 인덱스를 가리키는 변수
int queue[MAX]; // 자료를 삽입할 큐, 1차원 배열 구현

void QueueInit() {
	front = 0;
	rear = 0;
}

// 큐의 공백 상태 검출 함수
int QueueEmpty() {
	// 앞단의 인덱스와 뒷단의 인덱스가 같으면 큐에 삽입된 자료가 없다는 의미
	return (front == rear);
}

// 큐의 포화 상태를 검출하는 함수
int QueueFull() {
	// 뒷단의 인덱스 + 1을 MAX로 나누었을 때 떨어지는 수가 앞단의 인덱스라면
	// 큐는 포화 상태임을 의미
	if ((rear + 1) % MAX == front) {
		return 1;
	}
	return 0;
}

// 큐에 데이터를 삽입하는 함수
int QueueEnQueue(int value) {
	// 큐가 포화상태라면
	if (QueueFull()) {
		printf("Queue is full!");
		return 0; // 0 리턴 후 함수 종료
	}

	// 포화 상태가 아니라면
	// 큐의 뒷단에 값을 삽입하고
	queue[rear] = value;
	rear++; // 뒷단의 인덱스를 나타내는 변수를 증가 시켜준다.

	// 증가된 뒷단 인덱스를 의미하는 변수가 큐의 최대원소와 같으면
	if (rear == MAX)
		rear = 0; // 뒷단의 인덱스 변수를 0으로 초기화(원형 큐)

	return 1; // 삽입이 완료된 상태라면 1을 리턴 
}

// 큐에 데이터를 삭제하는 함수
int queueDequeue(int *value) {
	// 큐가 공백 상태라면
	if (QueueEmpty()) {
		printf("Queue is Empty!");
		return 0;
	}

	// 큐의 가장 앞단에 있는 데이터를 value에 저장
	*value = queue[front];
	front++; // front 증가

	// 데이터 삽입 시 : 0, 1, 2... 인덱스에 삽입
	// 데이터 삭제 시 : 3, 4, 5... 인덱스에 데이터들이 삭제
	// FIFO 방식으로 가장 먼저들어온 데이터가 가장 먼저 나간다는 방식

	// 가장 먼저들어온 데이터를 나타내는 front가 최대 원소 개수와 같아진다면
	if (front == MAX) {
		front = 0; // 0으로 초기화
	}
	return 1;
}

int main() {
	int T = 0; // 테스트 케이스 개수
	int N = 0; // 입력받을 데이터 개수
	int data = 0; // 큐에 삽입할 데이터

	for (scanf("%d", &T); T--;) {
		scanf("%d", &N); // 입력 받을 데이터 개수를 입력 받는다.

		QueueInit();
		for (int i = 0; i < N; i++) {
			scanf("%d", &data); // 사용자에게 데이터를 입력 받는다.
			QueueEnQueue(data); // 큐에 데이터 삽입
		}

		// 큐가 공백상태일 때 까지 순회
		while (!QueueEmpty()) {
			int value;
			if (queueDequeue(&value) == 1) {
				printf("%d ", value);
			}
		}
		printf("\n");
	}
	return 0;
}

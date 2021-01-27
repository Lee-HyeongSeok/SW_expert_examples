## **Stack - 스택 자료구조**

***



### **⚙ 스택의 특징**

- LIFO(Last in First Out) 후입 선출 방식
  - 가장 최근에 들어온 데이터가 먼저 출력 된다.
- 컴퓨터 시스템에서 함수를 호출할 때 사용한다.

![asd](https://user-images.githubusercontent.com/55940552/105873017-62fe3d80-603e-11eb-8ce2-3807ac59417a.PNG)   



### **⚙ 스택의 연산**

- Push() : 스택에 데이터를 삽입하는 연산
- Pop() : 스택에서 데이터를 제거하는 연산
  - 스택에서 완전히 삭제하면서 데이터를 반환한다.
- is_Empty() : 스택이 공백 상태인지 검사 하는 연산
- is_full() : 스택이 포화 상태인지 검사 하는 연산
- create() : 스택을 생성하는 연산
- peek() : 요소를 스택에서 삭제하지 않고 탐색하는 연산



### **⚙ 스택의 구현 - 1차원 배열을 통한 구현**

- 1차원 배열을 통한 구현
- 가장 최근에 입력된 자료를 가리키는 **top 변수**
  - 최근에 들어온 데이터를 stack[top]에 저장
- 스택이 공백 상태일 때(초기 상태) **top 변수**는 -1로 지정

![Untitled Diagram](https://user-images.githubusercontent.com/55940552/105874996-9a6de980-6040-11eb-9e61-bf0ceba15a56.png)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // 스택의 최대 크기 지정

typedef int element; // 데이터 자료형 지정
element stack[MAX]; // 1차원 배열
int top = -1;

// 스택 초기화 함수
void init() {
	for (int i = 0; i < MAX; i++) {
		stack[i] = 0;
	}
}

// 스택 공백상태 검출 함수
int is_Empty() {
	return (top == -1);
}

// 스택 포화상태 검출 함수
int is_full() {
	// 가장 최근에 들어온 값의 인덱스를 지정하는 top이 최대크기-1과 같으면
	// 스택에 최대 크기만큼 인덱스에 접근했다는 의미
	return (top == (MAX - 1)); 
}

// 스택에 데이터를 삽입하는 함수
void push(element item) {
	// 스택이 포화상태라면
	if (is_full()) {
		printf("스택 포화 상태\n");
		return; // 함수 종료
	}
	else
		stack[++top] = item; // top은 -1로 시작하므로 전위증가 후 데이터 삽입
}

// 스택에 데이터를 삭제하는 함수
element pop() {
	// 스택이 공백상태라면
	if (is_Empty()) {
		printf("스택 공백 상태\n");
		exit(1); // 프로그램 종료
	}
	else
		return stack[top--]; // 최상위 값을 리턴 후 top 변수를 후위감소
}

void printStackElement() {
	for (int i = top; i >= 0; i--) {
		printf("%d ", stack[i]);
	}
	printf("\n");
}

int main() {
	int T = 0;
	element data = 0; // 스택에 삽입할 데이터

	// 테스트 케이스 입력
	for (scanf("%d", &T); T--;) {
		init();
		while (1) {
			scanf("%d", &data);

			// -1 입력 시 데이터 입력 종료
			if (data == -1)
				break;

			push(data);
		}
		printStackElement(); // 스택의 모든 요소 출력, LIFO 방식
	}
}
```



### **⚙ 스택의 구현 - 구조체를 이용한 스택 구현**

- 1차원 배열과 top 변수를 가진 구조체 선언
- 각 함수마다 구조체 변수를 인자로 전달 받아서 처리

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 100 // 스택의 최대 크기 지정

typedef int element; // 데이터 형식 지정

// 1차원 배열을 구조체로 표현
typedef struct {
	element data[MAX];
	int top;
}StackType;


void init(StackType *s) {
	s->top = -1;
}

// 스택 공백 상태 검출 함수
// 인자로 전달된 구조체에 top 변수가 -1이면 공백 상태임을 의미
int is_empty(StackType * s) {
	return (s->top == -1);
}

// 스택 포화 상태 검출 함수 
int is_full(StackType * s) {
	return (s->top == (MAX - 1));
}

// 스택에 데이터를 삽입하는 함수
void push(StackType * s, element data) {
	// 인자로 전달받은 스택이 포화 상태라면
	if (is_full(s)) {
		printf("스택 포화 상태\n");
		return; // 함수 종료
	}
	// 포화 상태가 아니라면 데이터 삽입
	s->data[++(s->top)] = data;
}

// 스택에서 데이터를 삭제하는 함수
element pop(StackType * s) {
	if (is_empty(s)) {
		printf("스택 공백 상태\n");
		exit(1);
	}
	return s->data[(s->top)--]; // 데이터를 반환하면서 top변수를 감소 
}

void printStackElement(StackType * s) {
	for (int i = s->top; i >= 0; i--) {
		printf("%d ", s->data[i]);
	}
	printf("\n");
}
int main() {
	StackType s; // 스택 선언
	element data = 0;
	int T = 0;

	for (scanf("%d", &T); T--;) {
		init(&s); // 스택 초기화

		while (1) {
			scanf("%d", &data);

			// -1 입력 시 데이터 입력 종료
			if (data == -1)
				break;

			push(&s, data);
		}
		printStackElement(&s);
	}
}
```



### **⚙ 스택의 구현 - cpp 클래스를 이용한 구현**

- Stack을 클래스로 구현
- 클래스 내부 멤버 변수에는 데이터를 저장할 data[] 배열과 원소의 위치를 저장할 top 변수 존재

```c++
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
```


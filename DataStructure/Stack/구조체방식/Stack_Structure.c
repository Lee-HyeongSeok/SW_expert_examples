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
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // 리스트 최대 크기 지정

typedef int element; // 자료형 정의
typedef struct {
	element Arr[MAX]; // 리스트 정의
	int size; // 현재 리스트에 저장된 항목들의 개수
}ArrayList;

// 오류 처리 함수
void error(char *msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

// 리스트 초기화 함수
void init(ArrayList * L) {
	L->size = 0;
}

// 리스트 공백 상태 검출 함수
element is_empty(ArrayList * L) {
	// 리스트가 비어있으면 1, 그렇지 않으면 0 반환
	return (L->size == 0);
}

// 리스트 포화 상태 검출 함수
element is_full(ArrayList * L) {
	// size는 현재 인덱스 위치를 나타냄
	// size가 99라면 모든 인덱스에 접근된 것이므로 포화 상태임을 의미
	// 포화 상태일 시 1, 그렇지 않으면 0 반환
	return (L->size == MAX - 1);
}

// 인자로 전달한 pos 인덱스 위치에 값을 반환한다.
element get_entry(ArrayList * L, int pos) {
	// pos는 ArrayList의 인덱스 위치
	// 0보다 작거나 저장된 값의 인덱스보다 크다면 오류
	if (pos < 0 || pos >= L->size) {
		error("위치 오류");
	}
	return L->Arr[pos];
}

// 자료를 삽입 하는 함수
void insert(ArrayList * L, int pos, element item) {
	// 리스트가 포화 상태가 아니고 삽입 위치가 0보다 크거나 현재 사이즈 보다 작거나 같을 때
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		// 뒤에서부터 삽입
		for (int i = (L->size - 1); i >= pos; i--) {
			L->Arr[i + 1] = L->Arr[i]; // 삽입 위치 다음 요소들을 한칸씩 밀어낸다.
		}
		L->Arr[pos] = item; // 삽입 위치에 데이터 삽입
		L->size++; // 데이터 삽입 후 현재 항목 개수 증가
	}
}

// pos 위치에 데이터를 삭제하는 함수
element Delete(ArrayList * L, int pos) {
	element item;

	// 삭제하려는 데이터의 위치가 옳바르지 않을 때
	if (pos < 0 || pos >= L->size)
		error("위치 오류");

	item = L->Arr[pos]; // 삭제하려는 데이터 임시 저장

	// 삭제하려는 위치를 시작으로 배열의 마지막 항목까지 순회
	for (int i = pos; i < (L->size - 1); i++) {
		L->Arr[i] = L->Arr[i + 1]; // 앞으로 한 칸씩 당긴다.
	}
	L->size--; // 항목 개수 감소

	return item; // 삭제할 데이터 반환
}

// 리스트 출력 함수
void printArrayList(ArrayList * L) {
	for (int i = 0; i < L->size; i++) {
		printf("%d -> ", L->Arr[i]);
	}
	printf("\n");
}

int main() {
	ArrayList list;
	int T = 0;
	element pos = 0; // 사용자에게 입력받을 데이터 삽입 포지션
	element item = 0; // 사용자에게 입력받을 데이터

	// 테스트 케이스 입력 받음과 동시에 개수만큼 순회
	for (scanf("%d", &T); T--;) {
		init(&list);

		while (1) {
			scanf("%d %d", &pos, &item); // 데이터 삽입 포지션과 데이터 입력 받음

			// 사용자, -1입력 시 입력 종료
			if (item == -1)
				break;

			insert(&list, pos, item);
		}
		printArrayList(&list);
	}
	return 0;
}
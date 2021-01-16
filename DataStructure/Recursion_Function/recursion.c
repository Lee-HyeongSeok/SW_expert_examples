/*
재귀 : 자신을 정의할 때 자기 자신을 재참조하는 방법
주로 함수에 적용한 재귀 함수(Recursion Function)의 형태로 많이 사용된다.

입력
3 // 전체 테스트 케이스 수
9 // 수
12 // 수
20 // 수

결과
#1 9! = 362880
#2 12! = 479001600
#3 20! = 2432902008176640000
*/

#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>

long long factorial(int num) {
	if (num == 0) { // 재귀하는 인자가 0이라면
		return 1; // 1리턴, 재귀 탈출
	}
	else {
		return num * factorial(num - 1); 
		// ex) 7
		// 7 * factorial(6)
		// 7 * 6 * factorial(5)
		// 7 * 6 * 5 * factorial(4)
		// ...
		// return (7 * 6 * 5 * 4 * 3 * 2 * 1)
	}
}

int main(void) {
	int test_case;
	int T;
	int num;
	long long value;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case) {
		scanf("%d", &num);
		value = factorial(num);
		printf("#%d %d! = %lld\n", test_case, num, value);
	}
}
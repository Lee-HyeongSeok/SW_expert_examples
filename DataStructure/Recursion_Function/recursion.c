/*
��� : �ڽ��� ������ �� �ڱ� �ڽ��� �������ϴ� ���
�ַ� �Լ��� ������ ��� �Լ�(Recursion Function)�� ���·� ���� ���ȴ�.

�Է�
3 // ��ü �׽�Ʈ ���̽� ��
9 // ��
12 // ��
20 // ��

���
#1 9! = 362880
#2 12! = 479001600
#3 20! = 2432902008176640000
*/

#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>

long long factorial(int num) {
	if (num == 0) { // ����ϴ� ���ڰ� 0�̶��
		return 1; // 1����, ��� Ż��
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
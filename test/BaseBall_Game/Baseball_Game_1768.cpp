
#define N 4

typedef struct {
	int strike;
	int ball;
}Result;

extern Result query(int guess[]); // ����ü ���Ͻ�Ŵ/  �Խ�Ʈ�� ����ü = query(guess)ī��ɰŶ�
Result Compare(int key, int obj);
void init();

//int arr[N];

Result Compare(int key, int obj) {
	Result R1;
	R1.strike = 0;
	R1.ball = 0;

	int check[10] = { 0, };

	for (int i = 0; i < N; i++) {
		// �ڸ����� ���� ��� ���� �� ��Ʈ����ũ ó��
		if (key % 10 == obj % 10) {
			R1.strike++;
			// ���� �ڸ����� �����ϰԲ� �������
			//arr[N-(i+1)] = key%10; // ���� �ڸ���, ���ڸ� arr�迭�� �־���
		}
		// �ڸ����� ������ ���� �ٸ� ������ ��
		else {
			// check �迭�� �ڸ����� ǥ�����ش�.
			check[key % 10]++;
			check[obj % 10]++;
		}
		// ������ �ڸ����� üũ�ߴµ� 2�� �� ��� 
		// �ڸ����� �ٸ����� ���� ���ڰ� �ִٴ� �ǹ�
		if (check[key % 10] == 2) {
			R1.ball++;
		}
		if (check[obj % 10] == 2)
		{
			R1.ball++;
		}
		key /= 10;
		obj /= 10;
	}
	return R1;
}

bool num[9877];
int number[5040];
int index = 0;
bool flag = true;

void init(void) {
	if (flag) {
		flag = false;

		for (int i = 123; i <= 9876; i++) {
			int sub1 = i / 1000; // 1�� �ڸ�
			int sub2 = i % 1000 / 100; // 2�� �ڸ�
			int sub3 = i % 100 / 10; // 3�� �ڸ�
			int sub4 = i % 10; // 4�� �ڸ�

			// �� �κ� ���߿� �ٲ㺸��
			if (sub1 != sub2 && sub1 != sub3 && sub1 != sub4 && sub2 != sub3 && sub2 != sub4 && sub3 != sub4)
				number[index++] = i;

		}
	}
	for (int i = 0; i < index; i++)
		num[number[i]] = true;
}
void doUserImplementation(int guess[]) {
	init();

	while (1) {
		int ans;

		for (int i = 0; i < index; i++) {
			if (num[number[i]]) {
				ans = number[i];

				guess[0] = ans / 1000;
				guess[1] = ans % 1000 / 100;
				guess[2] = ans % 100 / 10;
				guess[3] = ans % 10;
				break;
			}
		}
		Result result = query(guess);

		if (result.strike == 4)
			break;
		else
			num[ans] = false;

		for (int i = 0; i < index; i++) {
			if (num[number[i]]) {
				Result cmp_result = Compare(ans, number[i]);

				if (result.strike != cmp_result.strike || result.ball != cmp_result.ball)
					num[number[i]] = false;
			}
		}
	}
}

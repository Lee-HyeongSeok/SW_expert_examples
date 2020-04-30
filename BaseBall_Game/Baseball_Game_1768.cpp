
#define N 4

typedef struct {
	int strike;
	int ball;
}Result;

extern Result query(int guess[]); // 구조체 리턴시킴/  게스트의 구조체 = query(guess)카면될거라
Result Compare(int key, int obj);
void init();

//int arr[N];

Result Compare(int key, int obj) {
	Result R1;
	R1.strike = 0;
	R1.ball = 0;

	int check[10] = { 0, };

	for (int i = 0; i < N; i++) {
		// 자리수와 숫자 모두 같을 때 스트라이크 처리
		if (key % 10 == obj % 10) {
			R1.strike++;
			// 남은 자리수만 추측하게끔 만드려고
			//arr[N-(i+1)] = key%10; // 같은 자리수, 숫자를 arr배열에 넣어줌
		}
		// 자리수는 같은데 서로 다른 숫자일 때
		else {
			// check 배열에 자리수를 표시해준다.
			check[key % 10]++;
			check[obj % 10]++;
		}
		// 위에서 자리수를 체크했는데 2개 일 경우 
		// 자리수는 다르지만 같은 숫자가 있다는 의미
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
			int sub1 = i / 1000; // 1의 자리
			int sub2 = i % 1000 / 100; // 2의 자리
			int sub3 = i % 100 / 10; // 3의 자리
			int sub4 = i % 10; // 4의 자리

			// 이 부분 나중에 바꿔보기
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

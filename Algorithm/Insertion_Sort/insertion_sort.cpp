#include <iostream>

using namespace std;

#define MAX 100

class InsertionSort {
private:
	int input[MAX]; // 정렬될 데이터를 저장하기 위한 배열, 최대 100개 
	int N; // 배열의 크기를 입력받기 위한 변수

public : 
	// InsertionSort의 기본 생성자, 객체 선언과 동시에 내부 데이터 초기화 
	InsertionSort() {
		
	}
	void init() {
		N = 0;
		for (int i = 0; i < MAX; i++) {
			input[i] = 0;
		}
	}
	// 오름차순 정렬
	void Sort() {
		int temp = 0;
		int i = 0;
		int j = 0;

		for (i = 1; i < N; i++) {
			temp = input[i];
			j = i - 1;

			// 인덱스 시작이 0이상이고 temp에 값이 앞선 데이터보다 작을 때
			// 현재 temp의 값을 자기보다 큰 데이터 앞 부분에 위치시켜야 함
			while ((j >= 0) && (temp < input[j])) {
				input[j + 1] = input[j];
				j = j - 1;
			}
			input[j + 1] = temp;
		}
	}
	// 배열의 크기를 결정할 N을 입력받는 함수
	void setN() {
		cin >> N;
	}
	// 배열 데이터를 입력받기 위한 함수
	void InputData() {
		for (int i = 0; i < N; i++) {
			cin >> input[i];
		}
	}
	// 정렬된 배열을 출력하기 위한 함수 
	void printResult() {
		for (int i = 0; i < N; ++i) {
			cout << input[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	int T = 0;
	cin >> T; // 테스트 케이스 개수를 입력받는다.
	InsertionSort obj; // 배열을 처리할 객체 선언 

	for (int test_case = 1; test_case <= T; test_case++) {
		obj.init();
		obj.setN(); // 삽입 정렬할 데이터의 크기를 입력받는다.
		obj.InputData(); // 배열 데이터를 입력받는다.
		obj.Sort(); // 배열 데이터를 정렬한다.
		cout << "#" << test_case << " ";
		obj.printResult(); // 정렬된 배열 데이터를 출력한다.
	}
	return 0;
}
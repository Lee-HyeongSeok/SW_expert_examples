## **Flatten**

***

### **🔑 Flatten  평탄화 문제**

- 높은 곳의 상자를 낮은 곳에 옮기는 방식으로 최고점, 최저점 간격을 줄이는 작업
- 평탄화를 모두 수행하고 나면, 최고점과 최저점의 차이가 최대 1 이내가 된다.
- 평탄화 작업을 위해 상자를 옮기는 작업 횟수에 제한이 걸려있을 때 제한된 횟수만큼 옮기는<br> 작업을 한 후 최고점과 최저점의 차이를 출력해라.  

![Untitled Diagram](https://user-images.githubusercontent.com/55940552/106024197-e1281600-610a-11eb-9f21-31996ecdb240.png)   



### **🔑 Flatten 문제 풀이**

- **처음에는 2차원 배열을 사용하여 높이를 입력 받은 만큼 1과 0으로 표시했다.**
  - 메모리 낭비
  - 연산 작업 시 n*n번의 접근이 필요
  - 효율성 감소
- **height[] 라는 배열을 이용하여 각 인덱스별 높이만 입력 받는다.**
  - 메모리 낭비 감소
  - 연산 작업 시 n 번의 접근만 필요
  - 효율성 증가
  - 접근 속도가 빠르다.

### **🔑 문제 해결 방법 - 1**

- 10개의 테스트 케이스가 고정되어 있다.
- 10개의 테스트 케이스를 순회하며 init() 함수를 통한 초기화 우선 실행
- dumpBoxes() 함수에 덤프 작업 횟수를 사용자에게 입력 받아서 인자로 전달.
- 테스트 케이스 출력
- 점수 계산 후 출력

```c
int main() {
	int dump = 0; // 덤프 횟수를 입력 받는다.

	for (int test_case = 1; test_case <= 10; test_case++) {
		init(); // 배열 초기화 
		scanf("%d", &dump);

		inputMap(); // 상자 높이를 입력 받는다.
		dumpBoxes(dump); // 덤프
		printf("#%d", test_case);
		Score(); // 점수 출력
		printf("\n");
	}

	return 0;
}
```



### **🔑 문제 해결 방법 - 2**

- dumpBoxes() 함수 내에서는 dump 횟수를 감소 시키면서 현재 모든 높이가 평탄한지 검사 - **isFlatten() 함수**
- 각 순회에서 최고점, 최저점에 해당하는 인덱스를 탐색 - **maxIndex(), minIndex() 함수**
- 덤프 횟수보다 빨리 평탄화 작업이 완료되었을 때를 위해 isFlatten() 함수로 평탄할 시 break로 while문 탈출

```c
// 현재 상자의 높이가 평탄한지 검사하는 함수
bool isFlatten() {
	for (int i = 0; i < MAX; i = i + 2) {
		if (height[i] - height[i + 1] > 0)
			return false;
	}
	return true;
}

void dumpBoxes(int dump) {
	// 덤프 횟수만큼 순회
	while (dump--) {
		// 평탄하지 않다면 덤프 작업 수행
		if (!isFlatten()) {
			maxIndex(); // maxIdx에 가장 큰 값의 인덱스를 저장한다.
			minIndex(); // minIdx에 가장 작은 값의 인덱스를 저장한다.

			// 가장 높은 상자를 가장 작은 상자로 보낸다.
			height[minIdx] += 1;
			height[maxIdx] -= 1;
		}
		// 평탄해지면 탈출
		else if (isFlatten())
			break;
	}
}
```



### **🔑 문제 해결 방법 - 3**

- 점수를 출력하기 위해 최고점과 최저점의 인덱스 탐색 후 maxIdx, minIdx 변수에 저장
- result 변수에 최고점과 최저점의 차를 저장
- 점수 출력

```c
void Score() {
	int result = 0;
	// max, min 값을 탐색
	maxIndex();
	minIndex();

	// 최고점과 최저점의 차이
	result = height[maxIdx] - height[minIdx];
	printf(" %d", result);
}
```



***

**[출처]**

[SW Expert Academy](https://swexpertacademy.com/main/learn/course/lectureProblemViewer.do)
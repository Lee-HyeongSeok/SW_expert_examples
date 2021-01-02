## SW expert 문제 해결   
***   

#### SW 문제를 해결하기 위한 5단계   
		1. 지문을 읽는다.   
		2. 문제를 이해한다 - 핵심 부분에서 정확히 요구하는 것 파악.   
		3. 문제를 풀어본다 - 노트에 손으로 문제를 풀어봄.   
		4. 풀이를 코딩한다 - 노트에 풀어본 내용을 소스코드로 코딩.   
		5. 디버깅, 검증 - 예외 발생 확인   

#### 꼭 파악해야 할 핵심 부분   
		1. 제한 시간   
		2. Big-O 계산   
		3. 제약사항 확인   

#### 1차원 배열   
		* 부분집합   
				* Left Shift 연산을 사용하여 모든 부분집합 탐색   
		![asd](https://user-images.githubusercontent.com/55940552/103454002-b375ca00-4d22-11eb-8316-e10e2e94f669.PNG)   

```c
	int arr[] = { 1, 2, 3, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < (1 << (n)); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				printf("%d", arr[j]);
			}
		}
		printf("\n");
	}
```   

#### 2차원 배열   
		* 탐색   
				1. 지그재그 탐색   
				![q](https://user-images.githubusercontent.com/55940552/103454052-5deded00-4d23-11eb-813a-d26ce1707dae.PNG)   

				2. 델타 이용, 4방향 탐색   
				![1](https://user-images.githubusercontent.com/55940552/103454132-30557380-4d24-11eb-8dfd-f06b5608cedc.PNG)   
				![2](https://user-images.githubusercontent.com/55940552/103454135-36e3eb00-4d24-11eb-9ab5-822d37c41b0b.PNG)   

				
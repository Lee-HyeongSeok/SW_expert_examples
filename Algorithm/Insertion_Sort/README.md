## Insertion Sort Algorithm

***

#### **문제** 

최대 100개의 데이터를 입력 받는 배열

오름차순 삽입 정렬



[입력]

1. 테스트 케이스 개수를 입력받는다.
2. 삽입 정렬할 데이터 크기를 입력 받는다.
3. 데이터 크기만큼의 데이터를 입력 받는다.



[출력]

#1 1 2 3 4 5 6 7 8 9 10

#2 1 2 3 4 5 6 



1. 현재 테스트 케이스 순번과 함께 배열의 결과를 오름차순으로 출력한다.
2. 테스트 케이스마다 개행 필수



#### **insertion sort Algorithm 분석**



* **알고리즘 흐름**

![삽입정렬](https://user-images.githubusercontent.com/55940552/104815852-a3013b80-585a-11eb-9459-9554679a7835.PNG)

* **sort 함수**

  ```c
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
  ```

* **시간복잡도**

  최악의 경우 : 역순일 경우

  ![1](https://user-images.githubusercontent.com/55940552/104815979-6d108700-585b-11eb-9b82-b949e8ef89e5.PNG)



***

출처 

[SW expert academy reference code](https://swexpertacademy.com/main/visualcode/main.do#/home/editor//)

[위키백과](https://ko.wikipedia.org/wiki/%EC%82%BD%EC%9E%85_%EC%A0%95%EB%A0%AC)
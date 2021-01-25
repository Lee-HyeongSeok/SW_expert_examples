## **특이한 자석**

***

### **🔑 문제**

- 4개의 자석 중 임의의 자석을 1 칸씩 K 번 회전 시킨다.
- 하나의 자석이 1 칸 회전할 때, 붙어 있는 자석은 서로 붙은 날의 자성과 다를 경우에만<br> 인력에 의해 반대 방향으로 1 칸 회전된다.
- 모든 회전이 끝난 후 점수를 계산한다.
  - N 번 자석의 빨간 화살표 위치에 날의 자성이 N 극이면 0점, S 극이면 1점 획득
- 결국 K 번 자석을 회전시킨 후 획득하는 점수의 총 합을 출력하는 문제

![asd](https://user-images.githubusercontent.com/55940552/105719601-d08a6b00-5f65-11eb-9be5-7dfc42204e77.PNG)



### **🔑 문제 규칙**

- 처음에 총 테스트 케이스가 주어짐

- 회전 횟수가 주어짐

- 자석의 자성 정보가 2차원 배열 형태로 주어짐

- n번 자석을 1 또는 -1 방향으로의 회전이 주어짐

  > exam
  >
  > 1	// 테스트 케이스
  >
  > 2	// 자석의 회전 횟수

  > 0 0 1 0 0 1 0 0	// 2차원 배열 형태의 자석의 자성 정보
  > 1 0 0 1 1 1 0 1
  > 0 0 1 0 1 1 0 0
  > 0 0 1 0 1 1 0 1
  >
  > 1 1	// 1번 자석을 1(시계방향)으로 회전
  >
  > 3 -1	// 3번 자석을 -1(반시계방향)으로 회전



### **🔑 문제 해결 방법**

1. **n번 자석을 1 또는 -1 방향으로의 회전이 주어졌을 때 - RotationMagneticCheck() 함수**

- 2차원 배열로 이루어진 자석의 자성 정보에서 맞닿는 부분인 2번 인덱스와 6번 인덱스를 사용

- n번 째 자석을 기준으로 왼쪽과 오른쪽으로 순회하면서 맞닿는 부분의 자성이 같은지 확인

  >  0번 인덱스는 더이상 왼쪽에 자석이 없으므로 0번 인덱스가 기준이 되어 순회할 필요가 없다.<br> 따라서 왼쪽 순회 이전에 n번 째 자석이 0보다 큰지 확인한다.

  > n 번째 자석과 인접한 자석의 맞닿는 부분이 서로 다른 극이라면 **RotationObject[]** 배열에 추가

![Untitled Diagram](https://user-images.githubusercontent.com/55940552/105721924-72ab5280-5f68-11eb-8c43-73be4cdd0c12.png)

2. **회전 해야 할 자석들의 회전 방향을 지정 - MagneticDirection() 함수**

- 회전의 방향이 결정된 자석의 회전 방향을 따라서 규칙이 정해진다.

  > 회전 방향이 결정된 자석 : 0번 자석
  >
  > 회전 방향이 결정된 자석의 회전 방향 : 1(시계방향)
  >
  > 0	1	2	3	  : 자석 번호
  >
  > 1	-1	1	-1	: 회전 규칙

- switchDirect 변수를 사용하여 기준 방향을 저장한다.

- 자석을 왼쪽과 오른쪽으로 순회하며 위의 규칙을 적용한다.

  ```c
  void MagneticDirection(int magnetNum, int direct) {
  	MagneticDirect[magnetNum] = direct; // 기준 자석의 방향 저장 
  	int switchDirect = direct; // 현재 자석의 회전 방향이 -1이면 인접 자석은 1을 가짐
  
  	// 2번 자석의 회전 방향이 -1이라 치자
  
  	// 왼쪽으로 검사
  	// 현재 자석의 방향 기준으로 -1, 1 둘 중에 하나를 선택하여 저장
  	for (int i = magnetNum - 1; i >= 0; i--) {
  		// 현 자석 기준으로 왼쪽에 자석이 회전 대상 리스트에 존재한다면
  		if (RotationObject[i] == 1) {
  			// 자석의 회전 방향을 저장
  			// 이전 회전 방향이 1이였다면
  			if (switchDirect == 1) {
  				switchDirect = -1; // 다음 회전 방향을 -1로 바꿔주고
  				MagneticDirect[i] = switchDirect; // 다음 위치에 해당하는 자석의 방향을 바꿔줌
  			}
  			else if (switchDirect == -1) {
  				switchDirect = 1;
  				MagneticDirect[i] = switchDirect;
  			}
  		}
  	}
  
  	// 현재 기준 자석의 회전 방향을 저장
  	switchDirect = direct;
  
  	// 오른쪽으로 검사
  	for (int i = magnetNum + 1; i < MaxMagnetic; i++) {
  		// 현 자석 기준으로 오른쪽에 자석이 회전 대상 리스트에 존재한다면
  		if (RotationObject[i] == 1) {
  			if (switchDirect == 1) {
  				switchDirect = -1;
  				MagneticDirect[i] = switchDirect;
  			}
  			else if (switchDirect == -1) {
  				switchDirect = 1;
  				MagneticDirect[i] = switchDirect;
  			}
  		}
  	}
  }
  ```

  

3. **회전할 자석 번호가 저장된 배열과 회전 방향이 저장된 배열을 통해 각 자석을<br> 회전 시킨다 - RotationMagnetic() 함수**

- 0번부터 3번 자석까지 순회 한다.
- 회전 대상 자석 번호가 저장된 배열을 확인하고 존재하는 자석의 번호에 대해서만 회전시킨다.
  - 회전 대상 자석이 가지는 회전 방향이 1 또는 -1인지 검사하여 반시계방향, 시계방향 회전을 구별
    - 시계 방향 회전 : **RotationArrayRight() 함수**
    - 반시계 방향 회전 : **RotationArrayLeft() 함수**

![Untitled Diagram1](https://user-images.githubusercontent.com/55940552/105725199-02063500-5f6c-11eb-87d8-7017b598b2b5.png)



***

**[출처]**

[SW Expert Academy](https://swexpertacademy.com/main/learn/course/lectureProblemViewer.do)


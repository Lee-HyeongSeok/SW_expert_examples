## **Ladder1**

***



### **⚙어느 사다리를 고르면 X표시에 도착하는가**

ex) 10 by 10 행렬에 임의의 개수의 막대들이 랜덤 간격으로 추가되고 이에 가로 방향의 선들이<br> 또한 랜덤하게 연결된다. x=0인 출발점에서 출발하는 사례에 대해 화살표로 표시한 바와 같이, <br> 아래 방향으로 진행하면서 좌우 방향으로 이동 가능한 통로가 나타나면 방향 전환을 하게 된다.

![1](https://user-images.githubusercontent.com/55940552/105358912-1d0a3980-5c3a-11eb-9e4e-9a4875d439ba.PNG)



### **⚙ 문제 해결 방법**

1. DFS 깊이 우선 탐색 - 조건문이 까다롭고 많은 재귀 호출이 발생함

2. 달팽이 번호 문제 응용해서 해결 - [달팽이 문제](https://github.com/Lee-HyeongSeok/SW_expert_examples/tree/main/test/Snail_number)

   ```c
   bool findLoad(int x, int y) {
   	while (1) {
   		// x가 MAX-1이면 바닥에 도착했다는 것
   		// 도착하는 이전에 2를 찾지 못하면 해당 라인에는 2가 없음
   		if (x == MAX - 1)
   			break;
   
   		// 오른쪽에 길이 있는지 검사
   		if (Map[x][y + 1] == 1 && !visit[x][y+1]) {
   			y++;
   			visit[x][y] = 1;
   			// 오른쪽으로 완전히 현재위치 이동 후 2가 있는지 검사
   			if (Map[MAX-1][y] == 2) {
   				return true;
   			}
   		}
   		// 항상 세 방향 탐색
   		// 아래 방향에 길이 있는지 검사 
   		else if (Map[x + 1][y] == 1 && !visit[x+1][y]) {
   
   			// 아래 방향에 길이 있으면서도 오른쪽 방향에도 길이 있는지 검사
   			if (Map[x][y + 1] == 1 && !visit[x][y + 1]) {
   				y++;
   				visit[x][y] = 1;
   			}
   			// 아래 방향에 길이 있으면서도 왼쪽 방향에도 길이 있는지 검사
   			else if (Map[x][y - 1] == 1 && !visit[x][y - 1]) {
   				y--;
   				visit[x][y] = 1;
   			}
   			// 아래 방향에 길이 있으며 좌우에 길이 없으면 아래 방향으로 진행
   			else {
   				x++;
   				visit[x][y] = 1;
   			}
   
   			// 진행 이후 현재위치에서 2를 발견하면 true를 리턴하고 함수를 빠져나감
   			if (Map[MAX-1][y] == 2) {
   				return true;
   			}
   		}
   		// 현재 위치 기준, 왼쪽 방향에 길이 있는지 검사 
   		else if (Map[x][y - 1] == 1 && !visit[x][y - 1]) {
   			y--;
   			visit[x][y] = 1;
   
   			// 완전히 이동 후 2가 있는지 검사
   			if (Map[MAX-1][y] == 2) {
   				return true;
   			}
   		}
   	}
   	return false; // 해당 라인에 2가 없을 때 
   }
   ```

   
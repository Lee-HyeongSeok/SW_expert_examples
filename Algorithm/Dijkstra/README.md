## **Dijkstra 다익스트라 알고리즘**

***

   

### **⚙Dijkstra Algorithm 이란**



- **최단 경로 문제**
  - 정점 u와 v를 연결하는 경로 중 간선들의 가중치 합이 최소가 되는 경로를 찾는 문제
- **하나의 시작 정점으로부터 모든 다른 정점까지의 최단 경로를 찾는 알고리즘**   

   

### **⚙Dijkstra 구현**



- 가중치는 가중치 인접 행렬이라 하는 2차원 배열에 저장

- 간선이 없는 구간은 INF를 인접 행렬에 저장

- 시작 정점에서 집합 S에 있는 정점만을 거쳐 다른 정점으로 가는 최단 거리를 기록하는 배열이 <br> 반드시 존재해야 한다.

  - 예제에서는 dist[] 라는 배열을 사용하고 있다.
  - 시작 정점을 v라 했을 때 dist[v] = 0
  - 다른 정점에 대한 dist[] 배열의 값은 시작 정점과 해당 정점 간의 가중치
  - 정점 v에서 w로의 간선이 없는 경우 INF(상수)를 저장한다.

- 최단 거리가 발견되는 정점들이 집합 S에 하나씩 추가된다.

- 매 단계에서 집합 S 안에 없는 정점 중 가장 dist[] 값이 작은 정점을 S에 추가한다.

- 새로운 정점 u가 집합 S에 추가되면 S에 없는 다른 정점들의 dist[] 값을 수정한다.

  ```c
  if (dist[j] > dist[v] + map[v][j]) {
  	dist[j] = dist[v] + map[v][j];
  	if (pre[j] != -1) // 이전 정점이 존재한다면
  		puts("unhighlight");
  	pre[j] = v; // 이전 정점에 현재 정점 저장
  }
  ```

  

### **⚙Dijkstra 실행 과정**

1. 시작 정점 기준을 0으로 하고 연결된 각 지점까지의 거리를 표시

   - 연결되지 않은 부분은 INF를 저장한다.

   ![다익1](https://user-images.githubusercontent.com/55940552/105191160-1ddb9680-5b7a-11eb-9971-6a5aca4bf995.PNG)

2. 가장 짧은 거리는 정점 4까지의 거리인 3이므로 정점 4를 집합 S에 추가 시킨다.

   - 정점 4가 추가되면서 다른 정점까지의 거리값이 변경된다.
   - 0번 정점에서 간접적으로 다른 정점들 까지 연결된 각 거리를 가중치 합을 계산하여 변경한다.
     - **0번 정점~1번 정점** = 0번 정점~4번 정점 가중치(3) + 4번 정점~1번 정점 가중치(2) = 가중치 5

   ![다익2](https://user-images.githubusercontent.com/55940552/105191342-4c597180-5b7a-11eb-836f-a77172839a82.PNG)

   

3. 정점 4번에서 갈 수 있는 거리 중 가장 가까운 1번 정점을 집합 S에 추가 후 거리 재계산

   - 정점 0에서 정점 4와 1을 거쳐 정점 2까지 가는 최단 거리는 0-4-1-2 정점이다.
     - 정점 0~4(3) + 4~1(2) + 1~2(4) = 가중치 9

   ![다익3](https://user-images.githubusercontent.com/55940552/105193557-f71e5f80-5b7b-11eb-891f-c5d3a6b151b7.PNG)

4. 현재 까지 dist[] 값 중 가장 작은 6번 정점을 선택

   - 6번 정점을 집합 S에 추가 
   - 갱신 가능한 정보는 정점 3 까지의 거리
   - 기존의 3까지의 거리는 14, 새로 갱신할 거리는 12이므로 값을 갱신해준다.

   ![다익4](https://user-images.githubusercontent.com/55940552/105194215-b246f880-5b7c-11eb-9aa4-52e5bde1b0f0.PNG)

5. dist[] 배열에서 가장 작은 가중치는 9 이므로 정점 2를 선택

   - 정점 2를 집합 S에 추가
   - 정점 3까지의 거리 갱신
   - 기존에 정점 3까지의 거리는 12 였지만 새로 갱신할 값인 11이 더 작으므로 갱신해준다.

   ![다익5](https://user-images.githubusercontent.com/55940552/105194541-0b169100-5b7d-11eb-8710-200e9b3c065f.PNG)





***

**[출처]**

[다익스트라 최단 경로 알고리즘 블로그](https://mattlee.tistory.com/50)

[SW expert Academy](https://swexpertacademy.com/main/main.do)
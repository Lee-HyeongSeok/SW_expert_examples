## **🎈 SW Expert 점심 식사시간 해설**

***



### **⚙ 문제**

- N by N 크기의 정사각형 모양의 방에 사람들이 앉아 있다.
- 점심을 먹기 위해 아랫 층으로 내려가야 하는데, 최대한 빠른 시간 내에 내려가야 한다.
  - **계단 입구까지 이동시간** : |PR - SR| + |PC - SC|
  - **계단 내려가는 시간**
    - 계단 입구 도착 시 1분 후 아래칸으로 내려갈 수 있다.
    - 계단 입구에는 최대 3명까지만 올라가 있을 수 있다(Stack을 이용한 문제)
    - 계단 마다 길이 K가 주어지며, 완전히 내려가는데 K 분이 걸린다.<br> 
- 방 안의 사람들은 P, 계단 입구를 S라 한다.
- **모든 사람들이 계단을 내려가 이동이 완료되는 시간이 최소가 되는 경우를 찾고 시간을 출력**<br> 

![Untitled Diagram](https://user-images.githubusercontent.com/55940552/108306386-5f01ad80-71ef-11eb-8d66-0806402ef23b.png)   



### **⚙ 입력 처리**

- 방 한 변의 길이 N은 4 이상 10 이하의 정수
- 사람 수는 1 이상 10 이하의 정수
- 계단의 입구는 반드시 2개, 서로 위치가 겹치지 않는다.
- 계단 길이는 2 이상 10 이하의 정수
- 초기 입력에 사람 위치와 계단 입구 위치는 겹치지 않는다.<br>  ![1](https://user-images.githubusercontent.com/55940552/108313093-0fc17a00-71fb-11eb-86e1-17fdccec7d45.png)<br> 

```c
#define MAXM 11 // 사람 수는 1 이상 10 이하의 정수
#define MAXT = MAXM * 2 + MAXM * MAXM

struct Position{
    // (r, c) : r 번째 행의 c 번째 열
    int r, c;
    
    // 기본 생성자
    Position(){
        
    }
    // 인자를 2개를 받는 생성자
    Position(int r, int c): r(r), c(c){
        
    }
}man[MAXM], stair[2];

// N : 방 한 변의 길이
// M : 사람 수
// S : 계단 수
int N, M, S;
int map[MAXM][MAXM]; // 최대 11 by 11 방 정보

// 사람과 계단 위치를 입력 받는 함수
void inputMap(){
    for(int i=1; i<= N; i++){
        for(int j=1; j<= N; j++){
            // 방 정보를 입력 받는다.
            scanf("%d", &map[i][j]);
            
            // 방의 (i, j)가 사람이면
            if(map[i][j] == 1)
                man[M++] = Position(i, j); // 해당 위치를 man에 삽입
            // 방의 (i, j)가 계단이면
            if(map[i][j] >= 2)
                stair[S++] = Position(i, j); // 해당 위치를 stair에 삽입
        }
    }
}
```



### **⚙ 문제 해결 방법**

- **계단의 수 2개**
  - 각 사람이 어느 계단을 사용할 것인지 모두 정해볼 수 있다.
  - 사람 수 M 명, 시간 복잡도는 **O(2^M)** 이다.
  - 가장 큰 입력에 대해서도 빠른 시간 내에 계산 가능 
  - **깊이 우선 탐색(Depth First Search)** 구현

```c
// match[MAXM] = y
// MAXM 번째 사람이 y 번째 계단을 내려가도록 결정된 상태(계단 입구에 존재)
int match[MAXM]; 

void dfs(int max_index){
    // 모든 사람에 대해 각 사람이 사용할 계단을 다 정했다면
    if(man_index == M){
        // 해당 상태에서 필요한 시간 계산, 정답 갱신
        update();
        // 함수 종료
        return;
    }
    // man_index 번째 사람이 stair_index 번째 계단을 선택, 재귀 호출
    // 각 사람당 2개의 계단을 내려가는 시간을 비교해서 가장 짧은 시간 도출 
    for(int stair_index=0; stair_index < 2; stair_index++){
        match[man_index] = stair_index;
        dfs(man_index+1); // 다음 사람을 인자로 전달 
    }
}
```

- **모든 사람들이 계단을 내려가는 시간 중 최소 시간 구하기**

  - **첫 번째** 계단을 사람들이 모두 내려가는데 필요한 시간 T0
  - **두 번째** 계단을 사람들이 모두 내려가는데 필요한 시간 T1
  - **T** = **max(T0, T1)** 
  - 각 계단을 모두 내려가는데 필요한 시간은 독립적으로 계산된다.
  - 가능한 계단에 먼저 도착한 사람부터 먼저 내려가는 것이 좋다.<br> 

- **각 사람들과 계단의 거리 구하기**

  - **| PR - SR | + | PC - SC |**

  ```c
  // man_index 번째 사람과 stair_index 번째 계단의 거리를 구하는 함수
  int dist(int man_index, int stair_index){
      int dx = abs(man[man_index].r - stair[stair_index].r);
      int dy = abs(man[man_index].c - stair[stair_index].c);
      return dx+dy;
  }
  ```

- **시간에 따른 계단 도착 인원 처리**

  ```c
  // arrival_time[ t ] : 시간 t 일 때 계단에 도착하는 사람의 수
  // t = 1, arrival_time[1] = 2 : 시간 1 일 때 계단에 도착한 사람의 수는 2명
  // 해당 시간에 몇 명이 계단을 사용 중인지를 나타내는 배열
  int arrival_time[MAXM * 2] = {0, };
  
  // man_index 번째 사람과 해당 인원이 선택한 계단과의 거리 측정
  for(int man_index=0; man_index < M; man_index++){
      if(match[man_index] == stair_index){
          // man_index 번째 사람의 stair_index 번째 계단 까지 도착하는 시간을 인덱스로 사용
          // 시간 t 일 때 계단에 도착하는 사람의 수를 1씩 증가
          arrival_time[dist(man_index, stair_index) + 1]++;
      }
  }
  ```

- **계단 길이 시간만큼, 계단 입구에 존재하는 인원 처리**

  ```c
  // stair_index 번째 계단을 내려가는 사람이 모두 내려가기 위해 필요한 최소 시간
  int now_min_time=0;
  
  // 계단에 도착하는 시간을 오름차순으로 진행
  // 각 사람이 계단을 내려가도록 진행
  for(int time=1; time <= 20; time++){
      // time 시간에 도착한 사람이 존재한다면
      while(arrival_time[time] > 0){
           arrival_time[time]--; // time 시간에 도착한 사람 1씩 감소
          
          // now_stair.r : 현재 now_stair의 열
          // now_stair.c : 현재 now_stair의 행
          // 현재 (r, c)위치에 있는 now_stair 번째 계단의 계단 길이를 가져온다.
          // 계단의 길이는 내려가는 시간이기 때문이다.
          int remain_time = map[now_stair.r][now_stair.c];
          
          // 계단을 내려보내는 동작
          // ex) 3명이 존재한다면 순차적으로 1칸씩 내려보낸다.
          for(int walk_time = time; walk_time < MAXT; walk_time++){
              // 3 : 각 계단 입구에 올라갈 수 있는 인원은 3명으로 문제에서 제한
              if(current_stair[walk_time] < 3){
                  current_stair[walk_time]++; // 계단 내려가는 시간 증가
                  remain_time--; // 현재 계단의 길이 감소
                  
                  // 현재 계단의 길이가 0이라면
                  // 계단을 전부 내려갔다는 의미
                  if(remain_time == 0){
                      // 현재 저장된 최소시간과 내려가는데 걸린 시간 중 가장 큰 값을 계산
                      now_min_time = max(now_min_time, walk_time+1);
                      break;
                  }
              }
          }
      }
  }
  
  // 전체 계단을 내려가는데 필요한 시간 : 두 계단을 내려가는데 필요한 최소 시간 중 최대값
  total_min_time = max(total_min_time, now_min_time);
  ```

  

<br> 

***

<br> **[출처]**

[SW Expert Academy](https://swexpertacademy.com/main/learn/course/lectureHtmlViewer.do)